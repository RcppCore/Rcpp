
# Copyright (C) 2010 - 2019  Dirk Eddelbuettel and Romain Francois
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

if (Sys.getenv("RunAllRcppTests") != "yes") exit_file("Set 'RunAllRcppTests' to 'yes' to run.")

if( ! Rcpp:::capabilities()[["Rcpp modules"]] ) exit_file("Skipping as no Modules capability.")

Rcpp::sourceCpp("cpp/Module.cpp")

# checks the presence of "invisible", added when the function returns void
is_void <- function(call) {
    if (length(grep("invisible", deparse(call))) == 0)
        return(FALSE)
    return(TRUE)
}

#    test.Module <- function(){
expect_equal( bar( 2L ), 4L )
expect_equal( foo( 2L, 10.0 ), 20.0 )
expect_equal( hello(), "hello" )

expect_false(is_void(bar@.Data))
expect_false(is_void(foo@.Data))
expect_false(is_void(hello@.Data))
expect_true(is_void(bla@.Data))
expect_true(is_void(bla1@.Data))
expect_true(is_void(bla2@.Data))

## module functions must be called with at least as many arguments as
## the C++ function takes, rather than reading the missing ones from
## uninitialized memory (#1521)
expect_error( foo( 2L ), "expecting 2, got 1" )
expect_error( bar(), "expecting 1, got 0" )
expect_equal( foo_formals(), 20.0 )
expect_equal( foo_formals( y = 3.0 ), 6.0 )
expect_error( foo_short_formals(), "expecting 2, got 1" )

## formals<- finds the .External() call wherever it is in the body, e.g.
## inside the block that coverage tools (covr) wrap each statement in
wrapped <- quote({ if (TRUE) { covr:::count("key"); .External(entry, pointer, ...) } })
expect_equal( deparse( Rcpp:::.cppfunction_set_external_args( wrapped, c("x", "y") ) ),
              deparse( quote({ if (TRUE) { covr:::count("key"); .External(entry, pointer, x, y) } }) ) )

w <- new( ModuleWorld )
expect_equal( w$greet(), "hello" )
w$set( "hello world" )
expect_equal( w$greet(), "hello world" )
w$set_ref( "hello world ref" )
expect_equal( w$greet(), "hello world ref" )
w$set_const_ref( "hello world const ref" )
expect_equal( w$greet(), "hello world const ref" )
w$clear( )
expect_equal( w$greet(), "" )

expect_false(is_void(w$greet))
expect_true(is_void(w$set))
expect_true(is_void(w$set_ref))
expect_true(is_void(w$set_const_ref))
expect_true(is_void(w$clear))

#    test.Module.exposed.class <- function(){
test <- new( ModuleTest, 3.0 )
expect_equal( Test_get_x_const_ref(test), 3.0 )
expect_equal( Test_get_x_const_pointer(test), 3.0 )
expect_equal( Test_get_x_ref(test), 3.0 )
expect_equal( Test_get_x_pointer(test), 3.0 )

expect_false(is_void(Test_get_x_const_ref@.Data))
expect_false(is_void(Test_get_x_const_pointer@.Data))
expect_false(is_void(Test_get_x_ref@.Data))
expect_false(is_void(Test_get_x_pointer@.Data))

expect_equal( attr_Test_get_x_const_ref(test), 3.0 )
expect_equal( attr_Test_get_x_const_pointer(test), 3.0 )
expect_equal( attr_Test_get_x_ref(test), 3.0 )
expect_equal( attr_Test_get_x_pointer(test), 3.0 )

## module object arguments are validated before their address is handed to
## C++, instead of reinterpreting or dereferencing whatever is there (#1523);
## patterns are regular expressions, as tinytest < 1.3.1 has no 'fixed'
expect_error( Test_get_x_const_ref( new( ModuleWorld ) ),
             "Expecting an object of C\\+\\+ class 'ModuleTest', got an object of class 'ModuleWorld'" )
expect_error( attr_Test_get_x_ref( new( ModuleWorld ) ),
             "got an object of class 'ModuleWorld'" )
expect_error( Test_get_x_pointer( unserialize( serialize( test, NULL ) ) ),
             "external pointer is not valid" )
uninitialized <- new( ModuleTest )
expect_error( Test_get_x_ref( uninitialized ), "not initialized" )
expect_error( Test_get_x_const_pointer( 1 ),
             "Expecting an object of C\\+\\+ class 'ModuleTest'" )

## objects of a class that derives() from the expected one are accepted
expect_equal( ModuleBase_value( new( ModuleBase ) ), 1.0 )
expect_equal( ModuleBase_value( new( ModuleDerived ) ), 2.0 )

#    test.Module.property <- function(){
w <- new( ModuleNum )
expect_equal( w$x, 0.0 )
expect_equal( w$y, 0L )

w$x <- 2.0
expect_equal( w$x, 2.0 )

expect_error( { w$y <- 3 } )

## every class_::property() overload; the free getter + member setter one
## did not return *this, which aborted loading the whole module (#1519)
p <- new( ModuleProperties )
p$get_set <- 1.0
expect_equal( p$get_set, 1.0 )
p$get_const_set <- 2.0
expect_equal( p$get_const_set, 2.0 )
p$get_set_free <- 3.0
expect_equal( p$get_set_free, 3.0 )
p$get_const_set_free <- 4.0
expect_equal( p$get_const_set_free, 4.0 )
p$get_free_set <- 5.0
expect_equal( p$get_free_set, 5.0 )
p$get_free_set_free <- 6.0
expect_equal( p$get_free_set_free, 6.0 )

expect_equal( c(p$get, p$get_const, p$get_free), c(6.0, 6.0, 6.0) )
expect_error( { p$get <- 7.0 } )
expect_error( { p$get_const <- 7.0 } )
expect_error( { p$get_free <- 7.0 } )

#    test.Module.member <- function(){
w <- new( ModuleNumber )
expect_equal( w$x, 0.0 )
expect_equal( w$y, 0L )

w$x <- 2.0
expect_equal( w$x, 2.0 )

expect_error( { w$y <- 3 } )

#    test.Module.Constructor <- function() {
r <- new( ModuleRandomizer, 10.0, 20.0 )
set.seed(123)
x10 <- runif(10, 10.0, 20.0)
set.seed(123)
expect_equal(r$get(10), x10)

## calling a method on an uninitialized module object (created via the
## dummy-object path for classes without a default constructor) should
## raise an R error rather than terminating the R session (#1495)
r <- new( ModuleRandomizer )
expect_error( r$get(10L), "not initialized" )

## an exception thrown while a module initializes raises an R error rather
## than terminating the R session, and clears the module scope (#1525)
expect_error( Rcpp::sourceCpp("cpp/ModuleInitError.cpp"), "no such class" )
expect_true( Module_scope_is_cleared() )

## completion lists the ordinary methods and the fields; an overloaded [[
## used to be counted once per overload, which dropped the last ordinary
## method, or ran past the end of the method map when there was none (#1529)
brackets <- new( ModuleBrackets )
expect_equal( Rcpp:::complete( brackets ), c("total( ", "value") )
expect_equal( brackets[[2L]], 2.0 )
expect_equal( Rcpp:::complete( new( ModuleBracketsOnly ) ), "value" )

## a body that throws after registering some of its classes and functions
## leaves nothing behind, so loading the module again does not end up with
## two copies of what the failed run registered
expect_error( Rcpp::sourceCpp("cpp/ModuleInitRetry.cpp"), "first boot fails" )
is_retry_module <- function(dll) is.loaded("_rcpp_module_boot_moduleInitRetry", PACKAGE = dll[["name"]])
dll <- Filter(is_retry_module, getLoadedDLLs())[[1L]]
mod <- Module( "moduleInitRetry", PACKAGE = dll, mustStart = TRUE )
expect_equal( length( mod$ModuleInitRetry@constructors ), 1L )
expect_equal( length( mod$ModuleInitRetry@methods$value@nargs ), 1L )
expect_equal( mod$retry_add_one( 41L ), 42L )
expect_equal( new( mod$ModuleInitRetry )$value(), 42L )

#    test.Module.flexible.semantics <- function( ){
expect_equal( test_reference( seq(0,10) ), 11L )
expect_equal( test_const_reference( seq(0,10) ), 11L )
expect_equal( test_const( seq(0,10) ), 11L )

## mixed-voidness method overloads dispatch through class_::invoke(),
## which must protect the freshly allocated method result while it
## wraps it in the result list (#1493); under gctorture every
## allocation triggers a collection, so a single call exercises the
## unprotected window deterministically
gadget <- new( ModuleGadget )
gctorture(TRUE)
res <- gadget$value()
gctorture(FALSE)
expect_identical( res, c(1, 2, 3) )

#    test.Module.finalize.dummy <- function(){
## an object created without arguments for a class lacking a default
## constructor holds the dummy pointer; finalizing it must be a no-op
## rather than an error (which used to surface at garbage collection)
r <- new( ModuleRandomizer )
expect_identical( r$finalize(), NULL )

## loading a module again must not re-run its body, which used to add
## every constructor and method to the static module once more (#1527);
## this redefines the module's classes, so it comes last
is_demo_module <- function(dll) is.loaded("_rcpp_module_boot_demoModule", PACKAGE = dll[["name"]])
dll <- Filter(is_demo_module, getLoadedDLLs())[[1L]]
mod <- Module( "demoModule", PACKAGE = dll, mustStart = TRUE )
mod <- Module( "demoModule", PACKAGE = dll, mustStart = TRUE )
expect_equal( length( mod$ModuleWorld@constructors ), 1L )
expect_equal( length( mod$ModuleWorld@methods$greet@nargs ), 1L )
