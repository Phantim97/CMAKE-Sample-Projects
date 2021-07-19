add_library(conversion "")

target_sources(conversion PRIVATE ${CMAKE_CURRENT_LIST_DIR}/conversion.cpp
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}/conversion.h)

target_include_directories(conversion PUBLIC ${CMAKE_CURRENT_LIST_DIR})