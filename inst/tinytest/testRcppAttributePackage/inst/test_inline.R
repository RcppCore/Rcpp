# test 0
# This example should just run and not crash
Rcpp::sourceCpp(code='
#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export( rng = false, signature = {x=list("{A}", "B"), verbose = getOption("verbose")}, invisible = TRUE )]]
List test_inline(List x, bool verbose) {
  if(x.size() > 0) {
    CharacterVector first_element = x[0];
    return List::create(first_element, verbose);
  } else {
      return List::create(verbose);
  }
}')
expect_equal(test_inline(), list("{A}", FALSE))
options(verbose=TRUE)
expect_equal(test_inline(), list("{A}", TRUE))
options(verbose=FALSE)

# test 1, from Enchufa2
# The verbose argument should be replaced with FALSE
Rcpp::sourceCpp(code='
#include <Rcpp.h>
using namespace Rcpp;
// [[Rcpp::export( rng = false, signature = {x=list("{A}", "B"), verbose=FALSE} )]]
List test_inline(List x, bool verbose=true) {
  if(x.size() > 0) {
    CharacterVector first_element = x[0];
    return List::create(first_element, verbose);
  } else {
      return List::create(verbose);
  }
}')
expect_equal(test_inline(), list("{A}", FALSE))

# test 2, from Enchufa2
# This second example should not compile because of missing parameter verbose
expect_error({
  Rcpp::sourceCpp(code='
  #include <Rcpp.h>
  using namespace Rcpp;
  // [[Rcpp::export( rng = false, signature = {x=list("{A}", "B")} )]]
  List test_inline(List x, bool verbose=true) {
    if(x.size() > 0) {
      CharacterVector first_element = x[0];
      return List::create(first_element, verbose);
    } else {
        return List::create(verbose);
    }
  }')
})

# test 3, from Enchufa2
# This third example should not compile because of missing end bracket }
# The bracket within the signature is taken as the end bracket, which results in 
# invalid R code. There are some additional warnings due to the incorrect syntax
suppressWarnings({
  expect_error({
    Rcpp::sourceCpp(code='
    #include <Rcpp.h>
    using namespace Rcpp;
    // [[Rcpp::export( rng = false, signature = {x=list("{A}", "B"), verbose=FALSE )]]
    List test_inline(List x, bool verbose) {
      if(x.size() > 0) {
        CharacterVector first_element = x[0];
        return List::create(first_element, verbose);
      } else {
          return List::create(verbose);
      }
    }', verbose=T)
  })
})
expect_error(result)

# test 4, from Enchufa2
# This 4th example is missing the end bracket and will not compile
expect_error({
  Rcpp::sourceCpp(code='
  #include <Rcpp.h>
  using namespace Rcpp;
  // [[Rcpp::export( rng = false, signature = {x=list("A", "B"), verbose=FALSE )]]
  List test_inline(List x, bool verbose) {
    if(x.size() > 0) {
      CharacterVector first_element = x[0];
      return List::create(first_element, verbose);
    } else {
        return List::create(verbose);
    }
  }')
})

# This 5th example has brackets but incorrect R syntax
expect_error({
  Rcpp::sourceCpp(code='
  #include <Rcpp.h>
  using namespace Rcpp;
  // [[Rcpp::export( rng = false, signature = {x=list("A", ###, verbose=FALSE} )]]
  List test_inline(List x, bool verbose) {
    if(x.size() > 0) {
      CharacterVector first_element = x[0];
      return List::create(first_element, verbose);
    } else {
        return List::create(verbose);
    }
  }')
})

# This 6th example is missing a parameter in the signature
expect_error({
  Rcpp::sourceCpp(code='
  #include <Rcpp.h>
  using namespace Rcpp;
  // [[Rcpp::export( rng = false, signature = {x=list("A", "B")} )]]
  List test_inline(List x, bool verbose) {
    if(x.size() > 0) {
      CharacterVector first_element = x[0];
      return List::create(first_element, verbose);
    } else {
        return List::create(verbose);
    }
  }')
})


