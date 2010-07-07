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
        	)  , 
        	
        	
        	
        	
        	
        	"list_ctor"=list(
                  signature(),
                  'List x(10) ;
	           for( int i=0; i<10; i++) x[i] = Rf_ScalarInteger( i * 2)  ;
	           return x ;')

                  ,"list_template_"=list(
                   signature(),
                   'List x(4) ;
	            x[0] = "foo"  ;
	            x[1] = 10 ;
	            x[2] = 10.2 ;
	            x[3] = false;
	            return x ;')

                  ,"list_VECSXP_"=list(
                   signature(vec = "list" ),
                   'List x(vec) ;
                    return x ;')

                  ,"list_matrix_indexing_1"=list(
                   signature(x = "character" ),
                   'GenericVector m(x) ;
		    GenericVector out(4) ;
		    for( size_t i=0 ; i<4; i++){
		        out[i] = m(i,i) ;
		    }
		    return out ;')

                  ,"list_matrix_indexing_2"=list(
                   signature(x = "integer" ),
                   'GenericVector m(x) ;
		    for(size_t i=0 ; i<4; i++){
		        m(i,i) = "foo" ;
		    }
		    return m ; ')

                  ,"list_Dimension_constructor_1"=list(
                   signature(),
                   'return List( Dimension( 5 ) ) ;')

                  ,"list_Dimension_constructor_2"=list(
                   signature(),
                   'return List( Dimension( 5, 5 ) );')

                  ,"list_Dimension_constructor_3"=list(
                   signature(),
                   ' return List( Dimension( 2, 3, 4) ) ;')

                  ,"list_iterator_"=list(
                   signature(x = "list", g = "function" ),
                   'Function fun(g) ;
		    List input(x) ;
		    List output( input.size() ) ;
		    std::transform( input.begin(), input.end(), output.begin(), fun ) ;
		    output.names() = input.names() ;
		    return output ; ')

                  ,"list_name_indexing"=list(
                   signature(x = "data.frame"),
                   'List df(x) ;
	            IntegerVector df_x = df["x"] ;
	            int res = std::accumulate( df_x.begin(), df_x.end(), 0 ) ;
	            return wrap(res); ')

                  ,"list_push_back"=list(
                   signature(x = "list"),
                   'List list(x) ;
	            list.push_back( 10 ) ;
	            list.push_back( "bar", "foo" ) ;
	            return list ;
	           ')

                  ,"list_push_front"=list(
                   signature(x = "list"),
                   'List list(x) ;
	            list.push_front( 10 ) ;
	            list.push_front( "bar", "foo" ) ;
	            return list ; ')

                  ,"list_erase"=list(
                   signature(x = "list"),
                   'List list(x) ;
	            list.erase( list.begin() ) ;
	            return list ; ')

                  ,"list_erase_range"=list(
                   signature(x = "list"),
	           'List list(x) ;
	            list.erase( 0, 1 ) ;
	            return list ; ')

                  ,"list_implicit_push_back"=list(
                   signature(),
                   'List list ;
                    list["foo"] = 10 ;
                    list["bar" ] = "foobar" ;
                    return list ;
                   '), 
              "list_create_" = list( 
              	signature(), 
              	'
					List output(2); 
					output[0] = List::create( 10, "foo" ) ;
					output[1] = List::create( 
						_["foo"] = 10, 
						_["bar"] = true ) ;
					return output ;
				'
              ), 
              "list_stdcomplex" = list( 
              		signature() , '
              			std::vector< std::complex<double> > v_double(10) ;
    					std::vector< std::complex<float> > v_float(10) ;
    					return List::create( _["float"] = v_float, _["double"] = v_double ) ;
    				'
    			), 
    			
    			
    			
    			
              "character_ctor"=list(
                  signature(),
                  'CharacterVector x(10) ;
	           for( int i=0; i<10; i++) x[i] = "foo" ;
	           return x ;')

                  ,"character_STRSXP_"=list(
                   signature(vec = "character" ),
                   'CharacterVector x(vec) ;
	            std::string st = "" ;
	            for( int i=0; i<x.size(); i++) {
		         st += x[i] ;
	            }
	            return wrap( st ) ;' )

                  ,"character_plusequals"=list(
                   signature(),
                   'CharacterVector x(2) ;
	            x[0] = "foo" ;
	            x[1] = "bar" ;
	            x[0] += "bar" ;
	            x[1] += x[0] ;
	            return x ;')

                  ,"character_matrix_indexing"=list(
                   signature(x = "character" ),
                   'CharacterVector m(x) ;
		    std::string trace;
		    for( size_t i=0 ; i<4; i++){
		        trace += m(i,i) ;
		    }
		    return wrap( trace ) ;')

                  ,"character_matrix_indexing_lhs"=list(
                   signature(x = "integer" ),
                   'CharacterVector m(x) ;
		    for( size_t i=0 ; i<4; i++){
		        m(i,i) = "foo" ;
		    }
		    return m ;')

                  ,"character_assign1"=list(
                   signature(),
                   'const char* x[] = { "foo", "bar", "bling", "boom" } ;
		    CharacterVector y ;
		    y.assign( x, x+4 ) ;
		    return y;')

                  ,"character_assign2"=list(
                   signature(),
                   'std::vector<std::string> vec(4) ;
		    vec[0] = "foo";
		    vec[1] = "bar";
		    vec[2] = "bling";
		    vec[3] = "boom" ;
		    CharacterVector y ;
		    y.assign( vec.begin(), vec.end() ) ;
		    return y;')

                  ,"character_range_ctor1"=list(
                   signature(),
                   'const char* x[] = { "foo", "bar", "bling", "boom" } ;
		    CharacterVector y( x, x+4 ) ;
		    return y;')

                  ,"character_range_ctor2"=list(
                   signature(),
                   'std::vector<std::string> vec(4) ;
		    vec[0] = "foo";
		    vec[1] = "bar";
		    vec[2] = "bling";
		    vec[3] = "boom" ;
		    CharacterVector y( vec.begin(), vec.end() ) ;
		    return y; ')

                  ,"character_dimension_ctor1"=list(
                   signature(),
                   'return CharacterVector( Dimension( 5 ) ) ;')

                  ,"character_dimension_ctor2"=list(
                   signature(),
                   'return CharacterVector( Dimension( 5, 5 ) ) ;')

                  ,"character_dimension_ctor3"=list(
                   signature(),
                   'return CharacterVector( Dimension( 2, 3, 4) ) ;')

                  ,"character_iterator1"=list(
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

                  ,"character_iterator2"=list(
                   signature(x = "character"),
                   'CharacterVector letters(x) ;
		    std::string res(std::accumulate(letters.begin(), letters.end(), std::string()));
		    return wrap(res) ;' )

                  ,"character_reverse"=list(
                   signature(x = "character"),
                   'CharacterVector y(x) ;
		    std::reverse( y.begin(), y.end() ) ;
		    return y ;')

                  ,"character_names_indexing"=list(
                   signature(x = "character"),
                   'CharacterVector y(x) ;
		    std::string foo( y["foo"] ) ;
		    return wrap(foo) ;')

                  ,"character_comma"=list(
                   signature(),
                   'CharacterVector x(3) ;
        	    x = "foo", "bar", "bling" ;
        	    return x ;')

                  ,"character_listOf"=list(
                   signature(l = "list"),
                   'List ll(l);
                    CharacterVector cv1 = ll["foo"];
                    CharacterVector cv2 = ll["bar"];
                    std::string rv1 = std::string(cv1[0]) + cv1[1] + cv1[2];
                    std::string rv2 = std::string(cv2[0]) + cv2[1] + cv2[2];
                    return List::create(_["foo"] = rv1, _["bar"] = rv2); ')

                  ,"character_find_"=list(
                   signature(x = "character"),
                   'CharacterVector y(x) ;
	            CharacterVector::iterator it = std::find( y.begin(), y.end(), "foo" ) ;
	            return wrap( std::distance( y.begin(), it )); '
	            
	            ), "character_create_" = list( 
	            	signature(), 
	            	'
						List output(2); 
						output[0] = CharacterVector::create( "foo", "bar" ) ;
						output[1] = CharacterVector::create( 
							_["foo"] = "bar", 
							_["bar"] = "foo"
							) ;
						return output ;
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
        		), 
        		
        		"list_initializer_list"=list(
                  signature(),
                  'SEXP x0 = PROTECT( Rf_ScalarInteger( 0 ) ) ;
		   			SEXP x1 = PROTECT( Rf_ScalarInteger( 1 ) ) ;
		   			SEXP x2 = PROTECT( Rf_ScalarInteger( 2 ) ) ;
		   			List x = { x0, x1, x2} ;
		   			UNPROTECT(3) ;
		   			return x ;'), 
		   			
		   		"character_initializer_list"=list(
                  signature(),
                  'CharacterVector x = {"foo", "bar"} ;
                  return x ;')

                  
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
         




test.List <- function(){
    fun <- .rcpp.Vector$list_ctor
    checkEquals( fun(), as.list( 2*0:9), msg = "GenericVector" )
}

test.List.template <- function(){
    fun <- .rcpp.Vector$list_template_
    checkEquals(fun(), list( "foo", 10L, 10.2, FALSE), msg = "GenericVector" )
}

test.List.VECSXP <- function(){
    fun <- .rcpp.Vector$list_VECSXP_
    checkEquals( fun(list(1,2)), list(1,2), msg = "GenericVector( VECSXP) " )
}

if( Rcpp:::capabilities()[["initializer lists"]] ){
    test.List.initializer.list <- function(){
        fun <- .rcpp.Vector$list_initializer_list
        checkEquals( fun(), as.list(0:2), msg = "List( initializer list) " )
    }
}

test.List.matrix.indexing <- function(){
    fun <- .rcpp.Vector$list_matrix_indexing_1
    ## a matrix of integer vectors
    x <- structure( lapply( 1:16, function(x) seq.int(x) ), dim = c( 4, 4) )
    checkEquals( fun(x), diag(x), msg = "matrix indexing 1" )

    fun <- .rcpp.Vector$list_matrix_indexing_2
    checkEquals(diag(fun(x)), rep(list("foo"), 4) , msg = "matrix indexing lhs" )

    ## drop dimensions
    dim(x) <- NULL
    checkException( fun(x) , msg = "not a matrix" )
}

test.List.Dimension.constructor <- function(){
    fun <- .rcpp.Vector$list_Dimension_constructor_1
    checkEquals(fun(),
		rep(list(NULL),5) ,
                msg = "List( Dimension(5))" )

    fun <- .rcpp.Vector$list_Dimension_constructor_2
    checkEquals(fun(),
		structure( rep( list(NULL), 25), dim = c(5,5) ),
		msg = "List( Dimension(5,5))" )

    fun <- .rcpp.Vector$list_Dimension_constructor_3
    checkEquals(fun(),
		array( rep(list(NULL)), dim = c(2,3,4) ) ,
		msg = "List( Dimension(2,3,4))" )
}

test.List.iterator <- function() {
    fun <- .rcpp.Vector$list_iterator_
    data <- list( x = letters, y = LETTERS, z = 1:4 )
    checkEquals(fun( data, length ),
		list( x = 26L, y = 26L, z = 4L),
		msg = "c++ version of lapply" )
}

test.List.name.indexing <- function(){
    fun <- .rcpp.Vector$list_name_indexing
    d <- data.frame( x = 1:10, y = letters[1:10] )
    checkEquals( fun( d ), sum(1:10), msg = "List names based indexing" )
}

test.List.push.back <- function(){
    fun <- .rcpp.Vector$list_push_back
    d <- list( x = 1:10, y = letters[1:10] )
    checkEquals(fun( d ),
		list( x = 1:10, y = letters[1:10], 10L, foo = "bar" ),
		msg = "List.push_back" )
}

test.List.push.front <- function(){
    fun <- .rcpp.Vector$list_push_front
    d <- list( x = 1:10, y = letters[1:10] )
    checkEquals(fun(d),
		list( foo = "bar", 10L, x = 1:10, y = letters[1:10] ),
		msg = "List.push_front" )
}

# test.List.insert <- function(){
#
# 	funx <- cppfunction( signature(x = "list"),
# 	'
# 	List list(x) ;
# 	list.insert( list.begin(), 10 ) ;
# 	list.insert( list.end(), Named("foo", "bar" ) ) ;
# 	return list ;
# 	' )
# 	d <- list( x = 1:10, y = letters[1:10] )
# 	res <- funx( d )
# 	checkEquals( res,
# 		list( 10L, x = 1:10, y = letters[1:10], foo = "bar" ),
# 		msg = "List.insert" )
# }

test.List.erase <- function(){
    fun <- .rcpp.Vector$list_erase
    d <- list( x = 1:10, y = letters[1:10] )
    checkEquals(fun(d),
		list( y = letters[1:10] ),
		msg = "List.erase" )
}

test.List.erase.range <- function(){
    fun <- .rcpp.Vector$list_erase_range
    d <- list( x = 1:10, y = letters[1:10], z = 1:10 )
    checkEquals(fun(d),
		list( z = 1:10 ),
		msg = "List.erase (range version)" )
}

test.List.implicit.push.back <- function(){
    fun <- .rcpp.Vector$list_implicit_push_back
    checkEquals( fun(), list( foo = 10, bar = "foobar" ), msg = "List implicit push back" )
}

test.List.create <- function(){
	fun <- .rcpp.Vector$list_create_
    checkEquals( fun(), list( list( 10L, "foo" ), list(foo = 10L, bar =  TRUE ) ), 
		msg = "List::create" )
}

test.List.stdcomplex <- function(){
	fun <- .rcpp.Vector$list_stdcomplex
    checkEquals( 
		fun(), 
		list( float = rep(0+0i, 10), double = rep(0+0i, 10) ), 
		msg = "range wrap over std::complex" )
}
           




test.CharacterVector <- function(){
    fun <- .rcpp.Vector$character_ctor
    checkEquals( fun(), rep("foo",10L), msg = "CharacterVector" )
}

test.CharacterVector.STRSXP <- function(){
    fun <- .rcpp.Vector$character_STRSXP_
    checkEquals( fun(letters), paste(letters,collapse="" ), msg = "CharacterVector( STRSXP) " )
}

if (Rcpp:::capabilities()[["initializer lists"]]) {
    test.CharacterVector.initializer.list <- function() {
        fun <- .rcpp.Vector$character_initializer_list
        checkEquals( fun(), c("foo","bar"), msg = "CharacterVector( initializer list) " )
    }
}

test.CharacterVector.plusequals <- function(){
    fun <- .rcpp.Vector$character_plusequals
    checkEquals( fun(), c("foobar", "barfoobar"), msg = "StringProxy::operator+=" )
}

test.CharacterVector.matrix.indexing <- function() {
    fun <- .rcpp.Vector$character_matrix_indexing
    x <- matrix( as.character(1:16), ncol = 4 )
    checkEquals( fun(x), paste(diag(x), collapse = ""), msg = "matrix indexing" )

    y <- as.vector( x )
    checkException( fun(y) , msg = "not a matrix" )

    fun <- .rcpp.Vector$character_matrix_indexing_lhs
    checkEquals( diag(fun(x)), rep("foo", 4) , msg = "matrix indexing lhs" )
}

test.CharacterVector.assign <- function(){
    fun <- .rcpp.Vector$character_assign1
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )

    fun <- .rcpp.Vector$character_assign2
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )

}

test.CharacterVector.range.constructors <- function(){
    fun <- .rcpp.Vector$character_range_ctor1
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )

    fun <- .rcpp.Vector$character_range_ctor2
    checkEquals( fun(), c("foo", "bar", "bling", "boom"), msg = "assign(char**, char**)" )
}

test.CharacterVector.Dimension.constructor <- function(){
    fun <- .rcpp.Vector$character_dimension_ctor1
    checkEquals(fun(),
                character(5),
                msg = "CharacterVector( Dimension(5))" )

    fun <- .rcpp.Vector$character_dimension_ctor2
    checkEquals(fun(),
                matrix( "", ncol = 5, nrow = 5),
                msg = "CharacterVector( Dimension(5,5))" )

    fun <- .rcpp.Vector$character_dimension_ctor3
    checkEquals(fun(),
		array( "", dim = c(2,3,4) ) ,
		msg = "CharacterVector( Dimension(2,3,4))" )
}

test.CharacterVector.iterator <- function(){
    fun <- .rcpp.Vector$character_iterator1
    checkEquals(fun(letters),
		paste(letters, collapse=""),
		msg = "CharacterVector::iterator explicit looping" )

    fun <- .rcpp.Vector$character_iterator2
    checkEquals(fun(letters),
		paste(letters, collapse=""),
		msg = "CharacterVector::iterator using std::accumulate" )
}

test.CharacterVector.reverse <- function(){
    fun <- .rcpp.Vector$character_reverse
    x <- c("foo", "bar", "bling")
    x <- fun(x)
    checkEquals( x, c("bling", "bar", "foo"), msg = "reverse" )
    x <- fun(x)
    checkEquals( x, c("foo", "bar", "bling"), msg = "reverse" )
}

test.CharacterVector.names.indexing <- function(){
    fun <- .rcpp.Vector$character_names_indexing
    x <- c( foo = "foo", bar = "bar" )
    checkEquals( fun(x), "foo", msg = "CharacterVector names based indexing" )
}

test.CharacterVector.comma <- function(){
    fun <- .rcpp.Vector$character_comma
    checkEquals( fun(), c("foo","bar", "bling" ), msg = "CharacterVector comma operator" )
}

test.CharacterVector.listOf <- function() {
    fun <- .rcpp.Vector$character_listOf
    checkEquals(fun(list(foo=c("tic","tac","toe"),
                         bar=c("Eenie","Meenie","Moe"))),
                list(foo="tictactoe", bar="EenieMeenieMoe"),
                msg="CharacterVector from list")
}

test.CharacterVector.find <- function(){
    fun <- .rcpp.Vector$character_find_
    checkEquals( fun( c("bar", "foo", "bob") ), 1L, msg = "support for std::find in CharacterVector" )
}
    
test.CharacterVector.create <- function(){
	fun <- .rcpp.Vector$character_create_
    checkEquals( fun(), list( c( "foo", "bar" ), c(foo = "bar", bar = "foo" ) ), 
	 	msg = "CharacterVector::create" )
}


