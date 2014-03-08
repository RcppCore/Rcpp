# Copyright (C) 2010 - 2014  Dirk Eddelbuettel, Romain Francois and Kevin Ushey
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

test <- function(output=if(file.exists("/tmp")) "/tmp" else getwd(),
                 gctorture=FALSE,
                 gctorture.exclude="runit.Module.client.package.R") {
    
    if (require(RUnit)) {
        
        if (gctorture) {
            
            message("Running tests with gctorture(TRUE)")
            if (length(gctorture.exclude)) {
                message("The following tests will be excluded:\n",
                    paste(">>", gctorture.exclude, collapse="\n")
                )
            }
            
            unitTestsDir <- system.file("unitTests", package="Rcpp")
            files <- list.files(
                unitTestsDir,
                recursive=TRUE
            )
            files <- setdiff(files, gctorture.exclude)
            dirs <- list.dirs(unitTestsDir, full.names=FALSE)
            testDir <- file.path( tempdir(), "RcppTests" )
            for (dir in file.path(testDir, dirs)) dir.create(dir)
            
            copySuccess <- sapply(files, function(file) {
                file.copy(
                    file.path(unitTestsDir, file), 
                    file.path(testDir, file)
                )
            })
            
            if (!all(copySuccess)) {
                stop("Could not copy test files to temporary directory")
            }
            
            ## Modify all the test files that were copied
            testFiles <- list.files(testDir, pattern="^runit", full.names=TRUE)
            for (file in testFiles) gctortureRUnitTest(file)
            
            ## Ensure we can read and parse each file
            for (file in testFiles) {
                tryCatch( parse(text=readLines(file)),
                    error=function(e) {
                        "could not parse test file"
                    }
                )
            }
            
        } else {
            testDir <- system.file("unitTests", package = "Rcpp")
        }
        
        testSuite <- defineTestSuite(name="Rcpp Unit Tests",
                                     dirs=testDir,
                                     testFuncRegexp = "^[Tt]est.+")

        ## if someoone calls Rcpp::test(), he/she wants all tests
        Sys.setenv("RunAllRcppTests"="yes")

        ## Run tests
        tests <- runTestSuite(testSuite)

        ## Print results
        printTextProtocol(tests)

        return(tests)
    }
  
    stop("Running unit tests requires the 'RUnit' package.")
}

unitTestSetup <- function(file, packages=NULL,
                          pathToRcppTests=system.file("unitTests", package = "Rcpp")) {
    function() {
        if (! is.null(packages)) {
            for (p in packages) {
                suppressMessages(require(p, character.only=TRUE))
            }
        }
        sourceCpp(file.path(pathToRcppTests, "cpp", file))
    }
}

gctortureRUnitTest <- function(file) {
    
    test <- readLines(file)
    
    ## TODO: handle '{', '}' within quotes
    findMatchingBrace <- function(test, start, balance=1) {
        line <- test[start]
        if (start > length(test)) {
            stop("error")
        }
        if (balance > 0) {
            balance <- balance + 
                sum(gregexpr("{", line, fixed=TRUE)[[1]] > 0) -
                sum(gregexpr("}", line, fixed=TRUE)[[1]] > 0)
            return( findMatchingBrace(test, start+1, balance) )
        }
        return(start - 1)
    }
    
    ## Find the lines defining unit tests
    testStarts <- grep("^[[:space:]]*[Tt]est\\.+", test)
    
    ## Get the line with the closing brace
    testEnds <- sapply(testStarts, function(ind) {
        findMatchingBrace(test, ind + 1)
    })
    stopifnot( length(testStarts) == length(testEnds) )
    
    ## Modify the function definition by wrapping it in gctorture
    for (i in seq_along(testStarts)) {
        start <- testStarts[i]
        end <- testEnds[i]
        test[start] <- paste( test[start], "gctorture(TRUE);" )
        test[end] <- paste("gctorture(FALSE); }")
    }
    
    cat(test, file=file, sep="\n")
    
}
