\name{C++Function-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Function-class}
\alias{show,C++Function-method}

\title{Class "C++Function"}
\description{
Internal C++ function
}
\section{Objects from the Class}{
	Objects can be created by the \code{Rcpp::InternalFunction}
	class from the \code{Rcpp} library
}
\section{Slots}{
  \describe{
    \item{\code{.Data}:}{R function that calls back to the internal function}
    \item{\code{pointer}:}{External pointer to a C++ object poiting to the function}
    \item{\code{docstring}:}{Short documentation for the function}
    \item{\code{signature}:}{C++ signature}
  }
}
\section{Extends}{
Class \code{"\linkS4class{function}"}, from data part.
Class \code{"\linkS4class{OptionalFunction}"}, by class "function", distance 2.
Class \code{"\linkS4class{PossibleMethod}"}, by class "function", distance 2.
}
\section{Methods}{
  \describe{
 	\item{show}{\code{signature(object = "C++Function")}: print the object }
	 }
}
\examples{
showClass("C++Function")
}
\keyword{classes}
