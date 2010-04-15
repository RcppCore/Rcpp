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

test.Pairlist <- function(){
	funx <- cppfunction(signature(x="ANY"), 'return Pairlist(x) ;' )
	checkEquals( funx( pairlist("rnorm") ), pairlist("rnorm" ), msg = "Pairlist( LISTSXP )" )
	checkEquals( funx( call("rnorm") ), pairlist(as.name("rnorm")), msg = "Pairlist( LANGSXP )" )
	checkEquals( funx(1:10), as.pairlist(1:10) , msg = "Pairlist( INTSXP) " )
	checkEquals( funx(TRUE), as.pairlist( TRUE) , msg = "Pairlist( LGLSXP )" )
	checkEquals( funx(1.3), as.pairlist(1.3), msg = "Pairlist( REALSXP) " )
	checkEquals( funx(as.raw(1) ), as.pairlist(as.raw(1)), msg = "Pairlist( RAWSXP)" )
	
	checkException( funx(funx), msg = "Pairlist not compatible with function" )
	checkException( funx(new.env()), msg = "Pairlist not compatible with environment" )
	
}

test.Pairlist.variadic <- function(){
	if( Rcpp:::capabilities()[["variadic templates"]] ){
		funx <- cppfunction(signature(), '
		return Pairlist( "rnorm", 10, 0.0, 2.0 ) ;
		', cxxargs = "-std=c++0x" )
		checkEquals( funx(), pairlist("rnorm", 10L, 0.0, 2.0 ), 
			msg = "variadic templates" )
			
		funx <- cppfunction(signature(), '
		return Pairlist( "rnorm", 10, Named("mean",0.0), 2.0 ) ;
		',
			cxxargs = "-std=c++0x" )
		checkEquals( funx(), pairlist("rnorm", 10L, mean = 0.0, 2.0 ), 
			msg = "variadic templates (with names)" )
	}
}

test.Pairlist.push.front <- function(){
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_front( 1 ) ;
	p.push_front( 10.0 ) ;
	p.push_front( "foo" ) ;
	p.push_front( Named( "foobar", 10) ) ;
	return p ;
	' )
	checkEquals( funx(), 
		pairlist( foobar = 10, "foo", 10.0, 1L), 
		msg = "Pairlist::push_front" )
}

test.Pairlist.push.back <- function(){
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( "foo" ) ;
	p.push_back( Named( "foobar", 10) ) ;
	return p ;
	' )
	checkEquals( funx(), 
		pairlist( 1L, 10.0, "foo", foobar = 10), 
		msg = "Pairlist::push_back" )
}

test.Pairlist.insert <- function(){
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	
	/* insert in 2nd position */
	p.insert( 1, Named( "bla", "bla" ) ) ;
	
	/* insert in front */
	p.insert( 0, 30.0 ) ;
	
	/* insert in back */
	p.insert( 5, "foobar" ) ;
	
	return p ;
	' )
	checkEquals( funx(), 
		pairlist( 30.0, 1L, bla = "bla", 10.0, 20.0, "foobar" ), 
		msg = "Pairlist::replace" )
}

test.Pairlist.replace <- function(){
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	p.replace( 0, Named( "first", 1 ) ) ;
	p.replace( 1, 20.0 ) ;
	p.replace( 2, false ) ;
	return p ;' )
	checkEquals( funx(),
		pairlist( first = 1, 20.0 , FALSE), msg = "Pairlist::replace" )	
}

test.Pairlist.size <- function(){
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	return wrap( p.size() ) ;
	' )
	checkEquals( funx(), 3L, msg = "Pairlist::size()" )
}

test.Pairlist.remove <- function(){
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	p.remove( 0 ) ;
	return p ;
	' )
	checkEquals( funx(), pairlist(10.0, 20.0), msg = "Pairlist::remove(0)" )
	
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	p.remove( 2 ) ;
	return p ;
	' )
	checkEquals( funx(), pairlist(1L, 10.0), msg = "Pairlist::remove(0)" )
	
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	p.remove( 1 ) ;
	return p ;
	' )
	checkEquals( funx(), pairlist(1L, 20.0), msg = "Pairlist::remove(0)" )
	
}

test.Pairlist.square <- function(){
	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	return p[1] ;
	' )
	checkEquals( funx(), 10.0, msg = "Pairlist::operator[] used as rvalue" )

	funx <- cppfunction(signature(), '
	Pairlist p ;
	p.push_back( 1 ) ;
	p.push_back( 10.0 ) ;
	p.push_back( 20.0 ) ;
	p[1] = "foobar" ;
	p[2] = p[0] ;
	return p ;
	' )
	checkEquals( funx(), pairlist(1L, "foobar", 1L) , msg = "Pairlist::operator[] used as lvalue" )
}


