# Copyright (C) 2012 JJ Allaire, Dirk Eddelbuettel and Romain Francois
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
                      showOutput = verbose,
                      verbose = getOption("verbose")) {

    # resolve code into a file if necessary. also track the working
    # directory to source the R embedded code chunk within
    if (!missing(code)) {
        rWorkingDir <- getwd() 
        file <- tempfile(fileext = ".cpp")
        con <- file(file, open = "w")
        writeLines(code, con)
        close(con)
    } else {
        rWorkingDir <- dirname(file)
    }

    # resolve the file path
    file <- normalizePath(file, winslash = "/")

    # error if the file extension isn't one supported by R CMD SHLIB
    if (! tools::file_ext(file) %in% c("cc", "cpp")) {
        stop("The filename '", basename(file), "' does not have an ",
             "extension of .cc or .cpp so cannot be compiled.")
    }

    # validate that there are no spaces in the path on windows
    if (.Platform$OS.type == "windows") {
        if (grepl(' ', basename(file), fixed=TRUE)) {
            stop("The filename '", basename(file), "' contains spaces. This ",
                 "is not permitted.")
        }
    }

    # get the context (does code generation as necessary)
    context <- .Call("sourceCppContext", PACKAGE="Rcpp",
                     file, code, rebuild, .Platform)

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
            .restoreEnvironment(envRestore)
            setwd(cwd)
            return (invisible(NULL))
        }

        # on.exit handler calls hook and restores environment and working dir
        on.exit({
            if (!succeeded)
                .showBuildFailureDiagnostics()
            .callBuildCompleteHook(succeeded, output)
            setwd(cwd)
            .restoreEnvironment(envRestore)
        })

        # unload and delete existing dylib if necessary
        if (file.exists(context$previousDynlibPath)) {
            try(silent=T, dyn.unload(context$previousDynlibPath))
            file.remove(context$previousDynlibPath)
        }

        # prepare the command (output if we are in showOutput mode)
        cmd <- paste(R.home(component="bin"), .Platform$file.sep, "R ",
                     "CMD SHLIB ",
                     "-o ", shQuote(context$dynlibFilename), " ",
                     ifelse(rebuild, "--preclean ", ""),
                     shQuote(context$cppSourceFilename), sep="")
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
                cat(result, "\n")
                succeeded <- FALSE
                stop("Error ", status, " occurred building shared library.")
            } else if (!file.exists(context$dynlibFilename)) {
                cat(result, "\n")
                succeeded <- FALSE
                stop("Error occurred building shared library.")
            } else {
                succeeded <- TRUE
            }
        }
        else if (!identical(as.character(result), "0")) {
            succeeded <- FALSE
            stop("Error ", result, " occurred building shared library.")
        } else {
            succeeded <- TRUE
        }
    }
    else {
        if (verbose)
            cat("\nNo rebuild required (use rebuild = TRUE to ",
                "force a rebuild)\n\n", sep="")
    }

    # load the module if we have exported symbols
    if (length(context$exportedFunctions) > 0 || length(context$modules) > 0) {

        # remove existing objects of the same name from the environment
        exports <- c(context$exportedFunctions, context$modules)
        removeObjs <- exports[exports %in% ls(envir = env, all.names = T)]
        remove(list = removeObjs, envir = env)

        # source the R script
        scriptPath <- file.path(context$buildDirectory, context$rSourceFilename)
        source(scriptPath, local = env)

    } else if (getOption("rcpp.warnNoExports", default=TRUE)) {
        warning("No Rcpp::export attributes or RCPP_MODULE declarations ",
                "found in source")
    }

    # source the embeddedR
    if (embeddedR && (length(context$embeddedR) > 0)) {
        srcConn <- textConnection(context$embeddedR)
        setwd(rWorkingDir) # will be reset by previous on.exit handler
        source(file=srcConn, echo=TRUE)
    }

    # return (invisibly) a list containing exported functions and modules
    invisible(list(functions = context$exportedFunctions,
                   modules = context$modules))
}

# Define a single C++ function
cppFunction <- function(code,
                        depends = character(),
                        plugins = character(),
                        includes = character(),
                        env = parent.frame(),
                        rebuild = FALSE,
                        showOutput = verbose,
                        verbose = getOption("verbose")) {

    # process depends
    if (!is.null(depends) && length(depends) > 0) {
        depends <- paste(depends, sep=", ")
        scaffolding <- paste("// [[Rcpp::depends(", depends, ")]]", sep="")
        scaffolding <- c(scaffolding, "", .linkingToIncludes(depends, FALSE),
                         recursive=TRUE)
    }
    else {
        scaffolding <- "#include <Rcpp.h>"
    }

    # process plugins
    if (!is.null(plugins) && length(plugins) > 0) {
        plugins <- paste(plugins, sep=", ")
        pluginsAttrib <- paste("// [[Rcpp::plugins(", plugins, ")]]", sep="")
        scaffolding <- c(scaffolding, pluginsAttrib)

        # append plugin includes
        for (pluginName in plugins) {
            plugin <- .findPlugin(pluginName)
            settings <- plugin()
            scaffolding <- c(scaffolding, settings$includes, recursive=TRUE)
        }
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
    if (verbose) {
        cat("\nGenerated code for function definition:",
            "\n--------------------------------------------------------\n\n")
        cat(code)
        cat("\n")
    }

    # source cpp into specified environment. if env is set to NULL
    # then create a new one (the caller can get a hold of the function
    # via the return value)
    if (is.null(env))
        env <- new.env()
    exported <- sourceCpp(code = code,
                          env = env,
                          rebuild = rebuild,
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
    function( type = "int", ... ){
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
    }
}

demangle <- .type_manipulate( "DEMANGLE" )
sizeof   <- .type_manipulate( "sizeof", "bytes" )

print.bytes <- function( x, ...){
    writeLines( sprintf( "%d bytes (%d bits)", x, 8 * x ) )
    invisible( x )    
}

# Evaluate a simple c++ expression
evalCpp <- function(code,
                    depends = character(),
                    includes = character(),
                    rebuild = FALSE,
                    showOutput = verbose,
                    verbose = getOption( "verbose" ) ){


    code <- sprintf( "SEXP get_value(){ return wrap( %s ) ; }", code )
    env <- new.env()
    cppFunction(code, depends = depends, includes = includes, env = env,
                rebuild = rebuild, showOutput = showOutput, verbose = verbose )
    fun <- env[["get_value"]]
    fun()
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
    depends <- .readPkgDescField(pkgDesc, "Depends", character())
    depends <- unique(.splitDepends(depends))
    depends <- depends[depends != "R"]

    # determine source directory
    srcDir <- file.path(pkgdir, "src")
    if (!file.exists(srcDir))
        return (FALSE)

    # create R directory if it doesn't already exist
    rDir <- file.path(pkgdir, "R")
    if (!file.exists(rDir))
        dir.create(rDir)

    # get a list of all source files
    cppFiles <- list.files(srcDir, pattern="\\.c(c|pp)$")

    # derive base names (will be used for modules)
    cppFileBasenames <- tools::file_path_sans_ext(cppFiles)

    # expend them to their full paths
    cppFiles <- file.path(srcDir, cppFiles)
    cppFiles <- normalizePath(cppFiles, winslash = "/")

    # generate the includes list based on LinkingTo. Specify plugins-only
    # because we only need as/wrap declarations
    linkingTo <- .readPkgDescField(pkgDesc, "LinkingTo")
    includes <- .linkingToIncludes(linkingTo, TRUE)

    # if a master include file is defined for the package then include it
    pkgHeader <- paste(pkgname, ".h", sep="")
    pkgHeaderPath <- file.path(pkgdir, "inst", "include",  pkgHeader)
    if (file.exists(pkgHeaderPath)) {
        pkgInclude <- paste("#include \"../inst/include/",
                            pkgHeader, "\"", sep="")
        includes <- c(pkgInclude, includes)
    }

    # generate exports
    invisible(.Call("compileAttributes", PACKAGE="Rcpp",
                    pkgdir, pkgname, depends, cppFiles, cppFileBasenames,
                    includes, verbose, .Platform))
}

# setup plugins environment
.plugins <- new.env()

# built-in C++11 plugin
.plugins[["cpp11"]] <- function() {
    list(env = list(PKG_CXXFLAGS ="-std=c++11"))
}

## built-in OpenMP++11 plugin
.plugins[["openmp"]] <- function() {
    list(env = list(PKG_CXXFLAGS="-fopenmp",
                    PKG_LIBS="-fopenmp"))
}

# register a plugin
registerPlugin <- function(name, plugin) {
    .plugins[[name]] <- plugin
}


# Take an empty function body and connect it to the specified external symbol
sourceCppFunction <- function(func, isVoid, dll, symbol) {

    args <- names(formals(func))

    body <- quote( CALL_PLACEHOLDER ( EXTERNALNAME, ARG ) )[ c(1:2, rep(3, length(args))) ]

    for (i in seq(along = args))
        body[[i+2]] <- as.symbol(args[i])

    body[[1L]] <- .Call
    body[[2L]] <- getNativeSymbolInfo(symbol, dll)$address

    if (isVoid)
        body <- call("invisible", body)

    body(func) <- body

    func
}


# Print verbose output
.printVerboseOutput <- function(context) {

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
}

# Add LinkingTo dependencies if the sourceFile is in a package
.getSourceCppDependencies <- function(depends, sourceFile) {

    # If the source file is in a package then simulate it being built
    # within the package by including it's LinkingTo dependencies,
    # the src directory (.), and the inst/include directory
    if (.isPackageSourceFile(sourceFile)) {
        descFile <- file.path(dirname(sourceFile), "..", "DESCRIPTION")
        DESCRIPTION <- read.dcf(descFile, all = TRUE)
        linkingTo <- .parseLinkingTo(DESCRIPTION$LinkingTo)
        unique(c(depends, linkingTo))
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
    if (length(unavailable) > 0) {
        stop(paste("Package '", unavailable[[1]], "' referenced from ",
                    "Rcpp::depends in source file ",
                      sourceFilename, " is not available.",
                      sep=""),
                call. = FALSE)
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
.getInlinePlugin <- function(package) {
    tryCatch(get("inlineCxxPlugin", asNamespace(package)),
             error = function(e) NULL)
}

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
            return;

        # if it doesn't exist already just set it
        if (is.null(buildEnv[[name]])) {
            buildEnv[[name]] <<- value
        }
        # if it's not identical then append
        else if (!identical(buildEnv[[name]], value)) {
            buildEnv[[name]] <<- paste(buildEnv[[name]], value);
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

        # add a LinkingTo for this package
        linkingToPackages <- unique(c(linkingToPackages, package))

        # see if the package exports a plugin
        plugin <- .getInlinePlugin(package)
        if (!is.null(plugin))
           setDependenciesFromPlugin(plugin)
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

    # if the source file is in a package then add src and inst/include
    if (.isPackageSourceFile(sourceFile)) {
        srcDir <- dirname(sourceFile)
        srcDir <- asBuildPath(srcDir)
        incDir <- file.path(dirname(sourceFile), "..", "inst", "include")
        incDir <- asBuildPath(incDir)
        dirFlags <- paste0('-I"', c(srcDir, incDir), '"', collapse=" ")
        buildEnv$CLINK_CPPFLAGS <- paste(buildEnv$CLINK_CPPFLAGS,
                                         dirFlags,
                                         collapse=" ")
    }

    # merge existing environment variables
    for (name in names(buildEnv))
        mergeIntoBuildEnv(name, Sys.getenv(name))

    # add cygwin message muffler
    buildEnv$CYGWIN = "nodosfilewarning"

    # on windows see if we need to add Rtools to the path
    # (don't do this for RStudio since it has it's own handling)
    if (identical(Sys.info()[['sysname']], "Windows") &&
        !nzchar(Sys.getenv("RSTUDIO"))) {
        path <- .pathWithRtools()
        if (!is.null(path))
            buildEnv$PATH <- path
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
.pathWithRtools <- function() {

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

            # Check version -- we only support 2.15 and 2.16 right now
            ver <- key$`Current Version`
            if (identical("2.15", ver) || identical("2.16", ver) ||
                identical("3.0", ver) || identical("3.1", ver)) {

                # See if the InstallPath leads to the expected directories
                rToolsPath <- key$`InstallPath`
                if (!is.null(rToolsPath)) {

                    # Return modified PATH if execpted directories exist
                    binPath <- file.path(rToolsPath, "bin", fsep="\\")
                    gccPath <- file.path(rToolsPath, "gcc-4.6.3", "bin", fsep="\\")
                    if (file.exists(binPath) && file.exists(gccPath))
                        return(paste(binPath,
                                     gccPath,
                                     Sys.getenv("PATH"),
                                     sep=.Platform$path.sep))
                }
            }
        }
    }

    return(NULL)
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

        if (is.character(fun))
            fun <- get(fun)

        # allow the hook to cancel the build (errors in the hook explicitly
        # do not cancel the build since they are unexpected bugs)
        continue <- tryCatch(fun(file, fromCode, showOutput),
                             error = function(e) TRUE)

        if (!continue)
            return (FALSE)
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

        if (is.character(fun))
            fun <- get(fun)

        try(fun(succeeded, output))
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
        plugin <- .getInlinePlugin(package)
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
        }
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
    list(before = before, after = after)
}

# Parse a LinkingTo field into a character vector
.parseLinkingTo <- function(linkingTo) {

    if (is.null(linkingTo))
        return (character())

    linkingTo <- strsplit(linkingTo, "\\s*\\,")[[1]]
    gsub("\\s", "", linkingTo)
}

# show diagnostics for failed builds
.showBuildFailureDiagnostics <- function() {

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
    }
}

# check if R development tools are installed (cache successful result)
.hasDevelTools <- FALSE
.checkDevelTools <- function() {

    if (!.hasDevelTools) {
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
        assignInMyNamespace(".hasDevelTools", is.null(attr(result, "status")))

        # if we build successfully then remove the shared library
        if (.hasDevelTools) {
            lib <- file.path(tempdir(),
                             paste("foo", .Platform$dynlib.ext, sep=''))
            unlink(lib)
        }
    }
    .hasDevelTools
}

