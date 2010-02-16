
test.runit <- function(){
	checkTrue( TRUE, msg = "checking checkTrue" )
	checkEquals( 1, 1, msg = "checking checkEquals" )
	checkException( stop("boom"), msg = "checking checkException" )
}

