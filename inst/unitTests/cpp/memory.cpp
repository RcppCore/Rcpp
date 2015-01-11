#include <Rcpp.h>
using namespace Rcpp;

class DeleteNotifier : public std::exception {
  int _id;
public:
  DeleteNotifier(int id) : std::exception(), _id(id) { }
  virtual ~DeleteNotifier() _NOEXCEPT {
    Rprintf("deleting DeleteNotifier(%d)\n", _id);
  }
  virtual const char* what() const _NOEXCEPT {
    return "test notifier";
  }
};

//[[Rcpp::export]]
void testMemory1() {
  DeleteNotifier dn(1);
}

//[[Rcpp::export]]
void testMemory2() {
  try {
    DeleteNotifier dn(2);
    throw std::logic_error("test dn2");
  } 
  catch(std::exception& e) {
  }
}

//[[Rcpp::export(".testMemory3")]]
void testMemory3() {
  DeleteNotifier dn(3);
  throw std::logic_error("test dn3");
}

//[[Rcpp::export(".testMemory4")]]
void testMemory4() {
  try {
    throw DeleteNotifier(4);
  }
  catch(std::exception& e) {
  }
}

//[[Rcpp::export(".testMemory5")]]
void testMemory5() {
  throw DeleteNotifier(5);
}

/*** R
testMemory3 <- function() {
  tryCatch(.testMemory3(), error = function(e) {})
  invisible(NULL)
}

testMemory4 <- function() {
  tryCatch(.testMemory4(), error = function(e) {})
  invisible(NULL)
}

testMemory5 <- function() {
  tryCatch(.testMemory5(), error = function(e) {})
  invisible(NULL)
}

*/
