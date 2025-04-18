# Copyright (C) 2009 - 2025  Dirk Eddelbuettel and Romain Francois
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

Rcpp.package.skeleton <- function(name = "anRpackage", list = character(),
                                  environment = .GlobalEnv,
                                  path = ".", force = FALSE,
                                  code_files = character(), cpp_files = character(),
                                  example_code = TRUE, attributes = TRUE, module = FALSE,
                                  author = "Your Name",
                                  maintainer = if (missing(author)) "Your Name"
                                               else author,
                                  email = "your@email.com",
                                  githubuser = NA_character_,
                                  license = "GPL (>= 2)") {

    havePkgKitten <- requireNamespace("pkgKitten", quietly=TRUE)

    call <- match.call()
    call[[1]] <- as.name("package.skeleton")
    env <- parent.frame(1)

    if (!is.character(cpp_files))
        stop("'cpp_files' must be a character vector")				# #nocov

    if (!length(list)) {
        fake <- TRUE
        assign("Rcpp.fake.fun", function() {}, envir = env)
        if (example_code && !isTRUE(attributes)) {
            assign("rcpp_hello_world", function() {}, envir = env)
            remove_hello_world <- TRUE
        } else {
            remove_hello_world <- FALSE
        }
    } else {
        if (example_code && !isTRUE(attributes)) {
            if (!"rcpp_hello_world" %in% list) {					# #nocov start
                assign( "rcpp_hello_world", function() {}, envir = env)
                call[["list"]] <- as.call(c(as.name("c"),
                                            as.list(c("rcpp_hello_world", list))))
            }
            remove_hello_world <- TRUE								# #nocov end
        } else {
            remove_hello_world <- FALSE
        }
        fake <- FALSE
    }

    ## first let the traditional version do its business
    ## remove Rcpp specific arguments

    call <- call[ c(1L, which(names(call) %in% names(formals(package.skeleton)))) ]

    if (fake) {
        call[["list"]] <- c(if(isTRUE(example_code)
                               && !isTRUE(attributes)) "rcpp_hello_world", "Rcpp.fake.fun")
    }

    tryCatch(eval(call, envir = env), error = function(e){
        stop(sprintf("error while calling `package.skeleton` : %s", conditionMessage(e)))	# #nocov
    })

    message("\nAdding Rcpp settings")

    ## now pick things up
    root <- file.path(path, name)

    # Add Rcpp to the DESCRIPTION
    DESCRIPTION <- file.path(root, "DESCRIPTION")
    if (file.exists(DESCRIPTION)) {
        imports <- c(if (isTRUE(module)) "methods", sprintf("Rcpp (>= %s)", getRcppVersion()))
        splitname <- strsplit(author, " ")[[1]]
        x <- cbind(read.dcf(DESCRIPTION,  fields = c("Package", "Type", "Title", "Version", "Date",
                                                     "Description", "License")),
                   "Imports" = paste(imports, collapse = ", "),
                   "LinkingTo" = "Rcpp",
                   "Authors@R" = sprintf("person(\"%s\", \"%s\", role = c(\"aut\", \"cre\"), email = \"%s\")",
                                         paste(splitname[-length(splitname)], collapse=" "),
                                         splitname[length(splitname)],
                                         email))
        fields_written <- c("Package", "Type", "Title", "Version", "Date",
                            "Authors@R", "Description", "License", "Imports", "LinkingTo")
        if (!is.na(githubuser)) {
            x <- cbind(x, matrix("", 1, 1, dimnames=list("", "URL")))
            x[1, "URL"] <- paste0("https://github.com/", githubuser, "/", name)
            x <- cbind(x, matrix("", 1, 1, dimnames=list("", "BugReports")))
            x[1, "BugReports"] <- paste0("https://github.com/", githubuser, "/", name, "/issues")

            fields_written <- c("Package", "Type", "Title", "Version", "Date",
                                "Authors@R", "Description", "URL", "BugReports",
                                "License", "Imports", "LinkingTo")
            }

        x[, "License"] <- license
        x[, "Title"] <- "Concise Summary of What the Package Does"
        x[, "Description"] <- "More about what it does (maybe more than one line)."
        x[, "Version"] <- "0.0.1"
        message( " >> added Imports: Rcpp" )
        message( " >> added LinkingTo: Rcpp" )
        write.dcf(x[1, fields_written, drop = FALSE], file = DESCRIPTION)
    }

    ## add useDynLib and importFrom to NAMESPACE
    NAMESPACE <- file.path(root, "NAMESPACE")
    lines <- readLines(NAMESPACE)
    ns <- file(NAMESPACE, open="w")
    if (!any(grepl("useDynLib", lines))) {
        if (getRversion() >= "3.4.0") {
            lines <- c(sprintf( "useDynLib(%s, .registration=TRUE)", name), lines)
        } else {
            lines <- c(sprintf( "useDynLib(%s)", name), lines)				# #nocov
        }
        writeLines(lines, con = ns)
        message(" >> added useDynLib directive to NAMESPACE" )
    }
    if (isTRUE(module)) {
        writeLines('import(methods, Rcpp)', ns)
        message(" >> added import(methods, Rcpp) directive to NAMESPACE")
    } else {
        writeLines('importFrom(Rcpp, evalCpp)', ns)
        message(" >> added importFrom(Rcpp, evalCpp) directive to NAMESPACE" )
    }
    if (!any(grepl("^exportPattern", lines))) {
        writeLines("exportPattern(\"^[[:alpha:]]+\")", ns)
    }
    close( ns )

    ## update the package description help page
    if (havePkgKitten) {                # if pkgKitten is available, use it
        pkgKitten::playWithPerPackageHelpPage(name, path, maintainer, email)
    } else {
        .playWithPerPackageHelpPage(name, path, maintainer, email)			# #nocov
    }

    ## lay things out in the src directory
    src <- file.path(root, "src")
    if (!file.exists(src)) {
        dir.create(src)
    }
    skeleton <- system.file("skeleton", package = "Rcpp")

    if (length(cpp_files) > 0L) {
        for (file in cpp_files) {											# #nocov start
            file.copy(file, src)
            message(" >> copied ", file, " to src directory" )				# #nocov end
        }
    }

    if (example_code) {
        if (isTRUE(attributes)) {
            file.copy(file.path( skeleton, "rcpp_hello_world_attributes.cpp"),
                      file.path( src, "rcpp_hello_world.cpp"))
            message(" >> added example src file using Rcpp attributes")
        } else {
            header <- readLines(file.path(skeleton, "rcpp_hello_world.h"))
            header <- gsub("@PKG@", name, header, fixed = TRUE)
            writeLines(header , file.path(src, "rcpp_hello_world.h"))
            message(" >> added example header file using Rcpp classes")

            file.copy(file.path(skeleton, "rcpp_hello_world.cpp"), src)
            message(" >> added example src file using Rcpp classes")

            rcode <- readLines(file.path( skeleton, "rcpp_hello_world.R"))
            rcode <- gsub("@PKG@", name, rcode, fixed = TRUE)
            writeLines( rcode , file.path( root, "R", "rcpp_hello_world.R"))
            message(" >> added example R file calling the C++ example")
        }

        hello.Rd <- file.path(root, "man", "rcpp_hello_world.Rd")
        unlink(hello.Rd)
        file.copy(system.file("skeleton", "rcpp_hello_world.Rd", package = "Rcpp"), hello.Rd)
        message( " >> added Rd file for rcpp_hello_world")
    }

    if (isTRUE(module)) {
        file.copy(system.file("skeleton", "rcpp_module.cpp", package="Rcpp"),
                  file.path(root, "src"))
        file.copy(system.file("skeleton", "Num.cpp", package="Rcpp"),
                  file.path(root, "src"))
        file.copy(system.file("skeleton", "stdVector.cpp", package="Rcpp"),
                  file.path(root, "src"))
        file.copy(system.file("skeleton", "zzz.R", package ="Rcpp"),
                  file.path(root, "R"))
        file.copy(system.file("skeleton", "Rcpp_modules_examples.Rd", package ="Rcpp"),
                  file.path(root, "man"))
        message(" >> copied the example module file ")
    }

    # generate native routines if we aren't using attributes (which already generate
    # them automatically) and we have at least R 3.4
    if (!attributes) {
        if (getRversion() >= "3.4.0") {
            con <- file(file.path(src, "init.c"), "wt")
            tools::package_native_routine_registration_skeleton(root, con=con)
            close(con)
            message(" >> created init.c for package registration")
        } else {
            message(" >> R version older than 3.4.0 detected, so NO file init.c created.")	# #nocov
        }
    }

    lines <- readLines(package.doc <- file.path( root, "man", sprintf("%s-package.Rd", name)))
    lines <- sub("~~ simple examples", "%% ~~ simple examples", lines)

    lines <- lines[! grepl("~~ package title", lines)]
    lines <- lines[! grepl("~~ The author and", lines)]
    lines <- sub("Who wrote it", author, lines )
    lines <- sub("Who to complain to.*", sprintf("%s <%s>", maintainer, email), lines)

    writeLines(lines, package.doc)

    if (fake) {
        rm("Rcpp.fake.fun", envir = env)
        unlink(file.path(root, "R"  , "Rcpp.fake.fun.R"))
        unlink(file.path(root, "man", "Rcpp.fake.fun.Rd"))

        ## cleansing NAMESPACE of fake function entry
        lines <- readLines(NAMESPACE)
        lines <- lines[!grepl("^export.*fake\\.fun", lines)]
        writeLines(lines, NAMESPACE)
    }

    if (isTRUE(remove_hello_world)) {
        rm("rcpp_hello_world", envir = env)
    }

    if (attributes) {
        compileAttributes(root)
        message(" >> compiled Rcpp attributes ")
    }

    invisible(NULL)
}

## Borrowed with love from pkgKitten, and modified slightly
.playWithPerPackageHelpPage <- function(name = "anRpackage",
                                        path = ".",
                                        maintainer = "Your Name",
                                        email = "your@mail.com") {
    root <- file.path(path, name)										# #nocov start
    helptgt <- file.path(root, "man", sprintf( "%s-package.Rd", name))
    helpsrc <- system.file("skeleton", "manual-page-stub.Rd", package="Rcpp")
    ## update the package description help page
    if (file.exists(helpsrc)) {
        lines <- readLines(helpsrc)
        lines <- gsub("__placeholder__", name, lines, fixed = TRUE)
        lines <- gsub("Who to complain to <yourfault@somewhere.net>",
                      sprintf( "%s <%s>", maintainer, email),
                      lines, fixed = TRUE)
        writeLines(lines, helptgt)
    }
    invisible(NULL)														# #nocov end
}
