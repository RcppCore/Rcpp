\name{Rcpp-package}
\alias{Rcpp-package}
\alias{Rcpp}
\docType{package}
\title{R / C++ interface}
\description{The \pkg{Rcpp} package provides C++ classes that
  greatly facilitate interfacing C or C++ code in \R packages using
  the \code{.Call} interface provided by \R.
}
\section{Overview}{
	
  \pkg{Rcpp} provides matching C++ classes for a large number of
  basic \R data types. Hence, a package author can keep his data in
  normal R data structure without having to worry about translation or
  transfer to C++. At the same time, the data structures can be accessed
  as easily at the C++ level, and used in the normal manner.

  The mapping of data types works in both directions. It is as
  straightforward to pass data from R to C++, as it is it return data
  from C++ to \R.  The following two sections list supported data types.
}
\section{Transfer from R to C++}{
  Standard \R datatypes that are understood are
  \enumerate{
    \item named lists containing numeric (i.e. floating point), integer,
    character, logical (i.e. boolean) or Date and Datetime
    (i.e. POSIXct) arguments;
    \item data frames containing numeric, integer, logical, character,
    Date, Datetime or Factor columns;
    \item named vectors containing numeric or integer values,
    \item vectors and matrices of different values
    \item character strings
  }
}
\section{Transfer from C++ to R}{
  Standard C++ datatypes can be returned to \R in a named list, the most
  general data type in \R.  Permissible components of the returns list
  are the following C++ types:
  \enumerate{
    \item double (scalar as well as vectors and vectors of vectors),
    \item int (scalar as well as vectors and vectors of vectors),
    \item string,
    \item STL vector types and vector<vector> types of int and double
    \item STL vector of strings
    \item internal Rcpp types RcppDate, RcppDateVector, RcppDatetime,
  RcppDatetimeVector, RcppStringVector, RcppVector of int or double,
  RcppMatrix of int or double, RcppFrame}
}
\section{Usage for package building}{
	The "Rcpp-package" vignette documents how to use Rcpp in client packages.
}
\author{Dominick Samperi wrote the initial versions of Rcpp (and
  RcppTemplate) during 2005 and 2006.  Dirk Eddelbuettel made some
  additions, and became maintainer in 2008. Dirk Eddelbuettel and Romain
  Francois have been extending Rcpp since 2009.
}
\examples{
\dontrun{
# information on how to build a package that uses Rcpp
vignette( "Rcpp-package" )	
}
}
\keyword{programming}
\keyword{interface}
