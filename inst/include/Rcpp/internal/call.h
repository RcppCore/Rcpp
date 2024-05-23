#ifndef RCPP_INTERNAL_CALL_H
#define RCPP_INTERNAL_CALL_H

#include <Rcpp/traits/index_sequence.h>
#include <functional>

#if defined(HAS_VARIADIC_TEMPLATES) || defined(RCPP_USING_CXX11)

namespace Rcpp {
namespace internal {
// Utility struct so that we can pass a pack of types between functions
template <typename... T> struct type_pack {};


/**
 * Implementation function for calling a function with an array of SEXP arguments,
 * where each argument is converted to the appropriate type before being passed
 * to the function. A compile-time sequence (`Is...`) is used to index the SEXP array.
 * 
 * The intended types of the result and arguments are passed using the `type_pack`
 * struct, which allows the template to be used for both function pointers and
 * `std::function` objects.
 * 
 * This specialisation is for functions that return a value, whereas the below
 * is for void-returning functions.
 * 
 * The "* = nullptr" default argument allows both templates to be well-defined
 * regardless of which one is used.
 */
template <typename F, typename RESULT_TYPE, typename... Us, int... Is,
            typename std::enable_if<!std::is_same<RESULT_TYPE, void>::value>::type* = nullptr>
SEXP call_impl(F fun, SEXP* args, type_pack<RESULT_TYPE, Us...>,
                traits::index_sequence<Is...>) {
    RESULT_TYPE res = fun((typename traits::input_parameter<Us>::type(args[Is]))...);
    return Rcpp::module_wrap<RESULT_TYPE>(res);
}

template <typename F, typename RESULT_TYPE, typename... Us, int... Is,
            typename std::enable_if<std::is_same<RESULT_TYPE, void>::value>::type* = nullptr>
SEXP call_impl(F fun, SEXP* args, type_pack<RESULT_TYPE, Us...>,
                traits::index_sequence<Is...>) {
    fun((typename traits::input_parameter<Us>::type(args[Is]))...);
    return R_NilValue;
}
} // namespace internal


template <typename RESULT_TYPE, typename... Us>
SEXP call(RESULT_TYPE (*fun)(Us...), SEXP* args) {
    return internal::call_impl(fun, args,
                                internal::type_pack<RESULT_TYPE, Us...>{},
                                traits::make_index_sequence<sizeof...(Us)>{});
}

template <typename RESULT_TYPE, typename... Us>
SEXP call(const std::function<RESULT_TYPE(Us...)> &fun, SEXP* args) {
    return internal::call_impl(fun, args,
                                internal::type_pack<RESULT_TYPE, Us...>{},
                                traits::make_index_sequence<sizeof...(Us)>{});
}

} // namespace Rcpp

#endif

#endif
