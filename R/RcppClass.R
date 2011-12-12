.RcppClass <- setRefClass("RcppClass",
            methods = list(
                initialize = function(...){
                    args <- list(...)
                    argNames <- allNames(args)
                    cppArgs <- !nzchar(argNames)
                    if(any(cppArgs)) {
                        do.call(Rcpp:::cpp_object_initializer, c(list(.self, .refClassDef), args[cppArgs]))
                        args <- args[!cppArgs]
                    }
                    else
                        Rcpp:::cpp_object_dummy(.self, .refClassDef)
                    ## <FIXME>
                    ## should be a way to have both superclasses & Cpp args
                    ## </FIXME>
                    if(any(args))
                        initRefFields(cppObj, def, as.environemnt(cppObj), args)
            }
            )
     )

## <Temporary:>  currently class "C++Object" redefines the S4 method for show,
## preventing subclasses from having a $show() method.  It should define a $show()
## method instead.  Meanwhile, we restore the standard reference class method

setMethod("show", "RcppClass", selectMethod("show", "envRefClass"))

.showCpp <- function (object) 
{
    env <- as.environment(object)
    pointer <- get(".pointer", envir = env)
    cppclass <- get(".cppclass", envir = env)
    txt <- sprintf("C++ object <%s> of class '%s' <%s>", externalptr_address(pointer), 
        .Call(Class__name, cppclass), externalptr_address(cppclass))
    writeLines(txt)
}


.RcppClass$methods(show = function () 
{
    cat("Rcpp class object of class ", classLabel(class(.self)), 
        "\n", sep = "")
    fields <- names(.refClassDef@fieldClasses)
    for (fi in fields) {
        cat("Field \"", fi, "\":\n", sep = "")
        methods::show(field(fi))
    }
    cat("Extending "); Rcpp:::.showCpp(.self)
}
)

## </Temporary:>

setRcppClass <- function(Class, CppClass = "<UNDEFINED>", fields = list(),
                        contains = character(),
                        methods = list(),
                        where = topenv(parent.frame()),
                        ...) {
    if(!is(CppClass, "C++Class"))
        stop(gettextf("\"%s\" is not a C++ Class", "RcppClass", CppClass))
    setRefClass(Class, fields = fields,
                         contains = c(contains, "RcppClass", as.character(CppClass)),
                         methods = methods,
                         where = where,
                         ...)
}
