#include <Rcpp.h>

// [[Rcpp::export]]
double sumTest(Rcpp::NumericVector v, int begin, int end) {
	return Rcpp::algorithm::sum(v.begin() + (begin - 1), v.begin() + end);
}

// [[Rcpp::export]]
double prodTest(Rcpp::NumericVector v, int begin, int end) {
	return Rcpp::algorithm::prod(v.begin() + (begin - 1), v.begin() + end);
}

// [[Rcpp::export]]
Rcpp::NumericVector logTest(Rcpp::NumericVector v) {
	Rcpp::NumericVector x = Rcpp::clone(v);
	Rcpp::algorithm::log(v.begin(), v.end(), x.begin());
	return x;
}

// [[Rcpp::export]]
Rcpp::NumericVector expTest(Rcpp::NumericVector v) {
	Rcpp::NumericVector x = Rcpp::clone(v);
	Rcpp::algorithm::exp(v.begin(), v.end(), x.begin());
	return x;
}

// [[Rcpp::export]]
Rcpp::NumericVector sqrtTest(Rcpp::NumericVector v) {
	Rcpp::NumericVector x = Rcpp::clone(v);
	Rcpp::algorithm::sqrt(v.begin(), v.end(), x.begin());
	return x;
}
