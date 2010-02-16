\name{RcppParams}
\alias{RcppParams}
\alias{RcppParamsExample}
\title{C++ class for receiving (scalar) parameters from R}
\description{
  \code{RcppParams} is a C++ class defined in \code{Rcpp.h} that receive
  any number of scalar parameters of types in a single named list object
  from \R through the \code{.Call()} function.
  
  The parameters can be of different types that are limited to the \R
  types \code{numeric}, \code{integer}, \code{character}, \code{logical}
  or \code{Date}. These types are mapped into, respectively, the
  corresponding C++ types \code{double},  \code{int}, \code{string},
  \code{bool} and \code{Date} (a custom class defined by \code{Rcpp}.
}
\usage{
  val <- RcppParamsExample(params) 
}
\arguments{
  \item{params}{A heterogeneous list specifying \code{method} (string),
    \code{tolerance} (double), \code{maxIter} (int) and \code{startDate}
  (Date in R, RcppDate in C++).}
}
\value{
  \code{RcppExample} returns a list containing:
  \item{method}{string input paramter}
  \item{tolerance}{double input paramter}
  \item{maxIter}{int input parameter}
  \item{startDate}{Date type with starting date}
  \item{params}{input parameter list (this is redundant because we
    returned the input parameters above)}
}
\details{
  Usage of \code{RcppParams} from \R via \code{.Call()} is as follows:
  \preformatted{%
  # an R example passing one type of each class to a function
  # someFunction in package somePackage
  val <- .Call("someFunction",
               list(pie=3.1415, magicanswer=42, sometext="foo",
                    yesno=true, today=Sys.date()),
		    PACKAGE="somePackage")
  }

  At the C++ level, the corresponding code to assign these parameter to
  C++ objects is 
  \preformatted{%
  SEXP someFunction(SEXP params) {
    RcppParams par(params);
    double p   = par.getDoubleValue("pie");
    int magic  = par.getIntValue("magicanswer");
    string txt = par.getStringValue("sometext");
    bool yn    = par.getBoolValue("yesno");
    RcppDate d = par.getDateValue("today");
    // some calculations ...
    // some return values ...
  }
  }
  As the lookup is driven by the names givem at the \R level, order is
  not important.  It is however important that the types match. Errors
  are typically caught and an exception is thrown. 

  The class member function \code{checkNames} can be used to verify that the
  \code{SEXP} object passed to the function contains a given set of
  named object.
}
%\references{
%  See \code{Rcpp.h} and the package vignette.
%}
\seealso{
  \code{RcppExample}, the vignette \dQuote{RcppAPI}.
}
\author{Dominick Samperi wrote most of Rcpp during 2005 and 2006.  Dirk
  Eddelbuettel made some additions, and became maintainer in 2008.}
\examples{

# set up some value
params <- list(method='BFGS',
               tolerance=1.0e-5,
               maxIter=100,
               startDate=as.Date('2006-7-15'))

# call the underlying  C++ function
result <- RcppParamsExample(params)

# inspect returned object
result

}
\keyword{programming}
\keyword{interface}
