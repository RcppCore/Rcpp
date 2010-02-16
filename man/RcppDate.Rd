\name{RcppDate}
\alias{RcppDate}
\alias{RcppDatetime}
\alias{RcppDateVector}
\alias{RcppDatetimeVector}
\alias{RcppDateExample}
\title{C++ classes for receiving date and datetime R objects in C++}
\description{
  \code{RcppDate}, \code{RcppDatetime}, \code{RcppDateVector} and
  \code{RcppDatetimeVector} are C++ classes defined in \code{Rcpp.h} that can
  pass scalars and vectors of of \R objects of types \code{Date} and
  \code{POSIXct}, respectively, to C++ via the \code{.Call()} function interface. 
  
  Member functions are provided to query the dimension of the vector or
  matrix object, convert it in a corresponding \code{C} representation.

  \R objects of type \code{Date}, and hence the \code{RcppDate} and
  \code{RcppDateVector} objects, are internally represented as an integer
  counting days since the epoch, i.e. January 1, 1970. Similarly, \R objects of type
  \code{POSIXct} and the \code{RcppDatetime} and
  \code{RcppDatetimeVector} objects, are internally represented as
  seconds since the epoch.  However, \R extends the POSIX standard by
  using a double leading to microsecond precision in timestamps. This is
  fully supported by \code{Rcpp} as well.
}
%\usage{
%}
%\arguments{
%}
%\value{
%  Internal to the C++ code.
%}
\details{
  Usage of the \code{RcppDate}, \code{RcppDatetime} (and their vector
  extensions) in \code{C++} is fully defined in \code{Rcpp.h}. 

  As example, consider a call from \R to \code{C++} such as

  \preformatted{
  # an R example passing one type of each class to a function
  # someFunction in package somePackage
  val <- .Call("someFunction",
               Sys.Date(),        # current date
	       Sys.time(), 	  # current timestamp
	       as.Date("2000-02-25")
	          + 0:5,         # date vector
	       ISOdatetime(1999,12,31,23,59,0)
	          + (0:5)*0.250, # datetime vector
   	       PACKAGE="somePackage")
  }

  At the \code{C++} level, the corresponding code to assign these parameter to
  \code{C++} objects is can be as follows::
  \preformatted{%
  SEXP someFunction(SEXP ds, SEXP dts,
                    SEXP dvs, SEXP dtvs) {

    RcppDate           d(ds);  		      
    RcppDatetime       dt(dts);
    RcppDateVector     dv(dvs);
    RcppDatetimeVector dtv(dtvs);
  }
  }

  Standard accessor functions are defined, see \code{Rcpp.h} for details.

  Objects of these types can also be returned via \code{RcppResultSet}. 

}
%\references{
%  See \code{Rcpp.h} and the package vignette.
%}
\seealso{
  \code{RcppResultSet}, the vignette \dQuote{RcppAPI}.
}
\author{Dominick Samperi wrote most of Rcpp during 2005 and 2006.  Dirk
  Eddelbuettel made some additions, and became maintainer in 2008.}
\examples{

# set up date and datetime vectors
dvec <- Sys.Date() + -2:2
dtvec <- Sys.time() + (-2:2)*0.5

# call the underlying  C++ function
result <- RcppDateExample(dvec, dtvec)

# inspect returned object
result
}
\keyword{programming}
\keyword{interface}
