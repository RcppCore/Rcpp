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
    tests <- ".rcpp.misc"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list(
        	"symbol_" = list( 
        		signature(), 
        		'
				SEXP res = PROTECT( Rf_allocVector( LGLSXP, 4) ) ;
				/* SYMSXP */
				LOGICAL(res)[0] = Symbol( Rf_install("foobar") ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
				
				/* CHARSXP */
				LOGICAL(res)[1] = Symbol( Rf_mkChar("foobar") ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
				
				/* STRSXP */
				LOGICAL(res)[2] = Symbol( Rf_mkString("foobar") ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
				
				/* std::string */
				LOGICAL(res)[3] = Symbol( "foobar" ).asSexp() == Rf_install("foobar") ? TRUE : FALSE ;
				
				UNPROTECT(1) ; /* res */
				return res ;
				'
        	), 
        	"symbol_ctor" = list( 
        		signature(x="ANY"), 
        		'return Symbol(x);' 
        	), 
        	"Argument_" = list( 
        		signature(), 
        		'
				Argument x("x");
				Argument y("y");
    			
				return List::create( x = 2, y = 3 );
    			'
        	), 
        	"Dimension_const" = list( 
        	signature( ia = "integer" ), 
        	'
			simple ss(ia);
			return wrap(ss.nrow());
			'
        	)
        )

        signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction(signatures, bodies,
                           plugin = "Rcpp", includes = "
                           
    using namespace std;
                           
	class simple {
	    Rcpp::Dimension dd;
	public:
	    simple(SEXP xp) : dd(xp) {}
	    int nrow() const { return dd[0]; }
	    int ncol() const { return dd[1]; }
	};
	",  cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x",""))
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.Symbol <- function(){
	funx <- .rcpp.misc$symbol_
	res <- funx() 	
	checkTrue( res[1L], msg = "Symbol creation - SYMSXP " )
	checkTrue( res[2L], msg = "Symbol creation - CHARSXP " )
	checkTrue( res[3L], msg = "Symbol creation - STRSXP " )
	checkTrue( res[4L], msg = "Symbol creation - std::string " )
}

test.Symbol.notcompatible <- function(){
	funx <- .rcpp.misc$symbol_ctor
	checkException( funx(funx), msg = "Symbol not compatible with function" )
	checkException( funx(asNamespace("Rcpp")), msg = "Symbol not compatible with environment" )
	checkException( funx(1:10), msg = "Symbol not compatible with integer" )
	checkException( funx(TRUE), msg = "Symbol not compatible with logical" )
	checkException( funx(1.3), msg = "Symbol not compatible with numeric" )
	checkException( funx(as.raw(1) ), msg = "Symbol not compatible with raw" )
}


test.Argument <- function(){
   funx <- .rcpp.misc$Argument_
   checkEquals( funx(), list( x = 2L, y = 3L ) , msg = "Argument")
}

test.Dimension.const <- function(){
	# from the Rcpp-devel thread
	# http://article.gmane.org/gmane.comp.lang.r.rcpp/327
	funx <- .rcpp.misc$Dimension_const
   checkEquals( funx( c(2L, 2L)) , 2L, msg = "testing const operator[]" )
	
}

test.has.iterator <- function(){
	
	classes <- c( "std::vector<int>", "std::list<int>", "std::deque<int>", 
		"std::set<int>", "std::map<std::string,int>", 
		"std::pair<std::string,int>", 
		"Rcpp::Symbol"
		)
	code <- lapply( classes, function(.){
			sprintf( '
			bool ok = Rcpp::traits::has_iterator< %s >::value ;
			return wrap(ok) ;
			', . )
		} )
	signatures <- rep( list(signature()), 7 )
	names( code ) <- names( signatures ) <- sprintf( "runit_has_iterator_%d", 1:7 )
	fx <- cxxfunction( signatures, code, plugin = "Rcpp" )
	
	checkTrue( fx$runit_has_iterator_1() , msg = "has_iterator< std::vector<int> >" )
	checkTrue( fx$runit_has_iterator_2() , msg = "has_iterator< std::ist<int> >" )
	checkTrue( fx$runit_has_iterator_3() , msg = "has_iterator< std::deque<int> >" )
	checkTrue( fx$runit_has_iterator_4() , msg = "has_iterator< std::set<int> >" )
	checkTrue( fx$runit_has_iterator_5() , msg = "has_iterator< std::map<string,int> >" )
	
	checkTrue( ! fx$runit_has_iterator_6(), msg = "has_iterator< std::pair<string,int> >" )
	checkTrue( ! fx$runit_has_iterator_7(), msg = "Rcpp::Symbol" )
	
}

