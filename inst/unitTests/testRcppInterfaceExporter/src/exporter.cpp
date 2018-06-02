#include "config.h"

#include <Rcpp.h>
#include "unwound.h"

// [[Rcpp::interfaces(r, cpp)]]

//' @export
// [[Rcpp::export]]
SEXP test_cpp_interface(SEXP x) {
  unwound_t stack_obj("cpp_interface_upstream");
  return Rcpp::Rcpp_fast_eval(x, R_GlobalEnv);
}
