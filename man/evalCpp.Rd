\name{evalCpp}
\alias{evalCpp}
\alias{areMacrosDefined}
\title{
Evaluate a C++ Expression
}
\description{
Evaluates a C++ expression. This creates a C++ function using 
\code{\link{cppFunction}} and calls it to get the result. 
}
\usage{
evalCpp(code, depends = character(), includes = character(), 
        rebuild = FALSE, showOutput = verbose, 
        verbose = getOption("verbose"))
areMacrosDefined(names, depends = character(), includes = character(), 
        rebuild = FALSE, showOutput = verbose, 
        verbose = getOption("verbose"))
}
\arguments{
  \item{code}{
C++ expression to evaluate
}
  \item{names}{
names of the macros we want to test
}
  \item{depends}{
see \code{\link{cppFunction}}
}
  \item{includes}{
see \code{\link{cppFunction}}
}
  \item{rebuild}{
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
    The result type of the C++ expression must be compatible with \code{Rcpp::wrap}.     
}
\value{
    The result of the evaluated C++ expression. 
}
\seealso{
\code{\link{sourceCpp}}, \code{\link{cppFunction}}
}
\examples{
\dontrun{

evalCpp( "__cplusplus" )
evalCpp( "std::numeric_limits<double>::max()" )
    
areMacrosDefined( c("__cplusplus", "HAS_TR1" ) )

}
}
