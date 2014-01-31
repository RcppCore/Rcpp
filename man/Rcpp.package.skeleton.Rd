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
	code_files = character(), cpp_files = character(),
	example_code = TRUE, attributes = TRUE, module = FALSE, 
	author = "Who wrote it", 
	maintainer = if(missing( author)) "Who to complain to" else author, 
	email = "yourfault@somewhere.net", 
	license = "What Licence is it under ?"
	)
}
\arguments{
	\item{name}{See \link[utils]{package.skeleton}}
	\item{list}{See \link[utils]{package.skeleton}}
	\item{environment}{See \link[utils]{package.skeleton}}
	\item{path}{See \link[utils]{package.skeleton}}
	\item{force}{See \link[utils]{package.skeleton}}
	\item{code_files}{See \link[utils]{package.skeleton}}
	\item{cpp_files}{A character vector with the paths to C++ source files to add to the package. }
	\item{example_code}{If TRUE, example c++ code using Rcpp is added to the package. }
	\item{attributes}{If TRUE, example code makes use of Rcpp attributes.}
	\item{module}{If TRUE, an example \code{\link{Module}} is added to the skeleton. }
	\item{author}{Author of the package.}
	\item{maintainer}{Maintainer of the package.}
	\item{email}{Email of the package maintainer.}
	\item{license}{License of the package.}
}
\details{
	In addition to \link[utils]{package.skeleton} : 
	
	The \samp{DESCRIPTION} file gains an Imports line requesting that 
	the package depends on Rcpp and a LinkingTo line so that the package
	finds Rcpp header files.
	
	The \samp{NAMESPACE} gains a \code{useDynLib} directive as well
	as an \code{importFrom(Rcpp, evalCpp} to ensure instantiation of Rcpp.
	
	The \samp{src} directory is created if it does not exists and 
	a \samp{Makevars} file is added setting the environment variables
	\samp{PKG_LIBS} to accomodate the necessary flags to link with the Rcpp library. 
	
	If \code{cpp_files} are provided then they will be copied to the \samp{src}
	directory.
	
	If the \code{example_code} argument is set to \code{TRUE}, 
	example files \samp{rcpp_hello_world.h} and \samp{rcpp_hello_world.cpp}
	are also created in the \samp{src}. An R file \samp{rcpp_hello_world.R} is 
	expanded in the \samp{R} directory, the \code{rcpp_hello_world} function
	defined in this files makes use of the C++ function \samp{rcpp_hello_world}
	defined in the C++ file. These files are given as an example and should 
	eventually by removed from the generated package.
	
	If the \code{attributes} argument is \code{TRUE}, then rather than generate
	the example files as described above, a single \samp{rcpp_hello_world.cpp}
	file is created in the \samp{src} directory and it's attributes are 
	compiled using the \code{\link{compileAttributes}} function, so files
	\samp{RcppExports.R} and \samp{RcppExports.cpp} are generated as well. 
	
	If the \code{module} argument is \code{TRUE}, a sample Rcpp module will 
	be generated as well. 
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
# simple package
Rcpp.package.skeleton( "foobar" )

# package using attributes
Rcpp.package.skeleton( "foobar", attributes = TRUE )

# package with a module
Rcpp.package.skeleton( "testmod", module = TRUE )

# the Rcpp-package vignette
vignette( "Rcpp-package" )

# the Rcpp-modules vignette for information about modules
vignette( "Rcpp-modules" )

}
}
\keyword{ programming }

