// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// internal.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2012 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_internal_h
#define Rcpp_internal_h

#define CALLFUN_0(name) SEXP name()
#define CALLFUN_1(name) SEXP name(SEXP)
#define CALLFUN_2(name) SEXP name(SEXP,SEXP)
#define CALLFUN_3(name) SEXP name(SEXP,SEXP,SEXP)
#define CALLFUN_4(name) SEXP name(SEXP,SEXP,SEXP,SEXP)
#define CALLFUN_5(name) SEXP name(SEXP,SEXP,SEXP,SEXP,SEXP)

// this file contains declarations of functions that are not 
// exported via Rcpp.h but are needed to make Rcpp work internally

#ifdef __cplusplus
extern "C" {
#endif

    CALLFUN_1(as_character_externalptr) ;

    CALLFUN_3(CppField__get);
    CALLFUN_4(CppField__set);

    CALLFUN_0(rcpp_capabilities) ;
    CALLFUN_0(rcpp_can_use_cxx0x) ;
    CALLFUN_1(rcpp_call_test) ;

    void init_Rcpp_routines(DllInfo*) ;
    const char * sexp_to_name(int sexp_type); 

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
