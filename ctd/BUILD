package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "libctd",
    srcs = [
        "ctd.cc",
        "ctd.h",
        "frame.h",
        "game_frame.cc",
        "game_frame.h",
        "raw_frame.cc",
        "raw_frame.h",
    ],
    deps = [
        "//lib/nthu_cs",
        "@abseil-cpp//absl/log:check",
        "@abseil-cpp//absl/strings",
    ],
)

cc_binary(
    name = "ctd",
    srcs = ["main.cc"],
    deps = [":libctd"],
)
