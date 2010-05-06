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
	suppressMessages( require( datasets ) )
	data( iris )
}

test.DataFrame.FromSEXP <- function() {
    DF <- data.frame(a=1:3, b=c("a","b","c"))
    fun <- cppfunction( signature(x='ANY'), '
	DataFrame df(x) ;
	return df;
    ' )
    checkEquals( fun(DF), DF, msg = "DataFrame pass-through")
}

test.DataFrame.CreateOne <- function() {
    DF <- data.frame(a=1:3)
    fun <- cppfunction( signature(), '
        IntegerVector v = IntegerVector::create(1,2,3);
		return DataFrame::create(Named("a")=v);
    ' )
    checkEquals( fun(), DF, msg = "DataFrame create1")
}

test.DataFrame.CreateTwo <- function() {
    DF <- data.frame(a=1:3, b=c("a","b","c"))
    fun <- cppfunction( signature(), '
        IntegerVector v = IntegerVector::create(1,2,3);
        std::vector<std::string> s(3);
        s[0] = "a";
        s[1] = "b";
        s[2] = "c";
		return DataFrame::create(Named("a")=v, Named("b")=s);
	' )
    checkEquals( fun(), DF, msg = "DataFrame create2")
}

test.DataFrame.SlotProxy <- function(){
	
	setClass("track", representation(x="data.frame", y = "function"))
	tr1 <- new( "track", x = iris, y = rnorm )                    
	fun <- cppfunction( signature(x="ANY", y="character"), '
		S4 o(x) ;
		return DataFrame( o.slot( as<std::string>(y) )) ;
	' )
	checkTrue( identical( fun(tr1, "x"), iris ), msg = "DataFrame( SlotProxy )" )
	checkException( fun(tr1, "y"), msg = "DataFrame( SlotProxy ) -> exception" )
}

test.DataFrame.AttributeProxy <- function(){
	
	tr1 <- structure( NULL, x = iris, y = rnorm )
	fun <- cppfunction( signature(x="ANY", y="character"), '
		List o(x) ;
		return DataFrame( o.attr( as<std::string>(y) )) ;
	' )
	checkTrue( identical( fun(tr1, "x"), iris) , msg = "DataFrame( AttributeProxy )" )
	checkException( fun(tr1, "y"), msg = "DataFrame( AttributeProxy ) -> exception" )
	
}


