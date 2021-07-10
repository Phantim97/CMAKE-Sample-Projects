# cmake init
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(CatchExample LANGUAGES CXX)

# require c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sum_integers sum_ints.cpp)

# main code
add_executable(sum_up main.cpp)
target_link_libraries(sum_up sum_integers)

# testing binary
add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test sum_integers)

enable_testing()

add_test(NAME catch_test COMMAND $<TARGET_FILE:cpp_test> --success)