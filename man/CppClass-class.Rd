\name{C++Class-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Class-class}
\alias{new,C++Class-method}
\alias{show,C++Class-method}

\title{Reflection information for an internal c++ class}
\description{
Information about an internal c++ class.
}
\section{Objects from the Class}{
	Objects are usually extracted from a \linkS4class{Module}
	using the dollar extractor.
}
\section{Slots}{
  \describe{
    \item{\code{pointer}:}{external pointer to the internal infomation}
    \item{\code{module}:}{external pointer to the module}
  }
}
\section{Methods}{
  \describe{
    \item{new}{\code{signature(Class = "C++Class")}: creates a new object 
    of this class using its default constructor. This creates
    instances of the class \linkS4class{"C++Object"}
    }
    \item{show}{\code{signature(object = "C++Class")}: prints the class. }
	 }
}
\keyword{classes}

