// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// hash.h: Rcpp R/C++ interface class library -- hashing 
//
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

#include <Rcpp/hash/hash_impl.h>

namespace Rcpp{
    namespace sugar{ 
    template <typename T> void add_hash_value( hash_t *h, int i) ;
    template <> inline void add_hash_value<int>( hash_t* h, int i ){ add_hash_int(h,i) ;}
    template <> inline void add_hash_value<double>( hash_t* h, int i ){ add_hash_real(h,i) ;}
    template <> inline void add_hash_value<SEXP>( hash_t* h, int i ){ add_hash_ptr(h,i) ;}
    
    template <typename T> int get_hash_value( hash_t *h, T val) ;
    template <> inline int get_hash_value<int>( hash_t *h, int val){ return get_hash_int(h, val) ; }
    template <> inline int get_hash_value<double>( hash_t *h, double val){ return get_hash_real(h, val); }
    template <> inline int get_hash_value<SEXP>( hash_t *h, SEXP val){ return get_hash_ptr(h, val) ; }
    
    template <int RTYPE>
    class IndexHash {
    public:
        typedef typename traits::storage_type<RTYPE>::type STORAGE ;
        typedef Vector<RTYPE> VECTOR ;
              
        IndexHash( SEXP table ) : h(0) {
            int n =  LENGTH(table) ;
            h = new_hash( dataptr(table), n ) ;
            for( int i=0; i<n; i++){
               add_hash_value<STORAGE>( h, i) ;     
            }    
        }
        ~IndexHash(){ 
            if(h) {
                free_hash(h);
                h = 0 ;
            }
        }
        
        template <typename T>
        SEXP lookup(const T& vec){
            int n = vec.size() ;
            SEXP res = Rf_allocVector(INTSXP, n) ;
            int *v = INTEGER(res) ;
            for( int i=0; i<n; i++){
                v[i] = get_hash_value<STORAGE>( h, vec[i] ) ;    
            }
            return res ;
        }
        
        SEXP lookup(const VECTOR& vec){
            int n = vec.size() ;
            SEXP res = Rf_allocVector(INTSXP, n) ;
            int *v = INTEGER(res) ;
            STORAGE* p_vec = vec.begin() ;
            for( int i=0; i<n; i++){
                v[i] = get_hash_value<STORAGE>( h, p_vec[i] ) ;    
            }
            return res ;
        }
        
    private:    
        hash_t* h ;
    } ;
    
} // sugar
} // Rcpp

#endif

