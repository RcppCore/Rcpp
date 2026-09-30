// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// is_elementwise.h: Rcpp R/C++ interface class library -- whether a sugar
// expression can be written into one of its own operands in place
//
// Copyright (C) 2026 Kevin Ushey
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

#ifndef Rcpp__traits__is_elementwise_h
#define Rcpp__traits__is_elementwise_h

namespace Rcpp{
namespace traits{

    template <typename T>
    class _has_elementwise_marker_helper : __sfinae_types {
        template <typename U> static __one __test(typename U::rcpp_elementwise*);
        template <typename U> static __two __test(...);
    public:
        static const bool value = sizeof(__test<T>(0)) == 1;
    };

    // An expression is elementwise when its element i depends only on
    // element i of the vectors it reads, all of which have the expression's
    // length. Writing such an expression into one of those vectors (or a
    // view of one) in place is safe; anything else has to be evaluated into
    // a temporary first.
    //
    // Vectors and matrices are elementwise; sugar expressions opt in with a
    // nested `rcpp_elementwise` type (usually defined in terms of their
    // operands), and are assumed not to be elementwise otherwise.
    template <
        typename T,
        bool = _has_storage_policy_helper<T>::value,
        bool = _has_elementwise_marker_helper<T>::value
    >
    struct is_elementwise : false_type {} ;

    template <typename T, bool MARKED>
    struct is_elementwise<T, true, MARKED> : true_type {} ;

    template <typename T>
    struct is_elementwise<T, false, true> :
        integral_constant<bool, T::rcpp_elementwise::value> {} ;

    template <int RTYPE, bool NA, typename T>
    struct is_elementwise< VectorBase<RTYPE, NA, T>, false, false > : is_elementwise<T> {} ;

    template <typename T1, typename T2, typename T3 = T2>
    struct are_elementwise : integral_constant<bool,
        is_elementwise<T1>::value &&
        is_elementwise<T2>::value &&
        is_elementwise<T3>::value
    > {} ;

} // traits
} // Rcpp

#endif
