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
		typedef const char* iterator ;
		typedef const char& reference ;
		
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
		
		inline iterator begin() { return get() ; }
		inline iterator end(){ return begin() + size() ; }
		inline reference operator[]( int i ){ return *( get() + i ) ; }
		inline int size(){ return strlen( get() ) ; }
		
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
			parent(v), name(name_){
				RCPP_DEBUG( "generic_name_proxy( VECTOR& = %p, const string& = %s)", v.asSexp(), name_.c_str() );
		} ;
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
			#if RCPP_DEBUG_LEVEL > 0
			SEXP res = get() ;
			RCPP_DEBUG( "generic_name_proxy::get() = <%p> ", res ) ;
			return ::Rcpp::as<T>( res ) ;
			#else
			return ::Rcpp::as<T>( get() ) ;
			#endif
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
		
		template <typename T>
		static target get( const T& input ){
			return caster<T,target>(input) ;
		}
		
		static target get( const target& input ){
			return input ;
		}
	} ;
	
	template <int RTYPE>
	class string_element_converter {
	public:
		typedef SEXP target ;
		
		template <typename T>
		static SEXP get( const T& input){
			std::string out(input) ;
			return Rf_mkChar( out.c_str() ) ;
		}
		
		static SEXP get(const std::string& input){
			return Rf_mkChar( input.c_str() ) ;
		}
		
		static SEXP get(const char& input){
			return Rf_mkChar( &input ) ;
		}
	} ;
	
	template <int RTYPE>
	class generic_element_converter {
	public:
		typedef SEXP target ;
		
		template <typename T>
		static SEXP get( const T& input){
			return ::Rcpp::wrap( input ) ;
		}
		
		static SEXP get( const char* input){
			return ::Rcpp::wrap( input );
		}
		
		static SEXP get(SEXP input){
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
	}
	
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
	
	template <int RTYPE> struct is_trivial  : public true_type{} ;
	template <> struct is_trivial<VECSXP>   : public false_type{} ;
	template <> struct is_trivial<EXPRSXP>  : public false_type{} ;

} // traits 

template <typename VECTOR>
class VectorBase : public RObject{
public:
	VectorBase() : RObject(){
		RCPP_DEBUG( "VectorBase()", 0 ) ;
	}
	VectorBase(SEXP x) : RObject(x){
		update() ;
		RCPP_DEBUG( "VectorBase( SEXP = <%p> ) = <%p>", x, asSexp() ) ;
	}
	~VectorBase(){
		RCPP_DEBUG( "~VectorBase", 0 ) ;
	}
	VectorBase(const VectorBase& v) : RObject( v.asSexp() ){
		update() ;
		RCPP_DEBUG( "VectorBase( const VectorBase& = <%p> ) ) = <%p>", v.asSexp(), asSexp() ) ;
	}
	VectorBase& operator=(const VectorBase& v) {
		setSEXP( v.asSexp() ) ;
		return *this ;
	}
	VECTOR& get_ref(){
		return static_cast<VECTOR&>(*this) ;
	}
	virtual void update(){
		RCPP_DEBUG( "%s::update", DEMANGLE(VectorBase) ) ;
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
	
	struct r_type : traits::integral_constant<int,RTYPE>{} ;
	
	Vector() : Base() {
		RCPP_DEBUG( "Vector()", 0 ) ;
		Base::setSEXP( Rf_allocVector( RTYPE, 0 ) ) ;
		init() ;
	} ;
    ~Vector(){
    	RCPP_DEBUG( "~Vector()", 0 ) ;
	};
    
	Vector( const Vector& other) : Base() {
		Base::setSEXP(other.asSexp()) ;
	}
	
	Vector& operator=( const Vector& other ){
		Base::setSEXP( other.asSexp() ) ;	
	}
	
    Vector( SEXP x ) : Base() {
    	RCPP_DEBUG( "Vector<%d>( SEXP = <%p> )", RTYPE, x) ;
    	Base::setSEXP( r_cast<RTYPE>( x ) ) ;
    	RCPP_DEBUG( "===========", 0) ;
    }
    
    Vector( const size_t& size ) : Base()  {
    	Base::setSEXP( Rf_allocVector( RTYPE, size) ) ;
		init() ;
    }
    
    template <typename U>
    Vector( const size_t& size, const U& u){
    	Base::setSEXP( Rf_allocVector( RTYPE, size) ) ;
		fill( u ) ;	
    }
    
    Vector( const Dimension& dims) : Base() {
    	Base::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		init() ;
		if( dims.size() > 1 ){
			Base::attr( "dim" ) = dims;
		}
    }
    
    template <typename U>
    Vector( const Dimension& dims, const U& u) : Base() {
    	Base::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		fill(u) ;
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

    inline int cols() { 
	return dims()[1]; 
    }
    inline int rows() { 
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
		RCPP_DEBUG(  "update_vector, VECTOR = %s", DEMANGLE(Vector) ) ;
		cache.update(*this) ;
	}
		
/* <code-bloat>

public:
	
	template <TYPENAMES>
	static Vector create(ARGUMENTS){
		return create__dispatch( typename traits::integral_constant<bool, 
			__OR__{{  traits::is_named<___T___>::value  }}
		>::type(), PARAMETERS ) ;  		
	}
	
private:
	
	template <TYPENAMES>
	static Vector create__dispatch( traits::false_type, ARGUMENTS ){
		Vector res(___N___) ;
		iterator it( res.begin() );
		
		////
		__FOR_EACH__{{ *it = converter_type::get(___X___) ; ++it ; }}
		////
		
		return res ;
	}
	
	template <TYPENAMES>
	static Vector create__dispatch( traits::true_type, ARGUMENTS){
		Vector res( ___N___ ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, ___N___ ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
		__FOR_EACH__{{ replace_element( it, names, index, ___X___ ) ; ++it; ++index ; }}
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

*/
public:
	
	template <typename T1>
	static Vector create(const T1& t1){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  
		>::type(), t1 ) ;  		
	}
	
private:
	
	template <typename T1>
	static Vector create__dispatch( traits::false_type, const T1& t1 ){
		Vector res(1) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1>
	static Vector create__dispatch( traits::true_type, const T1& t1){
		Vector res( 1 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 1 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2>
	static Vector create(const T1& t1, const T2& t2){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  
		>::type(), t1, t2 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2 ){
		Vector res(2) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2){
		Vector res( 2 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 2 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3>
	static Vector create(const T1& t1, const T2& t2, const T3& t3){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  
		>::type(), t1, t2, t3 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3 ){
		Vector res(3) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3){
		Vector res( 3 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 3 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  
		>::type(), t1, t2, t3, t4 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4 ){
		Vector res(4) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4){
		Vector res( 4 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 4 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  
		>::type(), t1, t2, t3, t4, t5 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5 ){
		Vector res(5) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5){
		Vector res( 5 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 5 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  
		>::type(), t1, t2, t3, t4, t5, t6 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6 ){
		Vector res(6) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6){
		Vector res( 6 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 6 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7 ){
		Vector res(7) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7){
		Vector res( 7 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 7 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8 ){
		Vector res(8) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8){
		Vector res( 8 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 8 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9 ){
		Vector res(9) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9){
		Vector res( 9 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 9 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10 ){
		Vector res(10) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10){
		Vector res( 10 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 10 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11 ){
		Vector res(11) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11){
		Vector res( 11 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 11 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12 ){
		Vector res(12) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12){
		Vector res( 12 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 12 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13 ){
		Vector res(13) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13){
		Vector res( 13 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 13 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  ||  traits::is_named<T14>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14 ){
		Vector res(14) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
 *it = converter_type::get(t14) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14){
		Vector res( 14 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 14 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
 replace_element( it, names, index, t14 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  ||  traits::is_named<T14>::value  ||  traits::is_named<T15>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15 ){
		Vector res(15) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
 *it = converter_type::get(t14) ; ++it ; 
 *it = converter_type::get(t15) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15){
		Vector res( 15 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 15 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
 replace_element( it, names, index, t14 ) ; ++it; ++index ; 
 replace_element( it, names, index, t15 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  ||  traits::is_named<T14>::value  ||  traits::is_named<T15>::value  ||  traits::is_named<T16>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16 ){
		Vector res(16) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
 *it = converter_type::get(t14) ; ++it ; 
 *it = converter_type::get(t15) ; ++it ; 
 *it = converter_type::get(t16) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16){
		Vector res( 16 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 16 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
 replace_element( it, names, index, t14 ) ; ++it; ++index ; 
 replace_element( it, names, index, t15 ) ; ++it; ++index ; 
 replace_element( it, names, index, t16 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  ||  traits::is_named<T14>::value  ||  traits::is_named<T15>::value  ||  traits::is_named<T16>::value  ||  traits::is_named<T17>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17 ){
		Vector res(17) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
 *it = converter_type::get(t14) ; ++it ; 
 *it = converter_type::get(t15) ; ++it ; 
 *it = converter_type::get(t16) ; ++it ; 
 *it = converter_type::get(t17) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17){
		Vector res( 17 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 17 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
 replace_element( it, names, index, t14 ) ; ++it; ++index ; 
 replace_element( it, names, index, t15 ) ; ++it; ++index ; 
 replace_element( it, names, index, t16 ) ; ++it; ++index ; 
 replace_element( it, names, index, t17 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  ||  traits::is_named<T14>::value  ||  traits::is_named<T15>::value  ||  traits::is_named<T16>::value  ||  traits::is_named<T17>::value  ||  traits::is_named<T18>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18 ){
		Vector res(18) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
 *it = converter_type::get(t14) ; ++it ; 
 *it = converter_type::get(t15) ; ++it ; 
 *it = converter_type::get(t16) ; ++it ; 
 *it = converter_type::get(t17) ; ++it ; 
 *it = converter_type::get(t18) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18){
		Vector res( 18 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 18 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
 replace_element( it, names, index, t14 ) ; ++it; ++index ; 
 replace_element( it, names, index, t15 ) ; ++it; ++index ; 
 replace_element( it, names, index, t16 ) ; ++it; ++index ; 
 replace_element( it, names, index, t17 ) ; ++it; ++index ; 
 replace_element( it, names, index, t18 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  ||  traits::is_named<T14>::value  ||  traits::is_named<T15>::value  ||  traits::is_named<T16>::value  ||  traits::is_named<T17>::value  ||  traits::is_named<T18>::value  ||  traits::is_named<T19>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19 ){
		Vector res(19) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
 *it = converter_type::get(t14) ; ++it ; 
 *it = converter_type::get(t15) ; ++it ; 
 *it = converter_type::get(t16) ; ++it ; 
 *it = converter_type::get(t17) ; ++it ; 
 *it = converter_type::get(t18) ; ++it ; 
 *it = converter_type::get(t19) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19){
		Vector res( 19 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 19 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
 replace_element( it, names, index, t14 ) ; ++it; ++index ; 
 replace_element( it, names, index, t15 ) ; ++it; ++index ; 
 replace_element( it, names, index, t16 ) ; ++it; ++index ; 
 replace_element( it, names, index, t17 ) ; ++it; ++index ; 
 replace_element( it, names, index, t18 ) ; ++it; ++index ; 
 replace_element( it, names, index, t19 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

public:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
	static Vector create(const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19, const T20& t20){
		return create__dispatch( typename traits::integral_constant<bool, 
  traits::is_named<T1>::value  ||  traits::is_named<T2>::value  ||  traits::is_named<T3>::value  ||  traits::is_named<T4>::value  ||  traits::is_named<T5>::value  ||  traits::is_named<T6>::value  ||  traits::is_named<T7>::value  ||  traits::is_named<T8>::value  ||  traits::is_named<T9>::value  ||  traits::is_named<T10>::value  ||  traits::is_named<T11>::value  ||  traits::is_named<T12>::value  ||  traits::is_named<T13>::value  ||  traits::is_named<T14>::value  ||  traits::is_named<T15>::value  ||  traits::is_named<T16>::value  ||  traits::is_named<T17>::value  ||  traits::is_named<T18>::value  ||  traits::is_named<T19>::value  ||  traits::is_named<T20>::value  
		>::type(), t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20 ) ;  		
	}
	
private:
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
	static Vector create__dispatch( traits::false_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19, const T20& t20 ){
		Vector res(20) ;
		iterator it( res.begin() );
		
		////
 *it = converter_type::get(t1) ; ++it ; 
 *it = converter_type::get(t2) ; ++it ; 
 *it = converter_type::get(t3) ; ++it ; 
 *it = converter_type::get(t4) ; ++it ; 
 *it = converter_type::get(t5) ; ++it ; 
 *it = converter_type::get(t6) ; ++it ; 
 *it = converter_type::get(t7) ; ++it ; 
 *it = converter_type::get(t8) ; ++it ; 
 *it = converter_type::get(t9) ; ++it ; 
 *it = converter_type::get(t10) ; ++it ; 
 *it = converter_type::get(t11) ; ++it ; 
 *it = converter_type::get(t12) ; ++it ; 
 *it = converter_type::get(t13) ; ++it ; 
 *it = converter_type::get(t14) ; ++it ; 
 *it = converter_type::get(t15) ; ++it ; 
 *it = converter_type::get(t16) ; ++it ; 
 *it = converter_type::get(t17) ; ++it ; 
 *it = converter_type::get(t18) ; ++it ; 
 *it = converter_type::get(t19) ; ++it ; 
 *it = converter_type::get(t20) ; ++it ; 
		////
		
		return res ;
	}
	
	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
	static Vector create__dispatch( traits::true_type, const T1& t1, const T2& t2, const T3& t3, const T4& t4, const T5& t5, const T6& t6, const T7& t7, const T8& t8, const T9& t9, const T10& t10, const T11& t11, const T12& t12, const T13& t13, const T14& t14, const T15& t15, const T16& t16, const T17& t17, const T18& t18, const T19& t19, const T20& t20){
		Vector res( 20 ) ;                                                                      
		SEXP names = PROTECT( ::Rf_allocVector( STRSXP, 20 ) ) ;
		int index = 0 ;
		iterator it( res.begin() );
		
		////
 replace_element( it, names, index, t1 ) ; ++it; ++index ; 
 replace_element( it, names, index, t2 ) ; ++it; ++index ; 
 replace_element( it, names, index, t3 ) ; ++it; ++index ; 
 replace_element( it, names, index, t4 ) ; ++it; ++index ; 
 replace_element( it, names, index, t5 ) ; ++it; ++index ; 
 replace_element( it, names, index, t6 ) ; ++it; ++index ; 
 replace_element( it, names, index, t7 ) ; ++it; ++index ; 
 replace_element( it, names, index, t8 ) ; ++it; ++index ; 
 replace_element( it, names, index, t9 ) ; ++it; ++index ; 
 replace_element( it, names, index, t10 ) ; ++it; ++index ; 
 replace_element( it, names, index, t11 ) ; ++it; ++index ; 
 replace_element( it, names, index, t12 ) ; ++it; ++index ; 
 replace_element( it, names, index, t13 ) ; ++it; ++index ; 
 replace_element( it, names, index, t14 ) ; ++it; ++index ; 
 replace_element( it, names, index, t15 ) ; ++it; ++index ; 
 replace_element( it, names, index, t16 ) ; ++it; ++index ; 
 replace_element( it, names, index, t17 ) ; ++it; ++index ; 
 replace_element( it, names, index, t18 ) ; ++it; ++index ; 
 replace_element( it, names, index, t19 ) ; ++it; ++index ; 
 replace_element( it, names, index, t20 ) ; ++it; ++index ; 
		////
		
		res.attr("names") = names ;
		UNPROTECT(1); // names
		return res ;
	}

/* </code-bloat> */	

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
		// int pos = position - start ;
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
		RCPP_DEBUG( "%s::update", DEMANGLE(Vector) ) ;
		update_vector() ;
	}
	
	traits::r_vector_cache<RTYPE> cache ;

} ; /* Vector */

template <int RTYPE> 
class Matrix : public Vector<RTYPE> {
public:
	typedef Vector<RTYPE> VECTOR ;
	typedef typename VECTOR::iterator iterator ;
    typedef typename VECTOR::converter_type converter_type ;
    typedef typename VECTOR::stored_type stored_type ;
    	
	Matrix() : VECTOR() {}
	
	Matrix(SEXP x) throw(RObject::not_compatible) : VECTOR(){
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		SEXP y = r_cast<RTYPE>( x ) ;
		VECTOR::setSEXP( y );
	}
	
	Matrix( const Dimension& dims) : VECTOR() {
		if( dims.size() != 2 ) throw RObject::not_compatible("not a matrix") ;
		VECTOR::setSEXP( Rf_allocVector( RTYPE, dims.prod() ) ) ;
		VECTOR::init() ;
		VECTOR::attr( "dim" ) = dims ;
	}
	
	Matrix( const int& nrows, const int& ncols) : VECTOR( Dimension( nrows, ncols ) ) {}
	Matrix( const int& n) : VECTOR( Dimension( n, n ) ) {}
	
	Matrix( const Matrix& other) : VECTOR() {
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		VECTOR::setSEXP( x ) ;
	}
	
	Matrix& operator=(const Matrix& other) {                                                         
		SEXP x = other.asSexp() ;
		if( ! ::Rf_isMatrix(x) ) throw RObject::not_compatible("not a matrix") ;
		VECTOR::setSEXP( x ) ;
		return *this ;
	}
	
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
    
private:
	virtual void update(){
		RCPP_DEBUG( "%s::update", DEMANGLE(Matrix) ) ;
		VECTOR::update_vector() ;
	}
	
	template <typename U>
	void fill_diag__dispatch( traits::false_type, const U& u){
		SEXP elem = PROTECT( converter_type::get( u ) ) ;
		int n = Matrix::ncol() ;
		int offset = n +1 ;
		iterator it( Matrix::begin()) ;
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
		iterator it( Matrix::begin()) ;
		for( int i=0; i<n; i++){
    		*it = elem ;
    		it += offset; 
    	}
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
		
		inline iterator begin(){ return CHAR( STRING_ELT( *parent, index ) ) ; }
		inline iterator end(){ return begin() + size() ; }
		inline int size(){ return strlen( begin() ) ; }
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
		
		private:
			static std::string buffer ;
		
	} ;
	
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

}  // Rcpp

namespace std {
	
#undef RCPP_GENERATE_SWAP
#define RCPP_GENERATE_SWAP(TYPE,RTYPE) 							\
	template<> inline void swap< Rcpp::internal::TYPE<RTYPE> >(	\
		Rcpp::internal::TYPE<RTYPE>& a ,							\
		Rcpp::internal::TYPE<RTYPE>& b) { 							\
			a.swap(b) ;												\
		}

RCPP_GENERATE_SWAP( generic_proxy,VECSXP)
RCPP_GENERATE_SWAP( generic_proxy,EXPRSXP)
RCPP_GENERATE_SWAP( string_proxy,STRSXP)
#undef RCPP_GENERATE_SWAP

}

#endif 
