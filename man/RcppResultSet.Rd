\name{RcppResultSet}
\alias{RcppResultSet}
\title{C++ class for sending C++ objects back to R}
\description{
  \code{RcppResultSet} is a C++ class defined in \code{Rcpp.h} that can
  assign any number of C++ objects to \R in a single named list object 
  as the \code{SEXP} return value of a \code{.Call()} function call.
  
  The C++ objects can be of different types that are limited to 
  types  \code{double},  \code{int}, \code{string}, vectors of
  \code{double} or \code{int} (with explicit dimensions),
  matrices of \code{double} or \code{int} (with explicit dimensions), 
  STL vectors of \code{double}, \code{int} or \code{string}, STL
  \sQuote{vector of vectors} of types \code{double} or \code{int} (all
  with implicit dimensions), the internal types \code{RcppDate}, \code{RcppDateVector},
  \code{RcppStringVector}, \code{RcppVector} of types \code{double} or
  \code{int}, \code{RcppMatrix} of types \code{double} or \code{int}
  as well \code{RcppFrame}, a type that can be converted into a
  \code{data.frame}, and the \R type \code{SEXP}. 
  
  Where applicable, the \code{C++} types are automatically converted to the
  corresponding \R types structures around types \code{numeric},
  \code{integer}, or \code{character}.  The \code{C++} code can all be
  retrieved in \R as elements of a named list object.

}
%\usage{
%}
%\arguments{
%}
%\value{
%  Internal to the C++ code.
%}
\details{
  Usage of \code{RcppResultSet} from  \code{C++} is fully defined in
  \code{Rcpp.h}. An example for returning data to \R at the end of a
  \code{.Call()} call follows.
  
  At the C++ level, the corresponding code to assign these parameter to
  C++ objects is can be as follows (taken from the C++ source of
  \code{RcppExample}):
  \preformatted{%
  SEXP rl;
  RcppResultSet rs;
    
  rs.add("date", aDate);	// RcppDate
  rs.add("dateVec", dateVec);	// RcppDateVec
  rs.add("method", method);	// string
  rs.add("tolerance", tol);	// numeric
  rs.add("maxIter", maxIter);	// int
  rs.add("matD", matD);		// RcppMatrix
  rs.add("stlvec", stlvec);	// vector<double> or <int>
  rs.add("stlmat", stlmat);	// vector< vector <double> >
  				//   or <int>
  rs.add("a", a, nrows, ncols);	// double** (or int**) with 
				//   two dimension
  rs.add("v", v, len);		// double* (or int*) with 
				//   one dimension
  rs.add("stringVec", strVec);	// RcppStringVector
  rs.add("strings", svec);	// vector<string>
  rs.add("InputDF", inframe);	// RcppFrame
  rs.add("PreDF", frame);	// RcppFrame

  rl = rs.getReturnList();
  return(rl);
  }

  As the \R level, we assign the returned object a list variables from
  which we select each list element by its name.
  lookup is driven by the names givem at the \R level, order is
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

# example from RcppDate
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
