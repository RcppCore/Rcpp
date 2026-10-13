// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// is_elementwise.h: Rcpp R/C++ interface class library -- whether a sugar
// expression can be written in place into storage it may read from
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

#include <Rcpp/traits/sugar_operand.h>

namespace Rcpp{
namespace traits{

    // Sugar expressions declare `typedef elementwise_operands<...>
    // rcpp_elementwise` when their element i depends only on element i of
    // those operands, all of which have the expression's length.
    template <typename T1 = void, typename T2 = void, typename T3 = void>
    struct elementwise_operands {} ;

    // Views declare `typedef ... rcpp_view` with the kind of view they are.
    struct range_view {} ;
    struct column_view {} ;
    struct row_view {} ;

    // Where an expression is being written, and so which views it may read
    // while it is written in place. Reading a view of the target's own
    // storage is harmless if the view always covers either exactly the
    // target's positions or none of them:
    //
    // - a whole vector: given matching lengths, any view of its storage
    //   covers all of it;
    // - a matrix column (row): any other column (row) of the same matrix is
    //   either the same one or disjoint from it;
    // - a range: another range of the same vector may overlap it at an
    //   offset, so no views are allowed.
    struct vector_target {
        template <typename VIEW> struct reads : true_type {} ;
    } ;
    struct column_target {
        template <typename VIEW> struct reads : same_type<VIEW, column_view> {} ;
    } ;
    struct row_target {
        template <typename VIEW> struct reads : same_type<VIEW, row_view> {} ;
    } ;
    struct range_target {
        template <typename VIEW> struct reads : false_type {} ;
    } ;

    template <typename T>
    class _has_elementwise_marker_helper : __sfinae_types {
        template <typename U> static __one __test(typename U::rcpp_elementwise*);
        template <typename U> static __two __test(...);
    public:
        static const bool value = sizeof(__test<T>(0)) == 1;
    };

    template <typename T>
    class _has_view_tag_helper : __sfinae_types {
        template <typename U> static __one __test(typename U::rcpp_view*);
        template <typename U> static __two __test(...);
    public:
        static const bool value = sizeof(__test<T>(0)) == 1;
    };

    template <typename OPERANDS, typename TARGET>
    struct _operands_are_elementwise : false_type {} ;

    // Whether an expression can be written in place into TARGET even if it
    // reads from TARGET's storage, i.e. whether it is elementwise. Vectors
    // and matrices are; views are if TARGET allows them; sugar expressions
    // are if they declare elementwise operands that are. Anything else is
    // assumed not to be, and has to be evaluated before it is written.
    template <
        typename T,
        typename TARGET,
        bool = _has_storage_policy_helper<T>::value,
        bool = _has_elementwise_marker_helper<T>::value,
        bool = _has_view_tag_helper<T>::value
    >
    struct is_elementwise : false_type {} ;

    template <typename T, typename TARGET, bool MARKED, bool VIEW>
    struct is_elementwise<T, TARGET, true, MARKED, VIEW> : true_type {} ;

    template <typename T, typename TARGET>
    struct is_elementwise<T, TARGET, false, true, false> :
        _operands_are_elementwise<typename T::rcpp_elementwise, TARGET> {} ;

    template <typename T, typename TARGET>
    struct is_elementwise<T, TARGET, false, false, true> :
        TARGET::template reads<typename T::rcpp_view> {} ;

    // unused operand slots
    template <typename TARGET>
    struct is_elementwise<void, TARGET, false, false, false> : true_type {} ;

    template <int RTYPE, bool NA, typename T, typename TARGET>
    struct is_elementwise< VectorBase<RTYPE, NA, T>, TARGET, false, false, false > :
        is_elementwise<T, TARGET> {} ;

    template <typename T1, typename T2, typename T3, typename TARGET>
    struct _operands_are_elementwise< elementwise_operands<T1, T2, T3>, TARGET > :
        integral_constant<bool,
            is_elementwise<T1, TARGET>::value &&
            is_elementwise<T2, TARGET>::value &&
            is_elementwise<T3, TARGET>::value
        > {} ;

} // traits
} // Rcpp

#endif
