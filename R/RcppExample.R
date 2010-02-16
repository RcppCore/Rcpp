RcppExample <- function(params, nlist, numvec, nummat, df, datevec, stringvec,
                        fnvec, fnlist) {

    ## Most of the input parameter checking here is not really
    ## necessary because it is done in the Rcpp code.

    ## Check that params is properly formatted.
    if (missing(params)) {
        cat("Setting default argument for params\n")
        params <- list(method='BFGS',
                       tolerance=1.0e-8,
                       maxIter=1000,
                       startDate=as.Date('2006-7-15'))
    }

    ## Check nlist
    if (missing(nlist)) {
        cat("Setting default argument for nlist\n")
        nlist <- list(ibm = 80.50, hp = 53.64, c = 45.41)
    } else if (!is.numeric(unlist(nlist))) {
        stop("The values in nlist must be numeric")
    }

    ## Check numvec
    if (missing(numvec)) {
        cat("Setting default argument for numvec\n")
        numvec <- seq(1,5) 			# numerical vector
    } else if (!is.vector(numvec)) {         ## Check numvec argument
        stop("numvec must be a vector");
    }

    ## Check nummat
    if (missing(nummat)) {
        cat("Setting default argument for nummat\n")
        nummat <- matrix(seq(1,20),4,5) # numerical matrix
    } else if (!is.matrix(nummat)) {
        stop("nummat must be a matrix");
    }

    ## Check df
    if (missing(df)) {
        cat("Setting default argument for data frame\n")
        df <- data.frame(a=c(TRUE, TRUE, FALSE), b=I(c('a','b','c')))
    }

    ## Check datevec
    if (missing(datevec)) {
        cat("Setting default argument for date vector\n")
        datestr <- c('2006-6-10', '2006-7-12', '2006-8-10')
        datevec <- as.Date(datestr, "%Y-%m-%d") # date vector
    }

    ## Check stringvec
    if (missing(stringvec)) {
        cat("Setting default argument for string vector\n")
        stringvec <- c("hello", "world", "fractal") # string vector
    }

    ## Check fnvec
    if (missing(fnvec)) {
        cat("Setting default argument for function vector\n")
        fnvec <- function(x) { sum(x) } # Add up components of vector
    }

    ## Check fnlist
    if (missing(fnlist)) {
        cat("Setting default argument for function list\n")
        fnlist <- function(l) { # Return vector with 1 added to each component
            vec <- c(l$alpha + 1, l$beta + 1, l$gamma + 1)
            vec
        }
    }

    ## Finally ready to make the call...
    val <- .Call("Rcpp_Example", params, nlist, numvec, nummat,
                 df, datevec, stringvec, fnvec, fnlist,
                 PACKAGE="Rcpp"
                 )

    ## Define a class for the return value so we can control what gets
    ## printed when a variable assigned this value is typed on a line by itself.
    ## This has the effect of calling the function print.RcppExample(). The
    ## function (defined below) simply prints the names of the fields that are
    ## available. Access each field with val$name.
    class(val) <- "RcppExample"

    val
}

print.RcppExample <- function(x,...) {
    cat('\nIn R, names defined in RcppExample return list:\n')
    cat('(Use result$name or result[[i]] to access)\n')
    namevec <- names(x)
    for(i in 1:length(namevec)) {
        cat(format(i, width=2), ': ', format(namevec[i], width=12))
        if (is.atomic(x[[i]])) {
            cat(format(x[[i]]))
        } else {
            cat(format("..."))
        }
        cat('\n')
    }
}

RcppParamsExample <- function(params) {

    ## Check that params is properly set.
    if (missing(params)) {
        cat("\nIn R, setting default argument for params\n")
        params <- list(method='BFGS',
                       tolerance=1.0e-8,
                       maxIter=1000,
                       startDate=as.Date('2006-7-15'))
    }

    ## Make the call...
    val <- .Call("RcppParamsExample",
                 params,
                 PACKAGE="Rcpp")

    ## Define a class for the return value so we can control what gets
    ## printed when a variable assigned this value is typed on a line by itself.
    ## This has the effect of calling the function print.RcppExample(). The
    ## function (defined below) simply prints the names of the fields that are
    ## available. Access each field with val$name.
    class(val) <- "RcppExample"

    val
}

RcppDateExample <- function(dv, dtv) {

    ## Check that params is properly set.
    if (missing(dv)) {
        cat("\nIn R, setting default argument for dv\n")
        dv <- Sys.Date() + -2:2
    }

    if (missing(dtv)) {
        cat("\nIn R, setting default argument for dtv\n")
        dtv <- Sys.time() + (-2:2)*0.5
    }

    ## Make the call...
    val <- .Call("RcppDateExample",
                 dv, dtv,
                 PACKAGE="Rcpp")

    ## Define a class for the return value so we can control what gets
    ## printed when a variable assigned this value is typed on a line by itself.
    ## This has the effect of calling the function print.RcppExample(). The
    ## function (defined below) simply prints the names of the fields that are
    ## available. Access each field with val$name.
    class(val) <- "RcppExample"

    val
}

RcppVectorExample <- function(v) {

    ## Check that params is properly set.
    if (missing(v)) {
        cat("\nIn R, setting default argument for v\n")
        v <- seq(1,9)^2
    }

    ## Make the call...
    val <- .Call("RcppVectorExample",
                 v,
                 PACKAGE="Rcpp")

    ## Define a class for the return value so we can control what gets
    ## printed when a variable assigned this value is typed on a line by itself.
    ## This has the effect of calling the function print.RcppExample(). The
    ## function (defined below) simply prints the names of the fields that are
    ## available. Access each field with val$name.
    class(val) <- "RcppExample"

    val
}
