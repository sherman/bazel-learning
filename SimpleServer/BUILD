
cc_library(
    name = "LZ4Utils",
    hdrs = ["LZ4Utils.cc"],
    deps = [
        "//ThirdParty/lz4:lz4"
    ]
)

cc_binary(
    name = "SimpleServer",
    srcs = ["SimpleServer.cc"],
    copts = [
        "-fpermissive"
    ],
    deps = [
        ":LZ4Utils"
    ]
)
