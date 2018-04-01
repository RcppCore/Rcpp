// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module_CppMethods_named_args.h: 
//
// Copyright (C) 2010 - 2018  Dirk Eddelbuettel, Romain Francois and Joris Goosen
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

#ifndef Rcpp_Module_CppMethods_named_args_h
#define Rcpp_Module_CppMethods_named_args_h

template <typename Class, typename RESULT_TYPE> class CppMethod1_NamedArgs : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (Class::*Method)(map_named_args named_args);
    typedef CppMethod<Class> method_class;
    typedef typename traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;
    
    CppMethod1_NamedArgs(Method m) : method_class(), met(m) {} 

    SEXP operator()(Class* object, map_named_args named_args) {
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>((object->*met)(named_args));
    }
    inline int nargs() { return 1; }
    inline bool is_void() { return false; }
    inline bool is_const() { return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,map_named_args>(s, name); }

private:
    Method met;
};

template <typename Class> class CppMethod1_NamedArgs<Class,void> : public CppMethod<Class> {
public:
    typedef void (Class::*Method)(map_named_args named_args);
    typedef CppMethod<Class> method_class;
    
    CppMethod1_NamedArgs( Method m) : method_class(), met(m) {} 

	SEXP operator()(Class* object, map_named_args named_args) {
		(object->*met)(named_args);
        return R_NilValue;
    }

    inline int nargs() { return 1; }
    inline bool is_void() { return true; }
    inline bool is_const() { return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type,map_named_args>(s, name); }

private:
    Method met;
};

template <typename Class, typename RESULT_TYPE> class const_CppMethod1_NamedArgs : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (Class::*Method)(map_named_args named_args) const;
    typedef CppMethod<Class> method_class;
    typedef typename Rcpp::traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;
    
    const_CppMethod1_NamedArgs(Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, map_named_args named_args) {
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>((object->*met)(named_args));
    }
    inline int nargs() { return 1; }
    inline bool is_void() { return false; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,map_named_args>(s, name); }

private:
    Method met;
} ;
    
template < typename Class> class const_CppMethod1_NamedArgs<Class,void> : public CppMethod<Class> {
public:
    typedef void (Class::*Method)(map_named_args named_args) const;
    typedef CppMethod<Class> method_class;
    
    const_CppMethod1_NamedArgs(Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, map_named_args named_args) {
		(object->*met)(named_args);
        return R_NilValue;
    }
    inline int nargs() { return 1; }
    inline bool is_void() { return true; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name ) { Rcpp::signature<void_type,map_named_args>(s, name); }

private:
    Method met ;
} ;



template <typename Class, typename RESULT_TYPE> class Pointer_CppMethod1_NamedArgs : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (*Method)(Class*, map_named_args named_args);
    typedef CppMethod<Class> method_class;
    typedef typename Rcpp::traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;

    Pointer_CppMethod1_NamedArgs(Method m) : method_class(), met(m) {} 

    SEXP operator()(Class* object, map_named_args named_args) {
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>(met(object, named_args));
    }

    inline int nargs(){ return 1; }
    inline bool is_void(){ return false; }
    inline bool is_const(){ return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,map_named_args>(s, name); }

private:
    Method met;
};

template <typename Class> class Pointer_CppMethod1_NamedArgs<Class,void> : public CppMethod<Class> {
public:
    typedef void (*Method)(Class*, map_named_args named_args);
    typedef CppMethod<Class> method_class;

    Pointer_CppMethod1_NamedArgs(Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, map_named_args named_args) {
        met(object, named_args);
        return R_NilValue;
    }
    inline int nargs() { return 1; }
    inline bool is_void() { return true; }
    inline bool is_const() { return false; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type,map_named_args>(s, name); }

private:
    Method met;
};


// const

template <typename Class, typename RESULT_TYPE> class Const_Pointer_CppMethod1_NamedArgs : public CppMethod<Class> {
public:
    typedef RESULT_TYPE (*Method)(const Class*, map_named_args named_args);
    typedef CppMethod<Class> method_class;
    typedef typename Rcpp::traits::remove_const_and_reference<RESULT_TYPE>::type CLEANED_RESULT_TYPE;

    Const_Pointer_CppMethod1_NamedArgs(Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, map_named_args named_args) {
        return Rcpp::module_wrap<CLEANED_RESULT_TYPE>(met(object, named_args));
    }
    inline int nargs() { return 1; }
    inline bool is_void() { return false; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,map_named_args>(s, name); }

private:
    Method met;
};

template <typename Class> class Const_Pointer_CppMethod1_NamedArgs<Class,void> : public CppMethod<Class> {
public:
    typedef void (*Method)(const Class*, map_named_args named_args);
    typedef CppMethod<Class> method_class;

    Const_Pointer_CppMethod1_NamedArgs( Method m) : method_class(), met(m) {} 
    SEXP operator()(Class* object, map_named_args named_args) {
        met(object, named_args);
        return R_NilValue;
    }
    inline int nargs() { return 1; }
    inline bool is_void() { return true; }
    inline bool is_const() { return true; }
    inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type,map_named_args>(s, name); }

private:
    Method met;
};

#endif