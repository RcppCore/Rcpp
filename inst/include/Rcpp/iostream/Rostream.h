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

#ifndef RCPP__IOSTREAM__ROSTREAM_H
#define RCPP__IOSTREAM__ROSTREAM_H

// modified from 
// http://stackoverflow.com/questions/243696/correctly-over-loading-a-stringbuf-to-replace-cout-in-a-matlab-mex-file

#include <Rcpp/iostream/Rstreambuf.h>
#include <iostream>

namespace Rcpp {   

    template <bool OUTPUT>
    class Rostream : public std::ostream {
        typedef Rstreambuf<OUTPUT> Buffer ; 
        Buffer* buf ;
    public:
        Rostream() : 
            std::ostream( new Buffer ), 
            buf( static_cast<Buffer*>( rdbuf() ) )
        {}
        ~Rostream() { 
            if (buf != NULL) {
                delete buf; 
                buf = NULL;
            }
        }
    };
    
    // declare global variable
    extern Rostream<true> Rcout;

    // declare global variable
    extern Rostream<false> Rcerr;
}

#endif
