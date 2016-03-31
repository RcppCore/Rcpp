\name{copy}
\alias{copy}
\title{
  Invokes the copy constructor of the C++ class
}
\description{
  Invokes the copy constructor of the C++ class. The function
  fails if the underlying class does not have a copy
  constructor.
}
\usage{
  copy(obj)
}
\arguments{
  \item{obj}{A C++ object from a class exposed by an Rcpp module}
}
\value{
  A new C++ object that is a copy of the object passed through
  according to the underlying C++ copy constructor.
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
  g <- copy(f)

  # f and g have the same value for the x field
  f$x == g$x

  # but they are different underlying C++ objects
  identical(f$.pointer, g$.pointer)

  g$x <- 4
  f$x

}
}
\keyword{ ~kwd1 }
