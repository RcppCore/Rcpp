#!/usr/bin/r

library(inline)
library(rbenchmark)

serialCode <- '
   // assign to C++ vector
   std::vector<double> x = Rcpp::as<std::vector< double > >(xs);
   size_t n = x.size();
   for (size_t i=0; i<n; i++) {
       x[i] = ::log(x[i]);
   }
   return Rcpp::wrap(x);
'
funSerial <- cxxfunction(signature(xs="numeric"), body=serialCode, plugin="Rcpp")

## same, but with Rcpp vector just to see if there is measurable difference
serialRcppCode <- '
   // assign to C++ vector
   Rcpp::NumericVector x = Rcpp::NumericVector(xs);
   size_t n = x.size();
   for (size_t i=0; i<n; i++) {
       x[i] = ::log(x[i]);
   }
   return x;
'
funSerialRcpp <- cxxfunction(signature(xs="numeric"), body=serialRcppCode, plugin="Rcpp")

## now with a sugar expression with internalizes the loop
sugarRcppCode <- '
   // assign to C++ vector
   Rcpp::NumericVector x = log ( Rcpp::NumericVector(xs) );
   return x;
'
funSugarRcpp <- cxxfunction(signature(xs="numeric"), body=sugarRcppCode, plugin="Rcpp")

## lastly via OpenMP for parallel use
openMPCode <- '
   // assign to C++ vector
   std::vector<double> x = Rcpp::as<std::vector< double > >(xs);
   size_t n = x.size();
#pragma omp parallel for shared(x, n)
   for (size_t i=0; i<n; i++) {
       x[i] = ::log(x[i]);
   }
   return Rcpp::wrap(x);
'

## modify the plugin for Rcpp to support OpenMP
settings <- getPlugin("Rcpp")
settings$env$PKG_CXXFLAGS <- paste('-fopenmp', settings$env$PKG_CXXFLAGS)
settings$env$PKG_LIBS <- paste('-fopenmp -lgomp', settings$env$PKG_LIBS)

funOpenMP <- cxxfunction(signature(xs="numeric"), body=openMPCode, plugin="Rcpp", settings=settings)


z <- seq(1, 2e6)
res <- benchmark(funSerial(z), funOpenMP(z),
                 funSerialRcpp(z), funSugarRcpp(z),
                 columns=c("test", "replications", "elapsed",
                           "relative", "user.self", "sys.self"),
                 order="relative",
                 replications=100)
print(res)


