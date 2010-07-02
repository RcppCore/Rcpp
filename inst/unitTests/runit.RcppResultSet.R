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

.setUp <- function() {
    if( ! exists( ".rcpp.RcppResultSet", globalenv() )) {
        ## definition of all the functions at once
        f <- list("double_"=list(
                  signature(),
                  'double y = 1.23456;
                   RcppResultSet rs;
                   rs.add("foo", y);
	               return rs.getReturnList();'),

                  "int_"=list(
                  signature(),
                  'int y = 42;
                   RcppResultSet rs;
                   rs.add("foo", y);
	               return rs.getReturnList();'),

                  "string_"=list(
                  signature(),
                  'std::string y = "hello unit tests";
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "double_vector"=list(
                  signature(),
                  'double y[3] = { 1.1, 2.2, 3.3 };
                  RcppResultSet rs;
                  rs.add("foo", y, 3);
	              return rs.getReturnList();'),

                  "int_vector"=list(
                  signature(),
                  'int y[3] = { 11, 22, 33 };
                  RcppResultSet rs;
                  rs.add("foo", y, 3);
	              return rs.getReturnList();'),

                  "double_matrix"=list(
                  signature(),
                  'double r1[2] = { 1.1, 2.2 };
                  double r2[2] = { 3.3, 4.4 };
                  double *y[2] = { r1, r2 };
                  RcppResultSet rs;
                  rs.add("foo", y, 2, 2);
	              return rs.getReturnList();'),

                  "int_matrix"=list(
                  signature(),
                  'int r1[2] = { 11, 22 };
                  int r2[2] = { 33, 44 };
                  int *y[2] = { r1, r2 };
                  RcppResultSet rs;
                  rs.add("foo", y, 2, 2);
	              return rs.getReturnList();'),

                  "RcppDate_"=list(
                  signature(),
                  'RcppDate y(01,01,2000); // silly North American mon-day-year
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "RcppDateVector_"=list(
                  signature(x="any"),
                  'RcppDateVector y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "RcppDatetime_"=list(
                  signature(x="any"),
                  'RcppDatetime y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
  	              return rs.getReturnList();'),

                  "RcppDatetimeVector_"=list(
                  signature(x="POSIXct"),
                  'RcppDatetimeVector y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "RcppStringVector_"=list(
                  signature(x="character"),
                  'RcppStringVector y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "std_vector_double"=list(
                  signature(),
                  'std::vector<double> y;
                  y.push_back(1.1);
                  y.push_back(2.2);
                  y.push_back(3.3);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "std_vector_int"=list(
                  signature(),
                  'std::vector<int> y;
                  y.push_back(11);
                  y.push_back(22);
                  y.push_back(33);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "std_vector_std_vector_double"=list(
                  signature(),
                  'std::vector<double> yy;
                  yy.push_back(1.1);
                  yy.push_back(2.2);
                  yy.push_back(3.3);
                  std::vector< std::vector<double> > y;
                  y.push_back(yy);
                  y.push_back(yy);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "std_vector_std_vector_int"=list(
                  signature(),
                  'std::vector<int> yy;
                  yy.push_back(11);
                  yy.push_back(22);
                  yy.push_back(33);
                  std::vector< std::vector<int> > y;
                  y.push_back(yy);
                  y.push_back(yy);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "std_vector_std_vector_string"=list(
                  signature(),
                  'std::string a("hello");
                  std::string b("goodbye");
                  std::vector< std::string > y;
                  y.push_back(a);
                  y.push_back(b);
                  RcppResultSet rs;
                  rs.add("foo", y);
        	      return rs.getReturnList();'),

                  "RcppVector_int"=list(
                  signature(x="integer"),
                  'RcppVector<int> y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "RcppVector_double"=list(
                  signature(x="double"),
                  'RcppVector<double> y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "RcppMatrix_int"=list(
                  signature(x="integer"),
                  'RcppMatrix<int> y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "RcppMatrix_double"=list(
                  signature(x="double"),
                  'RcppMatrix<double> y(x);
                  RcppResultSet rs;
                  rs.add("foo", y);
	              return rs.getReturnList();'),

                  "RcppFrame_"=list(
                  signature(x="any"),
                  'RcppFrame y(x);
                  RcppResultSet rs;
                  rs.add("", y);
	              return rs.getReturnList();'),

                  "SEXP_"=list(
                  signature(x="any"),
                  'RcppResultSet rs;
                  rs.add("", x, false);
	              return rs.getReturnList();')

                  )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction( signatures, bodies, plugin = "Rcpp")
        getDynLib( fun ) # just forcing loading the dll now
        assign( ".rcpp.RcppResultSet", fun, globalenv() )
    }
}

test.RcppResultSet.double <- function() {
    fun <- .rcpp.RcppResultSet$double_
    checkEquals(fun()[[1]], 1.23456, msg = "RcppResultRet.double")
}

test.RcppResultSet.int <- function() {
    fun <- .rcpp.RcppResultSet$int_
    checkEquals(fun()[[1]], 42, msg = "RcppResultSet.int")
}

test.RcppResultSet.string <- function() {
    fun <- .rcpp.RcppResultSet$string_
    checkEquals(fun()[[1]], "hello unit tests", msg = "RcppResultSet.string")
}

test.RcppResultSet.double.vector <- function() {
    fun <- .rcpp.RcppResultSet$double_vector
    checkEquals(fun()[[1]], c(1.1, 2.2, 3.3), msg = "RcppResultSet.double.vector")
}

test.RcppResultSet.int.vector <- function() {
    fun <- .rcpp.RcppResultSet$int_vector
    checkEquals(fun()[[1]], c(11, 22, 33), msg = "RcppResultSet.int.vector")
}

test.RcppResultSet.double.matrix <- function() {
    fun <- .rcpp.RcppResultSet$double_matrix
    checkEquals(fun()[[1]], matrix(c(1.1, 2.2, 3.3, 4.4), 2, byrow=TRUE), msg = "RcppResultSet.double.matrix")
}

test.RcppResultSet.int.matrix <- function() {
    fun <- .rcpp.RcppResultSet$int_matrix
    checkEquals(fun()[[1]], matrix(c(11, 22, 33, 44), 2, byrow=TRUE), msg = "RcppResultSet.int.matrix")
}

test.RcppResultSet.RcppDate <- function() {
    fun <- .rcpp.RcppResultSet$RcppDate_
    checkEquals(fun()[[1]], as.Date("2000-01-01"), msg = "RcppResultSet.RcppDate")
}

test.RcppResultSet.RcppDateVector <- function() {
    fun <- .rcpp.RcppResultSet$RcppDateVector_
    v <- c(as.Date("2000-01-01"), as.Date("2001-01-01"))
    checkEquals(fun(v)[[1]], v, msg = "RcppResultSet.RcppDateVector")
}

test.RcppResultSet.RcppDatetime <- function() {
    fun <- .rcpp.RcppResultSet$RcppDatetime_
    ## setting tz = "UTC" because otherwise the format gets set as the tz
    posixt <- as.POSIXct("2000-01-01 01:02:03.456", "%Y-%m-%d %H:%M:%OS", tz = "UTC" )
    result <- fun(as.numeric(posixt))[[1]]
    ## RcppDateTime discards the timezone, so we have to set it back
    ## otherwise the comparison fails on the attributes
    attr( result, "tzone") <- "UTC"
    checkTrue( (result - posixt) == 0.0 , msg = "RcppResultSet.RcppDatetime")
}

test.RcppResultSet.RcppDatetimeVector <- function() {
    fun <- .rcpp.RcppResultSet$RcppDatetimeVector_
    now <- Sys.time()
    attr(now, "tzone") <- NULL # no attribute gets set at the C++ level
    v <- now + 0:9
    checkTrue( sum( fun(v)[[1]] - v ) == 0.0 , msg = "RcppResultSet.RcppDatetimeVector")
}

test.RcppResultSet.RcppStringVector <- function() {
    fun <- .rcpp.RcppResultSet$RcppStringVector_
    v <- c("hello", "goodbye")
    checkEquals(fun(v)[[1]], v, msg = "RcppResultSet.RcppStringVector")
}

test.RcppResultSet.std.vector.double <- function() {
    fun <- .rcpp.RcppResultSet$std_vector_double
    checkEquals(fun()[[1]], c(1.1, 2.2, 3.3), msg = "RcppResultSet.std.vector.double")
}

test.RcppResultSet.std.vector.int <- function() {
    fun <- .rcpp.RcppResultSet$std_vector_int
    checkEquals(fun()[[1]], c(11, 22, 33), msg = "RcppResultSet.std.vector.int")
}

test.RcppResultSet.std.vector.std.vector.double <- function() {
    fun <- .rcpp.RcppResultSet$std_vector_std_vector_double
    checkEquals(fun()[[1]], matrix(c(1.1, 2.2, 3.3, 1.1, 2.2, 3.3), nrow=2, ncol=3, byrow=TRUE), msg = "RcppResultSet.std.vector.std.vector.double")
}

test.RcppResultSet.std.vector.std.vector.int <- function() {
    fun <- .rcpp.RcppResultSet$std_vector_std_vector_int
    checkEquals(fun()[[1]], matrix(c(11, 22, 33, 11, 22, 33), nrow=2, ncol=3, byrow=TRUE), msg = "RcppResultSet.std.vector.std.vector.int")
}

test.RcppResultSet.std.vector.std.vector.string <- function() {
    fun <- .rcpp.RcppResultSet$std_vector_std_vector_string
    checkEquals(fun()[[1]], c("hello", "goodbye"), msg = "RcppResultSet.std.vector.std.string")
}

test.RcppResultSet.RcppVector.int <- function() {
    fun <- .rcpp.RcppResultSet$RcppVector_int
    x <- c(11,22,33)
    checkEquals(fun(x)[[1]], x, msg = "RcppResultSet.RcppVector.int")
}

test.RcppResultSet.RcppVector.double <- function() {
    fun <- .rcpp.RcppResultSet$RcppVector_double
    x <- c(1.1,2.2,3.3)
    checkEquals(fun(x)[[1]], x, msg = "RcppResultSet.RcppVector.double")
}

test.RcppResultSet.RcppMatrix.int <- function() {
    fun <- .rcpp.RcppResultSet$RcppMatrix_int
    x <- matrix(1:9, 3, 3)
    checkEquals(fun(x)[[1]], x, msg = "RcppResultSet.RcppMatrix.int")
}

test.RcppResultSet.RcppMatrix.double <- function() {
    fun <- .rcpp.RcppResultSet$RcppMatrix_double
    x <- matrix(1.1*c(1:9), 3, 3)
    checkEquals(fun(x)[[1]], x, msg = "RcppResultSet.RcppMatrix.double")
}

test.RcppResultSet.RcppFrame <- function() {
    fun <- .rcpp.RcppResultSet$RcppFrame_
    x <- data.frame(x=1:9, y=LETTERS[1:9], z=sample(c(TRUE,FALSE), 9, replace=TRUE))
    checkEquals( as.data.frame(fun(x)[[1]]), x, msg = "RcppResultSet.RcppFrame")
}

test.RcppResultSet.SEXP <- function() {
    fun <- .rcpp.RcppResultSet$SEXP_
    x <- list(foo=1.23, bar=123, glim="glom")
    checkEquals( fun(x)[[1]], x, msg = "RcppResultSet.SEXP")
}

