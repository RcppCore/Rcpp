\name{C++Method-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Method-class}

\title{Class "C++Method"}
\description{
Metadata associated with a field of a class exposed through Rcpp modules
}
\section{Fields}{
  \describe{
    \item{\code{pointer}:}{external pointer to the internal (C++) object that represents the method}
    \item{\code{class_pointer}:}{external pointer to the class this method is from. }
    \item{\code{void}:}{\code{TRUE} if the method is void. }
  }
}
\section{Methods}{
No methods defined with class "C++Method" in the signature.
}
\seealso{
    The \code{fields} slot of the \code{\linkS4class{C++Class}} class is a 
    list of \code{C++Method} objects
}
\examples{
showClass("C++Method")
}
\keyword{classes}
