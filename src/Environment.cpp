// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Environment.cpp: Rcpp R/C++ interface class library -- Environments
//
// Copyright (C) 2009 - 2012  Dirk Eddelbuettel and Romain Francois
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

#include <Rcpp/Environment.h>

namespace Rcpp {

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
    
    Environment::Environment( const Environment& other ) {
        setSEXP( other.asSexp() ) ; 
    }
    
    Environment& Environment::operator=(const Environment& other) {
        setSEXP( other.asSexp() ) ; 
        return *this ;
    }
    
    Environment::~Environment(){
        logTxt( "~Environment" ) ;
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
    
    
} // namespace Rcpp

