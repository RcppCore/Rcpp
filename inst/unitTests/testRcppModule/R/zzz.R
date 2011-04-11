NAMESPACE <- environment()

.onLoad <- function(libname, pkgname){
    populate( Module("yada"), NAMESPACE )
    populate( Module("stdVector"), NAMESPACE )
    populate( Module("NumEx"), NAMESPACE )
}

