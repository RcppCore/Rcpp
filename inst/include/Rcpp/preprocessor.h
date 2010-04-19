// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// preprocessor.h: Rcpp R/C++ interface class library -- pre processor help
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

#ifndef Rcpp__PREPROCESSOR_h
#define Rcpp__PREPROCESSOR_h

#define RCPP_DECORATE(__FUN__) __FUN__##__rcpp__wrapper__

// res <- sapply( 0:65, function(i){
// 	txt <- sprintf( '
// #define RCPP_WRAPPER_%d(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(%s){     \\
// SEXP res = R_NilValue ;                                                            \\
// try{                                                                               \\
// 	res = __NAME__(%s) ;                                                           \\
// } catch( std::exception& __ex__ ){                                                 \\
// 	forward_exception_to_r( __ex__ ) ;                                             \\
// }                                                                                  \\
// return res ;                                                                       \\
// }', i, 
// 	if( i == 0 ) "" else paste( sprintf( "SEXP x%d", 0:(i-1) ), collapse = ", " ), 
// 	if( i == 0 ) "" else paste( sprintf( "x%d", 0:(i-1) ), collapse = ", " ) 
// 	)
// })
   



#define RCPP_WRAPPER_0(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__() ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_1(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_2(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_3(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_4(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_5(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_6(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_7(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_8(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_9(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_10(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_11(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_12(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_13(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_14(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_15(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_16(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_17(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_18(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_19(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_20(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_21(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_22(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_23(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_24(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_25(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_26(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_27(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_28(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_29(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_30(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_31(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_32(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_33(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_34(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_35(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_36(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_37(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_38(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_39(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_40(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_41(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_42(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_43(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_44(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_45(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_46(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_47(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_48(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_49(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_50(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_51(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_52(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_53(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_54(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_55(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_56(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_57(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_58(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_59(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_60(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_61(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_62(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_63(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_64(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#define RCPP_WRAPPER_65(__NAME__) extern "C" SEXP RCPP_DECORATE(__NAME__)(SEXP x0, SEXP x1, SEXP x2, SEXP x3, SEXP x4, SEXP x5, SEXP x6, SEXP x7, SEXP x8, SEXP x9, SEXP x10, SEXP x11, SEXP x12, SEXP x13, SEXP x14, SEXP x15, SEXP x16, SEXP x17, SEXP x18, SEXP x19, SEXP x20, SEXP x21, SEXP x22, SEXP x23, SEXP x24, SEXP x25, SEXP x26, SEXP x27, SEXP x28, SEXP x29, SEXP x30, SEXP x31, SEXP x32, SEXP x33, SEXP x34, SEXP x35, SEXP x36, SEXP x37, SEXP x38, SEXP x39, SEXP x40, SEXP x41, SEXP x42, SEXP x43, SEXP x44, SEXP x45, SEXP x46, SEXP x47, SEXP x48, SEXP x49, SEXP x50, SEXP x51, SEXP x52, SEXP x53, SEXP x54, SEXP x55, SEXP x56, SEXP x57, SEXP x58, SEXP x59, SEXP x60, SEXP x61, SEXP x62, SEXP x63, SEXP x64){     \
SEXP res = R_NilValue ;                                                            \
try{                                                                               \
res = __NAME__(x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24, x25, x26, x27, x28, x29, x30, x31, x32, x33, x34, x35, x36, x37, x38, x39, x40, x41, x42, x43, x44, x45, x46, x47, x48, x49, x50, x51, x52, x53, x54, x55, x56, x57, x58, x59, x60, x61, x62, x63, x64) ;                                                           \
} catch( std::exception& __ex__ ){                                                 \
forward_exception_to_r( __ex__ ) ;                                             \
}                                                                                  \
return res ;                                                                       \
}

#endif
