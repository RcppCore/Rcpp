\name{NEWS}
\title{News for Package 'Rcpp'}
\newcommand{\cpkg}{\href{http://CRAN.R-project.org/package=#1}{\pkg{#1}}}

\section{Changes in Rcpp version 0.11.2 (2014-06-06}{
  \itemize{
    \item Changes in Rcpp API:
    \itemize{
      \item Implicit conversions, e.g. between \code{NumericVector} and
      \code{IntegerVector}, will now give warnings if you use
      \code{\#define RCPP_WARN_ON_COERCE} before including the Rcpp
      headers.
      \item Templated \code{List} containers, \code{ListOf<T>}, have been 
      introduced. When subsetting such containers, the return is assumed 
      to be of type T, allowing code such as 
      \code{ListOf<NumericVector> x; NumericVector y = x[0] + x[1] + x[2]}.
      \item In a number of instances, returned results are protected and/or cast
      more carefully.
    }
    \item Changes in Rcpp Attributes
    \itemize{
      \item Trailing line comments are now stripped by the attributes
      parser. This allows the parser to handle C++ source files
      containing comments inline with function arguments.
      \item The \code{USE_CXX1X} environment variable is now defined by 
      the cpp11 plugin when R >= 3.1. Two additional plugins have been
      added for use with C++0x (eg when using g++ 4.6.* as on Windows)
      as well as C++1y for compilers beginning to support the next
      revision of the standard; additional fallback is provided for
      Windows. 
      \item \code{compileAttributes()} now also considers Imports: which
      may suppress a warning when running \code{Rcpp.package.skeleton()}.
    }
  }
}

\section{Changes in Rcpp version 0.11.1 (2014-03-13)}{
  \itemize{
    \item Changes in Rcpp API:
    \itemize{
      \item Preserve backwards compatibility with \cpkg{Rcpp} 0.10.* by
      allowing \code{RObject} extraction from vectors (or lists) of Rcpp
      objects
      \item Add missing default constructor to Reference class that was
      omitted in the header-only rewrite
      \item Fixes for \code{NA} and \code{NaN} handling of the
      \code{IndexHash} class, as well as the vector \code{.sort()}
      method. These fixes ensure that sugar functions depending on
      \code{IndexHash} (i.e. \code{unique()}, \code{sort_unique()},
      \code{match()}) will now properly handle \code{NA} and \code{NaN}
      values for numeric vectors.
      \item \code{DataFrame::nrows} now more accurately mimics R's
      internal behavior (checks the row.names attribute)
      \item Numerous changes to permit compilation on the Solaris OS 
      \item Rcpp vectors gain a subsetting method -- it is now possible
      to subset an Rcpp vector using \code{CharacterVector}s (subset
      by name), \code{LogicalVector}s (logical subsetting), and
      \code{IntegerVector}s (0-based index subsetting). Such subsetting
      will also work with Rcpp sugar expressions, enabling expressions
      such as \code{x[ x > 0]}.
      \item Comma initialization (e.g. 
      \code{CharacterVector x = "a", "b", "c";}, has been disabled, as
      it causes problems with the behavior of the \code{=} operator with
      \code{Rcpp::List}s. Users who want to re-enable this functionality 
      can use \code{#define RCPP_COMMA_INITIALIZATION}, but be aware of
      the above caveat. The more verbose 
      \code{CharacterVector x = CharacterVector::create("a", "b", "c")}
      is preferred.
    }
    \item Changes in Rcpp Attributes
    \itemize{
      \item Fix issue preventing packages with \code{Rcpp::interfaces}
      attribute from compiling.
      \item Fix behavior with attributes parsing of \code{::create} for default
      arguments, and also allow constructors of a given size
      (e.g. \code{NumericVector v = NumericVector(10))} gives a default
      value of \code{numeric(10)} at the R level). Also make NAs preserve
      type when exported to R (e.g. \code{NA_STRING} as a default argument
      maps to \code{NA_character_} at the R level)
    }
    \item Changes in Rcpp modules
    \itemize{
      \item Corrected the \code{un_pointer} implementation for \code{object} 
    }
  }
}
      
\section{Changes in Rcpp version 0.11.0 (2014-02-02)}{
  \itemize{
    \item Changes in Rcpp API:
    \itemize{
      \item Functions provided/used by \cpkg{Rcpp} are now registered
      with R and instantiated by client package alleviating the new for
      explicit linking against \code{libRcpp} which is therefore no
      longer created.
      \item Updated the \code{Rcpp.package.skeleton()} function accordingly.
      \item New class \code{StretchyList} for pair lists with fast addition of
      elements at the front and back. This abstracts the 3 functions
      \code{NewList}, \code{GrowList} and \code{Insert} used in various 
      packages and in parsers in R. 
      \item The function \code{dnt}, \code{pnt}, \code{qnt} sugar
      functions were incorrectly expanding to the no-degree-of-freedoms
      variant.
      \item Unit tests for \code{pnt} were added.
      \item The sugar table function did not handle NAs and NaNs properly
      for numeric vectors. Fixed and tests added.
      \item The internal coercion mechanism mapping numerics to strings has
      been updated to better match \R (specifically with \code{Inf}, \code{-Inf},
      and \code{NaN}.)
      \item Applied two bug fixes to Vector \code{sort()} and \code{RObject}
      definition spotted and corrected by Kevin Ushey
      \item New \code{checkUserInterrupt()} function that provides a C++ friendly 
      implementation of \code{R_CheckUserInterrupt}.
    }
    \item Changes in Rcpp attributes:
    \itemize{
      \item Embedded R code chunks in sourceCpp are now executed within
      the working directory of the C++ source file.
      \item Embedded R code chunks in sourceCpp can now be disabled.
    }
    \item Changes in Rcpp documentation:
    \itemize{
      \item The Rcpp-FAQ and Rcpp-package vignettes have been updated and expanded.
      \item Vignettes are now typeset with grey background for code boxes.
      \item The bibtex reference file has been update to reflexct
      current package versions.
    }
    \item Changes in Rcpp unit tests:
    \itemize{
      \item The file \code{tests/doRUnit.R} was rewritten following the
      pattern deployed in \cpkg{RProtoBuf} which is due to Murray Stokely
      \item The function \code{test()} was rewritten; it provides an
      easy entry point to running unit tests of the installed package 
    }
  }
}

\section{Changes in Rcpp version 0.10.6 (2013-10-27)}{
  \itemize{
    \item Changes in Rcpp API:
    \itemize{
      \item The function \code{exposeClass} takes a description of the
        constructors, fields and methods to be exposed from a C++
        class, and writes C++ and R files in the package.  Inherited
        classes can be dealt with, but require data type information.
        This approach avoids hand-coding module files.
      \item Two missing \code{is<>()} templates for
        \code{CharacterVector} and \code{CharacterMatrix} have been added,
        and some tests for \code{is_na()} and \code{is_finite()} have been
        corrected thanks to Thomas Tse.   
    }
    \item Changes in R code:
    \itemize{
      \item Export linking helper function \code{LdFlags} as well as
        \code{RcppLdFlags}.
      \item Function \code{Rcpp.package.skeleton()} no longer passes a
        \code{namespace} argument on to \code{package.skeleton()}
    }
    \item Changes in R setup:
    \itemize{
      \item Raise requirement for R itself to be version 3.0.0 or later
      as needed by the vignette processing
    }
    \item Changes in Rcpp attributes: 
    \itemize{
      \item \code{sourceCpp} now correctly binds to Rtools 3.0 and 3.1
    }
  }
}

\section{Changes in Rcpp version 0.10.5 (2013-09-28)}{
  \itemize{
    \item Changes in R code:
    \itemize{
      \item New R function \code{demangle} that calls the \code{DEMANGLE} macro.  
      \item New R function \code{sizeof} to query the byte size of a type. This
      returns an object of S3 class \code{bytes} that has a \code{print} method
      showing bytes and bits. 
    }
    \item Changes in Rcpp API:
    \itemize{
      \item Add \code{defined(__sun)} to lists of operating systems to
      test for when checking for lack of \code{backtrace()} needed for
      stack traces.
      \item \code{as<T*>}, \code{as<const T*>}, \code{as<T&>} and
      \code{as<const T&>} are now supported, when 
      T is a class exposed by modules, i.e. with \code{RCPP_EXPOSED_CLASS}
      \item \code{DoubleVector} as been added as an alias to 
      \code{NumericVector}
      \item New template function \code{is<T>} to identify if an R object 
      can be seen as a \code{T}. For example \code{is<DataFrame>(x)}. 
      This is a building block for more expressive dispatch in various places
      (modules and attributes functions). 
      \item \code{wrap} can now handle more types, i.e. types that iterate over 
      \code{std::pair<const KEY, VALUE>} where KEY can be converted to a 
      \code{String} and \code{VALUE} is either a primitive type (int, double)
      or a type that wraps. Examples :
      \itemize{
        \item \code{std::map<int, double>} : we can make a String from an int, 
        and double is primitive
        \item \code{boost::unordered_map<double, std::vector<double> >}: we can make
        a String from a double and \code{std::vector<double>} can wrap itself
      }
      Other examples of this are included at the end of the \code{wrap} unit test
      file (\code{runit.wrap.R} and \code{wrap.cpp}).
      \item \code{wrap} now handles containers of classes handled by modules. e.g.
      if you expose a class \code{Foo} via modules, then you can wrap 
      \code{vector<Foo>}, ... An example is included in the \code{wrap} unit test
      file
      \item \code{RcppLdFlags()}, often used in \code{Makevars} files of
      packages using \pkg{Rcpp}, is now exported from the package namespace.
    }
    \item Changes in Attributes:
    \itemize{
      \item Objects exported by a module (i.e. by a \code{RCPP_MODULE} call
      in a file that is processed by \code{sourceCpp}) are now directly 
      available in the environment. We used to make the module object
      available, which was less useful.
      \item A plugin for \code{openmp} has been added to support use of OpenMP.
      \item \code{Rcpp::export} now takes advantage of the more flexible 
      \code{as<>}, handling constness and referenceness of the input types. 
      For users, it means that for the parameters of function exported by modules, 
      we can now use references, pointers and const versions of them.
      The file \code{Module.cpp} file has an example. 
      \item{No longer call non-exported functions from the tools package}
      \item{No longer search the inline package as a fallback when loading
      plugins for the the \code{Rcpp::plugins} attribute}.
    }
    \item Changes in Modules:
    \itemize{
      \item We can now expose functions and methods that take
      \code{T&} or \code{const T&} as arguments. In these situations
      objects are no longer copied as they used to be. 
    }
    \item Changes in sugar:
    \itemize{
      \item \code{is_na} supports classes \code{DatetimeVector} and 
      \code{DateVector}
    }
    \item Changes in Rcpp documentation:
    \itemize{
      \item The vignettes have been moved from \code{inst/doc/} to the
      \code{vignettes} directory which is now preferred.
      \item The appearance of the vignettes has been refreshed by
      switching to the Bistream Charter font, and microtype package.
    }
    \item Deprecation of \code{RCPP_FUNCTION_*}:
    \itemize{
      \item The macros from the \code{preprocessor_generated.h} file
      have been deprecated. They are still available, but they print a
      message in addition to their expected behavior.
      \item The macros will be permanently removed in the first \pkg{Rcpp} 
      release after July 2014. 
      \item Users of these macros should start replacing them with more
      up-to-date code, such as using 'Rcpp attributes' or 'Rcpp modules'.  
    }
  }
}

\section{Changes in Rcpp version 0.10.4 (2013-06-23)}{
  \itemize{
    \item Changes in R code: None beyond those detailed for Rcpp Attributes
    \item Changes in Rcpp attributes:
    \itemize{
      \item Fixed problem whereby the interaction between the gc and the 
      RNGScope destructor could cause a crash.
      \item Don't include package header file in generated C++ interface
      header files.
      \item Lookup plugins in \pkg{inline} package if they aren't found
      within the \pkg{Rcpp} package.
      \item Disallow compilation for files that don't have extensions 
      supported by R CMD SHLIB
    }
    \item Changes in Rcpp API:
    \itemize{
      \item The \code{DataFrame::create} set of functions has been reworked
      to just use \code{List::create} and feed to the \code{DataFrame}
      constructor
      \item The \code{operator-()} semantics for \code{Date} and
      \code{Datetime} are now more inline with standard C++ behaviour;
      with thanks to Robin Girard for the report.
      \item RNGScope counter now uses unsigned long rather than int.
      \item \code{Vector<*>::erase(iterator, iterator)} was fixed. Now
      it does not remove the element pointed by last (similar to what is
      done on stl types and what was intended initially). Reported on
      Rcpp-devel by Toni Giorgino.
      \item Added equality operator between elements of
      \code{CharacterVector}s.  
    }
    \item Changes in Rcpp sugar:
    \itemize{
      \item New function \code{na_omit} based on the StackOverflow thread
      \url{http://stackoverflow.com/questions/15953768/}
      \item New function \code{is_finite} and \code{is_infinite} that
      reproduces the behavior of R's \code{is.finite} and
      \code{is.infinite} functions 
    }
    \item Changes in Rcpp build tools:
    \itemize{
      \item Fix by Martyn Plummer for Solaris in handling of
      \code{SingleLogicalResult}.      
      \item The \code{src/Makevars} file can now optionally override the
      path for \code{/usr/bin/install_name_tool} which is used on OS X.
      \item Vignettes are trying harder not to be built in parallel.
    }
    \item Changes in Rcpp documentation:
    \itemize{
      \item Updated the bibliography in \code{Rcpp.bib} (which is also
      sourced by packages using Rcpp).
      \item Updated the \code{THANKS} file.
    }
    \item Planned Deprecation of \code{RCPP_FUNCTION_*}:
    \itemize{
      \item The set of macros \code{RCPP_FUNCTION_} etc ... from the 
      \code{preprocessor_generated.h} file will be deprecated in the next version
      of \pkg{Rcpp}, i.e they will still be available but will generate some
      warning in addition to their expected behavior. 
      \item In the first release that is at least 12 months after this announcement, the
      macros will be removed from \pkg{Rcpp}. 
      \item Users of these macros (if there are any) should start replacing them 
      with more up to date code, such as using Rcpp attributes or Rcpp
      modules.  
    }
  }
}

\section{Changes in Rcpp version 0.10.3 (2013-03-23)}{
  \itemize{
    \item Changes in R code:
    \itemize{
      \item Prevent build failures on Windowsn when Rcpp is installed 
      in a library path with spaces (transform paths in the same manner
      that R does before passing them to the build system).
    }
    \item Changes in Rcpp attributes: 
    \itemize{
        \item Rcpp modules can now be used with \code{sourceCpp}
        \item Standalone roxygen chunks (e.g. to document a class) are now
        transposed into RcppExports.R
        \item Added \code{Rcpp::plugins} attribute for binding 
        directly to inline plugins. Plugins can be registered using
        the new \code{registerPlugin} function.
        \item Added built-in \code{cpp11} plugin for specifying
        the use of C++11 in a translation unit
        \item Merge existing values of build related environment 
        variables for sourceCpp
        \item Add global package include file to RcppExports.cpp
        if it exists
        \item Stop with an error if the file name passed to 
        \code{sourceCpp} has spaces in it
        \item Return invisibly from void functions
        \item Ensure that line comments invalidate block comments when
        parsing for attributes
        \item Eliminated spurious empty hello world function definition
        in Rcpp.package.skeleton
    }
    \item Changes in Rcpp API:
    \itemize{
      \item The very central use of R API R_PreserveObject and 
      R_ReleaseObject has been replaced by a new system based on the 
      functions Rcpp_PreserveObject, Rcpp_ReleaseObject and Rcpp_ReplaceObject
      which shows better performance and is implemented using a generic vector
      treated as a stack instead of a pairlist in the R
      implementation. However, as this preserve / release code is still
      a little rough at the edges, a new #define is used (in config.h)
      to disable it for now. 
      \item Platform-dependent code in Timer.cpp now recognises a few
      more BSD variants thanks to contributed defined() test suggestions
      \item Support for wide character strings has been added throughout the 
      API. In particular String, CharacterVector, wrap and as are aware of 
      wide character strings
    }
  }
}

\section{Changes in Rcpp version 0.10.2 (2012-12-21)}{
  \itemize{
    \item Changes in Rcpp API:
    \itemize{
      \item Source and header files were reorganized and consolidated so
      that compile time are now significantly lower 
      \item Added additional check in \code{Rstreambuf} deletetion
      \item Added support for \code{clang++} when using \code{libc++},
      and for anc \code{icpc} in \code{std=c++11} mode, thanks to a
      patch by Yan Zhou
      \item New class \code{Rcpp::String} to facilitate working with a single
      element of a character vector
      \item New utility class sugar::IndexHash inspired from Simon
      Urbanek's fastmatch package
      \item Implementation of the equality operator between two Rcomplex
      \item \code{RNGScope} now has an internal counter that enables it
      to be safely used multiple times in the same stack frame.
      \item New class \code{Rcpp::Timer} for benchmarking
    }
    \item Changes in Rcpp sugar:
    \itemize{
        \item More efficient version of \code{match} based on \code{IndexHash}
        \item More efficient version of \code{unique} base on \code{IndexHash}
        \item More efficient version of \code{in} base on \code{IndexHash}
        \item More efficient version of \code{duplicated} base on \code{IndexHash}
        \item More efficient version of \code{self_match} base on \code{IndexHash}
        \item New function \code{collapse} that implements paste(., collapse= "" )
    }
    \item Changes in Rcpp attributes: 
    \itemize{
        \item Use code generation rather than modules to implement
        \code{sourceCpp} and \code{compileAttributes} (eliminates 
        problem with exceptions not being able to cross shared library
        boundaries on Windows)
        \item Exported functions now automatically establish an \code{RNGScope}
        \item Functions exported by \code{sourceCpp} now directly
        reference the external function pointer rather than rely on 
        dynlib lookup
        \item On Windows, Rtools is automatically added to the PATH
        during \code{sourceCpp} compilations
        \item Diagnostics are printed to the console if \code{sourceCpp}
        fails and C++ development tools are not installed
        \item A warning is printed if when \code{compileAttributes} detects
        \code{Rcpp::depends} attributes in source files that are not 
        matched by Depends/LinkingTo entries in the package DESCRIPTION
    }
  }
}

\section{Changes in Rcpp version 0.10.1 (2012-11-26)}{
    \itemize{
        \item Changes in Rcpp sugar: 
        \itemize{
          \item New functions: \code{setdiff}, \code{union_}, \code{intersect}
            \code{setequal}, \code{in}, \code{min}, \code{max}, \code{range}, 
            \code{match}, \code{table}, \code{duplicated}
          \item New function: \code{clamp} which combines pmin and pmax, e.g. 
          clamp( a, x, b) is the same as pmax( b, pmin(x, a) )
          \item New function: \code{self_match} which implements something 
          similar to \code{match( x, unique( x ) )}
        }
        \item Changes in Rcpp API:
        \itemize{
            \item The \code{Vector} template class (hence \code{NumericVector}
            ...) get the \code{is_na} and the \code{get_na} static methods.
            \item New helper class \code{no_init} that can be used to 
            create a vector without initializing its data, e.g. : 
            \code{ IntegerVector out = no_init(n) ; }
            \item New exception constructor requiring only a message; \code{stop}
            function to throw an exception
            \item \code{DataFrame} gains a \code{nrows} method  
        }
        \item Changes in Rcpp attributes: 
        \itemize{
            \item Ability to embed R code chunks (via specially formatted
            block comments) in C++ source files.
            \item Allow specification of argument defaults for exported functions. 
            \item New scheme for more flexible mixing of generated and user composed
            C++ headers.
            \item Print warning if no export attributes are found in source file.
            \item Updated vignette with additional documentation on exposing
            C++ interfaces from packages and signaling errors.
        }
        \item Changes in Rcpp modules: 
        \itemize{
            \item Enclose .External invocations in \code{BEGIN_RCPP}/\code{END_RCPP}
        }
        \item Changes in R code :
        \itemize{
            \item New function \code{areMacrosDefined}    
             \item Additions to \code{Rcpp.package.skeleton}:
             \itemize{
                \item \code{attributes} parameter to generate a version of 
            	\code{rcpp_hello_world} that uses \code{Rcpp::export}.
            	\item \code{cpp_files} parameter to provide a list of C++
            	files to include the in the \code{src} directory of the package.
            }
        }
        \item Miscellaneous changes:
        \itemize{
          \item New example 'pi simulation' using R and C++ via Rcpp attributes
	}
    }
}
\section{Changes in Rcpp version 0.10.0 (2012-11-13)}{
  \itemize{
    \item Support for C++11 style attributes (embedded in comments) to enable
    use of C++ within interactive sessions and to automatically generate module
    declarations for packages:
    \itemize{
        \item Rcpp::export attribute to export a C++ function to R
        \item \code{sourceCpp()} function to source exported functions from a file
        \item \code{cppFunction()} and \code{evalCpp()} functions for inline declarations 
        and execution
        \item \code{compileAttribtes()} function to generate Rcpp modules from 
        exported functions within a package
        \item Rcpp::depends attribute for specifying additional build 
        dependencies for \code{sourceCpp()}
        \item Rcpp::interfaces attribute to specify the external bindings
        \code{compileAttributes()} should generate (defaults to R-only but a  
        C++ include file using R_GetCCallable can also be generated)
	\item New vignette "Rcpp-attribute" 
    }
    \item Rcpp modules feature set has been expanded:
    \itemize{
        \item Functions and methods can now return objects from classes that 
        are exposed through modules. This uses the make_new_object template
        internally. This feature requires that some class traits are declared
        to indicate Rcpp's \code{wrap}/\code{as} system that these classes are covered 
        by modules. The macro RCPP_EXPOSED_CLASS and RCPP_EXPOSED_CLASS_NODECL
        can be used to declared these type traits. 
        \item Classes exposed through modules can also be used as parameters
        of exposed functions or methods. 
        \item Exposed classes can declare factories with ".factory". A factory 
        is a c++ function that returns a pointer to the target class. It is 
        assumed that these objects are allocated with new on the factory. On the 
        R side, factories are called just like other constructors, with the 
        "new" function. This feature allows an alternative way to construct
        objects. 
        \item "converter" can be used to declare a way to convert an object
        of a type to another type. This gets translated to the appropriate
        "as" method on the R side. 
        \item Inheritance. A class can now declare that it inherits from 
        another class with the .derives<Parent>( "Parent" ) notation. As a result
        the exposed class gains methods and properties (fields) from its
        parent class. 
    }
    \item New sugar functions: 
    \itemize{
        \item \code{which_min} implements which.min. Traversing the sugar expression
        and returning the index of the first time the minimum value is found. 
        \item \code{which_max} idem
        \item \code{unique} uses unordered_set to find unique values. In particular, 
        the version for CharacterVector is found to be more efficient than 
        R's version
        \item \code{sort_unique} calculates unique values and then sorts them. 
    }
    \item Improvements to output facilities:
    \itemize{
      \item Implemented \code{sync()} so that flushing output streams works
      \item Added \code{Rcerr} output stream (forwarding to
      \code{REprintf})
    }
    \item Provide a namespace 'R' for the standalone Rmath library so
    that Rcpp users can access those functions too; also added unit tests 
    \item Development releases sets variable RunAllRcppTests to yes to
    run all tests (unless it was alredy set to 'no'); CRAN releases do
    not and still require setting -- which helps with the desired CRAN
    default of less testing at the CRAN server farm.
  }
}

\section{Changes in Rcpp version 0.9.15 (2012-10-13)}{
  \itemize{
    \item Untangling the clang++ build issue about the location of the
    exceptions header by directly checking for the include file -- an
    approach provided by Martin Morgan in a kindly contributed patch
    as unit tests for them.
    \item The \code{Date} and \code{Datetime} types now correctly
    handle \code{NA}, \code{NaN} and \code{Inf} representation; the
    \code{Date} type switched to an internal representation via \code{double}
    \item Added \code{Date} and \code{Datetime} unit tests for the new
    features
    \item An additional \code{PROTECT} was added for parsing exception
    messages before returning them to R, following a report by Ben North
  }
}

\section{Changes in Rcpp version 0.9.14 (2012-09-30)}{
  \itemize{
    \item Added new Rcpp sugar functions trunc(), round() and signif(), as well
    as unit tests for them
    \item Be more conservative about where we support clang++ and the inclusion
    of exception_defines.h and prevent this from being attempted on OS X
    where it failed for clang 3.1
    \item Corrected a typo in Module.h which now again permits use of finalizers
    \item Small correction for (unexported) bib() function (which provides a path
    to the bibtex file that ships with Rcpp)
    \item Converted NEWS to NEWS.Rd
  }
}
\section{Changes in Rcpp version 0.9.13 (2012-06-28)}{
  \itemize{
    \item Truly corrected Rcpp::Environment class by having default constructor
             use the global environment, and removing the default argument of
             global environment from the SEXP constructor
    \item Added tests for clang++ version to include bits/exception_defines.h
             for versions 3.0 or higher (similar to g++ 4.6.0 or later), needed to
      include one particular exceptions header
    \item Made more regression tests conditional on the RunAllRcppTests to come
             closer to the CRAN mandate of running tests in sixty seconds
    \item Updated unit test wrapper tests/doRUnit.R as well as unitTests/runTests.R
  }
}
\section{Changes in Rcpp version 0.9.12 (2012-06-23)}{
  \itemize{
    \item Corrected Rcpp::Environment class by removing (empty) ctor following
             rev3592 (on May 2) where default argument for ctor was moved
    \item Unit testing now checks for environment variable RunAllRcppTests being
             set to "yes"; otherwise some tests are skipped. This is arguably not
             the right thing to do, but CRAN maintainers insist on faster tests.
    \item Unit test wrapper script runTests.R has new option --allTests to set
             the environment variable
    \item The cleanup script now also considers inst/unitTests/testRcppClass/src 
  }
}
\section{Changes in Rcpp version 0.9.11 (2012-06-22)}{
  \itemize{
    \item New member function for vectors (and lists etc) containsElementNamed() 
             which returns a boolean indicating if the given element name is present
    \item Updated the Rcpp.package.skeleton() support for Rcpp modules by
             carrying functions already present from the corresponding unit test
      which was also slightly expanded; and added more comments to the code 
    \item Rcpp modules can now be loaded via loadRcppModules() from .onLoad(),
             or via loadModule("moduleName") from any R file 
    \item Extended functionality to let R modify C++ clases imported via modules
             documented in help(setRcppClass)
    \item Support compilation in Cygwin thanks to a patch by Dario Buttari
    \item Extensions to the Rcpp-FAQ and the Rcpp-modules vignettes
    \item The minium version of R is now 2.15.1 which is required for some of
             the Rcpp modules support 
  }
}
\section{Changes in Rcpp version 0.9.10 (2012-02-16)}{
  \itemize{
    \item Rearrange headers so that Rcpp::Rcout can be used by RcppArmadillo et al
    \item New Rcpp sugar function mapply (limited to two or three input vectors)
    \item Added custom version of the Rcpp sugar diff function for numeric vectors
             skipping unncesserry checks for NA
    \item Some internal code changes to reflect changes and stricter requirements
             in R CMD check in the current R-devel versions
    \item Corrected fixed-value initialization for IntegerVector (with thanks to
             Gregor Kastner for spotting this)
    \item New Rcpp-FAQ entry on simple way to set compiler option for cxxfunction
  }
}
\section{Changes in Rcpp version 0.9.9 (2012-12-25)}{
  \itemize{
    \item Reverting the 'int64' changes from release 0.9.8 which adversely
         	affect packages using Rcpp: We will re-apply the 'int64' changes in a 
      way which should cooperate more easily with 'long' and 'unsigned long'.
    \item Unit test output directory fallback changed to use Rcpp.Rcheck
    \item Conditioned two unit tests to not run on Windows where they now break
             whereas they passed before, and continue to pass on other OSs
  }
}
\section{Changes in Rcpp version 0.9.8 (2011-12-21)}{
  \itemize{
    \item wrap now handles 64 bit integers (int64_t, uint64_t) and containers 
             of them, and Rcpp now depends on the int64 package (also on CRAN).
             This work has been sponsored by the Google Open Source Programs
             Office.
    \item Added setRcppClass() function to create extended reference classes 
             with an interface to a C++ class (typically via Rcpp Module) which
      can have R-based fields and methods in addition to those from the C++.
    \item Applied patch by Jelmer Ypma which adds an output stream class
         	'Rcout' not unlike std::cout, but implemented via Rprintf to
         	cooperate with R and its output buffering.
    \item New unit tests for pf(), pnf(), pchisq(), pnchisq() and pcauchy()
    \item XPtr constructor now checks for corresponding type in SEXP
    \item Updated vignettes for use with updated highlight package
    \item Update linking command for older fastLm() example using external 
             Armadillo
  }
}
\section{Changes in Rcpp version 0.9.7 (2011-09-29)}{
  \itemize{
    \item Applied two patches kindly provided by Martyn Plummer which provide
         	support for compilation on Solaris using the SunPro compiler
    \item Minor code reorganisation in which exception specifiers are removed;
             this effectively only implements a run-time (rather than compile-time) 
             check and is generally seen as a somewhat depreated C++ idiom. Thanks
             to Darren Cook for alerting us to this issue.
    \item New example 'OpenMPandInline.r' in the OpenMP/ directory, showing how
             easily use OpenMP by modifying the RcppPlugin output
    \item New example 'ifelseLooped.r' showing Rcpp can accelerate loops that may
      be difficult to vectorise due to dependencies
    \item New example directory examples/Misc/ regrouping the new example as
             well as the fibonacci example added in Rcpp 0.9.6
    \item New Rcpp-FAQ example warning of lossy conversion from 64-bit long
             integer types into a 53-bit mantissa which has no clear fix yet.
    \item New unit test for accessing a non-exported function from a namespace
  }
}
\section{Changes in Rcpp version 0.9.6 (2011-07-26)}{
  \itemize{
    \item Added helper traits to facilitate implementation of the RcppEigen
      package: The is_eigen_base traits identifies if a class derives from
      EigenBase using SFINAE; and new dispatch layer was added to wrap() to
      help RcppEigen
    \item XPtr now accepts a second template parameter, which is a function
             taking a pointer to the target class. This allows the developper to
             supply his/her own finalizer. The template parameter has a default
             value which retains the original behaviour (calling delete on the
             pointer)
    \item New example RcppGibbs, extending Sanjog Misra's Rcpp illustration of
             Darren Wilkinson's comparison of MCMC Gibbs Sampler implementations;
      also added short timing on Normal and Gaussian RNG draws between Rcpp
      and GSL as R's rgamma() is seen to significantly slower
    \item New example on recursively computing a Fibonacci number using Rcpp and
             comparing this to R and byte-compiled R for a significant speed gain
  }
}
\section{Changes in Rcpp version 0.9.5 (2011-07-05)}{
  \itemize{
    \item New Rcpp-FAQ examples on using the plugin maker for inline's
             cxxfunction(), and on setting row and column names for matrices
    \item New sugar functions: mean, var, sd
    \item Minor correction and extension to STL documentation in Rcpp-quickref
    \item wrap() is now resilient to NULL pointers passed as in const char *
    \item loadRcppModules() gains a "direct" argument to expose the module instead
             of exposing what is inside it
    \item Suppress a spurious warning from R CMD check on packages created with
             Rcpp.package.skeleton(..., module=TRUE)
    \item Some fixes and improvements for Rcpp sugar function 'rlnorm()'
    \item Beginnings of new example using OpenMP and recognising user interrupts
  }
}
\section{Changes in Rcpp version 0.9.4 (2011-04-12)}{
  \itemize{
    \item New R function "loadRcppModules" to load Rcpp modules automatically
             from a package. This function must be called from the .onLoad function
             and works with the "RcppModules" field of the package's DESCRIPTION file
    \item The Modules example wrapped the STL std::vector received some editing
             to disambiguate some symbols the newer compilers did not like
    \item Coercing of vectors of factors is now done with an explicit callback
             to R's "as.character()" as Rf_coerceVector no longer plays along
    \item A CITATION file for the published JSS paper has been added, and 
             references were added to Rcpp-package.Rd and the different vignettes
  }
}
\section{Changes in Rcpp version 0.9.3 (2011-04-05)}{
  \itemize{
    \item Fixed a bug in which modules code was not behaving when compiled 
             twice as can easily happen with inline'ed version
    \item Exceptions code includes exception_defines.h only when g++ is 4.5 or
             younger as the file no longer exists with g++-4.6
    \item The documentation Makefile now uses the $R_HOME environment variable
    \item The documentation Makefile no longer calls clean in the all target
    \item C++ conformance issue found by clang/llvm addressed by re-ordering
             declarations in grow.h as unqualified names must be declared before
             they are used, even when used within templates
    \item The 'long long' typedef now depends on C++0x being enabled as this
             was not a feature in C++98; this suppresses a new g++-4.5 warning
    \item The Rcpp-introduction vignette was updated to the forthcoming JSS paper
  }
}
\section{Changes in Rcpp version 0.9.2 (2011-02-23)}{
  \itemize{
    \item The unitTest runit.Module.client.package.R is now skipped on older OS
             X releases as it triggers a bug with g++ 4.2.1 or older; OS X 10.6 is
             fine but as it no longer support ppc we try to accomodate 10.5 too
             Thanks to Simon Urbanek for pinning this down and Baptiste Auguie
             and Ken Williams for additonal testing 
    \item RcppCommon.h now recognises the Intel Compiler thanks to a short
             patch by Alexey Stukalov; this turns off Cxx0x and TR1 features too
    \item Three more setup questions were added to the Rcpp-FAQ vignette
    \item One question about RcppArmadillo was added to the Rcpp-FAQ vignette
  }
}
\section{Changes in Rcpp version 0.9.1 (2011-02-14)}{
  \itemize{
    \item A number of internal changes to the memory allocation / protection of
             temporary objects were made---with a heartfelt "Thank You!" to both
             Doug Bates for very persistent debugging of Rcpp modules code, and to
             Luke Tierney who added additional memory allocation debugging tools
             to R-devel (which will be in R 2.13.0 and may also be in R 2.12.2)
    \item Removed another GNU Make-specific variable from src/Makevars in order
             to make the build more portable; this was noticed on FreeBSD
    \item On *BSD, do not try to compute a stack trace but provide file and
             line number (which is the same behaviour as implemented in Windows)
    \item Fixed an int conversion bug reported by Daniel Sabanes Bove on r-devel,
             added unit test as well
    \item Added unit tests for complex-typed vectors (thanks to Christian Gunning)
    \item Expanded the Rcpp-quickref vignette (with thanks to Christian Gunning)
    \item Additional examples were added to the Rcpp-FAQ vignette
  }
}
\section{Changes in Rcpp version 0.9.0 (2010-12-19)}{
  \itemize{
    \item The classic API was factored out into its own package RcppClassic which
             is released concurrently with this version.
    \item If an object is created but not initialized, attempting to use
             it now gives a more sensible error message (by forwarding an
             Rcpp::not_initialized exception to R).
    \item SubMatrix fixed, and Matrix types now have a nested ::Sub typedef.
    \item New unexported function SHLIB() to aid in creating a shared library on
             the command-line or in Makefile (similar to CxxFlags() / LdFlags()).
    \item Module gets a seven-argument ctor thanks to a patch from Tama Ma.
    \item The (still incomplete) QuickRef vignette has grown thanks to a patch
             by Christian Gunning.
    \item Added a sprintf template intended for logging and error messages.
    \item Date::getYear() corrected (where addition of 1900 was not called for); 
             corresponding change in constructor from three ints made as well.
    \item Date() and Datetime() constructors from string received a missing
             conversion to int and double following strptime. The default format
             string for the Datetime() strptime call was also corrected.
    \item A few minor fixes throughout, see ChangeLog.
  }
}
\section{Changes in Rcpp version 0.8.9 (2010-11-27)}{
  \itemize{
    \item Many improvements were made in 'Rcpp modules':
             - exposing multiple constructors
             - overloaded methods
             - self-documentation of classes, methods, constructors, fields and 
               functions.
             - new R function "populate" to facilitate working with modules in 
               packages. 
             - formal argument specification of functions.
             - updated support for Rcpp.package.skeleton.
             - constructors can now take many more arguments.
    \item The 'Rcpp-modules' vignette was updated as well and describe many
             of the new features
    \item New template class Rcpp::SubMatrix<RTYPE> and support syntax in Matrix
             to extract a submatrix: 
                NumericMatrix x = ... ;
                // extract the first three columns
                SubMatrix<REALSXP> y = x( _ , Range(0,2) ) ; 
                // extract the first three rows
                SubMatrix<REALSXP> y = x( Range(0,2), _ ) ; 
                // extract the top 3x3 sub matrix
                SubMatrix<REALSXP> y = x( Range(0,2), Range(0,2) ) ; 
    \item Reference Classes no longer require a default constructor for
             subclasses of C++ classes    
    \item Consistently revert to using backticks rather than shell expansion
             to compute library file location when building packages against Rcpp
      on the default platforms; this has been applied to internal test
             packages as well as CRAN/BioC packages using Rcpp
  }
}
\section{Changes in Rcpp version 0.8.8 (2010-11-01)}{
  \itemize{
    \item New syntactic shortcut to extract rows and columns of a Matrix. 
             x(i,_) extracts the i-th row and x(_,i) extracts the i-th column. 
    \item Matrix indexing is more efficient. However, faster indexing is
             disabled if g++ 4.5.0 or later is used.
    \item A few new Rcpp operators such as cumsum, operator=(sugar)
    \item Variety of bug fixes:
             - column indexing was incorrect in some cases
             - compilation using clang/llvm (thanks to Karl Millar for the patch)
      - instantation order of Module corrected
             - POSIXct, POSIXt now correctly ordered for R 2.12.0 
  }
}
\section{Changes in Rcpp version 0.8.7 (2010-10-15)}{
  \itemize{
    \item As of this version, Rcpp depends on R 2.12 or greater as it interfaces
             the new reference classes (see below) and also reflects the POSIXt
             class reordering both of which appeared with R version 2.12.0
    \item new Rcpp::Reference class, that allows internal manipulation of R
             2.12.0 reference classes. The class exposes a constructor that takes
             the name of the target reference class and a field(string) method
             that implements the proxy pattern to get/set reference fields using
             callbacks to the R operators "$" and "$<-" in order to preserve the
             R-level encapsulation
    \item the R side of the preceding item allows methods to be written in R as
             per ?ReferenceClasses, accessing fields by name and assigning them
             using "<<-".  Classes extracted from modules are R reference classes.
             They can be subclassed in R, and/or R methods can be defined using
             the $methods(...) mechanism.
    \item internal performance improvements for Rcpp sugar as well as an added
             'noNA()' wrapper to omit tests for NA values -- see the included
             examples in inst/examples/convolveBenchmarks for the speedups
    \item more internal performance gains with Functions and Environments
  }
}
\section{Changes in Rcpp version 0.8.6 (2010-09-09)}{
  \itemize{
    \item new macro RCPP_VERSION and Rcpp_Version to allow conditional compiling
             based on the version of Rcpp
                #if defined(RCPP_VERSION) && RCPP_VERSION >= Rcpp_Version(0,8,6)
                #endif
    \item new sugar functions for statistical distributions (d-p-q-r functions)
      with distributions : unif, norm, gamma, chisq, lnorm, weibull, logis,
      f, pois, binom, t, beta.
    \item new ctor for Vector taking size and function pointer so that for example
         	   NumericVector( 10, norm_rand )
      generates a N(0,1) vector of size 10
    \item added binary operators for complex numbers, as well as sugar support 
    \item more sugar math functions: sqrt, log, log10, exp, sin, cos, ...
    \item started new vignette Rcpp-quickref : quick reference guide of Rcpp API
             (still work in progress)
    \item various patches to comply with solaris/suncc stricter standards
    \item minor enhancements to ConvolutionBenchmark example
    \item simplified src/Makefile to no longer require GNU make; packages using
             Rcpp still do for the compile-time test of library locations
  }
}
\section{Changes in Rcpp version 0.8.5 (2010-07-25)}{
  \itemize{
    \item speed improvements. Vector::names, RObject::slot have been improved
             to take advantage of R API functions instead of callbacks to R
    \item Some small updates to the Rd-based documentation which now points to 
             content in the vignettes.  Also a small formatting change to suppress
      a warning from the development version of R.
    \item Minor changes to Date() code which may reenable SunStudio builds
  }
}
\section{Changes in Rcpp version 0.8.4 (2010-07-09)}{
  \itemize{
    \item new sugar vector functions: rep, rep_len, rep_each, rev, head, tail,
      diag
    \item sugar has been extended to matrices: The Matrix class now extends the 
         	Matrix_Base template that implements CRTP. Currently sugar functions 
         	for matrices are: outer, col, row, lower_tri, upper_tri, diag
    \item The unit tests have been reorganised into fewer files with one call
      	each to cxxfunction() (covering multiple tests) resulting in a
      	significant speedup
    \item The Date class now uses the same mktime() replacement that R uses
             (based on original code from the timezone library by Arthur Olson)
      permitting wide date ranges on all operating systems
    \item The FastLM example has been updated, a new benchmark based on the
             historical Longley data set has been added
    \item RcppStringVector now uses std::vector<std::string> internally
    \item setting the .Data slot of S4 objects did not work properly
  }
}
\section{Changes in Rcpp version 0.8.3 (2010-06-27)}{
  \itemize{
    \item This release adds Rcpp sugar which brings (a subset of) the R syntax
             into C++. This supports : 
              - binary operators : <,>,<=,>=,==,!= between R vectors
              - arithmetic operators: +,-,*,/ between compatible R vectors
              - several functions that are similar to the R function of the same name:
             abs, all, any, ceiling, diff, exp, ifelse, is_na, lapply, pmin, pmax, 
             pow, sapply, seq_along, seq_len, sign
             Simple examples :
               // two numeric vector of the same size
               NumericVector x ;
               NumericVector y ;
               NumericVector res = ifelse( x < y, x*x, -(y*y) ) ;
               // sapply'ing a C++ function
               double square( double x )\{ return x*x ; \}
               NumericVector res = sapply( x, square ) ;
             Rcpp sugar uses the technique of expression templates, pioneered by the 
             Blitz++ library and used in many libraries (Boost::uBlas, Armadillo). 
             Expression templates allow lazy evaluation of expressions, which 
             coupled with inlining generates very efficient code, very closely 
             approaching the performance of hand written loop code, and often
             much more efficient than the equivalent (vectorized) R code.
             Rcpp sugar is curently limited to vectors, future releases will 
             include support for matrices with sugar functions such as outer, etc ...
             Rcpp sugar is documented in the Rcpp-sugar vignette, which contains
             implementation details.
    \item New helper function so that "Rcpp?something" brings up Rcpp help
    \item Rcpp Modules can now expose public data members
    \item New classes Date, Datetime, DateVector and DatetimeVector with proper
             'new' API integration such as as(), wrap(), iterators, ...
    \item The so-called classic API headers have been moved to a subdirectory
             classic/ This should not affect client-code as only Rcpp.h was ever
             included.
    \item RcppDate now has a constructor from SEXP as well
    \item RcppDateVector and RcppDatetimeVector get constructors from int
             and both const / non-const operator(int i) functions
    \item New API class Rcpp::InternalFunction that can expose C++ functions
         	to R without modules. The function is exposed as an S4 object of 
         	class C++Function
  }
}
\section{Changes in Rcpp version 0.8.2 (2010-06-09)}{
  \itemize{
    \item Bug-fix release for suncc compiler with thanks to Brian Ripley for
             additional testing.
  }
}
\section{Changes in Rcpp version 0.8.1 (2010-06-08)}{
  \itemize{
    \item This release adds Rcpp modules. An Rcpp module is a collection of
             internal (C++) functions and classes that are exposed to R. This
             functionality has been inspired by Boost.Python.
             Modules are created internally using the RCPP_MODULE macro and
             retrieved in the R side with the Module function. This is a preview 
             release of the module functionality, which will keep improving until
             the Rcpp 0.9.0 release. 
             The new vignette "Rcpp-modules" documents the current feature set of
             Rcpp modules.
    \item The new vignette "Rcpp-package" details the steps involved in making a
             package that uses Rcpp.
    \item The new vignette "Rcpp-FAQ" collects a number of frequently asked
             questions and answers about Rcpp.
    \item The new vignette "Rcpp-extending" documents how to extend Rcpp
             with user defined types or types from third party libraries. Based on
             our experience with RcppArmadillo
    \item Rcpp.package.skeleton has been improved to generate a package using 
             an Rcpp module, controlled by the "module" argument
    \item Evaluating a call inside an environment did not work properly
    \item cppfunction has been withdrawn since the introduction of the more
             flexible cxxfunction in the inline package (0.3.5). Rcpp no longer
             depends on inline since many uses of Rcpp do not require inline at
             all. We still use inline for unit tests but this is now handled
             locally in the unit tests loader runTests.R. 
             Users of the now-withdrawn function cppfunction can redefine it as:
                cppfunction <- function(...) cxxfunction( ..., plugin = "Rcpp" )
    \item Support for std::complex was incomplete and has been enhanced.
    \item The methods XPtr<T>::getTag and XPtr<T>::getProtected are deprecated, 
             and will be removed in Rcpp 0.8.2. The methods tag() and prot() should
             be used instead. tag() and prot() support both LHS and RHS use. 
    \item END_RCPP now returns the R Nil values; new macro VOID_END_RCPP
             replicates prior behabiour
  }
}
\section{Changes in Rcpp version 0.8.0 (2010-05-17)}{
  \itemize{
    \item All Rcpp headers have been moved to the inst/include directory,
             allowing use of 'LinkingTo: Rcpp'. But the Makevars and Makevars.win
             are still needed to link against the user library.
    \item Automatic exception forwarding has been withdrawn because of
             portability issues (as it did not work on the Windows platform).
             Exception forwarding is still possible but is now based on explicit
             code of the form:
               try \{
                 // user code
               \} catch( std::exception& __ex__)\{ 
                 forward_exception_to_r( __ex___ ) ;
             Alternatively, the macro BEGIN_RCPP and END_RCPP can use used to enclose
             code so that it captures exceptions and forward them to R. 
               BEGIN_RCPP
               // user code
               END_RCPP
    \item new __experimental__ macros 
             The macros RCPP_FUNCTION_0, ..., RCPP_FUNCTION_65 to help creating C++
             functions hiding some code repetition: 
               RCPP_FUNCTION_2( int, foobar, int x, int y)\{
                return x + y ;
             The first argument is the output type, the second argument is the
             name of the function, and the other arguments are arguments of the
             C++ function. Behind the scenes, the RCPP_FUNCTION_2 macro creates an
             intermediate function compatible with the .Call interface and handles
             exceptions
             Similarly, the macros RCPP_FUNCTION_VOID_0, ..., RCPP_FUNCTION_VOID_65 
             can be used when the C++ function to create returns void. The generated
             R function will return R_NilValue in this case.
               RCPP_FUNCTION_VOID_2( foobar, std::string foo )\{
                // do something with foo
             The macro RCPP_XP_FIELD_GET generates a .Call compatible function that
             can be used to access the value of a field of a class handled by an 
             external pointer. For example with a class like this: 
               class Foo\{
                 public:
                   int bar ;
               RCPP_XP_FIELD_GET( Foo_bar_get, Foo, bar ) ;
             RCPP_XP_FIELD_GET will generate the .Call compatible function called
             Foo_bar_get that can be used to retrieved the value of bar.
             The macro RCPP_FIELD_SET generates a .Call compatible function that 
             can be used to set the value of a field. For example:
               RCPP_XP_FIELD_SET( Foo_bar_set, Foo, bar ) ;
             generates the .Call compatible function called "Foo_bar_set" that 
             can be used to set the value of bar
             The macro RCPP_XP_FIELD generates both getter and setter. For example
               RCPP_XP_FIELD( Foo_bar, Foo, bar )
             generates the .Call compatible Foo_bar_get and Foo_bar_set using the 
             macros RCPP_XP_FIELD_GET and RCPP_XP_FIELD_SET previously described
             The macros RCPP_XP_METHOD_0, ..., RCPP_XP_METHOD_65 faciliate 
             calling a method of an object that is stored in an external pointer. For 
             example: 
               RCPP_XP_METHOD_0( foobar, std::vector<int> , size )
             creates the .Call compatible function called foobar that calls the
             size method of the std::vector<int> class. This uses the Rcpp::XPtr<
             std::vector<int> > class.
             The macros RCPP_XP_METHOD_CAST_0, ... is similar but the result of
             the method called is first passed to another function before being
             wrapped to a SEXP.  For example, if one wanted the result as a double
               RCPP_XP_METHOD_CAST_0( foobar, std::vector<int> , size, double )
             The macros RCPP_XP_METHOD_VOID_0, ... are used when calling the
             method is only used for its side effect.
              RCPP_XP_METHOD_VOID_1( foobar, std::vector<int>, push_back ) 
             Assuming xp is an external pointer to a std::vector<int>, this could
             be called like this :
               .Call( "foobar", xp, 2L )
    \item Rcpp now depends on inline (>= 0.3.4)
    \item A new R function "cppfunction" was added which invokes cfunction from
             inline with focus on Rcpp usage (enforcing .Call, adding the Rcpp
             namespace, set up exception forwarding). cppfunction uses BEGIN_RCPP
             and END_RCPP macros to enclose the user code
    \item new class Rcpp::Formula to help building formulae in C++
    \item new class Rcpp::DataFrame to help building data frames in C++
    \item Rcpp.package.skeleton gains an argument "example_code" and can now be
             used with an empty list, so that only the skeleton is generated. It
             has also been reworked to show how to use LinkingTo: Rcpp
    \item wrap now supports containers of the following types: long, long double,
             unsigned long, short and unsigned short which are silently converted
             to the most acceptable R type.
    \item Revert to not double-quote protecting the path on Windows as this
             breaks backticks expansion used n Makevars.win etc
    \item Exceptions classes have been moved out of Rcpp classes,
             e.g. Rcpp::RObject::not_a_matrix is now Rcpp::not_a_matrix
  }
}
\section{Changes in Rcpp version 0.7.12 (2010-04-16)}{
  \itemize{
    \item Undo shQuote() to protect Windows path names (which may contain
             spaces) as backticks use is still broken; use of $(shell ...) works
  }
}
\section{Changes in Rcpp version 0.7.11 (2010-03-26)}{
  \itemize{
    \item Vector<> gains a set of templated factory methods "create" which
             takes up to 20 arguments and can create named or unnamed vectors.
             This greatly facilitates creating objects that are returned to R. 
    \item Matrix now has a diag() method to create diagonal matrices, and
             a new constructor using a single int to create square matrices
    \item Vector now has a new fill() method to propagate a single value
    \item Named is no more a class but a templated function. Both interfaces
             Named(.,.) and Named(.)=. are preserved, and extended to work also on
             simple vectors (through Vector<>::create)
    \item Applied patch by Alistair Gee to make ColDatum more robust
    \item Fixed a bug in Vector that caused random behavior due to the lack of
             copy constructor in the Vector template
  }
}
\section{Changes in Rcpp version 0.7.10 (2010-03-15)}{
  \itemize{
    \item new class Rcpp::S4 whose constructor checks if the object is an S4
             object
    \item maximum number of templated arguments to the pairlist function, the
             DottedPair constructor, the Language constructor and the Pairlist
             constructor has been updated to 20 (was 5) and a script has been
             added to the source tree should we want to change it again
    \item use shQuote() to protect Windows path names (which may contain spaces)
  }
}
\section{Changes in Rcpp version 0.7.9 (2010-03-12)}{
  \itemize{
    \item Another small improvement to Windows build flags
    \item bugfix on 64 bit platforms. The traits classes (wrap_type_traits, etc)
             used size_t when they needed to actually use unsigned int
    \item fixed pre gcc 4.3 compatibility. The trait class that was used to
             identify if a type is convertible to another had too many false
             positives on pre gcc 4.3 (no tr1 or c++0x features). fixed by
             implementing the section 2.7 of "Modern C++ Design" book.
  }
}
\section{Changes in Rcpp version 0.7.8 (2010-03-09)}{
  \itemize{
    \item All vector classes are now generated from the same template class
             Rcpp::Vector<int RTYPE> where RTYPE is one of LGLSXP, RAWSXP, STRSXP,
             INTSXP, REALSXP, CPLXSXP, VECSXP and EXPRSXP. typedef are still 
             available : IntegerVector, ... All vector classes gain methods 
             inspired from the std::vector template : push_back, push_front, 
             erase, insert
    \item New template class Rcpp::Matrix<RTYPE> deriving from 
             Rcpp::Vector<RTYPE>. These classes have the same functionality
             as Vector but have a different set of constructors which checks
             that the input SEXP is a matrix. Matrix<> however does/can not
             guarantee that the object will allways be a matrix. typedef 
             are defined for convenience: Matrix<INTSXP> is IntegerMatrix, etc...
    \item New class Rcpp::Row<int RTYPE> that represents a row of a matrix
             of the same type. Row contains a reference to the underlying 
             Vector and exposes a nested iterator type that allows use of 
             STL algorithms on each element of a matrix row. The Vector class
             gains a row(int) method that returns a Row instance. Usage 
             examples are available in the runit.Row.R unit test file
    \item New class Rcpp::Column<int RTYPE> that represents a column of a 
             matrix. (similar to Rcpp::Row<int RTYPE>). Usage examples are 
             available in the runit.Column.R unit test file
    \item The Rcpp::as template function has been reworked to be more 
             generic. It now handles more STL containers, such as deque and 
             list, and the genericity can be used to implement as for more
             types. The package RcppArmadillo has examples of this
    \item new template class Rcpp::fixed_call that can be used in STL algorithms
             such as std::generate.
    \item RcppExample et al have been moved to a new package RcppExamples;
             src/Makevars and src/Makevars.win simplified accordingly
    \item New class Rcpp::StringTransformer and helper function 
             Rcpp::make_string_transformer that can be used to create a function
             that transforms a string character by character. For example
             Rcpp::make_string_transformer(tolower) transforms each character
             using tolower. The RcppExamples package has an example of this.
    \item Improved src/Makevars.win thanks to Brian Ripley
    \item New examples for 'fast lm' using compiled code: 
             - using GNU GSL and a C interface
             - using Armadillo (http://arma.sf.net) and a C++ interface
             Armadillo is seen as faster for lack of extra copying
    \item A new package RcppArmadillo (to be released shortly) now serves 
             as a concrete example on how to extend Rcpp to work with a modern 
             C++ library such as the heavily-templated Armadillo library
    \item Added a new vignette 'Rcpp-introduction' based on a just-submitted 
             overview article on Rcpp
  }
}
\section{Changes in Rcpp version 0.7.7 (2010-02-14)}{
  \itemize{
    \item new template classes Rcpp::unary_call and Rcpp::binary_call
             that facilitates using R language calls together 
             with STL algorithms.
    \item fixed a bug in Language constructors taking a string as their
             first argument. The created call was wrong.
  }
}
\section{Changes in Rcpp version 0.7.6 (2010-02-12)}{
  \itemize{
    \item SEXP_Vector (and ExpressionVector and GenericVector, a.k.a List) now
             have methods push_front, push_back and insert that are templated
    \item SEXP_Vector now has int- and range-valued erase() members
    \item Environment class has a default constructor (for RInside)
    \item SEXP_Vector_Base factored out of SEXP_Vector (Effect. C++ #44)
    \item SEXP_Vector_Base::iterator added as well as begin() and end()
             so that STL algorithms can be applied to Rcpp objects
    \item CharacterVector gains a random access iterator, begin() and end() to
             support STL algorithms; iterator dereferences to a StringProxy
    \item Restore Windows build; successfully tested on 32 and 64 bit;
    \item Small fixes to inst/skeleton files for bootstrapping a package
    \item RObject::asFoo deprecated in favour of Rcpp::as<Foo>
  }
}
\section{Changes in Rcpp version 0.7.5 (2010-02-08)}{
  \itemize{
    \item wrap has been much improved. wrappable types now are :
             - primitive types : int, double, Rbyte, Rcomplex, float, bool
             - std::string
             - STL containers which have iterators over wrappable types:
               (e.g. std::vector<T>, std::deque<T>, std::list<T>, etc ...). 
             - STL maps keyed by std::string, e.g std::map<std::string,T>
             - classes that have implicit conversion to SEXP
             - classes for which the wrap template if fully or partly specialized
             This allows composition, so for example this class is wrappable: 
             std::vector< std::map<std::string,T> > (if T is wrappable)
    \item The range based version of wrap is now exposed at the Rcpp::
             level with the following interface : 
             Rcpp::wrap( InputIterator first, InputIterator last )
             This is dispatched internally to the most appropriate implementation
             using traits
    \item a new namespace Rcpp::traits has been added to host the various
             type traits used by wrap
    \item The doxygen documentation now shows the examples
    \item A new file inst/THANKS acknowledges the kind help we got from others
    \item The RcppSexp has been removed from the library.
    \item The methods RObject::asFoo are deprecated and will be removed
             in the next version. The alternative is to use as<Foo>.
    \item The method RObject::slot can now be used to get or set the 
             associated slot. This is one more example of the proxy pattern
    \item Rcpp::VectorBase gains a names() method that allows getting/setting
             the names of a vector. This is yet another example of the 
             proxy pattern.
    \item Rcpp::DottedPair gains templated operator<< and operator>> that 
             allow wrap and push_back or wrap and push_front of an object
    \item Rcpp::DottedPair, Rcpp::Language, Rcpp::Pairlist are less
             dependent on C++0x features. They gain constructors with up
             to 5 templated arguments. 5 was choosed arbitrarily and might 
             be updated upon request.
    \item function calls by the Rcpp::Function class is less dependent
             on C++0x. It is now possible to call a function with up to 
             5 templated arguments (candidate for implicit wrap)
    \item added support for 64-bit Windows (thanks to Brian Ripley and Uwe Ligges)
  }
}
\section{Changes in Rcpp version 0.7.4 (2010-01-30)}{
  \itemize{
    \item matrix-like indexing using operator() for all vector 
             types : IntegerVector, NumericVector, RawVector, CharacterVector
             LogicalVector, GenericVector and ExpressionVector. 
    \item new class Rcpp::Dimension to support creation of vectors with 
             dimensions. All vector classes gain a constructor taking a 
             Dimension reference.
    \item an intermediate template class "SimpleVector" has been added. All
             simple vector classes are now generated from the SimpleVector 
             template : IntegerVector, NumericVector, RawVector, CharacterVector
             LogicalVector.
    \item an intermediate template class "SEXP_Vector" has been added to 
             generate GenericVector and ExpressionVector.
    \item the clone template function was introduced to explicitely
             clone an RObject by duplicating the SEXP it encapsulates.
    \item even smarter wrap programming using traits and template
             meta-programming using a private header to be include only
             RcppCommon.h
    \item the as template is now smarter. The template now attempts to 
             build an object of the requested template parameter T by using the
             constructor for the type taking a SEXP. This allows third party code
             to create a class Foo with a constructor Foo(SEXP) to have 
             as<Foo> for free.
    \item wrap becomes a template. For an object of type T, wrap<T> uses
             implicit conversion to SEXP to first convert the object to a SEXP
             and then uses the wrap(SEXP) function. This allows third party 
             code creating a class Bar with an operator SEXP() to have 
             wrap for free.
    \item all specializations of wrap :  wrap<double>, wrap< vector<double> >
             use coercion to deal with missing values (NA) appropriately.
    \item configure has been withdrawn. C++0x features can now be activated
             by setting the RCPP_CXX0X environment variable to "yes".
    \item new template r_cast<int> to facilitate conversion of one SEXP
             type to another. This is mostly intended for internal use and 
             is used on all vector classes
    \item Environment now takes advantage of the augmented smartness
             of as and wrap templates. If as<Foo> makes sense, one can 
             directly extract a Foo from the environment. If wrap<Bar> makes
             sense then one can insert a Bar directly into the environment. 
               Foo foo = env["x"] ;  /* as<Foo> is used */
               Bar bar ;
               env["y"] = bar ;      /* wrap<Bar> is used */     
    \item Environment::assign becomes a template and also uses wrap to 
             create a suitable SEXP
    \item Many more unit tests for the new features; also added unit tests
             for older API
  }
}
\section{Changes in Rcpp version 0.7.3 (2010-01-21)}{
  \itemize{
    \item New R function Rcpp.package.skeleton, modelled after 
             utils::package.skeleton to help creating a package with support
             for Rcpp use.
    \item indexing is now faster for simple vectors due to inlining of 
             the operator[] and caching the array pointer
    \item The class Rcpp::VectorBase was introduced. All vector classes
             derive from it. The class handles behaviour that is common 
             to all vector types: length, names, etc ...
    \item exception forwarding is extended to compilers other than GCC
             but default values are used for the exception class 
             and the exception message, because we don't know how to do it.
    \item Improved detection of C++0x capabilities
    \item Rcpp::Pairlist gains a default constructor
    \item Rcpp::Environment gains a new_child method to create a new
             environment whose parent is this
    \item Rcpp::Environment::Binding gains a templated implicit 
             conversion operator
    \item Rcpp::ExpressionVector gains an eval method to evaluate itself
    \item Rcpp::ExpressionVector gains a constructor taking a std::string
             representing some R code to parse. 
    \item Rcpp::GenericVector::Proxy gains an assignment operator to deal
             with Environment::Proxy objects
    \item Rcpp::LdFlags() now defaults to static linking OS X, as it already
             did on Windows; this default can be overridden. 
  }
}
\section{Changes in Rcpp version 0.7.2 (2010-01-12)}{
  \itemize{
    \item a new benchmark was added to the examples directory
             around the classic convolution example from
             Writing R extensions to compare C and C++ implementations
    \item Rcpp::CharacterVector::StringProxy gains a += operator
    \item Rcpp::Environment gains an operator[](string) to get/set
             objects from the environment. operator[] returns an object
             of class Rcpp::Environment::Binding which implements the proxy
             pattern. Inspired from Item 30 of 'More Effective C++'
    \item Rcpp::Pairlist and Rcpp::Language gain an operator[](int) 
             also using the proxy pattern
    \item Rcpp::RObject.attr can now be used on the rhs or the lhs, to get 
             or set an attribute. This also uses the proxy pattern
    \item Rcpp::Pairlist and Rcpp::Language gain new methods push_back
             replace, length, size, remove, insert
    \item wrap now returns an object of a suitable class, not just RObject
             anymore. For example wrap( bool ) returns a LogicalVector
    \item Rcpp::RObject gains methods to deal with S4 objects : isS4, 
             slot and hasSlot
    \item new class Rcpp::ComplexVector to manage complex vectors (CPLXSXP)
    \item new class Rcpp::Promise to manage promises (PROMSXP)
    \item new class Rcpp::ExpressionVector to manage expression vectors
             (EXPRSXP)
    \item new class Rcpp::GenericVector to manage generic vectors, a.k.a
             lists (VECSXP)
    \item new class Rcpp::IntegerVector to manage integer vectors (INTSXP)
    \item new class Rcpp::NumericVector to manage numeric vectors (REALSXP)
    \item new class Rcpp::RawVector to manage raw vectors (RAWSXP)
    \item new class Rcpp::CharacterVector to manage character vectors (STRSXP)
    \item new class Rcpp::Function to manage functions 
             (CLOSXP, SPECIALSXP, BUILTINSXP)
    \item new class Rcpp::Pairlist to manage pair lists (LISTSXP)
    \item new class Rcpp::Language to manage calls (LANGSXP)
    \item new specializations of wrap to deal with std::initializer lists
             only available with GCC >= 4.4
    \item new R function Rcpp:::capabilities that can query if various
             features are available : exception handling, variadic templates
             initializer lists
    \item new set of functions wrap(T) converting from T to RObject
    \item new template function as<T> that can be used to convert a SEXP
             to type T. Many specializations implemented to deal with 
             C++ builtin and stl types. Factored out of RObject
    \item new class Rcpp::Named to deal with named with named objects 
             in a pairlist, or a call
    \item new class Rcpp::Symbol to manage symbols (SYMSXP)
    \item The garbage collection has been improved and is now automatic 
             and hidden. The user needs not to worry about it at all.
    \item Rcpp::Environment(SEXP) uses the as.environment R function
    \item Doxygen-generated documentation is no longer included as it is both
             too large and too volatile. Zipfiles are provided on the website.
  }
}
\section{Changes in Rcpp version 0.7.1 (2010-01-02)}{
  \itemize{
    \item Romain is now a co-author of Rcpp
    \item New base class Rcpp::RObject replace RcppSexp (which is provided for
             backwards compatibility)
    \item RObject has simple wrappers for object creation and conversion to SEXP
    \item New classes Rcpp::Evaluator and Rcpp::Environment for expression
             evaluation and environment access, respectively
    \item New class Rcpp::XPtr for external pointers
    \item Enhanced exception handling allows for trapping of exceptions outside
             of try/catch blocks
    \item Namespace support with a new namespace 'Rcpp'
    \item Unit tests for most of the new classes, based on the RUnit package
    \item Inline support now provided by the update inline package, so a new
             Depends on 'inline (>= 0.3.4)' replaces the code in that was
             temporarily in Rcpp
  }
}
\section{Changes in Rcpp version 0.7.0 (2009-12-19)}{
  \itemize{
    \item Inline support via a modified version of 'cfunction' from Oleg
             Sklyar's 'inline' package: simple C++ programs can now be compiled,
             linked and loaded automagically from the R prompt, including support
             for external packages. Also works on Windows (with R-tools installed)
    \item New examples for the inline support based on 'Intro to HPC' tutorials
    \item New type RcppSexp for simple int, double, std::string scalars and vectors
    \item Every class is now in its own header and source file
    \item Fix to RcppParams.Rd thanks to Frank S. Thomas
    \item RcppVersion.R removed as redundant given DESCRIPTION and read.dcf()
    \item Switched to R_PreserveObject and R_ReleaseObject for RcppSexp with
             thanks to Romain
    \item Licensing changed from LGPL 2.1 (or later) to GPL 2 (or later), file
             COPYING updated
  }
}
\section{Changes in Rcpp version 0.6.8 (2009-11-19)}{
  \itemize{
    \item Several classes now split off into their own header and source files
    \item New header file RcppCommon.h regrouping common defines and includes
    \item Makevars\{,.win\} updated to reflect src/ reorg
  }
}
\section{Changes in Rcpp version 0.6.7 (2009-11-08)}{
  \itemize{
    \item New class RcppList for simple lists and data structures of different
             types and dimensions, useful for RProtoBuf project on R-Forge
    \item Started to split classes into their own header and source files
    \item Added short README file about history and status
    \item Small documentation markup fix thanks to Kurt; updated doxygen docs
    \item New examples directory functionCallback/ for R function passed to C++ 
             and being called
  }
}
\section{Changes in Rcpp version 0.6.6 (2009-08-03)}{
  \itemize{
    \item Updated Doxygen documentation
    \item RcppParams class gains a new exists() member function
  }
}
\section{Changes in Rcpp version 0.6.5 (2009-04-01)}{
  \itemize{
    \item Small OS X build correction using R_ARCH variable
    \item Include LGPL license as file COPYING
  }
}
\section{Changes in Rcpp version 0.6.4 (2009-03-01)}{
  \itemize{
    \item Use std:: namespace throughout instead of 'using namespace std'
    \item Define R_NO_REMAP so that R provides Rf_length() etc in lieu of length()
             to minimise clashes with other projects having similar functions
    \item Include Doxygen documentation, and Doxygen configuration file 
    \item Minor Windows build fix (with thanks to Uwe and Simon)
  }
}
\section{Changes in Rcpp version 0.6.3 (2009-01-09)}{
  \itemize{
    \item OS X build fix with thanks to Simon
    \item Added 'view-only' classes for int and double vector and matrix clases
             as well as string vector classses, kindly suggsted / provided by
             David Reiss
    \item Add two shorter helper functions Rcpp:::CxxFlags() and
             Rcpp:::LdFlags() for compilation and linker flags 
  }
}
\section{Changes in Rcpp version 0.6.2 (2008-12-02)}{
  \itemize{
    \item Small but important fix for Linux builds in Rcpp:::RcppLdFlags()
  }
}
\section{Changes in Rcpp version 0.6.1 (2008-11-30)}{
  \itemize{
    \item Now src/Makevars replaces src/Makefile, this brings proper OS X
             multi-arch support with thanks to Simon
    \item Old #ifdef statements related to QuantLib removed; Rcpp is now
             decoupled from QuantLib headers yet be used by RQuantLib
    \item Added RcppLdPath() to return the lib. directory patch and on Linux
             the rpath settings
    \item Added new RcppVectorExample()
    \item Augmented documentation on usage in Rcpp-package.Rd
  }
}
\section{Changes in Rcpp version 0.6.0 (2008-11-05)}{
  \itemize{
    \item New maintainer, taking over RcppTemplate (which has been without an
             update since Nov 2006) under its initial name Rcpp
    \item New files src/Makefile\{,.win\} including functionality from both
             configure and RcppSrc/Makefile; we now build two libraries, one for
             use by the package which also runs the example, and one for users to
             link against, and removed src/Makevars.in
    \item Files src/Rcpp.\{cpp,h\} moved in from ../RcppSrc
    \item Added new class RcppDatetime corresponding to POSIXct in with full 
             support for microsecond time resolution between R and C++
    \item Several new manual pages added
    \item Removed  configure\{,.in,.win\} as src/Makefile* can handle this more
             easily
    \item Minor cleanup and reformatting for DESCRIPTION, Date: now uses
             svn:keyword Date property
    \item Renamed RcppTemplateVersion to RcppVersion, deleted RcppDemo
    \item Directory demo/ removed as vignette("RcppAPI") is easier and more
             reliable to show vignette documentation
    \item RcppTemplateDemo() removed from R/zzz.R, vignette("RcppAPI") is easier;
             man/RcppTemplateDemo.Rd removed as well
    \item Some more code reindentation and formatting to R default arguments,
             some renamed from RcppTemplate* to Rcpp*
    \item Added footnote onto titlepage of inst/doc/RcppAPI.\{Rnw,pdf\} about how
             this document has not (yet) been updated along with the channges made
  }
}
