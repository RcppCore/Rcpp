// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module_method_named_args.h:
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

#ifndef Rcpp_Module_method_named_args_h
#define Rcpp_Module_method_named_args_h

template <typename RESULT_TYPE>
self& method_named_args(const char* name_, RESULT_TYPE (Class::*fun)(map_named_args named_args), const char* docstring = 0) 
{
    AddNamedArgsMethod( name_, new CppMethod1_NamedArgs<Class,RESULT_TYPE>(fun), docstring);
    return *this;
}

template <typename RESULT_TYPE>
self& method_named_args(const char* name_, RESULT_TYPE (Class::*fun)(map_named_args named_args) const, const char* docstring = 0) 
{
    AddNamedArgsMethod(name_, new const_CppMethod1_NamedArgs<Class,RESULT_TYPE>(fun), docstring);
    return *this ;
}

template <typename RESULT_TYPE>
self& nonconst_method_named_args(const char* name_, RESULT_TYPE (Class::*fun)(map_named_args named_args), const char* docstring = 0) 
{
    AddNamedArgsMethod(name_, new CppMethod1_NamedArgs<Class,RESULT_TYPE>( fun ), docstring);
    return *this;
}

template <typename RESULT_TYPE>
self& const_method_named_args(const char* name_, RESULT_TYPE (Class::*fun)(map_named_args named_args) const, const char* docstring = 0)
{
    AddNamedArgsMethod(name_, new const_CppMethod1_NamedArgs<Class,RESULT_TYPE>( fun ), docstring);
    return *this;
}


template <typename RESULT_TYPE>
self& method_named_args(const char* name_, RESULT_TYPE (*fun)(Class*, map_named_args named_args), const char* docstring = 0)
{
    AddNamedArgsMethod(name_, new Pointer_CppMethod1_NamedArgs<Class,RESULT_TYPE>(fun), docstring);
    return *this;
}

template <typename RESULT_TYPE>
self& const_method_named_args(const char* name_, RESULT_TYPE (*fun)(const Class*, map_named_args named_args), const char* docstring = 0)
{
    AddNamedArgsMethod(name_, new Const_Pointer_CppMethod1_NamedArgs<Class,RESULT_TYPE>(fun), docstring);
    return *this ;
}

#endif