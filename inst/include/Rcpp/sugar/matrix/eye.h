// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// eye.h: Rcpp R/C++ interface class library -- eye, ones, zeros
//
// Copyright (C) 2016 Nathan Russell
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

#ifndef Rcpp__sugar__eye_h
#define Rcpp__sugar__eye_h

namespace Rcpp {
namespace traits {

template<bool>
struct allowed_matrix_type;

template<>
struct allowed_matrix_type<true> {};

template <typename T>
class one_type {
private:
    Rcomplex op(true_type) const {
        Rcomplex res;
        res.i = 0.0;
        res.r = 1.0;
        return res;
    }
    
    T op(false_type) const {
        return static_cast<T>(1);
    }
    
public:
    operator T() const {
        return op(typename same_type<T, Rcomplex>::type());
    }
};

template <typename T>
class zero_type {
private:
    Rcomplex op(true_type) const {
        Rcomplex res;
        res.i = 0.0;
        res.r = 0.0;
        return res;
    }
    
    T op(false_type) const {
        return static_cast<T>(0);
    }
    
public:
    operator T() const {
        return op(typename same_type<T, Rcomplex>::type());
    }
};

} // traits

class eye {
private:
    int n;
    
public:
    eye(const int n_) 
        : n(n_) 
    {}
    
    template <int RTYPE>
    operator Matrix<RTYPE>() const {
        typedef typename traits::storage_type<RTYPE>::type stored_type;
        
        const bool enabled = 
            traits::is_arithmetic<stored_type>::value || 
            traits::same_type<stored_type, Rcomplex>::value;

        (void)sizeof(traits::allowed_matrix_type<enabled>);
        
        typedef traits::one_type<stored_type> one_type;

        return Matrix<RTYPE>::diag(n, one_type());
    }
};

class ones {
private: 
    int n; 
    
public:
    ones(const int n_) 
        : n(n_) 
    {}
    
    template <int RTYPE>
    operator Matrix<RTYPE>() const {
        typedef typename traits::storage_type<RTYPE>::type stored_type;

        const bool enabled = 
            traits::is_arithmetic<stored_type>::value || 
            traits::same_type<stored_type, Rcomplex>::value;

        (void)sizeof(traits::allowed_matrix_type<enabled>);
        
        typedef traits::one_type<stored_type> one_type;

        Matrix<RTYPE> res(n, n);
        std::fill(res.begin(), res.end(), one_type());
        
        return res;
    }
};

class zeros {
private: 
    int n; 
    
public:
    zeros(const int n_) 
        : n(n_) 
    {}
    
    template <int RTYPE>
    operator Matrix<RTYPE>() const {
        typedef typename traits::storage_type<RTYPE>::type stored_type;

        const bool enabled = 
            traits::is_arithmetic<stored_type>::value || 
            traits::same_type<stored_type, Rcomplex>::value;

        (void)sizeof(traits::allowed_matrix_type<enabled>);
        
        typedef traits::zero_type<stored_type> zero_type;

        Matrix<RTYPE> res(n, n);
        std::fill(res.begin(), res.end(), zero_type());
        
        return res;
    }
};

} // Rcpp

#endif // Rcpp__sugar__eye_h
