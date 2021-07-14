# CMake init
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(DynamLeak LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(example_lib leaky_impl.cpp)

add_executable(cpp_test test.cpp)

# Define not only the test but the MEMORYCHECK_COMMAND Command

find_program(MEMORYCHECK_COMMAND NAMES valgrind)
set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full")

#add memcheck test action
include(CTest)

enable_testing()

# To use memcheck we use ctest -m memcheck
add_test(NAME cpp_test COMMAND $<TARGET_FILE:cpp_test>)