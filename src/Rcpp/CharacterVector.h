// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// CharacterVector.h: Rcpp R/C++ interface class library -- character vectors
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

#ifndef Rcpp_CharacterVector_h
#define Rcpp_CharacterVector_h

#include <RcppCommon.h>
#include <Rcpp/exceptions.h>
#include <Rcpp/VectorBase.h>
#include <Rcpp/MatrixRow.h>
#include <Rcpp/MatrixColumn.h>
#include <Rcpp/Dimension.h>
#include <Rcpp/r_cast.h>

namespace Rcpp{ 

	class CharacterVector ;
	
namespace internal{
	
	template<> class VectorElement_Proxy<STRSXP>{
	public:
		/**
		 * Creates a proxy
		 *
		 * @param v reference to the associated character vector
		 * @param index index 
		 */
		VectorElement_Proxy( CharacterVector& v, int index ) ;
		VectorElement_Proxy( const VectorElement_Proxy& other ) ;
		
		/**
		 * lhs use. Assign the value of the referred element to 
		 * the current content of the element referred by the 
		 * rhs proxy
		 *
		 * @param rhs another proxy, possibly from another vector
		 */
		VectorElement_Proxy& operator=(const VectorElement_Proxy& rhs) ;
		
		/**
		 * lhs use. Assigns the value of the referred element
		 * of the character vector
		 *
		 * @param rhs new content for the element referred by this proxy
		 */
		VectorElement_Proxy& operator=(const std::string& rhs) ;
		
		/**
		 * lhs use. Adds the content of the rhs proxy to the 
		 * element this proxy refers to.
		 */
		VectorElement_Proxy& operator+=(const VectorElement_Proxy& rhs) ;
		
		/**
		 * lhs use. Adds the string to the element this proxy refers to
		 */
		VectorElement_Proxy& operator+=(const std::string& rhs) ;
		
		/**
		 * rhs use. Retrieves the current value of the 
		 * element this proxy refers to.
		 */
		operator SEXP() const ;
		
		/**
		 * rhs use. Retrieves the current value of the 
		 * element this proxy refers to and convert it to a 
		 * C string
		 */
		operator /*const */ char*() const ;
		
		/**
		 * Prints the element this proxy refers to to an 
		 * output stream
		 */
		friend std::ostream& operator<<(std::ostream& os, const VectorElement_Proxy& proxy);
		friend std::string operator+( const std::string& x, const VectorElement_Proxy& proxy);
		
		void swap( VectorElement_Proxy& other ) ;
		friend class CharacterVector ;
		
		CharacterVector& parent; 
		int index ;
		inline void move( int n ){ index += n ;}
	} ;
	
}
	
	
/**
 * Representation of character vectors (STRSXP)
 */
class CharacterVector : public VectorBase<CharacterVector> {     
public:

	const static int r_type = STRSXP ;
	typedef VectorBase<CharacterVector> Base ;
	
	typedef internal::VectorElement_Proxy<STRSXP> Proxy ;
	typedef internal::Proxy_Iterator<CharacterVector,Proxy> iterator ;
	
	typedef Proxy value_type ;
	typedef MatrixRow<CharacterVector> Row ;
	typedef MatrixColumn<CharacterVector> Column ;
	typedef Proxy reference ;
	
	/**
	 * Default constructor. Sets the underlying object to NULL
	 */
	CharacterVector() ;
	
	/**
	 * Copy constructor. Grab the underlying SEXP from the copied
	 * object. This does not make a copy of the SEXP.
	 */
	CharacterVector( const CharacterVector& other ) ;
	
	/**
	 * Assign the underlying object to be the same as the copied object
	 * This does not make a copy of the object
	 */
	CharacterVector& operator=( const CharacterVector& other ) ;
	
	internal::ListInitialization<iterator,std::string> operator=( const std::string& x){
		SET_STRING_ELT( m_sexp, 0, Rf_mkChar( x.c_str() ) ) ;
		return internal::ListInitialization<iterator,std::string>( iterator(*this, 1) ) ; 
	}
	
	/**
	 * encapsulates an R object
	 *
	 * @param x R object, presumably a character vector (STRSXP)
	 *
	 * @throw not_compatible if the R object can not be converted
	 *        to a character vector
	 */
	CharacterVector( SEXP x) throw(not_compatible);
	
	/**
	 * Creates a new character vector of the requested length
	 */
	CharacterVector( const size_t& size) ;
	
	/** 
	 * Creates a new character vector of length 1 containing the 
	 * given string
	 */
	CharacterVector( const std::string& x );
	
	/**
	 * Creates a character vector by copying the strings of the input vector
	 */
	CharacterVector( const std::vector<std::string>& x );
	
	/**
	 * Creates a character vector of the requested dimensions
	 */
	CharacterVector( const Dimension& dims) ;
	
	/**
	 * Range based constructor. InputIterator must be an iterator 
	 * over std::string
	 */
	template <typename InputIterator>
	CharacterVector( InputIterator first, InputIterator last): Base() {
		assign( first, last ) ;
	}
	
#ifdef HAS_INIT_LISTS
	/**
	 * Initializer list constructor. Copies the strings
	 *
	 * Example: CharacterVector x = { "foo", "bar" } ;
	 */
	CharacterVector( std::initializer_list<std::string> list ) : Base() {
		assign( list.begin(), list.end() ) ;
	}
#endif
	
	/**
	 * Returns a proxy to the given element of the character vector
	 * The proxy can then be used to get or set the undelting value
	 */
	const Proxy operator[]( int i ) const throw(index_out_of_bounds);
	
	/**
	 * Returns a proxy to the given element of the character vector
	 * The proxy can then be used to get or set the undelting value
	 */
	Proxy operator[]( int i ) throw(index_out_of_bounds);

	const Proxy operator[]( const std::string& name) const throw(index_out_of_bounds); 
	Proxy operator[]( const std::string& name ) throw(index_out_of_bounds);

	/* '(' indexing */
	/**
	 * Returns a proxy to the given element of the character vector
	 * The proxy can then be used to get or set the undelting value
	 *
	 * @throw index_out_of_bounds when the given index is invalid
	 */
	Proxy operator()( const size_t& i) throw(index_out_of_bounds) ;
	
	/**
	 * Returns a proxy to the given element of the character vector, 
	 * expressed in terms of matrix-style indexing. 
	 * 
	 * The proxy can then be used to get or set the undelting value
	 *
	 * @throw not_a_matrix if the underlying object is not a matrix
	 * @throw index_out_of_bounds when the given indices do not produce a valid offset
	 */
	Proxy operator()( const size_t& i, const size_t& j) throw(index_out_of_bounds,not_a_matrix) ;

	inline iterator begin() { return iterator(*this, 0 ) ; }
	
	inline iterator end() { return iterator(*this,::Rf_length(m_sexp));}
	
	template <typename InputIterator>
	void assign( InputIterator first, InputIterator last){
		size_t size = std::distance( first, last ) ;
		SEXP x = m_sexp ;
		bool update = false ;
		if( Rf_isNull(m_sexp) || static_cast<size_t>(length()) != size ){
			x = Rf_allocVector( STRSXP, size ) ;
			update = true ;
		}
		std::string y ;
		for( size_t i=0; i<size; i++, ++first){
			y.assign( *first ) ;
			SET_STRING_ELT( x, i, Rf_mkChar(y.c_str())) ;
		}
		if( update ) setSEXP(x) ;
	}

	inline Row row( int i ){ return Row( *this, i ) ; }
	inline Column column( int i ){ return Column( *this, i ) ; }

} ;

typedef CharacterVector StringVector ;

} // namespace

namespace std{
	template<> void swap< Rcpp::internal::VectorElement_Proxy<STRSXP> >(
		Rcpp::internal::VectorElement_Proxy<STRSXP>& a, 
		Rcpp::internal::VectorElement_Proxy<STRSXP>& b) ;
}



#endif
