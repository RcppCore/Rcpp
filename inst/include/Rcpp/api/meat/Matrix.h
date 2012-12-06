// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Matrix.h: Rcpp R/C++ interface class library -- Matrix meat 
//
// Copyright (C) 2012    Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_api_meat_Matrix_h
#define Rcpp_api_meat_Matrix_h

namespace Rcpp{ 

    template <int RTYPE>
    Matrix<RTYPE>::Matrix( const Dimension& dims) : VECTOR(), nrows(dims[0]) {
        if( dims.size() != 2 ) throw not_compatible("not a matrix") ;
        VECTOR::setSEXP( Rf_allocMatrix( RTYPE, dims[0], dims[1] ) ) ;
        VECTOR::init() ;
    }
    
    template <int RTYPE>
    Matrix<RTYPE>::Matrix( const int& nrows_, const int& ncols) : 
        VECTOR( Dimension( nrows_, ncols ) ), 
        nrows(nrows_)
    {}
     
    template <int RTYPE>
    template <typename Iterator>
    Matrix<RTYPE>::Matrix( const int& nrows_, const int& ncols, Iterator start ) : 
        VECTOR( start, start + (nrows_*ncols) ),
        nrows(nrows_)
    {
        VECTOR::attr( "dim" ) = Dimension( nrows, ncols ) ; 
    }
    
    template <int RTYPE>
    Matrix<RTYPE>::Matrix( const int& n) : VECTOR( Dimension( n, n ) ), nrows(n) {}
    
} // namespace Rcpp

#endif
