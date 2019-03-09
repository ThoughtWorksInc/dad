cc_library(
    name = "dad",
    srcs = [],
    hdrs = [
        "dad.h",
        "dad/value.h",
    ],
)

cc_test(
    name = "dad_test",
    srcs = [
        "dad_test.cc",
    ],
    deps = [
        "dad",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_binary(
    name = "dad_example",
    srcs = ["dad_example.cc"],
    deps = ["dad"],
)
