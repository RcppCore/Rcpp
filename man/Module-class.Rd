\name{Module-class}
\Rdversion{1.1}
\docType{class}
\alias{Module-class}
\alias{$,Module-method}

\title{Rcpp modules}
\description{
Collection of internal c++ functions and classes exposed to R
}
\section{Objects from the Class}{
	modules are created by the \code{link{Module}} function
}
\section{Slots}{
  \describe{
  	  \item{\code{pointer}:}{ external pointer of class \code{Rcpp::Module} }
  }
}
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "Module")}: extract a function or a class from the module }
	 }
}
\seealso{
	\code{\link{Module}}
}
\keyword{classes}
