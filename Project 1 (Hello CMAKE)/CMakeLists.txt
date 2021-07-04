# Simple Hello World for CMAKE

#Declare the minimum version of CMAKE required to run
cmake_minimum_required(VERSION 3.8)

#Name the project and language requirements
project(MyProject-01 LANGUAGES CXX)

#compile and link to create the hello-world executable
add_executable(hello-world main.cpp)