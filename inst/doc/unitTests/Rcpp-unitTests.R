pkg <- "Rcpp"

# load this package
require( pkg, character.only = TRUE )
require( inline )

if( compareVersion( packageDescription( "inline" )[["Version"]], "0.3.4.4" ) < 0 ){
	stop( "Rcpp unit tests need at least the version 0.3.4.4 of inline" )
}

cppfunction <- function( ... ){
	cxxfunction( ..., plugin = "Rcpp" )
}

#load RUnit
runit <- "RUnit" ; require( runit, character.only = TRUE )
if( file.exists( "unitTests-results" ) ){ unlink("unitTests-results", recursive = TRUE ) }
dir.create( "unitTests-results" ) 

path <- system.file("unitTests", package = pkg)
testSuite <- defineTestSuite(name=paste(pkg, "unit testing"), dirs = path)
tests <- runTestSuite(testSuite)
err <- getErrors(tests)
if( (err$nFail + err$nErr) > 0) {
    stop( sprintf( "unit test problems: %d failures, %d errors", err$nFail, err$nErr) )
}
printHTMLProtocol(tests, fileName= sprintf( "unitTests-results/%s-unitTests.html" , pkg ) )
printTextProtocol(tests, fileName= sprintf( "unitTests-results/%s-unitTests.txt"  , pkg ) )
if( file.exists( "/tmp" ) ){
	file.copy( sprintf( "unitTests-results/%s-unitTests.txt" , pkg ) , "/tmp", overwrite = TRUE )
	file.copy( sprintf( "unitTests-results/%s-unitTests.html", pkg ) , "/tmp", overwrite = TRUE )
}

