\name{.Cpp}
\alias{.Cpp}
\title{C++ foreign function interface}
\description{
Function to make calls to compiled code that been loaded into R. 

\code{.Cpp} is a modified version of \link{.Call} that handles
c++ exceptions and forwards them to R as R conditions. 
}
\usage{
.Cpp(name, \dots, PACKAGE)
}
\arguments{
  \item{name}{A character string giving the name of the C routine, or an object of class
    \code{"\link{NativeSymbolInfo}"}, \code{"\link{RegisteredNativeSymbol}"}
    or \code{"\link{NativeSymbol}"} referring to such a name.}
  \item{\dots}{arguments to be passed to the foreign function.}
  \item{PACKAGE}{Passed to \link{getNativeSymbolInfo}, See also \link{.Call} for details.}
}
\value{
result of the function or condition is an C++ exception is thrown
}
\details{
	\code{.Cpp} only handles routines that \link{.Call} can handle
}
\examples{
\dontrun{
# identical
.Cpp( "capabilities", PACKAGE = "Rcpp" )
.Call( "capabilities", PACKAGE = "Rcpp" )

# here testfun_ex_2 throws a c++ exception
# which .Call cannot handle, but .Cpp can
tryCatch( 
	.Cpp( "testfun_ex_2", 1, 2, PACKAGE = "Rcpp"), 
	"std::range_error" = function(e){
		# handle the message of the c++ exception
		print( conditionMessage(e) )
		
		print( str( e ) )
	} ) 
}     
}
\keyword{programming}
