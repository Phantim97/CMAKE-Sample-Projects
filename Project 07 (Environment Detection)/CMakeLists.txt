cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(EnvDetect LANGUAGES NONE)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	message(STATUS "Configuring on for Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	message(STATUS "Configuring on for macOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	message(STATUS "Configuring on for Windows")
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
	message(STATUS "Configuring on for IBM AIX")
else()
	message(STATUS "Configuring on for ${CMAKE_SYSTEM_NAME}")
endif()