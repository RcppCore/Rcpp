// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// DataFrame.h: Rcpp R/C++ interface class library -- data frames
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

#ifndef Rcpp__DataFrame_h
#define Rcpp__DataFrame_h

#include <RcppCommon.h>
#include <Rcpp/Vector.h>

namespace Rcpp{
	
	namespace internal{
		inline SEXP empty_data_frame(){
			return ::Rf_eval( ::Rf_lang1( ::Rf_install("data.frame") ), R_GlobalEnv ) ;	
		}
	}
	
	class DataFrame : public List {
	public:	
		DataFrame(): List( internal::empty_data_frame() ){}
		
		DataFrame(SEXP x) throw(not_compatible) : List(){
			set(x) ;
		}
		
		DataFrame( const DataFrame& other): List(other.asSexp()) {}
		
		DataFrame( const RObject::SlotProxy& proxy ) throw(not_compatible){ set(proxy); }
		DataFrame( const RObject::AttributeProxy& proxy ) throw(not_compatible){ set(proxy); }
		
		DataFrame& operator=( DataFrame& other){
			setSEXP( other.asSexp() ) ;
			return *this ;
		}
		
		DataFrame& operator=( SEXP x) throw( not_compatible) {
			set(x) ;
			return *this ;
		}
		
		~DataFrame(){}

		static DataFrame create(){ return DataFrame() ; }
		
#include <Rcpp/DataFrame_generated.h>		

	private:
		void set(SEXP x) throw(not_compatible) {
			SEXP y = internal::convert_using_rfunction( x, "as.data.frame" ) ;
			setSEXP( y ) ;
		}
		
	} ;
	
}

#endif
