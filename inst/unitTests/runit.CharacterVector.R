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
    tests <- ".rcpp.CharacterVector"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list("ctor"=list(
                  signature(),
                  'CharacterVector x(10) ;
	           for( int i=0; i<10; i++) x[i] = "foo" ;
	           return x ;')

                  ,"STRSXP_"=list(
                   signature(vec = "character" ),
                   'CharacterVector x(vec) ;
	            std::string st = "" ;
	            for( int i=0; i<x.size(); i++) {
		         st += x[i] ;
	            }
	            return wrap( st ) ;' )

                  ,"plusequals"=list(
                   signature(),
                   'CharacterVector x(2) ;
	            x[0] = "foo" ;
	            x[1] = "bar" ;
	            x[0] += "bar" ;
	            x[1] += x[0] ;
	            return x ;')

                  ,"matrix_indexing"=list(
                   signature(x = "character" ),
                   'CharacterVector m(x) ;
		    std::string trace;
		    for( size_t i=0 ; i<4; i++){
		        trace += m(i,i) ;
		    }
		    return wrap( trace ) ;')

                  ,"matrix_indexing_lhs"=list(
                   signature(x = "integer" ),
                   'CharacterVector m(x) ;
		    for( size_t i=0 ; i<4; i++){
		        m(i,i) = "foo" ;
		    }
		    return m ;')

                  ,"assign1"=list(
                   signature(),
                   'const char* x[] = { "foo", "bar", "bling", "boom" } ;
		    CharacterVector y ;
		    y.assign( x, x+4 ) ;
		    return y;')

                  ,"assign2"=list(
                   signature(),
                   'std::vector<std::string> vec(4) ;
		    vec[0] = "foo";
		    vec[1] = "bar";
		    vec[2] = "bling";
		    vec[3] = "boom" ;
		    CharacterVector y ;
		    y.assign( vec.begin(), vec.end() ) ;
		    return y;')

                  ,"range_ctor1"=list(
                   signature(),
                   'const char* x[] = { "foo", "bar", "bling", "boom" } ;
		    CharacterVector y( x, x+4 ) ;
		    return y;')

                  ,"range_ctor2"=list(
                   signature(),
                   'std::vector<std::string> vec(4) ;
		    vec[0] = "foo";
		    vec[1] = "bar";
		    vec[2] = "bling";
		    vec[3] = "boom" ;
		    CharacterVector y( vec.begin(), vec.end() ) ;
		    return y; ')

                  ,"dimension_ctor1"=list(
                   signature(),
                   'return CharacterVector( Dimension( 5 ) ) ;')

                  ,"dimension_ctor2"=list(
                   signature(),
                   'return CharacterVector( Dimension( 5, 5 ) ) ;')

                  ,"dimension_ctor3"=list(
                   signature(),
                   'return CharacterVector( Dimension( 2, 3, 4) ) ;')

                  ,"iterator1"=list(
                   signature(x = "character"),
                   'CharacterVector letters(x) ;
		    std::string res ;
		    CharacterVector::iterator first = letters.begin() ;
		    CharacterVector::iterator last = letters.end() ;
		    while( first != last ){
		        res += *first ;
			++first ;
		    }
		    return wrap(res) ;' )

                  ,"iterator2"=list(
                   signature(x = "character"),
                   'CharacterVector letters(x) ;
		    std::string res(std::accumulate(letters.begin(), letters.end(), std::string()));
		    return wrap(res) ;' )

                  ,"reverse"=list(
                   signature(x = "character"),
                   'CharacterVector y(x) ;
		    std::reverse( y.begin(), y.end() ) ;
		    return y ;')

                  ,"names_indexing"=list(
                   signature(x = "character"),
                   'CharacterVector y(x) ;
		    std::string foo( y["foo"] ) ;
		    return wrap(foo) ;')

                  ,"comma"=list(
                   signature(),
                   'CharacterVector x(3) ;
        	    x = "foo", "bar", "bling" ;
        	    return x ;')

                  ,"listOf"=list(
                   signature(l = "list"),
                   'List ll(l);
                    CharacterVector cv1 = ll["foo"];
                    CharacterVector cv2 = ll["bar"];
                    std::string rv1 = std::string(cv1[0]) + cv1[1] + cv1[2];
                    std::string rv2 = std::string(cv2[0]) + cv2[1] + cv2[2];
                    return List::create(_["foo"] = rv1, _["bar"] = rv2); ')

                  ,"find_"=list(
                   signature(x = "character"),
                   'CharacterVector y(x) ;
	            CharacterVector::iterator it = std::find( y.begin(), y.end(), "foo" ) ;
	            return wrap( std::distance( y.begin(), it )); ')

                   )

        g <- list("initializer_list"=list(
                  signature(),
                  'CharacterVector x = {"foo", "bar"} ;
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

test.CharacterVector <- function(){
    fun <- .rcpp.CharacterVector$ctor
    checkEquals( fun(), rep("foo",10L), msg = "CharacterVector" )
}

test.CharacterVector.STRSXP <- function(){
    fun <- .rcpp.CharacterVector$STRSXP_
    checkEquals( fun(letters), paste(letters,collapse="" ), msg = "CharacterVector( STRSXP) " )
}

if (Rcpp:::capabilities()[["initializer lists"]]) {
    test.CharacterVector.initializer.list <- function() {
        fun <- .rcpp.CharacterVector$initializer_list
        checkEquals( fun(), c("foo","bar"), msg = "CharacterVector( initializer list) " )
    }
}

test.CharacterVector.plusequals <- function(){
    fun <- .rcpp.CharacterVector$plusequals
    checkEquals( fun(), c("foobar", "barfoobar"), msg = "StringProxy::operator+=" )
}

test.CharacterVector.matrix.indexing <- function() {
    fun <- .rcpp.CharacterVector$matrix_indexing
    x <- matrix( as.character(1:16), ncol = 4 )
    checkEquals( fun(x), paste(diag(x), collapse = ""), msg = "matrix indexing" )

    y <- as.vector( x )
    checkException( fun(y) , msg = "not a matrix" )

    fun <- .rcpp.CharacterVector$matrix_indexing_lhs
    checkEquals( diag(fun(x)), rep("foo", 4) , msg = "matrix indexing lhs" )
}

test.CharacterVector.assign <- function(){
    fun <- .rcpp.CharacterVector$assign1
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )

    fun <- .rcpp.CharacterVector$assign2
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )

}

test.CharacterVector.range.constructors <- function(){
    fun <- .rcpp.CharacterVector$range_ctor1
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )

    fun <- .rcpp.CharacterVector$range_ctor2
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )
}

test.CharacterVector.Dimension.constructor <- function(){
    fun <- .rcpp.CharacterVector$dimension_ctor1
    checkEquals(fun(),
                character(5),
                msg = "CharacterVector( Dimension(5))" )

    fun <- .rcpp.CharacterVector$dimension_ctor2
    checkEquals(fun(),
                matrix( "", ncol = 5, nrow = 5),
                msg = "CharacterVector( Dimension(5,5))" )

    fun <- .rcpp.CharacterVector$dimension_ctor3
    checkEquals(fun(),
		array( "", dim = c(2,3,4) ) ,
		msg = "CharacterVector( Dimension(2,3,4))" )
}

test.CharacterVector.iterator <- function(){
    fun <- .rcpp.CharacterVector$iterator1
    checkEquals(fun(letters),
		paste(letters, collapse=""),
		msg = "CharacterVector::iterator explicit looping" )

    fun <- .rcpp.CharacterVector$iterator2
    checkEquals(fun(letters),
		paste(letters, collapse=""),
		msg = "CharacterVector::iterator using std::accumulate" )
}

test.CharacterVector.reverse <- function(){
    fun <- .rcpp.CharacterVector$reverse
    x <- c("foo", "bar", "bling")
    x <- fun(x)
    checkEquals( x, c("bling", "bar", "foo"), msg = "reverse" )
    x <- fun(x)
    checkEquals( x, c("foo", "bar", "bling"), msg = "reverse" )
}

test.CharacterVector.names.indexing <- function(){
    fun <- .rcpp.CharacterVector$names_indexing
    x <- c( foo = "foo", bar = "bar" )
    checkEquals( fun(x), "foo", msg = "CharacterVector names based indexing" )
}

test.CharacterVector.comma <- function(){
    fun <- .rcpp.CharacterVector$comma
    checkEquals( fun(), c("foo","bar", "bling" ), msg = "CharacterVector comma operator" )
}

test.CharacterVector.listOf <- function() {
    fun <- .rcpp.CharacterVector$listOf
    checkEquals(fun(list(foo=c("tic","tac","toe"),
                         bar=c("Eenie","Meenie","Moe"))),
                list(foo="tictactoe", bar="EenieMeenieMoe"),
                msg="CharacterVector from list")
}

test.CharacterVector.find <- function(){
    fun <- .rcpp.CharacterVector$find_
    checkEquals( fun( c("bar", "foo", "bob") ), 1L, msg = "support for std::find in CharacterVector" )
}

