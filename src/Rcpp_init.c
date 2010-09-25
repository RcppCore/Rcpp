// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Rcpp_init.c : Rcpp R/C++ interface class library -- Initialize and register
//
// Copyright (C) 2010	      John Chambers, Dirk Eddelbuettel and Romain Francois
//
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
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

#include <Rcpp/routines.h>

// borrowed from Matrix
#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}
#define EXTDEF(name)  {#name, (DL_FUNC) &name, -1}


// TODO: check that having this static does not mess up with 
//       RInside, and move it within init_Rcpp_routines otherwise
static R_CallMethodDef callEntries[]  = {
    CALLDEF(as_character_externalptr,1),
    
    CALLDEF(CppField__get,3),
    CALLDEF(CppField__set,4),
    
    CALLDEF(Class__name,1),
    
    CALLDEF(CppClass__complete,1),
    CALLDEF(CppClass__methods,1),
    
    CALLDEF(Module__classes_info,1),
    CALLDEF(Module__complete,1),
    CALLDEF(Module__get_class,2),
    CALLDEF(Module__has_class,2),
    CALLDEF(Module__has_function,2),
    CALLDEF(Module__functions_arity,1),
    CALLDEF(Module__name,1),
    
    {NULL, NULL, 0}
}; 

static R_ExternalMethodDef extEntries[]  = {
    EXTDEF(CppMethod__invoke),
    EXTDEF(InternalFunction_invoke),
    EXTDEF(Module__invoke), 
    EXTDEF(class__newInstance), 
    
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
          
void R_unload_Rcpp(DllInfo *info) {
  /* Release resources. */
}
