
# Copyright (C) 2012 - 2017  JJ Allaire, Dirk Eddelbuettel and Romain Francois
#
# This file is part of Rcpp.
#
# Rcpp is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# Rcpp is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.


# Source C++ code from a file
sourceCpp <- function(file = "",
                      code = NULL,
                      env = globalenv(),
                      embeddedR = TRUE,
                      rebuild = FALSE,
                      cacheDir = getOption("rcpp.cache.dir", tempdir()),
                      cleanupCacheDir = FALSE,
                      showOutput = verbose,
                      verbose = getOption("verbose"),
                      dryRun = FALSE) {

    # use an architecture/version specific subdirectory of the cacheDir
    # (since cached dynlibs can now perist across sessions we need to be
    # sure to invalidate them when R or Rcpp versions change)
    cacheDir <- path.expand(cacheDir)
    cacheDir <- .sourceCppPlatformCacheDir(cacheDir)
    cacheDir <- normalizePath(cacheDir)

    # resolve code into a file if necessary. also track the working
    # directory to source the R embedded code chunk within
    if (!missing(code)) {
        rWorkingDir <- getwd()
        file <- tempfile(fileext = ".cpp", tmpdir = cacheDir)
        con <- file(file, open = "w")
        writeLines(code, con)
        close(con)
    } else {
        rWorkingDir <- normalizePath(dirname(file))
    }

    # resolve the file path
    file <- normalizePath(file, winslash = "/")

    # error if the file extension isn't one supported by R CMD SHLIB
    if (! tools::file_ext(file) %in% c("cc", "cpp")) {          # #nocov start
        stop("The filename '", basename(file), "' does not have an ",
             "extension of .cc or .cpp so cannot be compiled.")
    }                                                           # #nocov end

    # validate that there are no spaces in the path on windows
    if (.Platform$OS.type == "windows") {                       # #nocov start
        if (grepl(' ', basename(file), fixed=TRUE)) {
            stop("The filename '", basename(file), "' contains spaces. This ",
                 "is not permitted.")
        }                                                       # #nocov end
    }

    # get the context (does code generation as necessary)
    context <- .Call("sourceCppContext", PACKAGE="Rcpp",
                     file, code, rebuild, cacheDir, .Platform)

    # perform a build if necessary
    if (context$buildRequired || rebuild) {

        # print output for verbose mode
        if (verbose)
            .printVerboseOutput(context)

        # variables used to hold completed state (passed to completed hook)
        succeeded <- FALSE
        output <- NULL

        # build dependency list
        depends <- .getSourceCppDependencies(context$depends, file)

        # validate packages (error if package not found)
        .validatePackages(depends, context$cppSourceFilename)

        # temporarily modify environment for the build
        envRestore <- .setupBuildEnvironment(depends, context$plugins, file)

        # temporarily setwd to build directory
        cwd <- getwd()
        setwd(context$buildDirectory)

        # call the onBuild hook. note that this hook should always be called
        # after .setupBuildEnvironment so subscribers are able to examine
        # the build environment
        fromCode <- !missing(code)
        if (!.callBuildHook(context$cppSourcePath, fromCode, showOutput)) {
            .restoreEnvironment(envRestore)                     # #nocov start
            setwd(cwd)
            return (invisible(NULL))
        }                                                       # #nocov end

        # on.exit handler calls hook and restores environment and working dir
        on.exit({
            if (!succeeded)
                .showBuildFailureDiagnostics()
            .callBuildCompleteHook(succeeded, output)
            setwd(cwd)
            .restoreEnvironment(envRestore)
        })

        # unload and delete existing dylib if necessary
        if (file.exists(context$previousDynlibPath)) {          # #nocov start
            try(silent=TRUE, dyn.unload(context$previousDynlibPath))
            file.remove(context$previousDynlibPath)
        }                                                       # #nocov end

        # prepare the command (output if we are in showOutput mode)
        cmd <- paste(R.home(component="bin"), .Platform$file.sep, "R ",
                     "CMD SHLIB ",
                     "-o ", shQuote(context$dynlibFilename), " ",
                     ifelse(rebuild, "--preclean ", ""),
                     ifelse(dryRun, "--dry-run ", ""),
                     paste(shQuote(context$cppDependencySourcePaths),
                           collapse = " "), " ",
                     shQuote(context$cppSourceFilename), " ",
                     sep="")
        if (showOutput)
            cat(cmd, "\n")

        # execute the build -- suppressWarnings b/c when showOutput = FALSE
        # we are going to explicitly check for an error and print the output
        result <- suppressWarnings(system(cmd, intern = !showOutput))

        # check build results
        if(!showOutput) {
            # capture output
            output <- result
            attributes(output) <- NULL
            # examine status
            status <- attr(result, "status")
            if (!is.null(status)) {
                cat(result, sep = "\n")                         # #nocov start
                succeeded <- FALSE
                stop("Error ", status, " occurred building shared library.")
            } else if (!file.exists(context$dynlibFilename)) {
                cat(result, sep = "\n")
                succeeded <- FALSE
                stop("Error occurred building shared library.") # #nocov end
            } else {
                succeeded <- TRUE
            }
        }
        else if (!identical(as.character(result), "0")) {       # #nocov start
            succeeded <- FALSE
            stop("Error ", result, " occurred building shared library.")
        } else {
            succeeded <- TRUE                                   # #nocov end
        }
    }
    else {
        cwd <- getwd()
        on.exit({
            setwd(cwd)
        })
        if (verbose)
            cat("\nNo rebuild required (use rebuild = TRUE to ",
                "force a rebuild)\n\n", sep="")
    }

    # return immediately if this was a dry run
    if (dryRun)
        return(invisible(NULL))

    # load the module if we have exported symbols
    if (length(context$exportedFunctions) > 0 || length(context$modules) > 0) {

        # remove existing objects of the same name from the environment
        exports <- c(context$exportedFunctions, context$modules)
        removeObjs <- exports[exports %in% ls(envir = env, all.names = T)]
        remove(list = removeObjs, envir = env)

        # source the R script
        scriptPath <- file.path(context$buildDirectory, context$rSourceFilename)
        source(scriptPath, local = env)

    } else if (getOption("rcpp.warnNoExports", default=TRUE)) { # #nocov start
        warning("No Rcpp::export attributes or RCPP_MODULE declarations ",
                "found in source")                              # #nocov end
    }

    # source the embeddedR
    if (embeddedR && (length(context$embeddedR) > 0)) {
        srcConn <- textConnection(context$embeddedR)
        setwd(rWorkingDir) # will be reset by previous on.exit handler
        source(file=srcConn, echo=TRUE)
    }

    # cleanup the cache dir if requested
    if (cleanupCacheDir)
        cleanupSourceCppCache(cacheDir, context$cppSourcePath, context$buildDirectory)

    # return (invisibly) a list containing exported functions and modules
    invisible(list(functions = context$exportedFunctions,
                   modules = context$modules,
                   cppSourcePath = context$cppSourcePath,
                   buildDirectory = context$buildDirectory))
}


# Cleanup a directory used as the cache for a sourceCpp compilation. This will
# remove all files from the cache directory that aren't a result of the
# compilation that yielded the passed buildDirectory.
cleanupSourceCppCache <- function(cacheDir, cppSourcePath, buildDirectory) {
    # normalize cpp source path and build directory             # #nocov start
    cppSourcePath <- normalizePath(cppSourcePath)
    buildDirectory <- normalizePath(buildDirectory)

    # determine the parent dir that was used for the compilation then collect all the
    # *.cpp files and subdirectories therein
    cacheFiles <- list.files(cacheDir, pattern = glob2rx("*.cpp"), recursive = FALSE, full.names = TRUE)
    cacheFiles <- c(cacheFiles, list.dirs(cacheDir, recursive = FALSE, full.names = TRUE))
    cacheFiles <- normalizePath(cacheFiles)

    # determine the list of tiles that were not yielded by the passed sourceCpp
    # result and remove them
    oldCacheFiles <- cacheFiles[!cacheFiles %in% c(cppSourcePath, buildDirectory)]
    unlink(oldCacheFiles, recursive = TRUE)                     # #nocov end
}

# Define a single C++ function
cppFunction <- function(code,
                        depends = character(),
                        plugins = character(),
                        includes = character(),
                        env = parent.frame(),
                        rebuild = FALSE,
                        cacheDir = getOption("rcpp.cache.dir", tempdir()),
                        showOutput = verbose,
                        verbose = getOption("verbose")) {

    # process depends
    if (!is.null(depends) && length(depends) > 0) {             # #nocov start
        depends <- paste(depends, sep=", ")
        scaffolding <- paste("// [[Rcpp::depends(", depends, ")]]", sep="")
        scaffolding <- c(scaffolding, "", .linkingToIncludes(depends, FALSE),
                         recursive=TRUE)                        # #nocov end
    }
    else {
        scaffolding <- "#include <Rcpp.h>"
    }

    # process plugins
    if (!is.null(plugins) && length(plugins) > 0) {
        plugins <- paste(plugins, sep=", ")                     # #nocov start
        pluginsAttrib <- paste("// [[Rcpp::plugins(", plugins, ")]]", sep="")
        scaffolding <- c(scaffolding, pluginsAttrib)

        # append plugin includes
        for (pluginName in plugins) {
            plugin <- .findPlugin(pluginName)
            settings <- plugin()
            scaffolding <- c(scaffolding, settings$includes, recursive=TRUE)
        }                                                       # #nocov end
    }

    # remainder of scaffolding
    scaffolding <- c(scaffolding,
                     "",
                     "using namespace Rcpp;",
                     "",
                     includes,
                     "// [[Rcpp::export]]",
                     recursive = T)

    # prepend scaffolding to code
    code <- paste(c(scaffolding, code, recursive = T), collapse="\n")

    # print the generated code if we are in verbose mode
    if (verbose) {                                              # #nocov start
        cat("\nGenerated code for function definition:",
            "\n--------------------------------------------------------\n\n")
        cat(code)
        cat("\n")
    }                                                           # #nocov end

    # source cpp into specified environment. if env is set to NULL
    # then create a new one (the caller can get a hold of the function
    # via the return value)
    if (is.null(env))
        env <- new.env()
    exported <- sourceCpp(code = code,
                          env = env,
                          rebuild = rebuild,
                          cacheDir = cacheDir,
                          showOutput = showOutput,
                          verbose = verbose)

    # verify that a single function was exported and return it
    if (length(exported$functions) == 0)
        stop("No function definition found")
    else if (length(exported$functions) > 1)
        stop("More than one function definition")
    else {
        functionName <- exported$functions[[1]]
        invisible(get(functionName, env))
    }
}

.type_manipulate <- function( what = "DEMANGLE", class = NULL ) {
    function( type = "int", ... ){                              # #nocov start
        code <- sprintf( '
        SEXP manipulate_this_type(){
            typedef %s type ;
            return wrap( %s(type) ) ;
        }', type, what )
        dots <- list( code, ... )
        dots[["env"]] <- environment()
        manipulate_this_type <- do.call( cppFunction, dots )
        res <- manipulate_this_type()
        if( ! is.null(class) ){
            class(res) <- class
        }
        res
    }                                                           # #nocov end
}

demangle <- .type_manipulate( "DEMANGLE" )
sizeof   <- .type_manipulate( "sizeof", "bytes" )

print.bytes <- function( x, ...){                               # #nocov start
    writeLines( sprintf( "%d bytes (%d bits)", x, 8 * x ) )
    invisible( x )
}                                                               # #nocov end

# Evaluate a simple c++ expression
evalCpp <- function(code,
                    depends = character(),
                    plugins = character(),
                    includes = character(),
                    rebuild = FALSE,
                    cacheDir = getOption("rcpp.cache.dir", tempdir()),
                    showOutput = verbose,
                    verbose = getOption( "verbose" ) ){

                                                                # #nocov start
    code <- sprintf( "SEXP get_value(){ return wrap( %s ) ; }", code )
    env <- new.env()
    cppFunction(code, depends = depends, plugins = plugins,
                includes = includes, env = env,
                rebuild = rebuild, cacheDir = cacheDir, showOutput = showOutput, verbose = verbose )
    fun <- env[["get_value"]]
    fun()                                                       # #nocov end
}

areMacrosDefined <- function(names,
                    depends = character(),
                    includes = character(),
                    rebuild = FALSE,
                    showOutput = verbose,
                    verbose = getOption( "verbose" ) ){


    code <- sprintf( '
        LogicalVector get_value(){

            return LogicalVector::create(
                %s
            ) ;
        }',

        paste( sprintf( '    _["%s"] =
                #if defined(%s)
                    true
                #else
                    false
                #endif
         ', names, names ), collapse = ",\n" )
    )
    env <- new.env()
    cppFunction(code, depends = depends, includes = includes, env = env,
                rebuild = rebuild, showOutput = showOutput, verbose = verbose )
    fun <- env[["get_value"]]
    fun()
}

# Scan the source files within a package for attributes and generate code
# based on the attributes.
compileAttributes <- function(pkgdir = ".", verbose = getOption("verbose")) {

    # verify this is a package and read the DESCRIPTION to get it's name
    pkgdir <- normalizePath(pkgdir, winslash = "/")
    descFile <- file.path(pkgdir,"DESCRIPTION")
    if (!file.exists(descFile))
        stop("pkgdir must refer to the directory containing an R package")
    pkgDesc <- read.dcf(descFile)[1,]
    pkgname = .readPkgDescField(pkgDesc, "Package")
    depends <- c(.readPkgDescField(pkgDesc, "Depends", character()),
                 .readPkgDescField(pkgDesc, "Imports", character()),
                 .readPkgDescField(pkgDesc, "LinkingTo", character()))
    depends <- unique(.splitDepends(depends))
    depends <- depends[depends != "R"]

    # check the NAMESPACE file to see if dynamic registration is enabled
    namespaceFile <- file.path(pkgdir, "NAMESPACE")
    if (!file.exists(namespaceFile))
        stop("pkgdir must refer to the directory containing an R package")
    pkgNamespace <- readLines(namespaceFile, warn = FALSE)
    registration <- any(grepl("^\\s*useDynLib.*\\.registration\\s*=\\s*TRUE.*$", pkgNamespace))

    # determine source directory
    srcDir <- file.path(pkgdir, "src")
    if (!file.exists(srcDir))
        return (FALSE)

    # create R directory if it doesn't already exist
    rDir <- file.path(pkgdir, "R")
    if (!file.exists(rDir))
        dir.create(rDir)

    # get a list of all source files
    cppFiles <- list.files(srcDir, pattern = "\\.((c(c|pp)?)|(h(pp)?))$")

    # derive base names (will be used for modules)
    cppFileBasenames <- tools::file_path_sans_ext(cppFiles)

    # expend them to their full paths
    cppFiles <- file.path(srcDir, cppFiles)
    cppFiles <- normalizePath(cppFiles, winslash = "/")

    # generate the includes list based on LinkingTo. Specify plugins-only
    # because we only need as/wrap declarations
    linkingTo <- .readPkgDescField(pkgDesc, "LinkingTo")
    includes <- .linkingToIncludes(linkingTo, TRUE)

    # if a master include file or types file is in inst/include then use it
    typesHeader <- c(paste0(pkgname, "_types.h"), paste0(pkgname, "_types.hpp"))
    pkgHeader <- c(paste0(pkgname, ".h"), typesHeader)
    pkgHeaderPath <- file.path(pkgdir, "inst", "include",  pkgHeader)
    pkgHeader <- pkgHeader[file.exists(pkgHeaderPath)]
    if (length(pkgHeader) > 0) {                                # #nocov start
        pkgInclude <- paste("#include \"../inst/include/",
                            pkgHeader, "\"", sep="")
        includes <- c(pkgInclude, includes)
    }                                                           # #nocov end

    # if a _types file is in src then include it
    pkgHeader <- typesHeader
    pkgHeaderPath <- file.path(pkgdir, "src", pkgHeader)
    pkgHeader <- pkgHeader[file.exists(pkgHeaderPath)]
    if (length(pkgHeader) > 0)
        includes <- c(paste0("#include \"", pkgHeader ,"\""), includes)

    # generate exports
    invisible(.Call("compileAttributes", PACKAGE="Rcpp",
                    pkgdir, pkgname, depends, registration, cppFiles, cppFileBasenames,
                    includes, verbose, .Platform))
}

# setup plugins environment
.plugins <- new.env()

# built-in C++98 plugin 
.plugins[["cpp98"]] <- function() {
    if (getRversion() >= "3.4")         # with recent R versions, R can decide
        list(env = list(USE_CXX98 = "yes"))
    else
        list(env = list(PKG_CXXFLAGS ="-std=c++98"))
}
                                        # built-in C++11 plugin
.plugins[["cpp11"]] <- function() {
    if (getRversion() >= "3.4")         # with recent R versions, R can decide
        list(env = list(USE_CXX11 = "yes"))
    else if (getRversion() >= "3.1")    # with recent R versions, R can decide
        list(env = list(USE_CXX1X = "yes"))
    else if (.Platform$OS.type == "windows")
        list(env = list(PKG_CXXFLAGS = "-std=c++0x"))
    else                                # g++-4.8.1 or later
        list(env = list(PKG_CXXFLAGS ="-std=c++11"))
}

# built-in C++11 plugin for older g++ compiler
.plugins[["cpp0x"]] <- function() {
    list(env = list(PKG_CXXFLAGS ="-std=c++0x"))
}

## built-in C++14 plugin for C++14 standard
## this is the default in g++-6.1 and later
## per https://gcc.gnu.org/projects/cxx-status.html#cxx14
.plugins[["cpp14"]] <- function() {
    if (getRversion() >= "3.4")         # with recent R versions, R can decide
        list(env = list(USE_CXX14 = "yes"))
    else
        list(env = list(PKG_CXXFLAGS ="-std=c++14"))
}

# built-in C++1y plugin for C++14 and C++17 standard under development
.plugins[["cpp1y"]] <- function() {
    list(env = list(PKG_CXXFLAGS ="-std=c++1y"))
}

# built-in C++17 plugin for C++17 standard (g++-6 or later)
.plugins[["cpp17"]] <- function() {
    if (getRversion() >= "3.4")         # with recent R versions, R can decide
        list(env = list(USE_CXX17 = "yes"))
    else
        list(env = list(PKG_CXXFLAGS ="-std=c++17"))
}

## built-in C++1z plugin for C++17 standard under development
## note that as of Feb 2017 this is taken to be a moving target
## see https://gcc.gnu.org/projects/cxx-status.html
.plugins[["cpp1z"]] <- function() {
    list(env = list(PKG_CXXFLAGS ="-std=c++1z"))
}

## built-in OpenMP plugin
.plugins[["openmp"]] <- function() {
    list(env = list(PKG_CXXFLAGS="-fopenmp",
                    PKG_LIBS="-fopenmp"))
}

# register a plugin
registerPlugin <- function(name, plugin) {
    .plugins[[name]] <- plugin                                  # #nocov
}


# Take an empty function body and connect it to the specified external symbol
sourceCppFunction <- function(func, isVoid, dll, symbol) {

    args <- names(formals(func))

    body <- quote( CALL_PLACEHOLDER ( EXTERNALNAME, ARG ) )[ c(1:2, rep(3, length(args))) ]

    for (i in seq(along.with = args))
        body[[i+2]] <- as.symbol(args[i])

    body[[1L]] <- .Call
    body[[2L]] <- getNativeSymbolInfo(symbol, dll)$address

    if (isVoid)
        body <- call("invisible", body)

    body(func) <- body

    func
}


# Print verbose output
.printVerboseOutput <- function(context) {                      # #nocov start

    cat("\nGenerated extern \"C\" functions",
        "\n--------------------------------------------------------\n")
    cat(context$generatedCpp, sep="")

    cat("\nGenerated R functions",
        "\n-------------------------------------------------------\n\n")
    cat(readLines(file.path(context$buildDirectory,
                            context$rSourceFilename)),
        sep="\n")

    cat("\nBuilding shared library",
        "\n--------------------------------------------------------\n",
        "\nDIR: ", context$buildDirectory, "\n\n", sep="")
}                                                               # #nocov end

# Add LinkingTo dependencies if the sourceFile is in a package
.getSourceCppDependencies <- function(depends, sourceFile) {

    # If the source file is in a package then simulate it being built
    # within the package by including it's LinkingTo dependencies,
    # the src directory (.), and the inst/include directory
    if (.isPackageSourceFile(sourceFile)) {                     # #nocov start
        descFile <- file.path(dirname(sourceFile), "..", "DESCRIPTION")
        DESCRIPTION <- read.dcf(descFile, all = TRUE)
        linkingTo <- .parseLinkingTo(DESCRIPTION$LinkingTo)
        unique(c(depends, linkingTo))                           # #nocov end
    } else {
        depends
    }
}


# Check whether a source file is in a package
.isPackageSourceFile <- function(sourceFile) {
    file.exists(file.path(dirname(sourceFile), "..", "DESCRIPTION"))
}

# Error if a package is not currently available
.validatePackages <- function(depends, sourceFilename) {
    unavailable <- depends[!depends %in% .packages(all.available=TRUE)]
    if (length(unavailable) > 0) {                              # #nocov start
        stop(paste("Package '", unavailable[[1]], "' referenced from ",
                    "Rcpp::depends in source file ",
                      sourceFilename, " is not available.",
                      sep=""),
                call. = FALSE)                                  # #nocov end
    }
}

# Split the depends field of a package description
.splitDepends <- function(x) {
    if (!length(x))
        return(character())
    x <- unlist(strsplit(x, ","))
    x <- sub("[[:space:]]+$", "", x)
    x <- unique(sub("^[[:space:]]*(.*)", "\\1", x))
    sub("^([[:alnum:].]+).*$", "\\1", x)
}

# read a field from a named package description character vector
.readPkgDescField <- function(pkgDesc, name, default = NULL) {
    if (name %in% names(pkgDesc))
        pkgDesc[[name]]
    else
        default
}


# Get the inline plugin for the specified package (return NULL if none found)
.getInlinePlugin <- function(package) {                         # #nocov start
    tryCatch(get("inlineCxxPlugin", asNamespace(package), inherits = FALSE),
             error = function(e) NULL)
}                                                               # #nocov end

# Lookup a plugin
.findPlugin <- function(pluginName) {

    plugin <- .plugins[[pluginName]]
    if (is.null(plugin))
        stop("Inline plugin '", pluginName, "' could not be found ",
             "within the Rcpp package. You should be ",
             "sure to call registerPlugin before using a plugin.")

    return(plugin)
}

# Setup the build environment based on the specified dependencies. Returns an
# opaque object that can be passed to .restoreEnvironment to reverse whatever
# changes that were made
.setupBuildEnvironment <- function(depends, plugins, sourceFile) {

    # setup
    buildEnv <- list()
    linkingToPackages <- c("Rcpp")

    # merge values into the buildEnv
    mergeIntoBuildEnv <- function(name, value) {

        # protect against null or empty string
        if (is.null(value) || !nzchar(value))
            return(invisible(NULL))

        # if it doesn't exist already just set it
        if (is.null(buildEnv[[name]])) {
            buildEnv[[name]] <<- value
        }
        # if it's not identical then append
        else if (!identical(buildEnv[[name]], value)) {
            buildEnv[[name]] <<- paste(buildEnv[[name]], value) # #nocov
        }
        else {
            # it already exists and it's the same value, this
            # likely means it's a flag-type variable so we
            # do nothing rather than appending it
        }
    }

    # update dependencies from a plugin
    setDependenciesFromPlugin <- function(plugin) {

        # get the plugin settings
        settings <- plugin()

        # merge environment variables
        pluginEnv <- settings$env
        for (name in names(pluginEnv)) {
            mergeIntoBuildEnv(name, pluginEnv[[name]])
        }

        # capture any LinkingTo elements defined by the plugin
        linkingToPackages <<- unique(c(linkingToPackages,
                                      settings$LinkingTo))
    }

    # add packages to linkingTo and introspect for plugins
    for (package in depends) {
                                                                # #nocov start
        # add a LinkingTo for this package
        linkingToPackages <- unique(c(linkingToPackages, package))

        # see if the package exports a plugin
        plugin <- .getInlinePlugin(package)
        if (!is.null(plugin))
           setDependenciesFromPlugin(plugin)                    # #nocov end
    }

    # process plugins
    for (pluginName in plugins) {
        plugin <- .findPlugin(pluginName)
        setDependenciesFromPlugin(plugin)
    }

    # if there is no buildEnv from a plugin then use the Rcpp plugin
    if (length(buildEnv) == 0) {
        buildEnv <- inlineCxxPlugin()$env
    }

    # set CLINK_CPPFLAGS based on the LinkingTo dependencies
    buildEnv$CLINK_CPPFLAGS <- .buildClinkCppFlags(linkingToPackages)

    # add the source file's directory to the compilation
    srcDir <- dirname(sourceFile)
    srcDir <- asBuildPath(srcDir)
    buildDirs <- srcDir

    # if the source file is in a package then add inst/include
    if (.isPackageSourceFile(sourceFile)) {                     # #nocov start
        incDir <- file.path(dirname(sourceFile), "..", "inst", "include")
        incDir <- asBuildPath(incDir)
        buildDirs <- c(buildDirs, incDir)                       # #nocov end
    }

    # set CLINK_CPPFLAGS with directory flags
    dirFlags <- paste0('-I"', buildDirs, '"', collapse=" ")
    buildEnv$CLINK_CPPFLAGS <- paste(buildEnv$CLINK_CPPFLAGS,
                                     dirFlags,
                                     collapse=" ")

    # merge existing environment variables
    for (name in names(buildEnv))
        mergeIntoBuildEnv(name, Sys.getenv(name))

    # add cygwin message muffler
    buildEnv$CYGWIN = "nodosfilewarning"

    # on windows see if we need to add Rtools to the path
    # (don't do this for RStudio since it has it's own handling)
    if (identical(Sys.info()[['sysname']], "Windows") &&
        !nzchar(Sys.getenv("RSTUDIO"))) {                       # #nocov start
        env <- .environmentWithRtools()
        for (var in names(env))
            buildEnv[[var]] <- env[[var]]                       # #nocov end
    }

    # create restore list
    restore <- list()
    for (name in names(buildEnv))
        restore[[name]] <- Sys.getenv(name, unset = NA)

    # set environment variables
    do.call(Sys.setenv, buildEnv)

    # return restore list
    return (restore)
}


# If we don't have the GNU toolchain already on the path then see if
# we can find Rtools and add it to the path
.environmentWithRtools <- function() {
                                                                # #nocov start
    # Only proceed if we don't have the required tools on the path
    hasRtools <- nzchar(Sys.which("ls.exe")) && nzchar(Sys.which("gcc.exe"))
    if (!hasRtools) {

        # Read the Rtools registry key
        key <- NULL
        try(key <- utils::readRegistry("SOFTWARE\\R-core\\Rtools",
                                       hive = "HLM", view = "32-bit"),
            silent = TRUE)

        # If we found the key examine it
        if (!is.null(key)) {

            # Check version
            ver <- key$`Current Version`
            if (ver %in% (c("2.15", "2.16", "3.0", "3.1", "3.2", "3.3", "3.4"))) {
                # See if the InstallPath leads to the expected directories
                # R version 3.3.0 alpha (2016-03-25 r70378)
                isGcc49 <- ver %in% c("3.3", "3.4") && as.numeric(R.Version()$`svn rev`) >= 70378

                rToolsPath <- key$`InstallPath`
                if (!is.null(rToolsPath)) {
                    # add appropriate path entries
                    path <- file.path(rToolsPath, "bin", fsep="\\")
                    if (!isGcc49)
                        path <- c(path, file.path(rToolsPath, "gcc-4.6.3", "bin", fsep="\\"))

                    # if they all exist then return a list with modified
                    # environment variables for the compilation
                    if (all(file.exists(path))) {
                        env <- list()
                        path <- paste(path, collapse = .Platform$path.sep)
                        env$PATH <- paste(path, Sys.getenv("PATH"), sep=.Platform$path.sep)
                        if (isGcc49) {
                            env$RTOOLS  <- .rtoolsPath(rToolsPath)
                            env$BINPREF <- file.path(env$RTOOLS, "mingw_$(WIN)/bin//", fsep = "/")
                        }
                        return(env)
                    }
                }
            }
        }
    }

    return(NULL)                                                # #nocov end
}


# Ensure that the path is suitable for passing as an RTOOLS
# environment variable
.rtoolsPath <- function(path) {
    path <- gsub("\\\\", "/", path)                             # #nocov start
    ## R 3.2.0 or later only:  path <- trimws(path)
    .localsub <- function(re, x) sub(re, "", x, perl = TRUE)
    path <- .localsub("[ \t\r\n]+$", .localsub("^[ \t\r\n]+", path))
    if (substring(path, nchar(path)) != "/")
        path <- paste(path, "/", sep="")
    path                                                        # #nocov end
}


# Build CLINK_CPPFLAGS from include directories of LinkingTo packages
.buildClinkCppFlags <- function(linkingToPackages) {
    pkgCxxFlags <- NULL
    for (package in linkingToPackages) {
        packagePath <- find.package(package, NULL, quiet=TRUE)
        packagePath <- asBuildPath(packagePath)
        pkgCxxFlags <- paste(pkgCxxFlags,
            paste0('-I"', packagePath, '/include"'),
            collapse=" ")
    }
    return (pkgCxxFlags)
}

.restoreEnvironment <- function(restore) {
    # variables to reset
    setVars <- restore[!is.na(restore)]
    if (length(setVars))
        do.call(Sys.setenv, setVars)

    # variables to remove
    removeVars <- names(restore[is.na(restore)])
    if (length(removeVars))
        Sys.unsetenv(removeVars)
}


# Call the onBuild hook. This hook is provided so that external tools
# can perform processing (e.g. lint checking or other diagnostics) prior
# to the execution of a build). The showOutput flag is there to inform the
# subscriber whether they'll be getting output in the onBuildComplete hook
# or whether it will need to be scraped from the console (for verbose=TRUE)
# The onBuild hook is always called from within the temporary build directory
.callBuildHook <- function(file, fromCode, showOutput) {

    for (fun in .getHooksList("sourceCpp.onBuild")) {

        if (is.character(fun))                                  # #nocov start
            fun <- get(fun)

        # allow the hook to cancel the build (errors in the hook explicitly
        # do not cancel the build since they are unexpected bugs)
        continue <- tryCatch(fun(file, fromCode, showOutput),
                             error = function(e) TRUE)

        if (!continue)
            return (FALSE)                                      # #nocov end
    }

    return (TRUE)
}

# Call the onBuildComplete hook. This hook is provided so that external tools
# can do analysis of build errors and (for example) present them in a
# navigable list. Note that the output parameter will be NULL when showOutput
# is TRUE. Tools can try to scrape the output from the console (in an
# implemenentation-dependent fashion) or can simply not rely on output
# processing in that case (since the user explicitly asked for output to be
# printed to the console). The onBuildCompleted hook is always called within
# the temporary build directory.
.callBuildCompleteHook <- function(succeeded, output) {

    # Call the hooks in reverse order to align sequencing with onBuild
    for (fun in .getHooksList("sourceCpp.onBuildComplete")) {

        if (is.character(fun))                                  # #nocov start
            fun <- get(fun)

        try(fun(succeeded, output))                             # #nocov end
    }
}

# The value for getHooks can be a single function or a list of functions,
# This function ensures that the result can always be processed as a list
.getHooksList <- function(name) {
    hooks <- getHook(name)
    if (!is.list(hooks))
        hooks <- list(hooks)
    hooks
}


# Generate list of includes based on LinkingTo. The pluginsOnly parameter
# to distinguish the case of capturing all includes needed for a compiliation
# (e.g. cppFunction) verses only needing to capture as/wrap converters which
# is the case for generation of shims (RcppExports.cpp) and Rcpp::interfaces
# package header files.
.linkingToIncludes <- function(linkingTo, pluginsOnly) {

    # This field can be NULL or empty -- in that case just return Rcpp.h
    if (is.null(linkingTo) || !nzchar(linkingTo))
        return (c("#include <Rcpp.h>"))

    # Look for Rcpp inline plugins within the list or LinkedTo packages
    include.before <- character()
    include.after <- character()
    linkingToPackages <- .parseLinkingTo(linkingTo)
    for (package in linkingToPackages) {

        # We already handle Rcpp internally
        if (identical(package, "Rcpp"))
            next

        # see if there is a plugin that we can extract includes from
        plugin <- .getInlinePlugin(package)                     # #nocov start
        if (!is.null(plugin)) {
            includes <- .pluginIncludes(plugin)
            if (!is.null(includes)) {
                include.before <- c(include.before, includes$before)
                include.after <- c(include.after, includes$after)
            }
        }
        # otherwise check for standard Rcpp::interfaces generated include
        else if (!pluginsOnly) {
            pkgPath <- find.package(package, NULL, quiet=TRUE)
            pkgHeader <- paste(package, ".h", sep="")
            pkgHeaderPath <- file.path(pkgPath, "include",  pkgHeader)
            if (file.exists(pkgHeaderPath)) {
                pkgInclude <- paste("#include <", pkgHeader, ">", sep="")
                include.after <- c(include.after, pkgInclude)
            }
        }                                                       # #nocov end
    }

    # return the includes
    c(include.before, "#include <Rcpp.h>", include.after)
}

# Analyze the plugin's includes field to determine include.before and
# include.after. We are ONLY interested in plugins that work with Rcpp since
# the only types we need from includes are as/wrap marshallers. Therefore,
# we verify that the plugin was created using Rcpp.plugin.maker and then
# use that assumption to correctly extract include.before and include.after
.pluginIncludes <- function(plugin) {
                                                                # #nocov start
    # First determine the standard suffix of an Rcpp plugin by calling
    # Rcpp.plugin.maker. If the plugin$includes has this suffix we know
    # it's an Rcpp plugin
    token <- "include_after_token"
    stockRcppPlugin <- Rcpp.plugin.maker(include.after=token)
    includes <- stockRcppPlugin()$includes
    suffix <- strsplit(includes, token)[[1]][[2]]

    # now ask the plugin for it's includes, ensure that the plugin includes
    # are not null, and verify they have the Rcpp suffix before proceeding
    pluginIncludes <- plugin()$includes
    if (is.null(pluginIncludes))
        return (NULL)
    if (!grepl(suffix, pluginIncludes))
        return (NULL)

    # strip the suffix then split on stock Rcpp include to get before and after
    pluginIncludes <- strsplit(pluginIncludes, suffix)[[1]][[1]]
    pluginIncludes <- strsplit(pluginIncludes, c("#include <Rcpp.h>"))[[1]]

    # extract before and after and nix empty lines
    before <- pluginIncludes[[1]]
    before <- strsplit(before, "\n")[[1]]
    before <- before[nzchar(before)]
    after <- pluginIncludes[[2]]
    after <- strsplit(after, "\n")[[1]]
    after <- after[nzchar(after)]

    # return before and after
    list(before = before, after = after)                        # #nocov end
}

# Parse a LinkingTo field into a character vector
.parseLinkingTo <- function(linkingTo) {

    if (is.null(linkingTo))
        return (character())

    linkingTo <- strsplit(linkingTo, "\\s*\\,")[[1]]
    result <- gsub("\\s", "", linkingTo)
    gsub("\\(.*", "", result)
}

# show diagnostics for failed builds
.showBuildFailureDiagnostics <- function() {
                                                                # #nocov start
    # RStudio does it's own diagnostics so only do this for other environments
    if (nzchar(Sys.getenv("RSTUDIO")))
        return();

    # if we can't call R CMD SHLIB then notify the user they should
    # install the appropriate development tools
    if (!.checkDevelTools()) {
        msg <- paste("\nWARNING: The tools required to build C++ code for R ",
                     "were not found.\n\n", sep="")
        sysName <- Sys.info()[['sysname']]
        if (identical(sysName, "Windows")) {
            msg <- paste(msg, "Please download and install the appropriate ",
                              "version of Rtools:\n\n",
                              "http://cran.r-project.org/bin/windows/Rtools/\n",
                              sep="");

        } else if (identical(sysName, "Darwin")) {
            msg <- paste(msg, "Please install Command Line Tools for XCode ",
                         "(or equivalent).\n", sep="")
        } else {
            msg <- paste(msg, "Please install GNU development tools ",
                         "including a C++ compiler.\n", sep="")
        }
        message(msg)
    }                                                           # #nocov end
}

# check if R development tools are installed (cache successful result)
.hasDevelTools <- FALSE
.checkDevelTools <- function() {

    if (!.hasDevelTools) {                                      # #nocov start
        # create temp source file
        tempFile <- file.path(tempdir(), "foo.c")
        cat("void foo() {}\n", file = tempFile)
        on.exit(unlink(tempFile))

        # set working directory to tempdir (revert on exit)
        oldDir <- setwd(tempdir())
        on.exit(setwd(oldDir), add = TRUE)

        # attempt the compilation and note whether we succeed
        cmd <- paste(R.home(component="bin"), .Platform$file.sep, "R ",
                     "CMD SHLIB foo.c", sep = "")
        result <- suppressWarnings(system(cmd,
                                          ignore.stderr = TRUE,
                                          intern = TRUE))
        utils::assignInMyNamespace(".hasDevelTools", is.null(attr(result, "status")))

        # if we build successfully then remove the shared library
        if (.hasDevelTools) {
            lib <- file.path(tempdir(),
                             paste("foo", .Platform$dynlib.ext, sep=''))
            unlink(lib)
        }
    }
    .hasDevelTools                                              # #nocov end
}


# insert a dynlib entry into the cache
.sourceCppDynlibInsert <- function(cacheDir, file, code, dynlib) {
    cache <- .sourceCppDynlibReadCache(cacheDir)
    index <- .sourceCppFindCacheEntryIndex(cache, file, code)
    if (is.null(index))
        index <- length(cache) + 1
    cache[[index]] <- list(file = file, code = code, dynlib = dynlib)
    .sourceCppDynlibWriteCache(cacheDir, cache)
}

# attempt to lookup a dynlib entry from the cache
.sourceCppDynlibLookup <- function(cacheDir, file, code) {
    cache <- .sourceCppDynlibReadCache(cacheDir)
    index <- .sourceCppFindCacheEntryIndex(cache, file, code)
    if (!is.null(index))
        cache[[index]]$dynlib
    else
        list()
}

# write the cache to disk
.sourceCppDynlibWriteCache <- function(cacheDir, cache) {
    index_file <- file.path(cacheDir, "cache.rds")
    save(cache, file = index_file, compress = FALSE)
}

# read the cache from disk
.sourceCppDynlibReadCache <- function(cacheDir) {
    index_file <- file.path(cacheDir, "cache.rds")
    if (file.exists(index_file)) {
        load(file = index_file)
        get("cache")
    } else {
        list()
    }
}

# search the cache for an entry that matches the file or code argument
.sourceCppFindCacheEntryIndex <- function(cache, file, code) {

    if (length(cache) > 0) {
        for (i in 1:length(cache)) {
            entry <- cache[[i]]
            if ((nzchar(file) && identical(file, entry$file)) ||
                (nzchar(code) && identical(code, entry$code))) {
                if (file.exists(entry$dynlib$cppSourcePath))
                    return(i)
            }
        }
    }

    # none found
    NULL
}

# generate an R version / Rcpp version specific cache dir for dynlibs
.sourceCppPlatformCacheDir <- function(cacheDir) {

    dir <- file.path(cacheDir,
                     paste("sourceCpp",
                           R.version$platform,
                           utils::packageVersion("Rcpp"),
                           sep = "-"))
    if (!utils::file_test("-d", dir))
        dir.create(dir, recursive = TRUE)

    dir
}

# generate a unique token for a cacheDir
.sourceCppDynlibUniqueToken <- function(cacheDir) {
    # read existing token (or create a new one)
    token_file <- file.path(cacheDir, "token.rds")
    if (file.exists(token_file))
        load(file = token_file)
    else
        token <- 0

    # increment
    token <- token + 1

    # write it
    save(token, file = token_file)

    # return it as a string
    as.character(token)
}

.extraRoutineRegistrations <- function(targetFile, routines) {

    declarations = character()
    call_entries = character()

    # if we are running R 3.4 or higher we can use an internal utility function
    # to automatically discover additional native routines that require registration
    if (getRversion() >= "3.4") {

        # determine the package directory
        pkgdir <- dirname(dirname(targetFile))

        # get the generated code from R
        con <- textConnection(object = NULL, open = "w")
        on.exit(close(con), add = TRUE)
        tools::package_native_routine_registration_skeleton(
            dir = pkgdir,
            con = con,
            character_only = FALSE
        )
        code <- textConnectionValue(con)

        # look for lines containing call entries
        matches <- regexec('^\\s+\\{"([^"]+)",.*$', code)
        matches <- regmatches(code, matches)
        matches <- Filter(x = matches, function(x) {
            length(x) > 0
        })
        for (match in matches) {
            routine <- match[[2]]
            if (!routine %in% routines) {
                declaration <- grep(sprintf("^extern .* %s\\(.*$", routine), code,
                                    value = TRUE)
                declarations <- c(declarations, sub("^extern", "RcppExport", declaration))
                call_entries <- c(call_entries, match[[1]])
            }
        }
    }

    # return extra declaratiosn and call entries
    list(declarations = declarations,
         call_entries = call_entries)
}
