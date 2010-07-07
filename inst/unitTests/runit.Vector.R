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
    tests <- ".rcpp.Vector"
    if( ! exists( tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list(
        	"raw_" = list( 
        		signature(), 
        		'
				RawVector x(10) ;
				for( int i=0; i<10; i++) x[i] = (Rbyte)i ;
				return x ;
				'
        	), 
        	"raw_REALSXP" = list( 
        		signature(vec = "raw" ),
        		'
				RawVector x(vec) ;
				for( int i=0; i<x.size(); i++) { 
					x[i] = x[i]*2 ;
				}
				return x ;
				'
        	), 
        	"expression_" = list( 
        		signature(), 
        		'
				ExpressionVector x(2) ;
				x[0] = Symbol( "rnorm" ) ;
				x[1] = Rf_lcons( Symbol("rnorm"), Rf_cons( Rf_ScalarReal(10.0), R_NilValue) ) ;
				return x ;
				'
        	), 
        	"expression_variadic" = list( 
        		signature(), 
        		'
				ExpressionVector x(2) ;
				x[0] = Symbol( "rnorm" ) ;
				x[1] = Language( "rnorm", 10.0 ) ;
				return x ;
				'
        	), 
        	"expression_parse" = list( 
        		signature(), 
        		'
					ExpressionVector code( "local( { y <- sample(1:10); sort(y) })" ) ;
					return code ;
				'
        	), 
        	"expression_parseerror" = list( 
        		signature(), 
        		'
					ExpressionVector code( "rnorm(" ) ;
					return code ;
				'
        	), 
        	"expression_eval" = list( 
        		signature(), 
        		'
				ExpressionVector code( "local( { y <- sample(1:10); sort(y) })" ) ;
				return code.eval() ;
				'
        	), 
        	"expression_evalenv" = list( 
        		signature(env = "environment"), 
        		'
				ExpressionVector code( "sort(x)" ) ;
				return code.eval(env) ;
				' 
        	), 
        	"complex_" = list( 
        		signature(), 
        		'
				ComplexVector x(10) ;
				Rcomplex rc ;
				for( int i=0; i<10; i++) {
					rc.r = rc.i = i + 0.0 ;
					x[i] = rc ;
				}
				return x ;
				'
        	), 
        	"complex_INTSXP" = list( 
        		signature(vec = "complex" ), 
        		'
				ComplexVector x(vec) ;
				for( int i=0; i<x.size(); i++) { 
					x[i].r = x[i].r*2 ;
					x[i].i = x[i].i*2 ;
				}
				return x ;
				'
        	), 
        	
        	
        	
        	
        	"integer_ctor"=list(
                  signature(),
                  'IntegerVector x(10) ;
	           for( int i=0; i<10; i++) x[i] = i ;
	           return x ;')

                  ,"integer_INTSXP_"=list(
                   signature(vec = "integer" ),
                   'IntegerVector x(vec) ;
	            for( int i=0; i<x.size(); i++) {
		       x[i] = x[i]*2 ;
	            }
	            return x ;')

                  ,"integer_matrix_indexing"=list(
                   signature(x = "integer" ),
                   'IntegerVector m(x) ;
		    int trace = 0.0 ;
		    for( size_t i=0 ; i<4; i++){
		        trace += m(i,i) ;
		    }
		    return wrap( trace ) ;')

                  ,"integer_matrix_indexing_lhs"=list(
                   signature(x = "integer" ),
                   'IntegerVector m(x) ;
		    for( size_t i=0 ; i<4; i++){
		        m(i,i) = 2 * i ;
		    }
		    return m ; ')

                  ,"integer_dimension_ctor_1"=list(
                   signature(),
                   'return IntegerVector( Dimension( 5 ) ) ;')

                  ,"integer_dimension_ctor_2"=list(
                   signature(),
                   'return IntegerVector( Dimension( 5, 5 ) ) ;')

                  ,"integer_dimension_ctor_3"=list(
                   signature(),
                   'return IntegerVector( Dimension( 2, 3, 4) ) ;')

                  ,"integer_range_ctor_1"=list(
                   signature(),
                   'int x[] = { 0, 1, 2, 3 } ;
		    IntegerVector y( x, x+4 ) ;
		    return y; ')

                  ,"integer_range_ctor_2"=list(
                   signature(),
                   'std::vector<int> vec(4) ;
		    for( size_t i = 0; i<4; i++) vec[i] = i;
		    IntegerVector y( vec.begin(), vec.end() ) ;
		    return y;')

                  ,"integer_names_set"=list(
                   signature(),
                   'IntegerVector y(2) ;
		    std::vector<std::string> names(2)  ;
		    names[0] = "foo" ;
		    names[1] = "bar" ;
		    y.names() = names ;
		    return y ; ')

                  ,"integer_names_get"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
		    return y.names() ;')

                  ,"integer_names_indexing"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
		    return wrap( y["foo"] ); ')

                  ,"integer_comma"=list(
                   signature(),
                   'IntegerVector x(4) ;
	            x = 0, 1, 2, 3 ;
	            return x ;')

                  ,"integer_push_back"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.push_back( 5 ) ;
	            return y ;')

                  ,"integer_push_front"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.push_front( 5 ) ;
	            return y ;')

                  ,"integer_insert"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.insert( 0, 5 ) ;
	            y.insert( 2, 7 ) ;
	            return y ;')

                  ,"integer_erase"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.erase(2) ;
	            return y ;')

                  ,"integer_erase2"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.erase(1,2) ;
	            return y ;')

                  ,"integer_fill"=list(
                   signature(x = "integer"),
                   'IntegerVector y(x) ;
	            y.fill(10) ;
	            return y ;' )

                  ,"integer_zero"=list(
                   signature(),
                   'return IntegerVector(0);' )

                  ,"integer_create_zero"=list(
                   signature(),
                   'return IntegerVector::create();'
                  ), 
                  "integer_create_" = list( 
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
                  "integer_clone_" = list( 
                  signature(x="integer"), 
                  '
					IntegerVector vec(x) ;
					IntegerVector dolly = clone( vec ) ;
					for( size_t i=0; i<10; i++){
						dolly[i] = 10 - i ;
					}
					return dolly ;
					'
                  ) , 
                  
                  
                  
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

        if (Rcpp:::capabilities()[["initializer lists"]]) {
        	g <- list( 
        		"raw_initializer_list"=list(
        			signature(), 
        			'
					RawVector x = {0,1,2,3} ;
					for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
					return x ;
					'
        		), 
        		"complex_initializer_list" = list( 
        			signature(), 
        			'
					Rcomplex c1 ; c1.r = c1.i = 0.0 ;
					Rcomplex c2 ; c2.r = c2.i = 1.0 ;
					ComplexVector x = { c1, c2 } ;
					return x ;
					'
        		), 
        		"integer_initializer_list"=list(
                  	signature(),
                  	'
                  		IntegerVector x = {0,1,2,3} ;
		   				for( int i=0; i<x.size(); i++) x[i] = x[i]*2 ;
		   				return x ;
		   			'
		   		), 
		   		
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
                           plugin = "Rcpp", includes = "
                           using namespace std;
                           inline double square( double x){ return x*x; }
                           ",
                           cxxargs = ifelse(Rcpp:::capabilities()[["initializer lists"]],"-std=c++0x",""))
        getDynLib( fun ) # just forcing loading the dll now
        assign( tests, fun, globalenv() )
    }
}

test.RawVector <- function(){
	funx <- .rcpp.Vector$raw_
	checkEquals( funx(), as.raw(0:9), msg = "RawVector(int)" )
}

test.RawVector.REALSXP <- function(){
	funx <- .rcpp.Vector$raw_REALSXP
	checkEquals( funx(as.raw(0:9)), as.raw(2*0:9), msg = "RawVector( RAWSXP) " )
}

if( Rcpp:::capabilities()[["initializer lists"]] ){
	test.RawVector.initializer.list <- function(){
		funx <- .rcpp.Vector$raw_initializer_list
		checkEquals( funx(), as.raw(2*0:3), msg = "RawVector( initializer list) " )
	}
}

test.ExpressionVector <- function(){
	funx <- .rcpp.Vector$expression_
	ex <- parse( text = "rnorm; rnorm(10)" )
	# get rid of the srcref stuff so that we can compare
	# more easily
	attributes(ex) <- NULL 
	checkEquals( funx(),  ex , msg = "ExpressionVector" )
}

test.ExpressionVector.variadic <- function(){
	funx <- .rcpp.Vector$expression_variadic
	ex <- parse( text = "rnorm; rnorm(10)" )
	attributes(ex) <- NULL
	checkEquals( funx(),  ex , msg = "ExpressionVector (using variadic templates) " )
}

test.ExpressionVector.parse <- function( ){
	funx <- .rcpp.Vector$expression_parse
	code <- funx()
	results <- eval( code )
	checkEquals( results, 1:10, msg = "ExpressionVector parsing" )
}

test.ExpressionVector.parse.error <- function(){
	funx <- .rcpp.Vector$expression_parseerror
	checkException( funx(), msg = "parse error" )
}

test.ExpressionVector.eval <- function(){
	funx <- .rcpp.Vector$expression_eval
	checkEquals( funx(), 1:10, msg = "ExpressionVector::eval" )
}

test.ExpressionVector.eval.env <- function(){
	funx <- .rcpp.Vector$expression_evalenv
	e <- new.env()
	e[["x"]] <- sample(1:10)
	checkEquals( funx(e), 1:10, msg = "ExpressionVector::eval in specific environment" )
}
         
test.ComplexVector <- function(){
	funx <- .rcpp.Vector$complex_
	checkEquals( funx(), 0:9*(1+1i), msg = "ComplexVector" )
}

test.ComplexVector.INTSXP <- function(){
	funx <- .rcpp.Vector$complex_INTSXP
	checkEquals( funx(0:9*(1+1i)), 2*0:9*(1+1i), msg = "ComplexVector( CPLXSXP) " )
}
if( Rcpp:::capabilities()[["initializer lists"]] ){
	test.ComplexVector.initializer.list <- function(){
		funx <- .rcpp.Vector$complex_initializer_list
		checkEquals( funx(), c( 0:1*(1+1i)), msg = "ComplexVector( initializer list) " )
	}
}





test.IntegerVector <- function(){
    fun <- .rcpp.Vector$integer_ctor
    checkEquals( fun(), 0:9, msg = "IntegerVector" )
}

test.IntegerVector.INTSXP_ <- function(){
    fun <- .rcpp.Vector$integer_INTSXP
    checkEquals( fun(0:9), 2*0:9, msg = "IntegerVector( INTSXP) " )
}

if (Rcpp:::capabilities()[["initializer lists"]]) {
    test.IntegerVector.initializer.list <- function() {
        fun <- .rcpp.Vector$integer_initializer_list
        checkEquals( fun(), 2*0:3, msg = "IntegerVector( initializer list) " )
    }
}

test.IntegerVector.matrix.indexing <- function(){
    fun <- .rcpp.Vector$integer_matrix_indexing
    x <- matrix( 1:16, ncol = 4 )
    checkEquals( fun(x), sum(diag(x)), msg = "matrix indexing" )

    fun <- .rcpp.Vector$integer_matrix_indexing_lhs
    checkEquals( diag(fun(x)), 2*0:3, msg = "matrix indexing lhs" )

    y <- as.vector( x )
    checkException( fun(y) , msg = "not a matrix" )
}

test.IntegerVector.Dimension.constructor <- function(){
    fun <- .rcpp.Vector$integer_dimension_ctor_1
    checkEquals(fun(),
                integer(5) ,
                msg = "IntegerVector( Dimension(5))" )

    fun <- .rcpp.Vector$integer_dimension_ctor_2
    checkEquals(fun(),
                matrix( 0L, ncol = 5, nrow = 5) ,
                msg = "IntegerVector( Dimension(5,5))" )

    fun <- .rcpp.Vector$integer_dimension_ctor_3
    checkEquals(fun(),
		array( 0L, dim = c(2,3,4) ) ,
		msg = "IntegerVector( Dimension(2,3,4))" )
}

test.IntegerVector.range.constructors <- function(){
    fun <- .rcpp.Vector$integer_range_ctor_1
    checkEquals( fun(), 0:3, msg = "assign(int*, int*)" )

    fun <- .rcpp.Vector$integer_range_ctor_2
    checkEquals( fun(), 0:3, msg = "assign(int*, int*)" )
}

test.IntegerVector.names.set <- function(){
    fun <- .rcpp.Vector$integer_names_set
    checkEquals(names(fun()), c("foo", "bar"), msg = "Vector::names" )
}

test.IntegerVector.names.get <- function(){
    fun <- .rcpp.Vector$integer_names_get
    checkEquals(fun( c("foo" = 1L, "bar" = 2L) ),
                c("foo", "bar"),
		msg = "Vector::names get" )
}

test.IntegerVector.names.indexing <- function(){
    fun <- .rcpp.Vector$integer_names_indexing
    x <- c( "foo" = 1L, "bar" = 2L )
    checkEquals( fun( x ), 1L, msg = "IntegerVector names based indexing" )
}

test.IntegerVector.comma <- function(){
    fun <- .rcpp.Vector$integer_comma
    checkEquals( fun(), 0:3, msg = "IntegerVector comma initialization" )
}

test.IntegerVector.push.back <- function(){
    fun <- .rcpp.Vector$integer_push_back
    checkEquals( fun(1:4), 1:5, msg = "IntegerVector push back" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- 1:5
    names(target) <- c( letters[1:4], "")
    checkEquals( fun(x), target, msg = "IntegerVector push back names" )
}

test.IntegerVector.push.front <- function(){
    fun <- .rcpp.Vector$integer_push_front
    checkEquals( fun(1:4), c(5L,1:4), msg = "IntegerVector push front" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c( 5L, 1:4 )
    names(target) <- c( "", letters[1:4])

    checkEquals( fun(x), target, msg = "IntegerVector push front names" )
}

test.IntegerVector.insert <- function(){
    fun <- .rcpp.Vector$integer_insert
    checkEquals( fun(1:4), c(5L,1L, 7L, 2:4), msg = "IntegerVector insert" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c( 5L, 1L, 7L, 2:4 )
    names(target) <- c( "", "a", "", letters[2:4])

    checkEquals( fun(x), target, msg = "IntegerVector insert names" )
}

test.IntegerVector.erase <- function(){
    fun <- .rcpp.Vector$integer_erase
    checkEquals( fun(1:4), c(1L, 2L, 4L), msg = "IntegerVector erase" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c(1L, 2L, 4L)
    names(target) <- c( "a", "b", "d" )

    checkEquals( fun(x), target, msg = "IntegerVector erase" )
}

test.IntegerVector.erase2 <- function(){
    fun <- .rcpp.Vector$integer_erase2
    checkEquals( fun(1:4), c(1L, 4L), msg = "IntegerVector erase2" )

    x <- 1:4
    names(x) <- letters[1:4]

    target <- c(1L, 4L)
    names(target) <- c( "a", "d" )

    checkEquals( fun(x), target, msg = "IntegerVector erase2" )
}

test.IntegerVector.fill <- function(){
    fun <- .rcpp.Vector$integer_fill
    x <- 1:10
    checkEquals( fun(x), rep(10L, 10 ), msg = "IntegerVector.fill" )
}

test.IntegerVector.zero <- function( ){
    fun <- .rcpp.Vector$integer_zero
    checkEquals( fun(), integer(0), msg = "IntegerVector(0)" )
}

test.IntegerVector.create.zero <- function( ){
    fun <- .rcpp.Vector$integer_create_zero
    checkEquals( fun(), integer(0), msg = "IntegerVector::create()" )
}

test.IntegerVector.create <- function(){
    fun <- .rcpp.Vector$integer_create_
	checkEquals( fun(), list( c( 10L, 20L) , c(foo = 20L, bar = 30L) ), 
		msg = "IntegerVector::create" )
}

test.IntegerVector.clone <- function(){
	x <- 1:10
	fun <- .rcpp.Vector$integer_clone_
	y <- fun(x)
	checkEquals( x, 1:10, msg = "clone" )
	checkEquals( y, 10:1, msg = "clone" )
}
          




test.NumericVector <- function(){
	funx <- .rcpp.Vector$numeric_
	checkEquals( funx(), as.numeric(0:9), msg = "NumericVector(int)" )
}

test.NumericVector.REALSXP <- function(){
	funx <- .rcpp.Vector$numeric_REALSXP
	checkEquals( funx(as.numeric(0:9)), 2*0:9, msg = "NumericVector( REALSXP) " )
}

if( Rcpp:::capabilities()[["initializer lists"]] ){
	test.NumericVector.initializer.list <- function(){
		funx <- .rcpp.Vector$numeric_initlist
		checkEquals( funx(), as.numeric(2*0:3), msg = "NumericVector( initializer list) " )
	}
}

test.NumericVector.import <- function(){
	funx <- .rcpp.Vector$numeric_import
	checkEquals( funx(), 0:9, msg = "IntegerVector::import" ) 
}

test.NumericVector.import.transform <- function(){
	funx <- .rcpp.Vector$numeric_importtransform
	checkEquals( funx(), (0:9)^2, msg = "NumericVector::import_transform" )
}

