
// barrier.cpp: Rcpp R/C++ interface class library -- write barrier
//
// Copyright (C) 2010 - 2020  Dirk Eddelbuettel and Romain Francois
// Copyright (C) 2021 - 2022  Dirk Eddelbuettel, Romain Francois and Iñaki Ucar
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

#define COMPILING_RCPP

#define USE_RINTERNALS
#include <Rinternals.h>
#include <Rcpp/barrier.h>
#include "internal.h"
#include <algorithm>
#include <Rcpp/protection/Shield.h>

// [[Rcpp::register]]
SEXP get_string_elt(SEXP x, R_xlen_t i) {			// #nocov start
    return STRING_ELT(x, i);
}

// [[Rcpp::register]]
const char* char_get_string_elt(SEXP x, R_xlen_t i) {
    return CHAR(STRING_ELT(x, i));
}

// [[Rcpp::register]]
void set_string_elt(SEXP x, R_xlen_t i, SEXP value) {
    SET_STRING_ELT(x, i, value);
}

// [[Rcpp::register]]
void char_set_string_elt(SEXP x, R_xlen_t i, const char* value) {
    SET_STRING_ELT(x, i, Rf_mkChar(value));
}

// [[Rcpp::register]]
SEXP* get_string_ptr(SEXP x) {
    return STRING_PTR(x);
}

// [[Rcpp::register]]
SEXP get_vector_elt(SEXP x, R_xlen_t i) {
    return VECTOR_ELT(x, i);
}

// [[Rcpp::register]]
void set_vector_elt(SEXP x, R_xlen_t i, SEXP value) {
    SET_VECTOR_ELT(x, i, value);
}

// [[Rcpp::register]]
SEXP* get_vector_ptr(SEXP x) {
    return VECTOR_PTR(x);							// #nocov end
}

// [[Rcpp::register]]
void* dataptr(SEXP x) {
    return DATAPTR(x);
}

// [[Rcpp::register]]
const char* char_nocheck(SEXP x) {
    return CHAR(x);
}

static bool Rcpp_cache_know = false;
static SEXP Rcpp_cache = R_NilValue;

#define RCPP_HASH_CACHE_INDEX 4
#define RCPP_CACHE_SIZE 5

#ifndef RCPP_HASH_CACHE_INITIAL_SIZE
#define RCPP_HASH_CACHE_INITIAL_SIZE 1024
#endif

namespace Rcpp {
static SEXP Rcpp_precious = R_NilValue;
// [[Rcpp::register]]
void Rcpp_precious_init() {
    Rcpp_precious = CONS(R_NilValue, R_NilValue);   // set up
	R_PreserveObject(Rcpp_precious); 			    // and protect
}
// [[Rcpp::register]]
void Rcpp_precious_teardown() {
    R_ReleaseObject(Rcpp_precious);                 // release resource
}
// [[Rcpp::register]]
SEXP Rcpp_precious_preserve(SEXP object) {
    if (object == R_NilValue) {
        return R_NilValue;
    }
    PROTECT(object);
    SEXP cell = PROTECT(CONS(Rcpp_precious, CDR(Rcpp_precious)));
    SET_TAG(cell, object);
    SETCDR(Rcpp_precious, cell);
    if (CDR(cell) != R_NilValue) {
        SETCAR(CDR(cell), cell);
    }
    UNPROTECT(2);
    return cell;
}
// [[Rcpp::register]]
void Rcpp_precious_remove(SEXP token) {
    if (token == R_NilValue || TYPEOF(token) != LISTSXP) {
        return;
    }
    SET_TAG(token, R_NilValue);
    SEXP before = CAR(token);
    SEXP after = CDR(token);
    SETCDR(before, after);
    if (after != R_NilValue) {
        SETCAR(after, before);
    }
}
}

// only used for debugging
SEXP get_rcpp_cache() {
    if (! Rcpp_cache_know) {

        SEXP getNamespaceSym = Rf_install("getNamespace"); // cannot be gc()'ed  once in symbol table
        Rcpp::Shield<SEXP> RcppString(Rf_mkString("Rcpp"));
        Rcpp::Shield<SEXP> call(Rf_lang2(getNamespaceSym, RcppString));
        Rcpp::Shield<SEXP> RCPP(Rf_eval(call, R_GlobalEnv));

        Rcpp_cache = Rf_findVarInFrame(RCPP, Rf_install(".rcpp_cache"));
        Rcpp_cache_know = true;
    }
    return Rcpp_cache;
}

namespace Rcpp {
    namespace internal {
        // [[Rcpp::register]]
        SEXP get_Rcpp_namespace() {
            return VECTOR_ELT(get_rcpp_cache() , 0);
        }
    }
}

// [[Rcpp::register]]
SEXP rcpp_get_stack_trace() {
    return VECTOR_ELT(get_rcpp_cache(), 3);
}

// [[Rcpp::register]]
SEXP rcpp_set_stack_trace(SEXP e) {
    SET_VECTOR_ELT(get_rcpp_cache(), 3, e);
    return R_NilValue;
}

SEXP set_error_occured(SEXP cache, SEXP e) {
    SET_VECTOR_ELT(cache, 1, e);
    return R_NilValue;
}

SEXP set_current_error(SEXP cache, SEXP e) {
    SET_VECTOR_ELT(cache, 2, e);
    return R_NilValue;
}

SEXP init_Rcpp_cache() {
    SEXP getNamespaceSym = Rf_install("getNamespace"); // cannot be gc()'ed  once in symbol table
    Rcpp::Shield<SEXP> RcppString(Rf_mkString("Rcpp"));
    Rcpp::Shield<SEXP> call(Rf_lang2(getNamespaceSym, RcppString));
    Rcpp::Shield<SEXP> RCPP(Rf_eval(call, R_GlobalEnv));
    Rcpp::Shield<SEXP> cache(Rf_allocVector(VECSXP, RCPP_CACHE_SIZE));

    // the Rcpp namespace
    SET_VECTOR_ELT(cache, 0, RCPP);
    set_error_occured(cache, Rf_ScalarLogical(FALSE)); // error occured
    set_current_error(cache, R_NilValue); // current error
    SET_VECTOR_ELT(cache, 3, R_NilValue); // stack trace
    Rcpp::Shield<SEXP> tmp(Rf_allocVector(INTSXP, RCPP_HASH_CACHE_INITIAL_SIZE));
    SET_VECTOR_ELT(cache, RCPP_HASH_CACHE_INDEX, tmp);
    Rf_defineVar(Rf_install(".rcpp_cache"), cache, RCPP);

    return cache;
}

// [[Rcpp::register]]
SEXP reset_current_error() {							// #nocov start
    SEXP cache = get_rcpp_cache();

    // error occured
    set_error_occured(cache, Rf_ScalarLogical(FALSE));

    // current error
    set_current_error(cache, R_NilValue);

    // stack trace
    SET_VECTOR_ELT(cache, 3, R_NilValue);

    return R_NilValue;
}

// [[Rcpp::register]]
int error_occured() {
    SEXP err = VECTOR_ELT(get_rcpp_cache(), 1);
    return LOGICAL(err)[0];
}

// [[Rcpp::internal]]
SEXP rcpp_error_recorder(SEXP e) {
    SEXP cache = get_rcpp_cache();

    // error occured
    set_error_occured(cache, Rf_ScalarLogical(TRUE));

    // current error
    set_current_error(cache, e);

    return R_NilValue;
}

// [[Rcpp::register]]
SEXP rcpp_get_current_error() {
    return VECTOR_ELT(get_rcpp_cache(), 2);				// #nocov end
}

// [[Rcpp::register]]
int* get_cache(int m) {
    SEXP cache = get_rcpp_cache();
    SEXP hash_cache = VECTOR_ELT(cache, RCPP_HASH_CACHE_INDEX);
    int n = Rf_length(hash_cache);
    if (m > n) {
        Rcpp::Shield<SEXP> new_hash_cache(Rf_allocVector(INTSXP, m));
        hash_cache = new_hash_cache;
        SET_VECTOR_ELT(cache,RCPP_HASH_CACHE_INDEX, hash_cache);
    }
    int *res = INTEGER(hash_cache);
    std::fill(res, res+m, 0);
    return res;
}
