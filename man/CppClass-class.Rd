\name{C++Class-class}
\Rdversion{1.1}
\docType{class}
\alias{C++Class-class}
\alias{$,C++Class-method}
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
  	\item{\code{.Data}:}{mangled name of the class}
    \item{\code{pointer}:}{external pointer to the internal infomation}
    \item{\code{module}:}{external pointer to the module}
    \item{\code{fields}:}{list of \linkS4class{C++Field} objects}
    \item{\code{methods}:}{list of \linkS4class{C++Method} objects}
    \item{generator}{the generator object for the class}
  }
}
\section{Methods}{
  \describe{
    \item{show}{\code{signature(object = "C++Class")}: prints the class. }
    \item{$}{\code{signature(object = "C++Class")}: ... }
	 }
}
\keyword{classes}

