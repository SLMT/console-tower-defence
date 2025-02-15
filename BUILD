load("@rules_pkg//:pkg.bzl", "pkg_zip")

cc_binary(
    name = "td",
    data = [":data"],
    deps = ["//src:libtd"],
)

filegroup(
    name = "data",
    srcs = glob(["data/**"]),
)

pkg_zip(
    name = "td_pkg",
    srcs = [
        ":data",
        ":td",
    ],
    out = "td.zip",
)
