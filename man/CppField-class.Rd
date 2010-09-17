\name{C++Field-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Field-class}

\title{Class "C++Field"}
\description{
Metadata associated with a field of a class exposed through Rcpp modules
}
\section{Fields}{
  \describe{
    \item{\code{pointer}:}{external pointer to the internal (C++) object that represents fields}
    \item{\code{cpp_class}:}{(demangled) name of the C++ class of the field}
    \item{\code{read_only}:}{Is this field read only}
    \item{\code{class_pointer}:}{external pointer to the class this field is from. }
  }
}
\section{Methods}{
No methods defined with class "C++Field" in the signature.
}
\seealso{
    The \code{fields} slot of the \code{\linkS4class{C++Class}} class is a 
    list of \code{C++Field} objects
}
\examples{
showClass("C++Field")
}
\keyword{classes}
