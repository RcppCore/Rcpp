
x <- tryCatch(
  error = identity,
  testRcppInterfaceUser::use_cpp_interface(quote(stop("jump!")))
)

stopifnot(grepl("jump!", x$message))

if (getRversion() >= "3.5.0") {
    stopifnot(
        testRcppInterfaceUser::peek_flag("cpp_interface_downstream"),
        testRcppInterfaceExporter::peek_flag("cpp_interface_upstream")
    )
}


testRcppInterfaceUser::reset_flags()
testRcppInterfaceExporter::reset_flags()

x <- withRestarts(
  here = identity,
  testRcppInterfaceUser::use_cpp_interface(quote(invokeRestart("here", "value")))
)

stopifnot(identical(x, "value"))

if (getRversion() >= "3.5.0") {
    stopifnot(
        testRcppInterfaceUser::peek_flag("cpp_interface_downstream"),
        testRcppInterfaceExporter::peek_flag("cpp_interface_upstream")
    )
}
