// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Rcpp_init.cpp : Rcpp R/C++ interface class library -- Initialize and register
//
// Copyright (C) 2010 - 2013 John Chambers, Dirk Eddelbuettel and Romain Francois
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

// borrowed from Matrix
#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}
#define EXTDEF(name)  {#name, (DL_FUNC) &name, -1}

static R_CallMethodDef callEntries[]  = {
    CALLDEF(Class__name,1),
    CALLDEF(Class__has_default_constructor,1),
    
    CALLDEF(CppClass__complete,1),
    CALLDEF(CppClass__methods,1),
    
    CALLDEF(CppObject__finalize,2),
    
    CALLDEF(Module__classes_info,1),
    CALLDEF(Module__complete,1),
    CALLDEF(Module__get_class,2),
    CALLDEF(Module__has_class,2),
    CALLDEF(Module__has_function,2),
    CALLDEF(Module__functions_arity,1),
    CALLDEF(Module__functions_names,1),
    CALLDEF(Module__name,1),
    CALLDEF(Module__get_function, 2),
    
    CALLDEF(get_rcpp_cache,0),
    CALLDEF(rcpp_error_recorder,1),
    CALLDEF(as_character_externalptr,1),
    
    CALLDEF(CppField__get,3),
    CALLDEF(CppField__set,4),
    
    CALLDEF(rcpp_capabilities,0),
    CALLDEF(rcpp_can_use_cxx0x,0),
    {NULL, NULL, 0}
}; 

static R_ExternalMethodDef extEntries[]  = {
    EXTDEF(CppMethod__invoke),
    EXTDEF(CppMethod__invoke_void),
    EXTDEF(CppMethod__invoke_notvoid),
    EXTDEF(InternalFunction_invoke),
    EXTDEF(Module__invoke), 
    EXTDEF(class__newInstance), 
    EXTDEF(class__dummyInstance), 
    
    {NULL, NULL, 0}
} ;

// this is called by R_init_Rcpp that is in Module.cpp
void init_Rcpp_routines(DllInfo *info){
  /* Register routines, allocate resources. */
  R_registerRoutines(info, 
      NULL /* .C*/, 
      callEntries /*.Call*/,
      NULL /* .Fortran */,
      extEntries /*.External*/
  );
}
      
void registerFunctions(){
    using namespace Rcpp ;
    using namespace Rcpp::internal ;
    
    #define RCPP_REGISTER(__FUN__) R_RegisterCCallable( "Rcpp", #__FUN__ , (DL_FUNC)__FUN__ );
    RCPP_REGISTER(rcpp_get_stack_trace)
    RCPP_REGISTER(rcpp_set_stack_trace)
    RCPP_REGISTER(type2name)
    RCPP_REGISTER(demangle)
    RCPP_REGISTER(enterRNGScope)
    RCPP_REGISTER(exitRNGScope)
    RCPP_REGISTER(get_Rcpp_namespace)
    RCPP_REGISTER(get_cache)
    RCPP_REGISTER(stack_trace)
    RCPP_REGISTER(get_string_elt)
    RCPP_REGISTER(char_get_string_elt)
    RCPP_REGISTER(set_string_elt)
    RCPP_REGISTER(char_set_string_elt)
    RCPP_REGISTER(get_string_ptr)
    RCPP_REGISTER(get_vector_elt)
    RCPP_REGISTER(set_vector_elt)
    RCPP_REGISTER(get_vector_ptr)
    RCPP_REGISTER(char_nocheck)
    RCPP_REGISTER(dataptr)
    RCPP_REGISTER(getCurrentScope)
    RCPP_REGISTER(setCurrentScope)
    RCPP_REGISTER(get_string_buffer)
    RCPP_REGISTER(short_file_name)
    RCPP_REGISTER(mktime00)
    RCPP_REGISTER(gmtime_)
    RCPP_REGISTER(reset_current_error)
    RCPP_REGISTER(error_occured)
    RCPP_REGISTER(rcpp_get_current_error)
    #undef RCPP_REGISTER
}


extern "C" void R_unload_Rcpp(DllInfo *info) {
  /* Release resources. */
}

extern "C" void R_init_Rcpp( DllInfo* info){
	setCurrentScope(0) ;
	
	registerFunctions() ;
	
	// init the cache
	init_Rcpp_cache() ;
	
	// init routines
	init_Rcpp_routines(info) ;
}

