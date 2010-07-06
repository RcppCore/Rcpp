#!/usr/bin/r -t
# -*- mode: R; tab-width: 4 -*-
#
# Copyright (C) 2009 - 2010  Romain Francois and Dirk Eddelbuettel
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

    tests <- ".Rcpp.RObject"
    if( ! exists(tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list("asDouble"=list(
                  signature(x="numeric"),
                  'double d = as<double>(x);
				   return(wrap( 2*d ) );')

                  ,"asInt"=list(
                   signature(x="numeric"),
                   'int i = as<int>(x) ;
					return(wrap( 2*i ) ); ')

                  ,"asStdString"=list(
                   signature(x="character"),
                   'std::string s = as<std::string>(x) ;
	                return(wrap( s+s ) );')

                  ,"asRaw"=list(
                   signature(x="raw"),
                   'Rbyte i = as<Rbyte>(x);
	                return(wrap( (Rbyte)(2*i) ) ); ')

                  ,"asLogical"=list(
                   signature(x="logical"),
                   'bool b = as<bool>(x);
					return(wrap( !b ));')

                  ,"asStdVectorIntResultsSet"=list(
                   signature(x="numeric"),
                   'std::vector<int> iv = as<std::vector<int> >( x );
					for (size_t i=0; i<iv.size(); i++) {
    	    			iv[i] = 2*iv[i];
    				}
			    	RcppResultSet rs;
    				rs.add("", iv);
    				return(rs.getSEXP());')

                  ,"asStdVectorInt"=list(
                   signature(x="numeric"),
                   'std::vector<int> iv = as< std::vector<int> >(x);
				    for (size_t i=0; i<iv.size(); i++) {
				        iv[i] = 2*iv[i];
    				}
				    return(Rcpp::wrap( iv ) );')

                  ,"asStdVectorDouble"=list(
                   signature(x="numeric"),
                   'std::vector<double> iv = as< std::vector<double> >( x );
					for (size_t i=0; i<iv.size(); i++) {
	        			iv[i] = 2*iv[i];
	    			}
				 	return(Rcpp::wrap( iv ));')

                  ,"asStdVectorRaw"=list(
                   signature(x="raw"),
                   'std::vector<Rbyte> iv = as< std::vector<Rbyte> >( x );
					for (size_t i=0; i<iv.size(); i++) {
			    	    iv[i] = 2*iv[i];
			    	}
			 		return(Rcpp::wrap( iv ));')

                  ,"asStdVectorBool"=list(
                   signature(x="logical"),
                   'std::vector<bool> bv = as< std::vector<bool> >( x );
					for (size_t i=0; i<bv.size(); i++) {
		    			bv[i].flip() ;
					}
					return(Rcpp::wrap( bv ));')

                  ,"asStdVectorString"=list(
                   signature(x="character"),
                   'std::vector<std::string> iv = as< std::vector<std::string> >( x );
					for (size_t i=0; i<iv.size(); i++) {
			    	    iv[i] = iv[i] + iv[i];
			    	}
				 	return(Rcpp::wrap( iv ));')

                  ,"stdsetint"=list(
                   signature(),
                   'std::set<int> iv ;
					iv.insert( 0 ) ;
					iv.insert( 1 ) ;
					iv.insert( 0 ) ;
					return Rcpp::wrap( iv );')

                  ,"stdsetdouble"=list(
                   signature(),
                   'std::set<double> ds;
					ds.insert( 0.0 );
					ds.insert( 1.0 );
					ds.insert( 0.0 );
					return(Rcpp::wrap( ds )); ')

                  ,"stdsetraw"=list(
                   signature(),
                   'std::set<Rbyte> bs ;
					bs.insert( (Rbyte)0 ) ;
					bs.insert( (Rbyte)1 ) ;
					bs.insert( (Rbyte)0 ) ;
					return(Rcpp::wrap( bs )); ')

                  ,"stdsetstring"=list(
                   signature(),
                   'std::set<std::string> ss ;
					ss.insert( "foo" ) ;
					ss.insert( "bar" ) ;
					ss.insert( "foo" ) ;
					return(Rcpp::wrap( ss )); ')

                  ,"attributeNames"=list(
                   signature(x="data.frame"),
                   'std::vector<std::string> iv = RObject(x).attributeNames();
					return(wrap( iv ));' )

                  ,"hasAttribute"=list(
                   signature(x="data.frame"),
                   'bool has_class = RObject(x).hasAttribute( "class" ) ;
					return wrap( has_class ) ;')

                  ,"attr"=list(
                   signature(x="data.frame"),
                   'return RObject(x).attr( "row.names" ) ;')

                  ,"attr_set"=list(
                   signature(),
                   'RObject y = wrap("blabla") ;
	                y.attr("foo") = 10 ;
					return y ; ')

                  ,"isNULL"=list(
                   signature(x="ANY"),
                   'bool is_null = RObject(x).isNULL() ;
					return wrap( is_null ) ; ' )

                  )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction(signatures, bodies,
                           plugin = "Rcpp", includes = "using namespace std;",
                           cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x",""))
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.RObject.asDouble <- function(){
	funx <- .Rcpp.RObject$asDouble
	checkEquals( funx(2.123), 4.246, msg = "as<double>( REALSXP ) " )
	checkEquals( funx(2L), 4.0, msg = "as<double>( INTSXP ) " )
	checkEquals( funx(as.raw(2L)), 4.0, msg = "as<double>( RAWSXP )" )
	checkException( funx(x='2'), msg = "as<double>( STRSXP ) -> exception" )
	checkException( funx(x=2:3), msg = "as<double> expects the vector to be of length 1" )
}

test.RObject.asInt <- function(){
	funx <- .Rcpp.RObject$asInt
	checkEquals( funx(2.123), 4L, msg = "as<int>( REALSXP )" )
	checkEquals( funx(2), 4L, msg = "as<int>( REALSXP )" )
	checkEquals( funx(2L), 4.0, msg = "as<int>( INTSXP )" )
	checkEquals( funx(as.raw(2L)), 4.0, msg = "as<int>( RAWSXP )" )
	checkException( funx(x='2'), msg = "as<int> can not convert character" )
	checkException( funx(x=2:3), msg = "as<int> expects the vector to be of length 1" )
}

test.RObject.asStdString <- function(){
	funx <- .Rcpp.RObject$asStdString
	checkEquals( funx("abc"), "abcabc", msg = "as<std::string>" )
	checkException( funx(NULL), msg = "as<std::string> expects character vector" )
	checkException( funx(0L), msg = "as<std::string> expects character vector" )
	checkException( funx(0.1), msg = "as<std::string> expects character vector" )
	checkException( funx(as.raw(0L)), msg = "as<std::string> expects character vector" )

	checkException( funx(letters), msg = "as<std::string> expects single string" )
}

test.RObject.asRaw <- function(){
	funx <- .Rcpp.RObject$asRaw
	checkEquals( funx(1L), as.raw(2L), msg = "as<Rbyte>(integer)" )
	checkEquals( funx(1.3), as.raw(2L), msg = "as<Rbyte>(numeric)" )
	checkEquals( funx(as.raw(1)), as.raw(2L), msg = "as<Rbyte>(raw)" )
	checkException( funx(NULL) , msg = "as<Rbyte>(NULL) -> exception" )
	checkException( funx("foo") , msg = "as<Rbyte>(character) -> exception" )
	checkException( funx(1:2), msg = "as<Rbyte>(>1 integer) -> exception" )
	checkException( funx(as.numeric(1:2)), msg = "as<Rbyte>(>1 numeric) -> exception" )
	checkException( funx(as.raw(1:3)), msg = "as<Rbyte>(>1 raw) -> exception" )
	checkException( funx(integer(0)), msg = "as<Rbyte>(0 integer) -> exception" )
	checkException( funx(numeric(0)), msg = "as<Rbyte>(0 numeric) -> exception" )
	checkException( funx(raw(0)), msg = "as<Rbyte>(0 raw) -> exception" )
}

test.RObject.asLogical <- function(){
	funx <- .Rcpp.RObject$asLogical
	checkTrue( !funx(TRUE), msg = "as<bool>(TRUE) -> true" )
	checkTrue( funx(FALSE), msg = "as<bool>(FALSE) -> false" )
	checkTrue( !funx(1L), msg = "as<bool>(1L) -> true" )
	checkTrue( funx(0L), msg = "as<bool>(0L) -> false" )
	checkTrue( !funx(1.0), msg = "as<bool>(1.0) -> true" )
	checkTrue( funx(0.0), msg = "as<bool>0.0) -> false" )
	checkTrue( !funx(as.raw(1)), msg = "as<bool>(aw.raw(1)) -> true" )
	checkTrue( funx(as.raw(0)), msg = "as<bool>(as.raw(0)) -> false" )

	checkException( funx(NULL), msg = "as<bool>(NULL) -> exception" )
	checkException( funx(c(TRUE,FALSE)), msg = "as<bool>(>1 logical) -> exception" )
	checkException( funx(1:2), msg = "as<bool>(>1 integer) -> exception" )
	checkException( funx(1:2+.1), msg = "as<bool>(>1 numeric) -> exception" )
	checkException( funx(as.raw(1:2)), msg = "as<bool>(>1 raw) -> exception" )

	checkException( funx(integer(0)), msg = "as<bool>(0 integer) -> exception" )
	checkException( funx(numeric(0)), msg = "as<bool>(0 numeric) -> exception" )
	checkException( funx(raw(0)), msg = "as<bool>(0 raw) -> exception" )
}

test.RObject.asStdVectorIntResultsSet <- function(){
	funx <- .Rcpp.RObject$asStdVectorIntResultsSet
	foo <- '
		std::vector<int> iv = as<std::vector<int> >( x );
		for (size_t i=0; i<iv.size(); i++) {
    	    iv[i] = 2*iv[i];
    	}
    	RcppResultSet rs;
    	rs.add("", iv);
    	return(rs.getSEXP());'
    funx <- cppfunction(signature(x="numeric"), foo )
	checkEquals( funx(x=2:5), 2:5*2L, msg = "as<std::vector<int> >(integer) via RcppResultSet" )
    checkEquals( funx(x=2:5+.1), 2:5*2L, msg = "as<std::vector<int> >(numeric) via RcppResultSet" )
    checkEquals( funx(x=as.raw(2:5)), 2:5*2L, msg = "as<std::vector<int> >(raw) via RcppResultSet" )
    checkException( funx("foo"), msg = "as<std::vector<int> >(character) -> exception" )
}

test.RObject.asStdVectorInt <- function(){
	funx <- .Rcpp.RObject$asStdVectorInt
    checkEquals( funx(x=2:5), 2:5*2L, msg = "as< std::vector<int> >(integer)" )
    checkEquals( funx(x=2:5+.1), 2:5*2L, msg = "as< std::vector<int> >(numeric)" )
    checkEquals( funx(x=as.raw(2:5)), 2:5*2L, msg = "as< std::vector<int> >(raw)" )
    checkException( funx("foo"), msg = "as< std::vector<int> >(character) -> exception" )
    checkException( funx(NULL), msg = "as< std::vector<int> >(NULL) -> exception" )
}

test.RObject.asStdVectorDouble <- function(){
	funx <- .Rcpp.RObject$asStdVectorDouble
	checkEquals( funx(x=0.1+2:5), 2*(0.1+2:5), msg = "as< std::vector<double> >( numeric )" )
	checkEquals( funx(x=2:5), 2*(2:5), msg = "as< std::vector<double> >(integer)" )
	checkEquals( funx(x=as.raw(2:5)), 2*(2:5), msg = "as< std::vector<double> >(raw)" )
	checkException( funx("foo"), msg = "as< std::vector<double> >(character) -> exception" )
    checkException( funx(NULL), msg = "as< std::vector<double> >(NULL) -> exception" )
}

test.RObject.asStdVectorRaw <- function(){
	funx <- .Rcpp.RObject$asStdVectorRaw
	checkEquals( funx(x=as.raw(0:9)), as.raw(2*(0:9)), msg = "as< std::vector<Rbyte> >(raw)" )
	checkEquals( funx(x=0:9), as.raw(2*(0:9)), msg = "as< std::vector<Rbyte> >( integer )" )
	checkEquals( funx(x=as.numeric(0:9)), as.raw(2*(0:9)), msg = "as< std::vector<Rbyte> >(numeric)" )
	checkException( funx("foo"), msg = "as< std::vector<Rbyte> >(character) -> exception" )
    checkException( funx(NULL), msg = "as< std::vector<Rbyte> >(NULL) -> exception" )

}

test.RObject.asStdVectorBool <- function(){
	funx <- .Rcpp.RObject$asStdVectorBool
	checkEquals( funx(x=c(TRUE,FALSE)), c(FALSE, TRUE), msg = "as< std::vector<bool> >(logical)" )
	checkEquals( funx(x=c(1L, 0L)), c(FALSE, TRUE), msg = "as< std::vector<bool> >(integer)" )
	checkEquals( funx(x=c(1.0, 0.0)), c(FALSE, TRUE), msg = "as< std::vector<bool> >(numeric)" )
	checkEquals( funx(x=as.raw(c(1,0))), c(FALSE, TRUE), msg = "as< std::vector<bool> >(raw)" )
	checkException( funx("foo"), msg = "as< std::vector<bool> >(character) -> exception" )
    checkException( funx(NULL), msg = "as< std::vector<bool> >(NULL) -> exception" )
}

test.RObject.asStdVectorString <- function(){
	funx <- .Rcpp.RObject$asStdVectorString
	checkEquals( funx(c("foo", "bar")), c("foofoo", "barbar"), msg = "as< std::vector<std::string> >(character)" )
	checkException( funx(1L), msg = "as< std::vector<std::string> >(integer) -> exception" )
	checkException( funx(1.0), msg = "as< std::vector<std::string> >(numeric) -> exception" )
	checkException( funx(as.raw(1)), msg = "as< std::vector<std::string> >(raw) -> exception" )
	checkException( funx(TRUE), msg = "as< std::vector<std::string> >(logical) -> exception" )
	checkException( funx(NULL), msg = "as< std::vector<std::string> >(NULL) -> exception" )
}

test.RObject.stdsetint <- function(){
	funx <- .Rcpp.RObject$stdsetint
	checkEquals( funx(), c(0L, 1L), msg = "wrap( set<int> )" )
}

test.RObject.stdsetdouble <- function(){
	funx <- .Rcpp.RObject$stdsetdouble
	checkEquals( funx(), as.numeric(0:1), msg = "wrap( set<double>" )
}

test.RObject.stdsetraw <- function(){
	funx <- .Rcpp.RObject$stdsetraw
	checkEquals( funx(), as.raw(0:1), msg = "wrap(set<raw>)" )
}

test.RObject.stdsetstring <- function(){
	funx <- .Rcpp.RObject$stdsetstring
	checkEquals( funx(), c("bar", "foo"), msg = "wrap(set<string>)" )
}

test.RObject.attributeNames <- function(){
	funx <- .Rcpp.RObject$attributeNames
	checkTrue( all( c("names","row.names","class") %in% funx(iris)), msg = "RObject.attributeNames" )
}

test.RObject.hasAttribute <- function(){
	funx <- .Rcpp.RObject$hasAttribute
	checkTrue( funx( iris ), msg = "RObject.hasAttribute" )
}

test.RObject.attr <- function(){
	funx <- .Rcpp.RObject$attr
	checkEquals( funx( iris ), 1:150, msg = "RObject.attr" )
}

test.RObject.attr.set <- function(){
	funx <- .Rcpp.RObject$attr_set
	checkEquals( attr(funx(), "foo"), 10L, msg = "RObject.attr() = " )
}

test.RObject.isNULL <- function(){
	funx <- .Rcpp.RObject$isNULL
	checkTrue( !funx( iris ), msg = "RObject.isNULL(iris) -> false" )
	checkTrue( funx(NULL), msg = "RObject.isNULL(NULL) -> true" )
	checkTrue( !funx(1L), msg = "RObject.isNULL(integer) -> false" )
	checkTrue( !funx(1.0), msg = "RObject.isNULL(numeric) -> false" )
	checkTrue( !funx(as.raw(1)), msg = "RObject.isNULL(raw) -> false" )
	checkTrue( !funx(letters), msg = "RObject.isNULL(character) -> false")
	checkTrue( !funx(funx), msg = "RObject.isNULL(function) -> false" )
	checkTrue( !funx(.GlobalEnv), msg = "RObject.isNULL(environment) -> false" )
}

