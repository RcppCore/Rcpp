// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// RcppCommon.cpp: R/C++ interface class library -- common functions
//
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
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

#include <Rcpp.h>
#include <cstring>
#include <stdio.h>

void logTxtFunction(const char* file, const int line, const char* expression) {
    Rprintf("%s:%d %s\n", file, line, expression);
}

SEXP capabilities(){
	SEXP cap = PROTECT( Rf_allocVector( LGLSXP, 8) ) ;
	SEXP names = PROTECT( Rf_allocVector( STRSXP, 8 ) ) ;
#ifdef HAS_VARIADIC_TEMPLATES
	LOGICAL(cap)[0] = TRUE ;
#else
	LOGICAL(cap)[0] = FALSE ;
#endif
#ifdef HAS_CXX0X_INITIALIZER_LIST
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

	LOGICAL(cap)[5] = TRUE ;

#ifdef RCPP_HAS_DEMANGLING
	LOGICAL(cap)[6] = TRUE ;
#else
	LOGICAL(cap)[6] = FALSE ;
#endif

	LOGICAL(cap)[7] = FALSE ;

	SET_STRING_ELT(names, 0, Rf_mkChar("variadic templates") ) ;
	SET_STRING_ELT(names, 1, Rf_mkChar("initializer lists") ) ;
	SET_STRING_ELT(names, 2, Rf_mkChar("exception handling") ) ;
	SET_STRING_ELT(names, 3, Rf_mkChar("tr1 unordered maps") ) ;
	SET_STRING_ELT(names, 4, Rf_mkChar("tr1 unordered sets") ) ;
	SET_STRING_ELT(names, 5, Rf_mkChar("Rcpp modules") ) ;
	SET_STRING_ELT(names, 6, Rf_mkChar("demangling") ) ;
	SET_STRING_ELT(names, 7, Rf_mkChar("classic api") ) ;
	Rf_setAttrib( cap, R_NamesSymbol, names ) ;
	UNPROTECT(2) ;
	return cap ;
}

const char * sexp_to_name(int sexp_type) {
    switch (sexp_type) {
    case NILSXP:	return "NILSXP";
    case SYMSXP:	return "SYMSXP";
    case RAWSXP:	return "RAWSXP";
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

namespace Rcpp{
namespace internal{

	template<> int* r_vector_start<INTSXP>(SEXP x){ return INTEGER(x) ; }
	template<> int* r_vector_start<LGLSXP>(SEXP x){ return LOGICAL(x) ; }
	template<> double* r_vector_start<REALSXP>(SEXP x){ return REAL(x) ; }
	template<> Rbyte* r_vector_start<RAWSXP>(SEXP x){ return RAW(x) ; }
	template<> Rcomplex* r_vector_start<CPLXSXP>(SEXP x){ return COMPLEX(x) ; }
	
	template<> void r_init_vector<VECSXP>(SEXP x){}
	template<> void r_init_vector<EXPRSXP>(SEXP x){}
	template<> void r_init_vector<STRSXP>(SEXP x){}

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
	
	SEXP convert_using_rfunction(SEXP x, const char* const fun) {
        SEXP res = R_NilValue ;
        try{
            SEXP funSym = Rf_install(fun);
            res = Evaluator::run( Rf_lang2( funSym, x ) ) ;
        } catch( eval_error& e){
            throw ::Rcpp::not_compatible( std::string("could not convert using R function : ") + fun  ) ;
        }
        return res;
    }
    
    SEXP try_catch( SEXP expr, SEXP env ) {
        return Evaluator::run(expr, env) ;
    }
    SEXP try_catch( SEXP expr ) {
        return Evaluator::run(expr) ;
    }
    
    SEXP eval_methods<EXPRSXP>::eval(){
        SEXP xp = ( static_cast<ExpressionVector&>(*this) ).asSexp() ;
        SEXP evalSym = Rf_install( "eval" );
        return try_catch( Rf_lang2( evalSym, xp ) ) ;
    }
    
    SEXP eval_methods<EXPRSXP>::eval( SEXP env ){
        SEXP xp = ( static_cast<ExpressionVector&>(*this) ).asSexp() ;
        SEXP evalSym = Rf_install( "eval" );
        return try_catch( Rf_lang3( evalSym, xp, env ) ) ;
    }
	
} // internal
} // Rcpp

SEXP rcpp_call_test(SEXP x){
	return Rf_ScalarInteger( ::Rcpp::internal::rcpp_call_test_(x) ) ;
}

SEXP as_character_externalptr(SEXP xp){
	char buffer[20] ;
	sprintf( buffer, "%p", (void*)EXTPTR_PTR(xp) ) ;
	return Rcpp::wrap( (const char*)buffer ) ;
}

SEXP exception_to_try_error( const std::exception& ex ){
    return string_to_try_error(ex.what());
}

SEXP string_to_try_error( const std::string& str){

    using namespace Rcpp;
	
    // form simple error condition based on a string
    SEXP rcppNS = PROTECT(R_FindNamespace(Rf_mkString("Rcpp")));
    SEXP simpleErrorExpr = PROTECT(::Rcpp_lcons(::Rf_install("simpleError"),
                                            pairlist(str, R_NilValue)));
    SEXP simpleError = PROTECT(Rf_eval(simpleErrorExpr, rcppNS));
	
    // create the try-error structure
    SEXP structureExpr = PROTECT(::Rcpp_lcons(::Rf_install("structure"), 
        pairlist(str, _["class"] = "try-error", _["condition"] = simpleError)));
    SEXP tryError = PROTECT(Rf_eval(structureExpr, rcppNS));
	
    // unprotect and return
    UNPROTECT(5);
    return tryError;
}
