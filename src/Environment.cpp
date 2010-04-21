// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// Environment.cpp: Rcpp R/C++ interface class library -- Environments
//
// Copyright (C) 2009 - 2010	Dirk Eddelbuettel and Romain Francois
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

	Environment::not_found::not_found(const std::string& binding_) : binding(binding_){}
	Environment::not_found::~not_found() throw(){}
	const char* Environment::not_found::what() const throw(){
		std::string message( "not found : " ) ;
		message += binding ;
		return message.c_str() ;
	}
	
    Environment::Environment() : RObject(R_NilValue){}

    Environment::Environment( SEXP x = R_GlobalEnv) throw(not_compatible) : RObject(x){
    	if( ! Rf_isEnvironment(x) ) {
    		/* not an environment, but maybe convertible to one using 
    		   as.environment, try that */
    		SEXP res ;
    		try{
    			res = Evaluator::run( Rf_lang2(Rf_install("as.environment"), x ) ) ;
    		} catch( const Evaluator::eval_error& ex){
    			throw not_compatible( "cannot convert to environment"  ) ; 
    		}
    		setSEXP( res ) ;
    	}
    }

    Environment::Environment( const std::string& name) throw(no_such_env) : RObject(R_EmptyEnv){
    	/* similar to matchEnvir@envir.c */
    	if( name == ".GlobalEnv" ) {
    		setSEXP( R_GlobalEnv ) ;
    	} else if( name == "package:base" ){
    		setSEXP( R_BaseEnv ) ;
    	} else{
    		SEXP res = R_NilValue ;
    		try{
    			res = Evaluator::run( 
    				Rf_lang2( Rf_install("as.environment"), Rf_mkString(name.c_str()) ) ) ;
    		} catch( const Evaluator::eval_error& ex){
    			throw no_such_env(name) ;
    		}
    		setSEXP( res ) ;
    	}
    }
    
    Environment::Environment(int pos) throw(no_such_env) : RObject(R_GlobalEnv){
    	   SEXP res ;
    	   try{
    	   	   res =  Evaluator::run( Rf_lang2( Rf_install("as.environment"), Rf_ScalarInteger(pos) ) ) ;
    	   } catch( const Evaluator::eval_error& ex){
    	   	   throw no_such_env(pos) ;
    	   }
    	   setSEXP( res ) ;
    }
    
    Environment::Environment( const Environment& other ) throw() {
	setSEXP( other.asSexp() ) ; 
    }
    
    Environment& Environment::operator=(const Environment& other) throw() {
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
    	SEXP res = Rf_findVarInFrame( m_sexp, Rf_install(name.c_str())  ) ;
    	
    	if( res == R_UnboundValue ) return R_NilValue ;
    	
    	/* We need to evaluate if it is a promise */
	if( TYPEOF(res) == PROMSXP){
    		res = Rf_eval( res, m_sexp ) ;
    	}
    	return res ;
    }
    
    SEXP Environment::find( const std::string& name) const {
    	SEXP res = Rf_findVar( Rf_install(name.c_str()), m_sexp ) ;
    	
    	if( res == R_UnboundValue ) throw not_found(name) ;
    	
    	/* We need to evaluate if it is a promise */
	if( TYPEOF(res) == PROMSXP){
    		res = Rf_eval( res, m_sexp ) ;
    	}
    	return res ;
    }
    
    bool Environment::exists( const std::string& name) const{
    	SEXP res = Rf_findVarInFrame( m_sexp, Rf_install(name.c_str())  ) ;
    	return res != R_UnboundValue ;
    }
    
    bool Environment::assign( const std::string& name, SEXP x = R_NilValue) const throw(binding_is_locked){
    	if( exists( name) && bindingIsLocked(name) ) throw binding_is_locked(name) ;
    	Rf_defineVar( Rf_install( name.c_str() ) , x, m_sexp );
    	return true ;
    }
    
    bool Environment::remove( const std::string& name) throw(binding_is_locked,no_such_binding){
    	    if( exists(name) ){
    	    	    if( bindingIsLocked(name) ){
    	    	    	    throw binding_is_locked(name) ;
    	    	    } else{
    	    	    	    /* unless we want to copy all of do_remove, 
    	    	    	       we have to go back to R to do this operation */
    	    	    	    SEXP call = Rf_lang2( 
    	    	    	    	    Rf_install( ".Internal" ), 
    	    	    	    	    Rf_lcons( Rf_install( "remove" ), 
    	    	    	    	    	    Rf_cons( Rf_mkString(name.c_str()), 
    	    	    	    	    	    	    Rf_cons( m_sexp, 
    	    	    	    	    	    	    	    Rf_cons( Rf_ScalarLogical( FALSE ), R_NilValue )
    	    	    	    	    	    	    	    ) 
    	    	    	    	    	    	    )
    	    	    	    	    	    )
    	    	    	    	    ) ;
    	    	    	    Rf_eval( call, R_GlobalEnv ) ;
    	    	    }
    	    } else{
    	    	throw no_such_binding(name) ;
    	    }
	    return true; // to make g++ -Wall happy
    }
    
    bool Environment::isLocked() const{
    	return R_EnvironmentIsLocked(m_sexp);
    }
    
    bool Environment::bindingIsActive(const std::string& name) const throw(no_such_binding) {
    	if( !exists( name) ) throw no_such_binding(name) ;
    	return R_BindingIsActive(Rf_install(name.c_str()), m_sexp) ;
    }
    
    bool Environment::bindingIsLocked(const std::string& name) const throw(no_such_binding) {
    	if( !exists( name) ) throw no_such_binding(name) ;
    	return R_BindingIsLocked(Rf_install(name.c_str()), m_sexp) ;
    }
    
    void Environment::lock( bool bindings = false ) {
    	R_LockEnvironment( m_sexp, bindings ? TRUE: FALSE ) ;
    }
    
    void Environment::lockBinding(const std::string& name) throw(no_such_binding) {
    	if( !exists( name) ) throw no_such_binding(name) ;
    	R_LockBinding( Rf_install( name.c_str() ), m_sexp ); 
    }
    
    void Environment::unlockBinding(const std::string& name) throw(no_such_binding) {
    	if( !exists( name) ) throw no_such_binding(name) ;
    	R_unLockBinding( Rf_install( name.c_str() ), m_sexp );
    }
    
    bool Environment::is_user_database() const {
    	return OBJECT(m_sexp) && Rf_inherits(m_sexp, "UserDefinedDatabase") ;
    }
    
    /* static */
    
    Environment Environment::global_env() throw() {
    	return Environment(R_GlobalEnv) ;
    }
    
    Environment Environment::empty_env() throw() {
    	return Environment(R_EmptyEnv) ;
    }
    
    Environment Environment::base_env() throw(){
    	return Environment(R_BaseEnv) ;
    }
    
    Environment Environment::base_namespace() throw() {
    	return Environment(R_BaseNamespace) ;
    }
    
    Environment Environment::namespace_env(const std::string& package) throw(no_such_namespace) {
    	
    	SEXP env = R_NilValue ;
    	try{
    		env = Evaluator::run( Rf_lang2(Rf_install("getNamespace"), Rf_mkString(package.c_str()) ) ) ;
    	} catch( const Evaluator::eval_error& ex){
    		throw no_such_namespace( package  ) ; 
    	}
    	return Environment( env ) ;
    }
    
    Environment Environment::parent() const throw() {
    	return Environment( ENCLOS(m_sexp) ) ; 
    }
    
    /* exceptions */    
    Environment::binding_is_locked::binding_is_locked(const std::string& binding) : 
    	message("binding is locked : '" + binding + "'" ) {}
    const char* Environment::binding_is_locked::what() const throw(){
    	return message.c_str() ;
    }
    Environment::binding_is_locked::~binding_is_locked() throw() {}
    
    Environment::no_such_namespace::no_such_namespace(const std::string& package) : 
    	message("no such namespace : '" + package + "'" ) {}
    const char* Environment::no_such_namespace::what() const throw(){
    	return message.c_str() ;
    }
    Environment::no_such_namespace::~no_such_namespace() throw() {}
    
    Environment::no_such_env::no_such_env(const std::string& name) : 
    	message("no environment called : '" + name + "'" ) {}
    Environment::no_such_env::no_such_env(int pos) : 
    	message("no environment in the given position" ) {}
    const char* Environment::no_such_env::what() const throw(){
    	return message.c_str() ;
    }
    Environment::no_such_env::~no_such_env() throw() {}
    
    
    
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
    
    Environment Environment::Rcpp_namespace() throw() {
    	    return Environment( Rf_eval( Rf_lcons( Rf_install("getNamespace"), Rf_cons( Rf_mkString("Rcpp") , R_NilValue) ), R_GlobalEnv ) ) ;
    }
    
    Environment Environment::new_child(bool hashed) {
    	    return Environment( Evaluator::run( 
    	    	    Rf_lcons( Rf_install("new.env"), 
    	    	    	    Rf_cons(Rf_ScalarLogical(hashed), 
    	    	    	    	    Rf_cons(m_sexp,R_NilValue)) ) ) );
    }
    
    
} // namespace Rcpp

