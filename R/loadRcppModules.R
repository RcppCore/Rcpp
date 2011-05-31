
loadRcppModules <- function(direct=TRUE){
   # hunt for the namespace of the package that calls this
   calls <- sys.calls()
   w <- which( sapply( calls, function(call){
      identical( call[[1L]], as.name( "runHook" ) ) 
   } ) )
   if( !length(w) ) 
    stop( "loadRcppModules can only be used within a .onLoad function" )
   w <- w[ length(w) ]
   call <- calls[[w]]
   if( !identical( call[[2L]], ".onLoad" ) ) 
    stop( "loadRcppModules can only be used within a .onLoad function" )
   f <- sys.frame( w )
   ns <- get("env", f )
   if( !isNamespace( ns ) ) 
    stop( "loadRcppModules not called from a namespace" )
   pkg <- get( "pkgname", f )
    
   # look for declared modules in the DESCRIPTION fields
   description <- packageDescription( pkg )
   modules <- description[["RcppModules"]]
   if( !is.null( modules ) ){
        modules <- strsplit( modules, "[[:space:]]*,[[:space:]]*")[[1L]]
        for( m in modules ){
            tryCatch( {
                mod <- Module( m, pkg, mustStart = TRUE)
                if(isTRUE(direct)){
                   populate( mod, ns )
                } else {
                    forceAssignInNamespace( m, mod, ns ) 
                }
            }, error = function(e){
                stop( sprintf( "failed to load module %s from package %s\n%s", m, pkg, conditionMessage(e) ) )  
            })
        }
   }
    
}
