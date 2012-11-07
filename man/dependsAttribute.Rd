\name{dependsAttribute}
\alias{dependsAttribute}

\title{Rcpp::depends Attribute}

\description{
The \code{Rcpp::depends} attribute is added to a C++ source file to indicate that it has a compilation dependency on one or more other packages. For example:
\preformatted{
// [[Rcpp::depends(RcppArmadillo)]]
}
}

\arguments{
 \item{\dots}{
    Packages which the source file depends on for compilation
}
}

\details{
    The \code{Rcpp::depends} attribute is used by the implementation of the \code{\link{sourceCpp}} function to correctly setup the build environment for \code{R CMD SHLIB}. 
    
    The include directories of the specified packages are added to the \code{CLINK_CPPFLAGS} environment variable. In addition, if the referenced package provides an \link[inline:plugins]{inline plugin} it is called to determine additional environment variables required to successfully build.

}

\note{
    The \code{Rcpp::depends} attribute is specified using a syntax compatible with the new \href{http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2761.pdf}{generalized attributes} feature of the C++11 standard. Note however that since this feature is not yet broadly supported by compilers it needs to be specified within a comment (see examples below).
}


\seealso{
\code{\link{sourceCpp}}
}

\examples{
\dontrun{

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::depends(Matrix, RcppGSL)]]
}
}

