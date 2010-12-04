\name{Module-class}
\Rdversion{1.1}
\docType{class}
\alias{Module-class}
\alias{$,Module-method}
\alias{prompt,Module-method}
\alias{show,Module-method}
\alias{initialize,Module-method}

\title{Rcpp modules}
\description{
Collection of internal c++ functions and classes exposed to R
}
\section{Objects from the Class}{
	modules are created by the \code{link{Module}} function
}
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "Module")}: extract a function or a class from the module. }
    \item{prompt}{\code{signature(object = "Module")}: generates skeleton of a documentation for a Module. }
    \item{show}{\code{signature(object = "Module")}: summary information about the module. }
    \item{initialize}{\code{signature(.Object = "Module")}: ... }
  }
}
\seealso{
	The \code{\link{Module}} function
}
\keyword{classes}
