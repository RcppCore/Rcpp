#!/usr/bin/r -t
#
# Copyright (C) 2010 - 2015  Dirk Eddelbuettel and Romain Francois
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

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes"

if (.runThisTest) {

    .setUp <- Rcpp:::unitTestSetup("algorithms.cpp")

    test.sum <- function() {
        v <- c(1.0, 2.0, 3.0, 4.0, 5.0)
        checkEquals(sum(v), sumTest(v, 1, 5))
    }

    test.prod <- function() {
        v <- c(1.0, 2.0, 3.0, 4.0, 5.0)
        checkEquals(prod(v), prodTest(v, 1, 5))
    }

    test.log <- function() {
        v <- c(1.0, 2.0, 3.0, 4.0, 5.0)
        checkEquals(log(v), logTest(v))
    }

    test.exp <- function() {
        v <- c(1.0, 2.0, 3.0, 4.0, 5.0)
        checkEquals(exp(v), expTest(v))
    }

    test.sqrt <- function() {
        v <- c(1.0, 2.0, 3.0, 4.0, 5.0)
        checkEquals(sqrt(v), sqrtTest(v))
    }
}
