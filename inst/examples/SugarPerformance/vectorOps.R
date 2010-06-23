
suppressMessages(library(inline))
suppressMessages(library(Rcpp))

src <- '
    NumericVector x(xs);
    NumericVector y(ys);
    unsigned int runs = as<int>(runss);
    int n = x.size() ;

    Timer timer;
    
    // approach one
    timer.Start();
    for (unsigned int i=0; i<runs; i++) {
   NumericVector res1( n ) ;
        double x_ = 0.0 ;
        double y_ = 0.0 ;
        for( int i=0; i<n; i++){
            x_ = x[i] ;
            y_ = y[i] ;
            if( R_IsNA(x_) || R_IsNA(y_) ){
                res1[i] = NA_REAL;
            } else if( x_ < y_ ){
                res1[i] = (x_ * x_) ;
            } else {
                res1[i] = - (y_ * y_) ;
            }
        }
    }
    timer.Stop();
    double t1 = timer.ElapsedTime();
    
    // approach two
    timer.Reset(); timer.Start();   
    start = as<double>( sys_time( ) ) ;
    for (unsigned int i=0; i<runs; i++) {
        NumericVector res2 = ifelse( x < y, x*x, -(y*y) ) ;
    }
    timer.Stop();
    double t2 = timer.ElapsedTime();
    
    ExpressionVector rcode( "ifelse( x<y, x*x, -(y*y) )" ) ;
    Language call = rcode[0] ;
    
    timer.Reset(); timer.Start();   
    for (unsigned int i=0; i<runs; i++) {
        NumericVector res2 = Rf_eval( call, R_GlobalEnv ) ;
    }
    timer.Stop();
    double t3 = timer.ElapsedTime();
    
    return NumericVector::create( 
    	_["hand written"] = t1, 
    	_["sugar"] = t2, 
    	_["R"]     = t3
    	) ;
'
settings <- getPlugin("Rcpp")
settings$env$PKG_CXXFLAGS <- paste("-I", getwd(), " -O0", sep="")

x <- runif(1e5)
y <- runif(1e5)
runs <- 500

fun <- cxxfunction(signature(runss="numeric", xs="numeric", ys="numeric"),
                   src,
                   includes='#include "Timer.h"',
                   plugin="Rcpp",
                   settings=settings)
print(fun(runs, x, y))
