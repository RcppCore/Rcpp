#include <Rcpp.h>
using namespace Rcpp;

// Test 4.1: Named Export Parameter
// Coverage target: src/attributes.cpp:360

// [[Rcpp::export(name = "custom_exported_name")]]
int test_named_export() { return 123; }

// [[Rcpp::export(name = "another.custom.name")]]
std::string test_named_export_with_dots() { return "dotted name"; }

// Test 4.2: Unnamed Export Parameter
// Coverage target: src/attributes.cpp:365

// [[Rcpp::export(my_custom_name)]]
int test_unnamed_export_param() { return 456; }

// Test 4.3: RNG Parameter Variations
// Coverage target: src/attributes.cpp:382-383

// [[Rcpp::export(rng = true)]]
int test_rng_lowercase_true() { return 789; }

// [[Rcpp::export(rng = TRUE)]]
int test_rng_uppercase_true() { return 101; }

// [[Rcpp::export(rng = false)]]
int test_rng_lowercase_false() { return 202; }

// Test 4.4: Invisible Parameter Variations
// Coverage target: src/attributes.cpp:391-392

// [[Rcpp::export(invisible = true)]]
void test_invisible_lowercase_true() {
  // Side effect only - returns invisibly
}

// [[Rcpp::export(invisible = TRUE)]]
void test_invisible_uppercase_true() {
  // Side effect only - returns invisibly
}

// Test 4.5: exportedCppName with Dots
// Coverage target: src/attributes.cpp:373-377
// This tests the conversion of dots to underscores in C++ names

// [[Rcpp::export(name = "test.with.dots")]]
int test_cpp_name_conversion() { return 999; }
