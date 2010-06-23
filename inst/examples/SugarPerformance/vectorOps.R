
suppressMessages(library(inline))
suppressMessages(library(Rcpp))

benchmark <- function( start, hand.written, sugar, expr, runs = 500, 
	data = list( x = runif(1e5),  y = runif(1e5) ), 
	end = ""){

src <- sprintf( '
    unsigned int runs = as<int>(runss);
   	Environment e(env) ;
    
   	%s
	    
    Timer timer;
    
    // approach one
    timer.Start();
    for (unsigned int i=0; i<runs; i++) {
	   %s
    }
    timer.Stop();
    double t1 = timer.ElapsedTime();
    
    // approach two
    timer.Reset(); timer.Start();   
    for (unsigned int i=0; i<runs; i++) {
        %s
    }
    timer.Stop();
    double t2 = timer.ElapsedTime();
    
    Language call(expr) ;
    
    timer.Reset(); timer.Start();   
    for (unsigned int i=0; i<runs; i++) {
        NumericVector res2 = Rf_eval( call, e ) ;
    }
    timer.Stop();
    double t3 = timer.ElapsedTime();
     
    %s
    
    return NumericVector::create( 
    	_["hand written"] = t1, 
    	_["sugar"] = t2, 
    	_["R"]     = t3
    	) ;
', 
	paste( start, collapse = "\n" ) ,
	paste( hand.written, collapse = "\n" ), 
	paste( sugar, collapse = "\n" ), 
	paste( end, collapse = "\n" )
	)
	
	e <- environment()
	for( i in names(data) ){
		assign( i, data[[i]], envir = e )
	}
	
	settings <- getPlugin("Rcpp")
	settings$env$PKG_CXXFLAGS <- paste("-I", getwd(), " -O0", sep="")
	
	fun <- cxxfunction(signature(runss="integer", expr = "language", env = "environment" ),
	                   src,
	                   includes='#include "Timer.h"',
	                   plugin="Rcpp",
	                   settings=settings)
	fun(runs, expr, environment() )
}

res.ifelse <- benchmark( '
	NumericVector x = e["x"] ;
	NumericVector y = e["y"] ;
', '
	int n = x.size() ;
    NumericVector res1( n ) ;
    double x_ = 0.0 ;
    double y_ = 0.0 ;
    for( int i=0; i<n; i++){
        x_ = x[i] ;
        y_ = y[i] ;
        if( R_IsNA(x_) || R_IsNA(y_) ){
            res1[i] = NA_REAL;
        } else if( x_ < y_ ){
            res1[i] = x_ * x_ ;
        } else {
            res1[i] = -( y_ * y_)  ;
        }
    }

', '
    NumericVector res2 = ifelse( x < y, x*x, -(y*y) ) ;
', 
	quote(ifelse(x<y, x*x, -(y*y) )) 
)

res.any <- benchmark( '
	NumericVector x = e["x"] ;
	NumericVector y = e["y"] ;
	int res ;
	SEXP res2 ;
	
', '
	int n = x.size() ;
	bool seen_na = false ;
	bool result = false ;
	double x_ = 0.0 ;
	double y_ = 0.0 ;
    for( int i=0; i<n; i++){
    	x_ = x[i] ;
    	if( R_IsNA( x_ )  ){
    		seen_na = true ;
    	} else {
    		y_ = y[i] ;
    		if( R_IsNA( y_ ) ){
    			seen_na = true ;
    		} else {
    			/* both non NA */
    			if( x_*y_ < 0.0 ){
    				result = true ;
    				break ;
    			}
    		}
    	}
    }
    res = result ? TRUE : ( seen_na ? NA_LOGICAL : FALSE ) ;
', '
    res2 = any( x*y < 0 ) ; 
', 
	quote(any(x*y<0)), 
	data = list( 
		x = seq( -1, 1, length = 1e05), 
		y = rep( 1, 1e05) 
	)
)

results <- rbind( 
	as.data.frame( t( res.ifelse ) ), 
	as.data.frame( t( res.any    ) )
	)
print( results )

