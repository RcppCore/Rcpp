// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// get_bits.h : Rcpp R/C++ interface class library -- 
//
// Copyright (C) 2011 Romain Francois
// Copyright (C) 2011 Google Inc.  All rights reserved.
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
    
#ifndef Rcpp__int64__get_bits__h
#define Rcpp__int64__get_bits__h

namespace Rcpp{
    namespace int64{

template <typename T64>
inline int get_low_bits( T64 x){
    return (int)( x & 0x00000000FFFFFFFF ) ;
}

template <typename T64>
inline int get_high_bits( T64 x){
    return (int)( x >> 32 ) ;
}

    } // namespace int64
} // namespace Rcpp
#endif
