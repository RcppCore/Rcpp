\name{setRcppClass}
\alias{setRcppClass}
\alias{RcppClass-class}
\title{
Define a Reference Class containing a C++ Class
}
\description{
Function \code{setRcppClass} creates an extended reference class that
contains an interface to a C++ class, typically as exposed by an Rcpp
\code{\link{Module}}.  The Rcpp class can have R-based fields and
methods in addition to those from the C++ class.
}
\usage{
setRcppClass(Class, CppClass = , fields = list(), contains = character(), methods = list(), where = topenv(parent.frame()), ...)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{Class}{
The name of the class to be defined.
}
  \item{CppClass}{
The C++ class extended by this class, usually a class specified in an
Rcpp \code{\link{Module}}.
}
  \item{fields, contains, methods, where, \dots}{
Arguments to \code{\link{setRefClass}}, extended in the case of
\code{contains=} to include the C++ class.
}
}
\value{
A generator object for the reference class.  The generator object is
from class \code{"rcppObjectGenerator"}, with some extra slots to hold
information about the contained C++ class.
}
\author{
John Chambers
}
\examples{
\dontrun{
### Following the vignette for Module exporting C++ class Uniform
### The class randU extends the C++ class to maintain seed for the RNG
### (An example of a reproducible simulation utility, protected
### from any other random number generation.  Class "Rseed", not shown,
###  mainly exists to print random seeds in a user-readable form.)
randU <- setRcppClass("randU", Uniform,
    fields = list(startSeed = "Rseed", currentSeed = "Rseed"),
    methods = list(
    set.seed = function(seed) {
        base::set.seed(seed)
        startSeed <<- as(.Random.seed, "Rseed")
        currentSeed <<- startSeed
        invisible(currentSeed)
    },
    draw = function(...) {
        if(exists(".Random.seed",envir = .GlobalEnv)) {
            previous <- get(".Random.seed", envir= .GlobalEnv)
            on.exit(assign(".Random.seed", previous, envir = .GlobalEnv))
        }
        else
            on.exit(remove(".Random.seed", envir = .GlobalEnv))
        assign(".Random.seed", currentSeed, envir = .GlobalEnv)
        value <- callSuper(...)
        currentSeed <<- as(get(".Random.seed", envir = .GlobalEnv),
                           "Rseed")
        value
    }
    )
)
randU$lock("startSeed")
}
\dontrun{

## This class can be used with mixed R/C++ methods:

ru <- randU$new(0,10)
ru$set.seed(429)
ru$draw(10)
}
}
\keyword{ programming }
\keyword{ classes }
