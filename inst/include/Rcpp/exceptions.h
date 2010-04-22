// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// exceptions.h: Rcpp R/C++ interface class library -- exceptions
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

#ifndef Rcpp__exceptions__h
#define Rcpp__exceptions__h

namespace Rcpp{

class exception : public std::exception {
	public:
		exception(const char* message_, const char* file, int line ) ;
		virtual ~exception() throw() ;
		virtual const char* what() const throw() { return message.c_str() ; };
	private:
		std::string message ;
} ;

class no_such_env : public std::exception{                                     
public:                                                                        
	no_such_env( const std::string& name ) throw() : message( std::string("no such environment: '") + name + "'" ){} ;
	no_such_env( int pos ) throw() : message( "no environment in given position ") {} ;
	virtual ~no_such_env() throw(){} ;                                         
	virtual const char* what() const throw(){ return message.c_str() ; } ;     
private:                                                                       
	std::string message ;                                                      
} ;


#define RCPP_EXCEPTION_CLASS(__CLASS__,__WHAT__)                               \
class __CLASS__ : public std::exception{                                       \
public:                                                                        \
	__CLASS__( const std::string& message ) throw() : message( __WHAT__ ){} ;  \
	virtual ~__CLASS__() throw(){} ;                                           \
	virtual const char* what() const throw(){ return message.c_str() ; } ;     \
private:                                                                       \
	std::string message ;                                                      \
} ;

#define RCPP_SIMPLE_EXCEPTION_CLASS(__CLASS__,__MESSAGE__)                     \
class __CLASS__ : public std::exception{                                       \
public:                                                                        \
	__CLASS__() throw() {} ;                                                   \
	virtual ~__CLASS__() throw(){} ;                                           \
	virtual const char* what() const throw(){ return __MESSAGE__ ; } ;         \
} ;

RCPP_SIMPLE_EXCEPTION_CLASS(not_a_matrix, "not a matrix" )
RCPP_SIMPLE_EXCEPTION_CLASS(index_out_of_bounds, "index out of bounds" )
RCPP_SIMPLE_EXCEPTION_CLASS(parse_error, "parse error") 
RCPP_SIMPLE_EXCEPTION_CLASS(not_s4, "not an S4 object" )
RCPP_SIMPLE_EXCEPTION_CLASS(no_such_slot, "no such slot" )
RCPP_SIMPLE_EXCEPTION_CLASS(not_a_closure, "not a closure" )
RCPP_SIMPLE_EXCEPTION_CLASS(no_such_function, "no such function" )
RCPP_SIMPLE_EXCEPTION_CLASS(unevaluated_promise, "promise not yet evaluated" )


RCPP_EXCEPTION_CLASS(not_compatible, message )
RCPP_EXCEPTION_CLASS(S4_creation_error, std::string("error creating object of S4 class : ") + message )
RCPP_EXCEPTION_CLASS(no_such_binding, std::string("no such binding : '") + message + "'" )
RCPP_EXCEPTION_CLASS(binding_not_found, std::string("binding not found: '") + message + "'" )
RCPP_EXCEPTION_CLASS(binding_is_locked, std::string("binding is locked: '") + message + "'" )
RCPP_EXCEPTION_CLASS(no_such_namespace, std::string("no such namespace: '") + message + "'" )
RCPP_EXCEPTION_CLASS(eval_error, message )


#undef RCPP_EXCEPTION_CLASS
#undef RCPP_SIMPLE_EXCEPTION_CLASS

} // namesapce Rcpp

#endif
