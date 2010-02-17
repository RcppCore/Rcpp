// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Symbol.cpp: Rcpp R/C++ interface class library -- Symbols
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

#include <Rcpp/SEXP_Vector.h>

namespace Rcpp{

/* proxy */
	
SEXP_Vector_Base::Proxy::Proxy(SEXP_Vector_Base& v, size_t i):
	parent(v), index(i) {};

void SEXP_Vector_Base::Proxy::set(SEXP x){
	SET_VECTOR_ELT( parent, index, x ) ;
}

SEXP SEXP_Vector_Base::Proxy::get() const {
	return VECTOR_ELT(parent, index );
}

SEXP_Vector_Base::Proxy& SEXP_Vector_Base::Proxy::operator=(SEXP rhs){
	set(rhs); 
	return *this ;
}

SEXP_Vector_Base::Proxy& SEXP_Vector_Base::Proxy::operator=(const Proxy& rhs){
	set(rhs.get());
	return *this ;
}

void SEXP_Vector_Base::Proxy::swap(Proxy& other){
	SEXP tmp = PROTECT( get() ) ;
	set( other.get() ) ;
	other.set( tmp ) ;
	UNPROTECT(1) ;
}

void SEXP_Vector_Base::Proxy::move(int n){
	index += n ;
}

/* iterator */

SEXP_Vector_Base::iterator::iterator( SEXP_Vector_Base& object, int index_):
	proxy(object,index_){}

/* SEXP_Vector_Base */
SEXP_Vector_Base::SEXP_Vector_Base() : VectorBase(){}

SEXP_Vector_Base::Proxy SEXP_Vector_Base::operator()( const size_t& i) throw(index_out_of_bounds) {
	return Proxy(*this, offset(i) ) ;
}
SEXP_Vector_Base::Proxy SEXP_Vector_Base::operator()( const size_t& i, const size_t& j) throw(index_out_of_bounds,not_a_matrix){
	return Proxy(*this, offset(i,j) ) ;
}

} // namespace Rcpp

namespace std{
template<> void swap( Rcpp::SEXP_Vector_Base::Proxy& a, Rcpp::SEXP_Vector_Base::Proxy& b){
	a.swap(b) ;
}
}

