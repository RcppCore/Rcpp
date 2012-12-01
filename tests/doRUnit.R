# Copyright (C) 2009 - 2012 Dirk Eddelbuettel and Romain Francois
# Earlier copyrights Gregor Gorjanc and Martin Maechler as detailed below
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

## Unit test wrapper invoked from tests/

##
## Based on a file written by Martin Maechler for the Rmetrics
## packages which itself was based on earlier work by Gregor Gorjanc
## and documented on the R Wiki.

## doRUnit.R --- Run RUnit tests
## ------------------------------------------------------------------------
##
## borrowed from package fUtilities in RMetrics
## http://r-forge.r-project.org/plugins/scmsvn/viewcvs.php/pkg/fUtilities/tests/doRUnit.R?rev=1958&root=rmetrics&view=markup
##
## Originally follows Gregor Gorjanc's example in CRAN package  'gdata'
## and the corresponding section in the R Wiki:
## http://wiki.r-project.org/rwiki/doku.php?id=developers:runit
##
## MM: Vastly changed:  This should also be "runnable" for *installed*
##     package which has no ./tests/
##     --> put the bulk of the code e.g. in  ../inst/unitTests/runTests.R :

if (require("RUnit", quietly = TRUE)) {

    pkg <- "Rcpp"                           # code below for Rcpp
    require(pkg, character.only=TRUE)
    pathRcppTests <<- system.file("unitTests", package = pkg)
    stopifnot(file.exists(pathRcppTests), file.info(path.expand(pathRcppTests))$isdir)

    ## without this, we get unit test failures
    Sys.setenv( R_TESTS = "" )

    ## force tests to be executed if in dev release which we define as
    ## having a sub-release, eg 0.9.15.5 is one whereas 0.9.16 is not
    if (length(strsplit(packageDescription(pkg)$Version, "\\.")[[1]]) > 3) {	# dev release, and
        if (Sys.getenv("RunAllRcppTests") != "no") { 				# if env.var not yet set
            message("Setting \"RunAllRcppTests\"=\"yes\" for development release\n")
            Sys.setenv("RunAllRcppTests"="yes")
        }
    }

    Rcpp.unit.test.output.dir <- getwd()

    source(file.path(pathRcppTests, "runTests.R"), echo = TRUE)

} else {
    print("package RUnit not available, cannot run unit tests")
}
