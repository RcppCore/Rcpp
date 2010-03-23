// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// exceptions.cpp: R/C++ interface class library -- exception handling
//
// Copyright (C) 2009 - 2010 Dirk Eddelbuettel and Romain Francois
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

/* for now, the fancy exception handling is only available in GCC, 
   simply because we've not investigated if it is available in other 
   compilers */
#ifdef __GNUC__
#include <typeinfo>
#include <exception_defines.h>
#include <cxxabi.h>

std::string demangle( const char* name){
	std::string real_class ;
	int status =-1 ;
	char *dem = 0;
	dem = abi::__cxa_demangle(name, 0, 0, &status);
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
#ifdef __EXCEPTIONS    	
    } catch (std::exception &exc) { 
    	exception_what = exc.what() ;
#endif
    } catch (...) { 
    	exception_what = "unrecognized exception" ;
    }
    
    Rf_eval( 
	    Rf_lang3( 
		     Rf_install("cpp_exception"), 
		     Rf_mkString(exception_what.c_str()), 
		     has_exception_class ? Rf_mkString(exception_class.c_str()) : R_NilValue
		      ), R_FindNamespace(Rf_mkString("Rcpp"))
	     ) ; 
}

#else
void forward_uncaught_exceptions_to_r(){
	Rf_eval( 
	    Rf_lang3( 
		     Rf_install("cpp_exception"), 
		     Rf_mkString("exception : we don't know how to get the exception message with your compiler, patches welcome"), 
		     R_NilValue ), R_FindNamespace(Rf_mkString("Rcpp"))
	     ) ; 
}
std::string demangle( const char* name){
	return std::string( name ) ;	
}
#endif
SEXP initUncaughtExceptionHandler(){
    /* FIXME: we might want to restore the original handler as the package
              gets unloaded */
    std::set_terminate(forward_uncaught_exceptions_to_r);
    return R_NilValue ;
}

