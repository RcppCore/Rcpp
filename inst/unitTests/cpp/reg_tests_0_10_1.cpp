#include <Rcpp.h>
using namespace Rcpp ;

// [[Rcpp::export]]
int DataFrame_nrows( DataFrame df){
    return df.nrows() ;
}

// [[Rcpp::export]]
double RangeIndexer_sugar( NumericVector x ){
    return max( x[ seq(0, 4) ] ) ;    
}

// [[Rcpp::export]]
IntegerVector test_self_match( CharacterVector x){
    return self_match( x ) ;
}

// [[Rcpp::export]]
IntegerVector test_table( CharacterVector x){
    return table( x ) ;
}

// [[Rcpp::export]]
LogicalVector test_duplicated( CharacterVector x){
    return duplicated( x ) ;
}

// [[Rcpp::export]]
IntegerVector test_union( IntegerVector x, IntegerVector y){
    return union_( x, y) ;
}
// [[Rcpp::export]]
IntegerVector test_setdiff( IntegerVector x, IntegerVector y){
    return setdiff( x, y) ;
}
// [[Rcpp::export]]
IntegerVector test_intersect( IntegerVector x, IntegerVector y){
    return intersect( x, y ) ;
}

