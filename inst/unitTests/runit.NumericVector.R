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
    tests <- ".rcpp.NumericVector"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list(
        	"numeric_" = list( 
        		signature(),
        		'
				NumericVector x(10) ;
				for( int i=0; i<10; i++) x[i] = i ;
				return x ;
				'
        	), 
        	"numeric_REALSXP" = list( 
        		signature(vec = "numeric" ), 
        		'
				NumericVector x(vec) ;
				for( int i=0; i<x.size(); i++) { 
					x[i] = x[i]*2.0 ;
				}
				return x ;
				'	
        	), 
        	"numeric_import" = list( 
        		signature(), 
        		'
					std::vector<int> v(10) ;
					for( int i=0; i<10; i++) v[i] = i ;
					
					return IntegerVector::import( v.begin(), v.end() ) ;
				
				'
        	), 
        	"numeric_importtransform" = list( 
        		signature(), 
        		'
					std::vector<double> v(10) ;
					for( int i=0; i<10; i++) v[i] = i ;
					
					return NumericVector::import_transform( v.begin(), v.end(), square ) ;
				
				'
        	)
        )
        
        if( Rcpp:::capabilities()[["initializer lists"]] ){
        	g <- list( 
        		"numeric_initlist" = list( 
        			signature(), 
        			'
						NumericVector x = {0.0,1.0,2.0,3.0} ;
						for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
						return x ;
					'
        		)
        	)
        	f <- c(f,g)
        }

       signatures <- lapply(f, "[[", 1L)
        bodies <- lapply(f, "[[", 2L)
        fun <- cxxfunction(signatures, bodies,
                           plugin = "Rcpp", 
                           includes = "
                           using namespace std; 
                           inline double square( double x){ return x*x; }
                           ",
                           cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x","") 
                           )
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.NumericVector <- function(){
	funx <- .rcpp.NumericVector$numeric_
	checkEquals( funx(), as.numeric(0:9), msg = "NumericVector(int)" )
}

test.NumericVector.REALSXP <- function(){
	funx <- .rcpp.NumericVector$numeric_REALSXP
	checkEquals( funx(as.numeric(0:9)), 2*0:9, msg = "NumericVector( REALSXP) " )
}

if( Rcpp:::capabilities()[["initializer lists"]] ){
	test.NumericVector.initializer.list <- function(){
		funx <- .rcpp.NumericVector$numeric_initlist
		checkEquals( funx(), as.numeric(2*0:3), msg = "NumericVector( initializer list) " )
	}
}

test.NumericVector.import <- function(){
	funx <- .rcpp.NumericVector$numeric_import
	checkEquals( funx(), 0:9, msg = "IntegerVector::import" ) 
}

test.NumericVector.import.transform <- function(){
	funx <- .rcpp.NumericVector$numeric_importtransform
	checkEquals( funx(), (0:9)^2, msg = "NumericVector::import_transform" )
}

