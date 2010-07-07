#!/usr/bin/r -t
# -*- mode: R; tab-width: 4 -*-
#
# Copyright (C) 2010    Dirk Eddelbuettel and Romain Francois
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

    tests <- ".Rcpp.Date"
    if( ! exists(tests, globalenv() )) {

        ## definition of all the functions at once
        f <- list("ctor_sexp"=list(
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

                  ,"operator_sexp"=list(
                   signature(),
                   'DateVector v(2) ;
                    v[0] = Date(2005,12,31) ;
                    v[1] = Date(12,31,2005) ;
                    return wrap( v );')

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

                  )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction( signatures, bodies, plugin = "Rcpp")
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
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
    fun <- .Rcpp.Date$operator_sexp
    checkEquals(fun(), rep(as.Date("2005-12-31"),2), msg = "DateVector.SEXP")
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
