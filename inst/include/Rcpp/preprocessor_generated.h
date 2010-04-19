
// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// preprocessor_generated.h: Rcpp R/C++ interface class library -- pre processor help
//
// Copyright (C) 2010 Dirk Eddelbuettel and Romain Francois
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


#define RCPP_FUNCTION_0(__NAME__)  \
SEXP RCPP_DECORATE(__NAME__)() ;     \
extern "C" SEXP __NAME__(){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)() ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)()

#define RCPP_FUNCTION_1(__NAME__, ___0)  \
SEXP RCPP_DECORATE(__NAME__)(___0) ;     \
extern "C" SEXP __NAME__(SEXP x0){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0)

#define RCPP_FUNCTION_2(__NAME__, ___0, ___1)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1)

#define RCPP_FUNCTION_3(__NAME__, ___0, ___1, ___2)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2)

#define RCPP_FUNCTION_4(__NAME__, ___0, ___1, ___2, ___3)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3)

#define RCPP_FUNCTION_5(__NAME__, ___0, ___1, ___2, ___3, ___4)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4)

#define RCPP_FUNCTION_6(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5)

#define RCPP_FUNCTION_7(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6)

#define RCPP_FUNCTION_8(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7)

#define RCPP_FUNCTION_9(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8)

#define RCPP_FUNCTION_10(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9)

#define RCPP_FUNCTION_11(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10)

#define RCPP_FUNCTION_12(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11)

#define RCPP_FUNCTION_13(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12)

#define RCPP_FUNCTION_14(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13)

#define RCPP_FUNCTION_15(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14)

#define RCPP_FUNCTION_16(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15)

#define RCPP_FUNCTION_17(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16)

#define RCPP_FUNCTION_18(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17)

#define RCPP_FUNCTION_19(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18)

#define RCPP_FUNCTION_20(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19)

#define RCPP_FUNCTION_21(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20)

#define RCPP_FUNCTION_22(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21)

#define RCPP_FUNCTION_23(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22)

#define RCPP_FUNCTION_24(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23)

#define RCPP_FUNCTION_25(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24)

#define RCPP_FUNCTION_26(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25)

#define RCPP_FUNCTION_27(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26)

#define RCPP_FUNCTION_28(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27)

#define RCPP_FUNCTION_29(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28)

#define RCPP_FUNCTION_30(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29)

#define RCPP_FUNCTION_31(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30)

#define RCPP_FUNCTION_32(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31)

#define RCPP_FUNCTION_33(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32)

#define RCPP_FUNCTION_34(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33)

#define RCPP_FUNCTION_35(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34)

#define RCPP_FUNCTION_36(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35)

#define RCPP_FUNCTION_37(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36)

#define RCPP_FUNCTION_38(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37)

#define RCPP_FUNCTION_39(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38)

#define RCPP_FUNCTION_40(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39)

#define RCPP_FUNCTION_41(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40)

#define RCPP_FUNCTION_42(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41)

#define RCPP_FUNCTION_43(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42)

#define RCPP_FUNCTION_44(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43)

#define RCPP_FUNCTION_45(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44)

#define RCPP_FUNCTION_46(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45)

#define RCPP_FUNCTION_47(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46)

#define RCPP_FUNCTION_48(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47)

#define RCPP_FUNCTION_49(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48)

#define RCPP_FUNCTION_50(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49)

#define RCPP_FUNCTION_51(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50)

#define RCPP_FUNCTION_52(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51)

#define RCPP_FUNCTION_53(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52)

#define RCPP_FUNCTION_54(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53)

#define RCPP_FUNCTION_55(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54)

#define RCPP_FUNCTION_56(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55)

#define RCPP_FUNCTION_57(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56)

#define RCPP_FUNCTION_58(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57)

#define RCPP_FUNCTION_59(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58)

#define RCPP_FUNCTION_60(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59)

#define RCPP_FUNCTION_61(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60)

#define RCPP_FUNCTION_62(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61)

#define RCPP_FUNCTION_63(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62)

#define RCPP_FUNCTION_64(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63)

#define RCPP_FUNCTION_65(__NAME__, ___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64)  \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64) ;     \
extern "C" SEXP __NAME__(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63, SEXP x64){          \
SEXP res = R_NilValue ;                 \
try{                                    \
	res = RCPP_DECORATE(__NAME__)(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64) ; \
} catch( std::exception& __ex__ ){      \
	forward_exception_to_r( __ex__ ) ;  \
}                                       \
return res ;                            \
}                                       \
SEXP RCPP_DECORATE(__NAME__)(___0, ___1, ___2, ___3, ___4, ___5, ___6, ___7, ___8, ___9, ___10, ___11, ___12, ___13, ___14, ___15, ___16, ___17, ___18, ___19, ___20, ___21, ___22, ___23, ___24, ___25, ___26, ___27, ___28, ___29, ___30, ___31, ___32, ___33, ___34, ___35, ___36, ___37, ___38, ___39, ___40, ___41, ___42, ___43, ___44, ___45, ___46, ___47, ___48, ___49, ___50, ___51, ___52, ___53, ___54, ___55, ___56, ___57, ___58, ___59, ___60, ___61, ___62, ___63, ___64)
#endif
