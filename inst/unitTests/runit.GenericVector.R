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
    tests <- ".rcpp.List"
    if( ! exists(tests, globalenv() )) {
        ## definition of all the functions at once
        f <- list("ctor"=list(
                  signature(),
                  'List x(10) ;
	           for( int i=0; i<10; i++) x[i] = Rf_ScalarInteger( i * 2)  ;
	           return x ;')

                  ,"template_"=list(
                   signature(),
                   'List x(4) ;
	            x[0] = "foo"  ;
	            x[1] = 10 ;
	            x[2] = 10.2 ;
	            x[3] = false;
	            return x ;')

                  ,"VECSXP_"=list(
                   signature(vec = "list" ),
                   'List x(vec) ;
                    return x ;')

                  ,"matrix_indexing_1"=list(
                   signature(x = "character" ),
                   'GenericVector m(x) ;
		    GenericVector out(4) ;
		    for( size_t i=0 ; i<4; i++){
		        out[i] = m(i,i) ;
		    }
		    return out ;')

                  ,"matrix_indexing_2"=list(
                   signature(x = "integer" ),
                   'GenericVector m(x) ;
		    for(size_t i=0 ; i<4; i++){
		        m(i,i) = "foo" ;
		    }
		    return m ; ')

                  ,"Dimension_constructor_1"=list(
                   signature(),
                   'return List( Dimension( 5 ) ) ;')

                  ,"Dimension_constructor_2"=list(
                   signature(),
                   'return List( Dimension( 5, 5 ) );')

                  ,"Dimension_constructor_3"=list(
                   signature(),
                   ' return List( Dimension( 2, 3, 4) ) ;')

                  ,"iterator_"=list(
                   signature(x = "list", g = "function" ),
                   'Function fun(g) ;
		    List input(x) ;
		    List output( input.size() ) ;
		    std::transform( input.begin(), input.end(), output.begin(), fun ) ;
		    output.names() = input.names() ;
		    return output ; ')

                  ,"name_indexing"=list(
                   signature(x = "data.frame"),
                   'List df(x) ;
	            IntegerVector df_x = df["x"] ;
	            int res = std::accumulate( df_x.begin(), df_x.end(), 0 ) ;
	            return wrap(res); ')

                  ,"push_back"=list(
                   signature(x = "list"),
                   'List list(x) ;
	            list.push_back( 10 ) ;
	            list.push_back( "bar", "foo" ) ;
	            return list ;
	           ')

                  ,"push_front"=list(
                   signature(x = "list"),
                   'List list(x) ;
	            list.push_front( 10 ) ;
	            list.push_front( "bar", "foo" ) ;
	            return list ; ')

                  ,"erase"=list(
                   signature(x = "list"),
                   'List list(x) ;
	            list.erase( list.begin() ) ;
	            return list ; ')

                  ,"erase_range"=list(
                   signature(x = "list"),
	           'List list(x) ;
	            list.erase( 0, 1 ) ;
	            return list ; ')

                  ,"implicit_push_back"=list(
                   signature(),
                   'List list ;
                    list["foo"] = 10 ;
                    list["bar" ] = "foobar" ;
                    return list ;
                   '), 
              "create_" = list( 
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
    			)
               	
              
        )

        g <- list("initializer_list"=list(
                  signature(),
                  'SEXP x0 = PROTECT( Rf_ScalarInteger( 0 ) ) ;
		   SEXP x1 = PROTECT( Rf_ScalarInteger( 1 ) ) ;
		   SEXP x2 = PROTECT( Rf_ScalarInteger( 2 ) ) ;
		   List x = { x0, x1, x2} ;
		   UNPROTECT(3) ;
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


test.List <- function(){
    fun <- .rcpp.List$ctor
    checkEquals( fun(), as.list( 2*0:9), msg = "GenericVector" )
}

test.List.template <- function(){
    fun <- .rcpp.List$template_
    checkEquals(fun(), list( "foo", 10L, 10.2, FALSE), msg = "GenericVector" )
}

test.List.VECSXP <- function(){
    fun <- .rcpp.List$VECSXP_
    checkEquals( fun(list(1,2)), list(1,2), msg = "GenericVector( VECSXP) " )
}

if( Rcpp:::capabilities()[["initializer lists"]] ){
    test.List.initializer.list <- function(){
        fun <- .rcpp.List$initializer_list
        checkEquals( fun(), as.list(0:2), msg = "List( initializer list) " )
    }
}

test.List.matrix.indexing <- function(){
    fun <- .rcpp.List$matrix_indexing_1
    ## a matrix of integer vectors
    x <- structure( lapply( 1:16, function(x) seq.int(x) ), dim = c( 4, 4) )
    checkEquals( fun(x), diag(x), msg = "matrix indexing 1" )

    fun <- .rcpp.List$matrix_indexing_2
    checkEquals(diag(fun(x)), rep(list("foo"), 4) , msg = "matrix indexing lhs" )

    ## drop dimensions
    dim(x) <- NULL
    checkException( fun(x) , msg = "not a matrix" )
}

test.List.Dimension.constructor <- function(){
    fun <- .rcpp.List$Dimension_constructor_1
    checkEquals(fun(),
		rep(list(NULL),5) ,
                msg = "List( Dimension(5))" )

    fun <- .rcpp.List$Dimension_constructor_2
    checkEquals(fun(),
		structure( rep( list(NULL), 25), dim = c(5,5) ),
		msg = "List( Dimension(5,5))" )

    fun <- .rcpp.List$Dimension_constructor_3
    checkEquals(fun(),
		array( rep(list(NULL)), dim = c(2,3,4) ) ,
		msg = "List( Dimension(2,3,4))" )
}

test.List.iterator <- function() {
    fun <- .rcpp.List$iterator_
    data <- list( x = letters, y = LETTERS, z = 1:4 )
    checkEquals(fun( data, length ),
		list( x = 26L, y = 26L, z = 4L),
		msg = "c++ version of lapply" )
}

test.List.name.indexing <- function(){
    fun <- .rcpp.List$name_indexing
    d <- data.frame( x = 1:10, y = letters[1:10] )
    checkEquals( fun( d ), sum(1:10), msg = "List names based indexing" )
}

test.List.push.back <- function(){
    fun <- .rcpp.List$push_back
    d <- list( x = 1:10, y = letters[1:10] )
    checkEquals(fun( d ),
		list( x = 1:10, y = letters[1:10], 10L, foo = "bar" ),
		msg = "List.push_back" )
}

test.List.push.front <- function(){
    fun <- .rcpp.List$push_front
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
    fun <- .rcpp.List$erase
    d <- list( x = 1:10, y = letters[1:10] )
    checkEquals(fun(d),
		list( y = letters[1:10] ),
		msg = "List.erase" )
}

test.List.erase.range <- function(){
    fun <- .rcpp.List$erase_range
    d <- list( x = 1:10, y = letters[1:10], z = 1:10 )
    checkEquals(fun(d),
		list( z = 1:10 ),
		msg = "List.erase (range version)" )
}

test.List.implicit.push.back <- function(){
    fun <- .rcpp.List$implicit_push_back
    checkEquals( fun(), list( foo = 10, bar = "foobar" ), msg = "List implicit push back" )
}

test.List.create <- function(){
	fun <- .rcpp.List$create_
    checkEquals( fun(), list( list( 10L, "foo" ), list(foo = 10L, bar =  TRUE ) ), 
		msg = "List::create" )
}

test.List.stdcomplex <- function(){
	fun <- .rcpp.List$list_stdcomplex
    checkEquals( 
		fun(), 
		list( float = rep(0+0i, 10), double = rep(0+0i, 10) ), 
		msg = "range wrap over std::complex" )
}
