#ifndef RCPP_TRAITS_INDEX_SEQUENCE_H
#define RCPP_TRAITS_INDEX_SEQUENCE_H


#if defined(HAS_VARIADIC_TEMPLATES) || defined(RCPP_USING_CXX11)

namespace Rcpp {
namespace traits {

template<int...> struct index_sequence {};

template<int N, int... Is>
struct make_index_sequence : make_index_sequence<N-1, N-1, Is...> {};

template<int... Is>
struct make_index_sequence<0, Is...> : index_sequence<Is...> {};

}
}

#endif

#endif
