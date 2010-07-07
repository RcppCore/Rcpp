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
    tests <- ".rcpp.IntegerVector"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list("ctor"=list(
                  signature(),
                  'IntegerVector x(10) ;
	           for( int i=0; i<10; i++) x[i] = i ;
	           return x ;')

                  ,"INTSXP_"=list(
                   signature(vec = "integer" ),
                   'IntegerVector x(vec) ;
	            for( int i=0; i<x.size(); i++) {
		       x[i] = x[i]*2 ;
	            }
	            return x ;')

                  ,"matrix_indexing"=list(
                   signature(x = "integer" ),
                   'IntegerVector m(x) ;
		    int trace = 0.0 ;
		    for( size_t i=0 ; i<4; i++){
		        trace += m(i,i) ;
		    }
		    return wrap( trace ) ;')

                  ,"matrix_indexing_lhs"=list(
                   signature(x = "integer" ),
                   'IntegerVector m(x) ;
		    for( size_t i=0 ; i<4; i++){
		        m(i,i) = 2 * i ;
		    }
		    return m ; ')

                  ,"dimension_ctor_1"=list(
                   signature(),
                   'return IntegerVector( Dimension( 5 ) ) ;')

                  ,"dimension_ctor_2"=list(
                   signature(),
                   'return IntegerVector( Dimension( 5, 5 ) ) ;')

                  ,"dimension_ctor_3"=list(
                   signature(),
                   'return IntegerVector( Dimension( 2, 3, 4) ) ;')

                  ,"range_ctor_1"=list(
                   signature(),
                   'int x[] = { 0, 1, 2, 3 } ;
		    IntegerVector y( x, x+4 ) ;
		    return y; ')

                  ,"range_ctor_2"=list(
                   signature(),
                   'std::vector<int> vec(4) ;
		    for( size_t i = 0; i<4; i++) vec[i] = i;
		    IntegerVector y( vec.begin(), vec.end() ) ;
		    return y;')

                  ,"names_set"=list(
                   signature(),
                   'IntegerVector y(2) ;
		    std::vector<std::string> names(2)  ;
		    names[0] = "foo" ;
		    names[1] = "bar" ;
		    y.names() = names ;
		    return y ; ')

                  ,"names_get"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
		    return y.names() ;')

                  ,"names_indexing"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
		    return wrap( y["foo"] ); ')

                  ,"comma"=list(
                   signature(),
                   'IntegerVector x(4) ;
	            x = 0, 1, 2, 3 ;
	            return x ;')

                  ,"push_back"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.push_back( 5 ) ;
	            return y ;')

                  ,"push_front"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.push_front( 5 ) ;
	            return y ;')

                  ,"insert"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.insert( 0, 5 ) ;
	            y.insert( 2, 7 ) ;
	            return y ;')

                  ,"erase"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.erase(2) ;
	            return y ;')

                  ,"erase2"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.erase(1,2) ;
	            return y ;')

                  ,"fill"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.fill(10) ;
	            return y ;' )

                  ,"zero"=list(
                   signature(),
                   'return IntegerVector(0);' )

                  ,"create_zero"=list(
                   signature(),
                   'return IntegerVector::create();'
                  ), 
                  "create_" = list( 
                  signature(), 
                  '
					List output(2); 
					output[0] = IntegerVector::create( 10, 20 ) ;
					output[1] = IntegerVector::create( 
						_["foo"] = 20, 
						_["bar"] = 30 ) ;
					return output ;
					' 
                  ), 
                  "clone_" = list( 
                  signature(x="integer"), 
                  '
					IntegerVector vec(x) ;
					IntegerVector dolly = clone( vec ) ;
					for( size_t i=0; i<10; i++){
						dolly[i] = 10 - i ;
					}
					return dolly ;
					'
                  )

                  )

        g <- list("initializer_list"=list(
                  signature(),
                  'IntegerVector x = {0,1,2,3} ;
		   for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
		   return x ;')
                  )

	if (Rcpp:::capabilities()[["initializer lists"]]) {
            f <- c(f,g)
        }

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction(signatures, bodies,
                           plugin = "Rcpp", includes = "using namespace std;",
                           cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x",""))
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.IntegerVector <- function(){
    fun <- .rcpp.IntegerVector$ctor
    checkEquals( fun(), 0:9, msg = "IntegerVector" )
}

test.IntegerVector.INTSXP_ <- function(){
    fun <- .rcpp.IntegerVector$INTSXP
    checkEquals( fun(0:9), 2*0:9, msg = "IntegerVector( INTSXP) " )
}

if (Rcpp:::capabilities()[["initializer lists"]]) {
    test.IntegerVector.initializer.list <- function() {
        fun <- .rcpp.IntegerVector$initializer_list
        checkEquals( fun(), 2*0:3, msg = "IntegerVector( initializer list) " )
    }
}

test.IntegerVector.matrix.indexing <- function(){
    fun <- .rcpp.IntegerVector$matrix_indexing
    x <- matrix( 1:16, ncol = 4 )
    checkEquals( fun(x), sum(diag(x)), msg = "matrix indexing" )

    fun <- .rcpp.IntegerVector$matrix_indexing_lhs
    checkEquals( diag(fun(x)), 2*0:3, msg = "matrix indexing lhs" )

    y <- as.vector( x )
    checkException( fun(y) , msg = "not a matrix" )
}

test.IntegerVector.Dimension.constructor <- function(){
    fun <- .rcpp.IntegerVector$dimension_ctor_1
    checkEquals(fun(),
                integer(5) ,
                msg = "IntegerVector( Dimension(5))" )

    fun <- .rcpp.IntegerVector$dimension_ctor_2
    checkEquals(fun(),
                matrix( 0L, ncol = 5, nrow = 5) ,
                msg = "IntegerVector( Dimension(5,5))" )

    fun <- .rcpp.IntegerVector$dimension_ctor_3
    checkEquals(fun(),
		array( 0L, dim = c(2,3,4) ) ,
		msg = "IntegerVector( Dimension(2,3,4))" )
}

test.IntegerVector.range.constructors <- function(){
    fun <- .rcpp.IntegerVector$range_ctor_1
    checkEquals( fun(), 0:3, msg = "assign(int*, int*)" )

    fun <- .rcpp.IntegerVector$range_ctor_2
    checkEquals( fun(), 0:3, msg = "assign(int*, int*)" )
}

test.IntegerVector.names.set <- function(){
    fun <- .rcpp.IntegerVector$names_set
    checkEquals(names(fun()), c("foo", "bar"), msg = "Vector::names" )
}

test.IntegerVector.names.get <- function(){
    fun <- .rcpp.IntegerVector$names_get
    checkEquals(fun( c("foo" = 1L, "bar" = 2L) ),
                c("foo", "bar"),
		msg = "Vector::names get" )
}

test.IntegerVector.names.indexing <- function(){
    fun <- .rcpp.IntegerVector$names_indexing
    x <- c( "foo" = 1L, "bar" = 2L )
    checkEquals( fun( x ), 1L, msg = "IntegerVector names based indexing" )
}

test.IntegerVector.comma <- function(){
    fun <- .rcpp.IntegerVector$comma
    checkEquals( fun(), 0:3, msg = "IntegerVector comma initialization" )
}

test.IntegerVector.push.back <- function(){
    fun <- .rcpp.IntegerVector$push_back
    checkEquals( fun(1:4), 1:5, msg = "IntegerVector push back" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- 1:5
    names(target) <- c( letters[1:4], "")
    checkEquals( fun(x), target, msg = "IntegerVector push back names" )
}

test.IntegerVector.push.front <- function(){
    fun <- .rcpp.IntegerVector$push_front
    checkEquals( fun(1:4), c(5L,1:4), msg = "IntegerVector push front" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c( 5L, 1:4 )
    names(target) <- c( "", letters[1:4])

    checkEquals( fun(x), target, msg = "IntegerVector push front names" )
}

test.IntegerVector.insert <- function(){
    fun <- .rcpp.IntegerVector$insert
    checkEquals( fun(1:4), c(5L,1L, 7L, 2:4), msg = "IntegerVector insert" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c( 5L, 1L, 7L, 2:4 )
    names(target) <- c( "", "a", "", letters[2:4])

    checkEquals( fun(x), target, msg = "IntegerVector insert names" )
}

test.IntegerVector.erase <- function(){
    fun <- .rcpp.IntegerVector$erase
    checkEquals( fun(1:4), c(1L, 2L, 4L), msg = "IntegerVector erase" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c(1L, 2L, 4L)
    names(target) <- c( "a", "b", "d" )

    checkEquals( fun(x), target, msg = "IntegerVector erase" )
}

test.IntegerVector.erase2 <- function(){
    fun <- .rcpp.IntegerVector$erase2
    checkEquals( fun(1:4), c(1L, 4L), msg = "IntegerVector erase2" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c(1L, 4L)
    names(target) <- c( "a", "d" )

    checkEquals( fun(x), target, msg = "IntegerVector erase2" )
}

test.IntegerVector.fill <- function(){
    fun <- .rcpp.IntegerVector$fill
    x <- 1:10
    checkEquals( fun(x), rep(10L, 10 ), msg = "IntegerVector.fill" )
}

test.IntegerVector.zero <- function( ){
    fun <- .rcpp.IntegerVector$zero
    checkEquals( fun(), integer(0), msg = "IntegerVector(0)" )
}

test.IntegerVector.create.zero <- function( ){
    fun <- .rcpp.IntegerVector$create_zero
    checkEquals( fun(), integer(0), msg = "IntegerVector::create()" )
}

test.IntegerVector.create <- function(){
    fun <- .rcpp.IntegerVector$create_
	checkEquals( fun(), list( c( 10L, 20L) , c(foo = 20L, bar = 30L) ), 
		msg = "IntegerVector::create" )
}

test.IntegerVector.clone <- function(){
	x <- 1:10
	fun <- .rcpp.IntegerVector$clone_
	y <- fun(x)
	checkEquals( x, 1:10, msg = "clone" )
	checkEquals( y, 10:1, msg = "clone" )
}

