# c-jump

It is not clear yet what this library is for :D

Currently it demonstrates the use of google's bazel for a C++ project.

## Build and test

Build with C++14 standard (Todo: investigate how to use CROSSTOOL files for toolchain specification)
```
bazel build --cxxopt -std=c++14 //...:all
bazel test  --cxxopt -std=c++14 //...:all
```

