
## For R 2.15.0 we still need require(), but note the R CMD check issue
.onLoad <- function(libname, pkgname){
    require("methods")  ## needed, but upsets R CMD check
    loadRcppModules()
}

## For R 2.15.1 and later this will work. Note that calling loadModule() triggers
## a load action, so this does not have to be placed in .onLoad() or evalqOnLoad().
#  loadModule("NumEx", TRUE)
#  loadModule("yada", TRUE)
#  loadModule("stdVector", TRUE)
#})


