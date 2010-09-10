\name{Module-class}
\Rdversion{1.1}
\docType{class}
\alias{Module-class}
\alias{$,Module-method}
\alias{prompt,Module-method}
\alias{show,Module-method}

\title{Rcpp modules}
\description{
Collection of internal c++ functions and classes exposed to R
}
\section{Objects from the Class}{
	modules are created by the \code{link{Module}} function
}
% \section{Slots}{
%   \describe{
%   	  \item{\code{pointer}:}{ external pointer of class \code{Rcpp::Module} }
%   }
% }
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "Module")}: extract a function or a class from the module. }
    \item{prompt}{\code{signature(object = "Module")}: generates skeleton of a documentation for a Module. }
    \item{show}{\code{signature(object = "Module")}: summary information about the module. }
  }
}
\seealso{
	\code{\link{Module}}
}
\keyword{classes}
