\name{setRcppClass}
\alias{setRcppClass}
\alias{loadRcppClass}
\alias{RcppClass-class}
\title{
Create a Class Extending a C++ Class
}
\description{
A class is defined that includes the fields and methods of a C++ class
defined, usually in this package.  For most applications, it is
recommended to call
\code{\link{classModule}()} to write files in the package with a call to \code{setRcppClass()} and the
C++ module code required.  See Details.
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
}
  \item{fields, contains, methods}{
Additional fields, superclasses and method definitions in \R{} that
extend the C++ class.  These arguments are passed on to
\code{\link{setRefClass}()}.
See Details for recommendations.
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
package.
It generates a load action that loads the specified module and
extracts the C++ class definition specified.

\R{} code can define new fields and methods for the class, typically
as prototypes for possible future C++ implementation.
Methods for the \R{} class can refer to methods and fields defined in
C++ for the C++ class.
These will be mapped into the C++ equivalents by \R{} code generated
by \code{setRcppClass}.
The C++ code may not deal as well as \R{} with incompatible
argument types and lengths.
Segmentation faults are a definite possibility.
If that's a problem, you should define methods in \R{} that check for
legal data types and values.

The fields  and methods defined can
include overriding C++ fields or methods.
Keep in mind, however, that \R{} methods can refer to C++ fields and
methods, but not the reverse.
If you override a C++ field or method, you essentially need to revise
all code that refers to that field or method.
Otherwise, the C++ code will continue to use the old C++ definition.

}
\value{
A generator for the new class.
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

