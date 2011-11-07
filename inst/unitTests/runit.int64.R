#!/usr/bin/r -t
#
# Copyright (C) 2010 - 2011  Dirk Eddelbuettel and Romain Francois
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

definitions <- function(){
f <- list(
    "wrap_int64" = list( 
        signature(), 
        '
int64_t x = 13 ;
return wrap( x ) ;
        '
    ), 
    "wrap_uint64" = list( 
        signature(), 
        '
uint64_t x = 13 ;
return wrap( x ) ;
        '
    ), 
    
    "wrap_vector_int64"=list( 
        signature(),
        '
std::vector<int64_t> x(3) ;
x[0] = 0 ;
x[1] = 1 ; 
x[2] = 2 ;
return wrap(x) ;
        '), 
    "wrap_vector_uint64"=list( 
        signature(),
        '
std::vector<uint64_t> x(3) ;
x[0] = 0 ;
x[1] = 1 ; 
x[2] = 2 ;
return wrap(x) ;
        '    
        ), 
    "as_int64" = list( 
        signature( x_ = "ANY" ), 
        '
int64_t x = as<int64_t>( x_) ;
return wrap( x == 13 ) ;
        '
    ), 
    "as_uint64" = list( 
        signature( x_ = "ANY" ), 
        '
uint64_t x = as<uint64_t>( x_) ;
return wrap( x == 13 ) ;
        '
    ), 
    "as_vector_int64" = list( 
    signature( x_ = "ANY" ), 
        '
std::vector<int64_t> x = as< std::vector<int64_t> >( x_) ;
int64_t sum = 0 ;
for( int i=0; i<x.size(); i++) sum += x[i] ;
return wrap( sum == 10 ) ;
        '
    ), 
    "as_vector_uint64" = list( 
    signature( x_ = "ANY" ), 
        '
std::vector<uint64_t> x = as< std::vector<uint64_t> >( x_) ;
uint64_t sum = 0 ;
for( int i=0; i<x.size(); i++) sum += x[i] ;
return wrap( sum == 10 ) ;
        '
    ), 
    "export_indexing_vector_int64" = list( 
    signature( x_ = "ANY" ), 
        '
std::vector<int64_t> x(4) ;
Rcpp::internal::export_indexing< std::vector<int64_t>, int64_t>( x_, x) ;
int64_t sum = 0 ;
for( int i=0; i<x.size(); i++) sum += x[i] ;
return wrap( sum == 10 ) ;

'
    ), 
    "export_indexing_vector_uint64" = list( 
    signature( x_ = "ANY" ), 
        '
std::vector<uint64_t> x(4) ;
Rcpp::internal::export_indexing< std::vector<uint64_t>, uint64_t>( x_, x) ;
uint64_t sum = 0 ;
for( int i=0; i<x.size(); i++) sum += x[i] ;
return wrap( sum == 10 ) ;

'
    )
 )
        f
}


.setUp <- function() {
    if( ! exists( ".rcpp.int64", globalenv() )) {
       fun <- Rcpp:::compile_unit_tests( definitions() )
       assign( ".rcpp.int64", fun, globalenv() )
    }
}

test.wrap.int64 <- function(){
    fun <- .rcpp.int64$wrap_int64
    checkEquals(fun(),
                as.int64(13),
                msg = "wrap( int64 ) " )  
                
    fun <- .rcpp.int64$wrap_uint64
    checkEquals(fun(),
                as.uint64(13),
                msg = "wrap( uint64 ) " )  
                
                
}

test.wrap.vector.int64 <- function(){
    fun <- .rcpp.int64$wrap_vector_int64
    checkEquals(fun(),
                as.int64(0:2),
                msg = "wrap( vector<int64> ) " )

    fun <- .rcpp.int64$wrap_vector_uint64
    checkEquals(fun(),
                as.uint64(0:2),
                msg = "wrap( vector<uint64> ) " )
}

test.as.int64 <- function(){
    fun <- .rcpp.int64$as_int64
    checkTrue(fun(13), msg = "as<int64_t>" )
    checkTrue(fun(13L), msg = "as<int64_t>" )
    checkTrue(fun(as.int64(13L)), msg = "as<int64_t>" )

    fun <- .rcpp.int64$as_uint64
    checkTrue(fun(13), msg = "as<uint64_t>" )
    checkTrue(fun(13L), msg = "as<uint64_t>" )
    checkTrue(fun(as.uint64(13L)), msg = "as<uint64_t>" )
}

test.as.vector.int64 <- function(){
    fun <- .rcpp.int64$as_vector_int64
    checkTrue(fun(1:4), msg = "as< vector<int64_t> >" )
    checkTrue(fun(seq(1, 4, by = 1)), msg = "as< vector<int64_t> >" )
    checkTrue(fun(as.int64(1:4)), msg = "as< vector<int64_t> >" )

    fun <- .rcpp.int64$as_vector_uint64
    checkTrue(fun(1:4), msg = "as<uint64_t>" )
    checkTrue(fun(seq(1, 4, by = 1)), msg = "as<uint64_t>" )
    checkTrue(fun(as.uint64(1:4)), msg = "as<uint64_t>" )

}

test.as.vector.int64 <- function(){
    fun <- .rcpp.int64$export_indexing_vector_int64
    checkTrue(fun(1:4), msg = "export_indexing< vector<int64_t>, int64_t>" )
    checkTrue(fun(seq(1, 4, by = 1)), msg = "export_indexing< vector<int64_t>, int64_t>" )
    checkTrue(fun(as.int64(1:4)), msg = "export_indexing< vector<int64_t>, int64_t>" )

    fun <- .rcpp.int64$export_indexing_vector_uint64
    checkTrue(fun(1:4), msg = "export_indexing< vector<uint64_t>, uint64_t>" )
    checkTrue(fun(seq(1, 4, by = 1)), msg = "export_indexing< vector<uint64_t>, uint64_t>" )
    checkTrue(fun(as.uint64(1:4)), msg = "export_indexing< vector<uint64_t>, uint64_t>" )
}

