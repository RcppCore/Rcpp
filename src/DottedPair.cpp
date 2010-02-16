// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// DottedPair.cpp: Rcpp R/C++ interface class library -- dotted pair lists
// base class of Language and Pairlist
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

#include <Rcpp/DottedPair.h>

namespace Rcpp {
	DottedPair::~DottedPair(){}
	DottedPair::DottedPair() : RObject(){}
	
	DottedPair& DottedPair::operator=(const DottedPair& other){
		setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	void DottedPair::remove( const size_t& index ) throw(index_out_of_bounds) {
		if( static_cast<R_len_t>(index) >= Rf_length(m_sexp) ) throw index_out_of_bounds() ;
		if( index == 0 ){
			setSEXP( CDR( m_sexp) ) ;
		} else{
			SEXP x = m_sexp ;
			size_t i=1;
			while( i<index ){ x = CDR(x) ; i++; }
			SETCDR( x, CDDR(x) ) ;
		}
	}
	
	DottedPair::Proxy::Proxy( DottedPair& v, const size_t& index_ ) throw(index_out_of_bounds) : node(){
		if( static_cast<R_len_t>(index_) >= v.length() ) throw index_out_of_bounds() ;
		SEXP x = v ; /* implicit conversion */
		size_t i = 0 ;
		while( i<index_) {
			x = CDR(x) ;
			++i ;
		}
		node = x ;
	}
	
	DottedPair::Proxy& DottedPair::Proxy::operator=(const Proxy& rhs){
		SEXP y = rhs ; /* implicit conversion */
		SETCAR( node, y ) ;
		return *this ;
	}
	
	DottedPair::Proxy& DottedPair::Proxy::operator=(SEXP rhs){
		SETCAR( node, rhs) ;
		return *this ;
	}
	
	DottedPair::Proxy& DottedPair::Proxy::operator=(const Named& rhs){
		SETCAR( node, rhs.getSEXP() ) ;
		SET_TAG( node, Rf_install( rhs.getTag().c_str() ) ) ;
		return *this ;
	}
	
	const DottedPair::Proxy DottedPair::operator[]( int i ) const {
		return Proxy( const_cast<DottedPair&>(*this), i) ;
	}
	DottedPair::Proxy DottedPair::operator[]( int i ) {
		return Proxy( *this, i );
	}
	
	
} // namespace Rcpp
