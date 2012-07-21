// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module.h: Rcpp R/C++ interface class library -- Rcpp modules
//
// Copyright (C) 2010 - 2011 Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Module_h
#define Rcpp_Module_h
   
#include <Rcpp/config.h>

namespace Rcpp{

    class CppClass ;
    class CppObject ;

    template <typename T>
    class result {
    public:
        result( T* ptr_ ) : ptr(ptr_){}
        operator T*(){ return ptr ; }
    private:
        T* ptr;
    } ;

    namespace internal {
        template <typename Class>
        SEXP make_new_object( Class* ptr ){
            Rcpp::XPtr<Class> xp( ptr, true ) ;
            Function maker = Environment::Rcpp_namespace()[ "cpp_object_maker"] ;
            return maker( typeid(Class).name() , xp ) ;
        }
    } 

    class CppFunction {
    public:
        CppFunction(const char* doc = 0) : docstring( doc == 0 ? "" : doc) {}
        virtual SEXP operator()(SEXP*) { 
            return R_NilValue ;
        }
        virtual ~CppFunction(){} ;
        virtual int nargs(){ return 0 ; }
        virtual bool is_void(){ return false ; }
        virtual void signature(std::string&, const char* ){}
        virtual SEXP get_formals(){ return R_NilValue; }
                
        std::string docstring ;
    };

#include <Rcpp/module/Module_generated_get_return_type.h>
#include <Rcpp/module/Module_generated_get_signature.h>

    // templates CppFunction0, ..., CppFunction65
#include <Rcpp/module/Module_generated_CppFunction.h>

    class class_Base {
    public:
        class_Base() : name(), docstring() {} ;
        class_Base(const char* name_, const char* doc) : 
            name(name_), docstring( doc == 0 ? "" : doc ){} ;
        
        virtual Rcpp::List fields(SEXP){ return Rcpp::List(0); }
        virtual Rcpp::List getMethods(SEXP, std::string&){ return Rcpp::List(0); }
        virtual Rcpp::List getConstructors(SEXP, std::string&){ return Rcpp::List(0); }
        
        virtual void run_finalizer(SEXP){ }
        
        virtual bool has_default_constructor(){ return false ; }
        virtual bool has_method( const std::string& ){ 
            return false ; 
        }
        virtual bool has_property( const std::string& ) { 
            return false ;
        }
        virtual SEXP newInstance(SEXP *, int){ 
            return R_NilValue;
        }
        virtual SEXP invoke( SEXP, SEXP, SEXP *, int ){ 
            return R_NilValue ;
        }
        virtual SEXP invoke_void( SEXP, SEXP, SEXP *, int ){ 
            return R_NilValue ;
        }
        virtual SEXP invoke_notvoid( SEXP, SEXP, SEXP *, int ){ 
            return R_NilValue ;
        }
        
        virtual Rcpp::CharacterVector method_names(){ return Rcpp::CharacterVector(0) ; }
        virtual Rcpp::CharacterVector property_names(){ return Rcpp::CharacterVector(0) ; }
        virtual bool property_is_readonly(const std::string& ) { return false ; }
        virtual std::string property_class(const std::string& ) { return "" ; }
        virtual Rcpp::IntegerVector methods_arity(){ return Rcpp::IntegerVector(0) ; }
        virtual Rcpp::LogicalVector methods_voidness(){ return Rcpp::LogicalVector(0); }
        virtual Rcpp::List property_classes(){ return Rcpp::List(0); }
        
        virtual Rcpp::CharacterVector complete(){ return Rcpp::CharacterVector(0) ; }
        virtual ~class_Base(){}
        
        virtual SEXP getProperty( SEXP, SEXP ) {
            throw std::range_error( "cannot retrieve property" ) ;
        }
        virtual void setProperty( SEXP, SEXP, SEXP) {
            throw std::range_error( "cannot set property" ) ;
        }
        virtual std::string get_typeinfo_name(){ return "" ; }
        
        std::string name ;
        std::string docstring ;
    } ;

    class Module {
    public:    
        typedef std::map<std::string,CppFunction*> MAP ;
        typedef std::pair<const std::string,CppFunction*> FUNCTION_PAIR ;
                
        typedef std::map<std::string,class_Base*> CLASS_MAP ;
        typedef std::pair<const std::string,class_Base*> CLASS_PAIR ;
        
        Module()  ;
        Module(const char* name_)  ;
                      
        SEXP invoke( const std::string& /* name */,  SEXP* /* args */, int /* nargs */ ) ;                        
                
        Rcpp::IntegerVector functions_arity() ;
        Rcpp::CharacterVector functions_names() ;
                
        Rcpp::CharacterVector class_names() ;
        Rcpp::List classes_info() ;
        Rcpp::CharacterVector complete() ;
        SEXP get_function_ptr( const std::string& ) ;
                
        inline void Add( const char* name_ , CppFunction* ptr){
            functions.insert( FUNCTION_PAIR( name_ , ptr ) ) ;
        }
                
        inline void AddClass(const char* name_ , class_Base* cptr){
            classes.insert( CLASS_PAIR( name_ , cptr ) ) ;
        }

        inline bool has_function( const std::string& m){
            return functions.find(m) != functions.end() ;
        }
                
        inline bool has_class( const std::string& m){
            return classes.find(m) != classes.end() ;
        }
                
        Rcpp::CppClass get_class(const std::string& ) ;
                
        std::string name ;
                
    private:
        MAP functions ;
        CLASS_MAP classes ;
                           
    };

}
extern "C" Rcpp::Module* getCurrentScope() ;
extern "C" void setCurrentScope( Rcpp::Module* ) ;

namespace Rcpp{
        
    template <typename Class>
    class CppMethod {
    public:
        typedef Rcpp::XPtr<Class> XP ;   
        
        CppMethod() {}
        virtual SEXP operator()(Class* object, SEXP* args) { return R_NilValue ; }
        virtual ~CppMethod(){}
        virtual int nargs(){ return 0 ; }
        virtual bool is_void(){ return false ; }
        virtual bool is_const(){ return false ; }
        virtual void signature(std::string& s, const char* name ){ s = name ; }
    } ;

#include <Rcpp/module/Module_generated_ctor_signature.h>
#include <Rcpp/module/Module_generated_Constructor.h>
#include <Rcpp/module/Module_generated_class_signature.h>

    typedef bool (*ValidConstructor)(SEXP*,int) ;
    typedef bool (*ValidMethod)(SEXP*,int) ;

    template <typename Class>
    class SignedConstructor {
    public:
    
        SignedConstructor( 
                          Constructor_Base<Class>* ctor_, 
                          ValidConstructor valid_, 
                          const char* doc
                           ) : ctor(ctor_), valid(valid_), docstring(doc == 0 ? "" : doc){}
    
        Constructor_Base<Class>* ctor ;
        ValidConstructor valid ;
        std::string docstring ;
    
        inline int nargs(){ return ctor->nargs() ; }
        inline void signature(std::string& buffer, const std::string& class_name){ 
            ctor->signature(buffer, class_name) ;
        }
    } ;

    template <typename Class>
    class SignedMethod {
    public:
        typedef CppMethod<Class> METHOD ;
        SignedMethod( METHOD* m, ValidMethod valid_, const char* doc ) : method(m), valid(valid_), docstring(doc == 0 ? "" : doc) {}
    
        METHOD* method ;
        ValidMethod valid ;
        std::string docstring ;
    
        inline int nargs(){ return method->nargs() ; }
        inline bool is_void(){ return method->is_void() ; }
        inline bool is_const(){ return method->is_const() ; }
        inline void signature(std::string& s, const char* name){ 
            method->signature(s, name);
        }

    } ;

    template <typename Class>
    class S4_CppConstructor : public Rcpp::Reference {
    public:             
        S4_CppConstructor( SignedConstructor<Class>* m, SEXP class_xp, const std::string& class_name, std::string& buffer ) : Reference( "C++Constructor" ){
            field( "pointer" )       = Rcpp::XPtr< SignedConstructor<Class> >( m, false ) ;
            field( "class_pointer" ) = class_xp ;
            field( "nargs" )         = m->nargs() ;
            m->signature( buffer, class_name ) ;
            field( "signature" )     = buffer ;
            field( "docstring" )     = m->docstring ;
        }
    } ;

    template <typename Class>
    class S4_CppOverloadedMethods : public Rcpp::Reference {
    public:    
        typedef SignedMethod<Class> signed_method_class ;
        typedef std::vector<signed_method_class*> vec_signed_method ;
        
        S4_CppOverloadedMethods( vec_signed_method* m, SEXP class_xp, const char* name, std::string& buffer ) : Reference( "C++OverloadedMethods" ){
            int n = m->size() ;
            Rcpp::LogicalVector voidness(n), constness(n) ;
            Rcpp::CharacterVector docstrings(n), signatures(n) ;
            signed_method_class* met ;
            for( int i=0; i<n; i++){ 
                met = m->at(i) ;
                voidness[i] = met->is_void() ;
                constness[i] = met->is_const() ;
                docstrings[i] = met->docstring ;
                met->signature(buffer, name) ;
                signatures[i] = buffer ;
            }
        
            field( "pointer" )       = Rcpp::XPtr< vec_signed_method >( m, false ) ;
            field( "class_pointer" ) = class_xp ;
            field( "size" )          = n ;
            field( "void" )          = voidness ;
            field( "const" )         = constness ;
            field( "docstrings" )    = docstrings ;
            field( "signatures" )    = signatures ;
        }
    } ;

#include <Rcpp/module/Module_generated_CppMethod.h>
#include <Rcpp/module/Module_generated_Pointer_CppMethod.h>

    template <typename Class>
    class CppProperty {
    public:
        typedef Rcpp::XPtr<Class> XP ;
                
        CppProperty(const char* doc = 0) : docstring( doc == 0 ? "" : doc ) {} ;
        virtual SEXP get(Class* ) { throw std::range_error("cannot retrieve property"); }
        virtual void set(Class*, SEXP) { throw std::range_error("cannot set property"); }
        virtual bool is_readonly(){ return false; }
        virtual std::string get_class(){ return ""; }
                
        std::string docstring ;
    } ;

    template <typename Class>
    class CppFinalizer{ 
    public:
        CppFinalizer(){} ;
        virtual void run(Class* ){} ;
    } ;

    template <typename Class>
    class FunctionFinalizer : public CppFinalizer<Class> {
    public:
        typedef void (*Pointer)(Class*) ;
        FunctionFinalizer( Pointer p ) : finalizer(p){} ;
    
        virtual void run(Class* object){ 
            finalizer( object ) ;
        }
    
    private:
        Pointer finalizer ;    
    } ;

    template <typename Class>
    class S4_field : public Rcpp::Reference {
    public:             
        S4_field( CppProperty<Class>* p, SEXP class_xp ) : Reference( "C++Field" ){
            field( "read_only" )     = p->is_readonly() ;
            field( "cpp_class" )     = p->get_class();
            field( "pointer" )       = Rcpp::XPtr< CppProperty<Class> >( p, false ) ;
            field( "class_pointer" ) = class_xp ;
            field( "docstring" )     = p->docstring ;
        }
    } ;

#include <Rcpp/module/Module_Property.h>

    template <typename Class>
    class class_ : public class_Base {
    public:
        typedef class_<Class> self ;
        typedef CppMethod<Class> method_class ;
        
        typedef SignedMethod<Class> signed_method_class ;
        typedef std::vector<signed_method_class*> vec_signed_method ;
        typedef std::map<std::string,vec_signed_method*> map_vec_signed_method ;
        typedef std::pair<std::string,vec_signed_method*> vec_signed_method_pair ;
        
        typedef std::map<std::string,method_class*> METHOD_MAP ;
        typedef std::pair<const std::string,method_class*> PAIR ;
        
        typedef Rcpp::XPtr<Class> XP ;
        typedef CppFinalizer<Class> finalizer_class ;
        
        typedef Constructor_Base<Class> constructor_class ;
        typedef SignedConstructor<Class> signed_constructor_class ;
        typedef std::vector<signed_constructor_class*> vec_signed_constructor ;
        
        typedef CppProperty<Class> prop_class ;
        typedef std::map<std::string,prop_class*> PROPERTY_MAP ;
        typedef std::pair<const std::string,prop_class*> PROP_PAIR ;
        
        class_( const char* name_, const char* doc = 0) : 
            class_Base(name_, 0), 
            vec_methods(), 
            properties(), 
            finalizer_pointer(0), 
            specials(0), 
            constructors(), 
            class_pointer(0), 
            typeinfo_name("")
        {
            Rcpp::Module* module = getCurrentScope() ;
            if( ! module->has_class(name_) ){
                class_pointer = new self ;
                class_pointer->name = name_ ;
                class_pointer->docstring = std::string( doc == 0 ? "" : doc );
                class_pointer->finalizer_pointer = new finalizer_class ;
                class_pointer->typeinfo_name = typeid(Class).name() ;
                module->AddClass( name_, class_pointer ) ;
            }
        }
         
        ~class_(){}
        
        
        self& AddConstructor( constructor_class* ctor, ValidConstructor valid, const char* docstring = 0 ){
            class_pointer->constructors.push_back( new signed_constructor_class( ctor, valid, docstring ) );  
            return *this ;
        }
        
        self& default_constructor( const char* docstring= 0, ValidConstructor valid = &yes_arity<0> ){
            return constructor( docstring, valid ) ;  
        }
                
#include <Rcpp/module/Module_generated_class_constructor.h>
        
    public:
        
        std::string get_typeinfo_name(){
            return typeinfo_name ;    
        }
    
        SEXP newInstance( SEXP* args, int nargs ){
            BEGIN_RCPP
                signed_constructor_class* p ;
            int n = constructors.size() ;
            for( int i=0; i<n; i++ ){
                p = constructors[i];
                bool ok = (p->valid)(args, nargs) ;
                if( ok ){
                    Class* ptr = p->ctor->get_new( args, nargs ) ;
                    return XP( ptr, true ) ;
                }
            }
            throw std::range_error( "no valid constructor available for the argument list" ) ;
            END_RCPP
                }
        
        bool has_default_constructor(){ 
            int n = constructors.size() ;
            signed_constructor_class* p ;
            for( int i=0; i<n; i++ ){
                p = constructors[i];
                if( p->nargs() == 0 ) return true ;
            }
            return false ;
        }
        
        SEXP invoke( SEXP method_xp, SEXP object, SEXP *args, int nargs ){ 
            BEGIN_RCPP
                
                vec_signed_method* mets = reinterpret_cast< vec_signed_method* >( EXTPTR_PTR( method_xp ) ) ;
            typename vec_signed_method::iterator it = mets->begin() ;
            int n = mets->size() ;
            method_class* m = 0 ;
            bool ok = false ; 
            for( int i=0; i<n; i++, ++it ){
                if( ( (*it)->valid )( args, nargs) ){
                    m = (*it)->method ;
                    ok = true ; 
                    break ;
                }
            }
            if( !ok ){
                throw std::range_error( "could not find valid method" ) ;   
            }
            if( m->is_void() ){
                m->operator()( XP(object), args ); 
                return Rcpp::List::create( true ) ;
            } else {
                return Rcpp::List::create( false, m->operator()( XP(object), args ) ) ;
            }
            END_RCPP        
                }
        
        SEXP invoke_void( SEXP method_xp, SEXP object, SEXP *args, int nargs ){ 
            BEGIN_RCPP
                
                vec_signed_method* mets = reinterpret_cast< vec_signed_method* >( EXTPTR_PTR( method_xp ) ) ;
            typename vec_signed_method::iterator it = mets->begin() ;
            int n = mets->size() ;
            method_class* m = 0 ;
            bool ok = false ; 
            for( int i=0; i<n; i++, ++it ){
                if( ( (*it)->valid )( args, nargs) ){
                    m = (*it)->method ;
                    ok = true ; 
                    break ;
                }
            }
            if( !ok ){
                throw std::range_error( "could not find valid method" ) ;   
            }
            m->operator()( XP(object), args ); 
            END_RCPP        
                }
        
        SEXP invoke_notvoid( SEXP method_xp, SEXP object, SEXP *args, int nargs ){ 
            BEGIN_RCPP
                
                vec_signed_method* mets = reinterpret_cast< vec_signed_method* >( EXTPTR_PTR( method_xp ) ) ;
            typename vec_signed_method::iterator it = mets->begin() ;
            int n = mets->size() ;
            method_class* m = 0 ;
            bool ok = false ; 
            for( int i=0; i<n; i++, ++it ){
                if( ( (*it)->valid )( args, nargs) ){
                    m = (*it)->method ;
                    ok = true ; 
                    break ;
                }
            }
            if( !ok ){
                throw std::range_error( "could not find valid method" ) ;   
            }
            return m->operator()( XP(object), args ) ;
            END_RCPP        
                }
        
        
        self& AddMethod( const char* name_, method_class* m, ValidMethod valid = &yes, const char* docstring = 0){
            typename map_vec_signed_method::iterator it = class_pointer->vec_methods.find( name_ ) ; 
            if( it == class_pointer->vec_methods.end() ){
                it = class_pointer->vec_methods.insert( vec_signed_method_pair( name_, new vec_signed_method() ) ).first ;
            } 
            (it->second)->push_back( new signed_method_class(m, valid, docstring ) ) ;
            if( *name_ == '[' ) class_pointer->specials++ ;
            return *this ;
        }
        
        self& AddProperty( const char* name_, prop_class* p){
            class_pointer->properties.insert( PROP_PAIR( name_, p ) ) ;
            return *this ;
        }

#include <Rcpp/module/Module_generated_method.h>
#include <Rcpp/module/Module_generated_Pointer_method.h>
        
        bool has_method( const std::string& m){
            return vec_methods.find(m) != vec_methods.end() ;
        }
        bool has_property( const std::string& m){
            return properties.find(m) != properties.end() ;
        }
        bool property_is_readonly( const std::string& p) {
            typename PROPERTY_MAP::iterator it = properties.find( p ) ;
            if( it == properties.end() ) throw std::range_error( "no such property" ) ;
            return it->second->is_readonly() ;
        }
        std::string property_class(const std::string& p) {
            typename PROPERTY_MAP::iterator it = properties.find( p ) ;
            if( it == properties.end() ) throw std::range_error( "no such property" ) ;
            return it->second->get_class() ;
        }
        
        Rcpp::CharacterVector method_names(){
            int n = 0 ; 
            int s = vec_methods.size() ;
            typename map_vec_signed_method::iterator it = vec_methods.begin( ) ;
            for( int i=0; i<s; i++, ++it){
                n += (it->second)->size() ;
            }
            Rcpp::CharacterVector out(n) ;
            it = vec_methods.begin() ;
            int k = 0 ;
            for( int i=0; i<s; i++, ++it){
                n = (it->second)->size() ;
                std::string name = it->first ;
                for( int j=0; j<n; j++, k++){
                    out[k] = name ;
                }
            } 
            return out ;
        }
        
        Rcpp::IntegerVector methods_arity(){
            int n = 0 ; 
            int s = vec_methods.size() ;
            typename map_vec_signed_method::iterator it = vec_methods.begin( ) ;
            for( int i=0; i<s; i++, ++it){
                n += (it->second)->size() ;
            }
            Rcpp::CharacterVector mnames(n) ;
            Rcpp::IntegerVector res(n) ;
            it = vec_methods.begin() ;
            int k = 0 ;
            for( int i=0; i<s; i++, ++it){
                n = (it->second)->size() ;
                std::string name = it->first ;
                typename vec_signed_method::iterator m_it = (it->second)->begin() ;
                for( int j=0; j<n; j++, k++, ++m_it){
                    mnames[k] = name ;
                    res[k] = (*m_it)->nargs() ;
                }
            }
            res.names( ) = mnames ;
            return res ;
        }
        
        Rcpp::LogicalVector methods_voidness(){
            int n = 0 ; 
            int s = vec_methods.size() ;
            typename map_vec_signed_method::iterator it = vec_methods.begin( ) ;
            for( int i=0; i<s; i++, ++it){
                n += (it->second)->size() ;
            }
            Rcpp::CharacterVector mnames(n) ;
            Rcpp::LogicalVector res(n) ;
            it = vec_methods.begin() ;
            int k = 0 ;
            for( int i=0; i<s; i++, ++it){
                n = (it->second)->size() ;
                std::string name = it->first ;
                typename vec_signed_method::iterator m_it = (it->second)->begin() ;
                for( int j=0; j<n; j++, k++, ++m_it){
                    mnames[k] = name ;
                    res[k] = (*m_it)->is_void() ;
                }
            }
            res.names( ) = mnames ;
            return res ;
        }
        
        
        Rcpp::CharacterVector property_names(){
            int n = properties.size() ;
            Rcpp::CharacterVector out(n) ;
            typename PROPERTY_MAP::iterator it = properties.begin( ) ;
            for( int i=0; i<n; i++, ++it){
                out[i] = it->first ;
            } 
            return out ;
        }
        
        Rcpp::List property_classes(){
            int n = properties.size() ;
            Rcpp::CharacterVector pnames(n) ;
            Rcpp::List out(n) ;
            typename PROPERTY_MAP::iterator it = properties.begin( ) ;
            for( int i=0; i<n; i++, ++it){
                pnames[i] = it->first ;
                out[i] = it->second->get_class() ; 
            } 
            out.names() = pnames ;
            return out ;
        }
        
        Rcpp::CharacterVector complete(){
            int n = vec_methods.size() - specials ;
            int ntotal = n + properties.size() ;
            Rcpp::CharacterVector out(ntotal) ;
            typename map_vec_signed_method::iterator it = vec_methods.begin( ) ;
            std::string buffer ;
            int i=0 ;
            for( ; i<n; ++it){  
                buffer = it->first ;
                if( buffer[0] == '[' ) continue ;
                // if( (it->second)->nargs() == 0){
                //      buffer += "() " ;
                // } else {
                //      buffer += "( " ;
                // } 
                buffer += "( " ;
                out[i] = buffer ;
                i++ ;
            }
            typename PROPERTY_MAP::iterator prop_it = properties.begin(); 
            for( ; i<ntotal; i++, ++prop_it){
                out[i] = prop_it->first ;
            }
            return out ;
        }
        
        SEXP getProperty( SEXP field_xp , SEXP object) {
            BEGIN_RCPP
                prop_class* prop = reinterpret_cast< prop_class* >( EXTPTR_PTR( field_xp ) ) ;
            return prop->get( XP(object) ); 
            END_RCPP
                }
        
        void setProperty( SEXP field_xp, SEXP object, SEXP value)  {
            BEGIN_RCPP
                prop_class* prop = reinterpret_cast< prop_class* >( EXTPTR_PTR( field_xp ) ) ;
            return prop->set( XP(object), value ); 
            VOID_END_RCPP
                }
        
        
        Rcpp::List fields( SEXP class_xp ){
            int n = properties.size() ;
            Rcpp::CharacterVector pnames(n) ;
            Rcpp::List out(n) ;
            typename PROPERTY_MAP::iterator it = properties.begin( ) ;
            for( int i=0; i<n; i++, ++it){
                pnames[i] = it->first ;
                out[i] = S4_field<Class>( it->second, class_xp ) ; 
            } 
            out.names() = pnames ;
            return out ;
        }

        Rcpp::List getMethods( SEXP class_xp, std::string& buffer){
            int n = vec_methods.size() ;
            Rcpp::CharacterVector mnames(n) ;
            Rcpp::List res(n) ;
            typename map_vec_signed_method::iterator it = vec_methods.begin( ) ;
            vec_signed_method* v; 
            for( int i=0; i<n; i++, ++it){
                mnames[i] = it->first ;
                v = it->second ;
                res[i] = S4_CppOverloadedMethods<Class>( v , class_xp, it->first.c_str(), buffer ) ;
            }
            res.names() = mnames ;
            return res ;
        }
        
        Rcpp::List getConstructors( SEXP class_xp, std::string& buffer){
            int n = constructors.size() ;
            Rcpp::List out(n) ;
            typename vec_signed_constructor::iterator it = constructors.begin( ) ;
            for( int i=0; i<n; i++, ++it){
                out[i] = S4_CppConstructor<Class>( *it , class_xp, name, buffer ) ; 
            } 
            return out ;
        }

#include <Rcpp/module/Module_Field.h>

#include <Rcpp/module/Module_Add_Property.h>

        self& finalizer( void (*f)(Class*) ){
            SetFinalizer( new FunctionFinalizer<Class>( f ) ) ;
            return *this ;
        }    

        virtual void run_finalizer( SEXP object ){
            finalizer_pointer->run( XP(object) ) ;
        }
    
    private:
    
        void SetFinalizer( finalizer_class* f ){
            if( class_pointer->finalizer_pointer ) delete class_pointer->finalizer_pointer ;
            class_pointer->finalizer_pointer = f ; 
        }
    
        map_vec_signed_method vec_methods ;
        PROPERTY_MAP properties ;
        
        finalizer_class* finalizer_pointer ;
        int specials ;
        vec_signed_constructor constructors ;
        self* class_pointer ;
        std::string typeinfo_name ;
    
        class_( ) : class_Base(), vec_methods(), properties(), specials(0) {}; 
        
    } ;   

    // function factories
#include <Rcpp/module/Module_generated_function.h>

    class CppClass : public S4{
    public:
        typedef Rcpp::XPtr<Rcpp::Module> XP ;
        CppClass( Module* p, class_Base* clazz, std::string& ) ;
        CppClass( SEXP x) ;
    } ;

    class CppObject : public S4{
    public:
        typedef Rcpp::XPtr<Rcpp::Module> XP ;
        CppObject( Module* p, class_Base*, SEXP xp ) ;
    } ;

}

#define RCPP_MODULE_BOOT(name) _rcpp_module_boot_##name

#define RCPP_MODULE(name)                                               \
    void _rcpp_module_##name##_init() ;                                 \
    static Rcpp::Module _rcpp_module_##name( # name ) ;                 \
    extern "C" SEXP _rcpp_module_boot_##name(){                         \
        ::setCurrentScope( & _rcpp_module_##name ) ;                    \
        _rcpp_module_##name##_init( ) ;                                 \
        Rcpp::XPtr<Rcpp::Module> mod_xp(& _rcpp_module_##name , false); \
        ::setCurrentScope( 0 ) ;                                        \
        return mod_xp ;                                                 \
    }                                                                   \
    void _rcpp_module_##name##_init()

// silly little dance to suppress a 'defined but not used variable' warning
#ifdef __GNUC__
#define VARIABLE_IS_NOT_USED __attribute__ ((unused))
#else
#define VARIABLE_IS_NOT_USED
#endif

// static variable to hold Rf_install symbol to prevent it from being gc'ed
static VARIABLE_IS_NOT_USED SEXP moduleSym = NULL;

// helper macro to cache the result of Rf_install("Module"): once
// it is allocated and in the symbol table it is safe from gc
#define GET_MODULE_SYM    ( moduleSym == NULL ? moduleSym = Rf_install("Module") : moduleSym )

// this macro is called by code wanting to load a module -- see RInside's rinside_module_sample0.cpp
#define LOAD_RCPP_MODULE(NAME) Rf_eval( Rf_lang2( GET_MODULE_SYM, _rcpp_module_boot_##NAME() ), R_GlobalEnv )

#endif

