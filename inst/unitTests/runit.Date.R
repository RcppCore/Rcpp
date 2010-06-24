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

test.Date.ctor.sexp <- function() {
    src <- 'Date dt = Date(d);
	    return wrap(dt);'
    fun <- cxxfunction(signature(d="Date"), src, plugin = "Rcpp" )
    d <- as.Date("2005-12-31"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.1")
    d <- as.Date("1970-01-01"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.2")
    d <- as.Date("1969-12-31"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.3")
    d <- as.Date("1954-07-04"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.4") # cf 'Miracle of Berne' ;-)
    d <- as.Date("1789-07-14"); checkEquals(fun(d), d, msg = "Date.ctor.sexp.5") # cf 'Quatorze Juillet' ;-)
}

test.Date.ctor.mdy <- function() {
    src <- 'Date dt = Date(12,31,2005);
	    return wrap(dt);'
    fun <- cxxfunction(signature(), src, plugin = "Rcpp" )
    checkEquals(fun(), as.Date("2005-12-31"), msg = "Date.ctor.mdy")
}

test.Date.ctor.ymd <- function() {
    src <- 'Date dt = Date(2005,12,31);
	    return wrap(dt);'
    fun <- cxxfunction(signature(), src, plugin = "Rcpp" )
    checkEquals(fun(), as.Date("2005-12-31"), msg = "Date.ctor.ymd")
}

test.Date.ctor.int <- function() {
    src <- 'Date dt = Date(Rcpp::as<int>(d));
	    return wrap(dt);'
    fun <- cxxfunction(signature(d="numeric"), src, plugin = "Rcpp")
    d <- as.Date("2005-12-31")
    checkEquals(fun(as.numeric(d)), d, msg = "Date.ctor.int")
    checkEquals(fun(-1), as.Date("1970-01-01")-1, msg = "Date.ctor.int")
    checkException(fun("foo"), msg = "Date.ctor -> exception" )
}

test.Date.operators <- function() {
    src <- 'Date d1 = Date(2005,12,31);
            Date d2 = d1 + 1;
            return List::create(Named("diff") = d2 - d1,
                                Named("bigger") = d2 > d1,
                                Named("smaller") = d2 < d1,
                                Named("equal") = d2 == d1,
                                Named("ge") = d2 >= d1,
                                Named("le") = d2 <= d1,
                                Named("ne") = d2 != d1);'
    fun <- cxxfunction(signature(), src, plugin="Rcpp")
    checkEquals(fun(),
                list(diff=-1, bigger=TRUE, smaller=FALSE, equal=FALSE, ge=TRUE, le=FALSE, ne=TRUE),
                msg = "Date.operators")
}

test.Date.components <- function() {
    src <- 'Date d = Date(2005,12,31);
            return List::create(Named("day") = d.getDay(),
                                Named("month") = d.getMonth(),
                                Named("year") = d.getYear(),
                                Named("weekday") = d.getWeekday(),
                                Named("yearday") = d.getYearday());'
    fun <- cxxfunction(signature(), src, plugin="Rcpp")
    checkEquals(fun(),
                list(day=31, month=12, year=2005, weekday=7, yearday=365),
                msg = "Date.components")
}

test.vector.Date <- function(){
	fx <- cxxfunction( , '
		std::vector<Date> v(2) ;
		v[0] = Date(2005,12,31) ;
		v[1] = Date(12,31,2005) ;
		return wrap( v ) ;
	', plugin = "Rcpp" )
    checkEquals(fx(), rep(as.Date("2005-12-31"),2), msg = "Date.vector.wrap")
}

test.DateVector.wrap <- function(){
	fx <- cxxfunction( , '
		DateVector v(2) ;
		v[0] = Date(2005,12,31) ;
		v[1] = Date(12,31,2005) ;
		return wrap( v ) ;
	', plugin = "Rcpp" )
    checkEquals(fx(), rep(as.Date("2005-12-31"),2), msg = "DateVector.wrap")
}

test.DateVector.operator.SEXP <- function(){
	fx <- cxxfunction( , '
		DateVector v(2) ;
		v[0] = Date(2005,12,31) ;
		v[1] = Date(12,31,2005) ;
		return v ;
	', plugin = "Rcpp" )
    checkEquals(fx(), rep(as.Date("2005-12-31"),2), msg = "DateVector.SEXP")
}

