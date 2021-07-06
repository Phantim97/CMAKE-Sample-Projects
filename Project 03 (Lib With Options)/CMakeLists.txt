#Controllig Compilation with Conditionals

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-04 LANGUAGES CXX)

#Introduce USE_LIBRARY variable
option(USE_LIBRARY "Compile the sources into a Library" OFF)

message(STATUS "Compile Sources into a Library? ${USE_LIBRARY}")

#Set BUILD_SHARED_LIBS global variable to off, calling add_library and omitting the second arg will build s atatic lib
set(BUILD_SHARED_LIBS OFF)

#introduce variable _sources listing message.h and message.cpp
list(APPEND _sources Message.h Message.cpp)

#If USE_LIBRARY is true message files will be packaged into a library
# add_library will create a static library
# since BUILD_SHARED_LIBS is OFF
if (USE_LIBRARY)
	add_library(message ${_sources})
	add_executable(hello-lib-sample2 main.cpp)
else()
	add_executable(hello-lib-sample2  main.cpp ${_sources})
endif()