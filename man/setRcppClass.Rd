\name{setRcppClass}
\alias{setRcppClass}
\alias{loadRcppClass}
\alias{RcppClass-class}
\title{
Create a Class Extending a C++ Class
}
\description{
These routines create a class definition in \R for an exposed C++
class, setting up and executing a load action to incorporate the C++
pointer information.
Neither function should normally need to be called directly; for most applications,
a call to
\code{\link{exposeClass}()} will create both C++ and \R code files to
expose the C++ class.
}
\usage{
setRcppClass(Class, CppClass = , module = , fields = list(), contains = ,
             methods = , saveAs = Class, where = , ...)
loadRcppClass(Class, CppClass = , module = , fields = character(),
              contains = character(),
              methods = , saveAs = Class, where = , ...)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{Class}{
The name for the new class.
}
  \item{CppClass}{
The C++ class defined in the C++ code for the package that this class
extends. By default, the same as \code{Class}.
}
  \item{module}{
The Rcpp module in which the class is defined.  The module does not
have to be loaded separately; \code{setRcppClass()} will arrange to
load the module. By default, \code{"class_"} followed by the C++ class
name.

If \code{\link{exposeClass}()} has been called, the necessary module
code will have been written in the \code{src} directory of the package.
}
  \item{fields, contains, methods}{
Additional fields, superclasses and method definitions in \R{} that
extend the C++ class.  These arguments are passed on to
\code{\link{setRefClass}()}.
}
  \item{saveAs}{
Save a generator object for the class in the package's namespace under
this name.  By default, the generator object has the name of the
class.  To avoid saving any generator object, supply this argument as
\code{NULL}.

(This argument is currently needed because the actual class definition
must take place at package load time, to include C++ pointer
information.
Therefore the
value returned by \code{setRcppClass()} when called during package
installation is not the generator object returned by
\code{setRefClass()}.
We may be able to hack
around this problem in the future.)
}
  \item{where}{
The environment in which to save the class definition.  By default,
will be the namespace of the package in which the
\code{setRcppClass()} call is included.
}
  \item{\dots}{
Arguments, if any, to pass on to \code{\link{setRefClass}()}.
}
}
\details{
The call to these functions normally appears in the source code for a
package; in particular, a call is written in an \R source file when
\code{\link{exposeClass}()} is called.

\R{} code for this class or (preferably) a subclass can define new fields and methods for the class.
Methods for the \R{} class can refer to methods and fields defined in
C++ for the C++ class, if those have been exposed.

The fields  and methods defined can
include overriding C++ fields or methods.
Keep in mind, however, that \R{} methods can refer to C++ fields and
methods, but not the reverse.
If you override a C++ field or method, you essentially need to revise
all code that refers to that field or method.
Otherwise, the C++ code will continue to use the old C++ definition.

}
\value{
At load time, a generator for the new class is created and stored
according to the \code{saveAs} argument, typically under the name of
the class.

The value returned at installation time is a dummy.  Future revisions
of the function may allow us to return a valid generator at install
time.  We recommend using the standard style of assigning the value
to the name of the class, as one would do with \code{\link{setRefClass}}.
}
\author{
John Chambers
}
\note{
This function and function \code{\link{loadModule}()} require
version  2.15.0 of \R{} or later, in order to
use load actions, introduced in that version.

A subtle way this can fail is by somehow loading a legitimate
binary version of your package (installed under a valid version of
\R{}) into a session with an older \R{}.
In this case the load actions created in the binary package will
simply not be called.  None of the modules will be loaded and none of
the classes created.

If your symptom is that classes or other objects from modules don't
exist, check the \R{} version.
}
\examples{
\dontrun{
setRcppClass("World", 
    module = "yada", 
    fields = list(more = "character"),
    methods = list(
        test = function(what) message("Testing: ", what, "; ", more)),
    saveAs = "genWorld"
         )
}
}
\keyword{ classes }

