cmake_minimum_required(VERSION 3.12)
project(code_kata_cpp)

set(CMAKE_CXX_STANDARD 17)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_library(cpp src/kata02/binary_search.cpp src/kata02/binary_search.h)

option (BUILD_TESTING "Build the testing tree." ON)
# Only build tests if we are the top-level project
# Allows this to be used by super projects with `add_subdirectory`
if (BUILD_TESTING AND (PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR))
    # Code Coverage Configuration
    add_library(coverage_config INTERFACE)
    option(CODE_COVERAGE "Enable coverage reporting" ON)

    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        # Add required flags (GCC & LLVM/Clang)
        target_compile_options(coverage_config INTERFACE
                -O0        # no optimization
                -g         # generate debug info
                --coverage # sets all required flags
                )
        if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
            target_link_options(coverage_config INTERFACE --coverage)
        else()
            target_link_libraries(coverage_config INTERFACE --coverage)
        endif()
    endif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

    enable_testing()
    add_subdirectory(test)
endif()