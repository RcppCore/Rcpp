\name{LdFlags}
\alias{LdFlags}
\alias{RcppLdFlags}
\title{(Deprecated) Rcpp Linker Flags}
\description{
  In previous versions of Rcpp, \code{LdFlags} and \code{RcppLdFlags}  
  were used to return the required flags and options for the system linker to 
  link to the Rcpp user library. Since we no longer build or ship a 
  user library, these functions now return an empty string.
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
  \bold{40(8)}, 1-18. URL http://www.jstatsoft.org/v40/i08/ and
  available as \code{vignette("Rcpp-introduction")}.
}
\author{Dirk Eddelbuettel and Romain Francois}
\keyword{programming}
\keyword{interface}
