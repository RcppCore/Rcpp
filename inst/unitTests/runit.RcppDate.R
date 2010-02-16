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

.setUp <- function(){
    suppressMessages( require( inline ) )
}

test.RcppDate.get.functions <- function() {
    src <- 'RcppDate dt = RcppDate(12,31,1999);
            RcppResultSet rs;
            rs.add("month", dt.getMonth());
            rs.add("day",   dt.getDay());
            rs.add("year",  dt.getYear());
            rs.add("julian",dt.getJulian());
	    return rs.getReturnList();';
    funx <- cfunction(signature(), src, Rcpp=TRUE)
    checkEquals(funx(), list(month=12, day=31, year=1999, julian=10956), msg = "RcppDate.get.functions")
}

test.RcppDate.operators <- function() {
    src <- 'RcppDate d1 = RcppDate(12,31,1999);
            RcppDate d2 = d1 + 1;
            RcppResultSet rs;
            rs.add("diff",    d2 - d1);
            rs.add("bigger",  d2 > d1);
            rs.add("smaller", d2 < d1);
            rs.add("equal",   d2 == d1);
            rs.add("ge",      d2 >= d1);
            rs.add("le",      d2 <= d1);
	    return rs.getReturnList();';
    funx <- cfunction(signature(), src, Rcpp=TRUE)
    checkEquals(funx(), list(diff=1, bigger=1, smaller=0, equal=0, ge=1, le=0), msg = "RcppDate.operators")
}














