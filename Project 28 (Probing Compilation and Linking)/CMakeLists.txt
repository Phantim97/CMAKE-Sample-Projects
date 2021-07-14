cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(ProbingComp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP)

if(OpenMP_FOUND)
	# This scratch directory will be used by try_compile to generate its intermediate files
	set(_scratch_dir ${CMAKE_CURRENT_BINARY_DIR}/omp_try_compile)

	# generate a small project to attempt compiling the source file task.cpp success or failure
	try_compile(omp_taskloop_test_1 ${_scratch_dir} SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/task.cpp LINK_LIBRARIES OpenMP::OpenMP_CXX)
	message(STATUS "Result try_compile: ${omp_taskloop_test_1}")

	include(CheckCXXSourceCompiles)

	# Copy contents of source files into a cmake variable
	file(READ ${CMAKE_CURRENT_SOURCE_DIR}/task.cpp _snippet)

	# Set CMAKE_REQUIRED_LIBRARIES
	set(CMAKE_REQUIRED_LIBRARIES OpenMP::OpenMP_CXX)

	# Invoke check_cxx_source_compiles function with code sinppet and save res
	check_cxx_sources_compiles("${_snippet}" omp_taskloop_test_2)

	# Unset the variables defined before calling check_cxx_source_compiles
	unset(CMAKE_REQUIRED_LIBRARIES)
	message(STATUS "Result of check_cxx_source_compiles: ${omp_taskloop_test_2}")
else()
	message(STATUS "OpenMP not found no test for task is run")
endif()