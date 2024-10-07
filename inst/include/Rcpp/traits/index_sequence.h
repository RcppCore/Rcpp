#ifndef RCPP_TRAITS_INDEX_SEQUENCE_H
#define RCPP_TRAITS_INDEX_SEQUENCE_H


#if defined(HAS_VARIADIC_TEMPLATES)

namespace Rcpp {
namespace traits {
  /**
   * C++11 implementations for index_sequence and make_index_sequence.
   * To avoid name conflicts or ambiguity when compiling with C++14 or later,
   * they should always be prefaced with `Rcpp::traits::` when used.
  */
  template <int...>
  struct index_sequence {};

  template <int N, int... Is>
  struct make_index_sequence : make_index_sequence<N-1, N-1, Is...> {};

  template <int... Is>
  struct make_index_sequence<0, Is...> : index_sequence<Is...> {};
}
}

#endif

#endif
