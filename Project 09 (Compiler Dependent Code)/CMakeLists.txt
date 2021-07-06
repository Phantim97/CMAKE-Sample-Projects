# Base CMAKE stuff
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(CrossComp LANGUAGES CXX)

add_executable(cross-comp main.cpp)

# Compiler target
target_compile_definitions(cross-comp PUBLIC "COMPILER_NAME=\"${CMAKE_CXX_COMPILER_ID}\"")

if(CMAKE_CXX_COMPILER_ID MATCHES Intel)
	target_compile_definitions(cross-comp PUBLIC "IS_INTEL_CXX_COMPILER")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
	target_compile_definitions(cross-comp PUBLIC "IS_GNU_CXX_COMPILER")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES PGI)
	target_compile_definitions(cross-comp PUBLIC "IS_PGI_CXX_COMPILER")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES XL)
	target_compile_definitions(cross-comp PUBLIC "IS_XL_CXX_COMPILER")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
	target_compile_definitions(cross-comp PUBLIC "IS_WIN_CXX_COMPILER")
endif()