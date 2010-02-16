#!/usr/bin/r

x11(width=3,height=3)
par(mar=c(3,3,1,1),cex=0.8, pch=19)

# named list of parameters passed to C++; here only one scalar int used
params <- list(N=10)

# vector we operate on with R function called from C++
xvec <- sqrt(c(1:12, 11:1))

# R function that will be called from C++
vecfunc <- function(x) {
    y <- x^1.05                         # do a transformation
    print(y)                            # but also print
    plot(y, ylim=c(1,8), type='b')      # and even plot
    Sys.sleep(0.225)                    # sleep before next call
    return(y)
}

# load shared library with wrapper code and callback class
dyn.load("RcppFunctionCallExample.so")

# call the wrapper function provided in the shared library
val <- .Call("RCppFunctionCallWrapper", params, xvec, vecfunc)






