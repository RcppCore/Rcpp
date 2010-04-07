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
	namespace = TRUE, code_files = character(), 
	example_code = TRUE )
}
\arguments{
	\item{name}{See \link[utils]{package.skeleton}}
	\item{list}{See \link[utils]{package.skeleton}}
	\item{environment}{See \link[utils]{package.skeleton}}
	\item{path}{See \link[utils]{package.skeleton}}
	\item{force}{See \link[utils]{package.skeleton}}
	\item{namespace}{See \link[utils]{package.skeleton}}
	\item{code_files}{See \link[utils]{package.skeleton}}
	\item{example_code}{If TRUE, example c++ code using Rcpp is added to the package}
}
\details{
	In addition to \link[utils]{package.skeleton} : 
	
	The \samp{DESCRIPTION} file gains a Depends line requesting that 
	the package depends on Rcpp and a LinkingTo lines so that the package
	finds Rcpp header files.
	
	The \samp{NAMESPACE}, if any, gains a \code{useDynLib} directive.
	
	The \samp{src} directory is created if it does not exists and 
	a \samp{Makevars} file is added setting the environment variables
	\samp{PKG_CXXFLAGS} and \samp{PKG_LIBS} to accomodate the necessary flags
	to link with the Rcpp library. 
	
	If the \code{example_code} argument is set to \code{TRUE}, 
	xample files \samp{rcpp_hello_world.h} and \samp{rcpp_hello_world.cpp}
	are also created in the \samp{src}. An R file \samp{rcpp_hello_world.R} is 
	expanded in the \samp{R} directory, the \code{rcpp_hello_world} function
	defined in this files makes use of the C++ function \samp{rcpp_hello_world}
	defined in the C++ file. These files are given as an example and should 
	eventually by removed from the generated package.
}
\value{
Nothing, used for its side effects
}
\seealso{
\link[utils]{package.skeleton}
}
\references{
Read the \emph{Writing R Extensions} manual for more details.

Once you have created a \emph{source} package you need to install it:
see the \emph{R Installation and Administration} manual,
\code{\link{INSTALL}} and \code{\link{install.packages}}.
}
\examples{
\dontrun{
f <- function(){}
Rcpp.package.skeleton( "foobar", "f" )
}
}
\keyword{ programming }

