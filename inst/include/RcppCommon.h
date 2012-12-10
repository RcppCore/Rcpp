// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// RcppCommon.h: Rcpp R/C++ interface class library -- common include and defines statements
//
// Copyright (C) 2008 - 2009 Dirk Eddelbuettel
// Copyright (C) 2009 - 2012 Dirk Eddelbuettel and Romain Francois
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

#ifndef RcppCommon_h
#define RcppCommon_h

#include <Rcpp/platform/compiler.h>

#include <Rcpp/config.h>
#include <Rcpp/macros/unroll.h>

void logTxtFunction(const char* file, const int line, const char* expression ) ;

/**
 * \brief Rcpp API
 */
namespace Rcpp{

    /**
     * \brief traits used to dispatch wrap
     */
    namespace traits{
    } // traits

    /**
     * \brief internal implementation details
     */
    namespace internal{     
    } // internal 
} // Rcpp

#include <Rcpp/module/macros.h>

#include <iterator>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
#include <deque>
#include <functional>
#include <numeric>
#include <algorithm>
#include <complex>
#include <limits>
#include <typeinfo>
#include <Rcpp/sprintf.h>

// include R headers, but set R_NO_REMAP and access everything via Rf_ prefixes
#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Complex.h>
#include <R_ext/Parse.h>
#include <R_ext/Rdynload.h>
#include <Rversion.h>
#define RCPP_GET_NAMES(x)       Rf_getAttrib(x, R_NamesSymbol)

inline SEXP Rcpp_lcons(SEXP car, SEXP cdr){
    PROTECT(car) ;
    car = Rf_lcons( car, cdr ) ; 
    UNPROTECT(1) ;
    return car ;
}
#include <Rcpp/lang.h>

#include <Rcpp/complex.h>

#include <Rcpp/barrier.h>

#define RcppExport extern "C"

RcppExport void init_Rcpp_routines(DllInfo*) ;

const char * sexp_to_name(int sexp_type); 

#include <Rcpp/exceptions.h>

namespace Rcpp{
    /* internal namespace for things not intended to be used by the user */
    namespace internal{     
        
        SEXP try_catch( SEXP expr, SEXP env );
        SEXP try_catch( SEXP expr );
        
    } // namespace internal 
    
    inline bool Rboolean_to_bool( int x){ return x == TRUE ; }
    inline bool int_to_bool(int x){ return x != 0 ; }
    inline bool double_to_bool(double x){ return x != 0.0 ; }
    inline bool Rbyte_to_bool(Rbyte x){ return x != static_cast<Rbyte>(0) ; }

} // namespace Rcpp

#include <Rcpp/macros/debug.h>

#define Rcpp_error(MESSAGE) throw Rcpp::exception( MESSAGE, __FILE__, __LINE__ ) 

namespace Rcpp {
	  inline void stop(const std::string& message) { throw Rcpp::exception(message.c_str()); }
} // namespace Rcpp

namespace Rcpp{
    template <typename T> class object ;
    class String ;
	namespace internal{
		template <typename Class> SEXP make_new_object( Class* ptr ) ;	
	}
}	

// DO NOT CHANGE THE ORDER OF THESE INCLUDES
#include <Rcpp/traits/integral_constant.h>
#include <Rcpp/traits/same_type.h>
#include <Rcpp/traits/named_object.h>
#include <Rcpp/Named.h>
#include <Rcpp/traits/is_convertible.h>
#include <Rcpp/traits/has_iterator.h>
#include <Rcpp/traits/expands_to_logical.h>
#include <Rcpp/traits/matrix_interface.h>
#include <Rcpp/traits/is_sugar_expression.h>
#include <Rcpp/traits/is_eigen_base.h>
#include <Rcpp/traits/has_na.h>
#include <Rcpp/traits/storage_type.h>
#include <Rcpp/traits/r_sexptype_traits.h>
#include <Rcpp/traits/storage_type.h>
#include <Rcpp/traits/comparator_type.h>
#include <Rcpp/traits/r_type_traits.h>
#include <Rcpp/traits/un_pointer.h>
#include <Rcpp/traits/is_pointer.h>
#include <Rcpp/traits/wrap_type_traits.h>
#include <Rcpp/traits/module_wrap_traits.h>
#include <Rcpp/traits/is_na.h>
#include <Rcpp/traits/if_.h>
#include <Rcpp/traits/get_na.h>
#include <Rcpp/traits/is_trivial.h>
#include <Rcpp/traits/init_type.h>

#include <Rcpp/traits/is_const.h>
#include <Rcpp/traits/is_reference.h>
#include <Rcpp/traits/remove_const.h>
#include <Rcpp/traits/remove_reference.h>
#include <Rcpp/traits/remove_const_and_reference.h>
#include <Rcpp/traits/result_of.h>

#include <Rcpp/internal/caster.h>
#include <Rcpp/internal/r_vector.h>
#include <Rcpp/r_cast.h>

#include <Rcpp/internal/wrap_forward.h>

#include <Rcpp/Date_forward.h>
#include <Rcpp/Datetime_forward.h>

#include <Rcpp/internal/export.h>
#include <Rcpp/traits/Exporter.h>
#include <Rcpp/internal/r_coerce.h>
#include <Rcpp/as.h>

#include <Rcpp/vector/VectorBase.h>
#include <Rcpp/vector/MatrixBase.h>

#include <Rcpp/internal/wrap.h>

#include <Rcpp/internal/ListInitialization.h>
#include <Rcpp/internal/Proxy_Iterator.h>
#include <Rcpp/internal/SEXP_Iterator.h>

#include <Rcpp/preprocessor.h>
#include <Rcpp/algo.h>

#include <Rcpp/sugar/sugar_forward.h>

#include <Rcpp/routines.h>
#include <Rcpp/cache.h>

// "Rcout" iostream class contributed by Jelmer Ypma
#include <Rcpp/iostream/Rstreambuf.h>
#include <Rcpp/iostream/Rostream.h>

#endif
