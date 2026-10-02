\name{C++OverloadedMethods-class}
\Rdversion{1.1}
\docType{class}
\alias{C++OverloadedMethods-class}
\alias{$,C++OverloadedMethods-method}
\alias{$<-,C++OverloadedMethods-method}

\title{Class "C++OverloadedMethods"}
\description{
Set of C++ methods
}
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "C++OverloadedMethods")}: slot access, kept for backwards compatibility }
    \item{$<-}{\code{signature(x = "C++OverloadedMethods")}: slot assignment, kept for backwards compatibility }
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
    \item{\code{pointer}:}{Object of class \code{externalptr} pointer to the internal structure that represents the set of methods }
    \item{\code{class_pointer}:}{Object of class \code{externalptr} pointer to the internal structure that models the related class }
    \item{\code{size}:}{number of overloaded methods }
    \item{\code{void}:}{logical, whether each method returns void }
    \item{\code{const}:}{logical, whether each method is const }
    \item{\code{docstrings}:}{docstring of each method }
    \item{\code{signatures}:}{signature of each method }
    \item{\code{nargs}:}{number of arguments of each method }
  }
}
