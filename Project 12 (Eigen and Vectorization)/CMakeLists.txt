cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(EigenProj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Eigen
find_package(Eigen3 3.3 REQUIRED CONFIG)

#include CheckCCXCompilerFlag.cmake standard module file
include(CheckCXXCompilerFlag)

# Check that -marh=native compiler flag works
check_cxx_compiler_flag("-march=native" _march_native_works)

# Alternative too
check_cxx_compiler_flag("-xHost" _xhost_works)

set(_CXX_FLAGS)
if(_march_native_works)
	message(STATUS "Using processor's vector instructions (-march=native compiler flag set)")
	set(_CXX_FLAGS "-march=native")
elseif(_xhost_works)
	message(STATUS "Using processor's vector instructions (-xHost compiler flag set)")
	set(_CXX_FLAGS "-xHost")
else()
	message(STATUS "No suitable compiler flag found for vectorization")
endif()

# Unoptimized
add_executable(linear-algebra-unoptimized main.cpp)

target_link_libraries(linear-algebra-unoptimized PRIVATE Eigen3::Eigen)

# Optimized Version
add_executable(linear-algebra main.cpp)

target_compile_options(linear-algebra PRIVATE ${_CXX_FLAGS})

target_link_libraries(linear-algebra PRIVATE Eigen3::Eigen)