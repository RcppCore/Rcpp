// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// string_proxy.h: Rcpp R/C++ interface class library -- 
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

#ifndef Rcpp__vector__string_proxy_h
#define Rcpp__vector__string_proxy_h
 
namespace internal{
	
	template<int RTYPE> class string_proxy {
	public:
		
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef const char* iterator ;
		typedef const char& reference ;
		
		string_proxy() : parent(0), index(-1){};
		
		/**
		 * Creates a proxy
		 *
		 * @param v reference to the associated character vector
		 * @param index index 
		 */
		string_proxy( VECTOR& v, int index_ ) : 
			parent(&v), index(index_){
				RCPP_DEBUG( "string_proxy( VECTOR& = <%p>, index_ = %d) ", v.asSexp(), index_ ) ;
		}
			
		string_proxy( const string_proxy& other ) : 
			parent(other.parent), index(other.index){} ;
		
		/**
		 * lhs use. Assign the value of the referred element to 
		 * the current content of the element referred by the 
		 * rhs proxy
		 *
		 * @param rhs another proxy, possibly from another vector
		 */
		string_proxy& operator=(const string_proxy& other){
			set( other.get() ) ;
			return *this ;
		}
		
		/**
		 * lhs use. Assigns the value of the referred element
		 * of the character vector
		 *
		 * @param rhs new content for the element referred by this proxy
		 */
		string_proxy& operator=(const std::string& rhs){
			set( Rf_mkChar( rhs.c_str() ) ) ;
			return *this ;
		}
		
		string_proxy& operator=(const char& rhs){
			set( Rf_mkChar( &rhs ) ) ;
			return *this ;	
		}
		
		string_proxy& operator=(SEXP rhs){
			// TODO: check this is a CHARSXP
			set( rhs ) ;
			return *this ;
		}
		
		void import( const string_proxy& other){
			parent = other.parent ;
			index  = other.index ;
		}
		
		/**
		 * lhs use. Adds the content of the rhs proxy to the 
		 * element this proxy refers to.
		 */
		string_proxy& operator+=(const string_proxy& rhs){
			buffer = CHAR(STRING_ELT(*parent,index)) ;
			buffer += CHAR(STRING_ELT( *(rhs.parent), rhs.index)) ;
			SET_STRING_ELT( *parent, index, Rf_mkChar(buffer.c_str()) ) ;
			return *this ;
		}
		
		/**
		 * lhs use. Adds the string to the element this proxy refers to
		 */
		string_proxy& operator+=(const std::string& rhs){
			buffer = CHAR(STRING_ELT(*parent,index)) ;
			buffer += rhs ;
			SET_STRING_ELT( *parent, index, Rf_mkChar(buffer.c_str()) ) ;
			return *this ;
		} 	 
		
		/**
		 * rhs use. Retrieves the current value of the 
		 * element this proxy refers to.
		 */
		operator SEXP() const {
			return get() ;
		}
		
		/**
		 * rhs use. Retrieves the current value of the 
		 * element this proxy refers to and convert it to a 
		 * C string
		 */
		 operator /*const */ char*() const {
		 	 return const_cast<char*>( CHAR(get()) );
		 }
		
		/**
		 * Prints the element this proxy refers to to an 
		 * output stream
		 */
		template <int RT>
		friend std::ostream& operator<<(std::ostream& os, const string_proxy<RT>& proxy);
		
		template <int RT>
		friend std::string operator+( const std::string& x, const string_proxy<RT>& proxy);
		
		void swap( string_proxy& other ){
			SEXP tmp = PROTECT( STRING_ELT(*parent, index)) ;
			SET_STRING_ELT( *parent, index, STRING_ELT( *(other.parent), other.index) ) ;
			SET_STRING_ELT( *(other.parent), other.index, tmp ) ;
			UNPROTECT(1) ; /* tmp */
		}
		
		VECTOR* parent; 
		int index ;
		inline void move( int n ){ index += n ;}
		
		inline SEXP get() const {
			return STRING_ELT( *parent, index ) ;
		}
		inline void set(SEXP x){
			SET_STRING_ELT( *parent, index, x ) ;
		}
		inline void set( const std::string& x ){
			set( ::Rf_mkChar(x.c_str()) ) ;
		}
		
		inline iterator begin() const { return CHAR( STRING_ELT( *parent, index ) ) ; }
		inline iterator end() const { return begin() + size() ; }
		inline int size() const { return strlen( begin() ) ; }
		inline reference operator[]( int n ){ return *( begin() + n ) ; }
		
		template <typename UnaryOperator>
		void transform( UnaryOperator op ){
			buffer = begin() ;
			std::transform( buffer.begin(), buffer.end(), buffer.begin(), op ) ;
			set( buffer ) ;
		}
		
		template <typename OutputIterator, typename UnaryOperator>
		void apply( OutputIterator target, UnaryOperator op){
			std::transform( begin(), end(), target, op ) ;
		}
		
		template <typename UnaryOperator>
		void apply( UnaryOperator op){
			std::for_each( begin(), end(), op );
		}
		
		bool operator==( const char* other){
			return strcmp( begin(), other ) == 0 ;
		}
			
		private:
			static std::string buffer ;
		
	} ;
	
	template <int RT>
	bool operator<( const string_proxy<RT>& lhs, const string_proxy<RT>& rhs) {
		return strcmp( 
			const_cast<char *>(lhs.begin() ), 
			const_cast<char *>(rhs.begin())
			) < 0 ;
	}

	template <int RT>
	bool operator>( const string_proxy<RT>& lhs, const string_proxy<RT>& rhs) {
		return strcmp( 
			const_cast<char *>(lhs.begin() ), 
			const_cast<char *>(rhs.begin())
			) > 0 ;
	}
	
	template <int RT>
	bool operator>=( const string_proxy<RT>& lhs, const string_proxy<RT>& rhs) {
		return strcmp( 
			const_cast<char *>(lhs.begin() ), 
			const_cast<char *>(rhs.begin())
			) >= 0 ;
	}
	
	template <int RT>
	bool operator<=( const string_proxy<RT>& lhs, const string_proxy<RT>& rhs) {
		return strcmp( 
			const_cast<char *>(lhs.begin() ), 
			const_cast<char *>(rhs.begin())
			) <= 0 ;
	}
		
	template<int RTYPE> std::string string_proxy<RTYPE>::buffer ;
	
	inline std::ostream& operator<<(std::ostream& os, const string_proxy<STRSXP>& proxy) {
	    os << static_cast<const char*>(proxy) ;
	    return os;
	}
	
	inline std::string operator+( const std::string& x, const string_proxy<STRSXP>& y ){
		return x + static_cast<const char*>(y) ;
	}
	
	template <int RTYPE> 
	class generic_proxy{
		public:
			typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
			
			generic_proxy(): parent(0), index(-1){}
			
			generic_proxy( const generic_proxy& other ) : 
				parent(other.parent), index(other.index){} ;
			
			generic_proxy( VECTOR& v, int i ) : parent(&v), index(i){} ;
		
			generic_proxy& operator=(SEXP rhs) { 
				set(rhs) ;
				return *this ;
			}
			
			generic_proxy& operator=(const generic_proxy& rhs) {
				set(rhs.get());
				return *this ;	
			}
	               
			template <typename T>
			generic_proxy& operator=( const T& rhs){
				set( wrap(rhs) ) ;
				return *this; 
			}
			
			operator SEXP() const { return get() ; }
			
			template <typename U> operator U() const {
				return ::Rcpp::as<U>( get() ) ;
			}
			
			void swap(generic_proxy& other){
				SEXP tmp = PROTECT( get() ) ;
				set( other.get() ) ;
				other.set( tmp ) ;
				UNPROTECT(1) ;
			}
			
			VECTOR* parent; 
			int index ;
			inline void move(int n) { index += n ; }
			
			void import( const generic_proxy& other){
				parent = other.parent ;
				index  = other.index ;
			}
			
		private:
			inline void set(SEXP x) { SET_VECTOR_ELT( *parent, index, x ) ;} 
			inline SEXP get() const { return VECTOR_ELT(*parent, index ); } 
		
	}  ;
	
}

#endif
