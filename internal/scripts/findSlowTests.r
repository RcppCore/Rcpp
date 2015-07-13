#!/usr/bin/Rscript
#  this should really be /usr/bin/r but you-know-who on a Mac ...

dir <- "Rcpp/inst/unitTests"
files <- list.files( dir, pattern = "^runit[.]", full = TRUE )
ntests <- sapply( files, function(.) sum( grepl( "^test[.]", readLines( . ) ) ) )
fast <- sapply( files, function(.) any( grepl( "cxxfunction.*signatures", readLines( . ) ) ) )
print(head(subset( data.frame( ntests, fast )[ order(-ntests), ], !fast ),10))
