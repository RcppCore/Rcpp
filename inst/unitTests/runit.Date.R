#!/usr/bin/r -t
# -*- mode: R; tab-width: 4 -*-
#
# Copyright (C) 2010, 2012   Dirk Eddelbuettel and Romain Francois
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

definitions <- function() {
    list(          "ctor_sexp"=list(
                   signature(d="Date"),
                   'Date dt = Date(d);
                   return wrap(dt);')

                  ,"ctor_mdy"=list(
                   signature(),
                   'Date dt = Date(12,31,2005);
                   return wrap(dt);')

                  ,"ctor_ymd"=list(
                   signature(),
                   'Date dt = Date(2005,12,31);
                    return wrap(dt);')

                  ,"ctor_int"=list(
                   signature(d="numeric"),
                   'Date dt = Date(Rcpp::as<int>(d));
                    return wrap(dt);')

                  ,"ctor_string"=list(
                   signature(x="date"),
                   'std::string dtstr = Rcpp::as<std::string>(x);
                    Date dt(dtstr);
				    return wrap(dt);')

                   ,"operators"=list(
                    signature(),
                    'Date d1 = Date(2005,12,31);
                    Date d2 = d1 + 1;
                    return List::create(Named("diff") = d2 - d1,
                                        Named("bigger") = d2 > d1,
                                        Named("smaller") = d2 < d1,
                                        Named("equal") = d2 == d1,
                                        Named("ge") = d2 >= d1,
                                        Named("le") = d2 <= d1,
                                        Named("ne") = d2 != d1);')

                  ,"components"=list(
                   signature(),
                   'Date d = Date(2005,12,31);
                    return List::create(Named("day") = d.getDay(),
                                        Named("month") = d.getMonth(),
                                        Named("year") = d.getYear(),
                                        Named("weekday") = d.getWeekday(),
                                        Named("yearday") = d.getYearday());')

                  ,"vector_Date"=list(
                   signature(),
                   'std::vector<Date> v(2) ;
                    v[0] = Date(2005,12,31) ;
                    v[1] = Date(12,31,2005) ;
                    return wrap( v );')

                  ,"Datevector_wrap"=list(
                   signature(),
                   'DateVector v(2) ;
                    v[0] = Date(2005,12,31) ;
                    v[1] = Date(12,31,2005) ;
                    return wrap( v );')

                  ,"Datevector_sexp"=list(
                   signature(),
                   'DateVector v(2) ;
                    v[0] = Date(2005,12,31) ;
                    v[1] = Date(12,31,2005) ;
                    return wrap( v );')

                  ,"Date_get_functions"=list(
                   signature(x="Date"),
                   'Date d = Date(x);
		            return List::create(Named("year") = d.getYear(),
    		                            Named("month") = d.getMonth(),
    		                            Named("day") = d.getDay(),
    		                            Named("wday") = d.getWeekday(),
    		                            Named("yday") = d.getYearday());')

                  ,"Datetime_get_functions"=list(
                   signature(x="Datetime"),
                   'Datetime dt = Datetime(x);
		            return List::create(Named("year") = dt.getYear(),
    		                            Named("month") = dt.getMonth(),
    		                            Named("day") = dt.getDay(),
    		                            Named("wday") = dt.getWeekday(),
    		                            Named("hour") = dt.getHours(),
    		                            Named("minute") = dt.getMinutes(),
    		                            Named("second") = dt.getSeconds(),
    		                            Named("microsec") = dt.getMicroSeconds());')

                  ,"Datetime_operators"=list(
                   signature(),
                   'Datetime d1 = Datetime(946774923.123456);
		            Datetime d2 = d1 + 60*60;
		            return List::create(Named("diff") = d2 - d1,
		                                Named("bigger") = d2 > d1,
		                                Named("smaller") = d2 < d1,
		                                Named("equal") = d2 == d1,
		                                Named("ge") = d2 >= d1,
		                                Named("le") = d2 <= d1,
		                                Named("ne") = d2 != d1);')

                  ,"Datetime_wrap"=list(
                   signature(),
                   'Datetime dt = Datetime(981162123.123456);
				    return wrap(dt);')

                  ,"Datetime_from_string"=list(
                   signature(x="datetime"),
                   'std::string dtstr = Rcpp::as<std::string>(x);
                    Datetime dt(dtstr);
				    return wrap(dt);')

                  ,"Datetime_ctor_sexp"=list(
                   signature(d="Datetime"),
                   'Datetime dt = Datetime(d);
                   return wrap(dt);')

                  ,"DatetimeVector_ctor"=list(
                   signature(d="DatetimeVector"),
                   'DatetimeVector dt = DatetimeVector(d);
                   return wrap(dt);')

                  )
}

.setUp <- function() {
    tests <- ".Rcpp.Date"
    if( ! exists(tests, globalenv() )) {
        fun <- Rcpp:::compile_unit_tests(definitions() )
        assign( tests, fun , globalenv() )
    }
}


test.Date.ctor.sexp <- function() {
    fun <- .Rcpp.Date$ctor_sexp
    d <- as.Date("2005-12-31"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.1")
    d <- as.Date("1970-01-01"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.2")
    d <- as.Date("1969-12-31"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.3")
    d <- as.Date("1954-07-04"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.4") # cf 'Miracle of Berne' ;-)
    d <- as.Date("1789-07-14"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.5") # cf 'Quatorze Juillet' ;-)
}

test.Date.ctor.notFinite <- function() {
    fun <- .Rcpp.Date$ctor_sexp
    checkEquals(fun(NA),  as.Date(NA,  origin="1970-01-01"), msg = "Date.ctor.na")
    checkEquals(fun(NaN), as.Date(NaN, origin="1970-01-01"), msg = "Date.ctor.nan")
    checkEquals(fun(Inf), as.Date(Inf, origin="1970-01-01"), msg = "Date.ctor.inf")
}

test.Date.ctor.diffs <- function() {
    fun <- .Rcpp.Date$ctor_sexp
    now <- Sys.Date()
    checkEquals(as.numeric(difftime(fun(now+0.025),  fun(now), units="days")), 0.025, msg = "Date.ctor.diff.0025")
    checkEquals(as.numeric(difftime(fun(now+0.250),  fun(now), units="days")), 0.250, msg = "Date.ctor.diff.0250")
    checkEquals(as.numeric(difftime(fun(now+2.500),  fun(now), units="days")), 2.500, msg = "Date.ctor.diff.2500")
}

test.Date.ctor.mdy <- function() {
    fun <- .Rcpp.Date$ctor_mdy
    checkEquals(fun(), as.Date("2005-12-31"), msg = "Date.ctor.mdy")
}

test.Date.ctor.ymd <- function() {
    fun <- .Rcpp.Date$ctor_ymd
    checkEquals(fun(), as.Date("2005-12-31"), msg = "Date.ctor.ymd")
}

test.Date.ctor.int <- function() {
    fun <- .Rcpp.Date$ctor_int
    d <- as.Date("2005-12-31")
    checkEquals(fun(as.numeric(d)), d, msg = "Date.ctor.int")
    checkEquals(fun(-1), as.Date("1970-01-01")-1, msg = "Date.ctor.int")
    checkException(fun("foo"), msg = "Date.ctor -> exception" )
}

test.Date.ctor.string <- function() {
    fun <- .Rcpp.Date$ctor_string
    dtstr <- "1991-02-03"
    dtfun <- fun(dtstr)
    dtstr <- as.Date(strptime(dtstr, "%Y-%m-%d"))
    ddstr <- as.Date(dtstr, "%Y-%m-%d")
    checkEquals(dtfun, dtstr, msg = "Date.fromString.strptime")
    checkEquals(dtfun, ddstr, msg = "Date.fromString.asDate")
}

test.Date.operators <- function() {
    fun <- .Rcpp.Date$operators
    checkEquals(fun(),
                list(diff=-1, bigger=TRUE, smaller=FALSE, equal=FALSE, ge=TRUE, le=FALSE, ne=TRUE),
                msg = "Date.operators")
}

test.Date.components <- function() {
    fun <- .Rcpp.Date$components
    checkEquals(fun(),
                list(day=31, month=12, year=2005, weekday=7, yearday=365),
                msg = "Date.components")
}

test.vector.Date <- function(){
    fun <- .Rcpp.Date$vector_Date
    checkEquals(fun(), rep(as.Date("2005-12-31"),2), msg = "Date.vector.wrap")
}

test.DateVector.wrap <- function(){
    fun <- .Rcpp.Date$Datevector_wrap
    checkEquals(fun(), rep(as.Date("2005-12-31"),2), msg = "DateVector.wrap")
}

test.DateVector.operator.SEXP <- function(){
    fun <- .Rcpp.Date$Datevector_sexp
    checkEquals(fun(), rep(as.Date("2005-12-31"),2), msg = "DateVector.SEXP")
}

test.Date.getFunctions <- function(){
    fun <- .Rcpp.Date$Date_get_functions
    checkEquals(fun(as.Date("2010-12-04")),
                list(year=2010, month=12, day=4, wday=7, yday=338), msg = "Date.get.functions.1")
    checkEquals(fun(as.Date("2010-01-01")),
                list(year=2010, month=1, day=1, wday=6, yday=1), msg = "Date.get.functions.2")
    checkEquals(fun(as.Date("2009-12-31")),
                list(year=2009, month=12, day=31, wday=5, yday=365), msg = "Date.get.functions.3")
}

test.Datetime.get.functions <- function() {
    fun <- .Rcpp.Date$Datetime_get_functions
    checkEquals(fun(as.numeric(as.POSIXct("2001-02-03 01:02:03.123456", tz="UTC"))),
                list(year=2001, month=2, day=3, wday=7, hour=1, minute=2, second=3, microsec=123456),
                msg = "Datetime.get.functions")
}

test.Datetime.operators <- function() {
    fun <- .Rcpp.Date$Datetime_operators
    checkEquals(fun(),
                list(diff=-60*60, bigger=TRUE, smaller=FALSE, equal=FALSE, ge=TRUE, le=FALSE, ne=TRUE),
                msg = "Datetime.operators")
}

test.Datetime.wrap <- function() {
    fun <- .Rcpp.Date$Datetime_wrap
    checkEquals(as.numeric(fun()), as.numeric(as.POSIXct("2001-02-03 01:02:03.123456", tz="UTC")),
                msg = "Datetime.wrap")
}

test.Datetime.fromString <- function() {
    fun <- .Rcpp.Date$Datetime_from_string
    dtstr <- "1991-02-03 04:05:06.789"
    dtfun <- fun(dtstr)
    dtstr <- as.POSIXct(strptime(dtstr, "%Y-%m-%d %H:%M:%OS"))
    checkEquals(as.numeric(dtfun), as.numeric(dtstr), msg = "Datetime.fromString")
}

# TZ difference ...
#test.Datetime.ctor <- function() {
#    fun <- .Rcpp.Date$Datetime_ctor_sexp
#    checkEquals(fun(1234567),  as.POSIXct(1234567,  origin="1970-01-01"), msg = "Datetime.ctor.1")
#    checkEquals(fun(-120.25),  as.POSIXct(-120.5,   origin="1970-01-01"), msg = "Datetime.ctor.2")
#    checkEquals(fun( 120.25),  as.POSIXct( 120.25,  origin="1970-01-01"), msg = "Datetime.ctor.3")
#}

test.Datetime.ctor.notFinite <- function() {
    fun <- .Rcpp.Date$Datetime_ctor_sexp
    posixtNA <- as.POSIXct(NA,  origin="1970-01-01")
    checkEquals(fun(NA),  posixtNA, msg = "Datetime.ctor.na")
    checkEquals(fun(NaN), posixtNA, msg = "Datetime.ctor.nan")
    checkEquals(fun(Inf), posixtNA, msg = "Datetime.ctor.inf")
}

test.Datetime.ctor.diffs <- function() {
    fun <- .Rcpp.Date$Datetime_ctor_sexp
    now <- Sys.time()
    ## first one is Ripley's fault as he decreed that difftime of POSIXct should stop at milliseconds
    checkEquals(round(as.numeric(difftime(fun(now+0.025),  fun(now), units="sec")), digits=4), 0.025, msg = "Datetime.ctor.diff.0025")
    checkEquals(as.numeric(difftime(fun(now+0.250),  fun(now), units="sec")), 0.250, msg = "Datetime.ctor.diff.0250")
    checkEquals(as.numeric(difftime(fun(now+2.500),  fun(now), units="sec")), 2.500, msg = "Datetime.ctor.diff.2500")
}

test.DatetimeVector.ctor <- function() {
    fun <- .Rcpp.Date$DatetimeVector_ctor
    now <- Sys.time()
    checkEquals(fun(now + (0:4)*60), now+(0:4)*60, msg = "Datetime.ctor.sequence")
    vec <- c(now, NA, NaN, Inf, now+2.345)
    posixtNA <- as.POSIXct(NA,  origin="1970-01-01")
    checkEquals(fun(vec), c(now, rep(posixtNA, 3), now+2.345), msg = "Datetime.ctor.set")
}
