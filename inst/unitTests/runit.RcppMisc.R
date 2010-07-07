#!/usr/bin/r -t
# -*- mode: R; tab-width: 4 -*-
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

    tests <- ".Rcpp.RcppMisc"
    if ( ! exists(tests, globalenv() )) {

        ## definition of all the functions at once
        f <- list("RcppFrame_"=list(
                  signature(),
                 'std::vector<std::string> names;
		          names.push_back("A");
                  names.push_back("B");
                  names.push_back("C");
                  RcppFrame fr(names);

                  std::vector<ColDatum> colDatumVector(3);
                  colDatumVector[0].setDoubleValue(1.23);
                  colDatumVector[1].setIntValue(42);
                  colDatumVector[2].setLogicalValue(0);
                  fr.addRow(colDatumVector);

                  colDatumVector[0].setDoubleValue(4.56);
                  colDatumVector[1].setIntValue(21);
                  colDatumVector[2].setLogicalValue(1);
                  fr.addRow(colDatumVector);

                  RcppResultSet rs;
                  rs.add("data.frame", fr);
	              return rs.getReturnList();')

                  ,"RcppList_"=list(
                   signature(),
                   'RcppList l;
		            l.setSize(3);
                    l.append("foo", 1);
                    l.append("bar", 2.0);
                    l.append("biz", "xyz");
                    return l.getList();')

                  ,"RcppParams_Double"=list(
                  signature(x="ANY"),
                  'double y = 2 * RcppParams(x).getDoubleValue("val");
				   return Rcpp::wrap(y);')

                  ,"RcppParams_Int"=list(
                  signature(x="ANY"),
                  'int y = 2 * RcppParams(x).getIntValue("val");
			       return Rcpp::wrap(y);')

                  ,"RcppParams_String"=list(
                  signature(x="ANY"),
                  'std::string y = RcppParams(x).getStringValue("val");
                   y = y + y; // trivial string operation
	               return Rcpp::wrap(y);')

                  ,"RcppParams_Bool"=list(
                  signature(x="ANY"),
                  'bool y = RcppParams(x).getBoolValue("val");
	    		   return Rcpp::wrap(y);')

                  ,"RcppParams_Date"=list(
                  signature(x="ANY"),
                  'RcppDate y = RcppParams(x).getDateValue("val");
            	   RcppResultSet rs;
            	   rs.add("date", y);
	    		   return rs.getReturnList();')

                  ,"RcppParams_Datetime"=list(
                  signature(x="ANY"),
                  'RcppDatetime y = RcppParams(x).getDatetimeValue("val");
                   RcppResultSet rs;
                   rs.add("datetime", y);
	               return rs.getReturnList();')

                  )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction( signatures, bodies, plugin = "Rcpp")
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.RcppFrame <- function() {
    fun <- .Rcpp.RcppMisc$RcppFrame_
    dframe <- data.frame(fun()[[1]]) ## needs a data.frame() call on first list elem
    checkEquals(dframe, data.frame(A=c(1.23,4.56), B=c(42,21), C=c(FALSE,TRUE)), msg = "RcppFrame")
}

test.RcppList <- function() {
    fun <- .Rcpp.RcppMisc$RcppList_
    checkEquals(fun(), list(foo=1L, bar=2, biz="xyz"), msg="RcppList")
}

test.RcppParams.Double <- function() {
    fun <- .Rcpp.RcppMisc$RcppParams_Double
    checkEquals(fun(list(val=1.234)), 2*1.234, msg="RcppParams.getDoubleValue")
}

test.RcppParams.Int <- function() {
    fun <- .Rcpp.RcppMisc$RcppParams_Int
    checkEquals(fun(list(val=42)), 2*42, msg="RcppParams.getIntValue")
}

test.RcppParams.String <- function() {
    fun <- .Rcpp.RcppMisc$RcppParams_String
    checkEquals(fun(list(val="a test string")), "a test stringa test string", msg = "RcppParams.getStringValue")
}

test.RcppParams.Bool <- function() {
    fun <- .Rcpp.RcppMisc$RcppParams_Bool
    checkEquals(fun(list(val=FALSE)), FALSE, msg = "RcppParams.getBoolValue")
}

test.RcppParams.Date <- function() {
    fun <- .Rcpp.RcppMisc$RcppParams_Date
    checkEquals(fun(list(val=as.Date("2000-01-01")))[[1]], as.Date("2000-01-01"), msg = "RcppParams.getDateValue")
}

test.RcppParams.Datetime <- function() {
    fun <- .Rcpp.RcppMisc$RcppParams_Datetime
    posixt <- as.POSIXct(strptime("2000-01-02 03:04:05.678", "%Y-%m-%d %H:%M:%OS"))
    attr(posixt, "tzone") <- NULL    ## because we don't set a tzone attribute in C++
    result <- fun(list(val=posixt))[[1]]
    checkTrue( (result-posixt) == 0.0 , msg = "RcppParams.getDatetimeValue")
}
