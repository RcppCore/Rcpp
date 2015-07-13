# 
# run this from the directory that contains Rcpp
#
# Rscript ../scripts/preprocessor.R
#

rcpp_function <- sapply( 0:65, function(i){
	txt <- sprintf( '
#define RCPP_FUNCTION_%d(__OUT__,__NAME__%s)        \\
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \\
    using Rcpp::_ ;                                 \\
	Rcpp::List info = Rcpp::List::create(           \\
        _["n"]   = %d ,                             \\
        _["output"] = #__OUT__ ,                       \\
        _["input"]  = Rcpp::CharacterVector::create(   \\
        	%s                                       \\
        	) ) ;                                    \\
    info.attr( "class" ) = "rcppfunctioninfo" ;      \\
    return info ;                                   \\
}                                                   \\
__OUT__ RCPP_DECORATE(__NAME__)(%s) ;               \\
extern "C" SEXP __NAME__(%s){                       \\
SEXP res = R_NilValue ;                             \\
BEGIN_RCPP                                          \\
REprintf("  RCPP_FUNCTION_%d is deprecated, it will be removed permanently in july 2014\\n" ) ;     \\
res = ::Rcpp::wrap( RCPP_DECORATE(__NAME__)(%s) ) ; \\
return res ;                                        \\
END_RCPP                                            \\
}                                                   \\
__OUT__ RCPP_DECORATE(__NAME__)(%s)', 
	i,
	if( i == 0 ) "" else paste( ",", paste( sprintf( "___%d", 0:(i-1)), collapse=", ") ),
	i, 
	if( i == 0 ) "" else paste( sprintf( "#___%d", 0:(i-1)), collapse=", "),
	if( i == 0 ) "" else paste( sprintf( "___%d", 0:(i-1)), collapse=", "),
	if( i == 0 ) "" else paste( sprintf( "SEXP x%d", 0:(i-1) ), collapse = ", " ), 
	i,
	if( i == 0 ) "" else paste( sprintf( "::Rcpp::internal::converter( x%d )", 0:(i-1) ), collapse = ", " ), 
	if( i == 0 ) "" else paste( sprintf( "___%d", 0:(i-1)), collapse=", ")
	)
})


rcpp_function_void <- sapply( 0:65, function(i){
	txt <- sprintf( '
#define RCPP_FUNCTION_VOID_%d(__NAME__%s)           \\
void RCPP_DECORATE(__NAME__)(%s) ;                  \\
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){         \\
    using Rcpp::_ ;                                 \\
	Rcpp::List info = Rcpp::List::create(           \\
        _["n"]   = %d ,                             \\
        _["output"] = R_NilValue ,                     \\
        _["input"]  = Rcpp::CharacterVector::create(   \\
        	%s                                       \\
        	) );                                      \\
    info.attr( "class" ) = "rcppfunctionvoidinfo";  \\
    return info ;                                   \\
}                                                   \\
extern "C" SEXP __NAME__(%s){                       \\
BEGIN_RCPP                                          \\
REprintf("  RCPP_FUNCTION_VOID_%d is deprecated, it will be removed permanently in july 2014\\n" ) ;     \\
RCPP_DECORATE(__NAME__)(%s) ;                       \\
END_RCPP                                            \\
}                                                   \\
void RCPP_DECORATE(__NAME__)(%s)', 
	i,
	if( i == 0 ) "" else paste( ",", paste( sprintf( "___%d", 0:(i-1)), collapse=", ") ),
	if( i == 0 ) "" else paste( sprintf( "___%d", 0:(i-1)), collapse=", "),
	i, 
	if( i == 0 ) "" else paste( sprintf( "#___%d", 0:(i-1)), collapse=", "),
	if( i == 0 ) "" else paste( sprintf( "SEXP x%d", 0:(i-1) ), collapse = ", " ), 
	i, 
	if( i == 0 ) "" else paste( sprintf( "::Rcpp::internal::converter( x%d )", 0:(i-1) ), collapse = ", " ), 
	if( i == 0 ) "" else paste( sprintf( "___%d", 0:(i-1)), collapse=", ")
	)
})

rcpp_xp_method <- sapply( 0:65, function(i){
	txt <- sprintf( '
#define RCPP_XP_METHOD_%d(__NAME__,__CLASS__,__METHOD__ )   \\
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \\
    using Rcpp::_ ;                                         \\
	Rcpp::List info = Rcpp::List::create(                    \\
        _["n"]      = %d ,                                  \\
        _["class"]  = #__CLASS__   ,                        \\
        _["method"] = #__METHOD__                           \\
        ) ;                                              \\
    info.attr( "class" ) = "rcppxpmethodinfo" ;             \\
    return info   ;                                         \\
}                                                           \\
extern "C" SEXP __NAME__( SEXP xp %s ){                     \\
BEGIN_RCPP                                                  \\
    REprintf("  RCPP_XP_METHOD_%d is deprecated, it will be removed permanently in july 2014\\n" ) ;     \\
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                       \\
	return ::Rcpp::wrap( ptr->__METHOD__( %s ) ) ;           \\
END_RCPP                                                    \\
}
', 
	i, 
	i, 
	if( i == 0 ) "" else paste( ", ", paste( sprintf( "SEXP x%d", 0:(i-1) ), collapse = ", " ) ), 
	i,
	if( i == 0 ) "" else paste( sprintf( "::Rcpp::internal::converter( x%d )", 0:(i-1)), collapse=", ")
)

})

rcpp_xp_method_cast <- sapply( 0:65, function(i){
	txt <- sprintf( '
#define RCPP_XP_METHOD_CAST_%d(__NAME__,__CLASS__,__METHOD__,__CAST__)   \\
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \\
    using Rcpp::_ ;                                         \\
	Rcpp::List info = Rcpp::List::create(                    \\
        _["n"]      = %d ,                                  \\
        _["class"]  = #__CLASS__  ,                         \\
        _["method"] = #__METHOD__ ,                          \\
        _["cast"]   = #__CAST__                             \\
        )   ;                                              \\
    info.attr( "class" ) = "rcppxpmethodcastinfo" ;         \\
    return info   ;                                         \\
}                                                           \\
extern "C" SEXP __NAME__( SEXP xp %s ){                      \\
BEGIN_RCPP                                                   \\
	REprintf("  RCPP_XP_METHOD_CAST_%d is deprecated, it will be removed permanently in july 2014\\n" ) ;     \\
	::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                        \\
	return ::Rcpp::wrap( __CAST__( ptr->__METHOD__( %s ) ) ) ;\\
END_RCPP                                                     \\
}
', 
	i, 
	i, 
	if( i == 0 ) "" else paste( ", ", paste( sprintf( "SEXP x%d", 0:(i-1) ), collapse = ", " ) ), 
	i, 
	if( i == 0 ) "" else paste( sprintf( "::Rcpp::internal::converter( x%d )", 0:(i-1)), collapse=", ")
)

})



rcpp_xp_method_void <- sapply( 0:65, function(i){
	txt <- sprintf( '
#define RCPP_XP_METHOD_VOID_%d(__NAME__,__CLASS__,__METHOD__)    \\
extern "C" SEXP RCPP_PP_CAT(__NAME__,__rcpp_info__)( ){                 \\
    using Rcpp::_ ;                                         \\
	Rcpp::List info = Rcpp::List::create(                    \\
        _["n"]      = %d ,                                  \\
        _["class"]  = #__CLASS__  ,                         \\
        _["method"] = #__METHOD__                           \\
        ) ;                                                 \\
    info.attr( "class" ) = "rcppxpmethodvoidinfo" ;         \\
    return info   ;                                         \\
}                                                           \\
extern "C" SEXP __NAME__( SEXP xp %s ){                            \\
BEGIN_RCPP                                                         \\
REprintf("  RCPP_XP_METHOD_VOID_%d is deprecated, it will be removed permanently in july 2014\\n" ) ;     \\
::Rcpp::XPtr< __CLASS__ > ptr(xp) ;                                  \\
ptr->__METHOD__( %s ) ;                                            \\
END_RCPP                                                           \\
}
', 
	i, 
	i, 
	if( i == 0 ) "" else paste( ", ", paste( sprintf( "SEXP x%d", 0:(i-1) ), collapse = ", " ) ), 
	i, 
	if( i == 0 ) "" else paste( sprintf( "::Rcpp::internal::converter( x%d )", 0:(i-1)), collapse=", ")
)

})


res <- c( 
"// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
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
", rcpp_function, "
// }}}

// {{{ RCPP_FUNCTION_VOID 
", rcpp_function_void, "
// }}}

// {{{ RCPP_XP_METHOD
", rcpp_xp_method, "
// }}}

// {{{ RCPP_XP_METHOD_VOID
", rcpp_xp_method_void, "
// }}}

// {{{ RCPP_XP_METHOD_CAST
", rcpp_xp_method_cast, "
// }}}

#endif
" )

writeLines( res, "Rcpp/inst/include/Rcpp/macros/preprocessor_generated.h" )

