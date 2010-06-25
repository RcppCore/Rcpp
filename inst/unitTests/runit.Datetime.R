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

test.Datetime.get.functions <- function() {
    src <- 'Datetime dt = Datetime(x);
            return List::create(Named("year") = dt.getYear(),
                                Named("month") = dt.getMonth(),
                                Named("day") = dt.getDay(),
                                Named("wday") = dt.getWeekday(),
                                Named("hour") = dt.getHours(),
                                Named("minute") = dt.getMinutes(),
                                Named("second") = dt.getSeconds(),
                                Named("microsec") = dt.getMicroSeconds());'
    fun <- cxxfunction(signature(x="Datetime"), src,  plugin="Rcpp")
    checkEquals(fun(as.numeric(as.POSIXct("2001-02-03 01:02:03.123456", tz="UTC"))),
                list(year=2001, month=2, day=3, wday=7, hour=1, minute=2, second=3, microsec=123456),
                msg = "Date.get.functions")
}

test.Datetime.operators <- function() {
    src <- 'Datetime d1 = Datetime(946774923.123456);
            Datetime d2 = d1 + 60*60;
            return List::create(Named("diff") = d2 - d1,
                                Named("bigger") = d2 > d1,
                                Named("smaller") = d2 < d1,
                                Named("equal") = d2 == d1,
                                Named("ge") = d2 >= d1,
                                Named("le") = d2 <= d1,
                                Named("ne") = d2 != d1);'
    fun <- cxxfunction(signature(), src, plugin="Rcpp")
    checkEquals(fun(),
                list(diff=-60*60, bigger=TRUE, smaller=FALSE, equal=FALSE, ge=TRUE, le=FALSE, ne=TRUE),
                msg = "Datetime.operators")
}

test.Datetime.wrap <- function() {
    src <- 'Datetime dt = Datetime(981162123.123456);
	    return wrap(dt);';
    fun <- cxxfunction(signature(), src, plugin = "Rcpp" )
    checkEquals(as.numeric(fun()), as.numeric(as.POSIXct("2001-02-03 01:02:03.123456", tz="UTC")),
                msg = "Datetime.wrap")
}

