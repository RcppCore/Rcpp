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
    tests <- ".rcpp.as"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list("as_int"=list(
                  signature(x="numeric"),
                  'int y = as<int>(x);
	           return wrap(y) ;')

                  ,"as_double"=list(
                   signature(x="numeric"),
                   'double y = as<double>(x) ;
		    return wrap(y) ;')

                  ,"as_raw"=list(
                   signature(x="numeric"),
                   'Rbyte y = as<Rbyte>(x) ;
	            return wrap(y) ;')

                  ,"as_bool"=list(
                   signature(x="numeric"),
                   'bool y = as<bool>(x) ;
	            return wrap(y) ;')

                  ,"as_string"=list(
                   signature(x="character"),
                   'std::string y = as<std::string>(x) ;
	            return wrap(y) ;')

                  ,"as_vector_int"=list(
                   signature(x="numeric"),
                   'vector<int> y = as< vector<int> >(x) ;
	            return wrap(y) ;')

                  ,"as_vector_double"=list(
                   signature(x="numeric"),
                   'vector<double> y = as< vector<double> >(x) ;
  	            return wrap(y) ;')

                  ,"as_vector_raw"=list(
                   signature(x="numeric"),
                   'vector<Rbyte> y = as< vector<Rbyte> >(x) ;
	            return wrap(y) ;')

                  ,"as_vector_bool"=list(
                   signature(x="numeric"),
                   'vector<bool> y = as< vector<bool> >(x) ;
	            return wrap(y) ;')

                  ,"as_vector_string"=list(
                   signature(x="character"),
                   'vector<string> y = as< vector<string> >(x) ;
	            return wrap(y) ;')

                  ,"as_deque_int"=list(
                   signature(x="integer"),
                   'deque<int> y = as< deque<int> >(x) ;
		    return wrap( accumulate( y.begin(), y.end(), 0.0 ) ) ;')

                  ,"as_list_int"=list(
                   signature(x="integer"),
                   'list<int> y = as< list<int> >(x) ;
	            return wrap( accumulate( y.begin(), y.end(), 0.0 ) ) ;')

                  )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction( signatures, bodies, plugin = "Rcpp", includes = "using namespace std;")
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}


test.as.int <- function(){
    fun <- .rcpp.as$as_int
    checkEquals( fun(10), 10L, msg = "as<int>( REALSXP ) " )
    checkEquals( fun(10L), 10L, msg = "as<int>( INTSXP ) " )
    checkEquals( fun(as.raw(10L)), 10L, msg = "as<int>( RAWSXP ) " )
    checkEquals( fun(TRUE), 1L, msg = "as<int>( LGLSXP ) " )
}

test.as.double <- function(){
    fun <- .rcpp.as$as_double
    checkEquals( fun(10), 10.0, msg = "as<double>( REALSXP ) " )
    checkEquals( fun(10L), 10.0, msg = "as<double>( INTSXP ) " )
    checkEquals( fun(as.raw(10L)), 10.0, msg = "as<double>( RAWSXP ) " )
    checkEquals( fun(TRUE), 1.0, msg = "as<double>( LGLSXP ) " )
}

test.as.raw <- function(){
    fun <- .rcpp.as$as_raw
    checkEquals( fun(10), as.raw(10), msg = "as<Rbyte>( REALSXP ) " )
    checkEquals( fun(10L), as.raw(10), msg = "as<Rbyte>( INTSXP ) " )
    checkEquals( fun(as.raw(10L)), as.raw(10), msg = "as<Rbyte>( RAWSXP ) " )
    checkEquals( fun(TRUE), as.raw(1), msg = "as<Rbyte>( LGLSXP ) " )
}

test.as.bool <- function(){
    fun <- .rcpp.as$as_bool
    checkEquals( fun(10), as.logical(10), msg = "as<bool>( REALSXP ) " )
    checkEquals( fun(10L), as.logical(10), msg = "as<bool>( INTSXP ) " )
    checkEquals( fun(as.raw(10L)), as.logical(10), msg = "as<bool>( RAWSXP ) " )
    checkEquals( fun(TRUE), as.logical(1), msg = "as<bool>( LGLSXP ) " )
}

test.as.string <- function(){
    fun <- .rcpp.as$as_string
    checkEquals( fun("foo"), "foo", msg = "as<string>( STRSXP ) " )
}

test.as.vector.int <- function(){
    fun <- .rcpp.as$as_vector_int
    checkEquals( fun(1:10), 1:10 , msg = "as<vector<int>>( INTSXP ) " )
    checkEquals( fun(as.numeric(1:10)), 1:10 , msg = "as<vector<int>>( REALSXP ) " )
    checkEquals( fun(as.raw(1:10)), 1:10 , msg = "as<vector<int>>( RAWSXP ) " )
    checkEquals( fun(c(TRUE,FALSE)), 1:0 , msg = "as<vector<int>>( LGLSXP ) " )
}

test.as.vector.double <- function(){
    fun <- .rcpp.as$as_vector_double
    checkEquals( fun(1:10), as.numeric(1:10) , msg = "as<vector<double>>( INTSXP ) " )
    checkEquals( fun(as.numeric(1:10)), as.numeric(1:10) , msg = "as<vector<double>>( REALSXP ) " )
    checkEquals( fun(as.raw(1:10)), as.numeric(1:10), msg = "as<vector<double>>( RAWSXP ) " )
    checkEquals( fun(c(TRUE,FALSE)), c(1.0, 0.0) , msg = "as<vector<double>>( LGLSXP ) " )
}

test.as.vector.raw <- function(){
    fun <- .rcpp.as$as_vector_raw
    checkEquals( fun(1:10), as.raw(1:10) , msg = "as<vector<Rbyte>>( INTSXP ) " )
    checkEquals( fun(as.numeric(1:10)), as.raw(1:10) , msg = "as<vector<Rbyte>>( REALSXP ) " )
    checkEquals( fun(as.raw(1:10)), as.raw(1:10) , msg = "as<vector<Rbyte>>( RAWSXP ) " )
    checkEquals( fun(c(TRUE,FALSE)), as.raw(1:0) , msg = "as<vector<Rbyte>>( LGLSXP ) " )
}

test.as.vector.bool <- function(){
    fun <- .rcpp.as$as_vector_bool
    checkEquals( fun(0:10), as.logical(0:10) , msg = "as<vector<bool>>( INTSXP ) " )
    checkEquals( fun(as.numeric(0:10)), as.logical(0:10) , msg = "as<vector<bool>>( REALSXP ) " )
    checkEquals( fun(as.raw(0:10)), as.logical(0:10) , msg = "as<vector<bool>>( RAWSXP ) " )
    checkEquals( fun(c(TRUE,FALSE)), as.logical(1:0) , msg = "as<vector<bool>>( LGLSXP ) " )
}


test.as.vector.string <- function(){
    fun <- .rcpp.as$as_vector_string
    checkEquals( fun(letters), letters , msg = "as<vector<string>>( STRSXP ) " )
}

test.as.deque.int <- function(){
    fun <- .rcpp.as$as_deque_int
    checkEquals( fun(1:10), sum(1:10) , msg = "as<deque<int>>( INTSXP ) " )
}

test.as.list.int <- function(){
    fun <- .rcpp.as$as_list_int
    checkEquals( fun(1:10), sum(1:10) , msg = "as<list<int>>( INTSXP ) " )
}

