cc_library(
    name = "libtd",
    srcs = [
        "TD.c",
        "console_draw2.c",
        "game_part.c",
        "image.c",
        "kb_input2.c",
        "others.c",
    ],
    hdrs = [
        "TD.h",
        "console_draw2.h",
        "kb_input2.h",
    ],
)

cc_binary(
    name = "td",
    # Find a way to make the program load the data automatically
    # data = glob(["data/**"]),
    deps = [":libtd"],
)
