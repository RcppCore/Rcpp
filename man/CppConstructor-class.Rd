\name{C++Constructor-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Constructor-class}
\alias{$,C++Constructor-method}
\alias{$<-,C++Constructor-method}

\title{Class "C++Constructor"}
\description{
Representation of a C++ constructor
}
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "C++Constructor")}: slot access, kept for backwards compatibility }
    \item{$<-}{\code{signature(x = "C++Constructor")}: slot assignment, kept for backwards compatibility }
  }
}
\note{
This used to be a reference class. Objects of this class are plain S4
objects now; the slots may still be accessed with \code{$} for backwards
compatibility.
}
\keyword{classes}
\section{Slots}{
  \describe{
    \item{\code{pointer}:}{pointer to the internal structure that represent the constructor}
    \item{\code{class_pointer}:}{pointer to the internal structure that represent the associated C++ class}
    \item{\code{nargs}:}{Number of arguments the constructor expects}
    \item{\code{signature}:}{C++ signature of the constructor}
    \item{\code{docstring}:}{Short description of the constructor}
  }
}
