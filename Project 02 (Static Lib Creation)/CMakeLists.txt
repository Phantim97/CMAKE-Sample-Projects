cmake_minimum_required(VERSION 3.8)

#Alternative without shared object files
#add_library(message STATIC Message.h Message.cpp) -> add_executable(hello-lib-sample main.cpp) -> target_link_libraries(hello-lib-sample message)

#Creates objects for sources
add_library(message-objs 
	OBJECT
	Message.h
	Message.cpp)

set_target_properties(message-objs PROPERTIES POSITION_INDEPENDENT_CODE 1)

add_library(message-shared SHARED $<TARGET_OBJECTS:message-objs>) # Creates dll for us
set_target_properties(message-shared PROPERTIES OUTPUT_NAME "message")

add_library(message-static STATIC $<TARGET_OBJECTS:message-objs>) # creates static lib
set_target_properties(message-static PROPERTIES OUTPUT_NAME "message")

add_executable(hello-lib-sample main.cpp)

target_link_libraries(hello-lib-sample message-static)