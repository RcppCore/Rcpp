// int64_lite.h : 64 bit integers
//
// Copyright (C) 2011 Romain Francois and Dirk Eddelbuettel
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
  
#ifndef int64__lite_h
#define int64__lite_h

namespace Rcpp{
    namespace int64{
        SEXP int2(int,int); 
        
        template <typename LONG> class LongVector ;
    }
}    

#include <Rcpp/int64/get_class.h>
#include <Rcpp/int64/get_long.h>
#include <Rcpp/int64/get_bits.h>
#include <Rcpp/int64/new_long.h>
#include <Rcpp/int64/LongVector.h>

#endif
