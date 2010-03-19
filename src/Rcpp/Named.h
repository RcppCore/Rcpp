// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Named.h: Rcpp R/C++ interface class library -- named object 
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

#ifndef Rcpp_Named_h
#define Rcpp_Named_h

#include <RcppCommon.h>

#include <Rcpp/Symbol.h>
#include <Rcpp/RObject.h>

namespace Rcpp{  

/** 
 * Facility to have named arguments in pairlist, such 
 * as Language objects
 */
class Named{
public:
	/** default constructor */
	Named( ) : object(R_MissingArg), tag("") {} ;
	
	/**
	 * @param tag name to give to the object 
	 * @param value value of the object
	 */
	Named( const std::string& tag, SEXP value ) : object(value), tag(tag) {}; 
	
	/**
	 * uses NULL as the value
	 * @param tag name to give to the object
	 */
	Named( const std::string& tag ) : object(R_MissingArg), tag(tag){} ;
	
	template<typename T>
	Named( const std::string& tag, const T& value ) : object(wrap(value)), tag(tag) {}
	
	/**
	 * This allows the syntax : 
	 * Language( "rnorm", Named( "mean" ) = 10 ) ;
	 */
	template <typename T>
	Named& operator=( const T& o ){
		object = wrap( o ) ;
		return *this ;
	}
	
	inline SEXP getSEXP() const { return object.asSexp() ; }
	
	inline std::string getTag() const { return tag ; }
	
private:
	RObject object ;
	std::string tag ;
} ;

namespace traits {

template <typename T> class named_object {
	public:
		named_object( const std::string& name_, const T& o_) : 
			name(name_), object(o_){} 
		const std::string& name ;
		const T& object ;
		operator ::Rcpp::Named(){
			return ::Rcpp::Named(name, object) ;	
		}
} ;

template <typename T>
named_object<T> named( const std::string& name, const T& o){
	return named_object<T>( name, o );	
} ;

template <typename T> struct is_named : public false_type{} ;
template <typename T> struct is_named< named_object<T> >   : public true_type {} ;


} // namespace traits


class Argument {
public:
	Argument() : name(){} ;
	Argument( const std::string& name_) : name(name_){} 
	
	template<typename T>
	traits::named_object<T> operator=( const T& t){
		return traits::named_object<T>( name, t ) ;	
	}
	
private:
	std::string name ;	
} ;


namespace internal{

class NamedPlaceHolder {
public:
	NamedPlaceHolder(){}
	~NamedPlaceHolder(){}
	Argument operator[]( const std::string& arg) const {
		return Argument( arg ) ;
	}
	Argument operator()(const std::string& arg) const {
		return Argument( arg ) ;
	}
	operator SEXP() const { return R_MissingArg ; }
} ;
} // internal

static internal::NamedPlaceHolder _ ;

} // namespace Rcpp

#endif
