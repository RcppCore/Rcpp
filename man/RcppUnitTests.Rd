\name{RcppUnitTests}
\alias{RcppUnitTests}

\title{Rcpp : unit tests results}
\description{
Unit tests results for package Rcpp. 

Unit tests are run automatically at build time and reports are included in the
\samp{doc} directory as html or text. 
}

\seealso{
\ifelse{latex}{}{\ifelse{html}{\url{../doc/unitTests-results/Rcpp-unitTests.html}: html formatted unit test report}{\samp{../doc/unitTests-results/Rcpp-unitTests.html}: html formatted unit test report}}
}

\details{
\ifelse{latex}{}{\ifelse{html}{\out{<pre>}}{}}
\Sexpr[echo=FALSE,results=text]{ 
txt <- system.file( "doc", "unitTests-results", "Rcpp-unitTests.txt", package = "Rcpp" )
if( file.exists( txt ) ) paste( readLines( txt ), collapse = "\n\n" ) else ""
}
\ifelse{latex}{}{\ifelse{html}{\out{</pre>}}{}}
}

\examples{
# unit tests are in the unitTests directory of the package
list.files( system.file("unitTests", package = "Rcpp" ), 
	pattern = "^runit", full = TRUE )

# trigger the unit tests preparation, follow printed instructions
# on how to run them
\dontrun{
source( system.file("unitTests", "runTests.R", package = "Rcpp" ) )
}
}

\keyword{programming}
