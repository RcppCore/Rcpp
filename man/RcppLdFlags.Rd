\name{LdFlags}
\alias{LdFlags}
\alias{RcppLdFlags}
\title{Provide Rcpp Linker Flags}
\description{
  \code{LdFlags} and \code{RcppLdFlags} return the required flags and
  options for the system linker. This allows portable use of
  \pkg{Rcpp} as package location as well as operating-system specific
  details are abstracted away behind the interface of this function.

  \code{LdFlags} is commonly called from the files \code{Makevars} (or
  \code{Makevars.win}) rather than in an interactive session.
}
\usage{
LdFlags(static=staticLinking())
RcppLdFlags(static=staticLinking())
}
\arguments{
  \item{static}{A boolean determining use of static (as opposed to
  dynamic) linking; defaults to using the \code{staticLinking()}
  function which defaults to \code{FALSE} on Linux, and \code{TRUE}
  if the operating system is different from Linux.}
}
\value{
  A character vector suitable by use by the system linker in order to
  create a library based on \pkg{Rcpp}.
}
\details{
  Thee functions are not meant to used interactively, and are intended
  solely for use by the build tools.
}
\references{
  Dirk Eddelbuettel and Romain Francois (2011). \pkg{Rcpp}: Seamless R
  and C++ Integration. \emph{Journal of Statistical Software},
  \bold{40(8)}, 1-18. URL http://www.jstatsoft.org/v40/i08/ and
  available as \code{vignette("Rcpp-introduction")}.
}
\seealso{
  The vignette \sQuote{Rcpp-package} has more details.
}
\author{Dirk Eddelbuettel and Romain Francois}
\keyword{programming}
\keyword{interface}
