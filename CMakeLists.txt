# CMake 3.30 is required for C++23 `import std` support.
cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 23)
if (CMAKE_VERSION VERSION_GREATER_EQUAL "4.0")
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
else ()
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
endif()

set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_CXX_MODULE_STD 1)

# C++ needs to be enabled.
project(import_std LANGUAGES CXX)

# Tell CMake that we explicitly want `import std`. This will initialize the
# property on all targets declared after this to 1

# Make a library.
add_library(uses_std STATIC)
# Add sources.
target_sources(uses_std
        PRIVATE
        uses_std.cxx)
# Tell CMake we're using C++23 but only C++20 is needed to consume it.
target_compile_features(uses_std
        PRIVATE   cxx_std_23
        INTERFACE cxx_std_20)
# Make an executable.
add_executable(main)
# Note that this source is *not* allowed to `import std` as it ends up
# with only C++20 support due to the `uses_std` INTERFACE requirements.
target_sources(main
        PRIVATE
        main.cxx)
target_link_libraries(main PRIVATE uses_std)

add_library(greeting)
target_sources(greeting
        PUBLIC
        FILE_SET CXX_MODULES FILES
        greeting.ixx
)
target_sources(greeting
        PRIVATE
        greeting.cpp
)
target_compile_features(greeting PUBLIC cxx_std_23)

add_executable(greeting_main greeting_main.cpp)
target_link_libraries(greeting_main PRIVATE greeting)