http_archive(
    name = "com_google_googletest",
    url = "https://github.com/google/googletest/archive/d175c8bf823e709d570772b038757fadf63bc632.tar.gz",
    sha256 = "39a708e81cf68af02ca20cad879d1dbd055364f3ae5588a5743c919a51d7ad46",
    strip_prefix = "googletest-d175c8bf823e709d570772b038757fadf63bc632",
)

new_http_archive(
    name = "eigen_archive",
    urls = [
        "https://bitbucket.org/eigen/eigen/get/429aa5254200.tar.gz",
        "http://mirror.bazel.build/bitbucket.org/eigen/eigen/get/429aa5254200.tar.gz",
    ],
    sha256 = "61d8b6fc4279dd1dda986fb1677d15e3d641c07a3ea5abe255790b1f0c0c14e9",
    strip_prefix = "eigen-eigen-429aa5254200",
    build_file = "//third_party:eigen.BUILD",
)

