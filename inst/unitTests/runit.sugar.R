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

test.sugar.abs <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( abs(xx), abs(yy) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( abs(x), abs(y) ) )
}


test.sugar.all.one.less <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return all( xx < 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( is.na( fx( NA ) ) )
	checkTrue( is.na( fx( c( NA, 1)  ) ) )
	checkTrue( ! fx( c( 6, NA)  ) )
	
}

test.sugar.all.one.greater <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	    NumericVector xx(x) ;
		return all( xx > 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( fx( 6:10 ) )
	checkTrue( ! fx( c(NA, 1) ) )
	checkTrue( is.na( fx( c(NA, 6) ) ) )
}


test.sugar.all.one.less.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return all( xx <= 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( is.na( fx( NA ) ) )
	checkTrue( is.na( fx( c( NA, 1)  ) ) )
	checkTrue( ! fx( c( 6, NA)  ) )
	checkTrue( fx( 5 ) )
	
}

test.sugar.all.one.greater.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	    NumericVector xx(x) ;
		return all( xx >= 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( fx( 6:10 ) )
	checkTrue( fx( 5 ) )
	checkTrue( ! fx( c(NA, 1) ) )
	checkTrue( is.na( fx( c(NA, 6) ) ) )
}
 

test.sugar.all.one.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	   	NumericVector xx(x) ;
		return all( xx == 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:2 ) )
	checkTrue( fx( rep(5,4) ) )
	checkTrue( is.na( fx( c(5,NA) ) ) )
	checkTrue(! fx( c(NA, 1) ) )
	
}

test.sugar.all.one.not.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return all( xx != 5.0 ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1 ) )
	checkTrue( fx( 1:2 ) )
	checkTrue( ! fx( 5 ) )
	checkTrue( is.na( fx( c(NA, 1) ) ) )
	checkTrue( ! fx( c(NA, 5) ) )
	
}


test.sugar.all.less <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx < yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( fx( 1:10, 2:11 ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.greater <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx > yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 0 ) )
	checkTrue( fx( 2:11, 1:10 ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 0:9, c(0:8,10) ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.less.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx <= yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.greater.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx >= yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}


test.sugar.all.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx == yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.all.not.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return all( xx != yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}


test.sugar.any.less <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return any( xx < yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( fx( 1:10, 2:11 ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.any.greater <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return any( xx > yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 0 ) )
	checkTrue( fx( 2:11, 1:10 ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.any.less.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return any( xx <= yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.any.greater.or.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return any( xx >= yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}


test.sugar.any.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return any( xx == yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.any.not.equal <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return any( xx != yy ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}

test.sugar.constructor <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		LogicalVector res( xx < yy ) ;
		return res ;
		
	', plugin = "Rcpp" )


	checkEquals( fx( 1, 0 ), FALSE )
	checkEquals( fx( 1:10, 2:11 ), rep(TRUE,10) )
	checkEquals( fx( 0, 1 ), TRUE )
	checkTrue( identical( fx( NA, 1 ), NA ) )
	
}

test.sugar.assignment <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		LogicalVector res; 
		res = xx < yy ;
		return res ;
		
	', plugin = "Rcpp" )


	checkEquals( fx( 1, 0 ), FALSE )
	checkEquals( fx( 1:10, 2:11 ), rep(TRUE,10) )
	checkEquals( fx( 0, 1 ), TRUE )
	checkTrue( identical( fx( NA, 1 ), NA ) )
	
}


test.sugar.diff <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector res = diff( xx );
		
		return res ;
	
	', plugin = "Rcpp" )
	
	x <- rnorm( 100 )
	checkEquals( fx(x) , diff(x) )
}


test.sugar.exp <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( exp(xx), exp(yy) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( exp(x), exp(y) ) )
}

test.sugar.floor <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( floor(xx), floor(yy) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( floor(x), floor(y) ) )
}

test.sugar.ceil <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( ceil(xx), ceil(yy) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( ceiling(x), ceiling(y) ) )
}

test.sugar.pow <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create( pow(xx, 3), pow(yy, 2.3) ) ;
	', plugin = "Rcpp" )
	
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( x^3L , y^2.3 ) )
}


test.sugar.ifelse <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		NumericVector res = ifelse( xx < yy, xx*xx, -(yy*yy) ) ;
		return res ;
	', plugin = "Rcpp" )

	x <- 1:10
	y <- 10:1
	checkEquals( fx( x, y), ifelse( x<y, x*x, -(y*y) ) )
	
}


test.sugar.isna <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return wrap( is_na( xx ) ) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx( 1:10) , rep(FALSE,10) )
}

test.sugar.isna.isna <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return wrap( is_na( is_na( xx ) ) ) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx( c(1:5,NA,7:10) ) , rep(FALSE,10) )
}

test.sugar.any.isna <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return any( is_na( xx ) ) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx( c(1:5,NA,7:10) ) , TRUE )
}


test.sugar.lapply <- function( ){

	fx <- cxxfunction( signature( x = "integer" ), '
		IntegerVector xx(x) ;
		List res = lapply( xx, seq_len );
		return res ;
	
	', plugin = "Rcpp" )
	
	checkEquals( fx( 1:10 ), lapply( 1:10, seq_len ) )
}


test.sugar.minus <- function( ){

	fx <- cxxfunction( signature( x = "integer" ), '
		IntegerVector xx(x) ;
		return List::create(
			xx - 10, 
			10 - xx, 
			xx - xx
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , list( (1:10)-10L, 10L-(1:10), rep(0L,10) )  )
}


test.sugar.any.equal.not <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		
		return any( !( xx == yy) ) ;
	
	', plugin = "Rcpp" )
	
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
	
}


test.sugar.plus <- function( ){

	fx <- cxxfunction( signature( x = "integer" ), '
		IntegerVector xx(x) ;
		return List::create(
			xx + 10, 
			10 + xx, 
			xx + xx, 
			xx + xx + xx
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , list( 11:20,11:20,1:10+1:10, 3*(1:10))  )
}

test.sugar.plus.seqlen <- function( ){

	fx <- cxxfunction( signature(), '
		return List::create(
			seq_len(10) + 10, 
			10 + seq_len(10),
			seq_len(10) + seq_len(10)
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx() , list( 11:20,11:20, 1:10+1:10)  )
}

test.sugar.plus.all <- function( ){

	fx <- cxxfunction( signature( x = "integer" ), '
		IntegerVector xx(x) ;
		return all( (xx+xx) < 10 ) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , FALSE )
}


test.sugar.pmin <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		NumericVector res = pmin( xx, yy );
		return res ;
	
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10, 10:1) , c(1:5,5:1) )
}

test.sugar.pmin.one <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return List::create( 
			pmin( xx, 5), 
			pmin( 5, xx)
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , 
		list( 
			c(1:5,rep(5,5)), 
			c(1:5,rep(5,5))
		)
	)
}



test.sugar.pmax <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		NumericVector res = pmax( xx, yy );
		return res ;
	
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10, 10:1) , c(10:6,6:10) )
}

test.sugar.pmax.one <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return List::create( 
			pmax( xx, 5), 
			pmax( 5, xx)
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , 
		list( 
			c(rep(5,5), 6:10), 
			c(rep(5,5), 6:10) 
		)
	) 
}


test.sugar.Range <- function( ){

	fx <- cxxfunction( signature(  ), '
	
		NumericVector xx(8) ;
		xx[ Range(0,3) ] = exp( seq_len(4) ) ;
		xx[ Range(4,7) ] = exp( - seq_len(4) ) ;
		return xx ;
	', plugin = "Rcpp" )
	
	checkEquals( fx() , c( exp(seq_len(4)), exp(-seq_len(4))  ) )
}


test.sugar.sapply <- function( ){

	inc <- '
	template <typename T>
	class square : public std::unary_function<T,T> {
	public:
		T operator()( T t) const { return t*t ; }
	} ;
	'
	
	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector res = sapply( xx, square<double>() );
		
		return res ;
	
	', include = inc, plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , (1:10)^2 )
}

test.sugar.sapply.rawfun <- function( ){

	inc <- '
	double square( double x){ return x*x; }
	'
	
	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		NumericVector res = sapply( xx, square );
		
		return res ;
	
	', include = inc, plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , (1:10)^2 )
}

test.sugar.sapply.square <- function( ){

	inc <- '
	template <typename T>
	class square : public std::unary_function<T,T> {
	public:
		T operator()( T t) const { return t*t ; }
	} ;
	'
	
	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		return all( sapply( xx * xx , square<double>() ) < 10.0 );
	
	', include = inc, plugin = "Rcpp" )
	
	checkTrue( ! fx(1:10)  )
}

test.sugar.sapply.list <- function( ){

	fx <- cxxfunction( signature( x = "integer" ), '
		IntegerVector xx(x) ;
		List res = sapply( xx, seq_len );
		return res ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10), lapply( 1:10, seq_len ) )
}



test.sugar.seqlaong <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
	
		NumericVector xx(x) ;
		IntegerVector res = seq_along( xx );
		
		return res ;
	
	', plugin = "Rcpp" )
	
	
	checkEquals( fx( rnorm(10)) , 1:10  )
}

test.sugar.seqlen <- function( ){

	fx <- cxxfunction( signature( ), '
		IntegerVector res = seq_len( 10 );
		return res ;
	', plugin = "Rcpp" )
	
	
	checkEquals( fx() , 1:10  )
}


test.sugar.sign <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "integer" ), '
	
		NumericVector xx(x) ;
		IntegerVector yy(y) ;
		
		return List::create(
			sign( xx ), 
			sign( yy )
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( 
		fx( seq(-10, 10, length.out = 51), -25:25 ), 
		list( 
			c( rep(-1L, 25), 0L, rep(1L, 25) ), 
			c( rep(-1L, 25), 0L, rep(1L, 25) )
		)
	)
}


test.sugar.times <- function( ){

	fx <- cxxfunction( signature( x = "integer" ), '
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
	', plugin = "Rcpp" )
	
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

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		return List::create(
			xx / 10, 
			10 / xx, 
			xx / xx
			) ;
	', plugin = "Rcpp" )
	
	checkEquals( fx(1:10) , 
		list( 
			1:10/10,
			10/1:10,
			rep(1,10)
		)
	)
}


test.sugar.unary.minus <- function( ){

	fx <- cxxfunction( signature( x = "numeric" ), '
		NumericVector xx(x) ;
		NumericVector yy = - xx ;
		return yy ;
	', plugin = "Rcpp" )
	
	checkEquals( fx( seq(0,5,by=10) ), - seq(0,5,by=10) )
	checkTrue( identical( fx( c(0,NA,2) ), c(0,NA,-2) ) )
	
}


test.sugar.wrap <- function( ){

	fx <- cxxfunction( signature( x = "numeric", y = "numeric", env = "environment" ), '
	
		NumericVector xx(x) ;
		NumericVector yy(y) ;
		Environment e(env) ;
		
		e["foo"] = xx < yy  ;
		return R_NilValue ;
		
	', plugin = "Rcpp" )

	e <- new.env() 
	fx( 1:10, 2:11, e )
	checkEquals( e[["foo"]], rep(TRUE, 10 ) )
	
}

