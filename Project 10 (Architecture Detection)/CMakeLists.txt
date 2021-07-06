# Basic CMAKE defines
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(ArchDetect LANGUAGES CXX)

add_executable(arch-detect main.cpp)

# We check for the size of the void pointer type (SIZEOF_VOID_P) this will tell us if the cpu is 32 or 8 bit
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	target_compile_definitions(arch-detect PUBLIC "IS_64_BIT_ARCH")
	message(STATUS "Target is 64 bits")
else()
	target_compile_definitions(arch-detect PUBLIC "IS_32_BIT_ARCH")
	message(STATUS "Target is 32 bits")
endif()

# Let the preprocessor
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
	message(STATUS "i386 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
	message(STATUS "i686 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
	message(STATUS "x86_64 architecture detected")
else()
	message(STATUS "Host Processor is Unknown")
endif()

# Make our define for the ARCHITECTURE MACRO HERE
target_compile_definitions(arch-detect PUBLIC "ARCHITECTURE=${CMAKE_HOST_SYSTEM_PROCESSOR}")
