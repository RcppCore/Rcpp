// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Matrix.h: Rcpp R/C++ interface class library -- matrices
//
// Copyright (C) 2010 - 2012 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__vector__Matrix_h
#define Rcpp__vector__Matrix_h

class Dimension ;

template <int RTYPE> 
class Matrix : public Vector<RTYPE>, public MatrixBase<RTYPE,true, Matrix<RTYPE> > {
    int nrows ; 
    
public:
    struct r_type : traits::integral_constant<int,RTYPE>{} ;
    struct can_have_na : traits::true_type{} ;
    typedef MatrixRow<RTYPE> Row ;
    typedef MatrixColumn<RTYPE> Column ;
    typedef SubMatrix<RTYPE> Sub ;
        
    typedef Vector<RTYPE> VECTOR ;
    typedef typename VECTOR::iterator iterator ;
    typedef typename VECTOR::const_iterator const_iterator ;
    typedef typename VECTOR::converter_type converter_type ;
    typedef typename VECTOR::stored_type stored_type ;
    typedef typename VECTOR::Proxy Proxy ;
    typedef typename VECTOR::const_Proxy const_Proxy ;
    
    Matrix() : VECTOR() {}
        
    Matrix(SEXP x) ;
        
    Matrix( const int& n) ; 
    Matrix( const Dimension& dims)  ;
    Matrix( const int& nrows_, const int& ncols)  ;
        
    template <typename Iterator>
    Matrix( const int& nrows_, const int& ncols, Iterator start ) ;
        
    Matrix( const Matrix& other)  ;
        
    template <bool NA, typename MAT>
    Matrix( const MatrixBase<RTYPE,NA,MAT>& other )  ;
    
    Matrix( const SubMatrix<RTYPE>& ) ;
    
    Matrix& operator=(const Matrix& other)  ;
    Matrix& operator=( const SubMatrix<RTYPE>& ) ;
   
    inline int ncol() const {
        return VECTOR::dims()[1]; 
    }
    inline int nrow() const {
        return nrows ; 
    }
    inline int cols() const { 
        return VECTOR::dims()[1]; 
    }
    inline int rows() const { 
        return nrows ; 
    }
        
    inline Row row( int i ){ return Row( *this, i ) ; }
    inline Column column( int i ){ return Column(*this, i ) ; }
        
    inline const_iterator begin() const{ return VECTOR::begin() ; }
    inline const_iterator end() const{ return VECTOR::end() ; }
    inline iterator begin() { return VECTOR::begin() ; }
    inline iterator end() { return VECTOR::end() ; }

    template <typename U> void fill_diag( const U& u) ;
        
    template <typename U> static Matrix diag( int size, const U& diag_value ) ;
    
    inline Proxy operator[]( int i ) ;
    inline const_Proxy operator[]( int i ) const  ;
    
    inline Proxy operator()( const size_t& i, const size_t& j) ; 
    inline const_Proxy operator()( const size_t& i, const size_t& j) const  ;
    
    inline Row operator()( int i, internal::NamedPlaceHolder ) ;
    inline Column operator()( internal::NamedPlaceHolder, int i ) ;
    inline Column operator()( internal::NamedPlaceHolder, int i ) const  ;
    inline Sub operator()( const Range& row_range, const Range& col_range) ;        
    inline Sub operator()( internal::NamedPlaceHolder, const Range& col_range) ;
    inline Sub operator()( const Range& row_range, internal::NamedPlaceHolder ) ;
        
        
private:
    
    inline int offset( int i, int j) const { return i + nrows * j ; }
    
    void update_matrix(){
        RCPP_DEBUG_1( "%s::update_matrix", DEMANGLE(Matrix) ) ;
        VECTOR::update_vector() ;
    }
    
    template <typename U>
    void fill_diag__dispatch( traits::false_type, const U& u) ;
        
    template <typename U>
    void fill_diag__dispatch( traits::true_type, const U& u) ;

    template <bool NA, typename MAT>
    void import_matrix_expression( const MatrixBase<RTYPE,NA,MAT>& other, int nr, int nc ) ;
        
} ;


#endif
