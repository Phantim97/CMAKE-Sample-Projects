cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cross-compilation LANGUAGES C CXX)

message(STATUS "Is the C++ Compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")
if (CMAKE_CXX_COMPILER_LOADED)
	message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
	message(STATUS "Is the C++ from GNU?: ${CMAKE_COMPILER_IS_GNUCXX}")
	message(STATUS "The C++ Compiler Version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()

message(STATUS "Is the C Compiler loaded? ${CMAKE_C_COMPILER_LOADED}")
if (CMAKE_C_COMPILER_LOADED)
	message(STATUS "The C compiler ID is: ${CMAKE_C_COMPILER_ID}")
	message(STATUS "Is the C from GNU?: ${CMAKE_COMPILER_IS_GNUCC}")
	message(STATUS "The C Compiler Version is: ${CMAKE_C_COMPILER_VERSION}")
endif()