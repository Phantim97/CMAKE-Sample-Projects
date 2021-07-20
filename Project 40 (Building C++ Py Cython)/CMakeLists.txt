cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(CythonProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

find_package(PythonInterp REQUIRED)

# Directory containing UseCython.cmake and FindCython.cmake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-cython)

# This defines cython_add_module
include(UseCython)

# Tells UseCython to compile this file as a c++ file
set_source_files_properties(account.pyx PROPERTIES CYTHON_IS_CXX TRUE)

# Create Python Module
cython_add_module(account account.pyx account.cpp)

# Location of header
target_include_directories(account PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Define a test
enable_testing()

add_test(NAME python_test COMMAND ${CMAKE_COMMAND} -E env ACCOUNT_MODULE_NAME=$<TARGET_FILE_DIR:account>
	${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py)