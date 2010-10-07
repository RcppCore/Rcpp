// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// cache.h: Rcpp R/C++ interface class library -- 
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

#ifndef RCPP_CACHE_H
#define RCPP_CACHE_H

namespace Rcpp {
namespace internal{
        
    SEXP get_Rcpp_namespace() ;
    
}    
}

extern "C" SEXP get_rcpp_cache() ;
extern "C" SEXP init_Rcpp_cache() ; 
extern "C" void maybe_init() ;
extern "C" SEXP reset_current_error() ;
extern "C" SEXP rcpp_error_recorder(SEXP) ;
extern "C" SEXP rcpp_set_current_error(SEXP) ;
extern "C" SEXP rcpp_get_current_error() ;
extern "C" SEXP rcpp_set_error_occured(SEXP) ;
extern "C" SEXP rcpp_get_error_occured() ;
extern "C" SEXP rcpp_set_stack_trace(SEXP) ;
extern "C" SEXP rcpp_get_stack_trace() ;

#endif
