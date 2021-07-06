# Initialize Project
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(switch-builds LANGUAGES C CXX)

# Set Default Build Type, note CACHE allows for subsequent editing through the cache
if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE Release CACHE STRING "Build Type" FORCE)
endif()

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# Print corresponding compile flags set by cmake as a function of the buildt type
message(STATUS "C flags, Debug Configuration: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release Configuration: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release Configuration With Debug Info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "C flags, Minimal Release Configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")

message(STATUS "C++ flags, Debug Configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release Configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release Configuration With Debug Info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "C++ flags, Minimal Release Configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")