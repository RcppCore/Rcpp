\name{sourceCpp}
\alias{sourceCpp}
\title{
Source C++ Code from a File
}
\description{
\code{sourceCpp} parses the specified C++ file and looks for functions marked with the \code{\link[=exportAttribute]{Rcpp::export}} attribute. The C++ file is then built into a shared library and it's exported functions are made available as R functions in the specified environment.
}
\usage{
sourceCpp(file, local = FALSE, rebuild = FALSE, 
          show.output = verbose, verbose = getOption("verbose"))
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{file}{
    A character string giving the pathname of a file.
}
  \item{local}{
    \code{TRUE}, \code{FALSE} or an environment, determining where the R functions will be made available. \code{FALSE} (the default) corresponds to the user's workspace (the global environment) and \code{TRUE} to the environment from which source is called
}
  \item{rebuild}{
    Force a rebuild of the shared library by passing \code{--preclean} to \code{R CMD SHLIB} 
}
  \item{show.output}{
    \code{TRUE} to print \code{R CMD SHLIB} output to the console
}
  \item{verbose}{
    \code{TRUE} to print detailed information about generated code to the console
}
}
\details{
    Functions marked with the \code{\link[=exportAttribute]{Rcpp::export}} attribute must have return types that are compatible with \code{Rcpp::wrap} and parameter types that are compatible with \code{Rcpp::as}.
    
    If the source file has compilation dependencies on other packages (e.g. \pkg{Matrix}, \pkg{RcppArmadillo}) then an \code{\link[=dependsAttribute]{Rcpp::depends}} attribute should be added to the file naming these dependencies.
}

\seealso{
\code{\link[=exportAttribute]{Rcpp::export}}, \code{\link[=dependsAttribute]{Rcpp::depends}}
}

\examples{
\dontrun{

sourceCpp("transform.cpp")
}
}
