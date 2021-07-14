cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(TestSubsets LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

enable_testing()

add_test(NAME feature-a COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/feature-a.py)
add_test(NAME feature-b COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/feature-b.py)
add_test(NAME feature-c COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/feature-c.py)

add_test(NAME benchmark-a COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/benchmark-a.py)
add_test(NAME benchmark-b COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/benchmark-b.py)
add_test(NAME benchmark-c COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/benchmark-c.py)

set_tests_properties(
	feature-a
	feature-b
	feature-c
	PROPERTIES
		LABELS "quick"
)

set_tests_properties(
	benchmark-a
	benchmark-b
	benchmark-c
	PROPERTIES
		LABELS "long"
)