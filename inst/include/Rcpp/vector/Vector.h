// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Vector.h: Rcpp R/C++ interface class library -- vectors
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

#ifndef Rcpp__vector__Vector_h
#define Rcpp__vector__Vector_h

template <int RTYPE>
class Vector :
	public RObject,       
	public VectorBase< RTYPE, true, Vector<RTYPE> >, 
	public internal::eval_methods<RTYPE>
	{
public:
	typedef typename traits::r_vector_proxy<RTYPE>::type Proxy ;
	typedef typename traits::r_vector_name_proxy<RTYPE>::type NameProxy ;
	typedef typename traits::r_vector_proxy<RTYPE>::type value_type ;
	typedef typename traits::r_vector_iterator<RTYPE>::type iterator ;
	typedef typename traits::init_type<RTYPE>::type init_type ;
	typedef typename traits::r_vector_element_converter<RTYPE>::type converter_type ;
	typedef typename traits::storage_type<RTYPE>::type stored_type ;
	typedef MatrixRow<RTYPE> Row ;
	typedef MatrixColumn<RTYPE> Column ;
	
	Vector() : RObject() {
		RCPP_DEBUG( "Vector()" ) ;
		RObject::setSEXP( Rf_allocVector( RTYPE, 0 ) ) ;
		init() ;
	} ;
    ~Vector(){
    	RCPP_DEBUG( "~Vector()" ) ;
	};
    
	Vector( const Vector& other) : RObject() {
		RObject::setSEXP(other.asSexp()) ;
	}
	
	Vector& operator=( const Vector& other ){
		RObject::setSEXP( other.asSexp() ) ;
		return *this ;
	}
	
	Vector( const RObject::SlotProxy& proxy ) throw(not_compatible) {
		RObject::setSEXP( r_cast<RTYPE>( proxy ) ) ;
	}
	
	Vector( const RObject::AttributeProxy& proxy ) throw(not_compatible) {
		RObject::setSEXP( r_cast<RTYPE>( proxy ) ) ;
	}
	
	template <typename T>
	Vector& operator=( const T& x){
		RObject::setSEXP( r_cast<RTYPE>( wrap(x) ) ) ;
		return *this ;
	}
	
	internal::ListInitialization<iterator,init_type> operator=( init_type x){
		iterator start = begin() ; *start = x; 
		return internal::ListInitialization<iterator,init_type>( start + 1 ) ; ;
	}
	
    Vector( SEXP x ) throw(not_compatible) : RObject() {
    	RCPP_DEBUG_2( "Vector<%d>( SEXP = <%p> )", RTYPE, x) ;
    	RObject::setSEXP( r_cast<RTYPE>( x ) ) ;
    	RCPP_DEBUG( "===========" ) ;
    }
    
    Vector( const int& size ) : RObject()  {
    	RObject::setSEXP( Rf_allocVector( RTYPE, size) ) ;
		init() ;
    }
    
    template <bool __NA__, typename __VEC__>
    Vector( const VectorBase<RTYPE,__NA__,__VEC__>& other ) : RObject() {
    	int n = other.size() ;
    	RObject::setSEXP( Rf_allocVector( RTYPE, other.size() ) ) ;
    	import_expression<__NA__,__VEC__>( other, n ) ;
	}
    
private:
	
	template <bool __NA__, typename __VEC__>
    void import_expression( const VectorBase<RTYPE,__NA__,__VEC__>& other, int n ){
    	iterator start = begin() ; 
		for( int i=0; i<n; i++, ++start){
			*start = other[i] ;
		}
    }
	
public:
    
    template <typename U>
    Vector( const int& size, const U& u){
    	RObject::setSEXP( Rf_allocVector( RTYPE, size) ) ;
		fill( u ) ;	
    }
    
    Vector( const Dimension& dims) : RObject() {
    	RObject::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		init() ;
		if( dims.size() > 1 ){
			RObject::attr( "dim" ) = dims;
		}
    }
    
    template <typename U>
    Vector( const Dimension& dims, const U& u) : RObject() {
    	RObject::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		fill(u) ;
		if( dims.size() > 1 ){
			RObject::attr( "dim" ) = dims;
		}
    }
    
   
	template <typename InputIterator>
	Vector( InputIterator first, InputIterator last) : RObject(){
		assign( first, last ) ;
	}

	Vector( const std::string& st ) throw(parse_error,not_compatible) : RObject(){
		RObject::setSEXP( internal::vector_from_string<RTYPE>(st) );
	}
	
#ifdef HAS_INIT_LISTS
	Vector( std::initializer_list<init_type> list ) : RObject(){
		assign( list.begin() , list.end() ) ;
	}
#endif
	
    /**
     * the length of the vector, uses Rf_length
     */
    inline R_len_t length() const { return ::Rf_length( RObject::m_sexp ) ; }
    
    /**
     * alias of length
     */
    inline R_len_t size() const { return ::Rf_length( RObject::m_sexp ) ; }
    
    /**
     * offset based on the dimensions of this vector
     */
    size_t offset(const size_t& i, const size_t& j) const throw(not_a_matrix,index_out_of_bounds){
    	if( !::Rf_isMatrix(RObject::m_sexp) ) throw not_a_matrix() ;
		/* we need to extract the dimensions */
		int *dim = dims() ;
		size_t nrow = static_cast<size_t>(dim[0]) ;
		size_t ncol = static_cast<size_t>(dim[1]) ;
		if( i >= nrow || j >= ncol ) throw index_out_of_bounds() ;
		return i + nrow*j ;
    }
    
    /**
     * one dimensional offset doing bounds checking to ensure
     * it is valid
     */
    size_t offset(const size_t& i) const throw(index_out_of_bounds){
		if( static_cast<R_len_t>(i) >= ::Rf_length(RObject::m_sexp) ) throw index_out_of_bounds() ;
		return i ;
    }
    
    R_len_t offset(const std::string& name) const throw(index_out_of_bounds){
    	SEXP names = RCPP_GET_NAMES( RObject::m_sexp ) ;
    	if( names == R_NilValue ) throw index_out_of_bounds(); 
    	R_len_t n=size() ;
    	for( R_len_t i=0; i<n; ++i){
    		if( ! name.compare( CHAR(STRING_ELT(names, i)) ) ){
    			return i ;
    		}
    	}
    	throw index_out_of_bounds() ;
    	return -1 ; /* -Wall */
    }
    
    private:
	
	template <typename U>
	void fill_dispatch( traits::false_type, const U& u){
		// when this is not trivial, this is SEXP
		SEXP elem = PROTECT( converter_type::get( u ) ); 
		iterator it(begin());
		for( int i=0; i<size ; i++, ++it){
			*it = ::Rf_duplicate( elem ) ;
		}
		UNPROTECT(1) ; /* elem */
	}
	
	template <typename U>
	void fill__dispatch( traits::true_type, const U& u){
		std::fill( begin(), end(), converter_type::get( u ) ) ;
	}
	
	public:	
	
	template <typename U>
	void fill( const U& u){
		fill__dispatch( typename traits::is_trivial<RTYPE>::type(), u ) ;
	}

                                                      
    /* TODO: 3 dimensions, ... n dimensions through variadic templates */
    
    class NamesProxy {
	public:
		NamesProxy( const Vector& v) : parent(v){} ;
	
		/* lvalue uses */              
		NamesProxy& operator=(const NamesProxy& rhs) {
			set( rhs.get() ) ;
			return *this ;
    		}
	
		template <typename T>
		NamesProxy& operator=(const T& rhs){
			set( wrap(rhs) ) ;
			return *this ;
		}
	
		template <typename T> operator T() const {
			return Rcpp::as<T>(get()) ;
		}
		
	private:
		const Vector& parent; 
		
		SEXP get() const {
			return RCPP_GET_NAMES(parent) ;
		}
		
		void set(SEXP x) const {
			SEXP new_vec = PROTECT( internal::try_catch( 
			Rf_lcons( Rf_install("names<-"), 
					Rf_cons( parent, Rf_cons( x , R_NilValue) )))) ;
			/* names<- makes a new vector, so we have to change 
			   the SEXP of the parent of this proxy, it might be 
			   worth to work directly with the names attribute instead
			   of using the names<- R function, but then we need to 
			   take care of coercion, recycling, etc ... we cannot just 
			   brutally assign the names attribute */
			const_cast<Vector&>(parent).setSEXP( new_vec ) ;
			UNPROTECT(1) ; /* new_vec */
    		}
    		
	} ;
    	
	NamesProxy names() const {
		return NamesProxy(*this) ;
	}
    
	inline Row row( int i ){ return Row( *this, i ) ; }
	inline Column column( int i ){ return Column(*this, i ) ; }
	
	inline iterator begin() const{ return cache.get() ; }
	inline iterator end() const{ return cache.get(size()) ; }
	
	inline Proxy operator[]( const int& i ){ return cache.ref(i) ; }
	inline Proxy operator[]( const int& i ) const { return cache.ref(i) ; }
	inline Proxy operator()( const size_t& i) throw(index_out_of_bounds){
		return cache.ref( offset(i) ) ;
	}
	inline Proxy operator()( const size_t& i, const size_t& j) throw(not_a_matrix,index_out_of_bounds){
		return cache.ref( offset(i,j) ) ;
	}
	inline NameProxy operator[]( const std::string& name ){
		return NameProxy( *this, name ) ;
	}
	inline NameProxy operator()( const std::string& name ){
		return NameProxy( *this, name ) ;
	}
	
	template <typename InputIterator>
	void assign( InputIterator first, InputIterator last){
		/* FIXME: we can do better than this r_cast to avoid 
		          allocating an unnecessary temporary object
		 */
		SEXP x = PROTECT( r_cast<RTYPE>( wrap( first, last ) ) );
		RObject::setSEXP( x) ;
		UNPROTECT(1) ;
	}

	template <typename InputIterator>
	static Vector import( InputIterator first, InputIterator last){
		Vector v ;
		v.assign( first , last ) ;
		return v ;
	}

	template <typename InputIterator, typename F>
	static Vector import_transform( InputIterator first, InputIterator last, F f){
		int n = std::distance( first, last ) ;
		Vector v( n ) ;
		std::transform( first, last, v.begin(), f) ;
		return v ;
	}
	
	template <typename T>
	void push_back( const T& object){
		push_back__impl( converter_type::get(object) ) ;
	}
	
	template <typename T>
	void push_back( const T& object, const std::string& name ){
		push_back_name__impl( converter_type::get(object), name ) ;
	}
	
	template <typename T>
	void push_front( const T& object){
		push_front__impl( converter_type::get(object) ) ;
	}
	
	template <typename T>
	void push_front( const T& object, const std::string& name){
		push_front_name__impl( converter_type::get(object), name ) ;
	}
	
	
	template <typename T>
	iterator insert( iterator position, const T& object){
		return insert__impl( position, converter_type::get(object) ) ;
	}
	
	template <typename T>
	iterator insert( int position, const T& object){
		return insert__impl( cache.get(position), converter_type::get(object) ); 
	}
	
	iterator erase( int position){
		return erase_single__impl( cache.get(position) ) ;
	}
	
	iterator erase( iterator position){
		return erase_single__impl( position ) ;
	}
	
	iterator erase( int first, int last){
		return erase_range__impl( cache.get(first), cache.get(last) ) ;
	}
	
	iterator erase( iterator first, iterator last){
		return erase_range__impl( first, last ) ;
	}
	
	void update_vector(){
		RCPP_DEBUG_1(  "update_vector, VECTOR = %s", DEMANGLE(Vector) ) ;
		cache.update(*this) ;
	}
		
	static Vector create(){
		return Vector( 0 ) ;
	}

#include <Rcpp/generated/Vector__create.h>

	template <typename U>
	static void replace_element( iterator it, SEXP names, int index, const U& u){
		replace_element__dispatch( typename traits::is_named<U>::type(), 
			it, names, index, u ) ;
	}
	
	template <typename U>
	static void replace_element__dispatch( traits::false_type, iterator it, SEXP names, int index, const U& u){
		*it = converter_type::get(u);
	}
	
	template <typename U>
	static void replace_element__dispatch( traits::true_type, iterator it, SEXP names, int index, const U& u){
		*it = converter_type::get(u.object ) ;
		SET_STRING_ELT( names, index, ::Rf_mkChar( u.name.c_str() ) ) ;
	}
	
	
	void set_sexp(SEXP x){
		RObject::setSEXP( x) ;
		update_vector() ;
	}
	
	void push_back__impl(const stored_type& object){
		int n = size() ;
		Vector target( n + 1 ) ;
		SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
		iterator target_it( target.begin() ) ;
		iterator it(begin()) ;
		iterator this_end(end());
		if( names == R_NilValue ){
			for( ; it < this_end; ++it, ++target_it ){
				*target_it = *it ;
			}
		} else {
			SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1) ) ;
			int i = 0 ;
			for( ; it < this_end; ++it, ++target_it, i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
			}
			SET_STRING_ELT( newnames, i, Rf_mkChar("") ) ;
			target.attr("names") = newnames ;
			UNPROTECT(1) ; /* newnames */
		}
		*target_it = object;
		set_sexp( target.asSexp() ) ;
	}
	
	void push_back_name__impl(const stored_type& object, const std::string& name ){
		int n = size() ;
		Vector target( n + 1 ) ;
		iterator target_it( target.begin() ) ;
		iterator it(begin()) ;
		iterator this_end(end());
		SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
		SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n+1 ) ) ;
		int i=0;
		if( names == R_NilValue ){
			SEXP dummy = PROTECT( Rf_mkChar("") );
			for( ; it < this_end; ++it, ++target_it,i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i , dummy );
			}
			UNPROTECT(1) ; /* dummy */
		} else {
			for( ; it < this_end; ++it, ++target_it, i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
			}
		}
		SET_STRING_ELT( newnames, i, Rf_mkChar( name.c_str() ) );
		target.attr("names") = newnames ;
		
		*target_it = object;
		UNPROTECT(1) ; /* newnames, */
		set_sexp( target.asSexp() ) ;
	}
	
	
	void push_front__impl(const stored_type& object){
		int n = size() ;
		Vector target( n+1);
		iterator target_it(target.begin());
		iterator it(begin());
		iterator this_end(end());
		*target_it = object ;
		++target_it ;
		SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
		if( names == R_NilValue ){
			for( ; it<this_end; ++it, ++target_it){
				*target_it = *it ;
			}
		} else{
			SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1) );
			int i=1 ;
			SET_STRING_ELT( newnames, 0, Rf_mkChar("") ) ;
			for( ; it<this_end; ++it, ++target_it, i++){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
			}
			target.attr("names") = newnames ;
			UNPROTECT(1) ; /* newnames */
		}
		set_sexp( target.asSexp() ) ;
	}
	
	void push_front_name__impl(const stored_type& object, const std::string& name ){
		int n = size() ;
		Vector target( n + 1 ) ;
		iterator target_it( target.begin() ) ;
		iterator it(begin()) ;
		iterator this_end(end());
		SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
		SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n+1 ) ) ;
		int i=1;
		SET_STRING_ELT( newnames, 0, Rf_mkChar( name.c_str() ) );
		*target_it = object;
		++target_it ;
		
		if( names == R_NilValue ){
			SEXP dummy = PROTECT( Rf_mkChar("") );
			for( ; it < this_end; ++it, ++target_it,i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i , dummy );
			}
			UNPROTECT(1) ; /* dummy */
		} else {
			for( ; it < this_end; ++it, ++target_it, i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i-1 ) ) ;
			}
		}
		target.attr("names") = newnames ;
		
		UNPROTECT(1) ; /* newnames, */
		set_sexp( target.asSexp() ) ;
	}
	
	
	
	iterator insert__impl( iterator position, const stored_type& object){
		int n = size() ;
		// iterator start = begin() ;
		// int pos = position - start ;
		Vector target( n+1 ) ;
		iterator target_it = target.begin();
		iterator it = begin() ;
		iterator this_end = end() ;
		SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
		iterator result ;
		if( names == R_NilValue ){
			for( ; it < position; ++it, ++target_it){
				*target_it = *it ;
			}
			result = target_it;
			*target_it = object ; 
			++target_it ;
			for( ; it < this_end; ++it, ++target_it ){
				*target_it = *it ;
			}
		} else{
			SEXP newnames = PROTECT( ::Rf_allocVector( STRSXP, n + 1 ) ) ;
			int i=0;
			for( ; it < position; ++it, ++target_it, i++){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) ) ;
			}
			result = target_it;
			*target_it = object ;
			SET_STRING_ELT( newnames, i, ::Rf_mkChar("") ) ;
			i++ ;
			++target_it ;
			for( ; it < this_end; ++it, ++target_it, i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i - 1) ) ;
			}
			target.attr( "names" ) = newnames ;
			UNPROTECT(1) ; /* newmanes */
		}
		set_sexp( target.asSexp() );
		return result ;
	}
	
	iterator erase_single__impl( iterator position ){
		if( position < begin() || position >= end() ) throw index_out_of_bounds( ) ;
		int n = size() ;
		Vector target( n - 1 ) ;
		iterator target_it(target.begin()) ;
		iterator it(begin()) ;
		iterator this_end(end()) ;
		SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
		if( names == R_NilValue ){
			for( ; it < position; ++it, ++target_it){
				*target_it = *it;
			}
			iterator result(target_it) ;
			++it ;
			for( ; it < this_end ; ++it, ++target_it){
				*target_it = *it;
			}
			set_sexp( target.asSexp() ) ;
			return result ;
		} else {
			SEXP newnames = PROTECT(::Rf_allocVector( STRSXP, n-1 ));
			int i= 0 ;
			for( ; it < position; ++it, ++target_it,i++){
				*target_it = *it;
				SET_STRING_ELT( newnames, i , STRING_ELT(names,i) ) ;
			}
			iterator result(target_it) ;
			++it ;
			i++ ;
			for( ; it < this_end ; ++it, ++target_it, i++){
				*target_it = *it;
				SET_STRING_ELT( newnames, i-1, STRING_ELT(names,i) ) ;
			}
			target.attr( "names" ) = newnames ;
			UNPROTECT(1) ; /* newnames */
			set_sexp( target.asSexp() ) ;
			return result ;
		}
	}
	
	iterator erase_range__impl( iterator first, iterator last ){
		if( first > last ) throw std::range_error("invalid range") ;
		if( last >= end() || first < begin() ) throw index_out_of_bounds() ;
		
		iterator it = begin() ;
		iterator this_end = end() ;
		int nremoved = std::distance(first,last)+1 ;
		int target_size = size() - nremoved  ;
		Vector target( target_size ) ;
		iterator target_it = target.begin() ;
		
		SEXP names = RCPP_GET_NAMES(RObject::m_sexp) ;
		iterator result ;
		if( names == R_NilValue ){
			for( ; it < first; ++it, ++target_it ){
				*target_it = *it ;
			}
			result = it ;
			for( it = last +1 ; it < this_end; ++it, ++target_it ){
				*target_it = *it ;
			}
		} else{
			SEXP newnames = PROTECT( ::Rf_allocVector(STRSXP, target_size) ) ;
			int i= 0 ;
			for( ; it < first; ++it, ++target_it, i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i ) );
			}
			result = it ;
			for( it = last +1 ; it < this_end; ++it, ++target_it, i++ ){
				*target_it = *it ;
				SET_STRING_ELT( newnames, i, STRING_ELT(names, i + nremoved ) );
			}
			target.attr("names" ) = newnames ;
			UNPROTECT(1) ; /* newnames */
		}
		set_sexp(target.asSexp() );
		return result ;
	}
		
	void init(){
		internal::r_init_vector<RTYPE>(RObject::m_sexp) ;
	}

	virtual void update(){
		RCPP_DEBUG_1( "%s::update", DEMANGLE(Vector) ) ;
		update_vector() ;
	}
	
	traits::r_vector_cache<RTYPE> cache ;

public:
	
	typedef internal::RangeIndexer<RTYPE,Vector> Indexer ;
	
	inline Indexer operator[]( const Range& range ){
		return Indexer( const_cast<Vector&>(*this), range );
	}

protected:
	inline int* dims() const throw(not_a_matrix) {
		if( !::Rf_isMatrix(RObject::m_sexp) ) throw not_a_matrix() ;
		return INTEGER( ::Rf_getAttrib( RObject::m_sexp, ::Rf_install( "dim") ) ) ;
	}

	
} ; /* Vector */

#endif
