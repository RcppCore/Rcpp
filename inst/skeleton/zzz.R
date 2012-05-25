
.onLoad <- function(libname, pkgname){
    require("methods")  ## needed, but upsets R CMD check
    loadRcppModules()
}


