cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(SourceGen LANGUAGES Fortran C)

# obtain username for user configing the project
execute_process(COMMAND whoami TIMEOUT 1 OUTPUT_VARIABLE _user_name OUTPUT_STRIP_TRAILING_WHITESPACE)

# query system information
# host system info
cmake_host_system_information(RESULT _host_name QUERY HOSTNAME)
cmake_host_system_information(RESULT _fqdn QUERY HOSTNAME)

# processor information
cmake_host_system_information(RESULT _processor_name QUERY PROCESSOR_NAME)
cmake_host_system_information(RESULT _processor_description QUERY PROCESSOR_DESCRIPTION)

# os information
cmake_host_system_information(RESULT _os_name QUERY OS_NAME)
cmake_host_system_information(RESULT _os_release QUERY OS_RELEASE)
cmake_host_system_information(RESULT _os_version QUERY OS_VERSION)
cmake_host_system_information(RESULT _os_platform QUERY OS_PLATFORM)

string(TIMESTAMP _configuration_time "%Y-%m-%d %H:%M:S [UTC]" UTC)

# configure the template file
configure_file(print_info.c.in print_info.c @ONLY)

# add executable
add_executable(example "")

target_sources(PRIVATE example.f90 ${CMAKE_CURRENT_BINARY_DIR}/print_info.c)