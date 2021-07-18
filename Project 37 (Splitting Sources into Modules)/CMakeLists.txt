cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Modules LANGUAGES NONE)

list(append CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(colors)
define_colors()

message(STATUS "This is a normal message")
message(STATUS "${Red}This is a red${ColourReset}")
message(STATUS "${BoldRed}This is a bold red${ColourReset}")
message(STATUS "${Green}This is a green${ColourReset}")
message(STATUS "${BoldMagenta}This is a bold${ColourReset}")