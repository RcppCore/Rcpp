\name{destruct}
\alias{destruct}
\alias{is_destructed}
\title{
Explicitely destructs the C++ object.
}
\description{
Explicitely invokes the C++ object destructor. 
}
\usage{
destruct(obj)
is_destructed(obj)
}
\arguments{
  \item{obj}{A C++ object}
}
\details{
\code{destruct} explicitely destruct the C++ object
\code{is_destructed} checks if it has been destructed
}
\value{
\code{is_destructed} returns a logical.
}
\author{
  Romain Francois <romain@r-enthusiasts.com>
}
\examples{
\dontrun{

  sourceCpp( code = '
    #include <Rcpp.h>
    using namespace Rcpp ;

    class Foo{
      public:
        Foo( int x_ ) : x(x_){}
        ~Foo(){ Rprintf("~Foo\\n") ; }
        int x ;
    } ;

    RCPP_MODULE(test){
      class_<Foo>("Foo")
        .constructor<int>()
        .field( "x", &Foo::x)
      ;
  }
  ')
  f <- new( Foo, 1 )
  destruct(f)
  is_destructed(f)

}
}
\keyword{manip}
