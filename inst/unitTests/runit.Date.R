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

test.Date.ctor.mdy <- function() {
    src <- 'Rcpp::Date dt = Rcpp::Date(12,31,2005);
	    return Rcpp::wrap(dt);';
    fun <- cppfunction(signature(), src)
    checkEquals(fun(), as.Date("2005-12-31"), msg = "Date.ctor.mdy")
}

test.Date.ctor.ymd <- function() {
    src <- 'Rcpp::Date dt = Rcpp::Date(2005,12,31);
	    return Rcpp::wrap(dt);';
    fun <- cppfunction(signature(), src)
    checkEquals(fun(), as.Date("2005-12-31"), msg = "Date.ctor.ymd")
}

test.Date.ctor.int <- function() {
    src <- 'Rcpp::Date dt = Rcpp::Date(Rcpp::as<int>(d));
	    return Rcpp::wrap(dt);';
    fun <- cppfunction(signature(d="numeric"), src)
    d <- as.Date("2005-12-31")
    checkEquals(fun(as.numeric(d)), d, msg = "Date.ctor.int")
    checkEquals(fun(-1), as.Date("1970-01-01")-1, msg = "Date.ctor.int")
    checkException(fun("foo"), msg = "Date.ctor -> exception" )
}


