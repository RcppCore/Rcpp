// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// sugar_operand.h: Rcpp R/C++ interface class library -- how sugar
// expressions hold their operands
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

#ifndef Rcpp__traits__sugar_operand_h
#define Rcpp__traits__sugar_operand_h

namespace Rcpp{
namespace traits{

    // Objects with a storage policy (vectors, matrices, and classes derived
    // from them) own an R object.
    template <typename T>
    class _has_storage_policy_helper : __sfinae_types {
        template <typename U> static __one __test(typename U::Storage*);
        template <typename U> static __two __test(...);
    public:
        static const bool value = sizeof(__test<T>(0)) == 1;
    };

    // Sugar expressions hold objects that own an R object by reference, but
    // everything else (nested sugar expressions, and views such as
    // MatrixColumn) by value. Those are usually temporaries, and holding
    // them by reference leaves them dangling once the full-expression that
    // created them ends, e.g. when an expression is stored in an `auto`
    // variable.
    template <typename T, bool = _has_storage_policy_helper<T>::value>
    struct sugar_operand {
        typedef const T& type ;
    } ;

    template <typename T>
    struct sugar_operand<T, false> {
        typedef const T type ;
    } ;

    // Operands are often named by their CRTP base; hold the derived type.
    template <int RTYPE, bool NA, typename T>
    struct sugar_operand< VectorBase<RTYPE, NA, T>, false > : sugar_operand<T> {} ;

    template <int RTYPE, bool NA, typename T>
    struct sugar_operand< MatrixBase<RTYPE, NA, T>, false > : sugar_operand<T> {} ;

} // traits
} // Rcpp

#endif
