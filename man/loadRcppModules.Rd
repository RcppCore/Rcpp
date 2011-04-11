\name{loadRcppModules}
\alias{loadRcppModules}
\title{
Loads Rcpp modules on package startup
}
\description{
Function to simplify loading Rcpp modules contained in a package. 
This function must be called from the \code{.onLoad} function of a package. 
It uses the \code{RcppModules} field of the package \code{DESCRIPTION} file
to query the names of the modules that the package should export, loads each module, 
and \code{\link{populate}} each module into the package NAMESPACE.
}
\usage{
loadRcppModules()
}
\seealso{
    \code{\link{populate}}
}
\keyword{interface}

