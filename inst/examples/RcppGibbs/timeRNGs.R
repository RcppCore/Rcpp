
suppressMessages(library(Rcpp))
suppressMessages(library(inline))
suppressMessages(library(rbenchmark))

rcppGamma <- cxxfunction(signature(xs="numeric"), plugin="Rcpp", body='
  NumericVector x(xs);
  int n   = x.size();

  // Initialize Random number generator
  RNGScope scope;

  const double y = 1.234;
  for (int i=0; i<n; i++) {
    x[i] = ::Rf_rgamma(3.0, 1.0/(y*y+4));
  }

  // Return to R
  return x;
')


gslGamma <- cxxfunction(signature(xs="numeric"), plugin="RcppGSL",
                        include='#include <gsl/gsl_rng.h>
                                 #include <gsl/gsl_randist.h>',
                        body='
  NumericVector x(xs);
  int n   = x.size();

  gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
  const double y = 1.234;
  for (int i=0; i<n; i++) {
    x[i] = gsl_ran_gamma(r,3.0,1.0/(y*y+4));
  }
  gsl_rng_free(r);

  // Return to R
  return x;
')


rcppNormal <- cxxfunction(signature(xs="numeric"), plugin="Rcpp", body='
  NumericVector x(xs);
  int n   = x.size();

  // Initialize Random number generator
  RNGScope scope;

  const double y = 1.234;
  for (int i=0; i<n; i++) {
    x[i] = ::Rf_rnorm(1.0/(y+1),1.0/sqrt(2*y+2));
  }

  // Return to R
  return x;
')


gslNormal <- cxxfunction(signature(xs="numeric"), plugin="RcppGSL",
                        include='#include <gsl/gsl_rng.h>
                                 #include <gsl/gsl_randist.h>',
                        body='
  NumericVector x(xs);
  int n   = x.size();

  gsl_rng *r = gsl_rng_alloc(gsl_rng_mt19937);
  const double y = 1.234;
  for (int i=0; i<n; i++) {
    x[i] = 1.0/(y+1)+gsl_ran_gaussian(r,1.0/sqrt(2*y+2));
  }
  gsl_rng_free(r);

  // Return to R
  return x;
')


x <- rep(NA, 1e6)
res <- benchmark(rcppGamma(x),
                 gslGamma(x),
                 rcppNormal(x),
                 gslNormal(x),
                 columns=c("test", "replications", "elapsed", "relative", "user.self", "sys.self"),
                 order="relative",
                 replications=20)
print(res)


