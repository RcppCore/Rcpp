// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Module_Add_Property.h: Rcpp R/C++ interface class library -- Rcpp modules
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

#ifndef Rcpp_Module_Field_h
#define Rcpp_Module_Field_h
	
	// getter through a member function
	template <typename PROP>
	class CppProperty_Getter_Setter : public CppProperty<Class> {
		public: 	
			typedef PROP Class::*pointer ;
			
			CppProperty_Getter_Setter( pointer ptr_ ) : ptr(ptr_), class_name(DEMANGLE(PROP)) {}
			
			SEXP get(Class* object) throw(std::range_error){ return Rcpp::wrap( object->*ptr ) ; }
			void set(Class* object, SEXP value) throw(std::range_error,Rcpp::not_compatible){ object->*ptr = Rcpp::as<PROP>( value ) ; }		
			bool is_readonly(){ return false ; }
			std::string get_class(){ return class_name; }
			
		private:
			pointer ptr ;
			std::string class_name ;
	} ;
	
	
	// getter through a member function
	template <typename PROP>
	class CppProperty_Getter : public CppProperty<Class> {
		public: 	
			typedef PROP Class::*pointer ;
			
			CppProperty_Getter( pointer ptr_ ) : ptr(ptr_), class_name(DEMANGLE(PROP)) {}
			
			SEXP get(Class* object) throw(std::range_error){ return Rcpp::wrap( object->*ptr ) ; }
			void set(Class* object, SEXP value) throw(std::range_error,Rcpp::not_compatible){ throw std::range_error("read only data member") ; }		
			bool is_readonly(){ return true ; }
			std::string get_class(){ return class_name; }
			
		private:
			pointer ptr ;
			std::string class_name ;
	} ;

	
	template <typename T>
	self& field( const char* name_, T Class::*ptr ){
		AddProperty( name_, 
			new CppProperty_Getter_Setter<T>( ptr )
		) ;
		return *this ;
	}
	
	template <typename T>
	self& field_readonly( const char* name_, T Class::*ptr ){
		AddProperty( name_, 
			new CppProperty_Getter<T>( ptr )
		) ;
		return *this ;
	}

#endif
