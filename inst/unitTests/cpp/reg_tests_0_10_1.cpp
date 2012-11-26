#include <Rcpp.h>
using namespace Rcpp ;

// [[Rcpp::export]]
int DataFrame_nrows( DataFrame df){
    return df.nrows() ;
}

// [[Rcpp::export]]
double RangeIndexer_sugar( NumericVector x ){
    return max( x[ seq(0, 4) ], 5 ) ;    
}

