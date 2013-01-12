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
    Note that plugins must be registered using the \code{\link{registerPlugin}}
    function. \pkg{Rcpp} also includes a built-in \code{cpp11} plugin that
    adds the flag required to enable \code{C++11} features in the compiler.
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

