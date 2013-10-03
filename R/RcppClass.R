# Copyright (C) 2010 - 2012 John Chambers, Dirk Eddelbuettel and Romain Francois
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


setRcppClass <- function(Class, CppClass,
                         module,
                         fields = list(),
                         contains = character(),
                         methods = list(),
                         saveAs = Class,
                         where = topenv(parent.frame()),
                         ...) {
    myCall <- match.call()
    myCall[[1]] <- quote(Rcpp::loadRcppClass)
    if(!missing(module) && moduleIsLoaded(module, where)) # eval now
        eval.parent(myCall)
    else {
        f <- function(NS)NULL
        myCall$where = as.name("NS")
        body(f, where) <- myCall
        setLoadAction(f, where = where)
    }
}

loadRcppClass <- function(Class, CppClass = Class,
                         module = paste0("class_",Class),
                         fields = character(),
                         contains = character(),
                         methods = list(),
                         saveAs = Class,
                         where = topenv(parent.frame()),
                         ...) {

    if(isBotchedSession()) {
        value <- setRefClass(Class, fields = fields, methods = methods,  contains = contains, where = where, ...)  # kludge -- see loadModule.R
        if(is.character(saveAs) && length(saveAs) == 1)
            assign(saveAs, value, envir = where)
        return(value)
    }
    mod <- loadModule(module, NULL, env = where, loadNow = TRUE)
    storage <- get("storage", envir = as.environment(mod))
    if(exists(CppClass, envir = storage, inherits = FALSE)) {
        cppclassinfo <- get(CppClass, envir = storage)
        if(!is(cppclassinfo, "C++Class"))
            stop(gettextf("Object \"%s\" in module \"%s\" is not a C++ class description", CppClass, module))
    }
    else
        stop(gettextf("No object \"%s\" in module \"%s\"", CppClass, module))
    allmethods <- .makeCppMethods(methods, cppclassinfo, where)
    allfields <- .makeCppFields(fields, cppclassinfo, where)
    value <- setRefClass(Class, fields = allfields,
                         contains = c(contains, "RcppClass"),
                         methods = allmethods, where=where, ...)
    ## declare the fields and methods to shut up codetools
    ## the R level fields and methods were declared by setRefClass
    ## but we declare them again; globalVariables() applies unique()
    if(exists("globalVariables", envir = asNamespace("utils"))) # >=2.15.1
       utils::globalVariables(c(names(allfields), names(allmethods)),
                              where)
    if(is.character(saveAs) && length(saveAs) == 1)
        assign(saveAs, value, envir = where)
    value
}

.makeCppMethods <- function(methods, cppclassinfo, env) {
    cppMethods <- names(cppclassinfo@methods)
    newMethods <- names(methods)
    for(what in cppMethods[! cppMethods %in% newMethods])
        methods[[what]] <- eval(substitute(
                  function(...) .CppObject$WHAT(...), list(WHAT = as.name(what))),
                                env)
    methods
}

.makeFieldsList <- function(fields) {
    fnames <- allNames(fields)
    any_s <- !nzchar(fnames)
    fnames[any_s] <- fields[any_s]
    fields[any_s] <- "ANY"
    fields <- as.list(fields)
    names(fields) <- fnames
    fields
}

.makeCppFields <- function(fields, cppclassinfo, env) {
    if(is.character(fields))
        fields <- .makeFieldsList(fields)
    cppFields <- names(cppclassinfo@fields)
    newFields <- names(fields)
    for(what in cppFields[! cppFields %in% newFields])
        fields[[what]] <- eval(substitute(
            function(value) if(missing(value)) .CppObject$WHAT else .CppObject$WHAT <- value,
                 list(WHAT = as.name(what))), env)
    ## insert the generator and cppclass def as constants
    cppgenerator <- getRefClass(cppclassinfo)
    fields[[".CppClassDef"]] <- eval(substitute(
            function(value) if(missing(value)) DEF else stop("this field is a constant"),
                 list(DEF = cppclassinfo)), env)
    fields[[".CppGenerator"]] <- eval(substitute(
            function(value) if(missing(value)) DEF else stop("this field is a constant"),
                 list(DEF = cppgenerator)), env)
    fields
}

.RcppClass <- setRefClass("RcppClass",
                          methods = list(
                          initialize = function(...){
                              args <- list(...)
                              argNames <- allNames(args)
                              cppArgs <- !nzchar(argNames)
                              .CppObject <<- do.call(.CppGenerator$new, args[cppArgs])
                              for(i in seq_along(args)[!cppArgs])
                                  field(argNames[[i]], args[[i]])
                          }
                          ),
                          fields = list(
                              .CppObject = "C++Object"
                          ),
                          contains = "VIRTUAL"
                          )

.RcppClass$methods(show = function ()
               {
                   cat("Rcpp class object of class ", classLabel(class(.self)),
                       "\n", sep = "")
                   fields <- names(.refClassDef@fieldClasses)
                   if(".CppObject" %in% fields) {
                       cat("\n")
                       methods::show(field(".CppObject"))
                       cat("\n")
                   }
                   fields <- fields[ ! fields %in% c(".CppObject", ".CppClassDef", ".CppGenerator")]
                   for (fi in fields) {
                       cat("Field \"", fi, "\":\n", sep = "")
                       methods::show(field(fi))
                   }
               },
    objectPointer = function()
           .CppObject$.pointer
    )



