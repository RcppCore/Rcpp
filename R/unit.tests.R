# Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois
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

test <- function(output=if(file.exists("/tmp")) "/tmp" else getwd()) {
    if (require(RUnit)) {
        testSuite <- defineTestSuite(name="Rcpp Unit Tests",
                                     dirs=system.file("unitTests", package = "Rcpp"),
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

