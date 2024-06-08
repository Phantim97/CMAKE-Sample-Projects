#set min version
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# project name and language 
project(GtestExample LANGUAGES CXX)

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#ex lib
add_library(sum_integers sum_ints.cpp)

add_executable(sum_up main.cpp)
target_link_libraries(sum_up sum_integers)

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")


if(ENABLE_UNIT_TESTS)
	#all remaining cmake code will be placed here
	include(FetchContent)

	FetchContent_Declare(googletest GIT_REPOSITORY http://github.com/google/googletest.git GIT_TAG v1.14.0)

	FetchContent_GetProperties(googletest)

	if(NOT googletest_POPULATED)
		FetchContent_Populate(googletest)

		#prevent google test from overriding our compiler/linker options when building with vs
		set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

		#adds the targets: gtest, gtest_main, gmock, gmock_main
		add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

		#silence std::tr1 warning on MSVC
		if(MSVC)
			foreach(_tgt gtest gtest_main gmock gmock_main)
				target_compile_definitions(${_tgt} PRIVATE "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING")
			endforeach()
		endif()

		#MinGW tries to use pthreads, so here we force it disabled
    		if(MINGW)
			set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
		endif()
	endif()

	add_executable(cpp_test "")

	target_sources(cpp_test PRIVATE test.cpp)

	target_link_libraries(cpp_test PRIVATE sum_integers gtest_main)

	#enable testing and add_test to define unit tests
	enable_testing()

	add_test(NAME google_test COMMAND $<TARGET_FILE:cpp_test>)
endif()
