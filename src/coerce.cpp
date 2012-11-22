// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// coerce.cpp: Rcpp R/C++ interface class library -- coercion
//
// Copyright (C) 2010 - 2012 Dirk Eddelbuettel and Romain Francois
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

#include <R_ext/PrtUtil.h>

namespace Rcpp{ 
namespace internal{

template <> int r_coerce<INTSXP,INTSXP>(int from) { return from ; }
template <> int r_coerce<LGLSXP,LGLSXP>(int from) { return from ; }
template <> double r_coerce<REALSXP,REALSXP>(double from) { return from ; }
template <> Rcomplex r_coerce<CPLXSXP,CPLXSXP>(Rcomplex from) { return from ; }
template <> Rbyte r_coerce<RAWSXP,RAWSXP>(Rbyte from) { return from ; }

// -> INTSXP
template <> int r_coerce<LGLSXP,INTSXP>(int from){
	return (from==NA_LOGICAL) ? NA_INTEGER : from ;
}
template <> int r_coerce<REALSXP,INTSXP>(double from){
	if (ISNAN(from)) return NA_INTEGER;
	else if (from > INT_MAX || from <= INT_MIN ) {
		return NA_INTEGER;
	}
	return static_cast<int>(from);

}
template <> int r_coerce<CPLXSXP,INTSXP>(Rcomplex from){
	return r_coerce<REALSXP,INTSXP>(from.r) ;
}
template <> int r_coerce<RAWSXP,INTSXP>(Rbyte from){
	return static_cast<int>(from);
}

// -> REALSXP
template <> double r_coerce<LGLSXP,REALSXP>(int from){
	return from == NA_LOGICAL ? NA_REAL : static_cast<double>(from) ;
}
template <> double r_coerce<INTSXP,REALSXP>(int from){
	return from == NA_INTEGER ? NA_REAL : static_cast<double>(from) ; 
}
template <> double r_coerce<CPLXSXP,REALSXP>(Rcomplex from){
	return from.r ;
}
template <> double r_coerce<RAWSXP,REALSXP>(Rbyte from){
	return static_cast<double>(from) ;
}

// -> LGLSXP
template <> int r_coerce<REALSXP,LGLSXP>(double from){
	return ( from == NA_REAL ) ? NA_LOGICAL : (from!=0.0);
}
template <> int r_coerce<INTSXP,LGLSXP>(int from){
	return ( from == NA_INTEGER ) ? NA_LOGICAL : (from!=0);
}
template <> int r_coerce<CPLXSXP,LGLSXP>(Rcomplex from){
	if( from.r == NA_REAL ) return NA_LOGICAL ;
	if( from.r == 0.0 || from.i == 0.0 ) return FALSE ;
	return TRUE ;
}
template <> int r_coerce<RAWSXP,LGLSXP>(Rbyte from){
	if( from != static_cast<Rbyte>(0) ) return TRUE ;
	return FALSE ;
}

// -> RAWSXP
template <> Rbyte r_coerce<REALSXP,RAWSXP>(double from){
	if( from == NA_REAL) return static_cast<Rbyte>(0) ; 
	return r_coerce<INTSXP,RAWSXP>(static_cast<int>(from)) ;
}
template <> Rbyte r_coerce<INTSXP,RAWSXP>(int from){
	return (from < 0 || from > 255) ? static_cast<Rbyte>(0) : static_cast<Rbyte>(from) ;
}
template <> Rbyte r_coerce<CPLXSXP,RAWSXP>(Rcomplex from){
	return r_coerce<REALSXP,RAWSXP>(from.r) ;
}
template <> Rbyte r_coerce<LGLSXP,RAWSXP>(int from){
	return static_cast<Rbyte>(from == TRUE) ;
}

// -> CPLXSXP
template <> Rcomplex r_coerce<REALSXP,CPLXSXP>(double from){
	Rcomplex c ;
	if( from == NA_REAL ){
		c.r = NA_REAL; 
		c.i = NA_REAL;
	} else{
		c.r = from ;
		c.i = 0.0 ;
	}
	return c ;
}
template <> Rcomplex r_coerce<INTSXP,CPLXSXP>(int from){
	Rcomplex c ;
	if( from == NA_INTEGER ){
		c.r = NA_REAL; 
		c.i = NA_REAL;
	} else{
		c.r = static_cast<double>(from) ;
		c.i = 0.0 ;
	}
	return c ;
}
template <> Rcomplex r_coerce<RAWSXP,CPLXSXP>(Rbyte from){
	Rcomplex c ;
	c.r = static_cast<double>(from);
	c.i = 0.0 ;
	return c ;
}
template <> Rcomplex r_coerce<LGLSXP,CPLXSXP>(int from){
	Rcomplex c ;
	if( from == TRUE ){
		c.r = 1.0 ; c.i = 0.0 ;
	} else if( from == FALSE ){
		c.r = c.i = 0.0 ;
	} else { /* NA */
		c.r = c.i = NA_REAL;
	}
	return c ;
}

inline int integer_width( int n ){
    return n < 0 ? ( (int) ( log10( -n+0.5) + 2 ) ) : ( (int) ( log10( n+0.5) + 1 ) ) ;    
}

#define NB 1000
template <> SEXP r_coerce<INTSXP ,STRSXP>(int from){
    static char buffer[NB] ;
    if( from == NA_INTEGER ) return NA_STRING ;
    snprintf( buffer, NB, "%*d", integer_width(from), from );
    return Rf_mkChar(buffer) ;
}
template <> SEXP r_coerce<LGLSXP ,STRSXP>(int from){
    return from == NA_LOGICAL ? NA_STRING : (from == 0 ? Rf_mkChar("FALSE") : Rf_mkChar("TRUE") ) ;    
}
template <> SEXP r_coerce<RAWSXP ,STRSXP>(Rbyte from){
    char buff[3];
    ::sprintf(buff, "%02x", from);
    return Rf_mkChar( buff ) ;    
}


static const char* dropTrailing0(char *s, char cdec) {
    /* Note that  's'  is modified */
    char *p = s;
    for (p = s; *p; p++) {
	if(*p == cdec) {
	    char *replace = p++;
	    while ('0' <= *p  &&  *p <= '9')
		if(*(p++) != '0')
		    replace = p;
	    if(replace != p)
		while((*(replace++) = *(p++)))
		    ;
	    break;
	}
    }
    return s;
}

template <> SEXP r_coerce<REALSXP,STRSXP>(double x){
    if( Rcpp::traits::is_na<REALSXP>( x ) ) return NA_STRING ;
    
    int w,d,e ;
    Rf_formatReal( &x, 1, &w, &d, &e, 0 ) ;
    char* tmp = const_cast<char*>( Rf_EncodeReal(x, w, d, e, '.') );
	return Rf_mkChar(dropTrailing0(tmp, '.'));
        
}
template <> SEXP r_coerce<CPLXSXP,STRSXP>(Rcomplex x){
    if( Rcpp::traits::is_na<CPLXSXP>(x) ) return NA_STRING ;
    
    int wr, dr, er, wi, di, ei;
    Rf_formatComplex(&x, 1, &wr, &dr, &er, &wi, &di, &ei, 0);
    return Rf_mkChar( Rf_EncodeComplex(x, wr, dr, er, wi, di, ei, '.' ));
}


} // internal
} // Rcpp

