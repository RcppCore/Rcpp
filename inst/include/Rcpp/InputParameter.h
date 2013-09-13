// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// InputParameter.h: Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2013    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__InputParameter__h
#define Rcpp__InputParameter__h

namespace Rcpp {
    
    template <typename T>
    class InputParameter {
    public:
        InputParameter(SEXP x_) : x(x_){}
        
        inline operator T() { return as<T>(x) ; }
        
    private:
        SEXP x ;
    } ;
    
}

#endif
