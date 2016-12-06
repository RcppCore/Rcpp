##' Helper function to establish minimal compiler versions, currently limited
##' only to \code{g++} which (particularly for older RHEL/CentOS releases) is
##' too far behind current C++11 standards required for some packages.
##'
##' This function looks up \code{g++} (as well as optional values in the
##' \code{CXX} and \code{CXX1X} environment variables) in the \code{PATH}.  For
##' all values found, the output of \code{g++ -v} is analyzed for the version
##' string, which is then compared to the given minimal version.
##' @title Check for Minimal (g++) Compiler Version
##' @param minVersion An object of type \code{package_version}, with a default
##'  of version 4.6.0
##' @return A boolean value is returned, indicating if the minimal version is
##'  being met
##' @author Dirk Eddelbuettel
compilerCheck <- function(minVersion=package_version("4.6.0")) { # nocov start

    binaries <- c("g++", Sys.getenv("CXX", unset=""), Sys.getenv("CXX1X", unset=""))
    binpaths <- lapply(binaries, function(b) { if (b=="") NULL else Sys.which(b) })
                       
    allgood <- FALSE
    rl <- lapply(binpaths, function(b) {
        if (is.null(b)) return(NULL)
        con <- pipe(paste(b, "-v 2>&1"), "r") # NB: not --version, but -v
        lines <- readLines(con)
        close(con)
        lines <- lines[grepl("^g.. version", lines)]
        if (length(lines) == 0) return(NULL)
        ver <- strsplit(lines, " ")[[1]][3]   # format is 'gcc version x.y.z ....'
        package_version(ver) >= minVersion
    })
    all(do.call(c, rl))                 # drops NULLs
}                                       # nocov end

## TODO: maybe not limit to gcc/g++
## TODO: maybe be smarter about combination of path, CXX and CXX1X ?
## TODO: maybe make env.var optional arguments too
