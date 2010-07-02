#!/usr/bin/r -t
#
# Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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

test.RcppStringVector.classic <- function() {
    src <- 'RcppStringVector s = RcppStringVector(sx);
            RcppResultSet rs;
            rs.add("string", s);
	        return rs.getReturnList();';
    fun <- cxxfunction(signature(sx="character"), src, plugin="Rcpp")
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), list(string=sv), msg = "RcppStringVector.classic")
}

test.RcppStringVector.wrap <- function() {
    src <- 'RcppStringVector s = RcppStringVector(sx);
	        return wrap(s);';
    fun <- cxxfunction(signature(sx="character"), src, plugin="Rcpp")
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), sv, msg = "RcppStringVector.wrap")
}

test.RcppStringVector.begin <- function() {
    src <- 'RcppStringVector s = RcppStringVector(sx);
            return wrap(*s.begin());';
    fun <- cxxfunction(signature(sx="character"), src, plugin="Rcpp")
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), sv[1], msg = "RcppStringVector.begin")
}

test.RcppStringVector.end <- function() {
    src <- 'RcppStringVector s = RcppStringVector(sx);
            return wrap(s(s.size()-1));';
    fun <- cxxfunction(signature(sx="character"), src, plugin="Rcpp")
    sv <- c("tic", "tac", "toe")
    checkEquals(fun(sv), sv[3], msg = "RcppStringVector.begin")
}


