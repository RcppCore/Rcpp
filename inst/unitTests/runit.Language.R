#!/usr/bin/r -t
#       hey emacs, please make this use  -*- tab-width: 4 -*-
#
# Copyright (C) 2010 - 2012  Dirk Eddelbuettel and Romain Francois
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

.setUp <- function(){
    sourceCpp(file.path(pathRcppTests, "cpp/language.cpp"))
}

test.Language <- function(){
	funx <- runit_language
	checkEquals( funx( call("rnorm") ), call("rnorm" ), msg = "Language( LANGSXP )" )
	checkException( funx(funx), msg = "Language not compatible with function" )
	checkException( funx(new.env()), msg = "Language not compatible with environment" )
	checkException( funx(1:10), msg = "Language not compatible with integer" )
	checkException( funx(TRUE), msg = "Language not compatible with logical" )
	checkException( funx(1.3), msg = "Language not compatible with numeric" )
	checkException( funx(as.raw(1) ), msg = "Language not compatible with raw" )
}

test.Language.variadic <- function(){
	funx <- runit_lang_variadic_1
	checkEquals( funx(), call("rnorm", 10L, 0.0, 2.0 ),
		msg = "variadic templates" )

	funx <- runit_lang_variadic_2
	checkEquals( funx(), call("rnorm", 10L, mean = 0.0, 2.0 ),
		msg = "variadic templates (with names)" )
}

# same as about but without variadic templates
test.Language.push.back <- function(){
	funx <- runit_lang_push_back
	checkEquals( funx(),
		call("rnorm", 10L, mean = 0.0, 2.0 ),
		msg = "Language::push_back" )
}

test.Language.square <- function(){
	funx <- runit_lang_square_rv
	checkEquals( funx(), 10.0, msg = "Language::operator[] used as rvalue" )

	funx <- runit_lang_square_lv
	checkEquals( funx(), call("rnorm", "foobar", 20.0, 20.0) , msg = "Pairlist::operator[] used as lvalue" )
}

test.Language.function <- function(){
	funx <- runit_lang_fun
	checkEquals( funx(sort, sample(1:10)), 1:10, msg = "Language( Function ) " )
}

test.Language.inputoperator <- function(){
	funx <- runit_lang_inputop
	checkEquals( funx(), call("rnorm", 10L, sd = 10L ) , msg = "Language<<" )
}

test.Language.unary.call <- function(){
	funx <- runit_lang_unarycall
	checkEquals(
		funx( 1:10 ),
		lapply( 1:10, function(n) seq(from=n, to = 0 ) ),
		msg = "c++ lapply using calls" )

}

test.Language.unary.call.index <- function(){
	funx <- runit_lang_unarycallindex
	checkEquals(
		funx( 1:10 ),
		lapply( 1:10, function(n) seq(from=10, to = n ) ),
		msg = "c++ lapply using calls" )

}

test.Language.binary.call <- function(){
	funx <- runit_lang_binarycall
	checkEquals(
		funx( 1:10, 11:20 ),
		lapply( 1:10, function(n) seq(n, n+10) ),
		msg = "c++ lapply using calls" )

}

test.Language.fixed.call <- function(){
	funx <- runit_lang_fixedcall
	set.seed(123)
	res <- funx()
	set.seed(123)
	exp <- lapply( 1:10, function(n) rnorm(10) )
	checkEquals( res, exp, msg = "std::generate" )
}

test.Language.in.env <- function(){
	funx <- runit_lang_inenv
	e <- new.env()
	e[["y"]] <- 1:10
	checkEquals( funx(e), sum(1:10), msg = "Language::eval( SEXP )" )
}

test.Pairlist <- function(){
	funx <- runit_pairlist
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
	funx <- runit_pl_variadic_1
	checkEquals( funx(), pairlist("rnorm", 10L, 0.0, 2.0 ),
		msg = "variadic templates" )

	funx <- runit_pl_variadic_2
	checkEquals( funx(), pairlist("rnorm", 10L, mean = 0.0, 2.0 ),
		msg = "variadic templates (with names)" )
}

test.Pairlist.push.front <- function(){
	funx <- runit_pl_push_front
	checkEquals( funx(),
		pairlist( foobar = 10, "foo", 10.0, 1L),
		msg = "Pairlist::push_front" )
}

test.Pairlist.push.back <- function(){
	funx <- runit_pl_push_back
	checkEquals( funx(),
		pairlist( 1L, 10.0, "foo", foobar = 10),
		msg = "Pairlist::push_back" )
}

test.Pairlist.insert <- function(){
	funx <- runit_pl_insert
	checkEquals( funx(),
		pairlist( 30.0, 1L, bla = "bla", 10.0, 20.0, "foobar" ),
		msg = "Pairlist::replace" )
}

test.Pairlist.replace <- function(){
	funx <- runit_pl_replace
	checkEquals( funx(),
		pairlist( first = 1, 20.0 , FALSE), msg = "Pairlist::replace" )
}

test.Pairlist.size <- function(){
	funx <- runit_pl_size
	checkEquals( funx(), 3L, msg = "Pairlist::size()" )
}

test.Pairlist.remove <- function(){
	funx <- runit_pl_remove_1
	checkEquals( funx(), pairlist(10.0, 20.0), msg = "Pairlist::remove(0)" )

	funx <- runit_pl_remove_2
	checkEquals( funx(), pairlist(1L, 10.0), msg = "Pairlist::remove(0)" )

	funx <- runit_pl_remove_3
	checkEquals( funx(), pairlist(1L, 20.0), msg = "Pairlist::remove(0)" )

}

test.Pairlist.square <- function(){
	funx <- runit_pl_square_1
	checkEquals( funx(), 10.0, msg = "Pairlist::operator[] used as rvalue" )

	funx <- runit_pl_square_2
	checkEquals( funx(), pairlist(1L, "foobar", 1L) , msg = "Pairlist::operator[] used as lvalue" )
}


test.Formula <- function(){
	funx <- runit_formula_
	checkEquals( funx(), x ~ y + z, msg = "Formula( string )" )
}

test.Formula.SEXP <- function(){
	funx <- runit_formula_SEXP
	checkEquals( funx( x ~ y + z), x ~ y + z, msg = "Formula( SEXP = formula )" )
	checkEquals( funx( "x ~ y + z" ), x ~ y + z, msg = "Formula( SEXP = STRSXP )" )
	checkEquals( funx( parse( text = "x ~ y + z") ), x ~ y + z, msg = "Formula( SEXP = EXPRSXP )" )
	checkEquals( funx( list( "x ~ y + z") ), x ~ y + z, msg = "Formula( SEXP = VECSXP(1 = STRSXP) )" )
	checkEquals( funx( list( x ~ y + z) ), x ~ y + z, msg = "Formula( SEXP = VECSXP(1 = formula) )" )
}

}
