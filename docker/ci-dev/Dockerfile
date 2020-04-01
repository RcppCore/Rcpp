## Emacs, make this -*- mode: sh; -*-

FROM rocker/drd

LABEL org.label-schema.license="GPL-2.0" \
      org.label-schema.vcs-url="https://github.com/RcppCore/Rcpp" \
      maintainer="Dirk Eddelbuettel <edd@debian.org>"

RUN apt-get update \
        && apt-get install -y --no-install-recommends git \
        && RDscript -e 'install.packages(c("codetools", "inline", "pkgKitten", "rbenchmark", "tinytest"))'

ENV _R_CHECK_FORCE_SUGGESTS_ FALSE
ENV _R_CHECK_TESTS_NLINES_ 0
ENV RunAllRcppTests yes

CMD ["bash"]
