// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Subsetter.h: Rcpp R/C++ interface class library -- vector subsetting
//
// Copyright (C) 2014  Dirk Eddelbuettel, Romain Francois and Kevin Ushey
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

#ifndef Rcpp_vector_Subsetter_h_
#define Rcpp_vector_Subsetter_h_

namespace Rcpp {

template <
    int RTYPE, template <class> class StoragePolicy,
    int RHS_RTYPE, bool RHS_NA, typename RHS_T
>
class SubsetProxy {

    typedef Vector<RTYPE, StoragePolicy> LHS_t;
    typedef Vector<RHS_RTYPE, StoragePolicy> RHS_t;

public:

    SubsetProxy(LHS_t& lhs_, const RHS_t& rhs_):
        lhs(lhs_), rhs(rhs_), lhs_n(lhs.size()), rhs_n(rhs.size()) {
        get_indices( traits::identity< traits::int2type<RHS_RTYPE> >() );
    }

    SubsetProxy(const SubsetProxy& other):
        lhs(other.lhs),
        rhs(other.rhs),
        lhs_n(other.lhs_n),
        rhs_n(other.rhs_n),
        indices(other.indices),
        indices_n(other.indices_n) {}

    // Enable e.g. x[y] = z
    template <int OtherRTYPE, template <class> class OtherStoragePolicy>
    SubsetProxy& operator=(const Vector<OtherRTYPE, OtherStoragePolicy>& other) {
        int n = other.size();
        if (indices_n != n) stop("index error");
        if (n == 1) {
            for (int i=0; i < n; ++i) {
                lhs[ indices[i] ] = other[0];
            }
        } else if (n == indices_n) {
            for (int i=0; i < n; ++i) {
                lhs[ indices[i] ] = other[i];
            }
        } else {
            stop("index error");
        }
        return *this;
    }

    // Enable e.g. x[y] = 1;
    // TODO: std::enable_if<primitive> with C++11
    SubsetProxy& operator=(double other) {
        for (int i=0; i < indices_n; ++i) {
            lhs[ indices[i] ] = other;
        }
        return *this;
    }

    SubsetProxy& operator=(int other) {
        for (int i=0; i < indices_n; ++i) {
            lhs[ indices[i] ] = other;
        }
        return *this;
    }

    SubsetProxy& operator=(const char* other) {
        for (int i=0; i < indices_n; ++i) {
            lhs[ indices[i] ] = other;
        }
        return *this;
    }

    SubsetProxy& operator=(bool other) {
        for (int i=0; i < indices_n; ++i) {
            lhs[ indices[i] ] = other;
        }
        return *this;
    }

    operator Vector<RTYPE, StoragePolicy>() const {
        return get_vec();
    }

    operator SEXP() const {
        return wrap( get_vec() );
    }

private:

    #ifndef RCPP_NO_BOUNDS_CHECK
    void check_indices(int* x, int n, int size) {
        for (int i=0; i < n; ++i) {
            if (x[i] < 0 or x[i] >= size) {
                stop("index error");
            }
        }
    }
    #else
    void check_indices(int* x, int n, int size) {}
    #endif

    void get_indices( traits::identity< traits::int2type<INTSXP> > t ) {
        indices = INTEGER(rhs);
        indices_n = rhs_n;
        check_indices(indices, rhs_n, lhs_n);
    }

    void get_indices( traits::identity< traits::int2type<REALSXP> > t ) {
        indices.reserve(rhs_n);
        Vector<INTSXP, StoragePolicy> tmp =
            as< Vector<INTSXP, StoragePolicy> >(rhs);
        int* ptr = INTEGER(tmp);
        check_indices(ptr, rhs_n, lhs_n);
        for (int i=0; i < rhs_n; ++i) {
            indices.push_back( tmp[i] );
        }
        indices_n = rhs_n;
    }

    void get_indices( traits::identity< traits::int2type<STRSXP> > t ) {
        indices.reserve(rhs_n);
        SEXP names = Rf_getAttrib(lhs, R_NamesSymbol);
        if (Rf_isNull(names)) stop("names is null");
        for (int i=0; i < rhs_n; ++i) {
            indices.push_back( find(names, CHAR( STRING_ELT(rhs, i) )) );
        }
        indices_n = indices.size();
    }

    int find(const RHS_t& names, const char* str) {
        for (int i=0; i < lhs_n; ++i) {
            if (strcmp( CHAR( STRING_ELT( names, i) ), str) == 0) return i;
        }
        stop("no name found");
        return -1;
    }

    void get_indices( traits::identity< traits::int2type<LGLSXP> > t ) {
        indices.reserve(rhs_n);
        if (lhs_n != rhs_n) {
            stop("logical subsetting requires vectors of identical size");
        }
        int* ptr = LOGICAL(rhs);
        for (int i=0; i < rhs_n; ++i) {
            if (ptr[i] == NA_INTEGER) {
                stop("can't subset using a logical vector with NAs");
            }
            if (ptr[i]) {
                indices.push_back(i);
            }
        }
        indices_n = indices.size();
    }

    Vector<RTYPE, StoragePolicy> get_vec() const {
        Vector<RTYPE, StoragePolicy> output = no_init(indices_n);
        for (int i=0; i < indices_n; ++i) {
            output[i] = lhs[ indices[i] ];
        }
        SEXP names = Rf_getAttrib(lhs, R_NamesSymbol);
        if (!Rf_isNull(names)) {
            Shield<SEXP> out_names( Rf_allocVector(STRSXP, indices_n) );
            for (int i=0; i < indices_n; ++i) {
                SET_STRING_ELT(out_names, i, STRING_ELT(names, indices[i]));
            }
            Rf_setAttrib(output, R_NamesSymbol, out_names);
        }
        Rf_copyMostAttrib(lhs, output);
        return output;
    }

    LHS_t& lhs;
    const RHS_t& rhs;
    int lhs_n;
    int rhs_n;

    // we want to reuse the indices if an IntegerVector is passed in; otherwise,
    // we construct a std::vector<int> to hold the indices
    typename traits::if_<
        RHS_RTYPE == INTSXP,
        int*,
        std::vector<int>
    >::type indices;

    // because of the above, we keep track of the size
    int indices_n;

};

}

#endif
