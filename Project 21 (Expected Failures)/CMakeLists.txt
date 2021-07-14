cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# No language needed for cmake as we are looking for the python interpreter

project(ExpectedFail LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

enable_testing()

add_test(example ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py)

# Sets tests as failing to be passing (Note can also use Regex to check output for pass/fail)
set_tests_properties(example PROPERTIES WILL_FAIL true)