setMethod( "show", "World", function(object){
	msg <- paste( "World object with message : ", object$greet() )
	writeLines( msg )
} )
