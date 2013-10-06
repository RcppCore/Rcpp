\name{exposeClass}
\alias{exposeClass}
\title{
Create an Rcpp Module to Expose a C++ Class in R
}
\description{
The arguments specify a C++ class and some combination of
constructors, fields and methods to be shared with \R by creating a
corresponding reference class in \R.
The information needed in the call to \code{exposeClass()} is the
simplest possible in order to create a C++ module for the class; for
example, fields and methods in this class need only be identified by
their name.
Inherited fields and methods can also be included, but more
information is needed.
The function writes a C++ source file,
containing a module definition to expose the class to
\R, plus one line of \R source to create the corresponding reference
class.
}

\usage{
exposeClass(class, constructors = , fields = , methods = , file = ,
    header = , module = , CppClass = class, readOnly = , rename = ,
    Rfile = TRUE)
}

\arguments{
  \item{class}{
The name of the class in \R.  By default, this will be the same as the
name of the class in C++, unless argument \code{CppClass} is supplied.
}
  \item{constructors}{
A list of the signatures for any of the class constructors to be
called from \R.  Each element of the list gives the data types in C++
for the arguments to the corresponding constructor.  See Details and
the example.
}
  \item{fields, methods}{
The vector of names for the fields and for the methods to be exposed
in \R.  For inherited fields and methods, type information needs to be
supplied; see the section \dQuote{Inherited Fields and Methods}.
}
  \item{file}{
Usually, the name for the file on which to write the C++ code,  by default
\code{paste0(CppClass, "Module.cpp")}.
If the current working directory in \R is the top-level
directory for a package, the function writes the file in the
\code{"src"} subdirectory.
Otherwise the file is written in the working directory.

The argument may also be a connection, already open for writing.

}
  \item{header}{
Whatever lines of C++ header information are needed to include the
definition of the class.  Typically this includes a file from the
package where we are writing the module definition, as in the example below.
}
  \item{module}{
The name for the Rcpp module,   by default
\code{paste0("class_",CppClass)}.
}
  \item{CppClass}{
The name for the class in C++.  By default and usually, the intended
class name in \R.
}
  \item{readOnly}{
Optional vector of field names.  These fields will be created as
read-only in the interface.
}
  \item{rename}{
Optional named character vector, used to name fields or methods
differently in \R from their C++ name.  The elements of the vector are
the C++ names and the corresponding elements of \code{names(rename)}
the desired names in \R.  So \code{c(.age = "age")} renames the C++
field or method \code{age} as \code{.age}.
}
  \item{Rfile}{
Controls the writing of a one-line \R command to create the reference
class corresponding to the C++ module information.  By default, this
will be a file \code{paste0(class, "Class.R")}.
If the working directory is an \R package source
directory, the file will be written in the \code{R} subdirectory, otherwise in the working directory itself.

Supplying a character string substitutes that file name for the
default.

The argument may also be a connection  open for
writing or \code{FALSE} to suppress writing the \R source altogether.
}
}

\details{
The file created by the call to these functions only depends on the
information in the C++ class supplied.  This file is intended to be
part of the C++ source for an \R package.  The file only needs to
modified when the information changes, either because the class has
changed or because you want to expose different information to \R.  In
that case you can either recall \code{exposeClass()} or edit the C++
file created.

The Rcpp Module mechanism has a number of other optional techniques,
not covered by \code{exposeClass()}.  These should be entered into the
C++ file created.  See the \dQuote{rcpp-modules} vignette with the
package for current possibilities.

For fields and methods specified directly in the C++ class,
the fields and method arguments to \code{exposeClass()} are character vectors naming the
corresponding members of the class.  For module construction, the
data types of directly specified fields and of the arguments for the methods are not
needed.

For \emph{inherited} fields or methods, data type information is
needed.  See the section \dQuote{Inherited Fields and Methods}.

For exposing class constructors, the module needs to know the
signatures of the constructors to be exposed; each signature is a
character vector of the corresponding C++ data types.

}

\section{Inherited Fields and Methods}{
If the C++ class inherits from one or more other classes, the standard
Rcpp \code{Module} mechanism can not be used to expose inherited
fields or methods.
An indirect mechanism is used, generating free functions in C++ to
expose the inherited members in \R.

This mechanism requires data type information in the call to
\code{exposeClass()}.
This is provided by naming the corresponding element of the
\code{fields} or \code{methods} argument with the name of the member.
The actual element of the \code{fields} argument is then the single
data type of the field.

For the \code{methods} argument the argument will generally need to be
a named list.
The corresponding element of the list is the vector of data types for
the return value and for the arguments, if any, to the method.
For example, if C++ method \code{foo()} took a single argument of type
\code{NumericVector} and returned a value of type \code{long}, the
\code{methods} argument would be \code{list(foo = c("long",
  "NumericVector"))}.

See the second example below.
}
\value{
Nothing, called for its side effect.
}
\author{
  John Chambers
}
\seealso{
\code{\link{setRcppClass}}, which must be called from some \R source
in the package.
}
\examples{
\dontrun{
### Given the following C++ class, defined in file PopBD.h,
### the call to exposeClass() shown below will write a file
### src/PopBDModule.cpp containing a corresponding module definition.
###   class PopBD {
###     public:
###       PopBD(void);
###       PopBD(NumericVector initBirth, NumericVector initDeath);
###   
###       std::vector<double> birth;
###       std::vector<double> death;
###       std::vector<int> lineage;
###       std::vector<long> size;
###       void evolve(int);
###   
###   };
### A file R/PopBDClass.R will be written containing the one line:
###   PopBD <- setRcppClass("PopBD")
###
### The call below exposes the lineage and size fields, read-only,
### and the evolve() method.

exposeClass("PopBD",
      constructors =
        list("", c("NumericVector", "NumericVector")),
      fields = c("lineage", "size"),
      methods = "evolve",
      header = '#include "PopBD.h"',
      readOnly = c("lineage", "size"))

### Example with inheritance:  the class PopCount inherits from 
### the previous class, and adds a method table().  It has the same
### constructors as the previous class.
### To expose the table() method, and the inherited evolve() method and size field:

exposeClass("PopCount",
      constructors =
        list("", c("NumericVector", "NumericVector")),
      fields = c(size = "std::vector<long>"),
      methods = list("table", evolve = c("void", "int")),
      header = '#include "PopCount.h"',
      readOnly = "size")
}
}

\keyword{ programming }
\keyword{ classes }
