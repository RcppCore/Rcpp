\name{loadModule}
\alias{loadModule}
\title{
Load an Rcpp Module into a Package
}
\description{
One or more calls to \code{loadModule} will be included in the source
code for a package to load modules and optionally expose objects from
them.  The actual extraction of the module takes place at load time.
}
\usage{
loadModule(module, what = , loadNow, env =)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{module}{
The name of the C++ module to load.  The code for the module should be
in the same package as the \R{} call to \code{loadModule}.
}
  \item{what}{
The objects to expose in the package's namespace corresponding to
objects in the module.  By default, nothing is exposed.

The special value \code{TRUE} says to load all the objects in the
module that have syntactically standard \R{} names (which all objects
in a module will normally have).

Otherwise, if supplied this should be a character vector, the elements being
objects defined in the module.  The vector can have a names attribute,
in which case the non-empty names will be used to rename the objects;
otherwise, the name of the object in the package namespace will be the
same as the name in the C++ module.
}
  \item{loadNow, env}{
A logical flag to say whether the load actions should happen now, and
the environment into which the objects should be inserted.  When
called from the source of a package, both of these arguments should
usually be omitted.

The value of \code{loadNow} will be set by checking the module's
status.  At package installation time, the module cannot be started,
in which case a load action (see \code{\link{setLoadAction}}) is
scheduled to do the actual module load.

The value of \code{env} will default to the package's namespace.
}
}
\details{
If the purpose of loading the module is to define classes based on C++
classes, see \code{\link{setRcppClass}()}, which does the necessary
module loading for you.

When the module can be started (at namespace load time), the function
\code{\link{Module}()} returns an environment with a description of
the module's contents. Function \code{loadModule()} saves this as a
metadata object in the package namespace.  Therefore multiple calls to
\code{loadModule()} are an efficient way to extract different objects
from the module.

Requesting an object that does not exist in the module produces a
warning.

Since assignments from the call cannot take place until namespace
loading time, any computations using the objects must also be
postponed until this time.  Use load actions
(\code{\link{setLoadAction}}) and make sure that the load action is
specified after the call to \code{loadModule()}.
}
\value{
If the load takes place, the module environment is returned.  Usually
however the function is called for its side effects.
}
\note{
This function requires version  2.15.0 of \R{} or later, in order to
use load actions, introduced in that version.  See the note in the
help page for \code{\link{setRcppClass}()} for details.
}
\author{
John Chambers
}
\seealso{
\code{\link{setRcppClass}()} to avoid the explicit call.

\code{\link{loadRcppModules}()} for a shotgun procedure to load all
modules.
}
\examples{
\dontrun{
loadModule("yada", TRUE) # load all the objects from module "yada"
}
}
\keyword{ programming }
