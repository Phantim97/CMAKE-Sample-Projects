cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# VERSION keyword stores version into PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH
project(Versioning VERSION 2.0.1 LANGUAGES C)

configure_file(version.h.in generated/version.h @ONLY)

add_executable(example main.c)

target_include_directories(example PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated)