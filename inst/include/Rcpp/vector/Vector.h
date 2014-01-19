// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Vector.h: Rcpp R/C++ interface class library -- vectors
//
// Copyright (C) 2010 - 2013 Dirk Eddelbuettel and Romain Francois
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

namespace Rcpp{

template <int RTYPE, template <class> class StoragePolicy = PreserveStorage >
class Vector :
    public StoragePolicy< Vector<RTYPE,StoragePolicy> >,       
    public SlotProxyPolicy< Vector<RTYPE,StoragePolicy> >,    
    public AttributeProxyPolicy< Vector<RTYPE,StoragePolicy> >,       
    public NamesProxyPolicy< Vector<RTYPE, StoragePolicy> >,
    public RObjectMethods< Vector<RTYPE, StoragePolicy> >,
    public VectorBase< RTYPE, true, Vector<RTYPE,StoragePolicy> >
{
public:

    typedef StoragePolicy<Vector> Storage ;
    
    typename traits::r_vector_cache_type<RTYPE>::type cache ;
    typedef typename traits::r_vector_proxy<RTYPE>::type Proxy ;
    typedef typename traits::r_vector_const_proxy<RTYPE>::type const_Proxy ;
    typedef typename traits::r_vector_name_proxy<RTYPE>::type NameProxy ;
    typedef typename traits::r_vector_proxy<RTYPE>::type value_type ;
    typedef typename traits::r_vector_iterator<RTYPE>::type iterator ;
    typedef typename traits::r_vector_const_iterator<RTYPE>::type const_iterator ;
    typedef typename traits::init_type<RTYPE>::type init_type ;
    typedef typename traits::r_vector_element_converter<RTYPE>::type converter_type ;
    typedef typename traits::storage_type<RTYPE>::type stored_type ;
	
    /** 
     * Default constructor. Creates a vector of the appropriate type
     * and 0 length
     */
    Vector() ;
    
    /**
     * copy constructor. shallow copy of the SEXP
     */
    Vector( const Vector& other){
        Storage::copy__(other) ;    
    }
    
    Vector& operator=(const Vector& rhs) {
        return Storage::copy__(rhs) ;                    
    }                                           
    
    Vector( SEXP x ) {
        Storage::set__( r_cast<RTYPE>(x) ) ;
    }
    
    template <typename Proxy>
    Vector( const GenericProxy<Proxy>& proxy ){
        Storage::set__( r_cast<RTYPE>(proxy.get()) ) ;    
    }
    
    explicit Vector( const no_init& obj) {
        Storage::set__( Rf_allocVector( RTYPE, obj.get() ) ) ;
    }
    
    Vector( const int& size, const stored_type& u ) {
        RCPP_DEBUG_2( "Vector<%d>( const int& size = %d, const stored_type& u )", RTYPE, size)
        Storage::set__( Rf_allocVector( RTYPE, size) ) ;
        fill( u ) ;
    }
    Vector( const std::string& st ){
        RCPP_DEBUG_2( "Vector<%d>( const std::string& = %s )", RTYPE, st.c_str() )
        Storage::set__( internal::vector_from_string<RTYPE>(st) ) ;
    }
    Vector( const char* st ) {
        RCPP_DEBUG_2( "Vector<%d>( const char* = %s )", RTYPE, st )
        Storage::set__(internal::vector_from_string<RTYPE>(st) ) ;
    }
	
    Vector( const int& siz, stored_type (*gen)(void) ) {
        RCPP_DEBUG_2( "Vector<%d>( const int& siz = %s, stored_type (*gen)(void) )", RTYPE, siz )
        Storage::set__( Rf_allocVector( RTYPE, siz) ) ;
        std::generate( begin(), end(), gen );
    }
    
    Vector( const int& size )  ;
    Vector( const Dimension& dims)  ;
    
    template <typename U> Vector( const Dimension& dims, const U& u) ;
    template <bool NA, typename VEC> Vector( const VectorBase<RTYPE,NA,VEC>& other )  ;
    template <typename U> Vector( const int& size, const U& u) ;
    template <bool NA, typename T> Vector( const sugar::SingleLogicalResult<NA,T>& obj ) ;
    
    template <typename U1>
    Vector( const int& siz, stored_type (*gen)(U1), const U1& u1) ;
    
    template <typename U1, typename U2>
    Vector( const int& siz, stored_type (*gen)(U1,U2), const U1& u1, const U2& u2) ;

    template <typename U1, typename U2, typename U3>
    Vector( const int& siz, stored_type (*gen)(U1,U2,U3), const U1& u1, const U2& u2, const U3& u3) ;

    template <typename InputIterator>
    Vector( InputIterator first, InputIterator last) ;

    template <typename InputIterator>
    Vector( InputIterator first, InputIterator last, int n)  ;

    template <typename InputIterator, typename Func>
    Vector( InputIterator first, InputIterator last, Func func)  ;
    
    template <typename InputIterator, typename Func>
    Vector( InputIterator first, InputIterator last, Func func, int n) ;

#ifdef HAS_CXX0X_INITIALIZER_LIST
    Vector( std::initializer_list<init_type> list ) {
        assign( list.begin() , list.end() ) ;
    }
#endif
	
    template <typename T> Vector& operator=( const T& x) ;
	
    static inline stored_type get_na() { 
        return traits::get_na<RTYPE>(); 
    }
    static inline bool is_na( stored_type x){ 
        return traits::is_na<RTYPE>(x); 
    }
    
    internal::ListInitialization<iterator,init_type> operator=( init_type x){
        iterator start = begin() ; *start = x; 
        return internal::ListInitialization<iterator,init_type>( start + 1 ) ; ;
    }
    
    /**
     * the length of the vector, uses Rf_length
     */
    inline R_len_t length() const { 
        return ::Rf_length( Storage::get__() ) ; 
    }
    
    /**
     * alias of length
     */
    inline R_len_t size() const { 
        return ::Rf_length( Storage::get__() ) ; 
    }
    
    /**
     * offset based on the dimensions of this vector
     */
    size_t offset(const size_t& i, const size_t& j) const {
        if( !::Rf_isMatrix(Storage::get__()) ) throw not_a_matrix() ;
        
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
    size_t offset(const size_t& i) const {
        if( static_cast<R_len_t>(i) >= ::Rf_length(Storage::get__()) ) throw index_out_of_bounds() ;
        return i ;
    }
    
    R_len_t offset(const std::string& name) const {
        SEXP names = RCPP_GET_NAMES( Storage::get__() ) ;
        if( Rf_isNull(names) ) throw index_out_of_bounds(); 
        R_len_t n=size() ;
        for( R_len_t i=0; i<n; ++i){
            if( ! name.compare( CHAR(STRING_ELT(names, i)) ) ){
                return i ;
            }
        }
        throw index_out_of_bounds() ;
        return -1 ; /* -Wall */
    }

    template <typename U>
    void fill( const U& u){
        fill__dispatch( typename traits::is_trivial<RTYPE>::type(), u ) ;
    }

    inline iterator begin() { return cache.get() ; }
    inline iterator end() { return cache.get() + size() ; }
	inline const_iterator begin() const{ return cache.get_const() ; }
    inline const_iterator end() const{ return cache.get_const() + size() ; }
	
    inline Proxy operator[]( int i ){ return cache.ref(i) ; }
    inline const_Proxy operator[]( int i ) const { return cache.ref(i) ; }
    
    inline Proxy operator()( const size_t& i) {
        return cache.ref( offset(i) ) ;
    }
    inline const_Proxy operator()( const size_t& i) const {
        return cache.ref( offset(i) ) ;
    }
    
    inline Proxy operator()( const size_t& i, const size_t& j) {
        return cache.ref( offset(i,j) ) ;
    }
    inline const_Proxy operator()( const size_t& i, const size_t& j) const {
        return cache.ref( offset(i,j) ) ;
    }
	
    inline NameProxy operator[]( const std::string& name ){
        return NameProxy( *this, name ) ;
    }
    inline NameProxy operator()( const std::string& name ){
        return NameProxy( *this, name ) ;
    }
	
    inline NameProxy operator[]( const std::string& name ) const {
        return NameProxy( const_cast<Vector&>(*this), name ) ;
    }
    inline NameProxy operator()( const std::string& name ) const {
        return NameProxy( const_cast<Vector&>(*this), name ) ;
    }
	
    Vector& sort(){
        typename traits::storage_type<RTYPE>::type* start = internal::r_vector_start<RTYPE>( Storage::get__() ) ;
        std::sort( 
            start, start + size(), 
            typename traits::comparator_type<RTYPE>::type()
            ) ;
        return *this ;
    }

    template <typename InputIterator>
    void assign( InputIterator first, InputIterator last){
        /* FIXME: we can do better than this r_cast to avoid 
           allocating an unnecessary temporary object
        */
        Shield<SEXP> x( r_cast<RTYPE>( wrap( first, last ) ) );
        Storage::set__( x) ;
    }

    template <typename InputIterator>
    static Vector import( InputIterator first, InputIterator last){
        Vector v ;
        v.assign( first , last ) ;
        return v ;
    }

    template <typename InputIterator, typename F>
    static Vector import_transform( InputIterator first, InputIterator last, F f){
        return Vector( first, last, f) ;
    }
	
    template <typename T>
    void push_back( const T& object){
        push_back__impl( converter_type::get(object), 
                         typename traits::same_type<stored_type,SEXP>()
                         ) ;
    }
	
    template <typename T>
    void push_back( const T& object, const std::string& name ){
        push_back_name__impl( converter_type::get(object), name, 
                              typename traits::same_type<stored_type,SEXP>()
                              ) ;
    }
	
    template <typename T>
    void push_front( const T& object){
        push_front__impl( converter_type::get(object), 
                          typename traits::same_type<stored_type,SEXP>() ) ;
    }
	
    template <typename T>
    void push_front( const T& object, const std::string& name){
        push_front_name__impl( converter_type::get(object), name, 
                               typename traits::same_type<stored_type,SEXP>() ) ;
    }
	
	
    template <typename T>
    iterator insert( iterator position, const T& object){
        return insert__impl( position, converter_type::get(object), 
                             typename traits::same_type<stored_type,SEXP>()
                             ) ;
    }
	
    template <typename T>
    iterator insert( int position, const T& object){
        return insert__impl( cache.get() + position, converter_type::get(object), 
                             typename traits::same_type<stored_type,SEXP>()
                             ); 
    }
	
    iterator erase( int position){
        return erase_single__impl( cache.get() + position) ;
    }
	
    iterator erase( iterator position){
        return erase_single__impl( position ) ;
    }
	
    iterator erase( int first, int last){
        iterator start = cache.get() ;
        return erase_range__impl( start + first, start + last ) ;
    }
	
    iterator erase( iterator first, iterator last){
        return erase_range__impl( first, last ) ;
    }
	
    void update(SEXP){
        cache.update(*this) ;
    }
		
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
        replace_element__dispatch__isArgument( typename traits::same_type<U,Argument>(), it, names, index, u ) ;
    }

    template <typename U>
    static void replace_element__dispatch__isArgument( traits::false_type, iterator it, SEXP names, int index, const U& u){
        RCPP_DEBUG_2( "  Vector::replace_element__dispatch<%s>(true, index= %d) ", DEMANGLE(U), index ) ; 
		
        *it = converter_type::get(u.object ) ;
        SET_STRING_ELT( names, index, ::Rf_mkChar( u.name.c_str() ) ) ;
    }
	
    template <typename U>
    static void replace_element__dispatch__isArgument( traits::true_type, iterator it, SEXP names, int index, const U& u){
        RCPP_DEBUG_2( "  Vector::replace_element__dispatch<%s>(true, index= %d) ", DEMANGLE(U), index ) ; 
		
        *it = R_MissingArg ;
        SET_STRING_ELT( names, index, ::Rf_mkChar( u.name.c_str() ) ) ;
    }
    
    typedef internal::RangeIndexer<RTYPE,true,Vector> Indexer ;
	
    inline Indexer operator[]( const Range& range ){
        return Indexer( const_cast<Vector&>(*this), range );
    }
    
    template <typename EXPR_VEC>
    Vector& operator+=( const VectorBase<RTYPE,true,EXPR_VEC>& rhs ) ;
    
    template <typename EXPR_VEC>
    Vector& operator+=( const VectorBase<RTYPE,false,EXPR_VEC>& rhs ) ;
    
    /** 
     *  Does this vector have an element with the target name 
     */
    bool containsElementNamed( const char* target ) const ;
     

protected:
    inline int* dims() const {
        if( !::Rf_isMatrix(Storage::get__()) ) throw not_a_matrix() ;
        return INTEGER( ::Rf_getAttrib( Storage::get__(), R_DimSymbol ) ) ;
    }
    void init(){
        RCPP_DEBUG_2( "VECTOR<%d>::init( SEXP = <%p> )", RTYPE, Storage::get__() )
        internal::r_init_vector<RTYPE>(Storage::get__()) ;
    }

private:
    
    void push_back__impl(const stored_type& object, traits::true_type ) ; 
    void push_back__impl(const stored_type& object, traits::false_type ) ; 
	
    void push_back_name__impl(const stored_type& object, const std::string& name, traits::true_type ) ;
    void push_back_name__impl(const stored_type& object, const std::string& name, traits::false_type ) ;
	
    void push_front__impl(const stored_type& object, traits::true_type ) ;
    void push_front__impl(const stored_type& object, traits::false_type ) ;
	
    void push_front_name__impl(const stored_type& object, const std::string& name, traits::true_type ) ; 
    void push_front_name__impl(const stored_type& object, const std::string& name, traits::false_type ) ; 
	
    iterator insert__impl( iterator position, const stored_type& object, traits::true_type ) ;
    iterator insert__impl( iterator position, const stored_type& object, traits::false_type ) ;
		
    iterator erase_single__impl( iterator position ) ;
	
    iterator erase_range__impl( iterator first, iterator last ) ;

    template <typename T> inline void assign_sugar_expression( const T& x ) ;
    
    // sugar
    template <typename T> inline void assign_object( const T& x, traits::true_type )  ;
    
    // anything else
    template <typename T> inline void assign_object( const T& x, traits::false_type ) ;
    	  
    // we are importing a real sugar expression, i.e. not a vector
    template <bool NA, typename VEC>
    inline void import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::false_type ) ;
    
    // we are importing a sugar expression that actually is a vector
    template <bool NA, typename VEC>
    inline void import_sugar_expression( const Rcpp::VectorBase<RTYPE,NA,VEC>& other, traits::true_type ) ;
    
    
    template <typename T>
    inline void import_expression( const T& other, int n ) ;
    
    template <typename T>
    inline void fill_or_generate( const T& t) ;
    
    template <typename T>
    inline void fill_or_generate__impl( const T& gen, traits::true_type) ;
    
    template <typename T>
    inline void fill_or_generate__impl( const T& t, traits::false_type) ;

    template <typename U>
    void fill__dispatch( traits::false_type, const U& u){
        // when this is not trivial, this is SEXP
        Shield<SEXP> elem( converter_type::get( u ) ); 
        iterator it(begin());
        for( int i=0; i<size() ; i++, ++it){
            *it = ::Rf_duplicate( elem ) ;
        }
    }
	
    template <typename U>
    void fill__dispatch( traits::true_type, const U& u){
        std::fill( begin(), end(), converter_type::get( u ) ) ;
    }

public:
    
    static Vector create(){
        return Vector( 0 ) ;
    }

    #include <Rcpp/generated/Vector__create.h>

public:
    
    inline SEXP eval() const {
        return Rcpp_eval( Storage::get__(), R_GlobalEnv ) ;    
    }
    
    inline SEXP eval(SEXP env) const {
        return Rcpp_eval( Storage::get__(), env );    
    }
    
    
} ; /* Vector */

}

#endif
