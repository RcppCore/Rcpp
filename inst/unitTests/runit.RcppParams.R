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

test.RcppParams.Double <- function() {
    src <- 'double y = 2 * RcppParams(x).getDoubleValue("val");
	    return Rcpp::wrap(y);';
    funx <- cppfunction(signature(x="ANY"), src)
    checkEquals(funx(list(val=1.234)), 2*1.234, msg="RcppParams.getDoubleValue")
}

test.RcppParams.Int <- function() {
    src <- 'int y = 2 * RcppParams(x).getIntValue("val");
	    return Rcpp::wrap(y);';
    funx <- cppfunction(signature(x="ANY"), src)
    checkEquals(funx(list(val=42)), 2*42, msg="RcppParams.getIntValue")
}

test.RcppParams.String <- function() {
    src <- 'std::string y = RcppParams(x).getStringValue("val");
            y = y + y; // trivial string operation
	    return Rcpp::wrap(y);';
    funx <- cppfunction(signature(x = "ANY"), src)
    checkEquals(funx(list(val="a test string")), "a test stringa test string", msg = "RcppParams.getStringValue")
}

test.RcppParams.Bool <- function() {
    src <- 'bool y = RcppParams(x).getBoolValue("val");
	    return Rcpp::wrap(y);';
    funx <- cppfunction(signature(x = "ANY"), src)
    checkEquals(funx(list(val=FALSE)), FALSE, msg = "RcppParams.getBoolValue")
}

test.RcppParams.Date <- function() {
    src <- 'RcppDate y = RcppParams(x).getDateValue("val");
            RcppResultSet rs;
            rs.add("date", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x = "ANY"), src)
    checkEquals(funx(list(val=as.Date("2000-01-01")))[[1]], as.Date("2000-01-01"), msg = "RcppParams.getDateValue")
}

test.RcppParams.Datetime <- function() {
    src <- 'RcppDatetime y = RcppParams(x).getDatetimeValue("val");
            RcppResultSet rs;
            rs.add("datetime", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x = "ANY"), src)
    posixt <- as.POSIXct(strptime("2000-01-02 03:04:05.678", "%Y-%m-%d %H:%M:%0S"))
    attr(posixt, "tzone") <- NULL    ## because we don't set a tzone attribute in C++
    checkEquals(funx(list(val=posixt))[[1]], posixt, msg = "RcppParams.getDatetimeValue")
}

