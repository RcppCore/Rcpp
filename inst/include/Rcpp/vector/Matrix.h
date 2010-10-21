// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Matrix.h: Rcpp R/C++ interface class library -- matrices
//
// Copyright (C) 2010	Dirk Eddelbuettel and Romain Francois
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
   
template <int RTYPE> 
class Matrix : public Vector<RTYPE>, public MatrixBase<RTYPE,true, Matrix<RTYPE> > {
public:
	struct r_type : traits::integral_constant<int,RTYPE>{} ;
	struct can_have_na : traits::true_type{} ;
	
	typedef Vector<RTYPE> VECTOR ;
	typedef typename VECTOR::iterator iterator ;
    typedef typename VECTOR::converter_type converter_type ;
    typedef typename VECTOR::stored_type stored_type ;
    typedef typename VECTOR::Proxy Proxy ;
    
	Matrix() : VECTOR() {}
	
	Matrix(SEXP x) throw(not_compatible) : VECTOR(), nrows(0) {
		if( ! ::Rf_isMatrix(x) ) throw not_compatible("not a matrix") ;
		SEXP y = r_cast<RTYPE>( x ) ;
		VECTOR::setSEXP( y );
		nrows = VECTOR::dims()[0] ;
	}
	
	Matrix( const Dimension& dims) throw(not_compatible) : VECTOR(), nrows(dims[0]) {
		if( dims.size() != 2 ) throw not_compatible("not a matrix") ;
		VECTOR::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		VECTOR::init() ;
		VECTOR::attr( "dim" ) = dims ;
	}
	
	Matrix( const int& nrows_, const int& ncols) : 
	    VECTOR( Dimension( nrows_, ncols ) ), 
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
	
	Matrix( const Matrix& other) throw(not_compatible) : VECTOR(), nrows(other.nrows) {
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) throw not_compatible("not a matrix") ;
		VECTOR::setSEXP( x ) ;
	}
	
	Matrix& operator=(const Matrix& other) throw(not_compatible) {                                                         
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) not_compatible("not a matrix") ;
		VECTOR::setSEXP( x ) ;
		nrows = other.nrows ;
		return *this ;
	}
	
	template <bool NA, typename MAT>
    Matrix( const MatrixBase<RTYPE,NA,MAT>& other ) : VECTOR(), nrows(other.nrow()) {
    	int nc = other.ncol() ;
    	SEXP x = PROTECT( Rf_allocVector( RTYPE, nrows * nc ) ) ;
    	SEXP d = PROTECT( Rf_allocVector( INTSXP, 2) ) ;
    	INTEGER(d)[0] = nrows ;
    	INTEGER(d)[1] = nc ;
    	Rf_setAttrib( x, R_DimSymbol, d ) ;
    	RObject::setSEXP( x ) ;
    	UNPROTECT( 2 ) ;
    	import_matrix_expression<NA,MAT>( other, nrows, nc ) ;
	}
   
private:
	
	template <bool NA, typename MAT>
    void import_matrix_expression( const MatrixBase<RTYPE,NA,MAT>& other, int nr, int nc ){
    	iterator start = VECTOR::begin() ;
    	for( int j=0; j<nc; j++){
			for( int i=0; i<nr; i++, ++start){
				*start = other(i,j) ;
			}
		}
    }

public:
	
	template <typename U>
    void fill_diag( const U& u){
    	fill_diag__dispatch( typename traits::is_trivial<RTYPE>::type(), u ) ;	
    }
	
	template <typename U>
    static Matrix diag( int size, const U& diag_value ){
    	Matrix res(size,size) ;
    	res.fill_diag( diag_value ) ;
    	return res ;
    }
    
    inline Proxy operator[]( int i ){
    	return static_cast< Vector<RTYPE>* >( this )->operator[]( i ) ;
    }
    inline Proxy operator()( int i, int j ){
    	return static_cast< Vector<RTYPE>* >( this )->operator()( i, j ) ;
    }
    
    inline Proxy operator[]( int i ) const {
    	return static_cast< const Vector<RTYPE>* >( this )->operator[]( i ) ;
    }
    
    inline Proxy operator()( const size_t& i, const size_t& j) throw(not_a_matrix,index_out_of_bounds){
		return static_cast< Vector<RTYPE>* >( this )->operator[]( 
		    offset( i, j )
		    ) ;
	}
	
	inline Proxy operator()( const size_t& i, const size_t& j) const throw(not_a_matrix,index_out_of_bounds){
		return static_cast< const Vector<RTYPE>* >( this )->operator[]( 
		    offset( i, j )
		    ) ;
	}
	
private:
    
    inline int offset( int i, int j) const {
        return i + nrows * j ;
    }
    
	virtual void update(){
		RCPP_DEBUG_1( "%s::update", DEMANGLE(Matrix) ) ;
		VECTOR::update_vector() ;
	}
	
	template <typename U>
	void fill_diag__dispatch( traits::false_type, const U& u){
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
	
	template <typename U>
	void fill_diag__dispatch( traits::true_type, const U& u){
		stored_type elem = converter_type::get( u ) ;
		int n = Matrix::ncol() ;
		int offset = n + 1 ;
		iterator it( VECTOR::begin()) ;
		for( int i=0; i<n; i++){
    		*it = elem ;
    		it += offset; 
    	}
    }

public:
	inline int ncol() const throw(not_a_matrix) {
    	return VECTOR::dims()[1]; 
    }
    inline int nrow() const throw(not_a_matrix){
    	return nrows ; 
    }
    inline int cols() const throw(not_a_matrix){ 
    	return VECTOR::dims()[1]; 
    }
    inline int rows() const throw(not_a_matrix){ 
    	return nrows ; 
    }
	    
	typedef MatrixRow<RTYPE> Row ;
	typedef MatrixColumn<RTYPE> Column ;

	inline Row row( int i ){ return Row( *this, i ) ; }
	inline Column column( int i ){ return Column(*this, i ) ; }
	
	inline iterator begin() const{ return VECTOR::begin() ; }
	inline iterator end() const{ return VECTOR::end() ; }
    
private:
    int nrows ;	
	
} ;

#endif
