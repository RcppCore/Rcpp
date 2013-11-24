\name{Rcpp.plugin.maker}
\alias{Rcpp.plugin.maker}
\title{
Facilitating making package plugins
}
\description{
This function helps packages making inline plugins. 
}
\usage{
Rcpp.plugin.maker(
  include.before = "", 
  include.after = "", 
  LinkingTo = unique(c(package, "Rcpp")), 
  Depends = unique(c(package, "Rcpp")), 
  libs = "", 
  Makevars = NULL, 
  Makevars.win = NULL, 
  package = "Rcpp"
)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{include.before}{Code to be included before the \samp{Rcpp.h} file}
  \item{include.after}{Code to be included after the \samp{Rcpp.h} file }
  \item{LinkingTo}{Packages to be added to the \samp{LinkingTo} field }
  \item{Depends}{Packages to be added to the \samp{Depends} field }
  \item{libs}{library flags}
  \item{Makevars}{content for a \samp{Makevars} file, or \code{NULL}}
  \item{Makevars.win}{content for a \samp{Makevars.win} file, or \code{NULL}}
  \item{package}{The package this plugin is for. }
}
\value{
A function that is suitable as a plugin. See for example the 
\samp{RcppArmadillo} package that uses this to create its inline plugin. 
}
\keyword{interface}
