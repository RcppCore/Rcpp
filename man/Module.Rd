\name{Module}
\alias{Module}
\title{
Retrieves an Rcpp module
}
\description{
Retrieves an Rcpp module from a dynamic library, usually associated with a 
package.
}
\usage{
Module(module, PACKAGE)
}
\arguments{
\item{module}{Name of the module, as declared in the \code{RCPP_MODULE} macro internally}
\item{PACKAGE}{Passed to \code{\link{getNativeSymbolInfo}}}
}
\value{
	An object of class \linkS4class{Module} collecting functions 
	and classes declared in the module. 
}
\keyword{programming}

