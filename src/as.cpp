// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// as.cpp: Rcpp R/C++ interface class library -- generic converters from SEXP
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

#include <RcppCommon.h>

namespace Rcpp{ 

template<> SEXP as<SEXP>(SEXP m_sexp){
	return m_sexp ;
}

template<> double as<double>(SEXP m_sexp) {
    if (Rf_length(m_sexp) != 1) {
	throw std::range_error("as<double> expects single value");
    }
    switch( TYPEOF(m_sexp) ){
    	case LGLSXP:
    		return internal::r_coerce<LGLSXP,REALSXP>( LOGICAL(m_sexp)[0] ) ; 
    	case REALSXP:
    		return REAL(m_sexp)[0] ; 
    	case INTSXP:
    		return internal::r_coerce<INTSXP,REALSXP>( INTEGER(m_sexp)[0] ); 
    	case RAWSXP:
    		return internal::r_coerce<RAWSXP,REALSXP>( RAW(m_sexp)[0] );
    	default:
    		throw std::range_error("as<double> invalid type");
    }
    return 0.0 ; 	// never reached
}

template<> int as<int>(SEXP m_sexp) {
    if (Rf_length(m_sexp) != 1) {
	throw std::range_error("as<int> expects single value");
    }
    switch( TYPEOF(m_sexp)){
    	case LGLSXP:
    		return internal::r_coerce<LGLSXP,INTSXP>( LOGICAL(m_sexp)[0] ) ; 
    	case REALSXP:
    		return internal::r_coerce<REALSXP,INTSXP>( REAL(m_sexp)[0] ); // some of this might be lost
    	case INTSXP:
    		return INTEGER(m_sexp)[0]; 
    	case RAWSXP:
    		return internal::r_coerce<RAWSXP,INTSXP>( RAW(m_sexp)[0] );
    	default:
    		throw std::range_error("as<int>");
    }
    return 0; 	// never reached
}

template<> Rbyte as<Rbyte>(SEXP m_sexp) {
    if (Rf_length(m_sexp) != 1) {
	throw std::range_error("as<Rbyte> expects single value");
    }
    switch( TYPEOF(m_sexp) ){
    	case LGLSXP:
    		return internal::r_coerce<LGLSXP,RAWSXP>( LOGICAL(m_sexp)[0] ) ; 
    	case REALSXP:
    		return internal::r_coerce<REALSXP,RAWSXP>( REAL(m_sexp)[0] );
    	case INTSXP:
    		return internal::r_coerce<INTSXP,RAWSXP>( INTEGER(m_sexp)[0] );
    	case RAWSXP:
    		return RAW(m_sexp)[0] ;
    	default:
    		throw std::range_error("as<Rbyte> expects raw, double or int");
    }
    return (Rbyte)0; 	// never reached
}

template<> bool as<bool>(SEXP m_sexp) {
    if (Rf_length(m_sexp) != 1) {
	throw std::range_error("as<bool> expects single value");
    }
    switch( TYPEOF(m_sexp) ){
    	case LGLSXP:
    		return LOGICAL(m_sexp)[0] ? true : false ; 
    	case REALSXP:
    		return double_to_bool( REAL(m_sexp)[0] ) ;
    	case INTSXP:
    		return int_to_bool( INTEGER(m_sexp)[0] ) ;
    	case RAWSXP:
    		return Rbyte_to_bool( RAW(m_sexp)[0] );
    	default:
    		throw std::range_error("as<bool> expects raw, double or int");
    }
    return false; 	// never reached
}

template<> std::string as<std::string>(SEXP m_sexp) {
    if (Rf_length(m_sexp) != 1) {
    	    throw std::range_error("as<std::string> expects single value");
    }
    if (!Rf_isString(m_sexp)) {
    	    throw std::range_error("as<std::string> expects string");
    }
    return std::string(CHAR(STRING_ELT(m_sexp,0)));
}

template<> std::vector<std::string> as< std::vector<std::string> >(SEXP m_sexp){
    R_len_t n = Rf_length(m_sexp);
    std::vector<std::string> v(n);
    if (!Rf_isString(m_sexp)) {
    	    throw std::range_error("as< vector<string> >:  expects string");
    }
    for (int i = 0; i < n; i++) {
	v[i] = std::string(CHAR(STRING_ELT(m_sexp,i)));
    }
    return v;
}

} // namespace Rcpp

