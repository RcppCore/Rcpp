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

class not_a_matrix : public std::exception{
	public:
		not_a_matrix(){} ;
		virtual ~not_a_matrix() throw() {} ;
		virtual const char* what() const throw() { return "not a matrix" ; };
	} ;

class index_out_of_bounds: public std::exception{
   	public:
   		index_out_of_bounds() throw(){};
   		virtual ~index_out_of_bounds() throw(){};
   		virtual const char* what() const throw(){ return "index out of bounds" ; } ;
   	} ;
   		
class parse_error : public std::exception{
	public:
		parse_error() throw(){};
		virtual ~parse_error() throw(){};
		virtual const char* what() const throw(){ return "parse error" ; } ;
	} ;

class S4_creation_error : public std::exception{
	public:
		S4_creation_error(const std::string& klass) throw() : message("error creating object of S4 class : ") {
			message += klass ;
		} ;
		virtual ~S4_creation_error() throw(){};
		virtual const char* what() const throw(){ return "" ; } ;
	private:
		std::string message ;
} ;


/**
  * Exception thrown when attempting to perform an operation on 
  * a binding and there is no such binding
  */
 class no_such_binding: public std::exception{
 	public:
 		
 		no_such_binding() throw() : message(){}
 		no_such_binding(const no_such_binding& other) throw() : message(other.message){} ;
 		no_such_binding& operator=( const no_such_binding& other ){
 			message = other.message ; 
 			return *this ;
 		}
 		/**
 		 * @param binding name of the binding
 		 */
 		no_such_binding( const std::string& binding) throw() : 
 		 	message( std::string("no such binding : '") + binding + "'" ) {};
 		
 		virtual ~no_such_binding() throw(){} ;
 		
 		/**
 		 * The message: no such binding : '{binding}' 
 		 */
 		 virtual const char* what() const throw(){ return message.c_str() ; }
 		
 	private:
 		std::string message ;
 } ;
    

} // namesapce Rcpp

#endif
