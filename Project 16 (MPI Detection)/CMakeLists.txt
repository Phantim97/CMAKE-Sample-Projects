cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(MpiExec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find MPI Package
find_package(MPI REQUIRED)

# link
add_executable(hello-mpi main.cpp)

target_link_libraries(hello-mpi PUBLIC MPI::MPI_CXX)