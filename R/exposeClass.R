.stdHeader <- c(
    "#include <Rcpp.h>",
    "using namespace Rcpp ;"
    )

.asString <- function(what) if(is.character(what)) what else deparse(what)

.strings <- function(expr) {
    if(is.call(expr) && ! identical(expr[[1]], quote(`::`)))
        lapply(as.list(expr)[-1], .strings)
    else
        .asString(expr)
}

.specifyItems <- function(what) {
    what <- as.list(what)
    wn <- allNames(what)
    simple <- !nzchar(wn)
    ## todo:  error checking here that unnamed elements are single strings
    wn[simple] <- as.character(what[simple])
    names(what) <- wn
    what[simple] <- list(character())
    what
}

.writeFieldFunction <- function(fldi, typei, CppClass, readOnly, ns, con){
    rootName <- paste0("field_", fldi)
    writeLines(sprintf("    %s %s_get(%s *obj) { return obj->%s; }\n",
                       typei, rootName, CppClass, fldi), con)
    value <- "_get"
    if(!readOnly) {
        writeLines(sprintf("    void %s_set(%s *obj, %s value) { obj->%s = value; }\n",
                           rootName, CppClass, typei, fldi), con)
        value <- c(value, "_set")
    }
    paste0(ns, "::field_", fldi, value)
}

.writeMethodFunction <- function(mdi, sigi, CppClass, ns, con) {
    mName <- paste0("method_", mdi)
    if(length(sigi) < 1)
        stop(gettextf("The type signature for method %s for class %s was of length 0: Must at least include the return type",
                      mdi, CppClass))
    rtnType <- sigi[[1]]
    sigi <- sigi[-1]
    if(length(sigi)) {
        argNames <- paste0("a", seq_along(sigi))
        args <- paste(" ,", paste(sigi, argNames, collapse = ", "))
    }
    else argNames <- args <- ""
    writeLines(sprintf("    %s %s(%s *obj%s){ return obj->%s(%s); }\n",
                       rtnType, mName, CppClass, args, mdi, argNames), con)
    paste0(ns, "::",mName)
}

exposeClass <- function(class, constructors, fields, methods,
                        file = paste0(CppClass, "Module.cpp"),
                        header = character(),
                        module = paste0("class_",class), CppClass = class,
                        readOnly = character(), rename = character(),
                        Rfile = TRUE) {
    ## some argument checks
    ## TODO:  checks on constructors, fields, methods
    if(length(readOnly)) {
        readOnly <- as.character(readOnly)
        if(!all(nzchar(readOnly)))
            stop("argument readOnly should be a vector of non-empty strings")
    }
    newnames <- allNames(rename)
    if(length(rename)) {
        if(!all(sapply(rename, function(x) is.character(x) && length(x) == 1 && nzchar(x))))
            stop("argument rename should be a vector of single, non-empty strings")
        if(!all(nzchar(newnames)))
            stop("all the elements of argument rename should be non-empty strings")
    }
    if(is.character(file)) {
        ## are we in a package directory?  Writable, searchable src subdirectory:
        if(file.access("src",3)==0)
            cfile <- file.path("src", file)
        else
            cfile <- file
        con <- file(cfile, "w")
        on.exit({message(sprintf("Wrote C++ file \"%s\"", cfile)); close(con)})
    }
    else
        con <- file
    ## and for the R code:
    if(identical(Rfile, FALSE)) {}
    else {
        if(identical(Rfile, TRUE))
            Rfile <- sprintf("%sClass.R",class)
        if(is.character(Rfile)) {
            if(file.access("R",3)==0) # in a package directory
                Rfile <- file.path("R", Rfile)
            Rcon <- file(Rfile, "w")
            msg <- sprintf("Wrote R file \"%s\"",Rfile)
            on.exit({message(msg); close(Rcon)}, add = TRUE)
        }
        else
            Rcon <- Rfile
        Rfile <- TRUE
    }
    mfile <- tempfile()
    mcon <- file(mfile, "w")
    writeLines(.stdHeader, con)
    if(length(header))
        writeLines(header, con)
    writeLines(c("", sprintf("RCPP_MODULE(%s) {\n",module), ""), mcon)
    writeLines(sprintf("    class_<%s>(\"%s\")\n", CppClass, class), mcon)

    ## the constructors argument defines a list of vectors of types
    for( cons in constructors) {
        if(length(cons) > 1 ||
           (length(cons) == 1 && nzchar(cons) && !identical(cons, "void")))
            cons <- paste0("<", paste(cons, collapse = ","),">")
        else
            cons = ""
        writeLines(paste0("    .constructor",cons,"()"),mcon)
    }
    writeLines("", mcon)
    flds <- .specifyItems(fields)
    nm <- names(flds)
    rdOnly <- nm %in% readOnly
    macros <- ifelse(rdOnly, ".field_readonly", ".field")
    test <- nm %in% rename
    if(any(test))
        nm[test] <- newnames[match(nm[test], newnames)]
    ns <- NULL
    for(i in seq_along(nm)) {
        typei <- flds[[i]]
        nmi <- fldi <- nm[[i]]
        macroi <- macros[[i]]
        if(!length(typei) || identical(typei, "")) ## direct field
            writeLines(sprintf("    %s(\"%s\", &%s::%s)",
                   macroi, nmi, CppClass, fldi), mcon)
        else { # create a free function, e.g. for an inherited field
            if(is.null(ns)) { # enclose in a namespace
                ns <- paste("module",class,"NS", sep = "_")
                writeLines(sprintf("\nnamespace %s {\n", ns),
                           con)
            }
            fldFuns <- .writeFieldFunction(fldi, typei, CppClass, rdOnly[[i]], ns, con)
            if(rdOnly[[i]])
                ## NOTE:  string 3rd arg. required by problem w. module parsing 10/3/13
                writeLines(sprintf("    .property(\"%s\", &%s, \"read-only field\")",
                      nmi, fldFuns[[1]]), mcon)
            else
                writeLines(sprintf("    .property(\"%s\", &%s, &%s)",
                      nmi, fldFuns[[1]], fldFuns[[2]]), mcon)
        }
    }
    writeLines("", mcon)
    sigs <- .specifyItems(methods)
    nm <- mds <- names(sigs)
    test <- nm %in% rename
    if(any(test))
        nm[test] <- newnames[match(nm[test], newnames)]
    for(i in seq_along(nm)) {
        sigi <- sigs[[i]]
        nmi <-  nm[[i]]
        mdi <- mds[[i]]
        if(!length(sigi) || identical(sigi, "")) # direct method
            writeLines(sprintf("    .method(\"%s\", &%s::%s)",
                   nmi, CppClass, mdi), mcon)
        else { # create a free function, e.g. for an inherited method
            if(is.null(ns)) { # enclose in a namespace
                ns <- paste("module",class,"NS", sep = "_")
                writeLines(sprintf("\nnamespace %s {\n", ns),
                           con)
            }
            mFun <- .writeMethodFunction(mdi, sigi, CppClass, ns, con)
            writeLines(sprintf("    .method(\"%s\", &%s)",
                  nmi, mFun), mcon)
        }
    }

    writeLines("    ;\n}", mcon)
    close(mcon)
    if(!is.null(ns))
        writeLines(sprintf("} // %s", ns), con) # close namespace
    writeLines(readLines(mfile), con)
    if(Rfile) {
        if(missing(CppClass))
            CppString <- ""
        else
            CppString <- paste(",",dQuote(CppClass))
        if(missing(module))
            ModString <- ""
        else
            ModString <- paste(", module =", dQuote(module))
        writeLines(sprintf("%s <- setRcppClass(\"%s\"%s%s)",
                               class, class, CppString,ModString), Rcon)
    }
}



