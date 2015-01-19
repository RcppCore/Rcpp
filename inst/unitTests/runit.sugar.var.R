#!/usr/bin/r -t
#                     -*- mode: R; ess-indent-level: 4; indent-tabs-mode: nil; -*-
#
# Copyright (C) 2015 Wush Wu
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

    test.Sugar.var <- function() {
        f1 <- Rcpp::cppFunction('double myVar(NumericVector x) { return(var(x)); }')
        f2 <- Rcpp::cppFunction('double myVar(IntegerVector x) { return(var(x)); }')
        f3 <- Rcpp::cppFunction('double myVar(ComplexVector x) { return(var(x)); }')
        f4 <- Rcpp::cppFunction('double myVar(LogicalVector x) { return(var(x)); }')
        checkEquals(f1((1:10) * 1.1), var((1:10) * 1.1))
        checkEquals(f2(1:10), var(1:10))
        checkEquals(f3(1:10 + (1 + 1i)), var(1:10 + (1 + 1i)))
        checkEquals(f4(c(T, F, T, F, T)), var(c(T, F, T, F, T)))
    }

}
