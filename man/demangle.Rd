\name{demangle}
\alias{demangle}
\title{
demanging c++ types 
}
\description{
    This uses the compiler functionality (if available) to demangle type. If the compiler
    cannot demangle, then it will return its argument as is
}
\usage{
    demangle(type = "int", ...)
}
\arguments{
    \item{type}{The type we want to demangle}
    \item{\dots}{Further argument for \code{\link{cppFunction}} }
}
\details{
    The following function is compiled and invoked: 
    
    \preformatted{%
        String demangle_this_type(){
            typedef %s type ;
            return DEMANGLE(type) ;
        }         
    }    
    
    \code{DEMANGLE} is a macro in \samp{Rcpp} that does the work. 
}
\value{
    The demangled type, as a string. 
}
\references{
    See this \href{http://gcc.gnu.org/onlinedocs/libstdc++/manual/ext_demangling.html}{chapter}
    from the GNU C++ library manual. 
}
\author{
    Romain Francois <romain@r-enthusiasts.com>
}
\note{
    We only know how to demangle with gcc. If you know how to demangle types
    with your compiler, let us know. 
}
\seealso{
    \code{\link{cppFunction}} is used to compile the function \code{demangle} creates. 
}
\examples{
\dontrun{
    demangle( "int64_t" )
    demangle( "uint64_t" )

    demangle( "NumericVector" )
    demangle( "std::map<std::string,double>" )
}
}
\keyword{programming}

