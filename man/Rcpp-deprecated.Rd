\name{Rcpp-deprecated}
\alias{Rcpp-deprecated}
\title{Deprecated Functions in the Rcpp Package}
\description{
  These functions are provided for compatibility with older versions of the
  \pkg{Rcpp} package only, and may be removed in future versions.
}
\details{
  \itemize{
  \item \code{\link{loadRcppModules}} calls should now be replaced by
  \code{\link{loadModule}} calls, one per Module.

  \item \code{\link{LdFlags}} and \code{\link{RcppLdFlags}} are no
  longer required as no library is provided (or needed) by Rcpp (as it
  was up until release 0.10.1).
  }
}
\author{Dirk Eddelbuettel and Romain Francois}
\keyword{programming}
\keyword{interface}
