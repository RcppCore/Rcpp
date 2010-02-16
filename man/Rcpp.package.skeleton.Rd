\name{Rcpp.package.skeleton}
\alias{Rcpp.package.skeleton}
\title{
Create a skeleton for a new package depending on Rcpp
}
\description{
	\code{Rcpp.package.skeleton} automates the creation of 
	a new source package that intends to use features of Rcpp. 
	
	It is based on the \link[utils]{package.skeleton} function
	which it executes first.
}
\usage{
Rcpp.package.skeleton(name = "anRpackage", list = character(), 
	environment = .GlobalEnv, path = ".", force = FALSE, 
	namespace = TRUE, code_files = character())
}
\arguments{
	\item{name}{See \link[utils]{package.skeleton}}
	\item{list}{See \link[utils]{package.skeleton}}
	\item{environment}{See \link[utils]{package.skeleton}}
	\item{path}{See \link[utils]{package.skeleton}}
	\item{force}{See \link[utils]{package.skeleton}}
	\item{namespace}{See \link[utils]{package.skeleton}}
	\item{code_files}{See \link[utils]{package.skeleton}}
}
\details{
	In addition to \link[utils]{package.skeleton} : 
	
	The \samp{DESCRIPTION} file gains a Depends line requesting that 
	the package depends on Rcpp
	
	The \samp{NAMESPACE}, if any, gains a \code{useDynLib} directove
	
	The \samp{src} directory is created if it does not exists and 
	a \samp{Makevars} file is added setting the environment variables
	\samp{PKG_CXXFLAGS} and \samp{PKG_LIBS}

}
\value{
Nothing, used for its side effects
}
\seealso{
\link[utils]{package.skeleton}
}
\examples{
\dontrun{
f <- function(){}
Rcpp.package.skeleton( "foobar", "f" )
}
}
\keyword{ programming }

