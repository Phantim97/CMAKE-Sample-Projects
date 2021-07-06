# Standard CMAKE stuff
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(CrossPlat LANGUAGES CXX)

add_executable(cross-plat main.cpp)

# Preprocessor is defined through the system via the system name by defining the following target compile defs
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_definitions(cross-plat PUBLIC "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	target_compile_definitions(cross-plat PUBLIC "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_definitions(cross-plat PUBLIC "IS_WINDOWS")
endif()
