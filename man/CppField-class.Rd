\name{C++Field-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Field-class}
\alias{$,C++Field-method}
\alias{$<-,C++Field-method}

\title{Class "C++Field"}
\description{
Metadata associated with a field of a class exposed through Rcpp modules
}
\section{Slots}{
  \describe{
    \item{\code{pointer}:}{external pointer to the internal (C++) object that represents fields}
    \item{\code{cpp_class}:}{(demangled) name of the C++ class of the field}
    \item{\code{read_only}:}{Is this field read only}
    \item{\code{class_pointer}:}{external pointer to the class this field is from. }
    \item{\code{docstring}:}{docstring of the field}
  }
}
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "C++Field")}: slot access, kept for backwards compatibility }
    \item{$<-}{\code{signature(x = "C++Field")}: slot assignment, kept for backwards compatibility }
  }
}
\seealso{
    The \code{fields} slot of the \code{\linkS4class{C++Class}} class is a 
    list of \code{C++Field} objects
}
\examples{
showClass("C++Field")
}
\note{
This used to be a reference class. Objects of this class are plain S4
objects now; the slots may still be accessed with \code{$} for backwards
compatibility.
}
\keyword{classes}
