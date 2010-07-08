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
    if( ! exists( ".rcpp.RcppDate", globalenv() )) {
        ## definition of all the functions at once
        functions <- list("get_functions"=list(
                          signature(),
                          'RcppDate dt = RcppDate(12,31,1999);
                           RcppResultSet rs;
                           rs.add("month", dt.getMonth());
                           rs.add("day",   dt.getDay());
                           rs.add("year",  dt.getYear());
                           rs.add("julian",dt.getJulian());
                           return rs.getReturnList();')

                          ,"operators"=list(
                           signature(),
                          'RcppDate d1 = RcppDate(12,31,1999);
                           RcppDate d2 = d1 + 1;
                           RcppResultSet rs;
                           rs.add("diff",    d2 - d1);
                           rs.add("bigger",  d2 > d1);
                           rs.add("smaller", d2 < d1);
                           rs.add("equal",   d2 == d1);
                           rs.add("ge",      d2 >= d1);
                           rs.add("le",      d2 <= d1);
                           return rs.getReturnList();')

                          ,"wrap"=list(
                           signature(),
                          'RcppDate dt = RcppDate(12,31,1999);
                           return wrap(dt);')

                          ,"RcppDatetime_functions"=list(
                           signature(x="numeric"),
                           'RcppDatetime dt = RcppDatetime(x);
				            RcppResultSet rs;
				            rs.add("year",     dt.getYear());
				            rs.add("month",    dt.getMonth());
				            rs.add("day",      dt.getDay());
				            rs.add("wday",     dt.getWeekday());
				            rs.add("hour",     dt.getHour());
				            rs.add("minute",   dt.getMinute());
				            rs.add("second",   dt.getSecond());
				            rs.add("microsec", dt.getMicroSec());
				            return rs.getReturnList();')

                          ,"RcppDatetime_operators"=list(
                           signature(x="numeric"),
                           'RcppDatetime d1 = RcppDatetime(946774923.123456);
				            //RcppDatetime d1 = RcppDatetime(1152338523.456789);
							// as.POSIXct("2006-07-08 01:02:03.456789")
				            RcppDatetime d2 = d1 + 60*60;
				            RcppResultSet rs;
        	    	        rs.add("diff",    d2 - d1);
	            	        rs.add("bigger",  d2 > d1);
		                    rs.add("smaller", d2 < d1);
		                    rs.add("equal",   d2 == d1);
	    	                rs.add("ge",      d2 >= d1);
	        	            rs.add("le",      d2 <= d1);
	            		    return rs.getReturnList();')

                           ,"RcppDatetime_wrap"=list(
                            signature(),
                            'RcppDatetime dt = RcppDatetime(981162123.123456);
			    		     return wrap(dt);')

                          )

        signatures <- lapply(functions, "[[", 1L)
        bodies <- lapply(functions, "[[", 2L)
        fun <- cxxfunction( signatures, bodies, plugin = "Rcpp")
        getDynLib( fun ) # just forcing loading the dll now
        assign( ".rcpp.RcppDate", fun, globalenv() )
        Sys.setenv("TZ"="UTC")          # to ensure localtime is GMT
    }
}

test.RcppDate.get.functions <- function() {
    fun <- .rcpp.RcppDate$get_functions
    checkEquals(fun(), list(month=12, day=31, year=1999, julian=10956), msg = "RcppDate.get.functions")
}

test.RcppDate.operators <- function() {
    fun <- .rcpp.RcppDate$operators
    checkEquals(fun(), list(diff=1, bigger=TRUE, smaller=FALSE, equal=FALSE, ge=TRUE, le=FALSE),
                msg = "RcppDate.operators")
}

test.RcppDate.wrap <- function() {
    fun <- .rcpp.RcppDate$wrap
    checkEquals(fun(), as.Date("1999-12-31"), msg = "RcppDate.wrap")
}

test.RcppDatetime.get.functions <- function() {
    fun <- .rcpp.RcppDate$RcppDatetime_functions
    ## checkEquals(fun(as.POSIXct("2001-02-03 01:02:03.123456", tz="UTC")),
    checkEquals(fun(981162123.123456),
                list(year=2001, month=2, day=3, wday=6, hour=1, minute=2, second=3, microsec=123456),
                msg = "RcppDate.get.functions")
}

test.RcppDatetime.operators <- function() {
    fun <- .rcpp.RcppDate$RcppDatetime_operators
    checkEquals(fun(as.numeric(as.POSIXct("2001-02-03 01:02:03.123456", tz="UTC"))),
                list(diff=3600, bigger=TRUE, smaller=FALSE, equal=FALSE, ge=TRUE, le=FALSE),
                msg = "RcppDatetime.operators")
}

test.RcppDatetime.wrap <- function() {
    fun <- .rcpp.RcppDate$RcppDatetime_wrap
    checkEquals(as.numeric(fun()), as.numeric(as.POSIXct("2001-02-03 01:02:03.123456", tz="UTC")),
                msg = "RcppDatetime.wrap")
}
