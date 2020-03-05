# include <RcppArmadillo.h>
# include <cmath>
// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
int sgn(const double x) {
  return (x > 0) - (x < 0);
}

// [[Rcpp::export]]
double mad(const arma::vec& x) {
  return 1.482602 * arma::median(arma::abs(x - arma::median(x)));
}

// [[Rcpp::export]]
void updateHuber(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, double& loss, const int n, const double tau, 
                 const double n1) {
  loss = 0.0;
  for (int i = 0; i < n; i++) {
    double cur = res(i);
    if (std::abs(cur) <= tau) {
      loss += 0.5 * cur * cur;
      der(i) = -cur;
    } else {
      loss += (tau * std::abs(cur) - 0.5 * tau * tau);
      der(i) = -tau * sgn(cur);
    }
  }
  loss *= n1;
  grad = n1 * Z.t() * der;
}

// [[Rcpp::export]]
arma::vec huberReg(const arma::mat& Z, const arma::vec& Y, arma::vec& der, arma::vec& gradOld, arma::vec& gradNew, double& lossOld, 
                   double& lossNew, const int n, const int p, const double n1, const double tol = 0.0000001, const double constTau = 1.345, 
                   const int iteMax = 5000) {
  double tau = constTau * mad(Y);
  updateHuber(Z, Y, der, gradOld, lossOld, n, tau, n1);
  arma::vec beta = -gradOld, betaDiff = -gradOld;
  arma::vec res = Y - Z * beta;
  tau = constTau * mad(res);
  updateHuber(Z, res, der, gradNew, lossNew, n, tau, n1);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    tau = constTau * mad(res);
    updateHuber(Z, res, der, gradNew, lossNew, n, tau, n1);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  return beta;
}

// [[Rcpp::export]]
arma::mat standardize(arma::mat X, const arma::rowvec& mx, const arma::vec& sx, const int p) {
  for (int i = 0; i < p; i++) {
    X.col(i) = (X.col(i) - mx(i)) / sx(i);
  }
  return X;
}

// [[Rcpp::export]]
void updateGauss(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, double& loss, const int n, const double tau, 
                 const double h, const double n1, const double h1, const double h2) {
  der = arma::normcdf(-res * h1) - tau;
  loss = arma::mean(0.39894 * h * arma::exp(-0.5 * h2 * arma::square(res)) - res % der);
  grad = n1 * Z.t() * der;
}

// [[Rcpp::export]]
void updateUnif(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, double& loss, const int n, const double tau, 
                const double h, const double n1, const double h1) {
  loss = 0.0;
  for (int i = 0; i < n; i++) {
    double cur = res(i);
    if (cur <= -h) {
      der(i) = 1 - tau;
      loss += (tau - 1) * cur;
    } else if (cur < h) {
      der(i) = 0.5 - tau - 0.5 * h1 * cur;
      loss += 0.25 * h1 * cur * cur + 0.25 * h + (tau - 0.5) * cur;
    } else {
      der(i) = -tau;
      loss += tau * cur;
    }
  }
  loss *= n1;
  grad = n1 * Z.t() * der;
}

// [[Rcpp::export]]
void updatePara(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, double& loss, const int n, const double tau, 
                const double h, const double n1, const double h1, const double h3) {
  loss = 0.0;
  for (int i = 0; i < n; i++) {
    double cur = res(i);
    if (cur <= -h) {
      der(i) = 1 - tau;
      loss += (tau - 1) * cur;
    } else if (cur < h) {
      der(i) = 0.5 - tau - 0.75 * h1 * cur + 0.25 * h3 * cur * cur * cur;
      loss += 0.1875 * h + 0.375 * h1 * cur * cur - 0.0625 * h3 * cur * cur * cur * cur + (tau - 0.5) * cur;
    } else {
      der(i) = -tau;
      loss += tau * cur;
    }
  }
  loss *= n1;
  grad = n1 * Z.t() * der;
}

// [[Rcpp::export]]
void updateTrian(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, double& loss, const int n, const double tau, 
                 const double h, const double n1, const double h1, const double h2) {
  loss = 0.0;
  for (int i = 0; i < n; i++) {
    double cur = res(i);
    if (cur <= -h) {
      der(i) = 1 - tau;
      loss += (tau - 1) * cur;
    } else if (cur < 0) {
      der(i) = 0.5 - tau - h1 * cur - 0.5 * h2 * cur * cur;
      loss += h2 * cur * cur * cur / 6 + 0.5 * h1 * cur * cur + h / 6 + (tau - 0.5) * cur;
    } else if (cur < h) {
      der(i) = 0.5 - tau - cur / h + 0.5 * cur * cur / (h * h);
      loss += -h2 * cur * cur * cur / 6 + 0.5 * h1 * cur * cur + h / 6 + (tau - 0.5) * cur;
    } else {
      der(i) = -tau;
      loss += tau * cur;
    }
  }
  loss *= n1;
  grad = n1 * Z.t() * der;
}

// [[Rcpp::export]]
Rcpp::List smqrGauss(const arma::mat& X, const arma::vec& Y, const double tau = 0.5, const double constTau = 1.345, const double tol = 0.0000001, 
                     const int iteMax = 5000) {
  const int n = X.n_rows;
  const int p = X.n_cols;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h, h2 = 1.0 / (h * h);
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = huberReg(Z, Y, der, gradOld, gradNew, lossOld, lossNew, n, p, n1, tol, constTau, iteMax);
  arma::vec quant = {tau};
  beta(0) = arma::as_scalar(arma::quantile(Y - Z.cols(1, p) * beta.rows(1, p), quant));
  arma::vec res = Y - Z * beta;
  updateGauss(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1, h2);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updateGauss(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updateGauss(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return Rcpp::List::create(Rcpp::Named("coeff") = beta, Rcpp::Named("ite") = ite, Rcpp::Named("residual") = Y - Z * beta, 
                            Rcpp::Named("bandwidth") = h);
}

// [[Rcpp::export]]
arma::vec smqrGaussIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau = 0.5, 
                       const double tol = 0.0000001, const int iteMax = 5000) {
  const int n = X.n_rows;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h, h2 = 1.0 / (h * h);
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = betaHat;
  arma::vec res = Y - Z * beta;
  updateGauss(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1, h2);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updateGauss(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updateGauss(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return beta;
}

// [[Rcpp::export]]
Rcpp::List smqrUnif(const arma::mat& X, const arma::vec& Y, const double tau = 0.5, const double constTau = 1.345, const double tol = 0.0000001, 
                    const int iteMax = 5000) {
  const int n = X.n_rows;
  const int p = X.n_cols;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h;
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = huberReg(Z, Y, der, gradOld, gradNew, lossOld, lossNew, n, p, n1, tol, constTau, iteMax);
  arma::vec quant = {tau};
  beta(0) = arma::as_scalar(arma::quantile(Y - Z.cols(1, p) * beta.rows(1, p), quant));
  arma::vec res = Y - Z * beta;
  updateUnif(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updateUnif(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updateUnif(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return Rcpp::List::create(Rcpp::Named("coeff") = beta, Rcpp::Named("ite") = ite, Rcpp::Named("residual") = Y - Z * beta, 
                            Rcpp::Named("bandwidth") = h);
}

// [[Rcpp::export]]
arma::vec smqrUnifIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau = 0.5, 
                      const double tol = 0.0000001, const int iteMax = 5000) {
  const int n = X.n_rows;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h;
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = betaHat;
  arma::vec res = Y - Z * beta;
  updateUnif(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updateUnif(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updateUnif(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return beta;
}
  
// [[Rcpp::export]]
Rcpp::List smqrPara(const arma::mat& X, const arma::vec& Y, const double tau = 0.5, const double constTau = 1.345, const double tol = 0.0000001, 
                    const int iteMax = 5000) {
  const int n = X.n_rows;
  const int p = X.n_cols;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h, h3 = 1.0 / (h * h * h);
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = huberReg(Z, Y, der, gradOld, gradNew, lossOld, lossNew, n, p, n1, tol, constTau, iteMax);
  arma::vec quant = {tau};
  beta(0) = arma::as_scalar(arma::quantile(Y - Z.cols(1, p) * beta.rows(1, p), quant));
  arma::vec res = Y - Z * beta;
  updatePara(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1, h3);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updatePara(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h3);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updatePara(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h3);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return Rcpp::List::create(Rcpp::Named("coeff") = beta, Rcpp::Named("ite") = ite, Rcpp::Named("residual") = Y - Z * beta, 
                            Rcpp::Named("bandwidth") = h);
}

// [[Rcpp::export]]
arma::vec smqrParaIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau = 0.5, 
                      const double tol = 0.0000001, const int iteMax = 5000) {
  const int n = X.n_rows;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h, h3 = 1.0 / (h * h * h);
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = betaHat;
  arma::vec res = Y - Z * beta;
  updatePara(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1, h3);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updatePara(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h3);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updatePara(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h3);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return beta;
}

// [[Rcpp::export]]
Rcpp::List smqrTrian(const arma::mat& X, const arma::vec& Y, const double tau = 0.5, const double constTau = 1.345, const double tol = 0.0000001, 
                     const int iteMax = 5000) {
  const int n = X.n_rows;
  const int p = X.n_cols;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h, h2 = 1.0 / (h * h);
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = huberReg(Z, Y, der, gradOld, gradNew, lossOld, lossNew, n, p, n1, tol, constTau, iteMax);
  arma::vec quant = {tau};
  beta(0) = arma::as_scalar(arma::quantile(Y - Z.cols(1, p) * beta.rows(1, p), quant));
  arma::vec res = Y - Z * beta;
  updateTrian(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1, h2);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updateTrian(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updateTrian(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return Rcpp::List::create(Rcpp::Named("coeff") = beta, Rcpp::Named("ite") = ite, Rcpp::Named("residual") = Y - Z * beta, 
                            Rcpp::Named("bandwidth") = h);
}

// [[Rcpp::export]]
arma::vec smqrTrianIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau = 0.5, 
                       const double tol = 0.0000001, const int iteMax = 5000) {
  const int n = X.n_rows;
  const double h = std::pow((std::log(n) + p) / n, 0.4);
  const double n1 = 1.0 / n;
  const double h1 = 1.0 / h, h2 = 1.0 / (h * h);
  arma::rowvec mx = arma::mean(X, 0);
  arma::vec sx = arma::stddev(X, 0, 0).t();
  arma::mat Z = arma::join_rows(arma::ones(n), standardize(X, mx, sx, p));
  double lossOld, lossNew;
  arma::vec der(n);
  arma::vec gradOld(p + 1), gradNew(p + 1);
  arma::vec beta = betaHat;
  arma::vec res = Y - Z * beta;
  updateTrian(Z, res, der, gradOld, lossOld, n, tau, h, n1, h1, h2);
  beta -= gradOld;
  arma::vec betaDiff = -gradOld;
  res -= Z * betaDiff;
  updateTrian(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
  arma::vec gradDiff = gradNew - gradOld;
  int ite = 1;
  while (std::abs(lossNew - lossOld) > tol && arma::norm(betaDiff, "inf") > tol && ite <= iteMax) {
    double alpha = 1.0;
    double cross = arma::as_scalar(betaDiff.t() * gradDiff);
    if (cross > 0) {
      double a1 = cross / arma::as_scalar(gradDiff.t() * gradDiff);
      double a2 = arma::as_scalar(betaDiff.t() * betaDiff) / cross;
      alpha = std::min(std::min(a1, a2), 100.0);
    }
    gradOld = gradNew;
    lossOld = lossNew;
    betaDiff = -alpha * gradNew;
    beta += betaDiff;
    res -= Z * betaDiff;
    updateTrian(Z, res, der, gradNew, lossNew, n, tau, h, n1, h1, h2);
    gradDiff = gradNew - gradOld;
    ite++;
  }
  beta.rows(1, p) /= sx;
  beta(0) -= arma::as_scalar(mx * beta.rows(1, p));
  return beta;
}

// [[Rcpp::export]]
arma::mat smqrGaussInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau = 0.5, 
                       const int B = 1000, const double tol = 0.0000001, const int iteMax = 5000) {
  arma::mat rst(p + 1, B);
  for (int b = 0; b < B; b++) {
    arma::uvec idx = arma::find(arma::randi(n, arma::distr_param(0, 1)) == 1);
    arma::mat mbX = X.rows(idx);
    arma::mat mbY = Y.rows(idx);
    rst.col(b) = smqrGaussIni(mbX, mbY, betaHat, p, tau, tol, iteMax);
  }
  return rst;
}

// [[Rcpp::export]]
arma::mat smqrUnifInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau = 0.5, 
                      const int B = 1000, const double tol = 0.0000001, const int iteMax = 5000) {
  arma::mat rst(p + 1, B);
  for (int b = 0; b < B; b++) {
    arma::uvec idx = arma::find(arma::randi(n, arma::distr_param(0, 1)) == 1);
    arma::mat mbX = X.rows(idx);
    arma::mat mbY = Y.rows(idx);
    rst.col(b) = smqrUnifIni(mbX, mbY, betaHat, p, tau, tol, iteMax);
  }
  return rst;
}

// [[Rcpp::export]]
arma::mat smqrParaInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau = 0.5, 
                      const int B = 1000, const double tol = 0.0000001, const int iteMax = 5000) {
  arma::mat rst(p + 1, B);
  for (int b = 0; b < B; b++) {
    arma::uvec idx = arma::find(arma::randi(n, arma::distr_param(0, 1)) == 1);
    arma::mat mbX = X.rows(idx);
    arma::mat mbY = Y.rows(idx);
    rst.col(b) = smqrParaIni(mbX, mbY, betaHat, p, tau, tol, iteMax);
  }
  return rst;
}

// [[Rcpp::export]]
arma::mat smqrTrianInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau = 0.5, 
                       const int B = 1000, const double tol = 0.0000001, const int iteMax = 5000) {
  arma::mat rst(p + 1, B);
  for (int b = 0; b < B; b++) {
    arma::uvec idx = arma::find(arma::randi(n, arma::distr_param(0, 1)) == 1);
    arma::mat mbX = X.rows(idx);
    arma::mat mbY = Y.rows(idx);
    rst.col(b) = smqrTrianIni(mbX, mbY, betaHat, p, tau, tol, iteMax);
  }
  return rst;
}

