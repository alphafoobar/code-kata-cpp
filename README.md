[![Build Status](https://travis-ci.com/alphafoobar/code-kata-cpp.svg?branch=master)](https://travis-ci.com/alphafoobar/code-kata-cpp) [![codecov](https://codecov.io/gh/alphafoobar/code-kata-cpp/branch/master/graph/badge.svg)](https://codecov.io/gh/alphafoobar/code-kata-cpp)

# Code Kata C++

* These katas are from [CodeKata](http://codekata.com/), as a starting point.
* This repository forms part of a collection of code kata in different languages.

This project is built in JetBrains CLion and using Travis-CI. It adheres to modern C++-17 and builds with 
G++-7 CMake ctests.

## Worth knowing in modern C++

1. Classes can be instantiated automatic or dynamic storage duration. Whenever possible use automatic storage duration!
`MyObject my_object{};`
1. C++ allows pass by reference, this is preferable for object passing.
`void my_function(MyObject &my_object)`
1. C/C++ header files must avoid circular dependencies and should not contain concrete implementations, this will
cause linker errors.

## Dependency management approach

* Google tests imported into test directory as a git submodule following recommendations:
   * https://www.jetbrains.com/help/clion/creating-google-test-run-debug-configuration-for-test.html
   * https://stackoverflow.com/questions/33638433/setup-google-test-in-clion
   * https://github.com/google/googletest/blob/release-1.8.1/googletest/docs/primer.md

## Useful links