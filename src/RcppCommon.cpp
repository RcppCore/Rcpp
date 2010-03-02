// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppCommon.cpp: R/C++ interface class library -- common functions
//
// Copyright (C) 2005 - 2006 Dominick Samperi
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
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

#include <Rcpp.h>
#include <cstring>

// Paul Roebuck has observed that the memory used by an exception message
// is not reclaimed if error() is called inside of a catch block (due to
// a setjmp() call), and he suggested the following work-around.
char *copyMessageToR(const char* const mesg) {
    char* Rmesg;
    const char* prefix = "Exception: ";
    void* Rheap = R_alloc(strlen(prefix)+strlen(mesg)+1,sizeof(char));
    Rmesg = static_cast<char*>(Rheap);
    strcpy(Rmesg, prefix);
    strcat(Rmesg, mesg);
    return Rmesg;
}

inline void logTxtFunction(const char* file, const int line, const char* expression) {
    Rprintf("%s:%d %s\n", file, line, expression);
}

SEXP capabilities(){
	SEXP cap = PROTECT( Rf_allocVector( LGLSXP, 5) ) ;
	SEXP names = PROTECT( Rf_allocVector( STRSXP, 5 ) ) ;
#ifdef HAS_VARIADIC_TEMPLATES
	LOGICAL(cap)[0] = TRUE ;
#else
	LOGICAL(cap)[0] = FALSE ;
#endif
#ifdef HAS_INIT_LISTS
	LOGICAL(cap)[1] = TRUE ;
#else
	LOGICAL(cap)[1] = FALSE ;
#endif
	/* exceptions are allways supported */
	LOGICAL(cap)[2] = TRUE ;

#ifdef HAS_TR1_UNORDERED_MAP
	LOGICAL(cap)[3] = TRUE ;
#else
	LOGICAL(cap)[3] = FALSE ;
#endif

#ifdef HAS_TR1_UNORDERED_SET
	LOGICAL(cap)[4] = TRUE ;
#else
	LOGICAL(cap)[4] = FALSE ;
#endif

	SET_STRING_ELT(names, 0, Rf_mkChar("variadic templates") ) ;
	SET_STRING_ELT(names, 1, Rf_mkChar("initializer lists") ) ;
	SET_STRING_ELT(names, 2, Rf_mkChar("exception handling") ) ;
	SET_STRING_ELT(names, 3, Rf_mkChar("tr1 unordered maps") ) ;
	SET_STRING_ELT(names, 4, Rf_mkChar("tr1 unordered sets") ) ;
	Rf_setAttrib( cap, R_NamesSymbol, names ) ;
	UNPROTECT(2) ;
	return cap ;
}


/* this is mainly here so that variadic template errors show up 
   at compile time */
SEXP test_named(){
#ifdef HAS_VARIADIC_TEMPLATES
	return Rcpp::Language( "foobar", Rcpp::Named("foo", 2 ), 2, Rcpp::Named("bar", 10) ) ;
#else
	return R_NilValue ;
#endif
}

const char * sexp_to_name(int sexp_type) {
    switch (sexp_type) {
    case NILSXP:	return "NILSXP";
    case SYMSXP:	return "SYMSXP";
    case LISTSXP:	return "LISTSXP";
    case CLOSXP:	return "CLOSXP";
    case ENVSXP:	return "ENVSXP";
    case PROMSXP:	return "PROMSXP";
    case LANGSXP:	return "LANGSXP";
    case SPECIALSXP:	return "SPECIALSXP";
    case BUILTINSXP:	return "BUILTINSXP";
    case CHARSXP:	return "CHARSXP";
    case LGLSXP:	return "LGLSXP";
    case INTSXP:	return "INTSXP";
    case REALSXP:	return "REALSXP";
    case CPLXSXP:	return "CPLXSXP";
    case STRSXP:	return "STRSXP";
    case DOTSXP:	return "DOTSXP";
    case ANYSXP:	return "ANYSXP";
    case VECSXP:	return "VECSXP";
    case EXPRSXP:	return "EXPRSXP";
    case BCODESXP:	return "BCODESXP";
    case EXTPTRSXP:	return "EXTPTRSXP";
    case WEAKREFSXP:	return "WEAKREFSXP";
    case S4SXP:		return "S4SXP";
    default:
	return "<unknown>";
    }
}

SEXP initRcpp(){
	initUncaughtExceptionHandler() ;
	return R_NilValue ;
}
   
namespace Rcpp{
namespace internal{

	template<> int* r_vector_start<INTSXP,int>(SEXP x){ return INTEGER(x) ; } ; 
	template<> int* r_vector_start<LGLSXP,int>(SEXP x){ return LOGICAL(x) ; };
	template<> double* r_vector_start<REALSXP,double>(SEXP x){ return REAL(x) ; } ;
	template<> Rbyte* r_vector_start<RAWSXP,Rbyte>(SEXP x){ return RAW(x) ; } ;
	template<> Rcomplex* r_vector_start<CPLXSXP,Rcomplex>(SEXP x){ return COMPLEX(x) ; } ;
	
	template<> void r_init_vector<VECSXP>(SEXP x){} ;
	template<> void r_init_vector<EXPRSXP>(SEXP x){} ;
	template<> void r_init_vector<STRSXP>(SEXP x){} ;

	template<> Rcomplex get_zero<CPLXSXP,Rcomplex>(){
		Rcomplex x ;
		x.r = 0.0 ;
		x.i = 0.0 ;
		return x ;
	}

	template<> Rcomplex caster<std::complex<double>, Rcomplex>( std::complex<double> from){
		Rcomplex cx ;
		cx.r = from.real() ; 
		cx.i = from.imag() ;
		return cx ;
	}
	template<> Rcomplex caster<std::complex<float>, Rcomplex>( std::complex<float> from){
		Rcomplex cx ;
		cx.r = static_cast<double>( from.real() ); 
		cx.i = static_cast<double>( from.imag() );
		return cx ;
	}

	template<> std::complex<double> caster<Rcomplex,std::complex<double> >( Rcomplex from){
		return std::complex<double>(from.r, from.i ) ;
	}
	template<> std::complex<float> caster<Rcomplex,std::complex<float> >( Rcomplex from){
		return std::complex<float>(static_cast<float>(from.r), static_cast<float>(from.i) ) ;
	}

	int rcpp_call_test_(SEXP x){
		RCPP_RETURN_VECTOR( rcpp_call_test, x );
	}
	
	
} // internal
} // Rcpp

SEXP rcpp_call_test(SEXP x){
	return Rf_ScalarInteger( ::Rcpp::internal::rcpp_call_test_(x) ) ;
}


SEXP RcppXPtrExample_create_external_pointer(){
	std::vector<int> *v = new std::vector<int> ;
	v->push_back( 1 ) ;
	v->push_back( 2 ) ;
	Rcpp::XPtr< std::vector<int> > p(v) ;
	return p ;
}

SEXP RcppXPtrExample_get_external_pointer(SEXP x){
	Rcpp::XPtr< std::vector<int> > p(x) ;
	return Rf_ScalarInteger( p->back( ) ) ;
}

