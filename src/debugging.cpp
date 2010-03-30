// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// debugging.cpp: R/C++ interface class library -- debugging helpers
//
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

#if defined(__GNUC__)
#if defined(WIN32)
/* silly version for windows */
SEXP stack_trace( const char* file, int line ){
    Rcpp::List trace = Rcpp::List::create( 
    	Rcpp::Named( "file"  ) = file, 
    	Rcpp::Named( "line"  ) = line, 
    	Rcpp::Named( "stack" ) = "C++ stack not available on windows (mingw does not have the execinfo.h file)" ) ;
    trace.attr("class") = "Rcpp_stack_trace" ;
    return trace ;
}
#else /* !defined(WIN32) */ 
#include <execinfo.h>
#include <cxxabi.h>

static std::string demangler_one( const char* input){
    static std::string buffer ;
    buffer = input ;
    buffer.resize( buffer.find_last_of( '+' ) - 1 ) ;
    buffer.erase(
	 buffer.begin(), 
	 buffer.begin() + buffer.find_last_of( ' ' ) + 1) ;
    return demangle( buffer) ;
}

/* inspired from http://tombarta.wordpress.com/2008/08/01/c-stack-traces-with-gcc/  */ 
SEXP stack_trace( const char *file, int line) {
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
    	Rcpp::Named( "stack" ) = res ) ;
    trace.attr("class") = "Rcpp_stack_trace" ;
    return trace ;
}
#endif 
#else /* !defined( __GNUC__ ) */
SEXP stack_trace( const char *file, int line) {
	return R_NilValue ;
}
#endif
