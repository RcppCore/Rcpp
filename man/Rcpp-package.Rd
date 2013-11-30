\name{Rcpp-package}
\alias{Rcpp-package}
\alias{Rcpp}
\docType{package}
\title{R / C++ interface}
\description{The \pkg{Rcpp} package provides C++ classes that
  greatly facilitate interfacing C or C++ code in \R packages using
  the \code{.Call} interface provided by \R.
}
\section{Introduction}{
  \pkg{Rcpp} provides C++ classes to facilitate manipulation of a large 
  number of R data structures : vectors, functions, environments, ... 
	
  The \dQuote{Rcpp-introduction} vignette gives an introduction on the package
}
\section{Usage for package building}{
  The \dQuote{Rcpp-package} vignette documents how to use Rcpp in client packages.
}
\author{Dirk Eddelbuettel and Romain Francois}
\references{
  Dirk Eddelbuettel and Romain Francois (2011). \pkg{Rcpp}: Seamless R
  and C++ Integration. \emph{Journal of Statistical Software},
  \bold{40(8)}, 1-18. URL \url{http://www.jstatsoft.org/v40/i08/} and
  available as \code{vignette("Rcpp-introduction")}.

  Eddelbuettel, Dirk (2013) Seamless R and C++ Integration with
  \pkg{Rcpp}. Springer, New York. ISBN 978-1-4614-6867-7.
}
\section{History}{
  The initial versions of Rcpp were written by Dominick Samperi during 2005 and
  2006.
  
  Dirk Eddelbuettel made some additions, and became maintainer in 2008. 
  
  Dirk Eddelbuettel and Romain Francois have been extending Rcpp since 2009.
}
\seealso{
  Development for \pkg{Rcpp} can be followed via the GitHub repository
  at \url{http://github.com/RcppCore/Rcpp}.

  Extensive examples with full documentation are available at
  \url{http://gallery.rcpp.org}.
}
\examples{
\dontrun{                  
# introduction to Rcpp
vignette("Rcpp-introduction")	

# information on how to build a package that uses Rcpp
vignette("Rcpp-package")	
}
}
\keyword{programming}
\keyword{interface}
