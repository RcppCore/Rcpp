// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Rostream.h: Rcpp R/C++ interface class library -- output stream
//
// Copyright (C) 2011 - 2012  Dirk Eddelbuettel, Romain Francois and Jelmer Ypma
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

#ifndef __ROSTREAM_H__
#define __ROSTREAM_H__

#include <iomanip>				// USES setw

#include "Rstreambuf.h"         		// to permit direct inclusion of Rostream header

// modified from 
// http://stackoverflow.com/questions/243696/correctly-over-loading-a-stringbuf-to-replace-cout-in-a-matlab-mex-file

namespace Rcpp {

    class Rostream : public std::ostream {
    public:
        Rostream(bool output) : std::ostream(&buf), buf(output) {}
        
    protected:
        Rstreambuf buf;
	
    };
    
    // declare global variable
    extern Rostream Rcout;

    // declare global variable
    extern Rostream Rcerr;
}

#endif
