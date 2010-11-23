\name{C++Constructor-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Constructor-class}

\title{Class "C++Constructor"}
\description{
Representation of a C++ constructor
}
\section{Extends}{
Class \code{"\linkS4class{envRefClass}"}, directly.
Class \code{"\linkS4class{.environment}"}, by class "envRefClass", distance 2.
Class \code{"\linkS4class{refClass}"}, by class "envRefClass", distance 2.
Class \code{"\linkS4class{environment}"}, by class "envRefClass", distance 3, with explicit coerce.
Class \code{"\linkS4class{refObject}"}, by class "envRefClass", distance 3.
}
\keyword{classes}
\section{Fields}{
  \describe{
    \item{\code{pointer}:}{pointer to the internal structure that represent the constructor}
    \item{\code{class_pointer}:}{pointer to the internal structure that represent the associated C++ class}
    \item{\code{nargs}:}{Number of arguments the constructor expects}
    \item{\code{signature}:}{C++ signature of the constructor}
    \item{\code{docstring}:}{Short description of the constructor}
  }
}
