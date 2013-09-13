// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
// jedit: :folding=explicit:
//
// api.cpp: Rcpp R/C++ interface class library -- Rcpp api
//
// Copyright (C) 2012 - 2013  Dirk Eddelbuettel and Romain Francois
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
  
#include <Rcpp.h>

#include "internal.h" 

// for R_ObjectTable
#include <R_ext/Callbacks.h>
#include <R_ext/PrtUtil.h>

// {{{ Rcpp api classes
namespace Rcpp {
         
    // {{{ SexpStack
    static SEXP RCPP_PROTECTION_STACK = R_NilValue ;
    static SEXP* RCPP_PROTECTION_STACK_PTR = 0 ;
    static bool RCPP_PROTECTION_STACK_READY = false ;
    
    #define GET_TOP() TRUELENGTH(RCPP_PROTECTION_STACK)
    #define SET_TOP(TOP) SET_TRUELENGTH(RCPP_PROTECTION_STACK, TOP)
    
    inline void init_ProtectionStack(){
        if(!RCPP_PROTECTION_STACK_READY){
            RCPP_PROTECTION_STACK = get_Rcpp_protection_stack() ;
            RCPP_PROTECTION_STACK_PTR = get_vector_ptr(RCPP_PROTECTION_STACK) ;
            RCPP_PROTECTION_STACK_READY = true ;
        }
    }
    
    SEXP Rcpp_PreserveObject(SEXP x){ 
#if RCPP_USE_NEW_PRESERVE_RELEASE
        if( x != R_NilValue ){
            init_ProtectionStack();
            int top = GET_TOP() ;
            RCPP_DEBUG_2( "Rcpp_PreserveObject( <%p>), top = %d", x, top )
            top++ ; 
            // RCPP_PROTECTION_STACK_PTR[top] = x ;
            set_vector_elt( RCPP_PROTECTION_STACK, top, x ) ;
            SET_TOP(top) ;
        }
        #if RCPP_DEBUG_LEVEL > 1 
        Rcpp_Stack_Debug() ;
        #endif
#else
        if( x != R_NilValue ) {
            R_PreserveObject(x); 
        }
#endif
        return x ;
    }
    void Rcpp_ReleaseObject(SEXP x){
#if RCPP_USE_NEW_PRESERVE_RELEASE
        if( x != R_NilValue ){
            init_ProtectionStack();
            
            int top = GET_TOP();
            RCPP_DEBUG_2( "Rcpp_ReleaseObject( <%p>),  top = %d )", x, top )
        
            if( x == RCPP_PROTECTION_STACK_PTR[top] ) {
                RCPP_PROTECTION_STACK_PTR[top] = R_NilValue ;
                top-- ;
                SET_TOP(top) ;
            } else {
                int i = top ;
                for( ; i>=0; i--){
                    if( x == RCPP_PROTECTION_STACK_PTR[i] ){
                        // swap position i and top
                        // perhaps should bubble down instead
                        
                        RCPP_PROTECTION_STACK_PTR[i] = RCPP_PROTECTION_STACK_PTR[top] ;
                        RCPP_PROTECTION_STACK_PTR[top] = R_NilValue ;
                        top-- ;
                
                        SET_TOP(top) ;
                        break ;
                    }
                }
                #if RCPP_DEBUG_LEVEL > 0
                if( i < 0 ) RCPP_DEBUG_2( "!!!! STACK ERROR, did not find SEXP <%p> (i=%d)", x, i ) ;
                #endif  
            }
            #if RCPP_DEBUG_LEVEL > 1 
            Rcpp_Stack_Debug() ;
            #endif
        }
#else
        if (x != R_NilValue) {
            R_ReleaseObject(x); 
        }
#endif
    }

    SEXP Rcpp_ReplaceObject(SEXP x, SEXP y){
        if( x == R_NilValue ){
            Rcpp_PreserveObject( y ) ;    
        } else if( y == R_NilValue ){
            Rcpp_ReleaseObject( x ) ;
        } else {
#if RCPP_USE_NEW_PRESERVE_RELEASE
            init_ProtectionStack();
            
            int top = GET_TOP(); 
            RCPP_DEBUG_3( "Rcpp_ReplaceObject( <%p> , <%p> ),  top = %d )", x, y, top )
            int i = top ;
            for( ; i>= 0; i--){
                if( x == RCPP_PROTECTION_STACK_PTR[i] ){
                    set_vector_elt( RCPP_PROTECTION_STACK, i, y) ;
                    break ;
                }
            }
            #if RCPP_DEBUG_LEVEL > 0
            if( i < 0 ) RCPP_DEBUG_1( "STACK ERROR, did not find SEXP <%p>", x ) ;
            #endif
            
            #if RCPP_DEBUG_LEVEL > 1 
            Rcpp_Stack_Debug() ;
            #endif
#else        
            // if we are setting to the same SEXP as we already have, do nothing 
            if (x != y) {
                
                // the previous SEXP was not NULL, so release it 
                Rcpp_ReleaseObject(x);
                
                // the new SEXP is not NULL, so preserve it 
                Rcpp_PreserveObject(y);
                        
                //update();
            }
#endif
        }
        return y ;
    }                                                                                          

    void Rcpp_Stack_Debug(){
        init_ProtectionStack();
        int top = GET_TOP() ;
        if( top == -1 ){
            Rprintf( "Rcpp_Stack_Debug [<<%p>>] : empty stack\n", RCPP_PROTECTION_STACK )    ;
        } else {                      
            int n = top + 1  ;
            Rprintf( "Rcpp_Stack_Debug, %d objects on stack [<<%p>>]\n", n, RCPP_PROTECTION_STACK  )    ;
            for( int i=0; i<n;i++){
                SEXP ptr = RCPP_PROTECTION_STACK_PTR[i] ;
                Rprintf( "[%4d] TYPE = %s, pointer = <%p>\n", i, sexp_to_name(TYPEOF(ptr)), ptr ) ;    
            }
        }
    }
    // }}}
    
                          

    // {{{ Rostream
    template <> inline std::streamsize Rstreambuf<true>::xsputn(const char *s, std::streamsize num ) {
        Rprintf( "%.*s", num, s ) ;
        return num ;
    }
    template <> inline std::streamsize Rstreambuf<false>::xsputn(const char *s, std::streamsize num ) {
        REprintf( "%.*s", num, s ) ; 
        return num ;
    }
    
    template <> inline int Rstreambuf<true>::overflow(int c ) {
      if (c != EOF) Rprintf( "%.1s", &c ) ;
      return c ;
    }
    template <> inline int Rstreambuf<false>::overflow(int c ) {
      if (c != EOF) REprintf( "%.1s", &c ) ;
      return c ;
    }
        
    template <> inline int Rstreambuf<true>::sync(){
        ::R_FlushConsole() ;
        return 0 ;
    }
    template <> inline int Rstreambuf<false>::sync(){
        ::R_FlushConsole() ;
        return 0 ;
    }
    Rostream<true>  Rcout;
    Rostream<false> Rcerr;
    // }}}
    
    // {{{ Evaluator
    SEXP Evaluator::run(SEXP expr, SEXP env) {
        PROTECT(expr);

        reset_current_error() ; 

        Environment RCPP = Environment::Rcpp_namespace(); 
        static SEXP tryCatchSym = NULL, evalqSym, conditionMessageSym, errorRecorderSym, errorSym ;
        if (!tryCatchSym) {
            tryCatchSym               = ::Rf_install("tryCatch");
            evalqSym                  = ::Rf_install("evalq");
            conditionMessageSym       = ::Rf_install("conditionMessage");
            errorRecorderSym          = ::Rf_install(".rcpp_error_recorder");
            errorSym                  = ::Rf_install("error");
        }

        SEXP call = PROTECT( Rf_lang3( 
            tryCatchSym, 
            Rf_lang3( evalqSym, expr, env ),
            errorRecorderSym
        ) ) ;
        SET_TAG( CDDR(call), errorSym ) ;
        /* call the tryCatch call */
        SEXP res  = PROTECT(::Rf_eval( call, RCPP ) );
        
        UNPROTECT(3) ;
        
        if( error_occured() ) {
            SEXP current_error        = PROTECT( rcpp_get_current_error() ) ;
            SEXP conditionMessageCall = PROTECT(::Rf_lang2(conditionMessageSym, current_error)) ;
            SEXP condition_message    = PROTECT(::Rf_eval(conditionMessageCall, R_GlobalEnv)) ;
            std::string message(CHAR(::Rf_asChar(condition_message)));
            UNPROTECT( 3 ) ;
            throw eval_error(message) ;
        }

        return res ;
    }

    SEXP Evaluator::run( SEXP expr) {
        return run(expr, R_GlobalEnv );
    }
    // }}}
    
    // {{{ RObject
    void RObject::setSEXP(SEXP x){
        RCPP_DEBUG_2( "RObject::setSEXP(SEXP = <%p>, TYPEOF=%s )", x, sexp_to_name(TYPEOF(x)) ) 
    
        // replace the currently protected SEXP by the new one
        m_sexp = Rcpp_ReplaceObject(m_sexp, x) ;
        
    }

    RObject::RObject() : m_sexp(R_NilValue) {}  
    RObject::RObject(SEXP x)  : m_sexp(Rcpp_PreserveObject(x)){}

    /* copy constructor */
    RObject::RObject( const RObject& other ) : m_sexp( Rcpp_PreserveObject(other.asSexp() ) ) {}

    RObject& RObject::operator=( const RObject& other){
        setSEXP( other.asSexp() ) ; 
        return *this ;
    }

    RObject& RObject::operator=( SEXP other ){
        setSEXP( other ) ; 
        return *this ;
    }

    RObject::~RObject() {
        RCPP_DEBUG_1("~RObject(<%p>)", m_sexp)
        Rcpp_ReleaseObject(m_sexp) ;
    }

    std::vector<std::string> RObject::attributeNames() const {
        /* inspired from do_attributes@attrib.c */
        
        std::vector<std::string> v ;
        SEXP attrs = ATTRIB(m_sexp);
        while( attrs != R_NilValue ){
            v.push_back( std::string(CHAR(PRINTNAME(TAG(attrs)))) ) ;
            attrs = CDR( attrs ) ;
        }
        return v ;
    }

    bool RObject::hasAttribute( const std::string& attr) const {
        SEXP attrs = ATTRIB(m_sexp);
        while( attrs != R_NilValue ){
            if( attr == CHAR(PRINTNAME(TAG(attrs))) ){
                return true ;
            }
            attrs = CDR( attrs ) ;
        }
        return false; /* give up */
    }

    RObject::SlotProxy::SlotProxy( const RObject& v, const std::string& name) : 
        parent(v), slot_name(name)
    {
        SEXP nameSym = Rf_install(name.c_str());            // cannot be gc()'ed  once in symbol table
        if( !R_has_slot( v, nameSym) ){
            throw no_such_slot() ; 
        }
    }

    RObject::SlotProxy& RObject::SlotProxy::operator=(const SlotProxy& rhs){
        set( rhs.get() ) ;
        return *this ;
    }


    SEXP RObject::SlotProxy::get() const {
        SEXP slotSym = Rf_install( slot_name.c_str() );     // cannot be gc()'ed  once in symbol table
        return R_do_slot( parent, slotSym ) ;       
    }

    // TODO: this should not be const
    void RObject::SlotProxy::set( SEXP x) const {
        SEXP slotnameSym = Rf_install( slot_name.c_str() ); // cannot be gc()'ed  once in symbol table
        // the SEXP might change (.Data)
        SEXP new_obj = PROTECT( R_do_slot_assign(parent, slotnameSym, x) ) ;
        const_cast<RObject&>(parent).setSEXP( new_obj ) ;
        UNPROTECT(1) ;
    }

    SEXP RObject::AttributeProxy::get() const {
        SEXP attrnameSym = Rf_install( attr_name.c_str() ); // cannot be gc()'ed  once in symbol table
        return Rf_getAttrib( parent, attrnameSym ) ;
    }

    // TODO: this should not be const
    void RObject::AttributeProxy::set(SEXP x) const{
        SEXP attrnameSym = Rf_install( attr_name.c_str() ); // cannot be gc()'ed  once in symbol table
#if RCPP_DEBUG_LEVEL > 0
        RCPP_DEBUG_1( "RObject::AttributeProxy::set() before = <%p>", parent.asSexp() ) ;
        SEXP res = Rf_setAttrib( parent, attrnameSym, x ) ;
        RCPP_DEBUG_1( "RObject::AttributeProxy::set() after  = <%p>", res ) ;
#else
        Rf_setAttrib( parent, attrnameSym, x ) ;
#endif
    }

    RObject::AttributeProxy::AttributeProxy( const RObject& v, const std::string& name) :
        parent(v), attr_name(name) {}

    RObject::AttributeProxy& RObject::AttributeProxy::operator=(const AttributeProxy& rhs){
        set( rhs.get() ) ;
        return *this ;
    }

    RObject::AttributeProxy RObject::attr( const std::string& name) const{
        return AttributeProxy( *this, name)  ;
    }

    /* S4 */

    bool RObject::hasSlot(const std::string& name) const {
        if( !Rf_isS4(m_sexp) ) throw not_s4() ;
        return R_has_slot( m_sexp, Rf_mkString(name.c_str()) ) ;
    }

    RObject::SlotProxy RObject::slot(const std::string& name) const {
        if( !Rf_isS4(m_sexp) ) throw not_s4() ;
        return SlotProxy( *this, name ) ;
    }
    // }}}
  
    // {{{ Function
    Function::Function(SEXP x) : RObject( ){
        switch( TYPEOF(x) ){
        case CLOSXP:
        case SPECIALSXP:
        case BUILTINSXP:
            setSEXP(x); 
            break; 
        default:
            throw not_compatible("cannot convert to function") ;
        }
    }
	
    Function::Function(const std::string& name) : RObject() {
        SEXP nameSym = Rf_install( name.c_str() );	// cannot be gc()'ed  once in symbol table
        SEXP x = PROTECT( Rf_findFun( nameSym, R_GlobalEnv ) ) ;
        setSEXP(x) ;
        UNPROTECT(1) ;
    }
	
    Function::Function(const Function& other) : RObject( other.asSexp() ){}
	
    Function& Function::operator=(const Function& other){
        setSEXP( other.asSexp() );
        return *this ;
    }
	
    Function::~Function(){}	
	
    SEXP Function::environment() const {
        if( TYPEOF(m_sexp) != CLOSXP ) {
            throw not_a_closure() ;
        }
        return CLOENV(m_sexp) ;
    }
	
    SEXP Function::body() const {
        return BODY( m_sexp ) ;
    }

    // }}}
    
    // {{{ DottedPair
        SEXP grow( SEXP head, SEXP tail ){
        SEXP x = PROTECT( head ) ;
	    SEXP res = PROTECT( Rf_cons( x, tail ) ) ;
	    UNPROTECT(2) ;
	    return res ;    
    }
    SEXP grow( const char* head, SEXP tail ) {
        return grow( Rf_mkString(head), tail ) ; 
    }
    
    
    DottedPair::~DottedPair(){}
    DottedPair::DottedPair() : RObject(){}
        
    DottedPair& DottedPair::operator=(const DottedPair& other){
        setSEXP( other.asSexp() ) ;
        return *this ;
    }
        
    void DottedPair::remove( const size_t& index ) {
        if( static_cast<R_len_t>(index) >= Rf_length(m_sexp) ) throw index_out_of_bounds() ;
        if( index == 0 ){
            setSEXP( CDR( m_sexp) ) ;
        } else{
            SEXP x = m_sexp ;
            size_t i=1;
            while( i<index ){ x = CDR(x) ; i++; }
            SETCDR( x, CDDR(x) ) ;
        }
    }
        
    DottedPair::Proxy::Proxy( DottedPair& v, const size_t& index_ ) : node(){
        if( static_cast<R_len_t>(index_) >= v.length() ) throw index_out_of_bounds() ;
        SEXP x = v ; /* implicit conversion */
        size_t i = 0 ;
        while( i<index_) {
            x = CDR(x) ;
            ++i ;
        }
        node = x ;
    }
     
    DottedPair::Proxy& DottedPair::Proxy::operator=(const Proxy& rhs){
        return set(rhs) ;
    }
        
    DottedPair::Proxy& DottedPair::Proxy::operator=(SEXP rhs){
        return set(rhs) ;
    }
        
    const DottedPair::Proxy DottedPair::operator[]( int i ) const {
        return Proxy( const_cast<DottedPair&>(*this), i) ;
    }
    DottedPair::Proxy DottedPair::operator[]( int i ) {
        return Proxy( *this, i );
    }
    // }}}
    
    // {{{ Promise
    Promise::Promise(SEXP x) : RObject(x){
        if( TYPEOF(x) != PROMSXP )
            throw not_compatible("not a promise") ;
    }

    Promise::Promise(const Promise& other) : RObject(other.asSexp()) {}
	
    Promise& Promise::operator=(const Promise& other){
        setSEXP( other.asSexp() );
        return *this ;
    }
	
    int Promise::seen() const {
        return PRSEEN(m_sexp);
    }

    SEXP Promise::value() const {
        SEXP val = PRVALUE(m_sexp) ; 
        if( val == R_UnboundValue ) throw unevaluated_promise() ;
        return val ;
    }
	
    bool Promise::was_evaluated() const {
        return PRVALUE(m_sexp) != R_UnboundValue ;
    }

    Environment Promise::environment() const {
        return Environment(PRENV(m_sexp)) ;
    }

    ExpressionVector Promise::expression() const {
        return ExpressionVector(PRCODE(m_sexp)) ;
    }

    // }}}
    
    // {{{ Pairlist
    Pairlist::Pairlist() : DottedPair() {}
    Pairlist::Pairlist( SEXP x ) : DottedPair( r_cast<LISTSXP>(x) ){}
    Pairlist::~Pairlist(){}
    Pairlist::Pairlist( const Pairlist& other): DottedPair(other.asSexp()){}
    Pairlist& Pairlist::operator=(const Pairlist& other){
        setSEXP( other.asSexp() ) ;
        return *this ;
    }
    // }}}
    
    // {{{ WeakReference
    WeakReference::WeakReference( SEXP x) : RObject(x){
        if( TYPEOF(x) != WEAKREFSXP )
            throw not_compatible( "not a weak reference" ) ;
    }
        
    SEXP WeakReference::key() {
        return R_WeakRefKey(m_sexp) ;
    }
        
    SEXP WeakReference::value() {
        return R_WeakRefValue(m_sexp);
    }
        
    WeakReference::WeakReference( const WeakReference& other ) : RObject( other.asSexp() ){}
        
    WeakReference& WeakReference::operator=(const WeakReference& other){
        setSEXP( other.asSexp() );
        return *this;
    }
    // }}}
    
    // {{{ Symbol
    Symbol::Symbol( SEXP x ) : RObject() {
        if( x != R_NilValue ){
            int type = TYPEOF(x) ;
            switch( type ){
            case SYMSXP:
                setSEXP( x ) ;
                break; /* nothing to do */
            case CHARSXP: {
                SEXP charSym = Rf_install(CHAR(x));     // cannot be gc()'ed  once in symbol table
                setSEXP( charSym ) ;
                break ;
            }
            case STRSXP: {
                /* FIXME: check that there is at least one element */
                SEXP charSym = Rf_install( CHAR(STRING_ELT(x, 0 )) ); // cannot be gc()'ed  once in symbol table
                setSEXP( charSym );
                break ;
            }
            default:
                throw not_compatible("cannot convert to symbol (SYMSXP)") ;
            }
        } 
    }
        
    Symbol::Symbol(const std::string& symbol): RObject( Rf_install(symbol.c_str()) ){}
        
    Symbol::Symbol( const Symbol& other) : RObject( other.asSexp() ) {}
        
    Symbol& Symbol::operator=(const Symbol& other){
        setSEXP( other.asSexp() );
        return *this;
    }
        
    Symbol::~Symbol(){}
    // }}}    
    
    // {{{ Language
    Language::Language() : DottedPair() {}
        
    Language::Language( SEXP x ) : DottedPair( x ){
        if( TYPEOF(x) != LANGSXP ){
            set_sexp( r_cast<LANGSXP>(x) ) ;  
        }
    }
        
    Language::Language( const Language& other): DottedPair( other.asSexp() ){}
        
    Language& Language::operator=(const Language& other){
        set_sexp( other.asSexp() ) ;
        return *this ;
    }
        
    Language::Language( const std::string& symbol ): DottedPair( Rf_lang1( Rf_install(symbol.c_str()) ) ) { 
       update_language_object() ; 
    }
        
    Language::Language( const Symbol& symbol ): DottedPair( Rf_lang1( symbol ) ) {
        update_language_object() ; 
    }
        
    Language::Language( const Function& function): DottedPair( Rf_lang1( function ) ) {
        update_language_object() ;
    }
        
    Language::~Language(){}

    void Language::setSymbol( const std::string& symbol){
        setSymbol( Symbol( symbol ) ) ;
    }
        
    void Language::setSymbol( const Symbol& symbol){
        SETCAR( m_sexp, symbol ) ;
        SET_TAG(m_sexp, R_NilValue);/* probably not necessary */
    }
        
    void Language::setFunction( const Function& function){
        SETCAR( m_sexp, function );
        SET_TAG(m_sexp, R_NilValue); /* probably not necessary */
    }
        
    void Language::update_language_object(){ 
        SET_TYPEOF( m_sexp, LANGSXP ) ;
        SET_TAG( m_sexp, R_NilValue ) ;
    }
    
    void Language::set_sexp(SEXP x){
        setSEXP(x) ;
        update_language_object() ;
    }
        
    SEXP Language::eval() {
        return eval( R_GlobalEnv ) ;
    }
        
    SEXP Language::eval( SEXP env ) {
        return internal::try_catch( m_sexp, env );
    }
    
    SEXP Language::fast_eval(){
        return Rf_eval( m_sexp, R_GlobalEnv ) ;    
    }
    SEXP Language::fast_eval(SEXP env ){
        return Rf_eval( m_sexp, env ) ;
    }
    // }}}
    
    // {{{ Dimension
    Dimension::Dimension() : dims(){}
        
    Dimension::Dimension(SEXP x): dims(){
        dims = as< std::vector<int> >(x) ;
    }
        
    Dimension::Dimension( const Dimension& other ) : dims(){
        dims = other.dims ; /* copy */
    }
        
    Dimension& Dimension::operator=(const Dimension& other){
        dims = other.dims ; /* copy */
        return *this ;
    }
        
    Dimension::Dimension(const size_t& n1) : dims(1){
        dims[0] = n1 ;
    }
        
    Dimension::Dimension(const size_t& n1, const size_t& n2) : dims(2){
        dims[0] = n1 ;
        dims[1] = n2 ;
    }
        
    Dimension::Dimension(const size_t& n1, const size_t& n2, const size_t& n3) : dims(3){
        dims[0] = n1 ;
        dims[1] = n2 ;
        dims[2] = n3 ;
    }
        
    Dimension::operator SEXP() const {
        return wrap( dims.begin(), dims.end() ) ;
    }
        
    int Dimension::size() const {
        return static_cast<int>( dims.size() ) ;
    }
        
    int Dimension::prod() const {
        return std::accumulate( dims.begin(), dims.end(), 1, std::multiplies<int>() ) ;
    }
        
    Dimension::reference Dimension::operator[](int i) {
        if( i < 0 || i>=static_cast<int>(dims.size()) ) throw std::range_error("index out of bounds") ;
        return dims.at(i) ;
    }

    Dimension::const_reference Dimension::operator[](int i) const {
        if( i < 0 || i>=static_cast<int>(dims.size()) ) throw std::range_error("index out of bounds") ;
        return dims.at(i) ;
    }    
    // }}}
    
    // {{{ Formula
    void Formula::set_sexp( SEXP x){
        setSEXP(x);
        Language::update_language_object() ;
    }
    Formula::Formula() : Language(){}
        
    Formula::Formula(SEXP x) : Language(){
        switch( TYPEOF( x ) ){
        case LANGSXP:
            if( ::Rf_inherits( x, "formula") ){
                set_sexp( x );
            } else{
                set_sexp( internal::convert_using_rfunction( x, "as.formula") ) ;
            }
            break;
        case EXPRSXP:
        case VECSXP:
            /* lists or expression, try the first one */
            if( ::Rf_length(x) > 0 ){
                SEXP y = VECTOR_ELT( x, 0 ) ;
                if( ::Rf_inherits( y, "formula" ) ){
                    set_sexp( y ) ;  
                } else{
                    SEXP z = internal::convert_using_rfunction( y, "as.formula") ;
                    set_sexp( z ) ;
                }
            } else{
                throw not_compatible( "cannot create formula from empty list or expression" ) ; 
            }
            break;
        default:
            set_sexp( internal::convert_using_rfunction( x, "as.formula") ) ;
        }
    }
        
    Formula::Formula( const std::string& code) : 
        Language( internal::convert_using_rfunction( ::Rf_mkString(code.c_str()), "as.formula") ) 
    {}
        
    Formula::Formula( const Formula& other ) : Language( other.asSexp() ){}
        
    Formula& Formula::operator=( const Formula& other ){
        setSEXP( other.asSexp() );
        return *this ;
    }
 
    // }}}
    
    // {{{ S4
    S4::S4() : RObject(){}
        
    S4::S4(SEXP x) : RObject(x){
        if( ! ::Rf_isS4(x) ) throw not_s4() ;
    }
        
    S4::S4( const S4& other) : RObject(other.asSexp()){}
        
    S4::S4( const RObject::SlotProxy& proxy ) : RObject() {
        set_sexp( proxy ) ;
    }
    S4::S4( const RObject::AttributeProxy& proxy ) : RObject() {
        set_sexp( proxy ) ;
    }
        
    S4& S4::operator=( const S4& other){
        set_sexp( other.asSexp() ) ;
        return *this ;
    }
        
    S4& S4::operator=( SEXP other ) {
        set_sexp( other ) ;
        return *this ;
    }
        
    S4::S4( const std::string& klass ) : RObject( R_do_new_object(R_do_MAKE_CLASS(klass.c_str())) ) {
        if (!Rf_inherits(m_sexp, klass.c_str()))
            throw S4_creation_error( klass ) ;
    }
        
    bool S4::is( const std::string& clazz ) {
        CharacterVector cl = attr("class");
                
        // simple test for exact match
        if( ! clazz.compare( cl[0] ) ) return true ;
                
        try{
            SEXP containsSym = ::Rf_install("contains");
            CharacterVector res(::Rf_getAttrib(
                                    ::R_do_slot(::R_getClassDef(CHAR(::Rf_asChar(as<SEXP>(cl)))),
                                                containsSym),
                                    R_NamesSymbol));

            // 
            // mimic the R call: 
            // names( slot( getClassDef( cl ), "contains" ) )
            // 
            // SEXP slotSym = Rf_install( "slot" ), // cannot cause gc() once in symbol table
            //     getClassDefSym = Rf_install( "getClassDef" );
            // CharacterVector res = internal::try_catch(Rf_lang2(R_NamesSymbol,
            //                                                    Rf_lang3(slotSym,
            //                                                             Rf_lang2( getClassDefSym, cl ), 
            //                                                             Rf_mkString( "contains" )))) ;
            return any( res.begin(), res.end(), clazz.c_str() ) ;
        } catch( ... ){
            // we catch eval_error and also not_compatible when 
            // contains is NULL
        }
        return false ;
                
    }
        
    void S4::set_sexp( SEXP x) {
        if( ! ::Rf_isS4(x) ){
            throw not_s4() ;
        } else{
            setSEXP( x) ;
        }
    }
    // }}}
    
    // {{{ Reference 
    Reference::Reference() : S4(){}
    
    Reference::Reference(SEXP x) : S4(x){
        check() ;
    }
    
    Reference::Reference( const Reference& other) : S4( other.asSexp() ){}
    
    Reference::Reference( const RObject::SlotProxy& proxy ) : S4() {
        set_sexp( proxy ) ;
    }
    Reference::Reference( const RObject::AttributeProxy& proxy ) : S4() {
        set_sexp( proxy ) ;
    }
    
    Reference& Reference::operator=( const Reference& other){
        set_sexp( other.asSexp() ) ;
        return *this ;
    }
    
    Reference& Reference::operator=( SEXP other ) {
        set_sexp( other ) ;
        return *this ;
    }
    
    Reference::Reference( const std::string& klass ) : S4(){
        // using callback to R as apparently R_do_new_object always makes the same environment
        SEXP newSym = Rf_install("new");
        SEXP call = PROTECT( Rf_lang2( newSym, Rf_mkString( klass.c_str() ) ) ) ;
        set_sexp( Rcpp::internal::try_catch( call ) ) ;
        UNPROTECT(1) ; // call
    }
    
    void Reference::set_sexp( SEXP x) {
        setSEXP( x) ;
        check();
    }
    void Reference::check( ) {
        // TODO: check that x is of a reference class
        if( ! ::Rf_isS4(m_sexp) ) throw not_reference() ;
    }
    
    
    Reference::FieldProxy::FieldProxy( Reference& v, const std::string& name) : 
        parent(v), field_name(name) {}

    Reference::FieldProxy& Reference::FieldProxy::operator=(const FieldProxy& rhs){
        set( rhs.get() ) ;
        return *this ;
    }
    
    
    SEXP Reference::FieldProxy::get() const {
        SEXP call = PROTECT( Rf_lang3( 
									  R_DollarSymbol, 
									  parent.asSexp(), 
									  Rf_mkString( field_name.c_str() )
									   ) ) ;
        UNPROTECT(1) ;
        return Rcpp::internal::try_catch( call ) ;
    }
    
    void Reference::FieldProxy::set( SEXP x) {
        PROTECT(x);
        SEXP dollarGetsSym = Rf_install( "$<-");
        SEXP name = PROTECT( Rf_mkString( field_name.c_str() ) ) ;
        SEXP call = PROTECT( Rf_lang4( 
									  dollarGetsSym,
									  parent.asSexp(), 
									  name , 
									  x
									   ) ) ;
        parent.set_sexp( Rf_eval( call, R_GlobalEnv ) ); 
        UNPROTECT(3) ;
    }

    Reference::FieldProxy Reference::field( const std::string& name) {
        return FieldProxy( *this, name );
    }
    
    Reference::ConstFieldProxy Reference::field( const std::string& name) const {
        return ConstFieldProxy( *this, name );
    }
    
    Reference::ConstFieldProxy::ConstFieldProxy( const Reference& v, const std::string& name) : 
        parent(v), field_name(name) {}

    SEXP Reference::ConstFieldProxy::get() const {
        SEXP call = PROTECT( Rf_lang3( 
									  R_DollarSymbol, 
									  const_cast<Reference&>(parent).asSexp(), 
									  Rf_mkString( field_name.c_str() )
									   ) ) ;
        return Rcpp::internal::try_catch( call ) ;
        UNPROTECT(1) ;
    }
    
    // }}}
 
    // {{{ Environment
    Environment::Environment() : RObject(R_GlobalEnv){}

    Environment::Environment(SEXP x) : RObject(x){
        if( ! Rf_isEnvironment(x) ) {
            /* not an environment, but maybe convertible to one using as.environment, try that */
            SEXP res ;
            try {
                SEXP asEnvironmentSym = Rf_install("as.environment"); // cannot be gc()'ed  once in symbol table
                res = Evaluator::run( Rf_lang2(asEnvironmentSym, x ) ) ;
            } catch( const eval_error& ex){
                throw not_compatible( "cannot convert to environment"  ) ; 
            }
            setSEXP( res ) ;
        }
    }

    Environment::Environment( const std::string& name) : RObject(R_EmptyEnv){
        /* similar to matchEnvir@envir.c */
        if( name == ".GlobalEnv" ) {
            setSEXP( R_GlobalEnv ) ;
        } else if( name == "package:base" ){
            setSEXP( R_BaseEnv ) ;
        } else{
            SEXP res = R_NilValue ;
            try{
                SEXP asEnvironmentSym = Rf_install("as.environment"); // cannot be gc()'ed  once in symbol table
                res = Evaluator::run(Rf_lang2( asEnvironmentSym, Rf_mkString(name.c_str()) ) ) ;
            } catch( const eval_error& ex){
                throw no_such_env(name) ;
            }
            setSEXP( res ) ;
        }
    }
    
    Environment::Environment(int pos) : RObject(R_GlobalEnv){
        SEXP res ;
        try{
            SEXP asEnvironmentSym = Rf_install("as.environment"); // cannot be gc()'ed  once in symbol table
            res =  Evaluator::run( Rf_lang2( asEnvironmentSym, Rf_ScalarInteger(pos) ) ) ;
        } catch( const eval_error& ex){
            throw no_such_env(pos) ;
        }
        setSEXP( res ) ;
    }
    
    Environment::Environment( const Environment& other ) : RObject( other.asSexp() ){}
    
    Environment& Environment::operator=(const Environment& other) {
        setSEXP( other.asSexp() ) ; 
        return *this ;
    }
    
    Environment::~Environment(){
        RCPP_DEBUG( "~Environment" )
    }
        
    SEXP Environment::ls( bool all = true) const {
        if( is_user_database() ){
            R_ObjectTable *tb = (R_ObjectTable*)
                R_ExternalPtrAddr(HASHTAB(m_sexp));
            return tb->objects(tb) ;
        } else{
            Rboolean get_all = all ? TRUE : FALSE ;
            return R_lsInternal( m_sexp, get_all ) ;
        }
        return R_NilValue ;
    }
    
    SEXP Environment::get( const std::string& name) const {
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        SEXP res = Rf_findVarInFrame( m_sexp, nameSym ) ;
        
        if( res == R_UnboundValue ) return R_NilValue ;
        
        /* We need to evaluate if it is a promise */
        if( TYPEOF(res) == PROMSXP){
            res = Rf_eval( res, m_sexp ) ;
        }
        return res ;
    }
    
    SEXP Environment::find( const std::string& name) const {
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        SEXP res = Rf_findVar( nameSym, m_sexp ) ;
        
        if( res == R_UnboundValue ) throw binding_not_found(name) ;
        
        /* We need to evaluate if it is a promise */
        if( TYPEOF(res) == PROMSXP){
            res = Rf_eval( res, m_sexp ) ;
        }
        return res ;
    }
    
    bool Environment::exists( const std::string& name) const{
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        SEXP res = Rf_findVarInFrame( m_sexp, nameSym  ) ;
        return res != R_UnboundValue ;
    }
    
    bool Environment::assign( const std::string& name, SEXP x = R_NilValue) const {
        if( exists( name) && bindingIsLocked(name) ) throw binding_is_locked(name) ;
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        Rf_defineVar( nameSym, x, m_sexp );
        return true ;
    }
    
    bool Environment::remove( const std::string& name) {
        if( exists(name) ){
            if( bindingIsLocked(name) ){
                throw binding_is_locked(name) ;
            } else{
                /* unless we want to copy all of do_remove, 
                   we have to go back to R to do this operation */
                SEXP internalSym = Rf_install( ".Internal" );
                SEXP removeSym = Rf_install( "remove" );
                SEXP call = PROTECT( Rf_lang2(internalSym, Rf_lang4(removeSym, Rf_mkString(name.c_str()), 
                                                                    m_sexp, Rf_ScalarLogical( FALSE ))) );
                Rf_eval( call, R_GlobalEnv ) ;
                UNPROTECT(1) ;
            }
        } else{
            throw no_such_binding(name) ;
        }
        return true; // to make g++ -Wall happy
    }
    
    bool Environment::isLocked() const{
        return R_EnvironmentIsLocked(m_sexp);
    }
    
    bool Environment::bindingIsActive(const std::string& name) const {
        if( !exists( name) ) throw no_such_binding(name) ;
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        return R_BindingIsActive(nameSym, m_sexp) ;
    }
    
    bool Environment::bindingIsLocked(const std::string& name) const {
        if( !exists( name) ) throw no_such_binding(name) ;
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        return R_BindingIsLocked(nameSym, m_sexp) ;
    }
    
    void Environment::lock( bool bindings = false ) {
        R_LockEnvironment( m_sexp, bindings ? TRUE: FALSE ) ;
    }
    
    void Environment::lockBinding(const std::string& name) {
        if( !exists( name) ) throw no_such_binding(name) ;
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        R_LockBinding( nameSym, m_sexp ); 
    }
    
    void Environment::unlockBinding(const std::string& name) {
        if( !exists( name) ) throw no_such_binding(name) ;
        SEXP nameSym = Rf_install(name.c_str());        // cannot be gc()'ed  once in symbol table
        R_unLockBinding( nameSym, m_sexp );
    }
    
    bool Environment::is_user_database() const {
        return OBJECT(m_sexp) && Rf_inherits(m_sexp, "UserDefinedDatabase") ;
    }
    
    /* static */
    
    Environment Environment::global_env() {
        return Environment(R_GlobalEnv) ;
    }
    
    Environment Environment::empty_env() {
        return Environment(R_EmptyEnv) ;
    }
    
    Environment Environment::base_env() {
        return Environment(R_BaseEnv) ;
    }
    
    Environment Environment::base_namespace() {
        return Environment(R_BaseNamespace) ;
    }
    
    Environment Environment::namespace_env(const std::string& package) {
        
        SEXP env = R_NilValue ;
        try{
            SEXP getNamespaceSym = Rf_install("getNamespace");
            env = Evaluator::run( Rf_lang2(getNamespaceSym, Rf_mkString(package.c_str()) ) ) ;
        } catch( const eval_error& ex){
            throw no_such_namespace( package  ) ; 
        }
        return Environment( env ) ;
    }
    
    Environment Environment::parent() const {
        return Environment( ENCLOS(m_sexp) ) ; 
    }
    
    Environment::Binding::Binding( Environment& env_, const std::string& name_): 
        env(env_), name(name_){}
    
    bool Environment::Binding::active() const{
        return env.bindingIsActive( name ) ; 
    }
    
    bool Environment::Binding::exists() const{
        return env.exists( name ) ; 
    }
    
    bool Environment::Binding::locked() const{
        return env.bindingIsLocked( name ) ; 
    }
    
    void Environment::Binding::lock() {
        env.lockBinding( name ) ;
    }
    
    void Environment::Binding::unlock() {
        env.unlockBinding( name ) ;
    }
    
    Environment::Binding& Environment::Binding::operator=( SEXP rhs ){
        env.assign( name, rhs ) ;
        return *this ;
    }
    
    Environment::Binding& Environment::Binding::operator=( const Binding& rhs){
        env.assign( name, rhs.env.get(rhs.name) ) ;
        return *this ;
    }

    const Environment::Binding Environment::operator[]( const std::string& name) const{
        return Binding( const_cast<Environment&>(*this), name );
    }
    
    Environment::Binding Environment::operator[]( const std::string& name) {
        return Binding( *this, name ) ;
    }
    
    Environment Environment::Rcpp_namespace() {
        return Rcpp::internal::get_Rcpp_namespace() ;
    }
    
    Environment Environment::new_child(bool hashed) {
        SEXP newEnvSym = Rf_install("new.env");
        return Environment( Evaluator::run(Rf_lang3( newEnvSym, Rf_ScalarLogical(hashed), m_sexp )) );
    }
    // }}}    
    
    // {{{ DataFrame
    namespace internal{
        inline SEXP empty_data_frame(){
            SEXP dataFrameSym = ::Rf_install( "data.frame"); // cannot be gc()ed once in symbol table
            return ::Rf_eval( ::Rf_lang1( dataFrameSym ), R_GlobalEnv ) ;       
        }
    }
    
    DataFrame::DataFrame(): List( internal::empty_data_frame() ){}
    DataFrame::DataFrame(SEXP x) : List(x){
        set_sexp(x) ;
    }  
    DataFrame::DataFrame( const DataFrame& other): List(other.asSexp()) {}
    DataFrame::DataFrame( const RObject::SlotProxy& proxy ) { set_sexp(proxy); }
    DataFrame::DataFrame( const RObject::AttributeProxy& proxy ) { set_sexp(proxy); }
              
    DataFrame& DataFrame::operator=( DataFrame& other) {
        set_sexp( other.asSexp() ) ;
        return *this ;
    }
            
    DataFrame& DataFrame::operator=( SEXP x) {
        set_sexp(x) ;
        return *this ;
    }
    DataFrame::~DataFrame(){}     
    void DataFrame::set_sexp(SEXP x) {
        if( ::Rf_inherits( x, "data.frame" )){
            setSEXP( x ) ;
        } else{
            SEXP y = internal::convert_using_rfunction( x, "as.data.frame" ) ;
            setSEXP( y ) ;
        }
        List::update_vector() ;
    } 
    int DataFrame::nrows() const { return Rf_length( VECTOR_ELT(m_sexp, 0) ); }
        
    DataFrame DataFrame::from_list( Rcpp::List obj ){
        bool use_default_strings_as_factors = true ;
        bool strings_as_factors = true ;
        int strings_as_factors_index = -1 ;
        int n = obj.size() ;
        CharacterVector names = obj.attr( "names" ) ;
        if( !names.isNULL() ){
            for( int i=0; i<n; i++){
                if( names[i] == "stringsAsFactors" ){
                    strings_as_factors_index = i ;
                    use_default_strings_as_factors = false ;        
                    if( !as<bool>(obj[i]) ) strings_as_factors = false ;
                    break ;         
                }
            }
        }
        if( use_default_strings_as_factors ) 
            return DataFrame(obj) ;
        SEXP as_df_symb = Rf_install("as.data.frame");
        SEXP strings_as_factors_symb = Rf_install("stringsAsFactors");
        
        obj.erase(strings_as_factors_index) ;
        names.erase(strings_as_factors_index) ;
        obj.attr( "names") = names ;
        SEXP call  = PROTECT( Rf_lang3(as_df_symb, obj, wrap( strings_as_factors ) ) ) ;
        SET_TAG( CDDR(call),  strings_as_factors_symb ) ;   
        SEXP res = PROTECT( Evaluator::run( call ) ) ; 
        DataFrame out( res ) ;
        UNPROTECT(2) ;
        return out ;
    }
    
    // }}}
    
} // namespace Rcpp
// }}}

// {{{ Rcomplex support
Rcomplex operator*( const Rcomplex& lhs, const Rcomplex& rhs){          
    Rcomplex y ;
    y.r = lhs.r * rhs.r - lhs.i * rhs.i ;
    y.i = lhs.r * rhs.i + rhs.r * lhs.i ;
    return y ;
}
Rcomplex operator+( const Rcomplex& lhs, const Rcomplex& rhs){
    Rcomplex y ;
    y.r = lhs.r + rhs.r ;
    y.i = lhs.i + rhs.i ;
    return y ;
}

Rcomplex operator-( const Rcomplex& lhs, const Rcomplex& rhs){
    Rcomplex y ;
    y.r = lhs.r - rhs.r ;
    y.i = lhs.i - rhs.i ;
    return y ;
}
   
Rcomplex operator/( const Rcomplex& a, const Rcomplex& b){

	Rcomplex c ;
    double ratio, den;
    double abr, abi;

    if( (abr = b.r) < 0)
	abr = - abr;
    if( (abi = b.i) < 0)
	abi = - abi;
    if( abr <= abi ) {
	ratio = b.r / b.i ;
	den = b.i * (1 + ratio*ratio);
	c.r = (a.r*ratio + a.i) / den;
	c.i = (a.i*ratio - a.r) / den;
    }
    else {
	ratio = b.i / b.r ;
	den = b.r * (1 + ratio*ratio);
	c.r = (a.r + a.i*ratio) / den;
	c.i = (a.i - a.r*ratio) / den;
    }
    return c ;
}
bool operator==( const Rcomplex& a, const Rcomplex& b){
    return a.r == b.r && a.i == b.i ;    
}
// }}}

// {{{ demangling
#ifdef RCPP_HAS_DEMANGLING
#include <cxxabi.h>

std::string demangle( const std::string& name ){
    std::string real_class ;
    int status =-1 ;
    char *dem = 0;
    dem = abi::__cxa_demangle(name.c_str(), 0, 0, &status);
    if( status == 0 ){
        real_class = dem ;
        free(dem);
    } else {
        real_class = name ;
    }
    return real_class ;
}
#else
std::string demangle( const std::string& name ){
	return name ;	
}
#endif
// }}}

// {{{ utilities (from RcppCommon.cpp)
SEXP rcpp_can_use_cxx0x(){ 
#ifdef HAS_VARIADIC_TEMPLATES
    return Rf_ScalarLogical( TRUE );
#else
    return Rf_ScalarLogical( FALSE );
#endif
}

SEXP rcpp_capabilities(){
	SEXP cap = PROTECT( Rf_allocVector( LGLSXP, 9) ) ;
	SEXP names = PROTECT( Rf_allocVector( STRSXP, 9 ) ) ;
#ifdef HAS_VARIADIC_TEMPLATES
	LOGICAL(cap)[0] = TRUE ;
#else
	LOGICAL(cap)[0] = FALSE ;
#endif
#ifdef HAS_CXX0X_INITIALIZER_LIST
	LOGICAL(cap)[1] = TRUE ;
#else
	LOGICAL(cap)[1] = FALSE ;
#endif
	/* exceptions are always supported */
	LOGICAL(cap)[2] = TRUE ;

#ifdef HAS_TR1_UNORDERED_MAP
	LOGICAL(cap)[3] = TRUE ;
#else
	LOGICAL(cap)[3] = FALSE ;
#endif

#ifdef HAS_TR1_UNORDERED_SET
	LOGICAL(cap)[4] = TRUE ;
#else
	LOGICAL(cap)[4] = FALSE ;
#endif

	LOGICAL(cap)[5] = TRUE ;

#ifdef RCPP_HAS_DEMANGLING
	LOGICAL(cap)[6] = TRUE ;
#else
	LOGICAL(cap)[6] = FALSE ;
#endif

	LOGICAL(cap)[7] = FALSE ;
	
#ifdef RCPP_HAS_LONG_LONG_TYPES
	LOGICAL(cap)[8] = TRUE ;
#else
    LOGICAL(cap)[8] = FALSE ;
#endif

	SET_STRING_ELT(names, 0, Rf_mkChar("variadic templates") ) ;
	SET_STRING_ELT(names, 1, Rf_mkChar("initializer lists") ) ;
	SET_STRING_ELT(names, 2, Rf_mkChar("exception handling") ) ;
	SET_STRING_ELT(names, 3, Rf_mkChar("tr1 unordered maps") ) ;
	SET_STRING_ELT(names, 4, Rf_mkChar("tr1 unordered sets") ) ;
	SET_STRING_ELT(names, 5, Rf_mkChar("Rcpp modules") ) ;
	SET_STRING_ELT(names, 6, Rf_mkChar("demangling") ) ;
	SET_STRING_ELT(names, 7, Rf_mkChar("classic api") ) ;
	SET_STRING_ELT(names, 8, Rf_mkChar("long long") ) ;
	Rf_setAttrib( cap, R_NamesSymbol, names ) ;
	UNPROTECT(2) ;
	return cap ;
}

const char * sexp_to_name(int sexp_type) {
    switch (sexp_type) {
    case NILSXP:	return "NILSXP";
    case SYMSXP:	return "SYMSXP";
    case RAWSXP:	return "RAWSXP";
    case LISTSXP:	return "LISTSXP";
    case CLOSXP:	return "CLOSXP";
    case ENVSXP:	return "ENVSXP";
    case PROMSXP:	return "PROMSXP";
    case LANGSXP:	return "LANGSXP";
    case SPECIALSXP:	return "SPECIALSXP";
    case BUILTINSXP:	return "BUILTINSXP";
    case CHARSXP:	return "CHARSXP";
    case LGLSXP:	return "LGLSXP";
    case INTSXP:	return "INTSXP";
    case REALSXP:	return "REALSXP";
    case CPLXSXP:	return "CPLXSXP";
    case STRSXP:	return "STRSXP";
    case DOTSXP:	return "DOTSXP";
    case ANYSXP:	return "ANYSXP";
    case VECSXP:	return "VECSXP";
    case EXPRSXP:	return "EXPRSXP";
    case BCODESXP:	return "BCODESXP";
    case EXTPTRSXP:	return "EXTPTRSXP";
    case WEAKREFSXP:	return "WEAKREFSXP";
    case S4SXP:		return "S4SXP";
    default:
	return "<unknown>";
    }
}

namespace Rcpp{
namespace internal{

	template<> int* r_vector_start<INTSXP>(SEXP x){ 
	    RCPP_DEBUG_1( "r_vector_start<INTSXP>( SEXP = %p )", x )
	    return INTEGER(x) ; 
	}
	template<> int* r_vector_start<LGLSXP>(SEXP x){ 
	    RCPP_DEBUG_1( "r_vector_start<LGLSXP>( SEXP = %p )", x )
	    return LOGICAL(x) ;
	}
	template<> double* r_vector_start<REALSXP>(SEXP x){ 
	    RCPP_DEBUG_1( "r_vector_start<REALSXP>( SEXP = %p )", x )
	    return REAL(x) ;
	}
	template<> Rbyte* r_vector_start<RAWSXP>(SEXP x){ 
	    RCPP_DEBUG_1( "r_vector_start<RAWSXP>( SEXP = %p )", x )
	    return RAW(x) ;
	}
	template<> Rcomplex* r_vector_start<CPLXSXP>(SEXP x){ 
	    RCPP_DEBUG_1( "r_vector_start<CPLXSXP>( SEXP = %p )", x )
	    return COMPLEX(x) ;
	}
	
	template<> void r_init_vector<VECSXP>(SEXP x){}
	template<> void r_init_vector<EXPRSXP>(SEXP x){}
	template<> void r_init_vector<STRSXP>(SEXP x){}

	template<> Rcomplex get_zero<CPLXSXP,Rcomplex>(){
		Rcomplex x ;
		x.r = 0.0 ;
		x.i = 0.0 ;
		return x ;
	}

	template<> Rcomplex caster<std::complex<double>, Rcomplex>( std::complex<double> from){
		Rcomplex cx ;
		cx.r = from.real() ; 
		cx.i = from.imag() ;
		return cx ;
	}
	template<> Rcomplex caster<std::complex<float>, Rcomplex>( std::complex<float> from){
		Rcomplex cx ;
		cx.r = static_cast<double>( from.real() ); 
		cx.i = static_cast<double>( from.imag() );
		return cx ;
	}

	template<> std::complex<double> caster<Rcomplex,std::complex<double> >( Rcomplex from){
		return std::complex<double>(from.r, from.i ) ;
	}
	template<> std::complex<float> caster<Rcomplex,std::complex<float> >( Rcomplex from){
		return std::complex<float>(static_cast<float>(from.r), static_cast<float>(from.i) ) ;
	}

	SEXP convert_using_rfunction(SEXP x, const char* const fun) {
        SEXP res = R_NilValue ;
        try{
            SEXP funSym = Rf_install(fun);
            res = Evaluator::run( Rf_lang2( funSym, x ) ) ;
        } catch( eval_error& e){
            throw ::Rcpp::not_compatible( std::string("could not convert using R function : ") + fun  ) ;
        }
        return res;
    }
    
    SEXP try_catch( SEXP expr, SEXP env ) {
        return Evaluator::run(expr, env) ;
    }
    SEXP try_catch( SEXP expr ) {
        return Evaluator::run(expr) ;
    }
    
    SEXP eval_methods<EXPRSXP>::eval(){
        SEXP xp = ( static_cast<ExpressionVector&>(*this) ).asSexp() ;
        SEXP evalSym = Rf_install( "eval" );
        return try_catch( Rf_lang2( evalSym, xp ) ) ;
    }
    
    SEXP eval_methods<EXPRSXP>::eval( SEXP env ){
        SEXP xp = ( static_cast<ExpressionVector&>(*this) ).asSexp() ;
        SEXP evalSym = Rf_install( "eval" );
        return try_catch( Rf_lang3( evalSym, xp, env ) ) ;
    }
	
} // internal
} // Rcpp

SEXP as_character_externalptr(SEXP xp){
	char buffer[20] ;
	sprintf( buffer, "%p", (void*)EXTPTR_PTR(xp) ) ;
	return Rcpp::wrap( (const char*)buffer ) ;
}

SEXP exception_to_try_error( const std::exception& ex ){
    return string_to_try_error(ex.what());
}

SEXP string_to_try_error( const std::string& str){

    using namespace Rcpp;
	
    // form simple error condition based on a string
    SEXP simpleErrorExpr = PROTECT(::Rf_lang2(::Rf_install("simpleError"), Rf_mkString(str.c_str())));
    SEXP simpleError = PROTECT(Rf_eval(simpleErrorExpr, R_GlobalEnv));
	
    SEXP tryError = PROTECT( Rf_mkString( str.c_str() ) ) ;
    Rf_setAttrib( tryError, R_ClassSymbol, Rf_mkString("try-error") ) ; 
    Rf_setAttrib( tryError, Rf_install( "condition") , simpleError ) ; 
    
    // unprotect and return
    UNPROTECT(3);
    return tryError;
}

const char* short_file_name(const char* file){
    std::string f(file) ;
    size_t index = f.find("/include/") ;
    if( index != std::string::npos ){ f = f.substr( index + 9 ) ;}
    return f.c_str() ;
}

#if defined(__GNUC__)
#if defined(WIN32) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__sun)
// Simpler version for Windows and *BSD 
SEXP stack_trace( const char* file, int line ){
    Rcpp::List trace = Rcpp::List::create( 
    	Rcpp::Named( "file"  ) = file, 
    	Rcpp::Named( "line"  ) = line, 
    	Rcpp::Named( "stack" ) = "C++ stack not available on this system" ) ;
    trace.attr("class") = "Rcpp_stack_trace" ;
    return trace ;
}
#else // ! (defined(WIN32) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__sun)
#include <execinfo.h>
#include <cxxabi.h>

static std::string demangler_one( const char* input){
    static std::string buffer ;
    buffer = input ;
    buffer.resize( buffer.find_last_of( '+' ) - 1 ) ;
    buffer.erase(
        buffer.begin(), 
        buffer.begin() + buffer.find_last_of( ' ' ) + 1
    ) ;
    return demangle( buffer) ;
}

/* inspired from http://tombarta.wordpress.com/2008/08/01/c-stack-traces-with-gcc/  */ 
SEXP stack_trace( const char *file, int line) {
    const size_t max_depth = 100;
    size_t stack_depth;
    void *stack_addrs[max_depth];
    char **stack_strings;

    stack_depth = backtrace(stack_addrs, max_depth);
    stack_strings = backtrace_symbols(stack_addrs, stack_depth);

    std::string current_line ;
    
    Rcpp::CharacterVector res( stack_depth - 1) ;
    std::transform( 
    	stack_strings + 1, stack_strings + stack_depth, 
    	res.begin(), 
    	demangler_one 
    	) ;
    free(stack_strings); // malloc()ed by backtrace_symbols
    
    Rcpp::List trace = Rcpp::List::create( 
    	Rcpp::Named( "file"  ) = file, 
    	Rcpp::Named( "line"  ) = line, 
    	Rcpp::Named( "stack" ) = res ) ;
    trace.attr("class") = "Rcpp_stack_trace" ;
    return trace ;
}
#endif 
#else /* !defined( __GNUC__ ) */
SEXP stack_trace( const char *file, int line) {
	return R_NilValue ;
}
#endif   
// }}}

// {{{ coercion

namespace Rcpp{ 
namespace internal{

template <> int r_coerce<INTSXP,INTSXP>(int from) { return from ; }
template <> int r_coerce<LGLSXP,LGLSXP>(int from) { return from ; }
template <> double r_coerce<REALSXP,REALSXP>(double from) { return from ; }
template <> Rcomplex r_coerce<CPLXSXP,CPLXSXP>(Rcomplex from) { return from ; }
template <> Rbyte r_coerce<RAWSXP,RAWSXP>(Rbyte from) { return from ; }

// -> INTSXP
template <> int r_coerce<LGLSXP,INTSXP>(int from){
	return (from==NA_LOGICAL) ? NA_INTEGER : from ;
}
template <> int r_coerce<REALSXP,INTSXP>(double from){
	if (ISNAN(from)) return NA_INTEGER;
	else if (from > INT_MAX || from <= INT_MIN ) {
		return NA_INTEGER;
	}
	return static_cast<int>(from);

}
template <> int r_coerce<CPLXSXP,INTSXP>(Rcomplex from){
	return r_coerce<REALSXP,INTSXP>(from.r) ;
}
template <> int r_coerce<RAWSXP,INTSXP>(Rbyte from){
	return static_cast<int>(from);
}

// -> REALSXP
template <> double r_coerce<LGLSXP,REALSXP>(int from){
	return from == NA_LOGICAL ? NA_REAL : static_cast<double>(from) ;
}
template <> double r_coerce<INTSXP,REALSXP>(int from){
	return from == NA_INTEGER ? NA_REAL : static_cast<double>(from) ; 
}
template <> double r_coerce<CPLXSXP,REALSXP>(Rcomplex from){
	return from.r ;
}
template <> double r_coerce<RAWSXP,REALSXP>(Rbyte from){
	return static_cast<double>(from) ;
}

// -> LGLSXP
template <> int r_coerce<REALSXP,LGLSXP>(double from){
	return ( from == NA_REAL ) ? NA_LOGICAL : (from!=0.0);
}
template <> int r_coerce<INTSXP,LGLSXP>(int from){
	return ( from == NA_INTEGER ) ? NA_LOGICAL : (from!=0);
}
template <> int r_coerce<CPLXSXP,LGLSXP>(Rcomplex from){
	if( from.r == NA_REAL ) return NA_LOGICAL ;
	if( from.r == 0.0 || from.i == 0.0 ) return FALSE ;
	return TRUE ;
}
template <> int r_coerce<RAWSXP,LGLSXP>(Rbyte from){
	if( from != static_cast<Rbyte>(0) ) return TRUE ;
	return FALSE ;
}

// -> RAWSXP
template <> Rbyte r_coerce<REALSXP,RAWSXP>(double from){
	if( from == NA_REAL) return static_cast<Rbyte>(0) ; 
	return r_coerce<INTSXP,RAWSXP>(static_cast<int>(from)) ;
}
template <> Rbyte r_coerce<INTSXP,RAWSXP>(int from){
	return (from < 0 || from > 255) ? static_cast<Rbyte>(0) : static_cast<Rbyte>(from) ;
}
template <> Rbyte r_coerce<CPLXSXP,RAWSXP>(Rcomplex from){
	return r_coerce<REALSXP,RAWSXP>(from.r) ;
}
template <> Rbyte r_coerce<LGLSXP,RAWSXP>(int from){
	return static_cast<Rbyte>(from == TRUE) ;
}

// -> CPLXSXP
template <> Rcomplex r_coerce<REALSXP,CPLXSXP>(double from){
	Rcomplex c ;
	if( from == NA_REAL ){
		c.r = NA_REAL; 
		c.i = NA_REAL;
	} else{
		c.r = from ;
		c.i = 0.0 ;
	}
	return c ;
}
template <> Rcomplex r_coerce<INTSXP,CPLXSXP>(int from){
	Rcomplex c ;
	if( from == NA_INTEGER ){
		c.r = NA_REAL; 
		c.i = NA_REAL;
	} else{
		c.r = static_cast<double>(from) ;
		c.i = 0.0 ;
	}
	return c ;
}
template <> Rcomplex r_coerce<RAWSXP,CPLXSXP>(Rbyte from){
	Rcomplex c ;
	c.r = static_cast<double>(from);
	c.i = 0.0 ;
	return c ;
}
template <> Rcomplex r_coerce<LGLSXP,CPLXSXP>(int from){
	Rcomplex c ;
	if( from == TRUE ){
		c.r = 1.0 ; c.i = 0.0 ;
	} else if( from == FALSE ){
		c.r = c.i = 0.0 ;
	} else { /* NA */
		c.r = c.i = NA_REAL;
	}
	return c ;
}

inline int integer_width( int n ){
    return n < 0 ? ( (int) ( ::log10( -n+0.5) + 2 ) ) : ( (int) ( ::log10( n+0.5) + 1 ) ) ;    
}

#define NB 1000
template <> const char* coerce_to_string<INTSXP>(int from){
    static char buffer[NB] ;
    snprintf( buffer, NB, "%*d", integer_width(from), from );
    return buffer ;
}
template <> const char* coerce_to_string<LGLSXP>(int from){
    return from == 0 ? "FALSE" : "TRUE" ;    
}
template <> const char* coerce_to_string<RAWSXP>(Rbyte from){
    static char buff[3];
    ::sprintf(buff, "%02x", from);
    return buff ;    
}

char* get_string_buffer(){
    static char buffer[MAXELTSIZE];
    return buffer ;    
}

static const char* dropTrailing0(char *s, char cdec) {
    /* Note that  's'  is modified */
    char *p = s;
    for (p = s; *p; p++) {
	if(*p == cdec) {
	    char *replace = p++;
	    while ('0' <= *p  &&  *p <= '9')
		if(*(p++) != '0')
		    replace = p;
	    if(replace != p)
		while((*(replace++) = *(p++)))
		    ;
	    break;
	}
    }
    return s;
}

template <> const char* coerce_to_string<REALSXP>(double x){
    //int w,d,e ;
    // cf src/main/format.c in R's sources:
    //   The return values are
    //     w : the required field width
    //     d : use %w.df in fixed format, %#w.de in scientific format
    //     e : use scientific format if != 0, value is number of exp digits - 1
    //
    //   nsmall specifies the minimum number of decimal digits in fixed format:
    //   it is 0 except when called from do_format.
    //Rf_formatReal( &x, 1, &w, &d, &e, 0 ) ;
    // we are no longer allowed to use this:
    //     char* tmp = const_cast<char*>( Rf_EncodeReal(x, w, d, e, '.') );
    // so approximate it poorly as
    static char tmp[128];
    snprintf(tmp, 127, "%f", x); 
    return dropTrailing0(tmp, '.');
}

template <> const char* coerce_to_string<CPLXSXP>(Rcomplex x){
    //int wr, dr, er, wi, di, ei;
    //Rf_formatComplex(&x, 1, &wr, &dr, &er, &wi, &di, &ei, 0);
    // we are no longer allowed to use this:
    //     Rf_EncodeComplex(x, wr, dr, er, wi, di, ei, '.' );
    // so approximate it poorly as
    static char tmp1[128], tmp2[128], tmp3[256];
    //snprintf(tmp, 127, "%*.*f+%*.*fi", wr, dr, x.r, wi, di, x.i);
    //snprintf(tmp, 127, "%f+%fi", x.r, x.i); // FIXEM: barebones default formatting
    snprintf(tmp1, 127, "%f", x.r); 
    snprintf(tmp2, 127, "%f", x.i); 
    snprintf(tmp3, 255, "%s+%si", dropTrailing0(tmp1, '.'), dropTrailing0(tmp2, '.'));
    return tmp3;
}

} // internal
} // Rcpp

// }}}

// {{{ r_cast support
namespace Rcpp{
    namespace internal{
        
        template<> SEXP r_true_cast<INTSXP>(SEXP x) {
            switch( TYPEOF(x) ){
            case REALSXP:
            case RAWSXP:
            case LGLSXP:
            case CPLXSXP:
                return Rf_coerceVector( x, INTSXP) ;
            default:
                throw ::Rcpp::not_compatible( "not compatible with INTSXP" ) ;
            }
            return R_NilValue ; /* -Wall */
        }

        template<> SEXP r_true_cast<REALSXP>( SEXP x) {
            switch( TYPEOF( x ) ){
            case INTSXP:
            case LGLSXP:
            case CPLXSXP:
            case RAWSXP:
                return Rf_coerceVector( x, REALSXP );
            default:
                throw ::Rcpp::not_compatible( "not compatible with REALSXP" ) ;
            }
            return R_NilValue ; /* -Wall */
        }

        template<> SEXP r_true_cast<LGLSXP>( SEXP x) {
            switch( TYPEOF( x ) ){
            case REALSXP:
            case INTSXP:
            case CPLXSXP:
            case RAWSXP:
                return Rf_coerceVector( x, LGLSXP );
            default:
                throw ::Rcpp::not_compatible( "not compatible with LGLSXP" ) ;
            }
            return R_NilValue ; /* -Wall */
        }

        template<> SEXP r_true_cast<RAWSXP>( SEXP x) {
            switch( TYPEOF( x ) ){
            case LGLSXP:
            case REALSXP:
            case INTSXP:
            case CPLXSXP:
                return Rf_coerceVector( x, RAWSXP );
            default:
                throw ::Rcpp::not_compatible( "not compatible with RAWSXP" ) ;
            }
            return R_NilValue ; /* -Wall */
        }


        template<> SEXP r_true_cast<CPLXSXP>( SEXP x) {
            switch( TYPEOF( x ) ){
            case RAWSXP:
            case LGLSXP:
            case REALSXP:
            case INTSXP:
                return Rf_coerceVector( x, CPLXSXP );
            default:
                throw ::Rcpp::not_compatible( "not compatible with CPLXSXP" ) ;
            }
            return R_NilValue ; /* -Wall */
        }

        template<> SEXP r_true_cast<STRSXP>( SEXP x) {
            switch( TYPEOF( x ) ){
            case CPLXSXP:
            case RAWSXP:
            case LGLSXP:
            case REALSXP:
            case INTSXP:
                {
                    // return Rf_coerceVector( x, STRSXP );
                    // coerceVector does not work for some reason
                    SEXP call = PROTECT( Rf_lang2( Rf_install( "as.character" ), x ) ) ;
                    SEXP res  = PROTECT( Rf_eval( call, R_GlobalEnv ) ) ;
                    UNPROTECT(2); 
                    return res ;
                }
            case CHARSXP:
                return Rf_ScalarString( x ) ;
            case SYMSXP:
                return Rf_ScalarString( PRINTNAME( x ) ) ; 
            default:
                throw ::Rcpp::not_compatible( "not compatible with STRSXP" ) ;
            }
            return R_NilValue ; /* -Wall */
        }

        template<> SEXP r_true_cast<VECSXP>(SEXP x) {
            return convert_using_rfunction(x, "as.list" ) ;
        }
    
        template<> SEXP r_true_cast<EXPRSXP>(SEXP x) {
            return convert_using_rfunction(x, "as.expression" ) ;
        }

        template<> SEXP r_true_cast<LISTSXP>(SEXP x) {
            switch( TYPEOF(x) ){
            case LANGSXP:
                {
                    SEXP y = R_NilValue ;
                    PROTECT(y = Rf_duplicate( x )); 
                    SET_TYPEOF(y,LISTSXP) ;
                    UNPROTECT(1);
                    return y ;
                }
            default:
                return convert_using_rfunction(x, "as.pairlist" ) ;
            }
        
        }

        template<> SEXP r_true_cast<LANGSXP>(SEXP x) {
            return convert_using_rfunction(x, "as.call" ) ;
        }
    }
}
// }}}

// {{{ random number generators
// these files are no longer part of Rcpp.h since they are only needed here
#include <Rcpp/stats/random/rnorm.h>
#include <Rcpp/stats/random/runif.h>
#include <Rcpp/stats/random/rgamma.h>
#include <Rcpp/stats/random/rbeta.h>
#include <Rcpp/stats/random/rlnorm.h>
#include <Rcpp/stats/random/rchisq.h>
#include <Rcpp/stats/random/rnchisq.h>
#include <Rcpp/stats/random/rf.h>
#include <Rcpp/stats/random/rt.h>
#include <Rcpp/stats/random/rbinom.h>
#include <Rcpp/stats/random/rcauchy.h>
#include <Rcpp/stats/random/rexp.h>
#include <Rcpp/stats/random/rgeom.h>
#include <Rcpp/stats/random/rnbinom.h>
#include <Rcpp/stats/random/rnbinom_mu.h>
#include <Rcpp/stats/random/rpois.h>
#include <Rcpp/stats/random/rweibull.h>
#include <Rcpp/stats/random/rlogis.h>
#include <Rcpp/stats/random/rwilcox.h>
#include <Rcpp/stats/random/rsignrank.h>
#include <Rcpp/stats/random/rhyper.h>

namespace Rcpp{
    namespace internal{
        namespace {
            unsigned long RNGScopeCounter = 0;
        }
        
        void enterRNGScope() {       
            if (RNGScopeCounter == 0)
                GetRNGstate();       
            RNGScopeCounter++;
        }
        
        void exitRNGScope() {
            RNGScopeCounter--;
            if (RNGScopeCounter == 0)
                PutRNGstate();
        }
    } // internal
	 
	
	NumericVector rnorm( int n, double mean, double sd){
		if (ISNAN(mean) || !R_FINITE(sd) || sd < 0.){
			// TODO: R also throws a warning in that case, should we ?
			return NumericVector( n, R_NaN ) ;
		}  else if (sd == 0. || !R_FINITE(mean)){
			return NumericVector( n, mean ) ;
		} else {
			bool sd1 = sd == 1.0 ; 
			bool mean0 = mean == 0.0 ;
			if( sd1 && mean0 ){
				return NumericVector( n, stats::NormGenerator__mean0__sd1() ) ;
			} else if( sd1 ){
				return NumericVector( n, stats::NormGenerator__sd1( mean ) );
			} else if( mean0 ){
				return NumericVector( n, stats::NormGenerator__mean0( sd ) );
			} else {
				// general case
				return NumericVector( n, stats::NormGenerator( mean, sd ) );
			}
		}
	}

	
	 
	
	NumericVector rnorm( int n, double mean /*, double sd [=1.0] */ ){
		if (ISNAN(mean) ){
			// TODO: R also throws a warning in that case, should we ?
			return NumericVector( n, R_NaN ) ;
		}  else if ( !R_FINITE(mean)){
			return NumericVector( n, mean ) ;
		} else {
			bool mean0 = mean == 0.0 ;
			if( mean0 ){
				return NumericVector( n, stats::NormGenerator__mean0__sd1() ) ;
			} else {
				return NumericVector( n, stats::NormGenerator__sd1( mean ) );
			}
		}
	}

	
	 
	
	NumericVector rnorm( int n /*, double mean [=0.0], double sd [=1.0] */ ){
		return NumericVector( n, stats::NormGenerator() ) ;
	}

	
	 
	
	NumericVector rbeta( int n, double a, double b ){
		return NumericVector( n, stats::BetaGenerator(a, b ) ) ;
	}

    
	 
	
	NumericVector rbinom( int n, double nin, double pp ){
		return NumericVector( n, stats::BinomGenerator(nin, pp) ) ;
	}
	
	
     
    
    NumericVector rcauchy( int n, double location, double scale ){
    	if (ISNAN(location) || !R_FINITE(scale) || scale < 0)
    		return NumericVector( n, R_NaN ) ;
    	
        if (scale == 0. || !R_FINITE(location))
        	return NumericVector( n, location ) ;
        
    	return NumericVector( n, stats::CauchyGenerator( location, scale ) ) ;
    }
    
    
     
    
    NumericVector rcauchy( int n, double location /* , double scale [=1.0] */ ){
    	if (ISNAN(location))
    		return NumericVector( n, R_NaN ) ;
    	
        if (!R_FINITE(location))
        	return NumericVector( n, location ) ;
        
    	return NumericVector( n, stats::CauchyGenerator_1( location ) ) ;
    }
    
    
     
    
    NumericVector rcauchy( int n /*, double location [=0.0] , double scale [=1.0] */ ){
    	return NumericVector( n, stats::CauchyGenerator_0() ) ;
    }
       
    
	 
	
	NumericVector rchisq( int n, double df ){
		if (!R_FINITE(df) || df < 0.0) return NumericVector(n, R_NaN) ;
		return NumericVector( n, stats::ChisqGenerator( df ) ) ;
	}
 
	
	 
	
	NumericVector rexp( int n, double rate ){
		double scale = 1.0 / rate ;
		if (!R_FINITE(scale) || scale <= 0.0) {
			if(scale == 0.) return NumericVector( n, 0.0 ) ;
			/* else */
			return NumericVector( n, R_NaN ) ;
		}
		return NumericVector( n, stats::ExpGenerator( scale ) ) ;
	}
	NumericVector rexp( int n /* , rate = 1 */ ){
		return NumericVector( n, stats::ExpGenerator__rate1() ) ;
	}


	
	 
	
	NumericVector rf( int n, double n1, double n2 ){
		if (ISNAN(n1) || ISNAN(n2) || n1 <= 0. || n2 <= 0.)
			return NumericVector( n, R_NaN ) ;
		if( R_FINITE( n1 ) && R_FINITE( n2 ) ){
			return NumericVector( n, stats::FGenerator_Finite_Finite( n1, n2 ) ) ;
		} else if( ! R_FINITE( n1 ) && ! R_FINITE( n2 ) ){
			return NumericVector( n, 1.0 ) ;
		} else if( ! R_FINITE( n1 ) ) {
			return NumericVector( n, stats::FGenerator_NotFinite_Finite( n2 ) ) ;
		} else {
			return NumericVector( n, stats::FGenerator_Finite_NotFinite( n1 ) ) ;	
		}
	}
	
	 
	
	 
	
	NumericVector rgamma( int n, double a, double scale ){
		if (!R_FINITE(a) || !R_FINITE(scale) || a < 0.0 || scale <= 0.0) {
			if(scale == 0.) return NumericVector( n, 0.) ;
			return NumericVector( n, R_NaN ) ;
		}
		if( a == 0. ) return NumericVector(n, 0. ) ;
		return NumericVector( n, stats::GammaGenerator(a, scale) ) ;
	} 
	NumericVector rgamma( int n, double a /* scale = 1.0 */ ){
		if (!R_FINITE(a) || a < 0.0 ) {
			return NumericVector( n, R_NaN ) ;
		}
		if( a == 0. ) return NumericVector(n, 0. ) ;
		/* TODO: check if we can take advantage of the scale = 1 special case */
		return NumericVector( n, stats::GammaGenerator(a, 1.0) ) ;
	} 

	
	 
	
	NumericVector rgeom( int n, double p ){
		if (!R_FINITE(p) || p <= 0 || p > 1) 
			return NumericVector( n, R_NaN );
		return NumericVector( n, stats::GeomGenerator( p ) ) ;
	}

	
	 
	
	NumericVector rhyper( int n, double nn1, double nn2, double kk ){
		return NumericVector( n, stats::HyperGenerator( nn1, nn2, kk ) ) ;
	}

	
	 
	
	NumericVector rlnorm( int n, double meanlog, double sdlog ){
		if (ISNAN(meanlog) || !R_FINITE(sdlog) || sdlog < 0.){
			// TODO: R also throws a warning in that case, should we ?
			return NumericVector( n, R_NaN ) ;
		}  else if (sdlog == 0. || !R_FINITE(meanlog)){
			return NumericVector( n, ::exp( meanlog ) ) ;
		} else {
			return NumericVector( n, stats::LNormGenerator( meanlog, sdlog ) ); 
		}
	}

	
	 
	
	NumericVector rlnorm( int n, double meanlog /*, double sdlog = 1.0 */){
		if (ISNAN(meanlog) ){
			// TODO: R also throws a warning in that case, should we ?
			return NumericVector( n, R_NaN ) ;
		}  else if ( !R_FINITE(meanlog)){
			return NumericVector( n, ::exp( meanlog ) ) ;
		} else {
			return NumericVector( n, stats::LNormGenerator_1( meanlog ) ); 
		}
	}

	
	 
	
	NumericVector rlnorm( int n /*, double meanlog [=0.], double sdlog = 1.0 */){
		return NumericVector( n, stats::LNormGenerator_0( ) ); 
	}

	
	 
	
	NumericVector rlogis( int n, double location, double scale ){
		if (ISNAN(location) || !R_FINITE(scale))
			return NumericVector( n, R_NaN ) ;

		if (scale == 0. || !R_FINITE(location))
			return NumericVector( n, location );
    
		return NumericVector( n, stats::LogisGenerator( location, scale ) ) ;
	}

	
	 
	
	NumericVector rlogis( int n, double location /*, double scale =1.0 */ ){
		if (ISNAN(location) )
			return NumericVector( n, R_NaN ) ;

		if (!R_FINITE(location))
			return NumericVector( n, location );
    
		return NumericVector( n, stats::LogisGenerator_1( location ) ) ;
	}

	
	 
	
	NumericVector rlogis( int n /*, double location [=0.0], double scale =1.0 */ ){
		return NumericVector( n, stats::LogisGenerator_0() ) ;
	}

	
	 
	
	NumericVector rnbinom( int n, double siz, double prob ){
		if(!R_FINITE(siz) || !R_FINITE(prob) || siz <= 0 || prob <= 0 || prob > 1)
			/* prob = 1 is ok, PR#1218 */
			return NumericVector( n, R_NaN ) ;
    
		return NumericVector( n, stats::NBinomGenerator( siz, prob ) ) ;
	}

	
	 
	
	NumericVector rnbinom_mu( int n, double siz, double mu ){
		if(!R_FINITE(siz) || !R_FINITE(mu) || siz <= 0 || mu < 0)
			return NumericVector( n, R_NaN ) ;
    
		return NumericVector( n, stats::NBinomGenerator_Mu( siz, mu ) ) ;
	}

	
	 
	
	NumericVector rnchisq( int n, double df, double lambda ){
		if (!R_FINITE(df) || !R_FINITE(lambda) || df < 0. || lambda < 0.) 
			return NumericVector(n, R_NaN) ;
		if( lambda == 0.0 ){
			// using the central generator, see rchisq.h
			return NumericVector( n, stats::ChisqGenerator( df ) ) ;
		}
		return NumericVector( n, stats::NChisqGenerator( df, lambda ) ) ;
	}

	
	 
	
	NumericVector rnchisq( int n, double df /*, double lambda = 0.0 */ ){
		if (!R_FINITE(df) || df < 0. ) 
			return NumericVector(n, R_NaN) ;
		return NumericVector( n, stats::ChisqGenerator( df ) ) ;
	}

	
	 
	
	NumericVector rpois( int n, double mu ){
		return NumericVector( n, stats::PoissonGenerator(mu) ) ;
	}

    
	
	 
	
	NumericVector rsignrank( int n, double nn ){
		return NumericVector( n, stats::SignRankGenerator(nn) ) ;
	}

	
	 
	
	NumericVector rt( int n, double df ){
		// special case
		if (ISNAN(df) || df <= 0.0)
			return NumericVector( n, R_NaN ) ;
	
		// just generating a N(0,1)
		if(!R_FINITE(df))
			return NumericVector( n, stats::NormGenerator__mean0__sd1() ) ;
	
		// general case
		return NumericVector( n, stats::TGenerator( df ) ) ;
	}
	 
	
	 
	
	NumericVector runif( int n, double min, double max ){
		if (!R_FINITE(min) || !R_FINITE(max) || max < min) return NumericVector( n, R_NaN ) ;
		if( min == max ) return NumericVector( n, min ) ;
		return NumericVector( n, stats::UnifGenerator( min, max ) ) ;
	}

	
	 
	
	NumericVector runif( int n, double min /*, double max = 1.0 */ ){
		if (!R_FINITE(min) || 1.0 < min) return NumericVector( n, R_NaN ) ;
		if( min == 1.0 ) return NumericVector( n, 1.0 ) ;
		return NumericVector( n, stats::UnifGenerator( min, 1.0 ) ) ;
	}

	
	 
	
	NumericVector runif( int n /*, double min = 0.0, double max = 1.0 */ ){
		return NumericVector( n, stats::UnifGenerator__0__1() ) ;
	}
 
	
	 
	
	NumericVector rweibull( int n, double shape, double scale ){
		if (!R_FINITE(shape) || !R_FINITE(scale) || shape <= 0. || scale <= 0.) {
			if(scale == 0.) return NumericVector(n, 0.);
			/* else */
			return NumericVector(n, R_NaN);
		}
		return NumericVector( n, stats::WeibullGenerator( shape, scale ) ) ;
	}

	NumericVector rweibull( int n, double shape /* scale = 1 */ ){
		if (!R_FINITE(shape) || shape <= 0. ) {
			return NumericVector(n, R_NaN);
		}
		return NumericVector( n, stats::WeibullGenerator__scale1( shape ) ) ;
	}

	
	 
	
	NumericVector rwilcox( int n, double mm, double nn ){
		return NumericVector( n, stats::WilcoxGenerator(mm, nn) ) ;
	}
}
// }}}


