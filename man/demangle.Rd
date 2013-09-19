\name{demangle}
\alias{demangle}
\alias{sizeof}
\alias{print.bytes}
\title{
c++ type information 
}
\description{
    \code{demangle} gives the demangled type, \code{sizeof} its size (in bytes). 
}
\usage{
    demangle(type = "int", ...)
    sizeof(type = "int", ...)
}
\arguments{
    \item{type}{The type we want to demangle}
    \item{\dots}{Further argument for \code{\link{cppFunction}} }
}
\details{
    The following function is compiled and invoked: 
    
    \preformatted{%
        SEXP demangle_this_type(){
            typedef %s type ;
            return wrap( DEMANGLE(type) ) ;
        }
        
        SEXP sizeof_this_type(){
            typedef %s type ;
            return wrap( sizeof(type) ) ;
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
    
    sizeof( "long" )
    sizeof( "long long" )
    
}
}
\keyword{programming}

