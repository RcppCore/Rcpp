// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// hash.h: Rcpp R/C++ interface class library -- hashing utility, inspired 
// from Simon's fastmatch package
//
// Copyright (C) 2010, 2011  Simon Urbanek
// Copyright (C) 2012  Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPP__HASH__HASH_H
#define RCPP__HASH__HASH_H

namespace Rcpp{
    namespace sugar{ 
      
    #ifndef RCPP_HASH    
    #define RCPP_HASH(X) (3141592653U * ((unsigned int)(X)) >> (32 - k))
    #endif
    
    template <int RTYPE>
    class IndexHash {
    public:
        typedef typename traits::storage_type<RTYPE>::type STORAGE ;
        typedef Vector<RTYPE> VECTOR ;
              
        IndexHash( SEXP table ) : m(2), k(1), src( (STORAGE*)dataptr(table) ), data(), size_(0) {
            int n =  Rf_length(table) ;
            int desired = n*2 ;
            while( m < desired ){ m *= 2 ; k++ ; }
            data.resize( m ) ;
            for( int i=0; i<n; i++) add_value(i) ;    
        }
        
        template <typename T>
        inline SEXP lookup(const T& vec) const {
            return lookup__impl(vec, vec.size() ) ;
        }
        
        // use the pointers for actual (non sugar expression vectors)
        inline SEXP lookup(const VECTOR& vec) const {
            return lookup__impl(vec.begin(), vec.size() ) ;
        }
        
        inline bool contains(STORAGE val) const {
            return get_index(val) != NA_INTEGER ;    
        }
        
        inline int size() const {
            return size_ ;
        }
        
        inline Vector<RTYPE> keys() const{
            Vector<RTYPE> res = no_init(size_) ;
            for( int i=0, j=0; j<size_; i++){
                if( data[i] ) res[j++] = src[data[i]] ;
            }
            return res ;
        }
        
    private:
        int m, k ;
        STORAGE* src ;
        std::vector<int> data ;
        int size_ ;
        
        template <typename T>
        SEXP lookup__impl(const T& vec, int n) const {
            SEXP res = Rf_allocVector(INTSXP, n) ;
            int *v = INTEGER(res) ;
            for( int i=0; i<n; i++) v[i] = get_index( vec[i] ) ;    
            return res ;
        }
        
        void add_value(int i){
            STORAGE val = src[i++] ;
            int addr = get_addr(val) ;
            while (data[addr] && src[data[addr] - 1] != val) {
              addr++;
              if (addr == m) addr = 0;
            }
            if (!data[addr]){
              data[addr] = i ;
              size_++ ;
            }
        }
        
        /* NOTE: we are returning a 1-based index ! */
        int get_index(STORAGE value) const {
            int addr = get_addr(value) ;
            while (data[addr]) {
              if (src[data[addr] - 1] == value)
                return data[addr];
              addr++;
              if (addr == m) addr = 0;
            }
            return NA_INTEGER;
        }
        
        // defined below
        int get_addr(STORAGE value) const ;
    } ;
        
    template <>
    inline int IndexHash<INTSXP>::get_addr(int value) const {
        return RCPP_HASH(value) ;
    }
    template <>
    inline int IndexHash<REALSXP>::get_addr(double val) const {
      int addr;
      union dint_u {
          double d;
          unsigned int u[2];
        };
      union dint_u val_u;
      /* double is a bit tricky - we nave to normalize 0.0, NA and NaN */
      if (val == 0.0) val = 0.0;
      if (R_IsNA(val)) val = NA_REAL;
      else if (R_IsNaN(val)) val = R_NaN;
      val_u.d = val;
      addr = RCPP_HASH(val_u.u[0] + val_u.u[1]);
      return addr ;
    }
    
    template <>
    inline int IndexHash<STRSXP>::get_addr(SEXP value) const {
        intptr_t val = (intptr_t) value;
        int addr;
        #if (defined _LP64) || (defined __LP64__) || (defined WIN64)
          addr = RCPP_HASH((val & 0xffffffff) ^ (val >> 32));
        #else
          addr = RCPP_HASH(val);
        #endif
        return addr ;
    }

    
} // sugar
} // Rcpp

#endif

