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

test.CharacterVector <- function(){
	funx <- cppfunction(signature(), '
	CharacterVector x(10) ;
	for( int i=0; i<10; i++) x[i] = "foo" ;
	return x ;' )
	checkEquals( funx(), rep("foo",10L), msg = "CharacterVector" )
}

test.CharacterVector.STRSXP <- function(){
	funx <- cppfunction(signature(vec = "character" ), '
	CharacterVector x(vec) ;
	std::string st = "" ;
	for( int i=0; i<x.size(); i++) {
		st += x[i] ;
	}
	return wrap( st ) ;' )
	checkEquals( funx(letters), paste(letters,collapse="" ),
		msg = "CharacterVector( STRSXP) " )
}

test.CharacterVector.initializer.list <- function(){
	if( Rcpp:::capabilities()[["initializer lists"]] ){
		funx <- cppfunction(signature(), '
		CharacterVector x = {"foo", "bar"} ;
		return x ;', cxxargs = "-std=c++0x" )
		checkEquals( funx(), c("foo","bar"), msg = "CharacterVector( initializer list) " )
	}
}

test.CharacterVector.plusequals <- function(){
	funx <- cppfunction(signature(), '
	CharacterVector x(2) ;
	x[0] = "foo" ;
	x[1] = "bar" ;
	x[0] += "bar" ;
	x[1] += x[0] ;
	return x ;
	',  )
	checkEquals( funx(), c("foobar", "barfoobar"),
		msg = "StringProxy::operator+=" )
}

test.CharacterVector.matrix.indexing <- function(){

	funx <- cppfunction(signature(x = "character" ), '
		CharacterVector m(x) ;
		std::string trace  ;
		for( size_t i=0 ; i<4; i++){
			trace += m(i,i) ;
		}
		return wrap( trace ) ;
	'   )
	x <- matrix( as.character(1:16), ncol = 4 )
	checkEquals( funx(x), paste(diag(x), collapse = ""), msg = "matrix indexing" )

	y <- as.vector( x )
	checkException( funx(y) , msg = "not a matrix" )

	funx <- cppfunction(signature(x = "integer" ), '
		CharacterVector m(x) ;
		for( size_t i=0 ; i<4; i++){
			m(i,i) = "foo" ;
		}
		return m ;
	'   )
	checkEquals( diag(funx(x)), rep("foo", 4) ,
		msg = "matrix indexing lhs" )
}

test.CharacterVector.assign <- function(){

	funx <- cppfunction(signature(), '
		const char* x[] = { "foo", "bar", "bling", "boom" } ;
		CharacterVector y ;
		y.assign( x, x+4 ) ;
		return y;
	'  )
	checkEquals( funx(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )


	funx <- cppfunction(signature(), '
		std::vector<std::string> vec(4) ;
		vec[0] = "foo";
		vec[1] = "bar";
		vec[2] = "bling";
		vec[3] = "boom" ;
		CharacterVector y ;
		y.assign( vec.begin(), vec.end() ) ;
		return y;
	' )
	checkEquals( funx(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )

}

test.CharacterVector.range.constructors <- function(){

	funx <- cppfunction(signature(), '
		const char* x[] = { "foo", "bar", "bling", "boom" } ;
		CharacterVector y( x, x+4 ) ;
		return y;
	'  )
	checkEquals( funx(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )


	funx <- cppfunction(signature(), '
		std::vector<std::string> vec(4) ;
		vec[0] = "foo";
		vec[1] = "bar";
		vec[2] = "bling";
		vec[3] = "boom" ;
		CharacterVector y( vec.begin(), vec.end() ) ;
		return y;
	'  )
	checkEquals( funx(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )
}

test.CharacterVector.Dimension.constructor <- function(){

	funx <- cppfunction(signature(), 'return CharacterVector( Dimension( 5 ) ) ;'  )
	checkEquals( funx(),
		character(5) ,
		msg = "CharacterVector( Dimension(5))" )

	funx <- cppfunction(signature(), 'return CharacterVector( Dimension( 5, 5 ) ) ;'  )
	checkEquals( funx(),
		matrix( "", ncol = 5, nrow = 5) ,
		msg = "CharacterVector( Dimension(5,5))" )

	funx <- cppfunction(signature(), 'return CharacterVector( Dimension( 2, 3, 4) ) ;'  )
	checkEquals( funx(),
		array( "", dim = c(2,3,4) ) ,
		msg = "CharacterVector( Dimension(2,3,4))" )
}

test.CharacterVector.iterator <- function(){
	funx <- cppfunction(signature(x = "character"), '
		CharacterVector letters(x) ;
		std::string res ;
		CharacterVector::iterator first = letters.begin() ;
		CharacterVector::iterator last = letters.end() ;
		while( first != last ){
			res += *first ;
			++first ;
		}
		return wrap(res) ;
	;' )
	checkEquals(
		funx(letters),
		paste(letters, collapse=""),
		msg = "CharacterVector::iterator explicit looping" )

	funx <- cppfunction(signature(x = "character"), '
		CharacterVector letters(x) ;
		std::string res(
			std::accumulate(
				letters.begin(), letters.end(), std::string() ) ) ;
		return wrap(res) ;
	;' )
	checkEquals(
		funx(letters),
		paste(letters, collapse=""),
		msg = "CharacterVector::iterator using std::accumulate" )

}

test.CharacterVector.reverse <- function(){
	funx <- cppfunction(signature(x = "character"), '
		CharacterVector y(x) ;
		std::reverse( y.begin(), y.end() ) ;
		return y ;
	;'  )
	x <- c("foo", "bar", "bling")
	funx(x)
	checkEquals( x, c("bling", "bar", "foo"), msg = "reverse" )
	funx(x)
	checkEquals( x, c("foo", "bar", "bling"), msg = "reverse" )
}

test.CharacterVector.names.indexing <- function(){
	funx <- cppfunction(signature(x = "character"), '
		CharacterVector y(x) ;
		std::string foo( y["foo"] ) ;
		return wrap(foo) ;
	;' )
	x <- c( foo = "foo", bar = "bar" )
	checkEquals( funx(x), "foo", msg = "CharacterVector names based indexing" )
}

test.CharacterVector.comma <- function(){
	funx <- cppfunction(signature(), '
        	CharacterVector x(3) ;
        	x = "foo", "bar", "bling" ;
        	return x ;'  )
        checkEquals( funx(), c("foo","bar", "bling" ), msg = "CharacterVector comma operator" )
}

test.CharacterVector.listOf <- function() {
    src <- '
    List ll(l);
    CharacterVector cv1 = ll["foo"];
    CharacterVector cv2 = ll["bar"];
    std::string rv1 = std::string(cv1[0]) + cv1[1] + cv1[2];
    std::string rv2 = std::string(cv2[0]) + cv2[1] + cv2[2];
    return List::create(_["foo"] = rv1, _["bar"] = rv2);
    '
    fun <- cppfunction(signature(l = "list"), src )
    checkEquals(fun(list(foo=c("tic","tac","toe"),
                         bar=c("Eenie","Meenie","Moe"))),
                list(foo="tictactoe", bar="EenieMeenieMoe"),
                msg="CharacterVector from list")
}




