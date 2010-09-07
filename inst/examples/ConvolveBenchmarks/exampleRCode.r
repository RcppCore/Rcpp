#!/usr/bin/r

set.seed(42)
a <- rnorm(100)
b <- rnorm(100)

## load shared libraries with wrapper code
dyn.load("convolve2_c.so")
dyn.load("convolve2_cpp.so")
dyn.load("convolve3_cpp.so")
dyn.load("convolve4_cpp.so")
dyn.load("convolve5_cpp.so")
dyn.load("convolve7_c.so")

## now run each one once for comparison of results,
## and define test functions

v1 <- .Call("convolve2", a, b)
R_API_optimised <- function(a,b) .Call("convolve2", a, b)

v2 <- .Call("convolve2cpp", a, b)[[1]]
stopifnot(all.equal(v1, v2))
Rcpp_Classic <- function(a,b) .Call("convolve2cpp", a, b)

v3 <- .Call("convolve3cpp", a, b)
stopifnot(all.equal(v1, v3))
Rcpp_New_std <- function(a,b) .Call("convolve3cpp", a, b)

v4 <- .Call("convolve4cpp", a, b)
stopifnot(all.equal(v1, v4))
Rcpp_New_ptr <- function(a,b) .Call("convolve4cpp", a, b)

v5 <- .Call( "convolve5cpp", a, b )
stopifnot(all.equal(v1, v5))
Rcpp_New_sugar <- function(a,b) .Call("convolve5cpp", a, b)

v7 <- .Call("convolve7", a, b)
R_API_naive <- function(a,b) .Call("convolve7", a, b)

## load benchmarkin helper function
suppressMessages(library(rbenchmark))
bm <- benchmark(R_API_optimised(a,b),
                R_API_naive(a,b),
                Rcpp_Classic(a,b),
                Rcpp_New_std(a,b),
                Rcpp_New_ptr(a,b),
                Rcpp_New_sugar(a,b),
                columns=c("test", "replications", "elapsed", "relative", "user.self", "sys.self"),
                order="relative",
                replications=10000)
print(bm)

cat("All results are equal\n") # as we didn't get stopped

