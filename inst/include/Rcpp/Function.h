// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Function.h: Rcpp R/C++ interface class library -- functions (also primitives and builtins)
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

#ifndef Rcpp_Function_h
#define Rcpp_Function_h

#include <RcppCommon.h>

#include <Rcpp/grow.h>
#include <Rcpp/RObject.h>

namespace Rcpp{ 

/** 
 * functions
 */
class Function : public RObject{
public:

	/**
	 * Attempts to convert the SEXP to a pair list
	 *
	 * @throw not_compatible if the SEXP could not be converted
	 * to a pair list using as.pairlist
	 */
	Function(SEXP lang) throw(not_compatible) ;
	
	/**
	 * Finds a function, searching from the global environment
	 *
	 * @param name name of the function
	 */
	Function(const std::string& name) throw(no_such_function) ;
	
	Function(const Function& other) ;
	Function& operator=(const Function& other );
	
	// /**
	//  * Finds a function, searching from a specific environment
	//  *
	//  * @param name name of the function
	//  * @param env environment where to find it
	//  */
	// Function(const std::string& name, SEXP env ) ;
	
	/**
	 * calls the function with the specified arguments
	 *
	 * @param ...Args variable length argument list. The type of each 
	 *        argument must be wrappable, meaning there need to be 
	 *        a wrap function that takes this type as its parameter
	 *
	 */
#ifdef HAS_VARIADIC_TEMPLATES
template<typename... Args> 
	SEXP operator()( const Args&... args) /* throw(Evaluator::eval_error) */ {
		return internal::try_catch( Rf_lcons( m_sexp, pairlist(args...) ) ) ;
	}
#else
	SEXP operator()(){
		return internal::try_catch( Rf_lcons( m_sexp, R_NilValue ) ) ;	
	}
	
#include <Rcpp/generated/Function__operator.h>	
#endif
	
	/**
	 * Returns the environment of this function
	 */
	SEXP environment() const throw(not_a_closure) ;
	
	/**
	 * Returns the body of the function
	 */
	SEXP body() const ;
	 
	~Function() ;
};

} // namespace Rcpp

#endif
