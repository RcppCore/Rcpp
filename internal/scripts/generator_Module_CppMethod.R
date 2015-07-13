#!/usr/bin/Rscript
#
# Generator for inst/include/Rcpp/module/Module_generated_CppMethod.h
#
# Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois

fun <- function(i) {

    index <- (1:i)-1
    collapse <- function(x, collapse = ", ") paste( x, collapse = collapse)
	
    typenames <- collapse(sprintf( "typename U%d", index))
    u <- collapse(sprintf("U%d u%d", index, index))
    input_parameter <- collapse(sprintf("typename Rcpp::traits::input_parameter<U%d>::type x%d(args[%d]);",
                                        index, index, index), collapse = "\n")  
    x <- collapse(sprintf( "x%d", index))
    U <- collapse(sprintf( "U%d", index))
       
    txt <- sprintf('

template <typename Class, typename RESULT_TYPE, %s> class CppMethod%d : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (Class::*Method)(%s);
    typedef CppMethod<Class> method_class;
    typedef typename Rcpp::traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;
    
    CppMethod%d(Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, SEXP* args) {
        %s
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>((object->*met)(%s));
    }
    inline int nargs() { return %d; }
    inline bool is_void() { return false; }
    inline bool is_const() { return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,%s>(s, name); }

private:
    Method met;
};

template <typename Class, %s> class CppMethod%d<Class,void,%s> : public CppMethod<Class> {
public:
    typedef void (Class::*Method)(%s);
    typedef CppMethod<Class> method_class;
    
    CppMethod%d( Method m) : method_class(), met(m) {} 
    SEXP operator()( Class* object, SEXP* args) {
        %s
        (object->*met)(%s);
        return R_NilValue;
    }
    inline int nargs() { return %d; }
    inline bool is_void() { return true; }
    inline bool is_const() { return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type,%s>(s, name); }

private:
    Method met;
};

template <typename Class, typename RESULT_TYPE, %s> class const_CppMethod%d : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (Class::*Method)(%s) const;
    typedef CppMethod<Class> method_class;
    typedef typename Rcpp::traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;
    
    const_CppMethod%d(Method m) : method_class(), met(m) {} 
    SEXP operator()( Class* object, SEXP* args) {
        %s
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>((object->*met)(%s));
    }
    inline int nargs() { return %d; }
    inline bool is_void() { return false; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,%s>(s, name); }

private:
    Method met;
} ;
    
template < typename Class, %s > class const_CppMethod%d<Class,void,%s> : public CppMethod<Class> {
public:
    typedef void (Class::*Method)(%s) const;
    typedef CppMethod<Class> method_class;
    
    const_CppMethod%d(Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, SEXP* args) {
        %s
        (object->*met)(%s);
        return R_NilValue;
    }
    inline int nargs() { return %d; }
    inline bool is_void() { return true; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name ) { Rcpp::signature<void_type,%s>(s, name); }

private:
    Method met ;
};', 
    typenames,  # typename U0, ...
    i,           
    u,          # U0 u0, ...
    i,
    input_parameter,
    x,         # Rcpp::as<U0>( args[0] ) , ...
    i, 
    U,

    typenames,  # typename U0, ...
    i, 
    U, 			# U0, ...
    u,          # U0 u0, ...
    i,
    input_parameter,
    x, 
    i, 
    U,


    typenames,  # typename U0, ...
    i,           
    u,          # U0 u0, ...
    i, 
    input_parameter,
    x,         # Rcpp::as<U0>( args[0] ) , ...
    i, 
    U, 

    typenames,  # typename U0, ...
    i, 
    U, 			 # U0, ...
    u,          # U0 u0, ...
    i, 
    input_parameter,
    x, 
    i,
    U 
    )   
}

file <- sprintf( 
'// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module_generated_CppMethod.h: -- generated helper code for Modules
//                                  see rcpp-scripts repo for generator script
//
// Copyright (C) 2010 - 2014  Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Module_generated_CppMethod_h
#define Rcpp_Module_generated_CppMethod_h

template <typename Class, typename RESULT_TYPE> class CppMethod0 : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (Class::*Method)(void);
    typedef CppMethod<Class> method_class;
    typedef typename Rcpp::traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;
    
    CppMethod0( Method m) : method_class(), met(m) {} 
    SEXP operator()( Class* object, SEXP*) {
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>((object->*met)());
    }
    inline int nargs() { return 0; }
    inline bool is_void() { return false; }
    inline bool is_const() { return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE>(s, name); }

private:
    Method met;
};

template <typename Class> class CppMethod0<Class,void> : public CppMethod<Class> {
public:
    typedef void (Class::*Method)(void);
    typedef CppMethod<Class> method_class;
    CppMethod0( Method m) : method_class(), met(m) {} 
    SEXP operator()( Class* object, SEXP* ) {
        (object->*met)();
        return R_NilValue;
    }
    inline int nargs() { return 0; }
    inline bool is_void() { return true; }
    inline bool is_const() { return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type>(s, name); }

private:
    Method met;
};

template <typename Class, typename RESULT_TYPE> class const_CppMethod0 : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (Class::*Method)(void) const;
    typedef CppMethod<Class> method_class;
    typedef typename Rcpp::traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;
    
    const_CppMethod0( Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, SEXP*) {
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>((object->*met)());
    }
    inline int nargs() { return 0; }
    inline bool is_void() { return false; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE>(s, name); }

private:
    Method met;
};

template <typename Class> class const_CppMethod0<Class,void> : public CppMethod<Class> {
public:
    typedef void (Class::*Method)(void) const;
    typedef CppMethod<Class> method_class;
    const_CppMethod0( Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, SEXP*) {
        (object->*met)( );
        return R_NilValue;
    }
    inline int nargs() { return 0; }
    inline bool is_void() { return true; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type>(s, name); }

private:
    Method met;
};

%s

#endif
', paste(sapply(1:65 , fun), collapse = "\n") 
)

stopifnot(file.exists("inst/include/Rcpp/module/"))
writeLines(file, "inst/include/Rcpp/module/Module_generated_CppMethod.h" )
