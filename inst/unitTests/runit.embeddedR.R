#!/usr/bin/env r
# -*- mode: R; ess-indent-level: 4; tab-width: 4; indent-tabs-mode: nil; -*
#
# Copyright (C) 2012 - 2016  Dirk Eddelbuettel and Romain Francois
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

.runThisTest <- TRUE # Sys.getenv("RunAllRcppTests") == "yes"

if (.runThisTest) {

    test.embeddedR <- function() {

        path <- system.file("unitTests", package = "Rcpp")
        expectedVars <- c("foo", "x")
        newEnv <- new.env()
        Rcpp::sourceCpp(file.path(path, "cpp", "embeddedR.cpp"), env = newEnv)
        checkEquals(ls(newEnv), expectedVars, msg = " sourcing code in other env")
    }

}



