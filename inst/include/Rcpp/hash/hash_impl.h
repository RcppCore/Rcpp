// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// hash_impl.h: Rcpp R/C++ interface class library -- hashing 
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

#ifndef RCPP__HASH__HASH_IMPL_H
#define RCPP__HASH__HASH_IMPL_H

#ifdef __cplusplus 
extern "C" {
#endif    

    typedef struct hash {
      int m, k  ;
      void *src;
      int ix[1];
    } hash_t;

    hash_t *new_hash(void *src, int len) ;
    void free_hash(hash_t *h) ;

    void add_hash_int(hash_t *h, int i) ;
    void add_hash_real(hash_t *h, int i) ;
    void add_hash_ptr(hash_t *h, int i) ;
     
    int get_hash_int(hash_t *h, int val) ;
    int get_hash_real(hash_t *h, double val) ;
    int get_hash_ptr(hash_t *h, void *val_ptr) ;

#ifdef __cplusplus 
}
#endif

#endif

