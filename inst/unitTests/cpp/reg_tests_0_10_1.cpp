#include <Rcpp.h>
using namespace Rcpp ;

// [[Rcpp::export]]
int DataFrame_nrows( DataFrame df){
    return df.nrows() ;
}

