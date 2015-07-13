#!/usr/bin/Rscript
#
# Generator for inst/include/Rcpp/module/Module_generated_CppFunction.h
#
# Copyright (C) 2010 - 2015  Dirk Eddelbuettel and Romain Francois

fun <- function(i) {

    index <- (1:i)-1
    collapse <- function(x, sep = ",") paste(x, collapse = sep)

txt <- sprintf( '
template <typename RESULT_TYPE, %s> class CppFunction%d : public CppFunction {
    public:

        CppFunction%d(RESULT_TYPE (*fun)(%s) , const char* docstring = 0) : CppFunction(docstring), ptr_fun(fun) {}

        SEXP operator()(SEXP* args) {
            %s
            return Rcpp::module_wrap<RESULT_TYPE>(ptr_fun(%s));
        }

        inline int nargs() { return %d; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,%s>(s, name); }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun ; }

    private:
        RESULT_TYPE (*ptr_fun)(%s) ;
};

template <%s>
class CppFunction%d<void,%s> : public CppFunction {
    public:
        CppFunction%d(void (*fun)(%s) , const char* docstring = 0) : CppFunction(docstring), ptr_fun(fun) {}

        SEXP operator()(SEXP* args) {
            %s
            ptr_fun(%s);
            return R_NilValue;
        }

        inline int nargs() { return %d; }
        inline bool is_void() { return true; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type,%s>(s, name); }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun; }

    private:
        void (*ptr_fun)(%s) ;
};



template <typename RESULT_TYPE, %s>
class CppFunction_WithFormals%d : public CppFunction {
    public:

        CppFunction_WithFormals%d(RESULT_TYPE (*fun)(%s) , Rcpp::List formals_, const char* docstring = 0) :
            CppFunction(docstring), formals(formals_), ptr_fun(fun) {}

        SEXP operator()(SEXP* args) {
            %s
            return Rcpp::module_wrap<RESULT_TYPE>(ptr_fun(%s));
        }

        inline int nargs() { return %d; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE,%s>(s, name); }
        SEXP get_formals() { return formals; }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun; }

    private:
        Rcpp::List formals;
        RESULT_TYPE (*ptr_fun)(%s);
};

template <%s>
class CppFunction_WithFormals%d<void,%s> : public CppFunction {
    public:
        CppFunction_WithFormals%d(void (*fun)(%s), Rcpp::List formals_, const char* docstring = 0) :
            CppFunction(docstring), formals(formals_), ptr_fun(fun) {}

        SEXP operator()(SEXP* args) {
            %s
            ptr_fun(%s);
            return R_NilValue;
        }

        inline int nargs() { return %d; }
        inline bool is_void() { return true; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type,%s>(s, name); }
        SEXP get_formals() { return formals; }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun; }

    private:
        Rcpp::List formals;
        void (*ptr_fun)(%s);
};
',
               collapse(sprintf("typename U%d", index)),
               i,
               i,
               collapse(sprintf("U%d", index)),
               collapse(sprintf("typename traits::input_parameter< U%d >::type x%d(args[%d]);",
                                index, index, index ), sep = "\n            "),
               collapse(sprintf("x%d", index)),
               i,
               collapse(sprintf("U%d", index)),
               collapse( sprintf( "U%d", index)),

               paste(sprintf("typename U%d", index), collapse = ", "),
               i,
               collapse(sprintf("U%d", index)),
               i,
               collapse(sprintf("U%d", index)),
               collapse(sprintf("typename traits::input_parameter< U%d >::type x%d(args[%d]);",
                                index, index, index), sep = "\n            " ),
               collapse(sprintf("x%d", index)),
               i,
               collapse(sprintf("U%d", index)),
               collapse(sprintf("U%d", index)),

               ## _ WithFormals
               collapse(sprintf("typename U%d", index)),
               i,
               i,
               collapse(sprintf("U%d", index)),
               collapse(sprintf("typename traits::input_parameter< U%d >::type x%d(args[%d]);",
                                index, index, index ), sep = "\n            " ),
               collapse(sprintf("x%d", index)),
               i,
               collapse(sprintf("U%d", index)),
               collapse(sprintf("U%d", index)),


               paste(sprintf("typename U%d", index), collapse = ", "),
               i,
               collapse(sprintf("U%d", index)),
               i,
               collapse(sprintf("U%d", index)),
               collapse(sprintf("typename traits::input_parameter< U%d >::type x%d(args[%d]);",
                                index, index, index), sep = "\n            " ),
               collapse(sprintf("x%d", index)),
               i,
               collapse(sprintf("U%d", index)),
               collapse(sprintf("U%d", index))
               )
}

file <- sprintf(
'// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// Module_generated_CppFunction.h: -- generated helper code for Modules
//                                    see rcpp-scripts repo for generator script
//
// Copyright (C) 2010 - 2015  Dirk Eddelbuettel and Romain Francois
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

#ifndef Rcpp_Module_generated_CppFunction_h
#define Rcpp_Module_generated_CppFunction_h

namespace Rcpp {

template <typename RESULT_TYPE>
class CppFunction0 : public CppFunction {
    public:
        CppFunction0(RESULT_TYPE (*fun)(void), const char* docstring = 0) : CppFunction(docstring), ptr_fun(fun) {}
        SEXP operator()(SEXP*) {
            return Rcpp::module_wrap<RESULT_TYPE>(ptr_fun());
        }

        inline int nargs() { return 0; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE>(s, name); }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun; }

    private:
        RESULT_TYPE (*ptr_fun)(void);
};


template <>
class CppFunction0<void> : public CppFunction {
    public:
        CppFunction0(void (*fun)(void), const char* docstring = 0) : CppFunction(docstring), ptr_fun(fun) {};

        SEXP operator()(SEXP*) {
            ptr_fun();
            return R_NilValue;
        }

        inline int nargs() { return 0; }
        inline bool is_void() { return true; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type>(s, name); }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun; }

    private:
        void (*ptr_fun)(void);
};


template <typename RESULT_TYPE>
class CppFunction_WithFormals0 : public CppFunction {
    public:
        CppFunction_WithFormals0(RESULT_TYPE (*fun)(void), Rcpp::List,  const char* docstring = 0) : CppFunction(docstring), ptr_fun(fun) {}
        SEXP operator()(SEXP*) {
            return Rcpp::module_wrap<RESULT_TYPE>(ptr_fun());
        }

        inline int nargs() { return 0; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<RESULT_TYPE>(s, name); }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun; }

    private:
        RESULT_TYPE (*ptr_fun)(void);
};


template <>
class CppFunction_WithFormals0<void> : public CppFunction {
    public:
        CppFunction_WithFormals0(void (*fun)(void), Rcpp::List, const char* docstring = 0) : CppFunction(docstring), ptr_fun(fun) {} ;

        SEXP operator()(SEXP*) {
            ptr_fun() ;
            return R_NilValue;
        }

        inline int nargs() { return 0; }
        inline bool is_void() { return true; }
        inline void signature(std::string& s, const char* name) { Rcpp::signature<void_type>(s, name); }
        inline DL_FUNC get_function_ptr() { return (DL_FUNC)ptr_fun; }

    private:
        void (*ptr_fun)(void) ;
};

%s

}

#endif
', paste(sapply( 1:65, fun), collapse = "\n")
    )

stopifnot(file.exists("inst/include/Rcpp/module/"))
writeLines(file, "inst/include/Rcpp/module/Module_generated_CppFunction.h")
