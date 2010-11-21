// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// routines.h: Rcpp R/C++ interface class library -- .Call exported routines
//
// Copyright (C) 2010	John Chambers, Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__routines_h
#define Rcpp__routines_h

#define CALLFUN_0(name) SEXP name()
#define CALLFUN_1(name) SEXP name(SEXP)
#define CALLFUN_2(name) SEXP name(SEXP,SEXP)
#define CALLFUN_3(name) SEXP name(SEXP,SEXP,SEXP)
#define CALLFUN_4(name) SEXP name(SEXP,SEXP,SEXP,SEXP)
#define CALLFUN_5(name) SEXP name(SEXP,SEXP,SEXP,SEXP,SEXP)
#define EXTFUN(name) SEXP name(SEXP)

// we have to do the ifdef __cplusplus dance because this file
// is included both in C and C++ files
#ifdef __cplusplus
extern "C" {
#endif

CALLFUN_1(as_character_externalptr) ;

CALLFUN_3(CppField__get);
CALLFUN_4(CppField__set);
CALLFUN_1(Class__name);
CALLFUN_1(Class__has_default_constructor) ;
CALLFUN_1(CppClass__complete);
CALLFUN_1(CppClass__methods);

CALLFUN_1(Module__classes_info) ;
CALLFUN_1(Module__complete) ;
CALLFUN_1(Module__functions_arity);
CALLFUN_2(Module__get_class);
CALLFUN_2(Module__has_class);
CALLFUN_2(Module__has_function);
CALLFUN_1(Module__name);
CALLFUN_2(CppObject__finalize);

CALLFUN_0(get_rcpp_cache);
CALLFUN_0(init_Rcpp_cache);
CALLFUN_0(reset_current_error);
CALLFUN_1(rcpp_error_recorder);
CALLFUN_1(rcpp_set_current_error);
CALLFUN_0(rcpp_get_current_error);
CALLFUN_1(rcpp_set_error_occured);
CALLFUN_0(rcpp_get_error_occured);
CALLFUN_1(rcpp_set_stack_trace);
CALLFUN_0(rcpp_get_stack_trace);


/* .External functions */
EXTFUN(CppMethod__invoke) ;
EXTFUN(CppMethod__invoke_void) ;
EXTFUN(CppMethod__invoke_notvoid) ;
EXTFUN(InternalFunction_invoke) ;
EXTFUN(Module__invoke) ;
EXTFUN(class__newInstance) ;

#ifdef __cplusplus
}
#endif

#undef CALLFUN_0
#undef CALLFUN_1
#undef CALLFUN_2
#undef CALLFUN_3
#undef CALLFUN_4
#undef CALLFUN_5

#endif
