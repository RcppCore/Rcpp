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
Module(module, PACKAGE = , where = , mustStart =  )
}
\arguments{
\item{module}{Name of the module, as declared in the \code{RCPP_MODULE} macro internally}
\item{PACKAGE}{Passed to \code{\link{getNativeSymbolInfo}}}
\item{where}{When the module is loaded, S4 classes are defined based on the 
	internal classes. This argument is passed to \code{\link{setClass}}
}
\item{mustStart}{TODO}
}
\value{
	An object of class \linkS4class{Module} collecting functions 
	and classes declared in the module. 
}
\keyword{programming}

