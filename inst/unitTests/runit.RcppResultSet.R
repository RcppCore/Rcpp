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

test.RcppResultSet.double <- function() {
    src <- 'double y = 1.23456;
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], 1.23456, msg = "RcppResultRet.double")
}

test.RcppResultSet.int <- function() {
    src <- 'int y = 42;
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], 42, msg = "RcppResultSet.int")
}

test.RcppResultSet.string <- function() {
    src <- 'std::string y = "hello unit tests";
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], "hello unit tests", msg = "RcppResultSet.string")
}

test.RcppResultSet.double.vector <- function() {
    src <- 'double y[3] = { 1.1, 2.2, 3.3 };
            RcppResultSet rs;
            rs.add("foo", y, 3);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], c(1.1, 2.2, 3.3), msg = "RcppResultSet.double.vector")
}

test.RcppResultSet.int.vector <- function() {
    src <- 'int y[3] = { 11, 22, 33 };
            RcppResultSet rs;
            rs.add("foo", y, 3);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], c(11, 22, 33), msg = "RcppResultSet.int.vector")
}

test.RcppResultSet.double.matrix <- function() {
    src <- 'double r1[2] = { 1.1, 2.2 };
            double r2[2] = { 3.3, 4.4 };
            double *y[2] = { r1, r2 };
            RcppResultSet rs;
            rs.add("foo", y, 2, 2);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], matrix(c(1.1, 2.2, 3.3, 4.4), 2, byrow=TRUE), msg = "RcppResultSet.double.matrix")
}

test.RcppResultSet.int.matrix <- function() {
    src <- 'int r1[2] = { 11, 22 };
            int r2[2] = { 33, 44 };
            int *y[2] = { r1, r2 };
            RcppResultSet rs;
            rs.add("foo", y, 2, 2);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], matrix(c(11, 22, 33, 44), 2, byrow=TRUE), msg = "RcppResultSet.int.matrix")
}

test.RcppResultSet.RcppDate <- function() {
    src <- 'RcppDate y(01,01,2000); // silly North American mon-day-year
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], as.Date("2000-01-01"), msg = "RcppResultSet.RcppDate")
}

test.RcppResultSet.RcppDateVector <- function() {
    src <- 'RcppDateVector y(x);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="ANY"), src)
    v <- c(as.Date("2000-01-01"), as.Date("2001-01-01"))
    checkEquals(funx(v)[[1]], v, msg = "RcppResultSet.RcppDateVector")
}

test.RcppResultSet.RcppDatetime <- function() {
     src <- 'RcppDatetime y(x);
             RcppResultSet rs;
             rs.add("foo", y);
  	     return rs.getReturnList();';
     funx <- cppfunction(signature(x="numeric"), src)
     # setting tz = "UTC" because otherwise the format gets set as the tz
     posixt <- as.POSIXct("2000-01-01 01:02:03.456", "%Y-%m-%d %H:%M:%OS", tz = "UTC" )
     result <- funx(as.numeric(posixt))[[1]]
     # RcppDateTime discards the timezone, so we have to set it back 
     # otherwise the comparison fails on the attributes
     attr( result, "tzone") <- "UTC" 
     checkEquals( result, posixt, msg = "RcppResultSet.RcppDatetime")
}

test.RcppResultSet.RcppDatetimeVector <- function() {
    src <- 'RcppDatetimeVector y(x);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="ANY"), src)
    now <- Sys.time()
    attr(now, "tzone") <- NULL # no attribute gets set at the C++ level
    v <- now + 0:9
    checkEquals(funx(v)[[1]], v, msg = "RcppResultSet.RcppDatetimeVector")
}

test.RcppResultSet.RcppStringVector <- function() {
    src <- 'RcppStringVector y(x);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="ANY"), src)
    v <- c("hello", "goodbye")
    checkEquals(funx(v)[[1]], v, msg = "RcppResultSet.RcppStringVector")
}

test.RcppResultSet.std.vector.double <- function() {
    src <- 'std::vector<double> y;
            y.push_back(1.1);
            y.push_back(2.2);
            y.push_back(3.3);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], c(1.1, 2.2, 3.3), msg = "RcppResultSet.std.vector.double")
}

test.RcppResultSet.std.vector.int <- function() {
    src <- 'std::vector<int> y;
            y.push_back(11);
            y.push_back(22);
            y.push_back(33);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], c(11, 22, 33), msg = "RcppResultSet.std.vector.int")
}

test.RcppResultSet.std.vector.std.vector.double <- function() {
    src <- 'std::vector<double> yy;
            yy.push_back(1.1);
            yy.push_back(2.2);
            yy.push_back(3.3);
            std::vector< std::vector<double> > y;
            y.push_back(yy);
            y.push_back(yy);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], matrix(c(1.1, 2.2, 3.3, 1.1, 2.2, 3.3), nrow=2, ncol=3, byrow=TRUE), msg = "RcppResultSet.std.vector.std.vector.double")
}

test.RcppResultSet.std.vector.std.vector.int <- function() {
    src <- 'std::vector<int> yy;
            yy.push_back(11);
            yy.push_back(22);
            yy.push_back(33);
            std::vector< std::vector<int> > y;
            y.push_back(yy);
            y.push_back(yy);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], matrix(c(11, 22, 33, 11, 22, 33), nrow=2, ncol=3, byrow=TRUE), msg = "RcppResultSet.std.vector.std.vector.int")
}

test.RcppResultSet.std.vector.std.vector.int <- function() {
    src <- 'std::string a("hello");
            std::string b("goodbye");
            std::vector< std::string > y;
            y.push_back(a);
            y.push_back(b);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(), src)
    checkEquals(funx()[[1]], c("hello", "goodbye"), msg = "RcppResultSet.std.vector.std.string")
}

test.RcppResultSet.RcppVector.int <- function() {
    src <- 'RcppVector<int> y(x);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="integer"), src)
    x <- c(11,22,33)
    checkEquals(funx(x)[[1]], x, msg = "RcppResultSet.RcppVector.int")
}

test.RcppResultSet.RcppVector.double <- function() {
    src <- 'RcppVector<double> y(x);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="double"), src)
    x <- c(1.1,2.2,3.3)
    checkEquals(funx(x)[[1]], x, msg = "RcppResultSet.RcppVector.double")
}

test.RcppResultSet.RcppMatrix.int <- function() {
    src <- 'RcppMatrix<int> y(x);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="integer"), src)
    x <- matrix(1:9, 3, 3)
    checkEquals(funx(x)[[1]], x, msg = "RcppResultSet.RcppMatrix.int")
}

test.RcppResultSet.RcppMatrix.double <- function() {
    src <- 'RcppMatrix<double> y(x);
            RcppResultSet rs;
            rs.add("foo", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="double"), src)
    x <- matrix(1.1*c(1:9), 3, 3)
    checkEquals(funx(x)[[1]], x, msg = "RcppResultSet.RcppMatrix.double")
}

test.RcppResultSet.RcppFrame <- function() {
    src <- 'RcppFrame y(x);
            RcppResultSet rs;
            rs.add("", y);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="ANY"), src)
    x <- data.frame(x=1:9, y=LETTERS[1:9], z=sample(c(TRUE,FALSE), 9, replace=TRUE))
    checkEquals( as.data.frame(funx(x)[[1]]), x, msg = "RcppResultSet.RcppFrame")
}

test.RcppResultSet.SEXP <- function() {
    src <- 'RcppResultSet rs;
            rs.add("", x, false);
	    return rs.getReturnList();';
    funx <- cppfunction(signature(x="ANY"), src)
    x <- list(foo=1.23, bar=123, glim="glom")
    checkEquals( funx(x)[[1]], x, msg = "RcppResultSet.SEXP")
}

