\name{evalCpp}
\alias{evalCpp}
\title{
Evaluate a C++ expression
}
\description{
Evaluates a C++ expression. This creates a C++ function using 
\code{\link{cppFunction}} and call it to get the result. 
}
\usage{
evalCpp(code, depends = character(), includes = character(), 
    showOutput = verbose, verbose = getOption("verbose") )
}
\arguments{
  \item{code}{
C++ expression to evaluate
}
  \item{depends}{
see \code{\link{cppFunction}}
}
  \item{includes}{
see \code{\link{cppFunction}}
}
  \item{showOutput}{
see \code{\link{cppFunction}}
}
  \item{verbose}{
see \code{\link{cppFunction}}
}
}
\note{
    The result type of the C++ expression must be compatible with wrap.     
}
\value{
    The result of the evaluated C++ expression. 
}
\seealso{
\code{\link{sourceCpp}} and \code{\link{cppFunction}}
}
\examples{
\dontrun{

evalCpp( "__cplusplus" )
evalCpp( "std::numeric_limits<double>::max()" )
    
}
}
