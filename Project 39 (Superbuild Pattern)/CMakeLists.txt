cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(SuperBuild LANGUAGES CXX)

# Set the EP_BASE directory for the current and any underlying directories
set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)

# Include ExternalProject.cmake standard module (gives ExternalProject_Add)
include(ExternalProject)

ExternalProject_Add(${PROJECT_NAME}_core SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src
	CMAKE_ARGS -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER} -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
		-DCMAKE_CXX_EXTENSIONS=${CMAKE_CXX_EXTENSIONS} -DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
		CMAKE_CACHE_ARGS -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS} BUILD_ALWAYS 1 INSTALL_COMMAND "")