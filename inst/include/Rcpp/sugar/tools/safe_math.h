// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// safe_math.h: Rcpp R/C++ interface class library --
//
// Copyright (C) 2026           Iñaki Ucar
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

#ifndef Rcpp__sugar__tools_safe_math_h
#define Rcpp__sugar__tools_safe_math_h

#ifndef safe_math__has_builtin
# ifdef __has_builtin
#  define safe_math__has_builtin(x) __has_builtin(x)
# else
#  define safe_math__has_builtin(x) 0
# endif
#endif

#define RCPP_SAFE_ADD(a, b) Rcpp::sugar::safe_add(a, b, __func__)
#define RCPP_SAFE_SUB(a, b) Rcpp::sugar::safe_sub(a, b, __func__)
#define RCPP_SAFE_MUL(a, b) Rcpp::sugar::safe_mul(a, b, __func__)

namespace Rcpp {
namespace sugar {

    inline void stop_overflow(const char* caller) {
        if (caller)
            Rcpp::stop("[%s] Integer overflow!", caller);
        Rcpp::stop("Integer overflow!");
    }

    // Addition
    template <typename T>
    inline typename std::enable_if<std::is_integral<T>::value, T>::type
    safe_add(T a, T b, const char* caller = nullptr) {
    #if safe_math__has_builtin(__builtin_add_overflow)
        T result;
        if (__builtin_add_overflow(a, b, &result))
            stop_overflow(caller);
        return result;
    #else // fallback
        if (std::is_signed<T>::value) {
            if ((b > 0 && a > std::numeric_limits<T>::max() - b) ||
                (b < 0 && a < std::numeric_limits<T>::min() - b))
                stop_overflow(caller);
        } else {
            if (a > std::numeric_limits<T>::max() - b)
                stop_overflow(caller);
        }
        return a + b;
    #endif
    }

    template <typename T>
    inline typename std::enable_if<!std::is_integral<T>::value, T>::type
    safe_add(T a, T b, const char* caller = nullptr) { return a + b; }

    // Subtraction
    template <typename T>
    inline typename std::enable_if<std::is_integral<T>::value, T>::type
    safe_sub(T a, T b, const char* caller = nullptr) {
    #if safe_math__has_builtin(__builtin_sub_overflow)
        T result;
        if (__builtin_sub_overflow(a, b, &result))
            stop_overflow(caller);
        return result;
    #else // fallback
        if (std::is_signed<T>::value) {
            if ((b < 0 && a > std::numeric_limits<T>::max() + b) ||
                (b > 0 && a < std::numeric_limits<T>::min() + b))
                stop_overflow(caller);
        } else {
            if (a < b)
                stop_overflow(caller);
        }
        return a - b;
    #endif
    }

    template <typename T>
    inline typename std::enable_if<!std::is_integral<T>::value, T>::type
    safe_sub(T a, T b, const char* caller = nullptr) { return a - b; }

    // Multiplication
    template <typename T>
    inline typename std::enable_if<std::is_integral<T>::value, T>::type
    safe_mul(T a, T b, const char* caller = nullptr) {
    #if safe_math__has_builtin(__builtin_mul_overflow)
        T result;
        if (__builtin_mul_overflow(a, b, &result))
            stop_overflow(caller);
        return result;
    #else // fallback
        if (a == 0 || b == 0) return 0;
        if (std::is_signed<T>::value) {
            if ((a > 0 && b > 0 && a > std::numeric_limits<T>::max() / b) ||
                (a > 0 && b < 0 && b < std::numeric_limits<T>::min() / a) ||
                (a < 0 && b > 0 && a < std::numeric_limits<T>::min() / b) ||
                (a < 0 && b < 0 && a < std::numeric_limits<T>::max() / b))
                stop_overflow(caller);
        } else {
            if (b > 0 && a > std::numeric_limits<T>::max() / b)
                stop_overflow(caller);
        }
        return a * b;
    #endif
    }

    template <typename T>
    inline typename std::enable_if<!std::is_integral<T>::value, T>::type
    safe_mul(T a, T b, const char* caller = nullptr) { return a * b; }

} // namespace sugar
} // namespace Rcpp

#undef safe_math__has_builtin

#endif
