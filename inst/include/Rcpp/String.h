// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// String.h: Rcpp R/C++ interface class library -- single string
//
// Copyright (C) 2012 - 2013 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp__String_h
#define Rcpp__String_h

#ifndef RCPP_STRING_DEBUG_LEVEL
#define RCPP_STRING_DEBUG_LEVEL 0
#endif


#if RCPP_STRING_DEBUG_LEVEL > 0
    #define RCPP_STRING_DEBUG_FORMAT "%40s:%4d "
    #define RCPP_STRING_DEBUG( MSG ) Rprintf( RCPP_STRING_DEBUG_FORMAT "%s\n" , short_file_name(__FILE__), __LINE__, MSG ) ;
    #define RCPP_STRING_DEBUG_1( fmt, MSG ) Rprintf( RCPP_STRING_DEBUG_FORMAT fmt "\n" , short_file_name(__FILE__), __LINE__, MSG ) ;
    #define RCPP_STRING_DEBUG_2( fmt, M1, M2 ) Rprintf( RCPP_STRING_DEBUG_FORMAT fmt "\n" , short_file_name(__FILE__), __LINE__, M1, M2 ) ;
    #define RCPP_STRING_DEBUG_3( fmt, M1, M2, M3 ) Rprintf( RCPP_STRING_DEBUG_FORMAT fmt "\n" , short_file_name(__FILE__), __LINE__, M1, M2, M3) ;
#else
    #define RCPP_STRING_DEBUG( MSG )
    #define RCPP_STRING_DEBUG_1( fmt, MSG )
    #define RCPP_STRING_DEBUG_2( fmt, M1, M2 )
    #define RCPP_STRING_DEBUG_3( fmt, M1, M2, M3 )
#endif


namespace Rcpp {

    /**
     * A single string, i.e. an element of a character vector.
     * This represents CHARSXP SEXP
     */
    class String {
    public:
        typedef internal::string_proxy<STRSXP> StringProxy;
        typedef internal::const_string_proxy<STRSXP> const_StringProxy;

        /** default constructor */
        String( ): data( Rf_mkChar("") ), buffer(), valid(true), buffer_ready(true), enc(CE_NATIVE) {
            Rcpp_PreserveObject( data );
            RCPP_STRING_DEBUG( "String()" ) ;
        }

        /** copy constructor */
        String( const String& other) : data( other.get_sexp()), valid(true), buffer_ready(false), enc(Rf_getCharCE(other.get_sexp())) {
            Rcpp_PreserveObject( data );
            RCPP_STRING_DEBUG( "String(const String&)" ) ;
        }

        String( const String& other, const std::string& enc) : data( other.get_sexp()), valid(true), buffer_ready(false) {
            Rcpp_PreserveObject( data );
            set_encoding(enc);
            RCPP_STRING_DEBUG( "String(const String&)" ) ;
        }

        /** construct a string from a single CHARSXP SEXP */
        String(SEXP charsxp) : data(charsxp), valid(true), buffer_ready(false), enc(Rf_getCharCE(charsxp)) {
            Rcpp_PreserveObject( data );
            RCPP_STRING_DEBUG( "String(SEXP)" ) ;
        }

        String(SEXP charsxp, const std::string& enc) : data(charsxp), valid(true), buffer_ready(false) {
            Rcpp_PreserveObject( data );
            set_encoding(enc);
            RCPP_STRING_DEBUG( "String(SEXP)" ) ;
        }

        /** from string proxy */
        String( const StringProxy& proxy ): data( proxy.get() ), valid(true), buffer_ready(false), enc(Rf_getCharCE(proxy.get())){
            Rcpp_PreserveObject( data );
            RCPP_STRING_DEBUG( "String( const StringProxy&)" ) ;
        }

        String( const StringProxy& proxy, const std::string& enc ): data( proxy.get() ), valid(true), buffer_ready(false) {
            Rcpp_PreserveObject( data );
            set_encoding(enc);
            RCPP_STRING_DEBUG( "String( const StringProxy&)" ) ;
        }

        /** from string proxy */
        String( const const_StringProxy& proxy ): data( proxy.get() ), valid(true), buffer_ready(false), enc(Rf_getCharCE(proxy.get())){
            Rcpp_PreserveObject( data );
            RCPP_STRING_DEBUG( "String( const const_StringProxy&)" ) ;
        }

        String( const const_StringProxy& proxy, const std::string& enc ): data( proxy.get() ), valid(true), buffer_ready(false) {
            Rcpp_PreserveObject( data );
            set_encoding(enc);
            RCPP_STRING_DEBUG( "String( const const_StringProxy&)" ) ;
        }

        /** from a std::string */
        String( const std::string& s) : buffer(s), valid(false), buffer_ready(true), enc(CE_NATIVE) {
            data = R_NilValue ;
            RCPP_STRING_DEBUG( "String(const std::string& )" ) ;
        }

        String( const std::wstring& s) : data(internal::make_charsexp(s)), valid(true), buffer_ready(false), enc(CE_NATIVE) {
            Rcpp_PreserveObject( data );
            RCPP_STRING_DEBUG( "String(const std::wstring& )" ) ;
        }

        /** from a const char* */
        String( const char* s) : buffer(s), valid(false), buffer_ready(true), enc(CE_NATIVE){
            data = R_NilValue ;
            RCPP_STRING_DEBUG( "String(const char*)" ) ;
        }

        String( const wchar_t* s) : data(internal::make_charsexp(s)), valid(true), buffer_ready(false), enc(CE_NATIVE) {
            Rcpp_PreserveObject( data );
            RCPP_STRING_DEBUG( "String(const wchar_t* s)" ) ;
        }

        /** constructors from R primitives */
        String( int x ) : data( internal::r_coerce<INTSXP,STRSXP>(x) ), valid(true), buffer_ready(false), enc(CE_NATIVE){Rcpp_PreserveObject( data );}
        String( double x ) : data( internal::r_coerce<REALSXP,STRSXP>(x) ), valid(true), buffer_ready(false), enc(CE_NATIVE){Rcpp_PreserveObject( data );}
        String( bool x ) : data( internal::r_coerce<LGLSXP,STRSXP>(x) ), valid( true ) , buffer_ready(false), enc(CE_NATIVE){Rcpp_PreserveObject( data );}
        String( Rcomplex x ) : data( internal::r_coerce<CPLXSXP,STRSXP>(x) ), valid( true ), buffer_ready(false), enc(CE_NATIVE){Rcpp_PreserveObject( data );}
        String( Rbyte x ) : data( internal::r_coerce<RAWSXP,STRSXP>(x) ), valid(true), buffer_ready(false), enc(CE_NATIVE){Rcpp_PreserveObject( data );}

        ~String() {
            Rcpp_ReleaseObject( data );
            data = R_NilValue ;
        }


        inline String& operator=( int x     ){ data = Rcpp_ReplaceObject( data, internal::r_coerce<INTSXP ,STRSXP>( x )) ; valid = true ; buffer_ready = false ; return *this ; }
        inline String& operator=( double x  ){ data = Rcpp_ReplaceObject( data, internal::r_coerce<REALSXP,STRSXP>( x )) ; valid = true ; buffer_ready = false ; return *this ; }
        inline String& operator=( Rbyte x   ){ data = Rcpp_ReplaceObject( data, internal::r_coerce<RAWSXP ,STRSXP>( x )) ; valid = true ; buffer_ready = false ; return *this ; }
        inline String& operator=( bool x    ){ data = Rcpp_ReplaceObject( data, internal::r_coerce<LGLSXP ,STRSXP>( x )) ; valid = true ; buffer_ready = false ; return *this ; }
        inline String& operator=( Rcomplex x){ data = Rcpp_ReplaceObject( data, internal::r_coerce<CPLXSXP,STRSXP>( x )) ; valid = true ; buffer_ready = false ; return *this ; }
        inline String& operator=( SEXP x){ data = Rcpp_ReplaceObject( data, x ) ; valid = true ; buffer_ready = false ; return *this ; }
        inline String& operator=( const StringProxy& proxy){ data = Rcpp_ReplaceObject( data, proxy.get() ) ; valid = true ; buffer_ready=false ; return *this ; }
        inline String& operator=( const String& other ){ data = Rcpp_ReplaceObject( data, other.get_sexp() ) ; valid = true ; buffer_ready = false ; return *this ; }
        inline String& operator=( const std::string& s){  buffer = s ; valid = false ; buffer_ready = true ; return *this ; }
        inline String& operator=( const char* s){ buffer = s ; valid = false ; buffer_ready = true ; return *this ; }

    private:
        template <typename T>
        inline String& assign_wide_string( const T& s){
            data = Rcpp_ReplaceObject( data, internal::make_charsexp( s )) ;
            valid = true ;
            buffer_ready = false ;
            return *this ;
        }

    public:
        inline String& operator=( const std::wstring& s){  return assign_wide_string(s) ; }
        inline String& operator=( const wchar_t* s){ return assign_wide_string(s) ; }

        inline String& operator+=( const std::string& s){
            RCPP_STRING_DEBUG( "String::operator+=( std::string )" ) ;
            if( is_na() ) return *this ;
            setBuffer() ; buffer += s ; valid = false ;
            return *this ;
        }

        inline String& operator+=( const char* s){
            RCPP_STRING_DEBUG( "String::operator+=( const char*)" ) ;
            if( is_na() ) return *this ;
            setBuffer() ; buffer += s ; valid = false ;
            return *this ;
        }
     private:
         template <typename T>
         inline String& append_wide_string( const T& s){
            RCPP_STRING_DEBUG_1( "String::operator+=( %s )", DEMANGLE(T) ) ;
            setData() ;
            if( is_na() ) return *this ;
            const char* buf = CHAR( data );
            std::wstring tmp( buf, buf + strlen(buf ) ) ;
            tmp += s ;
            data = Rcpp_ReplaceObject( data, internal::make_charsexp( tmp ) ) ;
            valid = true ;
            buffer_ready = false ;
            return *this ;
         }

     public:

        inline String& operator+=( const std::wstring& s){ return append_wide_string( s ); }
        inline String& operator+=( const wchar_t* s){ return append_wide_string( s ); }

        inline String& operator+=( const String& other ){
            RCPP_STRING_DEBUG( "String::operator+=( const char*)" ) ;
            if( is_na() ) return *this ;
            if( other.is_na() ){ data = Rcpp_ReplaceObject( data, NA_STRING) ; valid = true ; buffer_ready = false ; return *this ; }
            setBuffer() ; buffer += other ; valid = false ;
            return *this ;
        }
        inline String& operator+=( const StringProxy& proxy){
            RCPP_STRING_DEBUG( "String::operator+=( const StringProxy& )" ) ;
            if( is_na() ) return *this ;
            SEXP proxy_sexp = proxy ;
            if( proxy_sexp == NA_STRING ) { data = Rcpp_ReplaceObject( data, NA_STRING) ; valid = true; buffer_ready = false ; return *this ;}
            setBuffer() ; buffer += CHAR(proxy_sexp) ; valid = false ;
            return *this ;
        }
        inline String& operator+=( SEXP x){
            RCPP_STRING_DEBUG( "String::operator+=( SEXP )" ) ;
            if( is_na() ) return *this ;
            if( x == NA_STRING ) { data = Rcpp_ReplaceObject( data, NA_STRING ) ; valid = true; buffer_ready = false ; return *this ;}
            setBuffer() ; buffer += CHAR(x) ; valid = false ;
            return *this ;
        }
        // inline String& operator+=( int x     ){ data += char_nocheck(internal::r_coerce<INTSXP ,STRSXP>( x ) ) ; return *this ; }
        // inline String& operator+=( double x  ){ data += char_nocheck(internal::r_coerce<REALSXP,STRSXP>( x ) ) ; return *this ; }
        // inline String& operator+=( Rbyte x   ){ data += char_nocheck(internal::r_coerce<RAWSXP ,STRSXP>( x ) ) ; return *this ; }
        // inline String& operator+=( bool x    ){ data += char_nocheck(internal::r_coerce<LGLSXP ,STRSXP>( x ) ) ; return *this ; }
        // inline String& operator+=( Rcomplex x){ data += char_nocheck(internal::r_coerce<CPLXSXP,STRSXP>( x ) ) ; return *this ; }


        inline String& replace_first( const char* s, const char* news ){
            RCPP_STRING_DEBUG_2( "String::replace_first( const char* = '%s' , const char* = '%s')", s, news ) ;
            if( is_na() ) return *this ;
            setBuffer() ;
            size_t index = buffer.find_first_of( s ) ;
            if( index != std::string::npos ) buffer.replace( index, strlen(s), news ) ;
            valid = false ;
            return *this ;
        }
        inline String& replace_first( const Rcpp::String& s, const char* news ){
            // replace NA -> do nothing
            if( s.is_na() ) return *this ;
            return replace_first( s.get_cstring(), news ) ;
        }
        inline String& replace_first( const char* s, const Rcpp::String& news ){
            // replace NA -> do nothing
            if( news.is_na() ) return *this ;
            return replace_first( s, news.get_cstring() ) ;
        }
        inline String& replace_first( const Rcpp::String& s, const Rcpp::String& news ){
            // replace NA -> do nothing
            if( s.is_na() || news.is_na() ) return *this ;
            return replace_first( s.get_cstring(), news.get_cstring() ) ;
        }

        inline String& replace_last( const char* s, const char* news ){
            RCPP_STRING_DEBUG_2( "String::replace_last( const char* = '%s' , const char* = '%s')", s, news ) ;
            if( is_na() ) return *this ;
            setBuffer() ;
            size_t index = buffer.find_last_of( s ) ;
            if( index != std::string::npos ) buffer.replace( index, strlen(s), news ) ;
            valid = false ;
            return *this ;
        }
        inline String& replace_last( const Rcpp::String& s, const char* news ){
            // replace NA -> do nothing
            if( s.is_na() ) return *this ;
            return replace_last( s.get_cstring(), news ) ;
        }
        inline String& replace_last( const char* s, const Rcpp::String& news ){
            // replace NA -> do nothing
            if( news.is_na() ) return *this ;
            return replace_last( s, news.get_cstring() ) ;
        }
        inline String& replace_last( const Rcpp::String& s, const Rcpp::String& news ){
            // replace NA -> do nothing
            if( s.is_na() || news.is_na() ) return *this ;
            return replace_last( s.get_cstring(), news.get_cstring() ) ;
        }


        inline String& replace_all( const char* s, const char* news ){
            RCPP_STRING_DEBUG_2( "String::replace_all( const char* = '%s' , const char* = '%s')", s, news ) ;
            if( is_na() ) return *this ;
            setBuffer() ;
            size_t lens = strlen(s), len_news = strlen(news), index = buffer.find( s ) ;
            while( index != std::string::npos ){
                buffer.replace( index, lens, news ) ;
                index = buffer.find( s, index + len_news ) ;
            }
            valid = false ;
            return *this ;
        }

        template <typename LHS, typename RHS>
        inline String& replace_all( const LHS& s, const RHS& news ){
            return replace_all( String( s ), String(news) ) ;
        }

        inline String& replace_all( const Rcpp::String& s, const char* news ){
            // replace NA -> do nothing
            if( s.is_na() ) return *this ;
            return replace_all( s.get_cstring(), news ) ;
        }
        inline String& replace_all( const char* s, const Rcpp::String& news ){
            // replace NA -> do nothing
            if( news.is_na() ) return *this ;
            return replace_all( s, news.get_cstring() ) ;
        }
        inline String& replace_all( const Rcpp::String& s, const Rcpp::String& news ){
            // replace NA -> do nothing
            if( s.is_na() || news.is_na() ) return *this ;
            return replace_all( s.get_cstring(), news.get_cstring() ) ;
        }

        inline String& push_back( const char* s){
            if( is_na() ) return *this ;
            setBuffer() ; valid = false ; buffer += s ;
            return *this ;
        }
        inline String& push_back( const std::string& s){
            return push_back( s.c_str() ) ;
        }
        inline String& push_back( const Rcpp::String& s){
            if( is_na() ) return *this ;
            if( s.is_na() ){ set_na(); return *this ; }
            return push_back( s.get_cstring() ) ;
        }

        inline String& push_front( const char* s){
            if( is_na() ) return *this ;
            setBuffer() ; valid = false ; buffer = s + buffer;
            return *this ;
        }
        inline String& push_front( const std::string& s){
            return push_front( s.c_str() ) ;
        }
        inline String& push_front( const Rcpp::String& s){
            if( is_na() ) return *this ;
            if( s.is_na() ){ set_na(); return *this ; }
            return push_front( s.get_cstring() ) ;
        }


        inline void set_na(){
            data = Rcpp_ReplaceObject(data, NA_STRING) ;
            valid = true; buffer_ready = false ;
        }


        inline SEXP get_sexp() const {
            RCPP_STRING_DEBUG_1( "String::get_sexp const ( valid = %d) ", valid ) ;
            return valid ? data : Rf_mkCharCE( buffer.c_str(), enc ) ;
        }

        inline SEXP get_sexp() {
            RCPP_STRING_DEBUG_1( "String::get_sexp ( valid = %d) ", valid ) ;
            setData() ; return data ;
        }

        inline operator std::string() const {
            return get_cstring() ;
        }

        inline operator std::wstring() const {
            const char* s = get_cstring() ;
            return std::wstring( s, s + strlen(s) );
        }

        inline const char* get_cstring() const {
            return buffer_ready ? buffer.c_str() : CHAR(data) ;
        }

        inline const std::string get_encoding() const {
            switch (enc) {
                case CE_BYTES:
                    return "bytes";
                case CE_LATIN1:
                    return "latin1";
                case CE_UTF8:
                    return "UTF-8";
                default:
                    return "unknown";
            }
        }

        inline void set_encoding( cetype_t encoding ) {
            enc = encoding;

            if (valid) {
                data = Rcpp_ReplaceObject(data, Rf_mkCharCE(Rf_translateCharUTF8(data), encoding) );
            } else {
                data = Rf_mkCharCE(buffer.c_str(), encoding) ;
                Rcpp_PreserveObject( data );
                valid = true ;
            }
        }

        inline void set_encoding(const std::string & encoding) {
            if ( encoding == "bytes" ) {
                set_encoding( CE_BYTES );
            } else if ( encoding == "latin1" ) {
                set_encoding( CE_LATIN1 );
            } else if ( encoding == "UTF-8" ) {
                set_encoding( CE_UTF8 );
            } else {
                set_encoding( CE_ANY );
            }
        }

        bool operator<( const Rcpp::String& other ) const {
            return strcmp( get_cstring(), other.get_cstring() ) < 0;
        }

        bool operator==( const Rcpp::String& other) const {
            return get_sexp() == other.get_sexp() ;
        }
        bool operator!=( const Rcpp::String& other) const {
            return get_sexp() != other.get_sexp() ;
        }

        bool operator>( const Rcpp::String& other ) const {
            return strcmp( get_cstring(), other.get_cstring() ) > 0;
        }

    private:

        /** the CHARSXP this String encapsulates */
        SEXP data ;

        /** a buffer used to do string operations withough going back to the SEXP */
        std::string buffer ;

        /** is data in sync with buffer */
        bool valid ;

        /** is the buffer initialized */
        bool buffer_ready ;

        /** the encoding of encapsulated CHARSXP */
        cetype_t enc;

        inline bool is_na() const { return data == NA_STRING ; }
        inline void setBuffer(){
            if( !buffer_ready){
                buffer = char_nocheck(data) ;
                buffer_ready  = true ;
            }
        }
        inline void setData(){
            RCPP_STRING_DEBUG( "setData" ) ;
            if(!valid) {
                data = Rf_mkCharCE(buffer.c_str(), enc) ;
                Rcpp_PreserveObject( data );
                valid = true ;
            }
        }
        template <typename T> void append( const T& s){ buffer += s ;}
    } ;

    namespace traits{
        template<> struct r_type_traits<Rcpp::String>{ typedef r_type_RcppString_tag r_category ; } ;
        template<> struct r_sexptype_traits<Rcpp::String>{ enum{ rtype = STRSXP } ; } ;
    }

    namespace internal {
        template <int RTYPE>
        string_proxy<RTYPE>& string_proxy<RTYPE>::operator=( const String& s){
            set( s.get_sexp() );
            return *this ;
        }

        template <int RTYPE>
        SEXP string_element_converter<RTYPE>::get( const Rcpp::String& input) {
            RCPP_DEBUG( "string_element_converter::get< Rcpp::String >()" )
            return input.get_sexp() ;
		}

        template <>
        inline SEXP make_charsexp<Rcpp::String>( const Rcpp::String& s){
            return s.get_sexp() ;
        }

        template <int RTYPE>
        template <typename T>
        string_proxy<RTYPE>& string_proxy<RTYPE>::operator+=(const T& rhs) {
            String tmp = get() ;
            tmp += rhs ;
            set( tmp ) ;
            return *this ;
        }

	}


    template <>
    inline SEXP wrap<Rcpp::String>( const Rcpp::String& object) {
        RCPP_STRING_DEBUG( "wrap<String>()" ) ;
        Shield<SEXP> res( Rf_allocVector( STRSXP, 1 ) ) ;
        SEXP data = object.get_sexp();
        Rcpp_PreserveObject( data );
        SET_STRING_ELT( res, 0, data ) ;
        return res ;
    }


} // Rcpp

#endif
