\name{cppFunction}
\alias{cppFunction}
\title{
Define an R Function with a C++ Implementation
}
\description{
Dynamically define an R function with C++ source code. Compiles and links a shared library with bindings to the C++ function then defines an R function that uses \code{.Call} to invoke the library.
}
\usage{
cppFunction(code, depends = character(), plugins = character(),
            includes = character(), env = parent.frame(), rebuild = FALSE, 
            showOutput = verbose, verbose = getOption("verbose"))
}

\arguments{
  \item{code}{
    Source code for the function definition.
}
  \item{depends}{
    Character vector of packages that the compilation depends on. Each package listed will first be queried for an \link[inline:plugins]{inline plugin} to determine header files to include. If no plugin is defined for the package then a header file based the package's name (e.g. \code{PkgName.hpp}) will be included.
}
  \item{plugins}{
    Character vector of \link[inline:plugins]{inline plugins} to use for the compliation.
  }
  \item{includes}{
    Character vector of user includes (inserted after the includes provided by \code{depends}).
}
  \item{env}{
    The \link[base:environment]{environment} in which to define the R function. May be \code{NULL} in which case the defined function can be obtained from the return value of \code{cppFunction}.
}
  \item{rebuild}{
    Force a rebuild of the shared library.
}
  \item{showOutput}{
    \code{TRUE} to print \code{R CMD SHLIB} output to the console.
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
\code{\link{sourceCpp}},  \code{\link{evalCpp}}
}
\examples{
\dontrun{

cppFunction(
    'int fibonacci(const int x) {
        if (x == 0) return(0); 
        if (x == 1) return(1);
        return (fibonacci(x - 1)) + fibonacci(x - 2);
    }')

cppFunction(depends = "RcppArmadillo",
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
    
cppFunction(plugins=c("cpp11"), '
    int useCpp11() {
        auto x = 10;
        return x;
    }')
    
}
}
