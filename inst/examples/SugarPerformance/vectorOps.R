
suppressMessages(library(inline))
suppressMessages(library(Rcpp))


# RcppExport SEXP vectorOps(SEXP runss, SEXP xs, SEXP ys) {
src <- '
    Rcpp::NumericVector x(xs);
    Rcpp::NumericVector y(ys);
    unsigned int runs = Rcpp::as<int>(runss);
    int n = x.size() ;

    Rcpp::NumericVector res(2);
    Timer timerOne, timerTwo;

    // approach one
    timerOne.Start();
    for (unsigned int i=0; i<runs; i++) {
        Rcpp::NumericVector res1( n ) ;
        double x_ = 0.0 ;
        double y_ = 0.0 ;
        for( int i=0; i<n; i++){
            x_ = x[i] ;
            y_ = y[i] ;
            if( x_ < y_ ){
                res1[i] = x_ * x_ ;
            } else {
                res1[i] = -( y_ * y_)  ;
            }
        }
    }
    timerOne.Stop();
    //double t1 = timerOne.ElapsedTime();
    res[0] = timerOne.ElapsedTime();
    //timer.Reset();

    // approach two
    timerTwo.Start();
    for (unsigned int i=0; i<runs; i++) {
        Rcpp::NumericVector res2 = ifelse( x < y, x*x, -(y*y) ) ;
    }
    timer.Stop();
    //double t2 = timerTwo.ElapsedTime();
    res[1] = timer.ElapsedTime();

    return Rcpp::wrap(res);
    // FAILS:  return Rcpp::List(Rcpp::Named("one")=Rcpp::wrap(t1),
    //                           Rcpp::Named("two")=Rcpp::wrap(t2));
'


srcOne <- '
    Rcpp::NumericVector x(xs);
    Rcpp::NumericVector y(ys);
    unsigned int runs = Rcpp::as<int>(runss);
    int n = x.size() ;

    Timer timer;

    timer.Start();
    for (unsigned int i=0; i<runs; i++) {
        Rcpp::NumericVector res1( n ) ;
        double x_ = 0.0 ;
        double y_ = 0.0 ;
        for( int i=0; i<n; i++){
            x_ = x[i] ;
            y_ = y[i] ;
            if( x_ < y_ ){
                res1[i] = x_ * x_ ;
            } else {
                res1[i] = -( y_ * y_)  ;
            }
        }
    }
    timer.Stop();
    return Rcpp::wrap( timer.ElapsedTime() );
'

srcTwo <- '
    Rcpp::NumericVector x(xs);
    Rcpp::NumericVector y(ys);
    unsigned int runs = Rcpp::as<int>(runss);

    Timer timer;

    timer.Start();
    for (unsigned int i=0; i<runs; i++) {
        Rcpp::NumericVector res = ifelse( x < y, x*x, -(y*y) ) ;
    }
    timer.Stop();
    return Rcpp::wrap( timer.ElapsedTime() );
'



settings <- getPlugin("Rcpp")
settings$env$PKG_CXXFLAGS <- paste("-I", getwd(), " -O0", sep="")

funOne <- cxxfunction(signature(runss="numeric", xs="numeric", ys="numeric"),
                      srcOne,
                      includes='#include "Timer.h"',
                      plugin="Rcpp",
                      settings=settings)
funTwo <- cxxfunction(signature(runss="numeric", xs="numeric", ys="numeric"),
                      srcTwo,
                      includes='#include "Timer.h"',
                      plugin="Rcpp",
                      settings=settings)


x <- runif(1e6)
y <- runif(1e6)
runs <- 10

resOne <- funOne(runs, x, y)
resTwo <- funTwo(runs, x, y)
cat("Timings: ", resOne, "vs", resTwo, "\n")

# Does order matter?
resTwo <- funTwo(runs, x, y)
resOne <- funOne(runs, x, y)
cat("Timings: ", resOne, "vs", resTwo, "\n")
