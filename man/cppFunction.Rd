\name{cppFunction}
\alias{cppFunction}
\title{
Define an R Function with a C++ Implementation
}
\description{
Dynamically define an R function with C++ source code. Compiles and links a shared library with bindings to the C++ function then defines an R function that uses \code{.Call} to invoke the library.
}
\usage{
cppFunction(code, plugin = NULL, includes = NULL, 
            envir = parent.frame(), rebuild = FALSE, 
            verbose = getOption("verbose"))
}

\arguments{
  \item{code}{
    Source code for the function definition.
}
  \item{plugin}{
    The name of an \link[inline:plugins]{inline plugin} to use for the compilation.
}
  \item{includes}{
    User includes, inserted after the includes provided by the plugin.
}
  \item{envir}{
    The \link[base:environment]{environment} in which to define the R function. May be \code{NULL} in which case the defined function can be obtained from the return value of \code{cppFunction}.
}
  \item{rebuild}{
    Force a rebuild of the shared library.
}
  \item{verbose}{
    \code{TRUE} to print detailed information about generated code to the console.
}
}
\details{
   Functions defined using \code{cppFunction} must have return types that are compatible with \code{Rcpp::wrap} and parameter types that are compatible with \code{Rcpp::as}.
        
    The shared library will not be rebuilt if the underlying code has not changed since the last compilation.
}
\value{
    An R function that uses \code{.Call} to invoke the underlying C++ function.
}

\note{
    You can also define R functions with C++ implementations using the \code{\link{sourceCpp}} function, which allows you to separate the C++ code into it's own source file. For many use cases this is an easier and more maintainable approach.
}


\seealso{
\code{\link{sourceCpp}}
}
\examples{
\dontrun{

cppFunction(
    'int fibonacci(const int x) {
        if (x == 0) return(0); 
        if (x == 1) return(1);
        return (fibonacci(x - 1)) + fibonacci(x - 2);
    }')

cppFunction(plugin = "RcppArmadillo",
    'List fastLm(NumericVector yr, NumericMatrix Xr) {
        
        int n = Xr.nrow(), k = Xr.ncol();
        
        arma::mat X(Xr.begin(), n, k, false); 
        arma::colvec y(yr.begin(), yr.size(), false);
        
        arma::colvec coef = arma::solve(X, y);
        arma::colvec resid = y - X*coef;
        
        double sig2 = arma::as_scalar(arma::trans(resid)*resid/(n-k) );
        arma::colvec stderrest = arma::sqrt(
            sig2 * arma::diagvec(arma::inv(arma::trans(X)*X)));
        
        return List::create(Named("coefficients") = coef,
            Named("stderr")       = stderrest
        );
    }')
}
}
