\name{LdFlags-deprecated}
\alias{LdFlags}
\alias{RcppLdFlags}
\title{Deprecated Rcpp Linker Flags}
\description{
  In Rcpp versions prior to release 0.10.1 of November 2013,
  \code{LdFlags} and \code{RcppLdFlags} were used to return the required
  flags and options for the system linker to link to the Rcpp user
  library. Since we no longer build or ship a user library, these
  functions now return an empty string. As of Rcpp release 0.12.19,
  these functions are now deprecated.
}
\usage{
  LdFlags()
  RcppLdFlags()
}
\value{
  An empty string.
}
\references{
  Dirk Eddelbuettel and Romain Francois (2011). \pkg{Rcpp}: Seamless R
  and C++ Integration. \emph{Journal of Statistical Software},
  \bold{40(8)}, 1-18, \doi{10.18637/jss.v040.i08}. Also
  available as \code{vignette("Rcpp-introduction")}.
}
\author{Dirk Eddelbuettel and Romain Francois}
\keyword{programming}
\keyword{interface}
