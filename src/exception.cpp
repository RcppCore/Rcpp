// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
// jedit: :folding=explicit:
//
// exception.cpp: Rcpp R/C++ interface class library -- exception to stop
//
// Copyright (C) 2015 Wush Wu
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

#include <memory>
#include <Rcpp.h>
#include "exception.hpp"

static bool is_stop(false);
static std::auto_ptr< Rcpp::Shield<SEXP> > expr(NULL);

void rcpp_core_set_stop(const std::exception& e) {
    ::is_stop = true;
    SEXP stop_sym  = Rf_install( "stop" ) ;
    Rcpp::Shield<SEXP> condition( exception_to_r_condition(e) );
    expr.reset(new Rcpp::Shield<SEXP>( Rf_lang2( stop_sym , condition ) ) );
}

bool rcpp_core_is_stop() {
    if (::is_stop) {
        ::is_stop = false;
        return true;
    }
    return false;
}

void rcpp_core_get_stop() {
    Rf_eval( *expr, R_GlobalEnv ) ;
}
