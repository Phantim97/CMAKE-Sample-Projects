cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(SimpleTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonInterp REQUIRED)
find_program(BASH_EXECUTABLE NAMES bash REQUIRED) # Need manual install of bash and ubuntu on windows

# define the library, dependencies of the main exe and the testing exe

# example lib
add_library(sum_integers sum_ints.cpp)

# main code 
add_executable(sum_up main.cpp)
target_link_libraries(sum_up sum_integers)

# testing binary
add_executable(cpp_test "test.cpp")
target_link_libraries(cpp_test sum_integers)

# define our tests
enable_testing()

# optional path shown here
message(STATUS "Bash at: ${BASH_EXECUTABLE}")

message(STATUS $<TARGET_FILE:sum_up>)

add_test(NAME bash_test COMMAND ${BASH_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.sh $<TARGET_FILE:sum_up>)

add_test(NAME cpp_test COMMAND $<TARGET_FILE:cpp_test>)

add_test(NAME python_test_long COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py --executable $<TARGET_FILE:sum_up>)

add_test(NAME python_test_short COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py --short --executable $<TARGET_FILE:sum_up>)
