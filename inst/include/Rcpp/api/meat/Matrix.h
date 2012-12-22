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
    Matrix<RTYPE>::Matrix(SEXP x) : VECTOR( r_cast<RTYPE>( x ) ), nrows( VECTOR::dims()[0] ) {}
    
    template <int RTYPE>
    Matrix<RTYPE>::Matrix( const Dimension& dims) : VECTOR( Rf_allocMatrix( RTYPE, dims[0], dims[1] ) ), nrows(dims[0]) {
        if( dims.size() != 2 ) throw not_compatible("not a matrix") ;
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
    
    template <int RTYPE>
    Matrix<RTYPE>::Matrix( const Matrix& other) : VECTOR( other.asSexp() ), nrows(other.nrows) {}
    
    template <int RTYPE>
    template <bool NA, typename MAT>
    Matrix<RTYPE>::Matrix( const MatrixBase<RTYPE,NA,MAT>& other ) : VECTOR( Rf_allocMatrix( RTYPE, other.nrow(), other.ncol() ) ), nrows(other.nrow()) {
        import_matrix_expression<NA,MAT>( other, nrows, ncol() ) ;
    }
    
    template <int RTYPE>
    Matrix<RTYPE>& Matrix<RTYPE>::operator=(const Matrix& other) {
        SEXP x = other.asSexp() ;
        if( ! ::Rf_isMatrix(x) ) not_compatible("not a matrix") ;
        VECTOR::set_sexp( x ) ;
        nrows = other.nrows ;
        return *this ;
    }
    
    template <int RTYPE>
    template <typename U>
    void Matrix<RTYPE>::fill_diag( const U& u){
        fill_diag__dispatch( typename traits::is_trivial<RTYPE>::type(), u ) ;  
    }
    
    template <int RTYPE>
    template <typename U>
    Matrix<RTYPE> Matrix<RTYPE>::diag( int size, const U& diag_value ){
        Matrix res(size,size) ;
        res.fill_diag( diag_value ) ;
        return res ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Proxy Matrix<RTYPE>::operator[]( int i ){
        return static_cast< Vector<RTYPE>* >( this )->operator[]( i ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::const_Proxy Matrix<RTYPE>::operator[]( int i ) const {
        return static_cast< const Vector<RTYPE>* >( this )->operator[]( i ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Proxy Matrix<RTYPE>::operator()( const size_t& i, const size_t& j) {
        return static_cast< Vector<RTYPE>* >( this )->operator[]( offset( i, j ) ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::const_Proxy Matrix<RTYPE>::operator()( const size_t& i, const size_t& j) const {
        return static_cast< const Vector<RTYPE>* >( this )->operator[]( offset( i, j ) ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Row Matrix<RTYPE>::operator()( int i, internal::NamedPlaceHolder ){
        return Row( *this, i ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Column Matrix<RTYPE>::operator()( internal::NamedPlaceHolder, int i ){
        return Column( *this, i ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Column Matrix<RTYPE>::operator()( internal::NamedPlaceHolder, int i ) const {
        return Column( *this, i ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Sub Matrix<RTYPE>::operator()( const Range& row_range, const Range& col_range){
        return Sub( const_cast<Matrix&>(*this), row_range, col_range ) ;
    }
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Sub Matrix<RTYPE>::operator()( internal::NamedPlaceHolder, const Range& col_range){
        return Sub( const_cast<Matrix&>(*this), Range(0,nrow()-1) , col_range ) ;
    }
    
    template <int RTYPE>
    inline typename Matrix<RTYPE>::Sub Matrix<RTYPE>::operator()( const Range& row_range, internal::NamedPlaceHolder ){
        return Sub( const_cast<Matrix&>(*this), row_range, Range(0,ncol()-1) ) ;
    }
    
    template <int RTYPE>
    template <typename U>
    void Matrix<RTYPE>::fill_diag__dispatch( traits::false_type, const U& u){
        SEXP elem = PROTECT( converter_type::get( u ) ) ;
        int n = Matrix::ncol() ;
        int offset = n +1 ;
        iterator it( VECTOR::begin()) ;
        for( int i=0; i<n; i++){
            *it = ::Rf_duplicate( elem );
            it += offset; 
        }
        UNPROTECT(1); // elem
    }
    
    template <int RTYPE>
    template <typename U>
    void Matrix<RTYPE>::fill_diag__dispatch( traits::true_type, const U& u){
        stored_type elem = converter_type::get( u ) ;
        int n = Matrix::ncol() ;
        int offset = n + 1 ;
        iterator it( VECTOR::begin()) ;
        for( int i=0; i<n; i++){
            *it = elem ;
            it += offset; 
        }
    }

    template <int RTYPE>
    template <bool NA, typename MAT>
    void Matrix<RTYPE>::import_matrix_expression( const MatrixBase<RTYPE,NA,MAT>& other, int nr, int nc ){
        iterator start = VECTOR::begin() ;
        for( int j=0; j<nc; j++){
            for( int i=0; i<nr; i++, ++start){
                *start = other(i,j) ;
            }
        }
    }
    
} // namespace Rcpp

#endif
