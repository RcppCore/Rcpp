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
  \pkg{Rcpp} provides a header file and a library inside the installed
  package in the directory \code{lib}. From within \R, you can compute
  the directory location via \code{system.file("include", "Rcpp.h", 
    package="Rcpp")}. For Windows, it will be a static library
  \sQuote{Rcpp.a}. For Linux and Mac OS X, it will be \sQuote{libRcpp.so}.

  To use \code{Rcpp} in another package, you need to include the header
  during compilation. This typically requires use of the \code{-I} to
  provide the location as in \code{-I/usr/local/lib/R/site-library/Rcpp/include}.
  Similarly, for linking we need to provide the location of the library
  via \code{-L} as well as the actual library. An example for Linux
  would be \code{-L/usr/local/lib/R/site-library/Rcpp/lib -lRcpp}.

  In order to make it more convenient to use \code{Rcpp}, functions
  providing these arguments were added.  To use these, simply use a file
  \code{src/Makevars} such as this (which was taken from the
  \code{emdL1} package)

  \preformatted{
# compile flag providing header directory containing Rcpp.h
PKG_CXXFLAGS=$(shell $(R_HOME)/bin/Rscript -e 'Rcpp:::CxxFlags()')

# link flag providing library as well as path to library, and optionally rpath
PKG_LIBS=$(shell $(R_HOME)/bin/Rscript -e 'Rcpp:::LdFlags()')
}

  Alternatively, one can also encode the test for these variables using
  the \code{GNU autoconf} system. The \code{RQuantLib} package
  provides an example of that.  

  Lastly, on Linux, and during development, it can convenient to simply
  provide these files via soft links (or copies) from the usual locations like
  \sQuote{/usr/local/include} and \sQuote{/usr/local/lib} which
  alleviates the need for explicit location flags like \sQuote{-I} or
  \sQuote{-L}. Remember to also run \code{ldconfig} after creating the
  link for the library.  Alternatively, you can hardcode the dynamic 
  library location using the \code{rpath} linker directive:

  Use on Windows is identical to the use in Linux. However only a static
  library is provided. The two \code{\link{Rcpp}} functions detailed
  above provide the relevant content.
}
\author{Dominick Samperi wrote the initial versions of Rcpp (and
  RcppTemplate) during 2005 and 2006.  Dirk Eddelbuettel made some
  additions, and became maintainer in 2008. Dirk Eddelbuettel and Romain
  Francois have been extending Rcpp since 2009.
}
\keyword{programming}
\keyword{interface}
