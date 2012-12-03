/*
 *  fastmatch: fast implementation of match() in R using semi-permanent hash tables
 *
 *  Copyright (C) 2010, 2011  Simon Urbanek
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

/* for speed (should not really matter in this case as most time is spent in the hashing) */
#define USE_RINTERNALS 1
#include <Rinternals.h>

/* for malloc/free since we handle our hash table memory separately from R */
#include <stdlib.h>
/* for hashing for pointers we need intptr_t */
#include <stdint.h>

#include <Rcpp/hash/hash_impl.h>

/* create a new hash table with the given source and length.
   we store only the index - values are picked from the source 
   so you must make sure the source is still alive when used */
hash_t *new_hash(void *src, int len) {
  hash_t *h;
  int m = 2, k = 1, desired = len * 2; /* we want a maximal load of 50% */
  while (m < desired) { m *= 2; k++; }
  h = (hash_t*) calloc(1, sizeof(hash_t) + (sizeof(int) * m));
  if (!h) Rf_error("unable to allocate %.2Mb for a hash table", (double) sizeof(int) * (double) m / (1024.0 * 1024.0));
  h->m = m;
  h->k = k;
  h->src = src;
  return h;
}

/* free the hash table (and all chained hash tables as well) */
void free_hash(hash_t *h) {
  if (h->next) free_hash(h->next);
  free(h);
}

/* pi-hash fn */
#define HASH(X) (3141592653U * ((unsigned int)(X)) >> (32 - h->k))

/* add the integer value at index i (0-based!) to the hash */
void add_hash_int(hash_t *h, int i) {
  int *src = (int*) h->src;
  int val = src[i++], addr;
  addr = HASH(val);
  while (h->ix[addr] && src[h->ix[addr] - 1] != val) {
    addr++;
    if (addr == h->m) addr = 0;
  }
  if (!h->ix[addr])
    h->ix[addr] = i;
}

/* to avoid aliasing rules issues use a union */
union dint_u {
  double d;
  unsigned int u[2];
};

/* add the double value at index i (0-based!) to the hash */
void add_hash_real(hash_t *h, int i) {
  double *src = (double*) h->src;
  union dint_u val;
  int addr;
  /* double is a bit tricky - we nave to nomalize 0.0, NA and NaN */
  val.d = (src[i] == 0.0) ? 0.0 : src[i];
  if (R_IsNA(val.d)) val.d = NA_REAL;
  else if (R_IsNaN(val.d)) val.d = R_NaN;
  addr = HASH(val.u[0]+ val.u[1]);
  while (h->ix[addr] && src[h->ix[addr] - 1] != val.d) {
    addr++;
    if (addr == h->m) addr = 0;
  }
  if (!h->ix[addr])
    h->ix[addr] = i + 1;
}

/* add the pointer value at index i (0-based!) to the hash */
void add_hash_ptr(hash_t *h, int i) {
  int addr;
  void **src = (void**) h->src;
  intptr_t val = (intptr_t) src[i++];
#if (defined _LP64) || (defined __LP64__) || (defined WIN64)
  addr = HASH((val & 0xffffffff) ^ (val >> 32));
#else
  addr = HASH(val);
#endif
  while (h->ix[addr] && (intptr_t) src[h->ix[addr] - 1] != val) {
    addr++;
    if (addr == h->m) addr = 0;
  }
  if (!h->ix[addr])
    h->ix[addr] = i;
}

/* NOTE: we are returning a 1-based index ! */
int get_hash_int(hash_t *h, int val) {
  int *src = (int*) h->src;
  int addr;
  addr = HASH(val);
  while (h->ix[addr]) {
    if (src[h->ix[addr] - 1] == val)
      return h->ix[addr];
    addr ++;
    if (addr == h->m) addr = 0;
  }
  return NA_INTEGER;
}

/* NOTE: we are returning a 1-based index ! */
int get_hash_real(hash_t *h, double val) {
  double *src = (double*) h->src;
  int addr;
  union dint_u val_u;
  /* double is a bit tricky - we nave to normalize 0.0, NA and NaN */
  if (val == 0.0) val = 0.0;
  if (R_IsNA(val)) val = NA_REAL;
  else if (R_IsNaN(val)) val = R_NaN;
  val_u.d = val;
  addr = HASH(val_u.u[0] + val_u.u[1]);
  while (h->ix[addr]) {
    if (src[h->ix[addr] - 1] == val)
      return h->ix[addr];
    addr++;
    if (addr == h->m) addr = 0;
  }
  return NA_INTEGER;
}

/* NOTE: we are returning a 1-based index ! */
int get_hash_ptr(hash_t *h, void *val_ptr) {
  void **src = (void **) h->src;
  intptr_t val = (intptr_t) val_ptr;
  int addr;
#if (defined _LP64) || (defined __LP64__) || (defined WIN64)
  addr = HASH((val & 0xffffffff) ^ (val >> 32));
#else
  addr = HASH(val);
#endif               
  while (h->ix[addr]) {
    if ((intptr_t) src[h->ix[addr] - 1] == val)
      return h->ix[addr];
    addr ++;
    if (addr == h->m) addr = 0;
  }
  return NA_INTEGER;
}

/* the only externally visible function to be called from R */
SEXP simon_fmatch(SEXP x, SEXP y) {
  SEXPTYPE type = TYPEOF(y) ;
  
  hash_t* h = new_hash(DATAPTR(y), LENGTH(y));
  h->type = type;
  h->parent = y;

  int i, n = LENGTH(y);
  if (type == INTSXP)
	for(i = 0; i < n; i++)
	  add_hash_int(h, i);
  else if (type == REALSXP)
	for(i = 0; i < n; i++)
	  add_hash_real(h, i);
  else
	for(i = 0; i < n; i++)
	  add_hash_ptr(h, i);
    
  n = LENGTH(x) ;
    SEXP r = allocVector(INTSXP, n);
    int *v = INTEGER(r);
    if (type == INTSXP) {
      int *k = INTEGER(x);
      for (i = 0; i < n; i++)
	  v[i] = get_hash_int(h, k[i]);
    } else if (type == REALSXP) {
      double *k = REAL(x);
      for (i = 0; i < n; i++)
	  v[i] = get_hash_real(h, k[i]);
    } else {
      SEXP *k = (SEXP*) DATAPTR(x);
      for (i = 0; i < n; i++)
	  v[i] = get_hash_ptr(h, k[i]);
    }
  
    free_hash( h ) ;
    return r;
  
}

