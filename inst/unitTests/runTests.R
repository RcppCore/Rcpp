## -*- mode: R; tab-width: 4 -*-
##
## Copyright (C) 2009- 2010	Dirk Eddelbuettel and Romain Francois
##
## This file is part of Rcpp.
##
## Rcpp is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 2 of the License, or
## (at your option) any later version.
##
## Rcpp is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

pkg <- "Rcpp"

if( ! require( "inline", character.only = TRUE, quietly = TRUE ) ){
    stop( "The inline package is required to run Rcpp unit tests" )
}

if( compareVersion( packageDescription( "inline" )[["Version"]], "0.3.4.4" ) < 0 ){
    stop( "Rcpp unit tests need at least the version 0.3.4.4 of inline" )
}

cppfunction <- function(...){
    cxxfunction( ..., plugin = "Rcpp" )
}

if(require("RUnit", quietly = TRUE)) {

    is_local <- function(){
    	if( exists( "argv", globalenv() ) && "--local" %in% argv ) return(TRUE)
    	if( "--local" %in% commandArgs(TRUE) ) return(TRUE)
    	FALSE
    }
    if (is_local() ) path <- getwd()

    library(package=pkg, character.only = TRUE)
    if(!(exists("path") && file.exists(path)))
        path <- system.file("unitTests", package = pkg)

    ## --- Testing ---

    ## Define tests
    testSuite <- defineTestSuite(name=paste(pkg, "unit testing"), dirs = path
                                        # , testFileRegexp = "runit.Argument.R"
                                 )

    ## this is crass but as we time out on Windows we have no choice
    ## but to disable a number of tests
    ## TODO: actually prioritize which ones we want
    allTests <- function() {
        if (.Platform$OS.type != "windows") return(TRUE)
    	if (exists( "argv", globalenv() ) && "--allTests" %in% argv) return(TRUE)
    	if ("--allTests" %in% commandArgs(TRUE)) return(TRUE)
    	return(FALSE)
    }
    if (.Platform$OS.type == "windows" && allTests() == FALSE) {
        ## by imposing [D-Z] (instead of an implicit A-Z) we are going from
        ## 45 tests to run down to 38 (numbers as of release 0.8.3)
        testSuite$testFileRegexp <- "^runit.[D-Z]+\\.[rR]$"
    }

    if (interactive()) {
        cat("Now have RUnit Test Suite 'testSuite' for package '", pkg,
            "' :\n", sep='')
        str(testSuite)
        cat('', "Consider doing",
            "\t  tests <- runTestSuite(testSuite)", "\nand later",
            "\t  printTextProtocol(tests)", '', sep="\n")
    } else { ## run from shell / Rscript / R CMD Batch / ...

        ## Run
        tests <- runTestSuite(testSuite)

        output <- NULL

        process_args <- function(argv){
            if( !is.null(argv) && length(argv) > 0 ){
                rx <- "^--output=(.*)$"
                g  <- grep( rx, argv, value = TRUE )
                if( length(g) ){
                    sub( rx, "\\1", g[1L] )
                }
            }
        }

                                        # R CMD check uses this
        if( exists( "Rcpp.unit.test.output.dir", globalenv() ) ){
            output <- Rcpp.unit.test.output.dir
        } else {

            ## give a chance to the user to customize where he/she wants
            ## the unit tests results to be stored with the --output= command
            ## line argument
            if( exists( "argv",  globalenv() ) ){
                ## littler
                output <- process_args(argv)
            } else {
                ## Rscript
                output <- process_args(commandArgs(TRUE))
            }
        }

                                        # if it did not work, try to use /tmp
        if( is.null(output) ){
            if( file.exists( "/tmp" ) ){
                output <- "/tmp"
            } else{
                output <- getwd()
            }
        }

        ## Print results
        output.txt  <- file.path( output, sprintf("%s-unitTests.txt", pkg))
        output.html <- file.path( output, sprintf("%s-unitTests.html", pkg))

        printTextProtocol(tests, fileName=output.txt)
        message( sprintf( "saving txt unit test report to '%s'", output.txt ) )

        ## Print HTML version to a file
        ## printHTMLProtocol has problems on Mac OS X
        if (Sys.info()["sysname"] != "Darwin"){
            message( sprintf( "saving html unit test report to '%s'", output.html ) )
            printHTMLProtocol(tests, fileName=output.html)
        }

        ##  stop() if there are any failures i.e. FALSE to unit test.
        ## This will cause R CMD check to return error and stop
        err <- getErrors(tests)
        if( (err$nFail + err$nErr) > 0) {
            stop( sprintf( "unit test problems: %d failures, %d errors", err$nFail, err$nErr) )
        } else{
            success <- err$nTestFunc - err$nFail - err$nErr - err$nDeactivated
            cat( sprintf( "%d / %d\n", success, err$nTestFunc ) )
        }
    }

} else {
    cat("R package 'RUnit' cannot be loaded -- no unit tests run\n",
        "for package", pkg,"\n")
}

