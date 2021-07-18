cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(GitHash LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GIT_HASH "unknown")

# Find Git if available update the git hash variable
find_package(Git QUIET)

if(GIT_FOUND)
	execute_process(COMMAND ${GIT_EXECUTABLE} log -1 --pretty=format:%h OUTPUT_VARIABLE GIT_HASH
		OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_QUIET WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

message(STATUS "Git Hash is ${GIT_HASH}")

# Generate file version.h base on version.h.in
configure_file(version.h.in generated/version.h @ONLY)

# Example Code
add_executable(example main.cpp)

# Find generated header
target_include_directories(example PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated)