// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Evaluator.h: Rcpp R/C++ interface class library -- protected evaluation
//
// Copyright (C) 2009 - 2012    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Evaluator_h
#define Rcpp_Evaluator_h

#define R_NO_REMAP
#include <Rinternals.h>

namespace Rcpp{ 

    class Evaluator{
    public:
                
        static SEXP run(SEXP expr); 
        static SEXP run(SEXP expr, SEXP env);
    };

} // namespace Rcpp

#endif
