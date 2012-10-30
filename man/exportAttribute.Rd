\name{exportAttribute}
\alias{exportAttribute}

\title{Rcpp::export Attribute}

\description{
The \code{Rcpp::export} attribute is added to a C++ function definition to indicate that it should be made available as an R function. The \code{\link{sourceCpp}} and \code{\link{compileAttributes}} functions process the \code{Rcpp::export} attribute by generating the code required to call the C++ function from R.
}

\arguments{
  \item{name}{
    Specify an alternate name for the generated R function (optional, defaults to the name of the C++ function if not specified).
}
}

\details{
    Functions marked with the \code{Rcpp::export} attribute must have return types that are compatible with \code{Rcpp::wrap} and parameter types that are compatible with \code{Rcpp::as}.
    
    The \code{Rcpp::export} attribute is specified using a syntax compatible with the new \href{http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2761.pdf}{generalized attributes} feature of the C++11 standard. Note however that since this feature is not yet broadly supported by compilers it needs to be specified within a comment (see examples below).
}


\seealso{
\code{\link{sourceCpp}}, \code{\link{compileAttributes}}
}

\examples{
\dontrun{

// [[Rcpp::export]]
int fibonacci(const int x) {

   if (x == 0) return(0);
   if (x == 1) return(1);
   
   return (fibonacci(x - 1)) + fibonacci(x - 2);
}

// [[Rcpp::export("convolveCpp")]]
NumericVector convolve(NumericVector a, NumericVector b) {

   int na = a.size(), nb = b.size();
   int nab = na + nb - 1;
   NumericVector xab(nab);
    
   for (int i = 0; i < na; i++)
      for (int j = 0; j < nb; j++)
         xab[i + j] += a[i] * b[j];
    
   return xab;
}
}
}
