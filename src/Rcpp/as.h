// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// as.h: Rcpp R/C++ interface class library -- convert SEXP to C++ objects
//
// Copyright (C) 2009 - 2010	Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__as__h
#define Rcpp__as__h

namespace Rcpp{

/** 
 * Generic converted from SEXP to the typename. T can be any type that 
 * has a constructor taking a SEXP, which is the case for all our 
 * RObject and derived classes. 
 *
 * If it is not possible to add the SEXP constructor, e.g you don't control
 * the type, you can specialize the as template to perform the 
 * requested conversion
 *
 * This is used for example in Environment, so that for example the code
 * below will work as long as there is a way to as<> the Foo type
 *
 * Environment x = ... ; // some environment
 * Foo y = x["bla"] ;    // if as<Foo> makes sense then this works !!
 */
template <typename T> T as( SEXP m_sexp) {
	T t(m_sexp);
	return t ;
}

template<> SEXP as(SEXP m_sexp) ;

/**
 * Converts the R object to a bool. 
 * 
 * The R object must be either a logical, integer, raw or numeric vector
 * and must have only one element. An exception is thrown otherwise
 *
 * bool can not handle missing values, so NA are converted to false
 */
template<> bool 			as<bool>(SEXP m_sexp) ;

/**
 * Converts the R object to a double
 * 
 * The R object must be either a logical, integer, raw or numeric vector
 * and must have only one element. An exception is thrown otherwise
 */
template<> double                   	as<double>(SEXP m_sexp) ;

/**
 * Converts the R object to an int
 * 
 * The R object must be either a logical, integer, raw or numeric vector
 * and must have only one element. An exception is thrown otherwise
 */
template<> int                      	as<int>(SEXP m_sexp) ;

/**
 * Converts the R object to a Rbyte
 * 
 * The R object must be either a logical, integer, raw or numeric vector
 * and must have only one element. An exception is thrown otherwise
 */
template<> Rbyte                    	as<Rbyte>(SEXP m_sexp) ;

/**
 * Converts the R object to a std::string
 * 
 * The R object must be a character vector of length 1. 
 * An exception is thrown otherwise
 */
template<> std::string              	as<std::string>(SEXP m_sexp) ;

/**
 * Converts the R object to a std::vector<int>
 *
 * The R object must be a logical, integer, raw or numeric vector
 */
template<> std::vector<int>         	as< std::vector<int> >(SEXP m_sexp) ;

/**
 * Converts the R object to a std::vector<double>
 *
 * The R object must be a logical, integer, raw ornumeric vector
 */
template<> std::vector<double>      	as< std::vector<double> >(SEXP m_sexp) ;

/**
 * Converts the R object to a std::vector<std::string>
 *
 * The R object must be a character vector
 */
template<> std::vector<std::string> 	as< std::vector<std::string> >(SEXP m_sexp) ;

/**
 * Converts the R object to a std::vector<Rbyte>
 *
 * The R object must be a logical, integer, raw or numeric vector
 */
template<> std::vector<Rbyte>       	as< std::vector<Rbyte> >(SEXP m_sexp) ;

/**
 * Converts the R object to a std::vector<Rbyte>
 *
 * The R object must be a logical, integer, raw or numeric vector
 *
 * since bool can not handle missing values, they are converted to false
 */
template<> std::vector<bool>        	as< std::vector<bool> >(SEXP m_sexp) ;

} // Rcpp 

#endif
