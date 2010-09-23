// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-

// This is a rewrite of the 'Writing R Extensions' section 5.10.1 example
#include <R.h>
#include <Rdefines.h>

SEXP overhead_c(SEXP a, SEXP b) {
    return R_NilValue ;
}

