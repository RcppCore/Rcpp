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

template<> std::vector<bool> as< std::vector<bool> >(SEXP m_sexp) {
    R_len_t n = Rf_length(m_sexp);
    std::vector<bool> v(n);
    switch( TYPEOF(m_sexp) ){
    case LGLSXP:
    	std::transform( LOGICAL(m_sexp), LOGICAL(m_sexp)+n, v.begin(), Rboolean_to_bool ) ;
    	break ;
    case INTSXP:
    	std::transform( INTEGER(m_sexp), INTEGER(m_sexp)+n, v.begin(), int_to_bool ) ;
    	break;
    case REALSXP:
    	std::transform( REAL(m_sexp), REAL(m_sexp)+n, v.begin(), double_to_bool ) ;
    	break;
    case RAWSXP:
    	std::transform( RAW(m_sexp), RAW(m_sexp)+n, v.begin(), Rbyte_to_bool ) ;
    	break;
    default:
    		throw std::range_error( "as< vector<bool> >: invalid R type" ) ; 
    }
    return v;
}


template<> std::vector<int> as< std::vector<int> >(SEXP m_sexp){
    R_len_t n = Rf_length(m_sexp);
    std::vector<int> v(n);
    switch( TYPEOF(m_sexp) ){
    case INTSXP:
    	v.assign( INTEGER(m_sexp), INTEGER(m_sexp)+n ) ;
    	break;
    case LGLSXP:
    	std::transform( LOGICAL(m_sexp), LOGICAL(m_sexp)+n, v.begin(), internal::r_coerce<LGLSXP,INTSXP> ) ;
    	break;
    case REALSXP:
    	std::transform( REAL(m_sexp), REAL(m_sexp)+n, v.begin(), internal::r_coerce<REALSXP,INTSXP> ) ;
    	break;
    case RAWSXP:
    	std::transform( RAW(m_sexp), RAW(m_sexp)+n, v.begin(), internal::r_coerce<RAWSXP,INTSXP> ) ;
    	break;
    default:
    		throw std::range_error( "as< vector<int> >: invalid R type" ) ; 
    }
    return v;
}

template<> std::vector<Rbyte> as< std::vector<Rbyte> >(SEXP m_sexp) {
    R_len_t n = Rf_length(m_sexp);
    std::vector<Rbyte> v(n);
    switch( TYPEOF(m_sexp) ){
    case LGLSXP:
    	std::transform( LOGICAL(m_sexp), LOGICAL(m_sexp)+n, v.begin(), internal::r_coerce<LGLSXP,RAWSXP> ) ;
    	break ;
    case RAWSXP:
    	v.assign( RAW(m_sexp), RAW(m_sexp)+n ) ;
    	break ;
    case REALSXP:
    	std::transform( REAL(m_sexp), REAL(m_sexp)+n, v.begin(), internal::r_coerce<REALSXP,RAWSXP> ) ;
    	break;
    case INTSXP:
    	std::transform( INTEGER(m_sexp), INTEGER(m_sexp)+n, v.begin(), internal::r_coerce<INTSXP,RAWSXP> ) ;
    	break;
    default:
    	throw std::range_error("as< vector<Rbyte> > expects raw, double or int");
    }
    return v;
}

template<> std::vector<double> as< std::vector<double> >(SEXP m_sexp){
    R_len_t n = Rf_length(m_sexp);
    std::vector<double> v(n);
    switch( TYPEOF(m_sexp) ){
    case LGLSXP:
    	std::transform( LOGICAL(m_sexp), LOGICAL(m_sexp)+n, v.begin(), internal::r_coerce<LGLSXP,REALSXP> ) ;
    	break ;
    case RAWSXP:
    	std::transform( RAW(m_sexp), RAW(m_sexp)+n, v.begin(), internal::r_coerce<RAWSXP,REALSXP> ) ;
    	break ;
    case REALSXP:
    	v.assign( REAL(m_sexp), REAL(m_sexp)+n) ;
    	break;
    case INTSXP:
    	std::transform( INTEGER(m_sexp), INTEGER(m_sexp)+n, v.begin(), internal::r_coerce<INTSXP,REALSXP>) ;
    	break;
    default:
    	    throw std::range_error("as< vector<double> >:  expects raw, double or int");
    }
    return v;
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

