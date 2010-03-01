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

#ifndef Rcpp__Vector_h
#define Rcpp__Vector_h

#include <RcppCommon.h>
#include <Rcpp/Evaluator.h>
#include <Rcpp/exceptions.h>
#include <Rcpp/RObject.h>
#include <Rcpp/r_cast.h>
#include <Rcpp/Dimension.h>

namespace Rcpp{

template <int RTYPE> class Vector ;
template <int RTYPE> class MatrixRow ;
template <int RTYPE> class MatrixColumn ;

namespace internal{
	template <int RTYPE> class string_proxy ;
	template <int RTYPE> class generic_proxy ;
	
	template <int RTYPE> class simple_name_proxy {
	public:
		typedef ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type CTYPE ;
		simple_name_proxy( VECTOR& v, const std::string& name_) :
			parent(v), name(name_){} ;
		simple_name_proxy( const simple_name_proxy& other ) : 
			parent(other.parent), name(other.name){} ;
		~simple_name_proxy() {} ;
		
		simple_name_proxy& operator=( CTYPE rhs ){
			set( rhs ) ;
			return *this ;
		}
		simple_name_proxy& operator=( const simple_name_proxy& other){
			set( other.get() ) ;
			return *this ;
		}
		
		template <typename T>
		simple_name_proxy& operator=( const T& rhs ){
			set( caster<T,CTYPE>(rhs) ) ;
			return *this ;
		}
		
		// TODO: other operators +=, -=, ...
		
		operator CTYPE() const {
			 return get() ;
		}
		
		// this helps wrap, for example : wrap( x["foo"] )
		operator SEXP() const {
			return ::Rcpp::wrap(get()) ;
		}
		
	private:
		VECTOR& parent ;
		std::string name;
		void set( CTYPE rhs ){
			int index = 0 ;
			try{
				index = parent.offset(name) ;
				parent[ index ] = rhs ;
			} catch( const index_out_of_bounds& ex ){
				parent.push_back( rhs, name ); 
			}
		}
		CTYPE get() const {
			return parent[ parent.offset(name) ];
		}
	} ;
	
	template <int RTYPE>
	class string_name_proxy{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		
		string_name_proxy( VECTOR& v, const std::string& name_) :
			parent(v), name(name_){} ;
		string_name_proxy( const string_name_proxy& other ) : 
			parent(other.parent), name(other.name){} ;
		~string_name_proxy(){} ;
		
		string_name_proxy& operator=( const std::string& rhs ){
			set( rhs ) ;
			return *this ;
		}
		string_name_proxy& operator=( const string_name_proxy& other){
			set( other.get() ) ;
			return *this ;
		}
		
		operator char* (){
			 return get() ;
		}
		
		operator SEXP(){
			return ::Rf_mkString(get()) ;
		}
		
	private:
		VECTOR& parent ;
		std::string name;
		void set( const std::string& rhs ){
			int index = 0 ;
			try{
				index = parent.offset(name) ;
				parent[ index ] = rhs ;
			} catch( const index_out_of_bounds& ex ){
				parent.push_back( rhs, name ); 
			}
		}
		char* get(){
			return parent[ parent.offset(name) ];
		}
		
	} ;
	
	template <int RTYPE> class generic_name_proxy {
	public:
		typedef ::Rcpp::Vector<RTYPE> VECTOR ;
		generic_name_proxy( VECTOR& v, const std::string& name_) :
			parent(v), name(name_){} ;
		generic_name_proxy( const generic_name_proxy& other ) : 
			parent(other.parent), name(other.name){} ;
		~generic_name_proxy(){} ;
		
		generic_name_proxy& operator=( SEXP rhs ){
			set( rhs ) ;
			return *this ;
		}
		generic_name_proxy& operator=( const generic_name_proxy& other){
			set( other.get() ) ;
			return *this ;
		}
		
		template <typename T>
		generic_name_proxy& operator=( const T& rhs ){
			set( ::Rcpp::wrap(rhs) ) ;
			return *this ;
		}
		
		// TODO: other operators +=, -=, ...
		
		operator SEXP(){
			 return get() ;
		}
		
		template <typename T>
		operator T(){
			return ::Rcpp::as<T>( get() ) ;
		}
		
	private:
		VECTOR& parent ;
		std::string name;
		void set( SEXP rhs ){
			int index = 0 ;
			try{
				index = parent.offset(name) ;
				parent[ index ] = rhs ;
			} catch( const index_out_of_bounds& ex ){
				parent.push_back( rhs, name ); 
			}
		}
		SEXP get(){
			return parent[ parent.offset(name) ];
		}
	} ;
	
	template <int RTYPE>
	class element_converter{
	public:
		typedef typename ::Rcpp::traits::storage_type<RTYPE>::type target ;
		element_converter(){}
		
		template <typename T>
		target get( const T& input ){
			return caster<T,target>(input) ;
		}
		
		target get( const target& input ){
			return input ;
		}
	} ;
	
	template <int RTYPE>
	class string_element_converter {
	public:
		// typedef typename ::Rcpp::traits::storage_typ
		string_element_converter(){};
		
		template <typename T>
		SEXP get( const T& input){
			std::string out(input) ;
			return Rf_mkChar( out.c_str() ) ;
		}
		
		SEXP get(const std::string& input){
			return Rf_mkChar( input.c_str() ) ;
		}
	} ;
	
	template <int RTYPE>
	class generic_element_converter {
	public:
		generic_element_converter(){};
		
		template <typename T>
		SEXP get( const T& input){
			return ::Rcpp::wrap( input ) ;
		}
		
		SEXP get( const char* input){
			return ::Rcpp::wrap( input );
		}
		
		SEXP get(SEXP input){
			return input ;
		}
	} ;
	
	template <int RTYPE>
	SEXP vector_from_string( const std::string& st ){
		return r_cast<RTYPE>( Rf_mkString( st.c_str() ) ) ;
	}
	
	template <int RTYPE>
	SEXP vector_from_string_expr( const std::string& code){
		ParseStatus status;
		SEXP expr = PROTECT( ::Rf_mkString( code.c_str() ) );
		SEXP res  = PROTECT( ::R_ParseVector(expr, -1, &status, R_NilValue));
		switch( status ){
		case PARSE_OK:
			UNPROTECT( 2) ;
			return(res) ;
			break;
		default:
			UNPROTECT(2) ;
			throw parse_error() ;
		}
		return R_NilValue ; /* -Wall */
	}
	
	template <>
	inline SEXP vector_from_string<EXPRSXP>( const std::string& st ){
		return vector_from_string_expr<EXPRSXP>( st ) ;
	} ;
	
	template <typename VECTOR> class eval_methods {} ;
	
	template <typename VECTOR> class expr_eval_methods {
	public:
		SEXP eval(){
			SEXP xp = ( static_cast<VECTOR&>(*this) ).asSexp() ;
			return try_catch( ::Rf_lcons( ::Rf_install( "eval" ) , ::Rf_cons( xp, R_NilValue) ) ) ;
		} ;
		SEXP eval( const ::Rcpp::Environment& env ){
			SEXP xp = ( static_cast<VECTOR&>(*this) ).asSexp() ;
			return try_catch( ::Rf_lcons( ::Rf_install( "eval" ) , ::Rf_cons( xp, ::Rf_cons(env.asSexp(), R_NilValue)) ) ) ;
		} ;
	} ;
	
	template<> class eval_methods< ::Rcpp::Vector<EXPRSXP> > : 
		public expr_eval_methods< ::Rcpp::Vector<EXPRSXP> > {} ;
	
}

namespace traits{

	template <int RTYPE> struct r_vector_element_converter{
		typedef typename ::Rcpp::internal::element_converter<RTYPE> type ;
	} ;
	template<> struct r_vector_element_converter<STRSXP>{
		typedef ::Rcpp::internal::string_element_converter<STRSXP> type ;
	} ;
	template<> struct r_vector_element_converter<VECSXP>{
		typedef ::Rcpp::internal::generic_element_converter<VECSXP> type ;
	} ;
	template<> struct r_vector_element_converter<EXPRSXP>{
		typedef ::Rcpp::internal::generic_element_converter<EXPRSXP> type ;
	} ;
	
	template <int RTYPE> 
	struct r_vector_name_proxy{
		typedef typename ::Rcpp::internal::simple_name_proxy<RTYPE> type ;
	} ;
	template<> struct r_vector_name_proxy<STRSXP>{
		typedef ::Rcpp::internal::string_name_proxy<STRSXP> type ;
	} ;
	template<> struct r_vector_name_proxy<VECSXP>{
		typedef ::Rcpp::internal::generic_name_proxy<VECSXP> type ;
	} ;
	template<> struct r_vector_name_proxy<EXPRSXP>{
		typedef ::Rcpp::internal::generic_name_proxy<EXPRSXP> type ;
	} ;
	
	template <int RTYPE>
	struct r_vector_proxy{
		typedef typename storage_type<RTYPE>::type& type ;
	} ;
	template<> struct r_vector_proxy<STRSXP> {
		typedef ::Rcpp::internal::string_proxy<STRSXP> type ;
	} ;
	template<> struct r_vector_proxy<EXPRSXP> {
		typedef ::Rcpp::internal::generic_proxy<EXPRSXP> type ;
	} ;
	template<> struct r_vector_proxy<VECSXP> {
		typedef ::Rcpp::internal::generic_proxy<VECSXP> type ;
	} ;
	
	template <int RTYPE>
	struct r_vector_iterator {
		typedef typename storage_type<RTYPE>::type* type ;
	};
	template <int RTYPE> struct proxy_based_iterator{
		typedef ::Rcpp::internal::Proxy_Iterator< typename r_vector_proxy<RTYPE>::type > type ;
	} ;
	template<> struct r_vector_iterator<VECSXP> : proxy_based_iterator<VECSXP>{} ;
	template<> struct r_vector_iterator<EXPRSXP> : proxy_based_iterator<EXPRSXP>{} ;
	template<> struct r_vector_iterator<STRSXP> : proxy_based_iterator<STRSXP>{} ;
	
	template <int RTYPE>
	class r_vector_cache{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename r_vector_iterator<RTYPE>::type iterator ;
		typedef typename r_vector_proxy<RTYPE>::type proxy ;
		typedef typename storage_type<RTYPE>::type storage_type ;
		
		r_vector_cache() : start(0){} ;
		void update( const VECTOR& v ) {
			start = ::Rcpp::internal::r_vector_start<RTYPE,storage_type>(v.asSexp()) ;
		}
		inline iterator get() const { return start; }
		inline iterator get(int i) const { return start + i ; }
		inline proxy ref() const { return *start ;}
		inline proxy ref(int i) const { return *(start+i) ; }
		
		private:
			iterator start ;
	} ;
	template <int RTYPE> class proxy_cache{
	public:
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		typedef typename r_vector_iterator<RTYPE>::type iterator ;
		typedef typename r_vector_proxy<RTYPE>::type proxy ;
		
		proxy_cache(): p(0){}
		~proxy_cache(){}
		void update( const VECTOR& v ){
			p = const_cast<VECTOR*>(&v) ;
		}
		inline iterator get() const { return iterator( proxy(*p, 0 ) ) ;}
		inline iterator get(int i) const { return iterator( proxy(*p, i ) ) ;}
		inline proxy ref() const { return proxy(*p,0) ; }
		inline proxy ref(int i) const { return proxy(*p,i);}
		
		private:
			VECTOR* p ;
	} ;
	template<> class r_vector_cache<VECSXP> : public proxy_cache<VECSXP>{
	public:
		r_vector_cache() : proxy_cache<VECSXP>(){} ;
	};
	template<> class r_vector_cache<EXPRSXP> : public proxy_cache<EXPRSXP>{
	public:
		r_vector_cache() : proxy_cache<EXPRSXP>(){} ;
	};
	template<> class r_vector_cache<STRSXP> : public proxy_cache<STRSXP>{
	public:
		r_vector_cache() : proxy_cache<STRSXP>(){} ;
	} ;
	
	template<int RTYPE> struct init_type {
		typedef typename storage_type<RTYPE>::type type ;
	} ;
	template<> struct init_type<STRSXP>{
		typedef std::string type ;
	} ;
	template<> struct init_type<LGLSXP>{
		typedef bool type ;
	} ;
	
} // traits 

template <typename VECTOR>
class VectorBase : public RObject{
public:
	VectorBase() : RObject(){}
	VectorBase(SEXP x) : RObject(x){}
	~VectorBase(){}
	VectorBase(const VectorBase& v) : RObject( v.asSexp() ){}
	VectorBase& operator=(const VectorBase& v) {
		setSEXP( v.asSexp() ) ;
		return *this ;
	}
	VECTOR& get_ref(){
		return static_cast<VECTOR&>(*this) ;
	}
	virtual void update(){
		(static_cast<VECTOR&>(*this)).update_vector() ;
	}
} ;

template <int RTYPE>
class Vector : public VectorBase< Vector<RTYPE> >, public internal::eval_methods< Vector<RTYPE> >{
public:
	typedef VectorBase<Vector> Base ;
	typedef typename traits::r_vector_proxy<RTYPE>::type Proxy ;
	typedef typename traits::r_vector_name_proxy<RTYPE>::type NameProxy ;
	typedef typename traits::r_vector_proxy<RTYPE>::type value_type ;
	typedef typename traits::r_vector_iterator<RTYPE>::type iterator ;
	typedef typename traits::init_type<RTYPE>::type init_type ;
	typedef typename traits::r_vector_element_converter<RTYPE>::type converter_type ;
	typedef typename traits::storage_type<RTYPE>::type stored_type ;
	typedef MatrixRow<RTYPE> Row ;
	typedef MatrixColumn<RTYPE> Column ;
	
	Vector() : Base() {
		Base::setSEXP( Rf_allocVector( RTYPE, 0 ) ) ;
		init() ;
	} ;
    ~Vector(){};
    
    Vector( SEXP x ) : Base() {
    	Base::setSEXP( r_cast<RTYPE>( x ) ) ;
    }
    
    Vector( const size_t& size ) : Base()  {
    	Base::setSEXP( Rf_allocVector( RTYPE, size) ) ;
		init() ;
    }
    
    Vector( const Dimension& dims) : Base() {
    	Base::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		init() ;
		if( dims.size() > 1 ){
			Base::attr( "dim" ) = dims;
		}
    }
    
    internal::ListInitialization<iterator,init_type> operator=( init_type x){
		iterator start = begin() ; *start = x; 
		return internal::ListInitialization<iterator,init_type>( start + 1 ) ; ;
	}
	
	template <typename InputIterator>
	Vector( InputIterator first, InputIterator last) : Base(){
		assign( first, last ) ;
	}

	Vector( const std::string& st ) : Base(){
		Base::setSEXP( internal::vector_from_string<RTYPE>(st) );
	}
	
#ifdef HAS_INIT_LISTS
	Vector( std::initializer_list<init_type> list ) : Base(){
		assign( list.begin() , list.end() ) ;
	}
#endif
	
    /**
     * the length of the vector, uses Rf_length
     */
    inline R_len_t length() const { return ::Rf_length( Base::m_sexp ) ; }
    
    /**
     * alias of length
     */
    inline R_len_t size() const { return ::Rf_length( Base::m_sexp ) ; }
    
    inline int ncol(){
    	return dims()[1]; 
    }
    
    inline int nrow(){
    	return dims()[0]; 
    }
	
    /**
     * offset based on the dimensions of this vector
     */
    size_t offset(const size_t& i, const size_t& j) const throw(not_a_matrix,index_out_of_bounds){
    	if( !::Rf_isMatrix(Base::m_sexp) ) throw not_a_matrix() ;
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
		if( static_cast<R_len_t>(i) >= ::Rf_length(Base::m_sexp) ) throw index_out_of_bounds() ;
		return i ;
    }
    
    R_len_t offset(const std::string& name) const throw(index_out_of_bounds){
    	SEXP names = RCPP_GET_NAMES( Base::m_sexp ) ;
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
		} ;
		
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
		Base::setSEXP( x) ;
		UNPROTECT(1) ;
	}
	
	template <typename T>
	void push_back( const T& object){
		push_back__impl( converter.get(object) ) ;
	}
	
	template <typename T>
	void push_back( const T& object, const std::string& name ){
		push_back_name__impl( converter.get(object), name ) ;
	}
	
	template <typename T>
	void push_front( const T& object){
		push_front__impl( converter.get(object) ) ;
	}
	
	template <typename T>
	void push_front( const T& object, const std::string& name){
		push_front_name__impl( converter.get(object), name ) ;
	}
	
	
	template <typename T>
	iterator insert( iterator position, const T& object){
		return insert__impl( position, converter.get(object) ) ;
	}
	
	template <typename T>
	iterator insert( int position, const T& object){
		return insert__impl( cache.get(position), converter.get(object) ); 
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
		cache.update(*this) ;
	}
	
private:
	
	void set_sexp(SEXP x){
		Base::setSEXP( x) ;
		update_vector() ;
	}
	
	void push_back__impl(const stored_type& object){
		int n = size() ;
		Vector target( n + 1 ) ;
		SEXP names = RCPP_GET_NAMES(Base::m_sexp) ;
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
		SEXP names = RCPP_GET_NAMES(Base::m_sexp) ;
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
		SEXP names = RCPP_GET_NAMES(Base::m_sexp) ;
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
		SEXP names = RCPP_GET_NAMES(Base::m_sexp) ;
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
		iterator start = begin() ;
		int pos = position - start ;
		Vector target( n+1 ) ;
		iterator target_it = target.begin();
		iterator it = begin() ;
		iterator this_end = end() ;
		SEXP names = RCPP_GET_NAMES(Base::m_sexp) ;
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
		SEXP names = RCPP_GET_NAMES(Base::m_sexp) ;
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
		
		SEXP names = RCPP_GET_NAMES(Base::m_sexp) ;
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
	
	inline int* dims() const {
		if( !::Rf_isMatrix(Base::m_sexp) ) throw not_a_matrix() ;
		return INTEGER( ::Rf_getAttrib( Base::m_sexp, ::Rf_install( "dim") ) ) ;
	}
	
	void init(){
		internal::r_init_vector<RTYPE>(Base::m_sexp) ;
	}

	virtual void update(){ 
		update_vector() ;
	}
	
	traits::r_vector_cache<RTYPE> cache ;
	static converter_type converter ;
	
} ; /* Vector */

template <int RTYPE> 
class Matrix : public Vector<RTYPE> {
public:
	Matrix() : Vector<RTYPE>() {}
	
	Matrix(SEXP x) throw(RObject::not_compatible) : Vector<RTYPE>(){
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		SEXP y = r_cast<RTYPE>( x ) ;
		Vector<RTYPE>::setSEXP( y );
	}
	
	Matrix( const Dimension& dims) : Vector<RTYPE>() {
		if( dims.size() != 2 ) throw RObject::not_compatible("not a matrix") ;
		Vector<RTYPE>::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		Vector<RTYPE>::init() ;
		Vector<RTYPE>::attr( "dim" ) = dims ;
	}
	
	Matrix( const int& nrows, const int& ncols) : Vector<RTYPE>() {
		Vector<RTYPE>::setSEXP( Rf_allocVector( RTYPE, nrows*ncols ) ) ;
		Vector<RTYPE>::init() ;
		Vector<RTYPE>::attr( "dim" ) = Dimension( nrows, ncols ) ;
	}
	
	
	Matrix( const Matrix& other) : Vector<RTYPE>() {
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		Vector<RTYPE>::setSEXP( x ) ;
	}
	
	Matrix& operator=(const Matrix& other) {
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		Vector<RTYPE>::setSEXP( x ) ;
		return *this ;
	}
	
private:
	virtual void update(){
		Vector<RTYPE>::update_vector() ;
	}
	    
} ;

template <int RTYPE>
class MatrixRow {
public:
	typedef Vector<RTYPE> VECTOR ;
	typedef typename VECTOR::Proxy Proxy ;
	typedef typename VECTOR::Proxy reference ;
	// typedef typename VECTOR::value_type value_type ;
	
	class iterator {
	public:
		typedef typename traits::r_vector_iterator<RTYPE>::type vector_iterator ;
		
		typedef int difference_type ;
		typedef typename traits::r_vector_proxy<RTYPE>::type value_type ;
		typedef typename traits::r_vector_proxy<RTYPE>::type reference ;
		typedef typename std::iterator_traits<vector_iterator>::pointer pointer ;
	
		typedef std::random_access_iterator_tag iterator_category ;
		
		iterator( MatrixRow& row_, int index_ ) : row(row_), index(index_){}
		
		iterator& operator++(){ 
			index++;
			return *this ;
		}
		iterator& operator++(int) { 
			index++;
			return *this ;
		}
	
		iterator& operator--(){ 
			index-- ;
			return *this ;
		} 
		iterator& operator--(int){ 
			index-- ;
			return *this ;
		}
		                    
		iterator operator+(difference_type n) const { return iterator( row, index + n ) ; }
		iterator operator-(difference_type n) const { return iterator( row, index - n ) ; }
		
		iterator& operator+=(difference_type n) { index += n ; return *this ;} 
		iterator& operator-=(difference_type n) { index -= n ; return *this ;} 
        	
		reference operator*() {
			return row[index] ;
		}
		pointer operator->(){
			return &row[index] ;
		}
		
		bool operator==( const iterator& other) { return index == other.index ; } 
		bool operator!=( const iterator& other) { return index != other.index ; }
		bool operator<( const iterator& other ) { return index < other.index ;}
		bool operator>( const iterator& other ) { return index > other.index ;}
		bool operator<=( const iterator& other ) { return index <= other.index ; }
		bool operator>=( const iterator& other ) { return index >= other.index ; }
		
		difference_type operator-(const iterator& other) {
			return index - other.index ;
		}
		
	private:
		MatrixRow& row ;
		int index ;
	} ;
	
	MatrixRow( VECTOR& object, int i ) : parent(object), index(i){
		if( ! ::Rf_isMatrix(parent) ) throw not_a_matrix() ;
		if( i < 0 || i >= parent.nrow() ) throw index_out_of_bounds() ;
	}
	
	MatrixRow( const MatrixRow& other ) : parent(other.parent), index(other.index){} ;
	                          
	MatrixRow& operator=( MatrixRow& other ){
		parent = other.parent ;
		index = other.index ;
		return *this ;
	}
	
	reference operator[]( const int& i ){
		/* TODO: should we cache nrow and ncol */
		return parent[ index + i * parent.nrow() ] ;
	}
	
	inline iterator begin(){
		return iterator( *this, 0 ) ;
	}
	
	inline iterator end(){
		return iterator( *this, size() ) ;
	}
	
	inline int size() const {
		return parent.ncol() ;
	}
	
private:
	VECTOR& parent; 
	int index ;
} ;

template <int RTYPE>
class MatrixColumn {
public:
	typedef Vector<RTYPE> VECTOR ;
	typedef typename VECTOR::Proxy Proxy ;
	typedef typename VECTOR::value_type value_type ;
	typedef typename VECTOR::iterator iterator ;
	
	MatrixColumn( VECTOR& object, int i ) : parent(object), index(i){
		if( ! ::Rf_isMatrix(parent) ) throw not_a_matrix() ;
		if( i < 0 || i >= parent.ncol() ) throw index_out_of_bounds() ;
	}
	
	MatrixColumn( const MatrixColumn& other ) : parent(other.parent), index(other.index){} ;
	
	MatrixColumn& operator=( MatrixColumn& other ){
		parent = other.parent ;
		index  = other.index ;
	}
	
	Proxy operator[]( const int& i ){
		/* TODO: should we cache nrow and ncol */
		return parent[ index * parent.ncol() + i ] ;
	}
	
	iterator begin(){
		return parent.begin() + index * parent.ncol() ;
	}
	
	iterator end(){
		return parent.begin() + index * parent.ncol() + parent.nrow() ;
	}
	
	inline int size() const {
		return parent.nrow() ;
	}
	
private:
	VECTOR& parent; 
	int index ;
} ;

typedef Vector<CPLXSXP> ComplexVector ;  
typedef Vector<INTSXP> IntegerVector ;
typedef Vector<LGLSXP> LogicalVector ;
typedef Vector<REALSXP> NumericVector ;
typedef Vector<RAWSXP> RawVector ;

typedef Vector<STRSXP> CharacterVector ;   
typedef Vector<STRSXP> StringVector ;
typedef Vector<VECSXP> GenericVector ;
typedef Vector<VECSXP> List ;
typedef Vector<EXPRSXP> ExpressionVector ;

typedef Matrix<CPLXSXP> ComplexMatrix ;
typedef Matrix<INTSXP> IntegerMatrix ;
typedef Matrix<LGLSXP> LogicalMatrix ;
typedef Matrix<REALSXP> NumericMatrix ;
typedef Matrix<RAWSXP> RawMatrix ;

typedef Matrix<STRSXP> CharacterMatrix ;   
typedef Matrix<STRSXP> StringMatrix ;
typedef Matrix<VECSXP> GenericMatrix ;
typedef Matrix<VECSXP> ListMatrix ;
typedef Matrix<EXPRSXP> ExpressionMatrix ;

namespace internal{
	
	template<int RTYPE> class string_proxy {
	public:
		
		typedef typename ::Rcpp::Vector<RTYPE> VECTOR ;
		
		string_proxy() : parent(0), index(-1){};
		
		/**
		 * Creates a proxy
		 *
		 * @param v reference to the associated character vector
		 * @param index index 
		 */
		string_proxy( VECTOR& v, int index_ ) : 
			parent(&v), index(index_){}
			
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
		
		/**
		 * lhs use. Adds the content of the rhs proxy to the 
		 * element this proxy refers to.
		 */
		string_proxy& operator+=(const string_proxy& rhs){
			std::string full( CHAR(STRING_ELT(*parent,index)) ) ;
			full += CHAR(STRING_ELT( *(rhs.parent), rhs.index)) ;
			SET_STRING_ELT( *parent, index, Rf_mkChar(full.c_str()) ) ;
			return *this ;
		}
		
		/**
		 * lhs use. Adds the string to the element this proxy refers to
		 */
		string_proxy& operator+=(const std::string& rhs){
			std::string full( CHAR(STRING_ELT(*parent,index)) ) ;
			full += rhs ;
			SET_STRING_ELT( *parent, index, Rf_mkChar(full.c_str()) ) ;
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
		 	 return const_cast<char*>( CHAR(STRING_ELT( *parent, index )) );
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
		
	} ;
	
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

}  // Rcpp

namespace std {
	
#undef RCPP_GENERATE_SWAP
#define RCPP_GENERATE_SWAP(TYPE,RTYPE) 							\
	template<> inline void swap< Rcpp::internal::TYPE<RTYPE> >(	\
		Rcpp::internal::TYPE<RTYPE>& a ,							\
		Rcpp::internal::TYPE<RTYPE>& b) { 							\
			a.swap(b) ;												\
		}	; 

RCPP_GENERATE_SWAP( generic_proxy,VECSXP) ;
RCPP_GENERATE_SWAP( generic_proxy,EXPRSXP) ;
RCPP_GENERATE_SWAP( string_proxy,STRSXP) ;
#undef RCPP_GENERATE_SWAP

}

#endif 
