setClass( "World", representation( pointer = "externalptr" ) )

World_method <- function(name){
	paste( "World", name, sep = "__" )
}

setMethod( "$", "World", function(x, name ){
	function(...) .Call( World_method(name) , x@pointer, ... )
} )

w <- new( "World", .Call( World_method( "new" ) ) )
w$set( "hello world" )
w$greet()

