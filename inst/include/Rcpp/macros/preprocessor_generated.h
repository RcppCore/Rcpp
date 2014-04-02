// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
// :tabSize=4:indentSize=4:noTabs=true:folding=explicit:collapseFolds=1:
// preprocessor_generated.h: Rcpp R/C++ interface class library -- pre processor help
//
// Copyright (C) 2010 - 2013 Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPP__PREPROCESSOR_GENERATED_H
#define RCPP__PREPROCESSOR_GENERATED_H

// {{{ RCPP_FUNCTION


#define RCPP_FUNCTION_0(__OUT__,__NAME__)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 0 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)() ;               \
extern "C" SEXP __NAME__(){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_0 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)() ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)()

#define RCPP_FUNCTION_1(__OUT__,__NAME__, ___0)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 1 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0) ;               \
extern "C" SEXP __NAME__(SEXP x0){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_1 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0)

#define RCPP_FUNCTION_2(__OUT__,__NAME__, ___0, ___1)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 2 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_2 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1)

#define RCPP_FUNCTION_3(__OUT__,__NAME__, ___0, ___1, ___2)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 3 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_3 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2)

#define RCPP_FUNCTION_4(__OUT__,__NAME__, ___0, ___1, ___2, ___3)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 4 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_4 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3)

#define RCPP_FUNCTION_5(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 5 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_5 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4)

#define RCPP_FUNCTION_6(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 6 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_6 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5)

#define RCPP_FUNCTION_7(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 7 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_7 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6)

#define RCPP_FUNCTION_8(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 8 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_8 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7)

#define RCPP_FUNCTION_9(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 9 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_9 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8)

#define RCPP_FUNCTION_10(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 10 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_10 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9)

#define RCPP_FUNCTION_11(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 11 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_11 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10)

#define RCPP_FUNCTION_12(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 12 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_12 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11)

#define RCPP_FUNCTION_13(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 13 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_13 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12)

#define RCPP_FUNCTION_14(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 14 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_14 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13)

#define RCPP_FUNCTION_15(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 15 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_15 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14)

#define RCPP_FUNCTION_16(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 16 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_16 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15)

#define RCPP_FUNCTION_17(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 17 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_17 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16)

#define RCPP_FUNCTION_18(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 18 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_18 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17)

#define RCPP_FUNCTION_19(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 19 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_19 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18)

#define RCPP_FUNCTION_20(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 20 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_20 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19)

#define RCPP_FUNCTION_21(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 21 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_21 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20)

#define RCPP_FUNCTION_22(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 22 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_22 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21)

#define RCPP_FUNCTION_23(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 23 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_23 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22)

#define RCPP_FUNCTION_24(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 24 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_24 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23)

#define RCPP_FUNCTION_25(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 25 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_25 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24)

#define RCPP_FUNCTION_26(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 26 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_26 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25)

#define RCPP_FUNCTION_27(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 27 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_27 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26)

#define RCPP_FUNCTION_28(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 28 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_28 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27)

#define RCPP_FUNCTION_29(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 29 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_29 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28)

#define RCPP_FUNCTION_30(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 30 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_30 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29)

#define RCPP_FUNCTION_31(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 31 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_31 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30)

#define RCPP_FUNCTION_32(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 32 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_32 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31)

#define RCPP_FUNCTION_33(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 33 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_33 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32)

#define RCPP_FUNCTION_34(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 34 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_34 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33)

#define RCPP_FUNCTION_35(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 35 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_35 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34)

#define RCPP_FUNCTION_36(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 36 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_36 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35)

#define RCPP_FUNCTION_37(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 37 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_37 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36)

#define RCPP_FUNCTION_38(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 38 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_38 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37)

#define RCPP_FUNCTION_39(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 39 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_39 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38)

#define RCPP_FUNCTION_40(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 40 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_40 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39)

#define RCPP_FUNCTION_41(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 41 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_41 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40)

#define RCPP_FUNCTION_42(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 42 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_42 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41)

#define RCPP_FUNCTION_43(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 43 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_43 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42)

#define RCPP_FUNCTION_44(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 44 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_44 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43)

#define RCPP_FUNCTION_45(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 45 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_45 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44)

#define RCPP_FUNCTION_46(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 46 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_46 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45)

#define RCPP_FUNCTION_47(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 47 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_47 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46)

#define RCPP_FUNCTION_48(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 48 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_48 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47)

#define RCPP_FUNCTION_49(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 49 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_49 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48)

#define RCPP_FUNCTION_50(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 50 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_50 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49)

#define RCPP_FUNCTION_51(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 51 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_51 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50)

#define RCPP_FUNCTION_52(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 52 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_52 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51)

#define RCPP_FUNCTION_53(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 53 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_53 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52)

#define RCPP_FUNCTION_54(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 54 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_54 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53)

#define RCPP_FUNCTION_55(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 55 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_55 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54)

#define RCPP_FUNCTION_56(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 56 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_56 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55)

#define RCPP_FUNCTION_57(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 57 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_57 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56)

#define RCPP_FUNCTION_58(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 58 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_58 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57)

#define RCPP_FUNCTION_59(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 59 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_59 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58)

#define RCPP_FUNCTION_60(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 60 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_60 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59)

#define RCPP_FUNCTION_61(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 61 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_61 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60)

#define RCPP_FUNCTION_62(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 62 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_62 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61)

#define RCPP_FUNCTION_63(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 63 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61, #___62                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_63 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62)

#define RCPP_FUNCTION_64(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 64 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61, #___62, #___63                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_64 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63)

#define RCPP_FUNCTION_65(__OUT__,__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64)        \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 65 ,                             \
        _["output"] = #__OUT__ ,                       \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61, #___62, #___63, #___64                                       \
        	) ) ;                                    \
    info.attr( "class" ) = "rcppfunctioninfo" ;      \
    return info ;                                   \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64) ;               \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63, SEXP x64){                       \
SEXP res = R_NilValue ;                             \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_65 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ), ::Rcpp::internal::converter( x64 )) ) ; \
return res ;                                        \
END_RCPP                                            \
}                                                   \
__OUT__ RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64)

// }}}

// {{{ RCPP_FUNCTION_VOID


#define RCPP_FUNCTION_VOID_0(__NAME__)           \
void RCPP_DECORATE(__NAME__)() ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 0 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_0 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)() ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)()

#define RCPP_FUNCTION_VOID_1(__NAME__, ___0)           \
void RCPP_DECORATE(__NAME__)(___0) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 1 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_1 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0)

#define RCPP_FUNCTION_VOID_2(__NAME__, ___0, ___1)           \
void RCPP_DECORATE(__NAME__)(___0, ___1) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 2 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_2 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1)

#define RCPP_FUNCTION_VOID_3(__NAME__, ___0, ___1, ___2)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 3 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_3 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2)

#define RCPP_FUNCTION_VOID_4(__NAME__, ___0, ___1, ___2, ___3)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 4 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_4 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3)

#define RCPP_FUNCTION_VOID_5(__NAME__, ___0, ___1, ___2, ___3, ___4)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 5 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_5 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4)

#define RCPP_FUNCTION_VOID_6(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 6 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_6 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5)

#define RCPP_FUNCTION_VOID_7(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 7 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_7 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6)

#define RCPP_FUNCTION_VOID_8(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 8 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_8 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7)

#define RCPP_FUNCTION_VOID_9(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 9 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_9 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8)

#define RCPP_FUNCTION_VOID_10(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 10 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_10 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9)

#define RCPP_FUNCTION_VOID_11(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 11 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_11 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10)

#define RCPP_FUNCTION_VOID_12(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 12 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_12 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11)

#define RCPP_FUNCTION_VOID_13(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 13 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_13 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12)

#define RCPP_FUNCTION_VOID_14(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 14 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_14 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13)

#define RCPP_FUNCTION_VOID_15(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 15 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_15 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14)

#define RCPP_FUNCTION_VOID_16(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 16 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_16 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15)

#define RCPP_FUNCTION_VOID_17(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 17 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_17 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16)

#define RCPP_FUNCTION_VOID_18(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 18 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_18 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17)

#define RCPP_FUNCTION_VOID_19(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 19 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_19 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18)

#define RCPP_FUNCTION_VOID_20(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 20 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_20 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19)

#define RCPP_FUNCTION_VOID_21(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 21 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_21 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20)

#define RCPP_FUNCTION_VOID_22(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 22 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_22 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21)

#define RCPP_FUNCTION_VOID_23(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 23 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_23 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22)

#define RCPP_FUNCTION_VOID_24(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 24 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_24 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23)

#define RCPP_FUNCTION_VOID_25(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 25 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_25 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24)

#define RCPP_FUNCTION_VOID_26(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 26 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_26 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25)

#define RCPP_FUNCTION_VOID_27(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 27 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_27 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26)

#define RCPP_FUNCTION_VOID_28(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 28 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_28 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27)

#define RCPP_FUNCTION_VOID_29(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 29 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_29 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28)

#define RCPP_FUNCTION_VOID_30(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 30 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_30 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29)

#define RCPP_FUNCTION_VOID_31(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 31 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_31 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30)

#define RCPP_FUNCTION_VOID_32(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 32 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_32 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31)

#define RCPP_FUNCTION_VOID_33(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 33 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_33 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32)

#define RCPP_FUNCTION_VOID_34(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 34 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_34 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33)

#define RCPP_FUNCTION_VOID_35(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 35 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_35 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34)

#define RCPP_FUNCTION_VOID_36(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 36 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_36 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35)

#define RCPP_FUNCTION_VOID_37(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 37 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_37 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36)

#define RCPP_FUNCTION_VOID_38(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 38 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_38 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37)

#define RCPP_FUNCTION_VOID_39(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 39 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_39 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38)

#define RCPP_FUNCTION_VOID_40(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 40 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_40 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39)

#define RCPP_FUNCTION_VOID_41(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 41 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_41 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40)

#define RCPP_FUNCTION_VOID_42(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 42 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_42 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41)

#define RCPP_FUNCTION_VOID_43(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 43 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_43 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42)

#define RCPP_FUNCTION_VOID_44(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 44 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_44 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43)

#define RCPP_FUNCTION_VOID_45(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 45 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_45 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44)

#define RCPP_FUNCTION_VOID_46(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 46 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_46 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45)

#define RCPP_FUNCTION_VOID_47(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 47 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_47 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46)

#define RCPP_FUNCTION_VOID_48(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 48 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_48 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47)

#define RCPP_FUNCTION_VOID_49(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 49 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_49 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48)

#define RCPP_FUNCTION_VOID_50(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 50 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_50 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49)

#define RCPP_FUNCTION_VOID_51(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 51 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_51 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50)

#define RCPP_FUNCTION_VOID_52(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 52 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_52 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51)

#define RCPP_FUNCTION_VOID_53(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 53 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_53 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52)

#define RCPP_FUNCTION_VOID_54(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 54 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_54 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53)

#define RCPP_FUNCTION_VOID_55(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 55 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_55 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54)

#define RCPP_FUNCTION_VOID_56(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 56 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_56 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55)

#define RCPP_FUNCTION_VOID_57(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 57 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_57 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56)

#define RCPP_FUNCTION_VOID_58(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 58 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_58 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57)

#define RCPP_FUNCTION_VOID_59(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 59 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_59 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58)

#define RCPP_FUNCTION_VOID_60(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 60 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_60 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59)

#define RCPP_FUNCTION_VOID_61(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 61 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_61 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60)

#define RCPP_FUNCTION_VOID_62(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 62 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_62 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61)

#define RCPP_FUNCTION_VOID_63(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 63 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61, #___62                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_63 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62)

#define RCPP_FUNCTION_VOID_64(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 64 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61, #___62, #___63                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_64 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63)

#define RCPP_FUNCTION_VOID_65(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64)           \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64) ;                  \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \
    using Rcpp::_ ;                                 \
	Rcpp::List info = Rcpp::List::create(           \
        _["n"]   = 65 ,                             \
        _["output"] = R_NilValue ,                     \
        _["input"]  = Rcpp::CharacterVector::create(   \
        	#___0, #___1, #___2, #___3, #___4, #___5, #___6, #___7, #___8, #___9, #___10, #___11, #___12, #___13, #___14, #___15, #___16, #___17, #___18, #___19, #___20, #___21, #___22, #___23, #___24, #___25, #___26, #___27, #___28, #___29, #___30, #___31, #___32, #___33, #___34, #___35, #___36, #___37, #___38, #___39, #___40, #___41, #___42, #___43, #___44, #___45, #___46, #___47, #___48, #___49, #___50, #___51, #___52, #___53, #___54, #___55, #___56, #___57, #___58, #___59, #___60, #___61, #___62, #___63, #___64                                       \
        	) );                                      \
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \
    return info ;                                   \
}                                                   \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63, SEXP x64){                       \
BEGIN_RCPP                                          \
REprintf("  RCPP_FUNCTION_VOID_65 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
RCPP_DECORATE(__NAME__)(::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ), ::Rcpp::internal::converter( x64 )) ;                       \
END_RCPP                                            \
}                                                   \
void RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64)

// }}}

// {{{ RCPP_XP_METHOD


#define RCPP_XP_METHOD_0(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 0 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp  ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_0 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__(  ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_1(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 1 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_1 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_2(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 2 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_2 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_3(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 3 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_3 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_4(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 4 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_4 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_5(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 5 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_5 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_6(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 6 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_6 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_7(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 7 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_7 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_8(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 8 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_8 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_9(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 9 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_9 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_10(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 10 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_10 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_11(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 11 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_11 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_12(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 12 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_12 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_13(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 13 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_13 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_14(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 14 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_14 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_15(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 15 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_15 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_16(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 16 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_16 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_17(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 17 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_17 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_18(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 18 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_18 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_19(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 19 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_19 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_20(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 20 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_20 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_21(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 21 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_21 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_22(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 22 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_22 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_23(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 23 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_23 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_24(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 24 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_24 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_25(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 25 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_25 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_26(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 26 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_26 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_27(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 27 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_27 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_28(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 28 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_28 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_29(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 29 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_29 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_30(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 30 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_30 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_31(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 31 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_31 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_32(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 32 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_32 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_33(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 33 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_33 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_34(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 34 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_34 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_35(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 35 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_35 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_36(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 36 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_36 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_37(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 37 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_37 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_38(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 38 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_38 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_39(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 39 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_39 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_40(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 40 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_40 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_41(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 41 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_41 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_42(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 42 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_42 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_43(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 43 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_43 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_44(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 44 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_44 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_45(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 45 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_45 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_46(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 46 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_46 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_47(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 47 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_47 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_48(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 48 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_48 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_49(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 49 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_49 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_50(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 50 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_50 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_51(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 51 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_51 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_52(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 52 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_52 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_53(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 53 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_53 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_54(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 54 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_54 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_55(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 55 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_55 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_56(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 56 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_56 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_57(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 57 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_57 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_58(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 58 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_58 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_59(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 59 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_59 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_60(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 60 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_60 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_61(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 61 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_61 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_62(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 62 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_62 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_63(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 63 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_63 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_64(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 64 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_64 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ) ) ) ;           \
END_RCPP                                                    \
}


#define RCPP_XP_METHOD_65(__NAME__,__CLASS__,__METHOD__ )   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 65 ,                                  \
        _["class"]  = #__CLASS__   ,                        \
        _["method"] = #__METHOD__                           \
        ) ;                                              \
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63, SEXP x64 ){                     \
BEGIN_RCPP                                                  \
    REprintf("  RCPP_XP_METHOD_65 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \
	return ::Rcpp::wrap( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ), ::Rcpp::internal::converter( x64 ) ) ) ;           \
END_RCPP                                                    \
}


// }}}

// {{{ RCPP_XP_METHOD_VOID


#define RCPP_XP_METHOD_VOID_0(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 0 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp  ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_0 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__(  ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_1(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 1 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_1 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_2(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 2 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_2 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_3(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 3 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_3 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_4(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 4 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_4 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_5(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 5 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_5 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_6(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 6 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_6 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_7(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 7 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_7 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_8(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 8 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_8 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_9(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 9 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_9 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_10(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 10 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_10 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_11(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 11 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_11 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_12(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 12 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_12 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_13(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 13 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_13 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_14(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 14 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_14 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_15(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 15 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_15 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_16(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 16 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_16 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_17(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 17 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_17 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_18(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 18 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_18 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_19(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 19 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_19 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_20(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 20 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_20 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_21(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 21 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_21 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_22(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 22 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_22 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_23(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 23 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_23 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_24(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 24 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_24 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_25(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 25 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_25 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_26(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 26 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_26 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_27(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 27 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_27 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_28(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 28 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_28 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_29(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 29 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_29 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_30(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 30 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_30 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_31(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 31 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_31 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_32(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 32 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_32 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_33(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 33 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_33 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_34(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 34 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_34 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_35(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 35 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_35 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_36(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 36 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_36 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_37(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 37 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_37 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_38(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 38 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_38 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_39(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 39 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_39 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_40(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 40 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_40 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_41(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 41 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_41 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_42(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 42 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_42 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_43(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 43 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_43 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_44(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 44 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_44 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_45(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 45 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_45 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_46(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 46 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_46 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_47(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 47 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_47 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_48(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 48 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_48 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_49(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 49 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_49 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_50(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 50 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_50 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_51(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 51 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_51 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_52(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 52 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_52 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_53(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 53 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_53 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_54(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 54 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_54 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_55(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 55 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_55 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_56(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 56 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_56 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_57(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 57 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_57 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_58(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 58 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_58 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_59(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 59 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_59 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_60(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 60 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_60 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_61(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 61 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_61 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_62(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 62 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_62 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_63(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 63 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_63 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_64(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 64 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_64 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ) ) ;                                            \
END_RCPP                                                           \
}


#define RCPP_XP_METHOD_VOID_65(__NAME__,__CLASS__,__METHOD__)    \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 65 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__                           \
        ) ;                                                 \
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63, SEXP x64 ){                            \
BEGIN_RCPP                                                         \
REprintf("  RCPP_XP_METHOD_VOID_65 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \
ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ), ::Rcpp::internal::converter( x64 ) ) ;                                            \
END_RCPP                                                           \
}


// }}}

// {{{ RCPP_XP_METHOD_CAST


#define RCPP_XP_METHOD_CAST_0(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 0 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp  ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_0 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__(  ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_1(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 1 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_1 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_2(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 2 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_2 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_3(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 3 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_3 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_4(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 4 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_4 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_5(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 5 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_5 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_6(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 6 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_6 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_7(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 7 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_7 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_8(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 8 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_8 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_9(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 9 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_9 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_10(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 10 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_10 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_11(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 11 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_11 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_12(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 12 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_12 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_13(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 13 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_13 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_14(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 14 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_14 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_15(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 15 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_15 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_16(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 16 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_16 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_17(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 17 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_17 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_18(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 18 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_18 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_19(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 19 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_19 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_20(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 20 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_20 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_21(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 21 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_21 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_22(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 22 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_22 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_23(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 23 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_23 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_24(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 24 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_24 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_25(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 25 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_25 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_26(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 26 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_26 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_27(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 27 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_27 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_28(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 28 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_28 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_29(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 29 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_29 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_30(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 30 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_30 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_31(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 31 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_31 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_32(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 32 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_32 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_33(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 33 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_33 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_34(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 34 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_34 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_35(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 35 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_35 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_36(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 36 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_36 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_37(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 37 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_37 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_38(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 38 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_38 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_39(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 39 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_39 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_40(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 40 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_40 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_41(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 41 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_41 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_42(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 42 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_42 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_43(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 43 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_43 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_44(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 44 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_44 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_45(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 45 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_45 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_46(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 46 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_46 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_47(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 47 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_47 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_48(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 48 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_48 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_49(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 49 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_49 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_50(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 50 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_50 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_51(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 51 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_51 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_52(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 52 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_52 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_53(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 53 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_53 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_54(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 54 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_54 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_55(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 55 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_55 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_56(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 56 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_56 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_57(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 57 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_57 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_58(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 58 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_58 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_59(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 59 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_59 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_60(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 60 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_60 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_61(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 61 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_61 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_62(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 62 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_62 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_63(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 63 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_63 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_64(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 64 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_64 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ) ) ) ) ;\
END_RCPP                                                     \
}


#define RCPP_XP_METHOD_CAST_65(__NAME__,__CLASS__,__METHOD__,__CAST__)   \
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \
    using Rcpp::_ ;                                         \
	Rcpp::List info = Rcpp::List::create(                    \
        _["n"]      = 65 ,                                  \
        _["class"]  = #__CLASS__  ,                         \
        _["method"] = #__METHOD__ ,                          \
        _["cast"]   = #__CAST__                             \
        )   ;                                              \
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \
    return info   ;                                         \
}                                                           \
extern "C" SEXP __NAME__( SEXP xp ,  SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63, SEXP x64 ){                      \
BEGIN_RCPP                                                   \
	REprintf("  RCPP_XP_METHOD_CAST_65 is deprecated, it will be removed permanently in july 2014\n" ) ;     \
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( ::Rcpp::internal::converter( x0 ), ::Rcpp::internal::converter( x1 ), ::Rcpp::internal::converter( x2 ), ::Rcpp::internal::converter( x3 ), ::Rcpp::internal::converter( x4 ), ::Rcpp::internal::converter( x5 ), ::Rcpp::internal::converter( x6 ), ::Rcpp::internal::converter( x7 ), ::Rcpp::internal::converter( x8 ), ::Rcpp::internal::converter( x9 ), ::Rcpp::internal::converter( x10 ), ::Rcpp::internal::converter( x11 ), ::Rcpp::internal::converter( x12 ), ::Rcpp::internal::converter( x13 ), ::Rcpp::internal::converter( x14 ), ::Rcpp::internal::converter( x15 ), ::Rcpp::internal::converter( x16 ), ::Rcpp::internal::converter( x17 ), ::Rcpp::internal::converter( x18 ), ::Rcpp::internal::converter( x19 ), ::Rcpp::internal::converter( x20 ), ::Rcpp::internal::converter( x21 ), ::Rcpp::internal::converter( x22 ), ::Rcpp::internal::converter( x23 ), ::Rcpp::internal::converter( x24 ), ::Rcpp::internal::converter( x25 ), ::Rcpp::internal::converter( x26 ), ::Rcpp::internal::converter( x27 ), ::Rcpp::internal::converter( x28 ), ::Rcpp::internal::converter( x29 ), ::Rcpp::internal::converter( x30 ), ::Rcpp::internal::converter( x31 ), ::Rcpp::internal::converter( x32 ), ::Rcpp::internal::converter( x33 ), ::Rcpp::internal::converter( x34 ), ::Rcpp::internal::converter( x35 ), ::Rcpp::internal::converter( x36 ), ::Rcpp::internal::converter( x37 ), ::Rcpp::internal::converter( x38 ), ::Rcpp::internal::converter( x39 ), ::Rcpp::internal::converter( x40 ), ::Rcpp::internal::converter( x41 ), ::Rcpp::internal::converter( x42 ), ::Rcpp::internal::converter( x43 ), ::Rcpp::internal::converter( x44 ), ::Rcpp::internal::converter( x45 ), ::Rcpp::internal::converter( x46 ), ::Rcpp::internal::converter( x47 ), ::Rcpp::internal::converter( x48 ), ::Rcpp::internal::converter( x49 ), ::Rcpp::internal::converter( x50 ), ::Rcpp::internal::converter( x51 ), ::Rcpp::internal::converter( x52 ), ::Rcpp::internal::converter( x53 ), ::Rcpp::internal::converter( x54 ), ::Rcpp::internal::converter( x55 ), ::Rcpp::internal::converter( x56 ), ::Rcpp::internal::converter( x57 ), ::Rcpp::internal::converter( x58 ), ::Rcpp::internal::converter( x59 ), ::Rcpp::internal::converter( x60 ), ::Rcpp::internal::converter( x61 ), ::Rcpp::internal::converter( x62 ), ::Rcpp::internal::converter( x63 ), ::Rcpp::internal::converter( x64 ) ) ) ) ;\
END_RCPP                                                     \
}


// }}}

#endif

