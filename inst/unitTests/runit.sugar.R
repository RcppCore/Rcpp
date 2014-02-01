#!/usr/bin/r -t
#                     -*- mode: R; ess-indent-level: 4; indent-tabs-mode: nil; -*-
#
# Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois
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

.runThisTest <- Sys.getenv("RunAllRcppTests") == "yes"

if (.runThisTest) {

    .setUp <- Rcpp:::unitTestSetup("sugar.cpp")

    test.sugar.abs <- function( ){
	x <- rnorm(10)
	y <- -10:10
	checkEquals( runit_abs(x,y) , list( abs(x), abs(y) ) )
    }

    test.sugar.all.one.less <- function( ){
	checkTrue( runit_all_one_less( 1 ) )
	checkTrue( ! runit_all_one_less( 1:10 ) )
	checkTrue( is.na( runit_all_one_less( NA ) ) )
	checkTrue( is.na( runit_all_one_less( c( NA, 1)  ) ) )
	checkTrue( ! runit_all_one_less( c( 6, NA)  ) )
    }

    test.sugar.all.one.greater <- function( ){
	checkTrue( ! runit_all_one_greater( 1 ) )
	checkTrue( ! runit_all_one_greater( 1:10 ) )
	checkTrue( runit_all_one_greater( 6:10 ) )
	checkTrue( ! runit_all_one_greater( c(NA, 1) ) )
	checkTrue( is.na( runit_all_one_greater( c(NA, 6) ) ) )
    }

    test.sugar.all.one.less.or.equal <- function( ){
	checkTrue( runit_all_one_less_or_equal( 1 ) )
	checkTrue( ! runit_all_one_less_or_equal( 1:10 ) )
	checkTrue( is.na( runit_all_one_less_or_equal( NA ) ) )
	checkTrue( is.na( runit_all_one_less_or_equal( c( NA, 1)  ) ) )
	checkTrue( ! runit_all_one_less_or_equal( c( 6, NA)  ) )
	checkTrue( runit_all_one_less_or_equal( 5 ) )

    }

    test.sugar.all.one.greater.or.equal <- function( ){
	fx <- runit_all_one_greater_or_equal
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:10 ) )
	checkTrue( fx( 6:10 ) )
	checkTrue( fx( 5 ) )
	checkTrue( ! fx( c(NA, 1) ) )
	checkTrue( is.na( fx( c(NA, 6) ) ) )
    }


    test.sugar.all.one.equal <- function( ){
	fx <- runit_all_one_equal
	checkTrue( ! fx( 1 ) )
	checkTrue( ! fx( 1:2 ) )
	checkTrue( fx( rep(5,4) ) )
	checkTrue( is.na( fx( c(5,NA) ) ) )
	checkTrue(! fx( c(NA, 1) ) )

    }

    test.sugar.all.one.not.equal <- function( ){
	fx <- runit_all_not_equal_one
	checkTrue( fx( 1 ) )
	checkTrue( fx( 1:2 ) )
	checkTrue( ! fx( 5 ) )
	checkTrue( is.na( fx( c(NA, 1) ) ) )
	checkTrue( ! fx( c(NA, 5) ) )
    }


    test.sugar.all.less <- function( ){
	fx <- runit_all_less
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( fx( 1:10, 2:11 ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.all.greater <- function( ){
	fx <- runit_all_greater
	checkTrue( fx( 1, 0 ) )
	checkTrue( fx( 2:11, 1:10 ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 0:9, c(0:8,10) ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.all.less.or.equal <- function( ){
	fx <- runit_all_less_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.all.greater.or.equal <- function( ){
	fx <- runit_all_greater_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.all.equal <- function( ){
	fx <- runit_all_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.all.not.equal <- function( ){
	fx <- runit_all_not_equal
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( ! fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )

    }

    test.sugar.any.less <- function( ){
	fx <- runit_any_less
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( fx( 1:10, 2:11 ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.any.greater <- function( ){
	fx <- runit_any_greater
	checkTrue( fx( 1, 0 ) )
	checkTrue( fx( 2:11, 1:10 ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.any.less.or.equal <- function( ){
        fx <- runit_any_less_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.any.greater.or.equal <- function( ){
	fx <- runit_any_greater_or_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }


    test.sugar.any.equal <- function( ){
	fx <- runit_any_equal
	checkTrue( fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( ! fx( 0, 1 ) )
	checkTrue( ! fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.any.not.equal <- function( ){
	fx <- runit_any_not_equal
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }

    test.sugar.constructor <- function( ){
	fx <- runit_constructor
	checkEquals( fx( 1, 0 ), FALSE )
	checkEquals( fx( 1:10, 2:11 ), rep(TRUE,10) )
	checkEquals( fx( 0, 1 ), TRUE )
	checkTrue( identical( fx( NA, 1 ), NA ) )
    }

    test.sugar.assignment <- function( ){
	fx <- runit_assignment
	checkEquals( fx( 1, 0 ), FALSE )
	checkEquals( fx( 1:10, 2:11 ), rep(TRUE,10) )
	checkEquals( fx( 0, 1 ), TRUE )
	checkTrue( identical( fx( NA, 1 ), NA ) )
    }

    test.sugar.diff <- function( ){
        x <- as.integer(round(rnorm(100,1,100)))
        checkEquals( runit_diff_int(x) , diff(x) )
        x <- rnorm( 100 )
        checkEquals( runit_diff(x) , diff(x) )
        y    <- rnorm(100)
        pred <- sample( c(T,F), 99, replace = TRUE )
        checkEquals( runit_diff_ifelse(pred, x, y ), ifelse( pred, diff(x), diff(y) ) )
    }

    test.sugar.exp <- function( ){
	fx <- runit_exp
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( exp(x), exp(y) ) )
    }

    test.sugar.floor <- function( ){
	fx <- runit_floor
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( floor(x), floor(y) ) )
    }

    test.sugar.ceil <- function( ){
	fx <- runit_ceil
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( ceiling(x), ceiling(y) ) )
    }

    test.sugar.pow <- function( ){
	fx <- runit_pow
	x <- rnorm(10)
	y <- -10:10
	checkEquals( fx(x,y) , list( x^3L , y^2.3 ) )
    }


    test.sugar.ifelse <- function( ){
	fx <- runit_ifelse
	x <- 1:10
	y <- 10:1
	checkEquals( fx( x, y), list(
            "vec_vec"   = ifelse( x<y, x*x, -(y*y) ) ,
            "vec_prim"  = ifelse( x<y, 1.0, -(y*y) ),
            "prim_vec"  = ifelse( x<y, x*x, 1.0    ),
            "prim_prim" = ifelse( x<y, 1.0, 2.0    )
            ) )
    }


    test.sugar.isna <- function( ){
	fx <- runit_isna
	checkEquals( fx( 1:10) , rep(FALSE,10) )
    }

    test.sugar.isfinite <- function( ){
	checkEquals(
	    runit_isfinite( c(1, NA, Inf, -Inf, NaN) ) ,
	    c(TRUE, FALSE, FALSE, FALSE, FALSE),
	    msg = "is_finite"
            )
    }

    test.sugar.isinfinite <- function( ){
	checkEquals(
	    runit_isinfinite( c(1, NA, Inf, -Inf, NaN) ) ,
	    c(FALSE, FALSE, TRUE, TRUE, FALSE),
	    msg = "is_infinite"
            )
    }


    test.sugar.isnan <- function( ){
	checkEquals(
	    runit_isnan( c(1, NA, Inf, -Inf, NaN) ) ,
	    c(FALSE, FALSE, FALSE, FALSE, TRUE),
	    msg = "is_nan"
            )
    }

    test.sugar.isna.isna <- function( ){
	fx <- runit_isna_isna
	checkEquals( fx( c(1:5,NA,7:10) ) , rep(FALSE,10) )
    }

    test.sugar.any.isna <- function( ){
	fx <- runit_any_isna
	checkEquals( fx( c(1:5,NA,7:10) ) , TRUE )
    }

    test.sugar.lapply <- function( ){
	fx <- runit_lapply
	checkEquals( fx( 1:10 ), lapply( 1:10, seq_len ) )
    }

    test.sugar.minus <- function( ){
	fx <- runit_minus
	checkEquals(
	    fx(1:10) ,
	    list( (1:10)-10L, 10L-(1:10), rep(0L,10), (1:10)-10L, 10L-(1:10)  )
	    )
    }

    test.sugar.any.equal.not <- function( ){
	fx <- runit_any_equal_not
	checkTrue( ! fx( 1, 1 ) )
	checkTrue( fx( 1:2, c(1,1) ) )
	checkTrue( fx( 0, 1 ) )
	checkTrue( fx( 1, 0 ) )
	checkTrue( is.na( fx( NA, 1 ) ) )
    }


    test.sugar.plus <- function( ){
	fx <- runit_plus
	checkEquals( fx(1:10) , list( 11:20,11:20,1:10+1:10, 3*(1:10))  )
    }

    test.sugar.plus.seqlen <- function( ){
	fx <- runit_plus_seqlen
	checkEquals( fx() , list( 11:20,11:20, 1:10+1:10)  )
    }

    test.sugar.plus.all <- function( ){
	fx <- runit_plus_all
	checkEquals( fx(1:10) , FALSE )
    }

    test.sugar.pmin <- function( ){
	fx <- runit_pmin
	checkEquals( fx(1:10, 10:1) , c(1:5,5:1) )
    }

    test.sugar.pmin.one <- function( ){
	fx <- runit_pmin_one
	checkEquals( fx(1:10) ,
                    list(
			c(1:5,rep(5,5)),
			c(1:5,rep(5,5))
                        )
                    )
    }

    test.sugar.pmax <- function( ){
	fx <- runit_pmax
	checkEquals( fx(1:10, 10:1) , c(10:6,6:10) )
    }

    test.sugar.pmax.one <- function( ){
	fx <- runit_pmax_one
	checkEquals( fx(1:10) ,
                    list(
			c(rep(5,5), 6:10),
			c(rep(5,5), 6:10)
                        )
                    )
    }

    test.sugar.Range <- function( ){
	fx <- runit_Range
	checkEquals( fx() , c( exp(seq_len(4)), exp(-seq_len(4))  ) )
    }


    test.sugar.sapply <- function( ){
	fx <- runit_sapply
	checkEquals( fx(1:10) , (1:10)^2 )
    }

    test.sugar.sapply.rawfun <- function( ){
	fx <- runit_sapply_rawfun
	checkEquals( fx(1:10) , (1:10)^2 )
    }

    test.sugar.sapply.square <- function( ){
	fx <- runit_sapply_square
	checkTrue( ! fx(1:10)  )
    }

    test.sugar.sapply.list <- function( ){
	fx <- runit_sapply_list
	checkEquals( fx(1:10), lapply( 1:10, seq_len ) )
    }

    test.sugar.seqlaong <- function( ){
	fx <- runit_seqalong
	checkEquals( fx( rnorm(10)) , 1:10  )
    }

    test.sugar.seqlen <- function( ){
	fx <- runit_seqlen
	checkEquals( fx() , 1:10  )
    }

    test.sugar.sign <- function( ){
	fx <- runit_sign
	checkEquals(
            fx( seq(-10, 10, length.out = 51), -25:25 ),
            list(
                c( rep(-1L, 25), 0L, rep(1L, 25) ),
                c( rep(-1L, 25), 0L, rep(1L, 25) )
		)
            )
    }


    test.sugar.times <- function( ){
	fx <- runit_times
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
	fx <- runit_divides
	checkEquals( fx(1:10) ,
                    list(
			1:10/10,
			10/1:10,
			rep(1,10)
                        )
                    )
    }


    test.sugar.unary.minus <- function( ){
	fx <- runit_unary_minus
	checkEquals( fx( seq(0,5,by=10) ), - seq(0,5,by=10) )
	checkTrue( identical( fx( c(0,NA,2) ), c(0,NA,-2) ) )
    }


    test.sugar.wrap <- function( ){
	fx <- runit_wrap
	e <- new.env()
	fx( 1:10, 2:11, e )
	checkEquals( e[["foo"]], rep(TRUE, 10 ) )
    }


    test.sugar.complex <- function( ){
	x <- c( rnorm(10), NA ) + 1i*c( rnorm(10), NA )
	fx <- runit_complex
	checkEquals( fx(x), list(
            Re    = Re(x),
            Im    = Im(x),
            Conj  = Conj(x),
            Mod   = Mod(x),
            exp   = exp(x),
            log   = log(x),
            sqrt  = sqrt(x),
            cos   = cos(x),
            sin   = sin(x),
            tan   = tan(x),
            acos  = acos(x),
            asin  = asin(x),
            atan  = atan(x),
                                        # acosh = acosh(x),
            asinh = asinh(x),
            atanh = atanh(x),
            cosh  = cosh(x),
            sinh = sinh(x),
            tanh = tanh(x)

            )
                    )
    }

    test.sugar.rep <- function(){
	fx <- runit_rep
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
	fx <- runit_rev
	checkEquals( fx(1:10), rev( 1:10 * 1:10 ) )
    }

    test.sugar.head <- function(){
	fx <- runit_head
	checkEquals(
            fx(1:100),
            list( pos = 1:5, neg = 1:95 )
            )
    }

    test.sugar.tail <- function(){
	fx <- runit_tail
	checkEquals(
            fx(1:100),
            list( pos = 96:100, neg = 6:100 )
            )
    }





                                        # matrix



    test.sugar.matrix.outer <- function( ){
	fx <- runit_outer
	x <- 1:2
	y <- 1:5
	checkEquals( fx(x,y) , outer(x,y,"+") )
    }

    test.sugar.matrix.row <- function( ){
	fx <- runit_row
	m <- matrix( 1:16, nc = 4 )
	res <- fx( m )
	target <- list( row = row(m), col = col(m) )
	checkEquals( res, target )
    }

    test.sugar.diag <- function( ){
	fx <- runit_diag

	x <- 1:4
	m <- matrix( 1:16, nc = 4 )
	res <- fx(x, m)
	target <- list(
            diag(x),
            diag(m),
            diag( outer( x, x, "+" ) )
            )
	checkEquals( res, target )
    }


                                        # autogenerated sugar blocks

    test.sugar.gamma <- function(){
	fx <- runit_gamma
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
	fx <- runit_log1p
	checkEquals( fx(x),
                    list( log1p = log1p(x), expm1 = expm1(x) ) )
    }

    test.sugar.choose <- function(){
	fx <- runit_choose
	checkEquals( fx(10:6,5:1),
                    list(
			VV = choose( 10:6, 5:1),
			PV = choose( 10, 5:1 ),
			VP = choose( 10:6, 5 )
                        ) )
    }

    test.sugar.lchoose <- function(){
	fx <- runit_lchoose
	checkEquals( fx(10:6,5:1),
                    list(
			VV = lchoose( 10:6, 5:1),
			PV = lchoose( 10, 5:1 ),
			VP = lchoose( 10:6, 5 )
                        ) )
    }

    test.sugar.beta <- function(){
	fx <- runit_beta
	checkEquals( fx(10:6,5:1),
                    list(
			VV = beta( 10:6, 5:1),
			PV = beta( 10, 5:1 ),
			VP = beta( 10:6, 5 )
                        ) )
    }

    test.sugar.lbeta <- function(){
	fx <- runit_lbeta
	checkEquals( fx(10:6,5:1),
                    list(
			VV = lbeta( 10:6, 5:1),
			PV = lbeta( 10, 5:1 ),
			VP = lbeta( 10:6, 5 )
                        ) )
    }

    test.sugar.psigamma <- function(){
	fx <- runit_psigamma
	checkEquals( fx(10:6,5:1),
                    list(
			VV = psigamma( 10:6, 5:1),
			PV = psigamma( 10, 5:1 ),
			VP = psigamma( 10:6, 5 )
                        ) )
    }

    test.sugar.sum <- function(){
        fx <- runit_sum
        x <- rnorm( 10 )
        checkEquals( fx(x), sum(x) )
        x[4] <- NA
        checkEquals( fx(x), sum(x) )
    }

    test.sugar.cumsum <- function(){
        fx <- runit_cumsum
        x <- rnorm( 10 )
        checkEquals( fx(x), cumsum(x) )
        x[4] <- NA
        checkEquals( fx(x), cumsum(x) )
    }

    test.sugar.asvector <- function(){
        fx <- runit_asvector
        res <- fx( 1:4, 1:5, diag( 1:5 ) )
        checkEquals( res[[1]], as.vector( diag(1:5) ) )
        checkEquals( res[[2]], as.vector( outer( 1:4, 1:5, "+" ) ) )
    }

    test.sugar.asvector <- function(){
        fx <- runit_diff_REALSXP_NA
        x <- c( NA, 1.5, 2.5, NA, 3.5, 5.5, NA )
        checkEquals( fx(x), c(NA, 1.0, NA, NA, 2.0, NA) )
    }

                                        # additions 03 Sep 2012
    test.sugar.trunc <- function() {
        fx <- runit_trunc
        x <- seq(-5,5) + 0.5
        y <- seq(-5L, 5L)
        checkEquals(fx(x, y), list(trunc(x), trunc(y)))
    }
    test.sugar.round <- function() {
        fx <- runit_round
        x <- seq(-5,5) + 0.25
        checkEquals( fx(x, 0), round(x, 0) )
        checkEquals( fx(x, 1), round(x, 1) )
        checkEquals( fx(x, 2), round(x, 2) )
        checkEquals( fx(x, 3), round(x, 3) )
    }
    test.sugar.signif <- function() {
        fx <- runit_signif
        x <- seq(-5,5) + 0.25
        checkEquals( fx(x, 0), signif(x, 0) )
        checkEquals( fx(x, 1), signif(x, 1) )
        checkEquals( fx(x, 2), signif(x, 2) )
        checkEquals( fx(x, 3), signif(x, 3) )
    }

    test.RangeIndexer <- function(){
        x <- rnorm(10)
        checkEquals( runit_RangeIndexer(x), max(x[1:5]) )
    }

    test.self_match <- function(){
        x <- sample( letters, 1000, replace = TRUE )
        checkEquals( runit_self_match(x), match(x,unique(x)) )
    }

    test.table <- function(){
        x <- sample( letters, 1000, replace = TRUE )
        checkTrue( all( runit_table(x) == table(x) ) )
        checkTrue( all( names(runit_table(x)) == names(table(x)) ) )
    }

    test.duplicated <- function(){
        x <- sample( letters, 1000, replace = TRUE )
        checkEquals( runit_duplicated(x), duplicated(x) )
    }

    test.setdiff <- function(){
        checkEquals( 
            sort(runit_setdiff( 1:10, 1:5 )), 
            sort(setdiff( 1:10, 1:5))
            )
    }

    test.union <- function(){
        checkEquals( 
            sort(runit_union( 1:10, 1:5 )), 
            sort(union( 1:10, 1:5 )) 
            )
    }

    test.intersect <- function(){
        checkEquals( runit_intersect( 1:10, 1:5 ), intersect( 1:10, 1:5 ) )
    }

    test.clamp <- function(){
        r_clamp <- function(a, x, b) pmax(a, pmin(x, b) )
        checkEquals(
            runit_clamp( -1, seq(-3,3, length=100), 1 ),
            r_clamp( -1, seq(-3,3, length=100), 1 )
            )
    }

    test.vector.scalar.ops <- function( ){
        x <- rnorm(10)
        checkEquals(vector_scalar_ops(x), list(x + 2, 2 - x, x * 2, 2 / x), "sugar vector scalar operations")
    }

    test.vector.scalar.logical <- function( ){
        x <- rnorm(10) + 2
        checkEquals(vector_scalar_logical(x), list(x < 2, 2 > x, x <= 2, 2 != x), "sugar vector scalar logical operations")
    }

    test.vector.vector.ops <- function( ){
        x <- rnorm(10)
        y <- runif(10)
        checkEquals(vector_vector_ops(x,y), list(x + y, y - x, x * y, y / x), "sugar vector vector operations")
    }

    test.vector.vector.logical <- function( ){
        x <- rnorm(10)
        y <- runif(10)
        checkEquals(vector_vector_logical(x,y), list(x < y, x > y, x <= y, x >= y, x == y, x != y), "sugar vector vector operations")
    }

}
