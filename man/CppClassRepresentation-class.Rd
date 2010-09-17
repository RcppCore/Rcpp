\name{C++ClassRepresentation-class}
\Rdversion{1.1}
\docType{class}
\alias{C++ClassRepresentation-class}
\alias{referenceMethods,C++ClassRepresentation-method}

\title{Class "C++ClassRepresentation"}
\description{Representation of a C++ class}
\section{Slots}{
  \describe{
    \item{\code{pointer}:}{Object of class \code{"externalptr"} ~~ }
    \item{\code{generator}:}{Object of class \code{"refObjectGenerator"} ~~ }
    \item{\code{cpp_fields}:}{Object of class \code{"list"} ~~ }
    \item{\code{cpp_methods}:}{Object of class \code{"list"} ~~ }
    \item{\code{slots}:}{Object of class \code{"list"} ~~ }
    \item{\code{contains}:}{Object of class \code{"list"} ~~ }
    \item{\code{virtual}:}{Object of class \code{"logical"} ~~ }
    \item{\code{prototype}:}{Object of class \code{"ANY"} ~~ }
    \item{\code{validity}:}{Object of class \code{"OptionalFunction"} ~~ }
    \item{\code{access}:}{Object of class \code{"list"} ~~ }
    \item{\code{className}:}{Object of class \code{"character"} ~~ }
    \item{\code{package}:}{Object of class \code{"character"} ~~ }
    \item{\code{subclasses}:}{Object of class \code{"list"} ~~ }
    \item{\code{versionKey}:}{Object of class \code{"externalptr"} ~~ }
    \item{\code{sealed}:}{Object of class \code{"logical"} ~~ }
  }
}
\section{Extends}{
Class \code{"\linkS4class{classRepresentation}"}, directly.
}
\section{Methods}{
  \describe{
    \item{referenceMethods}{\code{signature(classDef = "C++ClassRepresentation")}: ... }
	 }
}
\examples{
showClass("C++ClassRepresentation")
}
\keyword{classes}
