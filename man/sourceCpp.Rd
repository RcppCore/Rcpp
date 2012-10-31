\name{sourceCpp}
\alias{sourceCpp}
\title{
Source C++ Code from a File
}
\description{
\code{sourceCpp} parses the specified C++ file or source code and looks for functions marked with the \code{\link[=exportAttribute]{Rcpp::export}} attribute. A shared library is then built and its exported functions are made available as R functions in the specified environment.
}
\usage{
sourceCpp(file, code = NULL, envir = globalenv(), rebuild = FALSE, 
          show.output = verbose, verbose = getOption("verbose"), code)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{file}{
    A character string giving the pathname of a file
}
  \item{code}{
    A charcter string with source code. If supplied, the code is taken from this string instead of a file. 
}
  \item{envir}{
    Environment where the R functions should be made available.
}
  \item{rebuild}{
    Force a rebuild of the shared library.
}
  \item{show.output}{
    \code{TRUE} to print \code{R CMD SHLIB} output to the console.
}
  \item{verbose}{
    \code{TRUE} to print detailed information about generated code to the console.
}
}
\details{
    If the \code{code} parameter is provided then the \code{file} parameter is ignored.

    Functions marked with the \code{\link[=exportAttribute]{Rcpp::export}} attribute must have return types that are compatible with \code{Rcpp::wrap} and parameter types that are compatible with \code{Rcpp::as}.
    
    If the code has compilation dependencies on other packages (e.g. \pkg{Matrix}, \pkg{RcppArmadillo}) then an \code{\link[=dependsAttribute]{Rcpp::depends}} attribute should be added naming these dependencies.
    
    The \code{sourceCpp} function will not rebuild the shared library if the underlying code has not changed since the last compilation.
}

\value{
    Returns (invisibly) a character vector with the names of the R functions that were sourced into the specified environment.
}

\seealso{
\code{\link[=exportAttribute]{Rcpp::export}}, \code{\link[=dependsAttribute]{Rcpp::depends}}
}

\examples{
\dontrun{

sourceCpp("fibonacci.cpp")

sourceCpp(code='
  #include <Rcpp.h>

  // [[Rcpp::export]]
  int fibonacci(const int x) {
    if (x == 0) return(0);
    if (x == 1) return(1);
    return (fibonacci(x - 1)) + fibonacci(x - 2);
  }'
)

}
}
