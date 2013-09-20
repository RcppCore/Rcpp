\name{Rcpp-internal}
\alias{Rcpp-internal}
\alias{cpp_object_initializer}
\alias{cpp_object_dummy}
\title{Rcpp internal functions}
\description{The \pkg{Rcpp} utilizes several internal functions which
  need to visible within its namespace, yet are not user-facing. This
  page provides basic documentation for them.
}
\usage{
  cpp_object_initializer(.self, .refClassDef, ..., .object_pointer)
  cpp_object_dummy(.self, .refClassDef)
}
\arguments{
  \item{.self}{A reference to the object being modified}
  \item{.refClassDef}{The definition of a reference class}
  \item{...}{Further arguments}
  \item{.object_pointer}{Optional external pointer}
}
\keyword{programming}
\keyword{interface}
\keyword{internal}
