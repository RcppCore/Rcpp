// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// ExpressionVector.cpp: Rcpp R/C++ interface class library -- expression vectors
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#include <Rcpp/ExpressionVector.h>

namespace Rcpp{
	
	ExpressionVector::parse_error::parse_error() throw(){}
	ExpressionVector::parse_error::~parse_error() throw(){}
	const char* ExpressionVector::parse_error::what() const throw(){ return "parse error" ; }
	
	ExpressionVector::ExpressionVector(SEXP x) throw(not_compatible) : ExpressionVector_Base(x) {}
	ExpressionVector::ExpressionVector(const size_t& size) : ExpressionVector_Base(size) {}
	
	ExpressionVector::ExpressionVector(const std::string& code) throw(parse_error) : ExpressionVector_Base() {
		ParseStatus status;
		SEXP expr = PROTECT( Rf_mkString( code.c_str() ) );
		SEXP res  = PROTECT( R_ParseVector(expr, -1, &status, R_NilValue));
		switch( status ){
		case PARSE_OK:
			setSEXP( res) ;
			UNPROTECT( 2) ;
			break;
		default:
			UNPROTECT(2) ;
			throw parse_error() ;
		}
	}
        
	ExpressionVector::ExpressionVector( const ExpressionVector& other ) : ExpressionVector_Base() {
		setSEXP( other.asSexp() ) ;
	}
	
	ExpressionVector& ExpressionVector::operator=( const ExpressionVector& other){
		setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	SEXP ExpressionVector::eval() throw(Evaluator::eval_error){
		return Evaluator::run( Rf_lcons( Rf_install( "eval" ) , Rf_cons( m_sexp, R_NilValue) )) ;
	}
	
	SEXP ExpressionVector::eval(const Environment& env) throw(Evaluator::eval_error){
		return Evaluator::run( Rf_lcons( Rf_install( "eval" ) , Rf_cons( m_sexp, Rf_cons(env.asSexp(), R_NilValue)) ) ) ;
	}

} // namespace 
