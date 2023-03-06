# conquer

**Con**volution-type smoothed **qu**antil**e** **r**egression

## Description

The `conquer` library performs fast and accurate convolution-type smoothed quantile regression ([Fernandes, Guerre and Horta, 2021](https://www.tandfonline.com/doi/full/10.1080/07350015.2019.1660177), [He et al., 2022](https://doi.org/10.1016/j.jeconom.2021.07.010), [Tan, Wang and Zhou, 2022](https://doi.org/10.1111/rssb.12485) for low/high-dimensional estimation and bootstrap inference.

In the low-dimensional setting, efficient gradient-based methods are employed for fitting both a single model and a regression process over a quantile range. Normal-based and (multiplier) bootstrap confidence intervals for all slope coefficients are constructed. In high dimensions, the conquer methods complemented with *&ell;<sub>1</sub>*-penalization and iteratively reweighted *&ell;<sub>1</sub>*-penalization are used to fit sparse models.


## Updates

**2023-03-05 (Version 1.3.3)**:

More efficient statistical inference based on asymptotic property. When calling `conquer` function with `ci = "asymptotic"`, an *n* by *n* diagonal matrix was involved for estimating asymptotic covariance matrix. This space allocation was expensive and unnecessary.

**2023-02-05 (Version 1.3.2)**:

1. Fix an issue in the `conquer.reg` function: when the penalties were group lasso, sparse group lasso or elastic-net, and the input *&lambda;* was a sequence, the estimated coefficients were not reasonable. This didn't affect cross-validation (`conquer.cv.reg`), or `conquer.reg` with other penalties or when input *&lambda;* was a scalar. 

2. When the input *&lambda;* of `conquer.reg` function was a sequence, the output estimation was a vector instead of a matrix, which was not consistent with the description of the function.

3. Update the default version of C++ as required by CRAN.

**2022-09-12 (Version 1.3.1)**:

Add flexibility into the `conquer` function:

1. The step size of Barzilai-Borweincan gradient descent can be unbounded, or the upper bound can be user-specified.

2. The smoothing bandwidth can be specified as any positive value. In previous versions, it has to be bounded away from zero. 

**2022-03-24 (Version 1.3.0)**:

1. Add inference methods based on estimated asymptotic covariance matrix for low-dimensional conquer.

2. Add more flexible penalties (elastic-net, group Lasso and sparse group Lasso) into `conquer.reg` and `conquer.cv.reg` functions.

3. Speed up cross-validation using warm start along a sequence of *&lambda;*'s.

**2022-02-12 (Version 1.2.2)**:

Remove the unnecessary dependent packge `caret` for a cleaner installation.

**2021-10-24 (Version 1.2.1)**:

Major updates:

1. Add a function `conquer.process` for conquer process over a quantile range.

2. Add functions `conquer.reg`, `conquer.cv.reg` for high-dimensional conquer with Lasso, SCAD and MCP penalties. The first function is called with a prescribed *&lambda;*, and the second function calibrate *&lambda;* via cross-validation. The candidates of *&lambda;* can be user-specified, or automatically generated by simulating the pivotal quantity proposed in [Belloni and Chernozhukov, 2011](https://doi.org/10.1214/10-AOS827).

Minor updates:

1. Add logistic kernel for all the functions.

2. Modify initialization using asymmetric Huber regression.

3. Default number of tightening iterations is now 3.

4. Parameters for SCAD (default = 3.7) and MCP (default = 3) are added as arguments into the functions.

## Installation

`conquer` is available on [CRAN](https://CRAN.R-project.org/package=conquer), and it can be installed into `R` environment:

```r
install.packages("conquer")
```

## Common errors or warnings

**Compilation errors by `install.packages("conquer")` in R**:

It usually takes several days to build a binary package after we submit a source packge to CRAN. During that time period, only a source package for the new version is available. However, installing source packges (especially Rcpp-based ones) may cause various compilation errors. Hence, when users see the prompt "There is a binary version available but the source version is later. Do you want to install from sources the package which needs compilation?", we strongly recommend selecting **no**.

Below are a collection of error / warning messages and their solutions:

* Error: smqr.cpp: 'quantile' is not a member of 'arma’. **Solution**: 'quantile' function was added into `RcppArmadillo` version 0.9.850.1.0 (2020-02-09), so reinstalling / updating the library `RcppArmadillo` will fix this issue.

* Error: unable to load shared object.. Symbol not found: _EXTPTR_PTR. **Solution**: This issue is common in some specific versions of `R` when we load Rcpp-based libraries. It is an error in R caused by a minor change about `EXTPTR_PTR`. Upgrading R to 4.0.2 will solve the problem.

* Error: function 'Rcpp_precious_remove' not provided by package 'Rcpp'. **Solution**: This happens when a package is compiled against a recent `Rcpp` release, but users load it using an older version of `Rcpp`. Reinstalling the package `Rcpp` will solve the problem.

## Functions

There are 4 functions in this library:

* `conquer`: convolution-type smoothed quantile regression
* `conquer.process`: convolution-type smoothed quantile regression process
* `conquer.reg`: convolution-type smoothed quantile regression with regularization
* `conquer.cv.reg`: cross-validated convolution-type smoothed quantile regression with regularization

## Examples

### Quantile regression

Let us illustrate conquer by a simple example. For sample size *n = 5000* and dimension *p = 500*, we generate data from a linear model *y<sub>i</sub> = &beta;<sub>0</sub> + <x<sub>i</sub>, &beta;> + &epsilon;<sub>i</sub>*, for *i = 1, 2, ... n*. Here we set *&beta;<sub>0</sub> = 1*, *&beta;* is a *p*-dimensional vector with every entry being *1*, *x<sub>i</sub>* follows *p*-dimensional standard multivariate normal distribution (available in the library `MASS`), and *&epsilon;<sub>i</sub>* is from *t<sub>2</sub>* distribution. 

```r
library(MASS)
library(quantreg)
library(conquer)
n = 5000
p = 500
beta = rep(1, p + 1)
set.seed(2021)
X = mvrnorm(n, rep(0, p), diag(p))
err = rt(n, 2)
Y = cbind(1, X) %*% beta + err
```

Then we run both quantile regression using package `quantreg`, with a Frisch-Newton approach after preprocessing ([Portnoy and Koenker, 1997](https://projecteuclid.org/euclid.ss/1030037960)), and conquer (with Gaussian kernel) on the generated data. The quantile level *&tau;* is fixed to be *0.5*. 

```r
tau = 0.5
start = Sys.time()
fit.qr = rq(Y ~ X, tau = tau, method = "pfn")
end = Sys.time()
time.qr = as.numeric(difftime(end, start, units = "secs"))
est.qr = norm(as.numeric(fit.qr$coefficients) - beta, "2")

start = Sys.time()
fit.conquer = conquer(X, Y, tau = tau)
end = Sys.time()
time.conquer = as.numeric(difftime(end, start, units = "secs"))
est.conquer = norm(fit.conquer$coeff - beta, "2")
```

It takes 7.4 seconds to run the standard quantile regression but only 0.2 seconds to run conquer. In the meanwhile, the estimation error is 0.5186 for quantile regression and 0.4864 for conquer. For readers’ reference, these runtimes are recorded on a Macbook Pro with 2.3 GHz 8-Core Intel Core i9 processor, and 16 GB 2667 MHz DDR4 memory. We refer to [He et al., 2022](https://doi.org/10.1016/j.jeconom.2021.07.010) for a more extensive numerical study.

### Quantile regression process

We can also run conquer over a quantile range

```r
fit.conquer.process = conquer.process(X, Y, tauSeq = seq(0.2, 0.8, by = 0.05))
beta.conquer.process = fit.conquer.process$coeff
```

### Regularized quantile regression

Let us switch to the setting of high-dimensional sparse regression with *(n, p, s) = (200, 500, 5)*, and generate data accordingly. 

```r
n = 200
p = 500
s = 5
beta = c(runif(s + 1, 1, 1.5), rep(0, p - s))
X = mvrnorm(n, rep(0, p), diag(p))
err = rt(n, 2)
Y = cbind(1, X) %*% beta + err
```

Regularized conquer can be executed with flexible penalitis, including Lasso, elastic-net, SCAD and MCP.
For all the penalties, the bandwidth parameter *h* is self-tuned, and the regularization parameter *&lambda;* is selected via cross-validation.

```r
fit.lasso = conquer.cv.reg(X, Y, tau = 0.5, penalty = "lasso")
beta.lasso = fit.lasso$coeff

fit.elastic = conquer.cv.reg(X, Y, tau = 0.5, penalty = "elastic", para.elastic = 0.7)
beta.elastic = fit.elastic$coeff

fit.scad = conquer.cv.reg(X, Y, tau = 0.5, penalty = "scad")
beta.scad = fit.scad$coeff

fit.mcp = conquer.cv.reg(X, Y, tau = 0.5, penalty = "mcp")
beta.mcp = fit.mcp$coeff
```

Finally, group Lasso is also incorporated in to account for more complicated sparse structure.
The **group** argument stands for group indices, and it has to be specified for group Lasso.

```
n = 200
p = 500
s = 5
beta = c(1, rep(1.3, 2), rep(1.5, 3), rep(0, p - s))
X = matrix(rnorm(n * p), n, p)
err = rt(n, 2)
Y = cbind(1, X) %*% beta + err

group = c(rep(1, 2), rep(2, 3), rep(3, p - s))
fit.group = conquer.cv.reg(X, Y,tau = 0.5, penalty = "group", group = group)
beta.group = fit.group$coeff
```

## Getting help

Help on the functions can be accessed by typing `?`, followed by function name at the `R` command prompt. 

For example, `?conquer` will present a detailed documentation with inputs, outputs and examples of the function `conquer`.

## License

GPL-3.0

## System requirements 

C++17

## Authors

Xuming He <xmhe@umich.edu>, Xiaoou Pan <xip024@ucsd.edu>, Kean Ming Tan <keanming@umich.edu> and Wen-Xin Zhou <wez243@ucsd.edu>

## Maintainer

Xiaoou Pan <xip024@ucsd.edu>

## References

Barzilai, J. and Borwein, J. M. (1988). Two-point step size gradient methods. *IMA J. Numer. Anal.* **8** 141-148. [Paper](https://doi.org/10.1093/imanum/8.1.141)

Belloni, A. and Chernozhukov, V. (2011) *&ell;<sub>1</sub>*-penalized quantile regression in high-dimensional sparse models. *Ann. Statist.* **39** 82-130. [Paper](https://doi.org/10.1214/10-AOS827)

Fan, J., Liu, H., Sun, Q. and Zhang, T. (2018). I-LAMM for sparse learning: Simultaneous control of algorithmic complexity and statistical error. *Ann. Statist.* **46** 814-841. [Paper](https://projecteuclid.org/euclid.aos/1522742437)

Fernandes, M., Guerre, E. and Horta, E. (2021). Smoothing quantile regressions. *J. Bus. Econ. Statist.* **39** 338-357, [Paper](https://www.tandfonline.com/doi/full/10.1080/07350015.2019.1660177)

He, X., Pan, X., Tan, K. M., and Zhou, W.-X. (2023). Smoothed quantile regression with large-scale inference. *J. Econometrics*, **232**(2) 367-388, [Paper](https://doi.org/10.1016/j.jeconom.2021.07.010)

Koenker, R. (2005). Quantile Regression. Cambridge Univ. Press, Cambridge. [Book](https://www.cambridge.org/core/books/quantile-regression/C18AE7BCF3EC43C16937390D44A328B1)

Koenker, R. and Bassett, G. (1978). Regression quantiles. *Econometrica* **46** 33-50. [Paper](https://doi.org/10.2307/1913643)

Portnoy, S. and Koenker, R. (1997). The Gaussian hare and the Laplacian tortoise: Computability of squared-error versus absolute-error estimators. *Statist. Sci.* **12** 279–300. [Paper](https://projecteuclid.org/euclid.ss/1030037960)

Tan, K. M., Wang, L. and Zhou, W.-X. (2022). High-dimensional quantile regression: convolution smoothing and concave regularization. *J. Roy. Statist. Soc. Ser. B* **84(1)** 205-233. [Paper](https://doi.org/10.1111/rssb.12485)

