// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// sgn
int sgn(const double x);
RcppExport SEXP _conquer_sgn(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(sgn(x));
    return rcpp_result_gen;
END_RCPP
}
// mad
double mad(const arma::vec& x);
RcppExport SEXP _conquer_mad(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(mad(x));
    return rcpp_result_gen;
END_RCPP
}
// updateHuber
void updateHuber(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, const int n, const double tau, const double n1);
RcppExport SEXP _conquer_updateHuber(SEXP ZSEXP, SEXP resSEXP, SEXP derSEXP, SEXP gradSEXP, SEXP nSEXP, SEXP tauSEXP, SEXP n1SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type res(resSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type der(derSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type grad(gradSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const double >::type n1(n1SEXP);
    updateHuber(Z, res, der, grad, n, tau, n1);
    return R_NilValue;
END_RCPP
}
// huberReg
arma::vec huberReg(const arma::mat& Z, const arma::vec& Y, arma::vec& der, arma::vec& gradOld, arma::vec& gradNew, const int n, const int p, const double n1, const double tol, const double constTau, const int iteMax);
RcppExport SEXP _conquer_huberReg(SEXP ZSEXP, SEXP YSEXP, SEXP derSEXP, SEXP gradOldSEXP, SEXP gradNewSEXP, SEXP nSEXP, SEXP pSEXP, SEXP n1SEXP, SEXP tolSEXP, SEXP constTauSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type der(derSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gradOld(gradOldSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gradNew(gradNewSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type n1(n1SEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(huberReg(Z, Y, der, gradOld, gradNew, n, p, n1, tol, constTau, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// standardize
arma::mat standardize(arma::mat X, const arma::rowvec& mx, const arma::vec& sx, const int p);
RcppExport SEXP _conquer_standardize(SEXP XSEXP, SEXP mxSEXP, SEXP sxSEXP, SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type mx(mxSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type sx(sxSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(standardize(X, mx, sx, p));
    return rcpp_result_gen;
END_RCPP
}
// updateGauss
void updateGauss(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, const double tau, const double n1, const double h1);
RcppExport SEXP _conquer_updateGauss(SEXP ZSEXP, SEXP resSEXP, SEXP derSEXP, SEXP gradSEXP, SEXP tauSEXP, SEXP n1SEXP, SEXP h1SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type res(resSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type der(derSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type grad(gradSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const double >::type n1(n1SEXP);
    Rcpp::traits::input_parameter< const double >::type h1(h1SEXP);
    updateGauss(Z, res, der, grad, tau, n1, h1);
    return R_NilValue;
END_RCPP
}
// updateUnif
void updateUnif(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, const int n, const double tau, const double h, const double n1, const double h1);
RcppExport SEXP _conquer_updateUnif(SEXP ZSEXP, SEXP resSEXP, SEXP derSEXP, SEXP gradSEXP, SEXP nSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP n1SEXP, SEXP h1SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type res(resSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type der(derSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type grad(gradSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type n1(n1SEXP);
    Rcpp::traits::input_parameter< const double >::type h1(h1SEXP);
    updateUnif(Z, res, der, grad, n, tau, h, n1, h1);
    return R_NilValue;
END_RCPP
}
// updatePara
void updatePara(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, const int n, const double tau, const double h, const double n1, const double h1, const double h3);
RcppExport SEXP _conquer_updatePara(SEXP ZSEXP, SEXP resSEXP, SEXP derSEXP, SEXP gradSEXP, SEXP nSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP n1SEXP, SEXP h1SEXP, SEXP h3SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type res(resSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type der(derSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type grad(gradSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type n1(n1SEXP);
    Rcpp::traits::input_parameter< const double >::type h1(h1SEXP);
    Rcpp::traits::input_parameter< const double >::type h3(h3SEXP);
    updatePara(Z, res, der, grad, n, tau, h, n1, h1, h3);
    return R_NilValue;
END_RCPP
}
// updateTrian
void updateTrian(const arma::mat& Z, const arma::vec& res, arma::vec& der, arma::vec& grad, const int n, const double tau, const double h, const double n1, const double h1, const double h2);
RcppExport SEXP _conquer_updateTrian(SEXP ZSEXP, SEXP resSEXP, SEXP derSEXP, SEXP gradSEXP, SEXP nSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP n1SEXP, SEXP h1SEXP, SEXP h2SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type Z(ZSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type res(resSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type der(derSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type grad(gradSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type n1(n1SEXP);
    Rcpp::traits::input_parameter< const double >::type h1(h1SEXP);
    Rcpp::traits::input_parameter< const double >::type h2(h2SEXP);
    updateTrian(Z, res, der, grad, n, tau, h, n1, h1, h2);
    return R_NilValue;
END_RCPP
}
// smqrGauss
Rcpp::List smqrGauss(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrGauss(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrGauss(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrGaussNsd
Rcpp::List smqrGaussNsd(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrGaussNsd(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrGaussNsd(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrGaussIni
arma::vec smqrGaussIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau, double h, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrGaussIni(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrGaussIni(X, Y, betaHat, p, tau, h, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrUnif
Rcpp::List smqrUnif(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrUnif(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrUnif(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrUnifNsd
Rcpp::List smqrUnifNsd(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrUnifNsd(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrUnifNsd(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrUnifIni
arma::vec smqrUnifIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau, double h, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrUnifIni(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrUnifIni(X, Y, betaHat, p, tau, h, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrPara
Rcpp::List smqrPara(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrPara(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrPara(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrParaNsd
Rcpp::List smqrParaNsd(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrParaNsd(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrParaNsd(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrParaIni
arma::vec smqrParaIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau, double h, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrParaIni(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrParaIni(X, Y, betaHat, p, tau, h, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrTrian
Rcpp::List smqrTrian(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrTrian(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrTrian(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrTrianNsd
Rcpp::List smqrTrianNsd(const arma::mat& X, const arma::vec& Y, const double tau, double h, const double constTau, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrTrianNsd(SEXP XSEXP, SEXP YSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP constTauSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type constTau(constTauSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrTrianNsd(X, Y, tau, h, constTau, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrTrianIni
arma::vec smqrTrianIni(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int p, const double tau, double h, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrTrianIni(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP hSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type h(hSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrTrianIni(X, Y, betaHat, p, tau, h, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrGaussInf
arma::mat smqrGaussInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau, const int B, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrGaussInf(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP nSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP BSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const int >::type B(BSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrGaussInf(X, Y, betaHat, n, p, tau, B, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrUnifInf
arma::mat smqrUnifInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau, const int B, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrUnifInf(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP nSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP BSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const int >::type B(BSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrUnifInf(X, Y, betaHat, n, p, tau, B, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrParaInf
arma::mat smqrParaInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau, const int B, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrParaInf(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP nSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP BSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const int >::type B(BSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrParaInf(X, Y, betaHat, n, p, tau, B, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}
// smqrTrianInf
arma::mat smqrTrianInf(const arma::mat& X, const arma::vec& Y, const arma::vec& betaHat, const int n, const int p, const double tau, const int B, const double tol, const int iteMax);
RcppExport SEXP _conquer_smqrTrianInf(SEXP XSEXP, SEXP YSEXP, SEXP betaHatSEXP, SEXP nSEXP, SEXP pSEXP, SEXP tauSEXP, SEXP BSEXP, SEXP tolSEXP, SEXP iteMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type betaHat(betaHatSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    Rcpp::traits::input_parameter< const int >::type p(pSEXP);
    Rcpp::traits::input_parameter< const double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< const int >::type B(BSEXP);
    Rcpp::traits::input_parameter< const double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< const int >::type iteMax(iteMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(smqrTrianInf(X, Y, betaHat, n, p, tau, B, tol, iteMax));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_conquer_sgn", (DL_FUNC) &_conquer_sgn, 1},
    {"_conquer_mad", (DL_FUNC) &_conquer_mad, 1},
    {"_conquer_updateHuber", (DL_FUNC) &_conquer_updateHuber, 7},
    {"_conquer_huberReg", (DL_FUNC) &_conquer_huberReg, 11},
    {"_conquer_standardize", (DL_FUNC) &_conquer_standardize, 4},
    {"_conquer_updateGauss", (DL_FUNC) &_conquer_updateGauss, 7},
    {"_conquer_updateUnif", (DL_FUNC) &_conquer_updateUnif, 9},
    {"_conquer_updatePara", (DL_FUNC) &_conquer_updatePara, 10},
    {"_conquer_updateTrian", (DL_FUNC) &_conquer_updateTrian, 10},
    {"_conquer_smqrGauss", (DL_FUNC) &_conquer_smqrGauss, 7},
    {"_conquer_smqrGaussNsd", (DL_FUNC) &_conquer_smqrGaussNsd, 7},
    {"_conquer_smqrGaussIni", (DL_FUNC) &_conquer_smqrGaussIni, 8},
    {"_conquer_smqrUnif", (DL_FUNC) &_conquer_smqrUnif, 7},
    {"_conquer_smqrUnifNsd", (DL_FUNC) &_conquer_smqrUnifNsd, 7},
    {"_conquer_smqrUnifIni", (DL_FUNC) &_conquer_smqrUnifIni, 8},
    {"_conquer_smqrPara", (DL_FUNC) &_conquer_smqrPara, 7},
    {"_conquer_smqrParaNsd", (DL_FUNC) &_conquer_smqrParaNsd, 7},
    {"_conquer_smqrParaIni", (DL_FUNC) &_conquer_smqrParaIni, 8},
    {"_conquer_smqrTrian", (DL_FUNC) &_conquer_smqrTrian, 7},
    {"_conquer_smqrTrianNsd", (DL_FUNC) &_conquer_smqrTrianNsd, 7},
    {"_conquer_smqrTrianIni", (DL_FUNC) &_conquer_smqrTrianIni, 8},
    {"_conquer_smqrGaussInf", (DL_FUNC) &_conquer_smqrGaussInf, 9},
    {"_conquer_smqrUnifInf", (DL_FUNC) &_conquer_smqrUnifInf, 9},
    {"_conquer_smqrParaInf", (DL_FUNC) &_conquer_smqrParaInf, 9},
    {"_conquer_smqrTrianInf", (DL_FUNC) &_conquer_smqrTrianInf, 9},
    {NULL, NULL, 0}
};

RcppExport void R_init_conquer(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
