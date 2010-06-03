\name{C++Object-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Object-class}
\alias{$,C++Object-method}
\alias{show,C++Object-method}

\title{c++ internal objects}
\description{
C++ internal objects instanciated from a class exposed in an Rcpp module
}
\section{Objects from the Class}{
	Objects can be created by the \code{new} method of the
	\linkS4class{"C++Class"} class.
}
\section{Extends}{
	Class \code{"\linkS4class{C++ObjectS3}"}, directly.
	Class \code{"\linkS4class{oldClass}"}, by class "C++ObjectS3", distance 2.
}

\section{Slots}{
  \describe{
    \item{\code{module}:}{external pointer to the module}
    \item{\code{cppclass}:}{external pointer to the c++ class}
    \item{\code{pointer}:}{external pointer to the c++ object}
  }
}
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "C++Object")}: invokes a method on the object }
	\item{show}{\code{signature(object = "C++Object")}: print the object }
	 }
}
\keyword{classes}
