cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(HostProcSpecs CXX)

#Define target execuatble, its source file, and include directories

add_executable(proc-info "")

target_sources(proc-info PRIVATE main.cpp)

target_include_directories(proc-info PRIVATE ${PROJECT_BINARY_DIR})

# query the host system info for a number of keys:

foreach(key IN ITEMS
	NUMBER_OF_LOGICAL_CORES
	NUMBER_OF_PHYSICAL_CORES
	TOTAL_VIRTUAL_MEMORY
	AVAILABLE_VIRTUAL_MEMORY
	TOTAL_PHYSICAL_MEMORY
	AVAILABLE_PHYSICAL_MEMORY
	IS_64BIT
	HAS_FPU
	HAS_MMX
	HAS_MMX_PLUS
	HAS_SSE
	HAS_SSE2
	HAS_SSE_FP
	HAS_SSE_MMX
	HAS_AMD_3DNOW
	HAS_AMD_3DNOW_PLUS
	HAS_IA64
	OS_NAME
	OS_RELEASE
	OS_VERSION
	OS_PLATFORM
	)
	cmake_host_system_information(RESULT _${key} QUERY ${key})
endforeach()

# Having defined the corresponding variables we configure config.h

# Note need to manually create config.h.in where this will create out config.h
# Auto creates a header
configure_file(config.h.in config.h @ONLY)