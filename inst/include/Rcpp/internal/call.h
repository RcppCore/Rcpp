#ifndef RCPP_INTERNAL_CALL_H
#define RCPP_INTERNAL_CALL_H

#include <Rcpp/traits/index_sequence.h>
#include <functional>

#if defined(HAS_VARIADIC_TEMPLATES) || defined(RCPP_USING_CXX11)

// Currently not declared in the Rcpp::internal namespace for compatibility
// with the generated call operators in InternalFunctionWithStdFunction_call.h
// but this should be changed in the future
namespace Rcpp {

template <typename RESULT_TYPE, typename... Us, int... Is>
RESULT_TYPE call_impl(const std::function<RESULT_TYPE(Us...)> &fun,
                        SEXP* args, traits::index_sequence<Is...>) {
    return fun((typename traits::input_parameter<Us>::type(args[Is]))...);
}

template <typename RESULT_TYPE, typename... Us, int... Is>
RESULT_TYPE call_impl(RESULT_TYPE (*fun)(Us...),
                        SEXP* args, traits::index_sequence<Is...>) {
    return fun((typename traits::input_parameter<Us>::type(args[Is]))...);
}


template <typename RESULT_TYPE, typename... Us>
RESULT_TYPE call(const std::function<RESULT_TYPE(Us...)> &fun, SEXP* args) {
    return call_impl(fun, args, traits::make_index_sequence<sizeof...(Us)>{});
}

template <typename RESULT_TYPE, typename... Us>
RESULT_TYPE call(RESULT_TYPE (*fun)(Us...), SEXP* args) {
    return call_impl(fun, args, traits::make_index_sequence<sizeof...(Us)>{});
}


template <typename... Us, int... Is>
void call_impl(const std::function<void(Us...)> &fun,
                        SEXP* args, traits::index_sequence<Is...>) {
    fun((typename traits::input_parameter<Us>::type(args[Is]))...);
}

template <typename... Us, int... Is>
void call_impl(void (*fun)(Us...),
                        SEXP* args, traits::index_sequence<Is...>) {
    fun((typename traits::input_parameter<Us>::type(args[Is]))...);
}


template <typename... Us>
void call(const std::function<void(Us...)> &fun, SEXP* args) {
    call_impl(fun, args, traits::make_index_sequence<sizeof...(Us)>{});
}

template <typename... Us>
void call(void (*fun)(Us...), SEXP* args) {
    call_impl(fun, args, traits::make_index_sequence<sizeof...(Us)>{});
}

} // namespace Rcpp

#endif

#endif
