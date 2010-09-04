#!/usr/bin/r

set.seed(42)
a <- rnorm(100)
b <- rnorm(100)

## load shared library with wrapper code and callback class
dyn.load("convolve2_c.so")

## call the wrapper function provided in the shared library
v1 <- .Call("convolve2", a, b)
t1 <- system.time(replicate(1000, .Call("convolve2", a, b)))


## load shared library with wrapper code and callback class
dyn.load("convolve2_cpp.so")

## call the wrapper function provided in the shared library
v2 <- .Call("convolve2cpp", a, b)[[1]]
t2 <- system.time(replicate(1000, .Call("convolve2cpp", a, b)))


## load shared library with wrapper code and callback class
dyn.load("convolve3_cpp.so")

## call the wrapper function provided in the shared library
v3 <- .Call("convolve3cpp", a, b)
t3 <- system.time(replicate(1000, .Call("convolve3cpp", a, b)))


## load shared library with wrapper code and callback class
dyn.load("convolve4_cpp.so")

## call the wrapper function provided in the shared library
v4 <- .Call("convolve4cpp", a, b)
t4 <- system.time(replicate(1000, .Call("convolve4cpp", a, b)))


## load the sugar based version
dyn.load( "convolve5_cpp.so" )
v5 <- .Call( "convolve5cpp", a, b )
t5 <- system.time(replicate(1000, .Call("convolve5cpp", a, b)))


## load shared library with wrapper code and callback class
dyn.load("convolve7_c.so")

## call the wrapper function provided in the shared library
v7 <- .Call("convolve7", a, b)
t7 <- system.time(replicate(1000, .Call("convolve7", a, b)))


res <- data.frame(rbind(t1, t7, t2, t3, t4, t5))
rownames(res) <- c("Writing R extensions",
                   "Less careful use of R API",
                   "RcppVector<double>::operator()",
                   "Rcpp::NumericVector::operator[]",
                   "Rcpp::NumericVector::begin()",
                   "sugar" )
print(res[,1:3])

results <- list( v1, v2, v3, v4, v7, v5)
for (i in seq_along(results) ){
    stopifnot( all.equal(results[[1L]], results[[i]] ) )
}
cat("All results are equal\n") # as we didn't get stopped

