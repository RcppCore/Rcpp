\name{pluginsAttribute}
\alias{pluginsAttribute}

\title{Rcpp::plugins Attribute}

\description{
The \code{Rcpp::plugins} attribute is added to a C++ source file to specify the
\link[inline:plugins]{inline plugins} that should be used in the compilation.
\preformatted{
// [[Rcpp::plugins(plugin1, plugin2)]]
}
}

\arguments{
 \item{\dots}{
   Plugins to add to the compilation.
}
}

\details{
Plugins must be registered using the \code{\link{registerPlugin}}
function. 

When included within a \code{\link{sourceCpp}} translation unit,
the configuration-related fields of the plugin (e.g. \code{env} and 
\code{LinkingTo}) are utilized, however the code-generation fields
(e.g. \code{includes} and \code{body}) are not.

}
\note{
\pkg{Rcpp} includes a built-in \code{cpp11} plugin that
adds the flags required to enable \code{C++11} features in the compiler.
}

\seealso{
\code{\link{registerPlugin}}
}

\examples{
\dontrun{

// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
int useCpp11() {
    auto x = 10;
    return x;
}
}
}

