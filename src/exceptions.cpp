// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// exceptions.cpp: R/C++ interface class library -- exception handling
//
// Copyright (C) 2009 - 2012  Dirk Eddelbuettel and Romain Francois
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

namespace Rcpp{
    exception::exception(const char* message_) : message(message_) {}
    exception::exception( const char* message_, const char* file, int line) : message(message_){
	rcpp_set_stack_trace( stack_trace(file,line) ) ;
    }
    exception::~exception() throw(){}

#define RCPP_EXCEPTION_WHAT(__CLASS__)					\
    const char* __CLASS__::what() const throw(){ return message.c_str(); }

    RCPP_EXCEPTION_WHAT(exception)

    RCPP_EXCEPTION_WHAT(not_compatible)
    RCPP_EXCEPTION_WHAT(S4_creation_error)
    RCPP_EXCEPTION_WHAT(reference_creation_error)
    RCPP_EXCEPTION_WHAT(no_such_binding)
    RCPP_EXCEPTION_WHAT(binding_not_found)
    RCPP_EXCEPTION_WHAT(binding_is_locked)
    RCPP_EXCEPTION_WHAT(no_such_namespace)
    RCPP_EXCEPTION_WHAT(function_not_exported)
    RCPP_EXCEPTION_WHAT(eval_error)

#undef RCPP_EXCEPTION_WHAT

#define RCPP_SIMPLE_EXCEPTION_WHAT(__CLASS__,__MESSAGE__)		\
const char* __CLASS__::what() const throw(){ return __MESSAGE__ ; }

    RCPP_SIMPLE_EXCEPTION_WHAT(not_a_matrix, "not a matrix" )
    RCPP_SIMPLE_EXCEPTION_WHAT(index_out_of_bounds, "index out of bounds" )
    RCPP_SIMPLE_EXCEPTION_WHAT(parse_error, "parse error") 
    RCPP_SIMPLE_EXCEPTION_WHAT(not_s4, "not an S4 object" )
    RCPP_SIMPLE_EXCEPTION_WHAT(not_reference, "not a reference S4 object" )
    RCPP_SIMPLE_EXCEPTION_WHAT(not_initialized, "C++ object not initialized" )
    RCPP_SIMPLE_EXCEPTION_WHAT(no_such_slot, "no such slot" )
    RCPP_SIMPLE_EXCEPTION_WHAT(no_such_field, "no such field" )
    RCPP_SIMPLE_EXCEPTION_WHAT(not_a_closure, "not a closure" )
    RCPP_SIMPLE_EXCEPTION_WHAT(no_such_function, "no such function" )
    RCPP_SIMPLE_EXCEPTION_WHAT(unevaluated_promise, "promise not yet evaluated" )

#undef RCPP_SIMPLE_EXCEPTION_WHAT
}

// for now, the fancy exception handling is only available in GCC, 
// simply because we've not investigated if it is available in other 
// compilers 
#ifdef RCPP_HAS_DEMANGLING
#include <typeinfo>
#if defined(__GNUC__) && !defined(__clang__)
  #ifdef IS_EARLIER_THAN_GCC_460
    #include <exception_defines.h>
  #endif
  #ifdef IS_GCC_460_OR_LATER
    #include <bits/exception_defines.h>
  #endif
#endif
#ifdef __clang__
  #if __has_include(<exception_defines.h>)
    #include <exception_defines.h>
  #elif  __has_include(<bits/exception_defines.h>)
    #include <bits/exception_defines.h>
  #else
    #error clang could not find <exception_defines.h>
  #endif
#endif
#include <cxxabi.h>

std::string demangle( const std::string& name ){
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
}

/* much inspired from the __verbose_terminate_handler of the GCC */
void forward_uncaught_exceptions_to_r(){
	
    std::string exception_class ;
    bool has_exception_class = false;
    std::string exception_what ;
    
    // Make sure there was an exception; terminate is also called for an
    // attempt to rethrow when there is no suitable exception.
    std::type_info *t = abi::__cxa_current_exception_type();
    if (t){
    	has_exception_class = true ;
    	const char *name = t->name() ;
    	// now we need to demangle "name"
    	
    	{
	    int status = -1;
	    char *dem = 0;
	    dem = abi::__cxa_demangle(name, 0, 0, &status);
	    if( status == 0){
		exception_class = dem ; /* great we can use the demangled name */
		free(dem);
	    } else{
		exception_class = name ; /* just using the mangled name */
	    }
    	}
    }
	
    // If the exception is derived from std::exception, we can give more
    // information.
    try {              
    	__throw_exception_again;
    } catch (std::exception &exc) { 
    	exception_what = exc.what() ;
    } catch (...) { 
    	exception_what = "unrecognized exception" ;
    }
    
    SEXP cppExceptSym = Rf_install("cpp_exception"); 	// cannot cause a gc() once in symbol table
    SEXP cppExceptExpr = PROTECT(Rf_lang3(cppExceptSym,
					  Rf_mkString(exception_what.c_str()), 
					  has_exception_class ? Rf_mkString(exception_class.c_str()) : R_NilValue)); 
    Rf_eval(cppExceptExpr, R_FindNamespace(Rf_mkString("Rcpp"))); // Should not return
    UNPROTECT(1);    // in case someone replaces the definition of "cpp_exception" such that it does return
}
void forward_exception_to_r( const std::exception& ex){
    std::string exception_class ;
    std::string exception_what  = ex.what();
    const char *name = typeid(ex).name() ;
    // now we need to demangle "name"
    {
	int status = -1;
	char *dem = 0;
	dem = abi::__cxa_demangle(name, 0, 0, &status);
	if( status == 0){
	    exception_class = dem ; /* great we can use the demangled name */
	    free(dem);
	} else{
	    exception_class = name ; /* just using the mangled name */
	}
    }
    SEXP cppExceptSym = Rf_install("cpp_exception"); // cannot cause a gc() once in symbol table
    SEXP cppExceptExpr = PROTECT(Rf_lang3(cppExceptSym,
					  Rf_mkString(exception_what.c_str()), 
					  Rf_mkString(exception_class.c_str())));
    Rf_eval(cppExceptExpr, R_FindNamespace(Rf_mkString("Rcpp"))); // Should not return
    UNPROTECT(1);    // in case someone replaces the definition of "cpp_exception" such that it does return
}
#else
void forward_uncaught_exceptions_to_r(){
    SEXP cppExceptSym = Rf_install("cpp_exception"); // cannot cause a gc() once in symbol table
    SEXP cppExceptExpr = PROTECT(Rf_lang3(cppExceptSym,
					  Rf_mkString("exception : we don't know how to get the exception"
						      "message with your compiler, patches welcome"), 
					  R_NilValue)); 
    Rf_eval(cppExceptExpr, R_FindNamespace(Rf_mkString("Rcpp"))); 	 // Should not return 
    UNPROTECT(1);    // in case someone replaces the definition of "cpp_exception" such that it does return
}
void forward_exception_to_r( const std::exception& ex){
    SEXP cppExceptSym = Rf_install("cpp_exception"); // cannot cause a gc() once in symbol table
    SEXP cppExceptExpr = PROTECT(Rf_lang3(cppExceptSym, Rf_mkString(ex.what()), R_NilValue)); 
    Rf_eval(cppExceptExpr, R_FindNamespace(Rf_mkString("Rcpp"))); 	 // Should not return
    UNPROTECT(1);    // in case someone replaces the definition of "cpp_exception" such that it does return
}
std::string demangle( const std::string& name ){
	return name ;	
}
#endif
SEXP initUncaughtExceptionHandler(){
    /* FIXME: we might want to restore the original handler as the package
              gets unloaded */
    std::set_terminate(forward_uncaught_exceptions_to_r);
    return R_NilValue ;
}

