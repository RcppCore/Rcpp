% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/asis.R
\name{asisWeave}
\alias{asisWeave}
\alias{asisTangle}
\title{Process pdf vignettes \sQuote{asis}}
\usage{
asisWeave(file, ...)

asisTangle(file, ..., pattern = "(|[.][^.]*)[.]asis$")
}
\arguments{
\item{file}{character Filename to be processed}

\item{...}{dots Currently ignored}

\item{pattern}{character A regular expression describing the filename pattern}
}
\value{
The respective filename is returned, invisibly
}
\description{
Simple \sQuote{asis} Vignette Processor
}
\details{
To pass pre-made pdf vignettes through \dQuote{as is}, a simple vignette
process is added. It is derived from the more feature-complete one in the \pkg{R.rsp}
package. To use it, add files named like the pdf file plus an appended \code{.asis}
with the vignette metainformation and register the vignette processor, see the examples.
}
\examples{
# To register this vignette engine in another package, add
# \code{VignetteBuilder: Rcpp} as well as \code{Suggests: Rcpp} to \code{DESCRIPTION}
# which uses the registration this package provides via
\dontrun{tools::vignetteEngine("asis", package = pkgname, pattern = "[.](pdf|html)[.]asis$",
                               weave = asisWeave, tangle = asisTangle)}

# Use a .asis file as in the Rcpp package, for example Rcpp-FAQ.pdf.asis has these lines:
#   \%\VignetteIndexEntry{Rcpp-FAQ}
#   \%\VignetteKeywords{Rcpp, FAQ, R, Cpp}
#   \%\VignettePackage{Rcpp}
#   \%\VignetteEncoding{UTF-8}
#   \%\VignetteEngine{Rcpp::asis}
}
\author{
Henrik Bengtsson for the original versions in package \pkg{R.rsp},
Dirk Eddelbuettel for the shortened ones used here
}
