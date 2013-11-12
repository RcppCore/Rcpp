// Copyright (C) 2013 Romain Francois
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

#ifndef RCPP_ROUTINE_H
#define RCPP_ROUTINE_H

#if defined(COMPILING_RCPP11)

// the idea is that this file should be generated automatically by Rcpp::register

namespace Rcpp{
    SEXP Rcpp_eval(SEXP expr, SEXP env = R_GlobalEnv) ;
    const char* type2name(SEXP x) ;
    std::string demangle( const std::string& name) ;
    void forward_exception_to_r( const std::exception& ex ) ;
    SEXP exception_to_try_error( const std::exception& ex ) ;
    SEXP string_to_try_error( const std::string& str) ;
    SEXP stack_trace( const char *file, int line) ;
    unsigned long enterRNGScope(); 
    unsigned long exitRNGScope() ;
    SEXP get_Rcpp11_namespace() ; 
    int* get_cache( int n ) ;
}
           
SEXP rcpp_set_stack_trace(SEXP) ;
SEXP get_string_elt(SEXP s, int i); 
const char* char_get_string_elt(SEXP s, int i) ;
void set_string_elt(SEXP s, int i, SEXP v); 
void char_set_string_elt(SEXP s, int i, const char* v); 
SEXP* get_string_ptr(SEXP s) ;
SEXP get_vector_elt(SEXP v, int i) ;
void set_vector_elt(SEXP v, int i, SEXP x); 
SEXP* get_vector_ptr(SEXP v); 
const char* char_nocheck( SEXP x) ;
void* dataptr(SEXP x) ;
Rcpp::Module* getCurrentScope() ;
void setCurrentScope( Rcpp::Module* mod ) ;
 
#else 
namespace Rcpp {
    
    #define GET_CALLABLE(__FUN__) (Fun) R_GetCCallable( "Rcpp", __FUN__ )
    
    inline SEXP Rcpp_eval(SEXP expr, SEXP env = R_GlobalEnv){
        typedef SEXP (*Fun)(SEXP,SEXP) ;
        static Fun fun = GET_CALLABLE("Rcpp_eval") ;
        return fun(expr, env) ;
    }
    
    inline const char* type2name(SEXP x){
        typedef const char* (*Fun)(SEXP) ;
        static Fun fun = GET_CALLABLE("type2name") ;
        return fun(x) ;
    }
    
    inline std::string demangle( const std::string& name){
        typedef std::string (*Fun)( const std::string& ) ;
        static Fun fun = GET_CALLABLE("demangle") ;
        return fun(name) ;
    }
    
    inline void forward_exception_to_r( const std::exception& ex ){
        typedef void (*Fun)(const std::exception&) ;
        static Fun fun = GET_CALLABLE("forward_exception_to_r") ;
        fun(ex) ;
    }
    
    inline SEXP exception_to_try_error( const std::exception& ex ){
        typedef SEXP (*Fun)(const std::exception& ) ;
        static Fun fun = GET_CALLABLE("exception_to_try_error") ;
        return fun(ex) ;
    }
    
    inline SEXP string_to_try_error( const std::string& str){
        typedef SEXP (*Fun)( const std::string&) ;
        static Fun fun = GET_CALLABLE("string_to_try_error") ;
        return fun(str) ;
    }
    
    inline SEXP stack_trace( const char *file, int line){
        typedef SEXP (*Fun)(const char*, int) ;
        static Fun fun = GET_CALLABLE("stack_trace") ;
        return fun(file, line) ;
    }
    
    inline unsigned long enterRNGScope(){
        typedef unsigned long (*Fun)(void) ; 
        static Fun fun = GET_CALLABLE("enterRNGScope") ;
        return fun() ;
    }
    
    inline unsigned long exitRNGScope(){
        typedef unsigned long (*Fun)(void) ;
        static Fun fun = GET_CALLABLE("exitRNGScope") ;
        return fun() ;
    }
           
    inline SEXP get_Rcpp_namespace() {
        typedef SEXP (*Fun)(void) ;
        static Fun fun = GET_CALLABLE("get_Rcpp_namespace") ;
        return fun();
    }
    
    inline int* get_cache( int n ){
        typedef int* (*Fun)(int) ;
        static Fun fun = GET_CALLABLE("get_cache") ;
        return fun(n) ;    
    }
    
}
           
inline SEXP get_string_elt(SEXP s, int i){
    typedef SEXP (*Fun)(SEXP, int) ;
    static Fun fun = GET_CALLABLE("get_string_elt") ;
    return fun(s, i) ;
}

inline const char* char_get_string_elt(SEXP s, int i){
    typedef const char* (*Fun)(SEXP, int) ;
    static Fun fun = GET_CALLABLE("char_get_string_elt") ;
    return fun(s, i); 
}

inline void set_string_elt(SEXP s, int i, SEXP v){
    typedef void (*Fun)(SEXP,int,SEXP) ;
    static Fun fun = GET_CALLABLE("set_string_elt") ;
    fun(s, i, v) ;
}

inline void char_set_string_elt(SEXP s, int i, const char* v){
    typedef void (*Fun)(SEXP,int, const char*) ;
    static Fun fun = GET_CALLABLE("char_set_string_elt") ; 
    fun(s, i, v ) ;    
}

inline SEXP* get_string_ptr(SEXP s){
    typedef SEXP* (*Fun)(SEXP) ;
    static Fun fun = GET_CALLABLE("get_string_ptr") ; 
    return fun(s) ;    
}

inline SEXP get_vector_elt(SEXP v, int i){
    typedef SEXP (*Fun)(SEXP, int );
    static Fun fun = GET_CALLABLE("get_vector_elt") ;
    return fun(v, i) ;
}

inline void set_vector_elt(SEXP v, int i, SEXP x){
    typedef void (*Fun)(SEXP, int, SEXP) ;
    static Fun fun = GET_CALLABLE("set_vector_elt") ;
    fun(v, i, x) ;
}

inline SEXP* get_vector_ptr(SEXP v){
    typedef SEXP* (*Fun)(SEXP) ;
    static Fun fun = GET_CALLABLE("get_vector_ptr") ;
    return fun(v) ;    
}

inline const char* char_nocheck( SEXP x){
    typedef const char* (*Fun)(SEXP) ;
    static Fun fun = GET_CALLABLE("char_nocheck") ;
    return fun(x) ;
}

inline void* dataptr(SEXP x){
    typedef void* (*Fun)(SEXP) ;
    static Fun fun = GET_CALLABLE("dataptr") ;
    return fun(x) ; 
}

inline SEXP rcpp_set_stack_trace(SEXP x){
    typedef SEXP (*Fun)(SEXP) ;
    static Fun fun = GET_CALLABLE("rcpp_set_stack_trace") ;
    return fun(x) ;    
}

inline Rcpp::Module* getCurrentScope(){
    typedef Rcpp::Module* (*Fun)(void) ;
    static Fun fun = GET_CALLABLE("getCurrentScope") ;
    return fun();
}

inline void setCurrentScope( Rcpp::Module* mod ){
    typedef void (*Fun)(Rcpp::Module*) ;
    static Fun fun = GET_CALLABLE("setCurrentScope") ;
    fun(mod) ;    
}

#endif


#endif