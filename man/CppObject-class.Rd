\name{C++Object-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Object-class}
\alias{$,C++Object-method}
\alias{$<-,C++Object-method}
\alias{show,C++Object-method}

\title{c++ internal objects}
\description{
C++ internal objects instanciated from a class exposed in an Rcpp module
}
\section{Objects from the Class}{
	This is a virtual class.  Actual C++ classes are subclasses.
}
\section{Methods}{
  \describe{
    \item{$}{\code{signature(x = "C++Object")}: invokes a method on the object, or retrieves the value of a property }
	\item{$<-}{\code{signature(x = "C++Object")}: set the value of a property }
	\item{show}{\code{signature(object = "C++Object")}: print the object }
	 }
}
\keyword{classes}
