cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(CompFlags LANGUAGES CXX)

message("C++ Compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC" "-Wall")

# account for flags not on windows

if (NOT WIN32)
	list(APPEND flags "-Wextra" "-Wpedantic")
endif()

add_library(geometry
	STATIC
	geometry_circle.cpp
	geometry_circle.h
	geometry_polygon.cpp
	geometry_polygon.h
	geometry_rhombus.cpp
	geometry_rhombus.h
	geometry_square.cpp
	geometry_square.h)

# library compile options
target_compile_options(geometry PRIVATE ${FLAGS})

add_executable(compute-areas compute-areas.cpp)

# executable compile options
target_compile_options(compute-areas PRIVATE "-fPIC")

target_link_libraries(compute-areas geometry)