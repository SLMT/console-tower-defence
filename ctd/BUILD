package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "libctd",
    srcs = [
        "ctd.cc",
        "ctd.h",
        "frame.cc",
        "frame.h",
    ],
    deps = [
        "//lib/nthu_cs",
        "@abseil-cpp//absl/log:check",
    ],
)

cc_binary(
    name = "ctd",
    srcs = ["main.cc"],
    deps = [":libctd"],
)
