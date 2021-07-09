cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(OmpTest LANGUAGES CXX)

#Set C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Find OpenMP Package
find_package(OpenMP REQUIRED)

add_executable(omptest main.cpp)

target_link_libraries(omptest PUBLIC OpenMP::OpenMP_CXX)