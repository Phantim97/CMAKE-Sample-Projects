add_library(evolution "")

target_sources(evolution PRIVATE evolution.cpp PUBLIC ${CMAKE_CURRENT_LIST_DIR}/evolution.h)

target_include_directories(evolution PUBLIC ${CMAKE_CURRENT_LIST_DIR})