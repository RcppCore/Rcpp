## Rcpp: Seamless R and C++ Integration

[![CI](https://github.com/RcppCore/Rcpp/workflows/ci/badge.svg)](https://github.com/RcppCore/Rcpp/actions?query=workflow%3Aci)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](https://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](https://www.r-pkg.org/badges/version/Rcpp)](https://cran.r-project.org/package=Rcpp)
[![Dependencies](https://tinyverse.netlify.app/badge/Rcpp)](https://cran.r-project.org/package=Rcpp)
[![Coverage Status](https://codecov.io/gh/RcppCore/Rcpp/graph/badge.svg)](https://app.codecov.io/github/RcppCore/Rcpp?branch=master)
[![Debian package](https://img.shields.io/debian/v/r-cran-rcpp/sid?color=brightgreen)](https://packages.debian.org/sid/r-cran-rcpp)
[![r-universe](https://rcppcore.r-universe.dev/badges/Rcpp)](https://rcppcore.r-universe.dev/Rcpp)
[![Last Commit](https://img.shields.io/github/last-commit/RcppCore/Rcpp)](https://github.com/RcppCore/Rcpp)
[![Downloads (monthly)](https://cranlogs.r-pkg.org/badges/Rcpp?color=brightgreen)](https://www.r-pkg.org/pkg/Rcpp)
[![Downloads (total)](https://cranlogs.r-pkg.org/badges/grand-total/Rcpp?color=brightgreen)](https://www.r-pkg.org/pkg/Rcpp)
[![CRAN use](https://jangorecki.gitlab.io/rdeps/Rcpp/CRAN_usage.svg?sanitize=true)](https://cran.r-project.org/package=Rcpp)
[![CRAN indirect](https://jangorecki.gitlab.io/rdeps/Rcpp/indirect_usage.svg?sanitize=true)](https://cran.r-project.org/package=Rcpp)
[![BioConductor use](https://jangorecki.gitlab.io/rdeps/Rcpp/BioC_usage.svg?sanitize=true)](https://cran.r-project.org/package=Rcpp)
[![JSS](https://img.shields.io/badge/JSS-10.18637%2Fjss.v040.i08-brightgreen)](https://doi.org/10.18637/jss.v040.i08)
[![Springer useR!](https://img.shields.io/badge/Springer%20useR!-10.1007%2F978--1--4614--6868--4-brightgreen)](https://link.springer.com/book/10.1007/978-1-4614-6868-4)
[![TAS](https://img.shields.io/badge/TAS-10.1080%2F00031305.2017.1375990-brightgreen)](https://doi.org/10.1080/00031305.2017.1375990)

### Synopsis

The [Rcpp package](https://cran.r-project.org/package=Rcpp) integrates R and C++ via R functions and a (header-only) C++ library.

All underlying R types and objects, _i.e._, everything a `SEXP` represents internally
in R, are matched to corresponding C++ objects. This covers anything from vectors,
matrices or lists to environments, functions and more. Each `SEXP` variant is
automatically mapped to a dedicated C++ class. For example, numeric vectors are
represented as instances of the `Rcpp::NumericVector` class, environments are
represented as instances of `Rcpp::Environment`, functions are represented as
`Rcpp::Function`, etc ...  The
[Rcpp-introduction](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-introduction.pdf)
vignette (now published as a
[TAS paper](https://doi.org/10.1080/00031305.2017.1375990); an
[earlier introduction](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-jss-2011.pdf)
was also published as a [JSS paper](https://doi.org/10.18637/jss.v040.i08)
provides a good entry point to Rcpp as do the [Rcpp
website](https://www.rcpp.org), the [Rcpp
page](https://dirk.eddelbuettel.com/code/rcpp.html) and the [Rcpp
Gallery](https://gallery.rcpp.org). Full documentation is provided by the
[Rcpp book](https://link.springer.com/book/10.1007/978-1-4614-6868-4).

Other highlights:

- The conversion from C++ to R and back is driven by the templates `Rcpp::wrap`
and `Rcpp::as` which are highly flexible and extensible, as documented
in the [Rcpp-extending](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-extending.pdf) vignette.

- Rcpp also provides Rcpp modules, a framework that allows exposing
C++ functions and classes to the R level. The [Rcpp-modules](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-modules.pdf) vignette
details the current set of features of Rcpp-modules.

- Rcpp includes a concept called Rcpp sugar that brings many R functions
into C++. Sugar takes advantage of lazy evaluation and expression templates
to achieve great performance while exposing a syntax that is much nicer
to use than the equivalent low-level loop code. The [Rcpp-sugar](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-sugar.pdf)
gives an overview of the feature.

- Rcpp attributes provide a high-level syntax for declaring C++
functions as callable from R and automatically generating the code
required to invoke them.  Attributes are intended to facilitate both
interactive use of C++ within R sessions as well as to support R
package development. Attributes are built on top of Rcpp modules and
their implementation is based on previous work in the inline package.
See the [Rcpp-atttributes](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-attributes.pdf) vignettes for more details.

### Documentation

The package ships with ten pdf vignettes, including a [recent introduction to
Rcpp](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-introduction.pdf) now
published as a [paper in
TAS](https://doi.org/10.1080/00031305.2017.1375990) (and as a
[preprint in PeerJ](https://peerj.com/preprints/3188/)). Also available is an
[earlier
introduction](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-jss-2011.pdf)
which was published as a [JSS paper](https://doi.org/10.18637/jss.v040.i08).

Among the other vignettes are the [Rcpp
FAQ](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-FAQ.pdf) and the
introduction to [Rcpp
Attributes](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-attributes.pdf).
Additional documentation is available via the [Rcpp book](https://link.springer.com/book/10.1007/978-1-4614-6868-4)
by Eddelbuettel (2013, Springer); see 'citation("Rcpp")' for details.

### Performance

Rcpp follows the C++ motto of _"you pay only for what you use"_ and imposes
no _run-time_ performance penalty: Rcpp outperforms related packages in
direct comparison, see for example [this repo for
details](https://github.com/eddelbuettel/ldlasb).

Compile-time performance can be tuned by selecting components. But it is also
worth noting that use of [`ccache`](https://ccache.dev/) will (strongly)
dominate all such possible component choices, we have [previously
recommended](https://dirk.eddelbuettel.com/blog/2017/11/27/) its use.

### Examples

The [Rcpp Gallery](https://gallery.rcpp.org) showcases over one hundred fully
documented and working examples. The
[package RcppExamples](https://cran.r-project.org/package=RcppExamples) contains a few basic
examples covering the core data types.

A number of examples are included, as are well over one thousand unit tests which provide
additional usage examples.

An earlier version of Rcpp, containing what we now call the 'classic Rcpp
API' was written during 2005 and 2006 by Dominick Samperi.  This code has
been factored out of Rcpp into the package RcppClassic, and it is still
available for code relying on the older interface. New development should
always use this Rcpp package instead.

Other usage examples are provided by packages using Rcpp. As of early July
2025, there are 3043 [CRAN](https://cran.r-project.org) packages using Rcpp
(corresponding to 13.6% of all packages, and 61.3% of packages containing
compiled code), a further 271 [BioConductor](https://www.bioconductor.org)
packages in its current release as well as an unknown number of GitHub,
Bitbucket, R-Forge, ... repositories using Rcpp.  All these packages provide
usage examples for Rcpp. The package is in widespread use and has been
downloaded over 100.6 million times (per the partial logs from the cloud mirrors
of CRAN).

### Installation

#### CRAN

Rcpp released on CRAN are carefully tested and curated. CRAN ensures they interoperate
with all other CRAN package on all test environment. The released and tested versions
are available via all mirrors of [CRAN](https://cran.r-project.org) network, and can be
installed from within R via

```R
install.packages("Rcpp")
```

#### Release Candidates

We generally make interim _candidate_ releases available via the [r-universe
page](https://rcppcore.r-universe.dev/Rcpp).  It provides a standard R repository which
corresponds to the current main branch in the source repository. Both binary and source
versions can be installed via

```R
install.packages("Rcpp", repos = c("https://rcppcore.r-universe.dev",
                                   "https://cloud.r-project.org"))
```

where other repos can be set as needed.

Testing the release candidates prior to the actual release helps. Please run
this if you can.

#### Source

To install from source, ensure you have a complete package development
environment for R as discussed in the relevant documentation; also see
questions 1.2 and 1.3 in the
[Rcpp-FAQ](https://cran.r-project.org/package=Rcpp/vignettes/Rcpp-FAQ.pdf).

#### Less Common Versions and Platforms

If you want to run Rcpp on another (not-tested on CRAN) platform, or on releases
older than the previous release, we suggest you do your due diligence and test
accordingly.  Rcpp is provided by an all-volunteer team with finite resources.
We work hard to test Rcpp with several thousand CRAN packages using it---but
we cannot test on outdated versions of R or your OS.

### Support

The best place for questions is the [discussion section of the GitHub
repo](https://github.com/RcppCore/Rcpp/discussions) as the previously used mailing list at R-forge
is no longer operational.

The [issue tickets at the GitHub repo](https://github.com/RcppCore/Rcpp/issues)
are the primary bug reporting interface.  As with the other web resources,
previous issues can be searched as well.


### Authors

Dirk Eddelbuettel, Romain Francois, JJ Allaire, Kevin Ushey, Qiang Kou,
Nathan Russell, Iñaki Ucar, Doug Bates, and John Chambers

### License

GPL (>= 2)
