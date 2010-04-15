\name{cppfunction}
\alias{cppfunction}
\title{
Functionality to dynamically define R functions
with inlined c++ code that uses Rcpp classes
}
\description{
\code{cppfunction} is a slightly modified version of \link[inline]{cfunction} 
}
\usage{
cppfunction(sig = character(), body = character(), includes = character(), 
otherdefs = character(), verbose = FALSE, cppargs = character(), 
cxxargs = character(), libargs = character(), .Cpp = TRUE, namespace = TRUE)
}
\arguments{
\item{sig}{Signature. See \link[inline]{cfunction}}
\item{body}{C++ code to inline. See \link[inline]{cfunction}}
\item{includes}{See \link[inline]{cfunction}}
\item{otherdefs}{See \link[inline]{cfunction}}
\item{verbose}{See \link[inline]{cfunction}}
\item{cppargs}{See \link[inline]{cfunction}}
\item{cxxargs}{See \link[inline]{cfunction}}
\item{libargs}{See \link[inline]{cfunction}}
\item{.Cpp}{If \code{TRUE} (which is the default and is recommended), 
  	  the call to \link{.Call} is replaced by a call to \link{.Cpp}
  	  which is identical except that it handles c++ exceptions
}
\item{namespace}{If \code{TRUE} the line "using namespace Rcpp; " is added
to the includes list}
}
\details{
	As opposed to \link[inline]{cfunction}, this function can only code 
	that is designed to use the \link{.Call} interface, the language is 
	restricted to C++ and the \code{Rcpp} argument of \link[inline]{cfunction}
	is set to \code{TRUE}
}
\value{
An R function, similar to the returned value of \link[inline]{cfunction}
}
\references{
Oleg Sklyar, Duncan Murdoch, Mike Smith and Dirk Eddelbuettel (2009).
  inline: Inline C, C++, Fortran function calls from R. R package
  version 0.3.4. \url{http://CRAN.R-project.org/package=inline}
}
\examples{
\dontrun{
fx <- cppfunction( body = "return IntegerVector::create( 1, 2, 3) ;" )
stopifnot( identical( fx(), 1:3 ) ) 
}
}
\keyword{interface}
