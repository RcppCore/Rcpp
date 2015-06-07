// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Matrix.h: Rcpp R/C++ interface class library -- matrices
//
// Copyright (C) 2010 - 2014 Dirk Eddelbuettel and Romain Francois
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

namespace Rcpp{

template <int RTYPE, template <class> class StoragePolicy = PreserveStorage >
class Matrix : public Vector<RTYPE, StoragePolicy>, public MatrixBase<RTYPE, true, Matrix<RTYPE,StoragePolicy> > {
    int nrows ;

public:
    struct r_type : traits::integral_constant<int,RTYPE>{} ;
    struct can_have_na : traits::true_type{} ;
    typedef MatrixRow<RTYPE> Row ;
    typedef MatrixColumn<RTYPE> Column ;
    typedef SubMatrix<RTYPE> Sub ;

    typedef StoragePolicy<Matrix> Storage ;
    typedef Vector<RTYPE, StoragePolicy> VECTOR ;
    typedef typename VECTOR::iterator iterator ;
    typedef typename VECTOR::const_iterator const_iterator ;
    typedef typename VECTOR::converter_type converter_type ;
    typedef typename VECTOR::stored_type stored_type ;
    typedef typename VECTOR::Proxy Proxy ;
    typedef typename VECTOR::const_Proxy const_Proxy ;

    Matrix() : VECTOR(Dimension(0, 0)), nrows(0) {}

    Matrix(SEXP x) : VECTOR( r_cast<RTYPE>( x ) ), nrows( VECTOR::dims()[0] ) {}

    Matrix( const Dimension& dims) : VECTOR( Rf_allocMatrix( RTYPE, dims[0], dims[1] ) ), nrows(dims[0]) {
        if( dims.size() != 2 ) throw not_compatible("not a matrix") ;
        VECTOR::init() ;
    }
    Matrix( const int& nrows_, const int& ncols) : VECTOR( Dimension( nrows_, ncols ) ),
      nrows(nrows_)
    {}

    template <typename Iterator>
    Matrix( const int& nrows_, const int& ncols, Iterator start ) :
        VECTOR( start, start + (nrows_*ncols) ),
        nrows(nrows_)
    {
        VECTOR::attr( "dim" ) = Dimension( nrows, ncols ) ;
    }

    Matrix( const int& n) : VECTOR( Dimension( n, n ) ), nrows(n) {}


    Matrix( const Matrix& other) : VECTOR( other.get__() ), nrows(other.nrows) {}

    template <bool NA, typename MAT>
    Matrix( const MatrixBase<RTYPE,NA,MAT>& other ) : VECTOR( Rf_allocMatrix( RTYPE, other.nrow(), other.ncol() ) ), nrows(other.nrow()) {
        import_matrix_expression<NA,MAT>( other, nrows, ncol() ) ;
    }

    Matrix( const SubMatrix<RTYPE>& ) ;

    Matrix& operator=(const Matrix& other) {
        SEXP x = other.get__() ;
        if( ! ::Rf_isMatrix(x) ) not_compatible("not a matrix") ;
        VECTOR::set__( x ) ;
        nrows = other.nrows ;
        return *this ;
    }
    Matrix& operator=( const SubMatrix<RTYPE>& ) ;

    explicit Matrix( const no_init_matrix& obj) {
        Storage::set__( Rf_allocMatrix( RTYPE, obj.nrow(), obj.ncol() ) );
    }

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

    template <typename U>
    void fill_diag( const U& u) {
      fill_diag__dispatch( typename traits::is_trivial<RTYPE>::type(), u ) ;
    }

    template <typename U> static Matrix diag( int size, const U& diag_value ) {
      Matrix res(size,size) ;
        res.fill_diag( diag_value ) ;
        return res ;
    }

    inline Proxy operator[]( R_xlen_t i ) {
      return static_cast< Vector<RTYPE>* >( this )->operator[]( i ) ;
    }
    inline const_Proxy operator[]( R_xlen_t i ) const {
      return static_cast< const Vector<RTYPE>* >( this )->operator[]( i ) ;
    }

    inline Proxy operator()( const size_t& i, const size_t& j) {
      return static_cast< Vector<RTYPE>* >( this )->operator[]( offset( i, j ) ) ;
    }
    inline const_Proxy operator()( const size_t& i, const size_t& j) const {
       return static_cast< const Vector<RTYPE>* >( this )->operator[]( offset( i, j ) ) ;
    }

    inline Row operator()( int i, internal::NamedPlaceHolder ) {
      return Row( *this, i ) ;
    }
    inline Column operator()( internal::NamedPlaceHolder, int i ) {
      return Column( *this, i ) ;
    }
    inline Column operator()( internal::NamedPlaceHolder, int i ) const {
      return Column( *this, i ) ;
    }
    inline Sub operator()( const Range& row_range, const Range& col_range) {
      return Sub( const_cast<Matrix&>(*this), row_range, col_range ) ;
    }
    inline Sub operator()( internal::NamedPlaceHolder, const Range& col_range) {
      return Sub( const_cast<Matrix&>(*this), Range(0,nrow()-1) , col_range ) ;
    }
    inline Sub operator()( const Range& row_range, internal::NamedPlaceHolder ) {
      return Sub( const_cast<Matrix&>(*this), row_range, Range(0,ncol()-1) ) ;
    }


private:

    inline R_xlen_t offset( int i, int j) const { return i + nrows * j ; }

    template <typename U>
    void fill_diag__dispatch( traits::false_type, const U& u) {
          Shield<SEXP> elem( converter_type::get( u ) ) ;
        int n = Matrix::ncol() ;
        int offset = n +1 ;
        iterator it( VECTOR::begin()) ;
        for( int i=0; i<n; i++){
            *it = ::Rf_duplicate( elem );
            it += offset;
        }
    }

    template <typename U>
    void fill_diag__dispatch( traits::true_type, const U& u) {
          stored_type elem = converter_type::get( u ) ;
        int n = Matrix::ncol() ;
        int offset = n + 1 ;
        iterator it( VECTOR::begin()) ;
        for( int i=0; i<n; i++){
            *it = elem ;
            it += offset;
        }
    }

    template <bool NA, typename MAT>
    void import_matrix_expression( const MatrixBase<RTYPE,NA,MAT>& other, int nr, int nc ) {
      iterator start = VECTOR::begin() ;
        for( int j=0; j<nc; j++){
            for( int i=0; i<nr; i++, ++start){
                *start = other(i,j) ;
            }
        }
    }

};

inline internal::DimNameProxy rownames(SEXP x) {
    return internal::DimNameProxy(x, 0);
}

inline internal::DimNameProxy colnames(SEXP x) {
    return internal::DimNameProxy(x, 1);
}

}

#endif
