// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
// jedit: :folding=explicit:
//
// api.cpp: Rcpp R/C++ interface class library -- Rcpp api
//
// Copyright (C) 2012 - 2013  Dirk Eddelbuettel and Romain Francois
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
  
#define COMPILING_RCPP

#include <Rcpp.h>

#include "internal.h" 
#include <R_ext/PrtUtil.h>

#ifdef RCPP_HAS_DEMANGLING
#include <cxxabi.h>
#endif

#if defined(__GNUC__)
    #if defined(WIN32) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__sun)
    #else
        #include <execinfo.h>
        
        static std::string demangler_one( const char* input){
            static std::string buffer ;
            buffer = input ;
            buffer.resize( buffer.find_last_of( '+' ) - 1 ) ;
            buffer.erase(
                buffer.begin(), 
                buffer.begin() + buffer.find_last_of( ' ' ) + 1
            ) ;
            return demangle( buffer) ;
        }

    #endif
#endif


namespace Rcpp {
     
    namespace internal{
        namespace {
            unsigned long RNGScopeCounter = 0;
        }
        
        // [[Rcpp::register]]
        void enterRNGScope() {       
            if (RNGScopeCounter == 0) GetRNGstate();       
            RNGScopeCounter++;
        }
        
        // [[Rcpp::register]]
        void exitRNGScope() {
            RNGScopeCounter--;
            if (RNGScopeCounter == 0) PutRNGstate();
        }
        
        // [[Rcpp::register]]
        char* get_string_buffer(){
            static char buffer[MAXELTSIZE];
            return buffer ;    
        }

    }
    
    // [[Rcpp::register]]
    SEXP Rcpp_eval(SEXP expr, SEXP env) {
        PROTECT(expr);
        
        reset_current_error() ; 
        
        Environment RCPP = Environment::Rcpp_namespace(); 
        static SEXP tryCatchSym = NULL, evalqSym, conditionMessageSym, errorRecorderSym, errorSym ;
        if (!tryCatchSym) {
            tryCatchSym               = ::Rf_install("tryCatch");
            evalqSym                  = ::Rf_install("evalq");
            conditionMessageSym       = ::Rf_install("conditionMessage");
            errorRecorderSym          = ::Rf_install(".rcpp_error_recorder");
            errorSym                  = ::Rf_install("error");
        }
        
        SEXP call = PROTECT( Rf_lang3( 
            tryCatchSym, 
            Rf_lang3( evalqSym, expr, env ),
            errorRecorderSym
        ) ) ;
        SET_TAG( CDDR(call), errorSym ) ;
        /* call the tryCatch call */
        SEXP res  = PROTECT(::Rf_eval( call, RCPP ) );
        
        UNPROTECT(3) ;
        
        if( error_occured() ) {
            SEXP current_error        = PROTECT( rcpp_get_current_error() ) ;
            SEXP conditionMessageCall = PROTECT(::Rf_lang2(conditionMessageSym, current_error)) ;
            SEXP condition_message    = PROTECT(::Rf_eval(conditionMessageCall, R_GlobalEnv)) ;
            std::string message(CHAR(::Rf_asChar(condition_message)));
            UNPROTECT( 3 ) ;
            throw eval_error(message) ;
        }
        
        return res ;
    }
    
    // [[Rcpp::register]]  
    std::string demangle( const std::string& name ){
        #ifdef RCPP_HAS_DEMANGLING
            std::string real_class ;
            int status =-1 ;
            char *dem = 0;
            dem = abi::__cxa_demangle(name.c_str(), 0, 0, &status);
            if( status == 0 ){
                real_class = dem ;
                free(dem);
            } else {
                real_class = name ;
            }
            return real_class ;
        #else
            return name ;
        #endif    
    }
      
    // [[Rcpp::register]]
    const char * type2name(SEXP x) {
        switch (TYPEOF(x)) {
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
    
    // [[Rcpp::internal]]
    SEXP rcpp_capabilities(){
        Shield<SEXP> cap( Rf_allocVector( LGLSXP, 9 ) );
        Shield<SEXP> names( Rf_allocVector( STRSXP, 9 ) );
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
        /* exceptions are always supported */
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
        
        #ifdef RCPP_HAS_LONG_LONG_TYPES
            LOGICAL(cap)[8] = TRUE ;
        #else
            LOGICAL(cap)[8] = FALSE ;
        #endif
        
        SET_STRING_ELT(names, 0, Rf_mkChar("variadic templates") ) ;
        SET_STRING_ELT(names, 1, Rf_mkChar("initializer lists") ) ;
        SET_STRING_ELT(names, 2, Rf_mkChar("exception handling") ) ;
        SET_STRING_ELT(names, 3, Rf_mkChar("tr1 unordered maps") ) ;
        SET_STRING_ELT(names, 4, Rf_mkChar("tr1 unordered sets") ) ;
        SET_STRING_ELT(names, 5, Rf_mkChar("Rcpp modules") ) ;
        SET_STRING_ELT(names, 6, Rf_mkChar("demangling") ) ;
        SET_STRING_ELT(names, 7, Rf_mkChar("classic api") ) ;
        SET_STRING_ELT(names, 8, Rf_mkChar("long long") ) ;
        Rf_setAttrib( cap, R_NamesSymbol, names ) ;
        return cap ;
    }
 

    // [[Rcpp::internal]]
    SEXP rcpp_can_use_cxx0x(){ 
        #ifdef HAS_VARIADIC_TEMPLATES
            return Rf_ScalarLogical( TRUE );
        #else
            return Rf_ScalarLogical( FALSE );
        #endif
    }
    
    // [[Rcpp::internal]]
    SEXP as_character_externalptr(SEXP xp){
        char buffer[20] ;
        sprintf( buffer, "%p", (void*)EXTPTR_PTR(xp) ) ;
        return Rcpp::wrap( (const char*)buffer ) ;
    }
      
    // [[Rcpp::register]]
    const char* short_file_name(const char* file){
        std::string f(file) ;
        size_t index = f.find("/include/") ;
        if( index != std::string::npos ){ 
            f = f.substr( index + 9 ) ;
        }
        return f.c_str() ;
    }
    
    
} // namespace Rcpp

// [[Rcpp::register]]
SEXP stack_trace( const char* file, int line ){
    #if defined(__GNUC__)
        #if defined(WIN32) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__sun)
            // Simpler version for Windows and *BSD 
            Rcpp::List trace = Rcpp::List::create( 
                Rcpp::Named( "file"  ) = file, 
                Rcpp::Named( "line"  ) = line, 
                Rcpp::Named( "stack" ) = "C++ stack not available on this system" ) ;
            trace.attr("class") = "Rcpp_stack_trace" ;
            return trace ;
        }
        #else // ! (defined(WIN32) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__sun)
        
            /* inspired from http://tombarta.wordpress.com/2008/08/01/c-stack-traces-with-gcc/  */ 
            const size_t max_depth = 100;
            size_t stack_depth;
            void *stack_addrs[max_depth];
            char **stack_strings;
            
            stack_depth = backtrace(stack_addrs, max_depth);
            stack_strings = backtrace_symbols(stack_addrs, stack_depth);
            
            std::string current_line ;
            
            Rcpp::CharacterVector res( stack_depth - 1) ;
            std::transform( 
                stack_strings + 1, stack_strings + stack_depth, 
                res.begin(), 
                demangler_one 
            ) ;
            free(stack_strings); // malloc()ed by backtrace_symbols
            
            Rcpp::List trace = Rcpp::List::create( 
                Rcpp::Named( "file"  ) = file, 
                Rcpp::Named( "line"  ) = line, 
                Rcpp::Named( "stack" ) = res
            ) ;
            trace.attr("class") = "Rcpp_stack_trace" ;
            return trace ;
        #endif 
    #else /* !defined( __GNUC__ ) */
	    return R_NilValue ;
	#endif 
}
// }}}

