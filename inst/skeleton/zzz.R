
# grab the namespace
.NAMESPACE <- environment()

# dummy module, will be replace later
yada <- new( "Module" )

.onLoad <- function(pkgname, libname){
	# load the module and store it in our namespace
	unlockBinding( "yada" , .NAMESPACE )
	assign( "yada",  Module( "yada" ), .NAMESPACE )
	lockBinding( "yada", .NAMESPACE )
}

