// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// ExpressionVector.h: Rcpp R/C++ interface class library -- expression vectors
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

#ifndef Rcpp_ExpressionVector_h
#define Rcpp_ExpressionVector_h

#include <RcppCommon.h>
#include <Rcpp/SEXP_Vector.h>

namespace Rcpp{ 

/* lazyness typedef */
typedef SEXP_Vector<EXPRSXP> ExpressionVector_Base ;

class ExpressionVector : public ExpressionVector_Base {     
public:
	class parse_error : public std::exception{
	public:
		parse_error() throw();
		virtual ~parse_error() throw();
	        virtual const char* what() const throw() ;
	} ;
	
	ExpressionVector(SEXP x) throw(not_compatible);
	ExpressionVector(const size_t& size) ;
	ExpressionVector(const std::string& code) throw(parse_error) ;
	ExpressionVector(const ExpressionVector& other) ;
	ExpressionVector& operator=(const ExpressionVector& other) ;
	
	SEXP eval() throw(Evaluator::eval_error) ;
	SEXP eval(const Environment& env) throw(Evaluator::eval_error);

} ;

} // namespace

#endif
