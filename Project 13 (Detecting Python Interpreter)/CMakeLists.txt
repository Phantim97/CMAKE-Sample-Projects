cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Detection only
project(PythonLocator LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

execute_process(COMMAND ${PYTHON_EXECUTABLE} "-c" "print('Hello, World')"
	RESULT_VARIABLE _status 
	OUTPUT_VARIABLE _hello_world
	ERROR_QUIET
	OUTPUT_STRIP_TRAILING_WHITESPACE)

# Print the return value and output of the Python Command
message(STATUS "RESULT_VARIABLE is: ${_status}")
message(STATUS "OUTPUT_VARIABLE is: ${_hello_world}")
