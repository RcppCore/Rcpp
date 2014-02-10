// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
/* :tabSize=4:indentSize=4:noTabs=false:folding=explicit:collapseFolds=1: */
//
// na.h: Rcpp R/C++ interface class library -- optimized na checking
//
// Copyright (C) 2012-2014 Dirk Eddelbuettel, Romain Francois and Kevin Ushey
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

namespace Rcpp {
  namespace internal {
    
    // On 64bit processors, NAs can change
    // we can still get a performance benefit by checking for specific
    // bit patterns, though
    
    // we rely on the presence of unsigned long long types (could do it with
    // a union, but that's messier; this is cleaner)
    #ifdef RCPP_HAS_LONG_LONG_TYPES
    
    #ifdef HAS_STATIC_ASSERT
    static_assert( 
      sizeof(rcpp_ulong_long_type) == sizeof(double),
      "unsigned long long and double have same size"
    );
    #endif
    
    static const rcpp_ulong_long_type SmallNA = 0x7FF00000000007A2;
    static const rcpp_ulong_long_type LargeNA = 0x7FF80000000007A2;
    
    struct NACanChange {
      enum { value = sizeof(void*) == 8 };
    };
    
    template <bool NACanChange>
    bool Rcpp_IsNA__impl(double);
    
    template <>
    inline bool Rcpp_IsNA__impl<true>(double x) {
      return memcmp(
        (void*) &x,
        (void*) &SmallNA,
        sizeof(double)
      ) == 0 or memcmp(
        (void*) &x,
        (void*) &LargeNA,
        sizeof(double)
      ) == 0;
    }
    
    template <>
    inline bool Rcpp_IsNA__impl<false>(double x) {
      printf("false\n");
      return memcmp(
        (void*) &x,
        (void*) &LargeNA,
        sizeof(double)
      ) == 0;
    }
    
    inline bool Rcpp_IsNA(double x) {
      return Rcpp_IsNA__impl< NACanChange::value >(x);
    }
    
    inline bool Rcpp_IsNaN(double x) {
      return R_IsNaN(x);
    }
    
    #else
    
    // fallback when we don't have unsigned long long
    
    inline bool Rcpp_IsNA(double x) {
      return R_IsNA(x);
    }
    
    inline bool Rcpp_IsNaN(double x) {
      return R_IsNaN(x);
    }
    
    #endif
    
  }
}
