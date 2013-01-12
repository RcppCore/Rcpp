\name{registerPlugin}
\alias{registerPlugin}
\title{
Register an inline plugin
}
\description{
Register an \link[inline:plugins]{inline plugin} for use with 
\code{\link{sourceCpp}} or \code{\link{cppFunction}}. Inline plugins are functions
that return a list with additional includes, environment variables, and
other compilation context. 
}
\usage{
registerPlugin(name, plugin)
}
\arguments{
    \item{name}{Name of the inline plugin}
    \item{plugin}{Inline plugin function}
}
\details{
    Plugins can be added to \code{\link{sourceCpp}} compilations using the
    \code{\link[=pluginsAttribute]{Rcpp::plugins}} attribute.
}
\seealso{
    \code{\link[=pluginsAttribute]{Rcpp::plugins}}
}


