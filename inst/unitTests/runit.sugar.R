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

.setUp <- function(){
	if( ! exists( ".rcpp.sugar", globalenv() ) ){
		# definition of all the functions at once
		
		sugar.functions <- list( 
			"runit_abs" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					IntegerVector yy(y) ;
					
					return List::create( abs(xx), abs(yy) ) ;
				'
			), 
			"runit_all_one_less" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return all( xx < 5.0 ) ;
				'
			), 
			"runit_all_one_greater" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return all( xx > 5.0 ) ;
				'				
			), 
			"runit_all_one_less_or_equal" = list(
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return all( xx <= 5.0 ) ;
				'
			), 
			"runit_all_one_greater_or_equal" = list( 
				signature( x = "numeric" ), 
				'
				    NumericVector xx(x) ;
					return all( xx >= 5.0 ) ;
				'
			), 
			"runit_all_one_equal" = list( 
				signature( x = "numeric" ), 
				'
				   	NumericVector xx(x) ;
					return all( xx == 5.0 ) ;
				'
			),
			"runit_all_not_equal_one" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return all( xx != 5.0 ) ;
				'
			), 
			"runit_all_less" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					return all( xx < yy ) ;
				'
			), 
			"runit_all_greater" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					return all( xx > yy ) ;
				'
			), 
			"runit_all_less_or_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
						NumericVector xx(x) ;
						NumericVector yy(y) ;
						return all( xx <= yy ) ;
				'				
			), 
			"runit_all_greater_or_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					return all( xx >= yy ) ;
				'
			), 
			"runit_all_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
						NumericVector xx(x) ;
						NumericVector yy(y) ;
						return all( xx == yy ) ;
				'				
			), 
			"runit_all_not_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
						NumericVector xx(x) ;
						NumericVector yy(y) ;
						return all( xx != yy ) ;
				'				
			), 
			"runit_any_less" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					return any( xx < yy ) ;
				'				 
			), 
			"runit_any_greater" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					return any( xx > yy ) ;
				'				
			), 
			"runit_any_less_or_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
				NumericVector xx(x) ;
				NumericVector yy(y) ;
				
				return any( xx <= yy ) ;
				'				
			), 
			"runit_any_greater_or_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
				NumericVector xx(x) ;
				NumericVector yy(y) ;
				
				return any( xx >= yy ) ;
				'				
			), 
			"runit_any_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
				NumericVector xx(x) ;
				NumericVector yy(y) ;
				return any( xx == yy ) ;
				'				
			), 
			"runit_any_not_equal" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
				NumericVector xx(x) ;
				NumericVector yy(y) ;
				return any( xx != yy ) ;
				'				
			), 
			"runit_constructor" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					LogicalVector res( xx < yy ) ;
					return res ;
				'				
			), 
			"runit_assignment" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					LogicalVector res; 
					res = xx < yy ;
					return res ;
				'	
			), 
			"runit_diff" = list( 
				signature( x = "numeric" ) ,
				'
					NumericVector xx(x) ;
					NumericVector res = diff( xx );
					return res ;
				'				
			), 
			"runit_exp" = list( 
				signature( x = "numeric", y = "integer" ), 
				'
					NumericVector xx(x) ;
					IntegerVector yy(y) ;
					return List::create( exp(xx), exp(yy) ) ;
				'				
			), 
			"runit_floor" = list( 
				signature( x = "numeric", y = "integer" ), 
				'
					NumericVector xx(x) ;
					IntegerVector yy(y) ;
					return List::create( floor(xx), floor(yy) ) ;
				'				
			), 
			"runit_ceil" = list( 
				signature( x = "numeric", y = "integer" ), 
				'
					NumericVector xx(x) ;
					IntegerVector yy(y) ;
					return List::create( ceil(xx), ceil(yy) ) ;
				'
			), 
			"runit_pow" = list( 
				signature( x = "numeric", y = "integer" ),
				'
					NumericVector xx(x) ;
					IntegerVector yy(y) ;
					return List::create( pow(xx, 3), pow(yy, 2.3) ) ;
				'				
			), 
			"runit_ifelse" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					
					return List::create( 
						_["vec_vec" ]  = ifelse( xx < yy, xx*xx, -(yy*yy) ), 
						_["vec_prim"]  = ifelse( xx < yy, 1.0  , -(yy*yy) ), 
						_["prim_vec"]  = ifelse( xx < yy, xx*xx, 1.0      ), 
						_["prim_prim"] = ifelse( xx < yy, 1.0, 2.0        )
						) ;
				'				
			), 
			"runit_isna" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return wrap( is_na( xx ) ) ;
				'				
			), 
			"runit_isna_isna" = list(
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return wrap( is_na( is_na( xx ) ) ) ;
				'				
			) , 
			"runit_any_isna" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return any( is_na( xx ) ) ;
				'				 
			), 
			"runit_lapply" = list( 
				signature( x = "integer" ), 
				'
					IntegerVector xx(x) ;
					List res = lapply( xx, seq_len );
					return res ;
				'				
			), 
			"runit_minus" = list( 
				signature( x = "integer" ), 
				'
					IntegerVector xx(x) ;
					return List::create(
						xx - 10, 
						10 - xx, 
						xx - xx
						) ;
				'			
			), 
			"runit_any_equal_not" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					return any( !( xx == yy) ) ;
				'				
			), 
			"runit_plus" = list( 
				signature( x = "integer" ), 
				'
					IntegerVector xx(x) ;
					return List::create(
						xx + 10, 
						10 + xx, 
						xx + xx, 
						xx + xx + xx
						) ;
				'			
			), 
			"runit_plus_seqlen" = list( 
				signature(), 
				'
					return List::create(
						seq_len(10) + 10, 
						10 + seq_len(10),
						seq_len(10) + seq_len(10)
						) ;
				'
			), 
			"runit_plus_all" = list( 
				signature( x = "integer" ), '
					IntegerVector xx(x) ;
					return all( (xx+xx) < 10 ) ;
				'
			), 
			"runit_pmin" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					NumericVector res = pmin( xx, yy );
					return res ;
				'				
			), 
			"runit_pmin_one" = list( 
				signature( x = "numeric" ), '
					NumericVector xx(x) ;
					return List::create( 
						pmin( xx, 5), 
						pmin( 5, xx)
						) ;
				'				
			), 
			"runit_pmax" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
						NumericVector xx(x) ;
						NumericVector yy(y) ;
						NumericVector res = pmax( xx, yy );
						return res ;
				'				
			), 
			"runit_pmax_one" = list( 
				signature( x = "numeric" ), 
				'
				NumericVector xx(x) ;
				return List::create( 
					pmax( xx, 5), 
					pmax( 5, xx)
					) ;
				'	
			), 
			"runit_Range" = list( 
				signature(  ), 
				'
					NumericVector xx(8) ;
					xx[ Range(0,3) ] = exp( seq_len(4) ) ;
					xx[ Range(4,7) ] = exp( - seq_len(4) ) ;
					return xx ;
				'	
			), 
			"runit_sapply" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector res = sapply( xx, square<double>() );
					return res ;
				'
			), 
			"runit_sapply_rawfun" = list( 
				signature( x = "numeric" ), '
					NumericVector xx(x) ;
					NumericVector res = sapply( xx, raw_square );
					return res ;
				'
			), 
			"runit_sapply_square" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return all( sapply( xx * xx , square<double>() ) < 10.0 );
				'
			), 
			"runit_sapply_list" = list( 
				signature( x = "integer" ), '
					IntegerVector xx(x) ;
					List res = sapply( xx, seq_len );
					return res ;
				'
			) , 
			"runit_seqalong" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					IntegerVector res = seq_along( xx );
					return res ;
				'				
			), 
			"runit_seqlen" = list( 
				signature( ), 
				'
					IntegerVector res = seq_len( 10 );
					return res ;
				'				
			) , 
			"runit_sign" = list( 
				signature( x = "numeric", y = "integer" ), '
					NumericVector xx(x) ;
					IntegerVector yy(y) ;
					
					return List::create(
						sign( xx ), 
						sign( yy )
						) ;
				'	
			), 
			"runit_times" = list( 
				signature( x = "integer" ), '
					IntegerVector xx(x) ; 
					IntegerVector yy = clone<IntegerVector>( xx ) ;
					yy[0] = NA_INTEGER ;
					
					return List::create(
    			        xx * 10, 
    			        10 * xx, 
    			        xx * xx, 
    			        xx * xx * xx, 
    			        xx * yy, 
    			        yy * 10, 
    			        10 * yy, 
    			        NA_INTEGER * xx
    			    ) ;
				'	
			), 
			"runit_divides" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return List::create(
						xx / 10, 
						10 / xx, 
						xx / xx
						) ;
				'	
			), 
			"runit_unary_minus" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy = - xx ;
					return yy ;
				'				
			), 
			"runit_wrap" = list( 
				signature( x = "numeric", y = "numeric", env = "environment" ), 
				'
					NumericVector xx(x) ;
					NumericVector yy(y) ;
					Environment e(env) ;
					e["foo"] = xx < yy  ;
					return R_NilValue ;
				'
			), 
			"runit_complex" = list( 
				signature(x = "complex" ), 
				'
					ComplexVector cx( x );
					return List::create( 
						_["Re"] = Re( cx ), 
						_["Im"] = Im( cx ), 
						_["Conj"] = Conj( cx ), 
						_["Mod"] = Mod( cx ), 
						_["exp"] = exp( cx ), 
						_["log"] = log( cx )
						) ;
				'
			), 
			"runit_rep" = list( 
				signature( x = "integer" ),
				'
				IntegerVector xx(x);
				List res = List::create( 
					_["rep"]      = rep( xx, 3 ), 
					_["rep_each"] = rep_each( xx, 3 ),
					_["rep_len"]  = rep_len( xx, 12 ), 
					_["rep_prim_double"] = rep( 0.0, 10 )
					) ;
				return res ;
				'
				), 
			"runit_rev" = list( 
				signature( x = "integer" ),
				'
				IntegerVector xx(x);
				IntegerVector yy = rev( xx * xx );
				return yy ;
				'
				), 
			"runit_outer" = list( 
				signature( x = "numeric", y = "numeric" ), 
				'
				NumericVector xx(x) ;
				NumericVector yy(y);
				NumericMatrix m = outer( xx, yy, std::plus<double>() ) ;
				return m ;
				'		), 
			"runit_row" = list( 
				signature( x = "numeric" ), 
				'
				NumericMatrix xx(x) ;
				return List::create( 
					_["row"] = row( xx ), 
					_["col"] = col( xx )
					) ;
				'	
			), 
			"runit_head" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return List::create( 
						_["pos"] = head( xx, 5 ), 
						_["neg"] = head( xx, -5 )
					) ;
				'
			), 
			"runit_tail" = list( 
				signature( x = "numeric" ), 
				'
					NumericVector xx(x) ;
					return List::create( 
						_["pos"] = tail( xx, 5 ), 
						_["neg"] = tail( xx, -5 )
					) ;
				'
			), 
			"runit_diag" = list( 
				signature( x = "numeric", m = "matrix" ), '
					NumericVector xx(x) ;
					NumericMatrix mm(m) ;
					return List::create( 
						diag( xx ) , 
						diag( mm ), 
						diag( outer( xx, xx, std::plus<double>() ) )
						) ;
				'
			), 
			"runit_gamma" = list( 
			signature(x = "numeric" ), 
			' 
				NumericVector xx(x) ;
				return List::create(
					_["gamma"]      = gamma(xx), 
					_["lgamma"]     = lgamma(xx),
					_["digamma"]    = digamma(xx),
					_["trigamma"]   = trigamma(xx), 
					_["tetragamma"] = tetragamma(xx), 
					_["pentagamma"] = pentagamma(xx), 
					_["factorial"]  = factorial(xx), 
					_["lfactorial"] = lfactorial(xx)
					) ;
			'), 
			"runit_choose" = list( 
			signature(n = "numeric", k = "numeric" ), 
			' 
				NumericVector nn(n), kk(k) ;
				return List::create(
					_["VV"] = choose(nn,kk), 
					_["PV"] = choose(10.0, kk ), 
					_["VP"] = choose(nn, 5.0 )
					) ;
			'
			), 
			"runit_lchoose" = list( 
			signature(n = "numeric", k = "numeric" ), 
			' 
				NumericVector nn(n), kk(k) ;
				return List::create(
					_["VV"] = lchoose(nn,kk), 
					_["PV"] = lchoose(10.0, kk ), 
					_["VP"] = lchoose(nn, 5.0 )
					) ;
			'
			),
			"runit_beta" = list( 
			signature(n = "numeric", k = "numeric" ), 
			' 
				NumericVector nn(n), kk(k) ;
				return List::create(
					_["VV"] = beta(nn,kk), 
					_["PV"] = beta(10.0, kk ), 
					_["VP"] = beta(nn, 5.0 )
					) ;
			'
			),
			"runit_psigamma" = list( 
			signature(n = "numeric", k = "numeric" ), 
			' 
				NumericVector nn(n), kk(k) ;
				return List::create(
					_["VV"] = psigamma(nn,kk), 
					_["PV"] = psigamma(10.0, kk ), 
					_["VP"] = psigamma(nn, 5.0 )
					) ;
			'
			),
			"runit_lbeta" = list( 
			signature(n = "numeric", k = "numeric" ), 
			' 
				NumericVector nn(n), kk(k) ;
				return List::create(
					_["VV"] = lbeta(nn,kk), 
					_["PV"] = lbeta(10.0, kk ), 
					_["VP"] = lbeta(nn, 5.0 )
					) ;
			'
			), 
			"runit_log1p" = list( 
			signature(x = "numeric" ), 
			' 
				NumericVector xx(x) ;
				return List::create(
					_["log1p"] = log1p(xx), 
					_["expm1"] = expm1(xx)
					) ;
			'
			) 
		)
		
		signatures <- lapply( sugar.functions, "[[", 1L )
		bodies <- lapply( sugar.functions, "[[", 2L )
		fx <- cxxfunction( signatures, bodies, plugin = "Rcpp", 
			include = '
			template <typename T>
			class square : public std::unary_function<T,T> {
			public:
				T operator()( T t) const { return t*t ; }
			} ;
			
			double raw_square( double x){ return x*x; }
	
	')
		getDynLib( fx ) # just forcing loading the dll now
		assign( ".rcpp.sugar", fx, globalenv() )
	}
}

test.sugar.abs <- function( ){
	fx <- .rcpp.sugar$runit_abs
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( abs(x), abs(y) ) )
}

test.sugar.all.one.less <- function( ){
	fx <- .rcpp.sugar$runit_all_one_less
	checkTrue( fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( is.na( fx( NA ) ) )
	checkTrue( is.na( fx( c( NA, 1)  ) ) )
	checkTrue( ! fx( c( 6, NA)  ) )
	
}

test.sugar.all.one.greater <- function( ){
	fx <- .rcpp.sugar$runit_all_one_greater
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( fx( 6:10 ) )
	checkTrue( ! fx( c(NA, 1) ) )
	checkTrue( is.na( fx( c(NA, 6) ) ) )
}


test.sugar.all.one.less.or.equal <- function( ){
	fx <- .rcpp.sugar$runit_all_one_less_or_equal
	checkTrue( fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( is.na( fx( NA ) ) )
	checkTrue( is.na( fx( c( NA, 1)  ) ) )
	checkTrue( ! fx( c( 6, NA)  ) )
	checkTrue( fx( 5 ) )
	
}

test.sugar.all.one.greater.or.equal <- function( ){
	fx <- .rcpp.sugar$runit_all_one_greater_or_equal
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( fx( 6:10 ) )
	checkTrue( fx( 5 ) )
	checkTrue( ! fx( c(NA, 1) ) )
	checkTrue( is.na( fx( c(NA, 6) ) ) )
}
 

test.sugar.all.one.equal <- function( ){

	fx <- .rcpp.sugar$runit_all_one_equal
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:2 ) )
	checkTrue( fx( rep(5,4) ) )
	checkTrue( is.na( fx( c(5,NA) ) ) )
	checkTrue(! fx( c(NA, 1) ) )
	
}

test.sugar.all.one.not.equal <- function( ){
	fx <- .rcpp.sugar$runit_all_not_equal_one
	checkTrue( fx( 1 ) )
	checkTrue( fx( 1:2 ) )
	checkTrue( ! fx( 5 ) )
	checkTrue( is.na( fx( c(NA, 1) ) ) )
	checkTrue( ! fx( c(NA, 5) ) )
}


test.sugar.all.less <- function( ){
	fx <- .rcpp.sugar$runit_all_less
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( fx( 1:10, 2:11 ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.all.greater <- function( ){
	fx <- .rcpp.sugar$runit_all_greater
	checkTrue( fx( 1, 0 ) )
	checkTrue( fx( 2:11, 1:10 ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 0:9, c(0:8,10) ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.all.less.or.equal <- function( ){
	fx <- .rcpp.sugar$runit_all_less_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.all.greater.or.equal <- function( ){
	fx <- .rcpp.sugar$runit_all_greater_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.all.equal <- function( ){
	fx <- .rcpp.sugar$runit_all_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.all.not.equal <- function( ){
	fx <- .rcpp.sugar$runit_all_not_equal
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.any.less <- function( ){
	fx <- .rcpp.sugar$runit_any_less
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( fx( 1:10, 2:11 ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.any.greater <- function( ){
	fx <- .rcpp.sugar$runit_any_greater
	checkTrue( fx( 1, 0 ) )
	checkTrue( fx( 2:11, 1:10 ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.any.less.or.equal <- function( ){

	fx <- .rcpp.sugar$runit_any_less_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.any.greater.or.equal <- function( ){
	fx <- .rcpp.sugar$runit_any_greater_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}


test.sugar.any.equal <- function( ){
	fx <- .rcpp.sugar$runit_any_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.any.not.equal <- function( ){
	fx <- .rcpp.sugar$runit_any_not_equal
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}

test.sugar.constructor <- function( ){
	fx <- .rcpp.sugar$runit_constructor
	checkEquals( fx( 1, 0 ), FALSE )
	checkEquals( fx( 1:10, 2:11 ), rep(TRUE,10) )
	checkEquals( fx( 0, 1 ), TRUE )
	checkTrue( identical( fx( NA, 1 ), NA ) )
}

test.sugar.assignment <- function( ){
	fx <- .rcpp.sugar$runit_assignment
	checkEquals( fx( 1, 0 ), FALSE )
	checkEquals( fx( 1:10, 2:11 ), rep(TRUE,10) )
	checkEquals( fx( 0, 1 ), TRUE )
	checkTrue( identical( fx( NA, 1 ), NA ) )
}

test.sugar.diff <- function( ){
	fx <- .rcpp.sugar$runit_diff
	x <- rnorm( 100 )
	checkEquals( fx(x) , diff(x) )
}

test.sugar.exp <- function( ){
	fx <- .rcpp.sugar$runit_exp
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( exp(x), exp(y) ) )
}

test.sugar.floor <- function( ){
	fx <- .rcpp.sugar$runit_floor
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( floor(x), floor(y) ) )
}

test.sugar.ceil <- function( ){
	fx <- .rcpp.sugar$runit_ceil
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( ceiling(x), ceiling(y) ) )
}

test.sugar.pow <- function( ){
	fx <- .rcpp.sugar$runit_pow
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( x^3L , y^2.3 ) )
}


test.sugar.ifelse <- function( ){
	fx <- .rcpp.sugar$runit_ifelse
	x <- 1:10
	y <- 10:1
	checkEquals( fx( x, y), list( 
		"vec_vec"   = ifelse( x<y, x*x, -(y*y) ), 
		"vec_prim"  = ifelse( x<y, 1.0, -(y*y) ), 
		"prim_vec"  = ifelse( x<y, x*x, 1.0    ), 
		"prim_prim" = ifelse( x<y, 1.0, 2.0    )
	) )
}


test.sugar.isna <- function( ){
	fx <- .rcpp.sugar$runit_isna
	checkEquals( fx( 1:10) , rep(FALSE,10) )
}

test.sugar.isna.isna <- function( ){
	fx <- .rcpp.sugar$runit_isna_isna
	checkEquals( fx( c(1:5,NA,7:10) ) , rep(FALSE,10) )
}

test.sugar.any.isna <- function( ){
	fx <- .rcpp.sugar$runit_any_isna
	checkEquals( fx( c(1:5,NA,7:10) ) , TRUE )
}

test.sugar.lapply <- function( ){
	fx <- .rcpp.sugar$runit_lapply
	checkEquals( fx( 1:10 ), lapply( 1:10, seq_len ) )
}

test.sugar.minus <- function( ){
	fx <- .rcpp.sugar$runit_minus
	checkEquals( fx(1:10) , list( (1:10)-10L, 10L-(1:10), rep(0L,10) )  )
}

test.sugar.any.equal.not <- function( ){
	fx <- .rcpp.sugar$runit_any_equal_not
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
}


test.sugar.plus <- function( ){
	fx <- .rcpp.sugar$runit_plus
	checkEquals( fx(1:10) , list( 11:20,11:20,1:10+1:10, 3*(1:10))  )
}

test.sugar.plus.seqlen <- function( ){
	fx <- .rcpp.sugar$runit_plus_seqlen
	checkEquals( fx() , list( 11:20,11:20, 1:10+1:10)  )
}

test.sugar.plus.all <- function( ){
	fx <- .rcpp.sugar$runit_plus_all
	checkEquals( fx(1:10) , FALSE )
}

test.sugar.pmin <- function( ){
	fx <- .rcpp.sugar$runit_pmin
	checkEquals( fx(1:10, 10:1) , c(1:5,5:1) )
}

test.sugar.pmin.one <- function( ){
	fx <- .rcpp.sugar$runit_pmin_one
	checkEquals( fx(1:10) , 
		list( 
			c(1:5,rep(5,5)), 
			c(1:5,rep(5,5))
		)
	)
}

test.sugar.pmax <- function( ){
	fx <- .rcpp.sugar$runit_pmax
	checkEquals( fx(1:10, 10:1) , c(10:6,6:10) )
}

test.sugar.pmax.one <- function( ){
	fx <- .rcpp.sugar$runit_pmax_one
	checkEquals( fx(1:10) , 
		list( 
			c(rep(5,5), 6:10), 
			c(rep(5,5), 6:10) 
		)
	) 
}

test.sugar.Range <- function( ){
	fx <- .rcpp.sugar$runit_Range
	checkEquals( fx() , c( exp(seq_len(4)), exp(-seq_len(4))  ) )
}


test.sugar.sapply <- function( ){
	fx <- .rcpp.sugar$runit_sapply
	checkEquals( fx(1:10) , (1:10)^2 )
}

test.sugar.sapply.rawfun <- function( ){
	fx <- .rcpp.sugar$runit_sapply_raw
	checkEquals( fx(1:10) , (1:10)^2 )
}

test.sugar.sapply.square <- function( ){
	fx <- .rcpp.sugar$runit_sapply_square
	checkTrue( ! fx(1:10)  )
}

test.sugar.sapply.list <- function( ){
	fx <- .rcpp.sugar$runit_sapply_list
	checkEquals( fx(1:10), lapply( 1:10, seq_len ) )
}

test.sugar.seqlaong <- function( ){
	fx <- .rcpp.sugar$runit_seqalong
	checkEquals( fx( rnorm(10)) , 1:10  )
}

test.sugar.seqlen <- function( ){
	fx <- .rcpp.sugar$runit_seqlen
	checkEquals( fx() , 1:10  )
}

test.sugar.sign <- function( ){
	fx <- .rcpp.sugar$runit_sign
	checkEquals( 
		fx( seq(-10, 10, length.out = 51), -25:25 ), 
		list( 
			c( rep(-1L, 25), 0L, rep(1L, 25) ), 
			c( rep(-1L, 25), 0L, rep(1L, 25) )
		)
	)
}


test.sugar.times <- function( ){
	fx <- .rcpp.sugar$runit_times
	checkEquals( fx(1:10) , 
		list( 
			10L*(1:10),
			10L*(1:10),
			(1:10)*(1:10), 
			(1:10)*(1:10)*(1:10), 
			c(NA,(2:10)*(2:10)), 
			c(NA,10L*(2:10)), 
			c(NA,10L*(2:10)), 
			rep( NA_integer_, 10L )
		)
	)
}
                         
test.sugar.divides <- function( ){
	fx <- .rcpp.sugar$runit_divides
	checkEquals( fx(1:10) , 
		list( 
			1:10/10,
			10/1:10,
			rep(1,10)
		)
	)
}


test.sugar.unary.minus <- function( ){
	fx <- .rcpp.sugar$runit_unary_minus
	checkEquals( fx( seq(0,5,by=10) ), - seq(0,5,by=10) )
	checkTrue( identical( fx( c(0,NA,2) ), c(0,NA,-2) ) )
}


test.sugar.wrap <- function( ){
	fx <- .rcpp.sugar$runit_wrap
	e <- new.env() 
	fx( 1:10, 2:11, e )
	checkEquals( e[["foo"]], rep(TRUE, 10 ) )
}


test.sugar.complex <- function( ){
	x <- c( rnorm(10), NA ) + 1i*c( rnorm(10), NA )
	fx <- .rcpp.sugar$runit_complex
	checkEquals( fx(x), list( 
		Re = Re( x ), 
		Im = Im( x ), 
		Conj = Conj(x), 
		Mod = Mod(x), 
		exp = exp(x), 
		log = log(x)
		)
	)
}

test.sugar.rep <- function(){
	fx <- .rcpp.sugar$runit_rep
	checkEquals( fx(1:10), 
		list( 
			"rep" = rep( 1:10, 3 ),
			"rep_each" = rep( 1:10, each = 3 ), 
			"rep_len" = rep( 1:10, length.out = 12 ), 
			"rep_prim_double" = rep( 0.0, 10 )
		)
	)
}

test.sugar.rev <- function(){
	fx <- .rcpp.sugar$runit_rev
	checkEquals( fx(1:10), rev( 1:10 * 1:10 ) )
}

test.sugar.head <- function(){
	fx <- .rcpp.sugar$runit_head
	checkEquals( 
		fx(1:100), 
		list( pos = 1:5, neg = 1:95 )
		)
}
     
test.sugar.tail <- function(){
	fx <- .rcpp.sugar$runit_tail
	checkEquals( 
		fx(1:100), 
		list( pos = 96:100, neg = 6:100 )
		)
}
     




# matrix 


			
test.sugar.matrix.outer <- function( ){
	fx <- .rcpp.sugar$runit_outer
	x <- 1:2
	y <- 1:5
	checkEquals( fx(x,y) , outer(x,y,"+") )
}

test.sugar.matrix.row <- function( ){
	fx <- .rcpp.sugar$runit_row
	m <- matrix( 1:16, nc = 4 )
	checkEquals( fx(m), list( row = row(m), col = col(m) ) ) 
}

test.sugar.diag <- function( ){
	fx <- .rcpp.sugar$runit_diag
	
	x <- 1:4
	m <- matrix( 1:16, nc = 4 )
	checkEquals( fx(x, m), 
		list( diag(x), diag(m), diag( outer( x, x, "+" ) ) ) ) 
}





# autogenerated sugar blocks

test.sugar.gamma <- function(){
	fx <- .rcpp.sugar$runit_gamma
	x <- seq( 1, 5, by = .5 )
	checkEquals( fx(x), 
	 	list( 
	  		"gamma"      = gamma(x), 
	  		"lgamma"     = lgamma(x),
	  		"digamma"    = digamma(x),
	  		"trigamma"   = trigamma(x), 
	  		"tetragamma" = psigamma(x, 2), 
	  		"pentagamma" = psigamma(x, 3),
	  		"factorial"  = factorial(x), 
	  		"lfactorial" = lfactorial(x)
	  	)
	)
}

test.sugar.log1p <- function(){
	x <- 10^-(1+2*1:9)
	fx <- .rcpp.sugar$runit_log1p
	checkEquals( fx(x), 
		list( log1p = log1p(x), expm1 = expm1(x) ) )
}

test.sugar.choose <- function(){
	fx <- .rcpp.sugar$runit_choose
	checkEquals( fx(10:6,5:1), 
		list( 
			VV = choose( 10:6, 5:1), 
			PV = choose( 10, 5:1 ), 
			VP = choose( 10:6, 5 )
		) )
}

test.sugar.lchoose <- function(){
	fx <- .rcpp.sugar$runit_lchoose
	checkEquals( fx(10:6,5:1), 
		list( 
			VV = lchoose( 10:6, 5:1), 
			PV = lchoose( 10, 5:1 ), 
			VP = lchoose( 10:6, 5 )
		) )
}

test.sugar.beta <- function(){
	fx <- .rcpp.sugar$runit_beta
	checkEquals( fx(10:6,5:1), 
		list( 
			VV = beta( 10:6, 5:1), 
			PV = beta( 10, 5:1 ), 
			VP = beta( 10:6, 5 )
		) )
}

test.sugar.lbeta <- function(){
	fx <- .rcpp.sugar$runit_lbeta
	checkEquals( fx(10:6,5:1), 
		list( 
			VV = lbeta( 10:6, 5:1), 
			PV = lbeta( 10, 5:1 ), 
			VP = lbeta( 10:6, 5 )
		) )
}

test.sugar.psigamma <- function(){
	fx <- .rcpp.sugar$runit_psigamma
	checkEquals( fx(10:6,5:1), 
		list( 
			VV = psigamma( 10:6, 5:1), 
			PV = psigamma( 10, 5:1 ), 
			VP = psigamma( 10:6, 5 )
		) )
}

