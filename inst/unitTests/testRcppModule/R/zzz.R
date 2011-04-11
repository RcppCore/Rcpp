NAMESPACE <- environment()

.onLoad <- function(libname, pkgname){
    loadRcppModules()
}

