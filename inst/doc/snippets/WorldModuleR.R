require( Rcpp )

# load the module
yada <- Module( "yada" )

# grab the World class
World <- yada$World

# create a new World object
w <- new( World )

# use methods of the class
w$greet()
w$set( "hello world" ) 
w$greet()
w$clear()
w$greet()

