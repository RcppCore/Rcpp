// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// any.h: Rcpp R/C++ interface class library -- any
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__sugar__any_h
#define Rcpp__sugar__any_h

namespace Rcpp{
namespace sugar{

template <typename T>
class Any : public SingleLogicalResult< true, Any<T> >{
public:
	typedef SingleLogicalResult< true , Any<T> > PARENT ;
	Any( const T& t ) : PARENT() , object(t) {}
	
	void apply(){
		apply__impl( typename can_have_na<T>::type() ) ;
	}	
private:		
	const T& object ;

	// version that takes NA into account
	void apply__impl( Rcpp::traits::true_type ){
		int n = object.size() ;
		int current = 0 ;
		PARENT::reset() ;
		for( int i=0 ; i<n ; i++){
			current = object[i] ;
			if( current == TRUE ) {
				PARENT::set_true() ; 
				return ;
			}
			if( Rcpp::traits::is_na<LGLSXP>(current)  ) {
				PARENT::set_na();
			}
		}
		if( PARENT::is_unresolved() ){
			PARENT::set_false() ;
		}
	}
	
	// version to use when we know there is no NA
	void apply__impl( Rcpp::traits::false_type ){
		int n = object.size() ;
		PARENT::set_false() ;
		for( int i=0 ; i<n ; i++){
			if( object[i] == TRUE ) {
				PARENT::set_true() ; 
				return ;
			}
		}
	}
	
	
private:
} ;

} // sugar

template <typename T>
inline sugar::Any<T> any( const T& t){
	return sugar::Any<T>( t ) ;
}

} // Rcpp
#endif

