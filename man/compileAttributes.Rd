\name{compileAttributes}
\alias{compileAttributes}
\title{
Compile Rcpp Attributes for a Package
}
\description{
Scan the source files within a package for attributes and generate code as required. Generates the bindings required to call C++ functions from R for functions adorned with the \code{Rcpp::export} attribute.
}
\usage{
compileAttributes(pkgdir = ".", verbose = getOption("verbose"))
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{pkgdir}{
    Directory containing the package to compile attributes for (defaults to the current working directory).
}
  \item{verbose}{
    \code{TRUE} to print detailed information about generated code to the console.
}
}
\details{
    The source files in the package directory given by \code{pkgdir} are scanned for attributes and code is generated as required based on the attributes. 
    
    For C++ functions adorned with the \code{Rcpp::export} attribute, the C++ and R source code required to bind to the function from R is generated and added (respectively) to \code{src/RcppExports.cpp} or \code{R/RcppExports.R}.
    
    In order to access the declarations for custom \code{Rcpp::as} and \code{Rcpp::wrap} handlers the \code{compileAttributes} function will also call any \link[inline:plugins]{inline plugins} available for packages listed in the \code{LinkingTo} field of the \code{DESCRIPTION} file.
}
\value{
    Returns (invisibly) a character vector with the paths to any files that were updated as a result of the call.
}

\note{
	The \code{compileAttributes} function deals only with exporting C++ functions to R. If you want the functions to additionally be publicly available from your package's namespace another step may be required. Specifically, if your package \code{NAMESPACE} file does not use a pattern to export functions then you should add an explicit entry to \code{NAMESPACE} for each R function you want publicly available.

    In addition to exporting R bindings for C++ functions, the \code{compileAttributes} function can also generate a direct C++ interface to the functions using the \code{\link[=interfacesAttribute]{Rcpp::interfaces}} attribute.
}

\seealso{
\code{\link[=exportAttribute]{Rcpp::export}}, \code{\link[=interfacesAttribute]{Rcpp::interfaces}}
}


\examples{
\dontrun{

# Compile attributes for package in the current working dir
compileAttributes()
}
}

