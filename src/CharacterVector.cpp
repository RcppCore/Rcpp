// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// CharacterVector.cpp: Rcpp R/C++ interface class library -- character vectors
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

#include <Rcpp/CharacterVector.h>
#include <Rcpp/exceptions.h>

namespace Rcpp{

CharacterVector::CharacterVector() : Base(){}

CharacterVector::CharacterVector(const CharacterVector& other) : Base(other.asSexp()){}

CharacterVector& CharacterVector::operator=(const CharacterVector& other ){
	setSEXP( other.asSexp() ) ;
	return *this ;
}

CharacterVector::CharacterVector(SEXP x) throw(not_compatible) : Base(x) {}

CharacterVector::CharacterVector(const size_t& size) : Base(size){}

CharacterVector::CharacterVector( const std::string& x) : Base(1) {
	SET_STRING_ELT( m_sexp, 0, Rf_mkChar( x.c_str() ) ) ;
}

CharacterVector::CharacterVector( const std::vector<std::string>& x): Base() {
	assign( x.begin(), x.end() ) ;
}

CharacterVector::CharacterVector( const Dimension& dims): Base(dims){}

/* proxy stuff */

internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy(CharacterVector& v, int i) :
	parent(v), index(i){}

internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy(const VectorElement_Proxy& other) :
	parent(other.parent), index(other.index){}

internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy::operator SEXP() const{
	return STRING_ELT( parent, index ) ;
}

internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy::operator /*const*/ char*() const {
	return const_cast<char*>( CHAR(STRING_ELT( parent, index )) );
}

// CharacterVector::Proxy::operator std::string() const {
// 	return std::string( CHAR(STRING_ELT( parent, index )) );
// }

internal::VectorElement_Proxy<STRSXP>& internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy::operator=( const VectorElement_Proxy& rhs){
	SET_STRING_ELT( parent, index, STRING_ELT( rhs.parent, rhs.index) ) ;
	return *this ;
}

internal::VectorElement_Proxy<STRSXP>& internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy::operator+=( const std::string& rhs){
	std::string full( CHAR(STRING_ELT(parent,index)) ) ;
	full += rhs ;
	SET_STRING_ELT( parent, index, Rf_mkChar( full.c_str() ) ) ;
	return *this ;
}

internal::VectorElement_Proxy<STRSXP>& internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy::operator+=( const VectorElement_Proxy& rhs){
	std::string full( CHAR(STRING_ELT(parent,index)) ) ;
	full += CHAR(STRING_ELT( rhs.parent, rhs.index)) ;
	SET_STRING_ELT( parent, index, Rf_mkChar(full.c_str()) ) ;
	return *this ;
}

internal::VectorElement_Proxy<STRSXP>& internal::VectorElement_Proxy<STRSXP>::VectorElement_Proxy::operator=( const std::string& rhs){
	SET_STRING_ELT( parent, index, Rf_mkChar( rhs.c_str() ) ) ;
	return *this ;
}

std::ostream& operator<<(std::ostream& os, const internal::VectorElement_Proxy<STRSXP>& proxy) {
    os << std::string(proxy) ;
    return os;
}

const CharacterVector::Proxy CharacterVector::operator[](int i) const throw(index_out_of_bounds){
	return Proxy(const_cast<CharacterVector&>(*this), offset(i) ) ;
}                                          

CharacterVector::Proxy CharacterVector::operator[](const std::string& name) throw(index_out_of_bounds) {
	return Proxy(*this, offset(name) ) ;
}

const CharacterVector::Proxy CharacterVector::operator[](const std::string& name) const throw(index_out_of_bounds){
	return Proxy(const_cast<CharacterVector&>(*this), offset(name) ) ;
}                                          

CharacterVector::Proxy CharacterVector::operator[](int i) throw(index_out_of_bounds) {
	return Proxy(*this, offset(i) ) ;
}


CharacterVector::Proxy CharacterVector::operator()( const size_t& i) throw(index_out_of_bounds){
	return Proxy(*this, offset(i) ) ;
}

CharacterVector::Proxy CharacterVector::operator()( const size_t& i, const size_t&j ) throw(index_out_of_bounds,not_a_matrix){
	return Proxy(*this, offset(i,j) ) ;
}

void internal::VectorElement_Proxy<STRSXP>::swap( VectorElement_Proxy& other){
	SEXP tmp = PROTECT( STRING_ELT(parent, index)) ;
	SET_STRING_ELT( parent, index, STRING_ELT(other.parent, other.index) ) ;
	SET_STRING_ELT( other.parent, other.index, tmp ) ;
	UNPROTECT(1) ;
}

} // namespace Rcpp

std::string operator+( const std::string& x, const Rcpp::internal::VectorElement_Proxy<STRSXP>& y ){
	return x + static_cast<const char*>(y) ;
}

namespace std{
	template<> 
	void swap< Rcpp::internal::VectorElement_Proxy<STRSXP> >( 
		Rcpp::internal::VectorElement_Proxy<STRSXP>& a, 
		Rcpp::internal::VectorElement_Proxy<STRSXP>& b){
	a.swap(b) ;
}
} ;


