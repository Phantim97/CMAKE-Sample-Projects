cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Timeouts LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

enable_testing()

add_test(example ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py)

add_test(timeout_fail ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test2.py)

set_tests_properties(example PROPERTIES TIMEOUT 10)

set_tests_properties(timeout_fail PROPERTIES TIMEOUT 10)

# Even with this here the TIMEOUT will prioritize failure
set_tests_properties(timeout_fail PROPERTIES WILL_FAIL true)