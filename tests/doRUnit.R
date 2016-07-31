# Copyright (C) 2009 - 2014 Dirk Eddelbuettel and Romain Francois
# Earlier copyrights Gregor Gorjanc, Martin Maechler and Murray Stokely as detailed below
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

## doRUnit.R --- Run RUnit tests
##
## with credits to package fUtilities in RMetrics
## which credits Gregor Gojanc's example in CRAN package  'gdata'
## as per the R Wiki http://wiki.r-project.org/rwiki/doku.php?id=developers:runit
## and changed further by Martin Maechler
## and more changes by Murray Stokely in HistogramTools
## and then used adapted in RProtoBuf
## and now used here with two additional env var setters/getters
##
## Dirk Eddelbuettel, Feb 2014

stopifnot(require(RUnit, quietly=TRUE))
stopifnot(require(Rcpp, quietly=TRUE))

## Set a seed to make the test deterministic
set.seed(42)

## Define tests
testSuite <- defineTestSuite(name = "Rcpp Unit Tests",
                             dirs = system.file("unitTests", package = "Rcpp"),
                             testFuncRegexp = "^[Tt]est.+")

## without this, we get (or used to get) unit test failures
Sys.setenv("R_TESTS"="")

## force tests to be executed if in dev release which we define as
## having a sub-release, eg 0.9.15.5 is one whereas 0.9.16 is not
if (length(strsplit(packageDescription("Rcpp")$Version, "\\.")[[1]]) > 3) {	# dev release, and
    if (Sys.getenv("RunAllRcppTests") != "no") { 				# if env.var not yet set
        message("Setting \"RunAllRcppTests\"=\"yes\" for development release\n")
        Sys.setenv("RunAllRcppTests"="yes")
    }
}

## Run tests
tests <- runTestSuite(testSuite)

## Print results
printTextProtocol(tests)

## Return success or failure to R CMD CHECK
if (getErrors(tests)$nFail > 0) {
    stop("TEST FAILED!")
}
if (getErrors(tests)$nErr > 0) {
    stop("TEST HAD ERRORS!")
}
if (getErrors(tests)$nTestFunc < 1 && Sys.getenv("RunAllRcppTests")=="yes") {
    stop("NO TEST FUNCTIONS RUN!")
}

