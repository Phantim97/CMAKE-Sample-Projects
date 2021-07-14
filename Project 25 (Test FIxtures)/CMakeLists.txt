cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Fixtures LANGUAGES NONE)

find_package(PythonInterp)

enable_testing()

# The tests bound by FIXTURE_REQUIRED will run the fixture for the test (setup and cleanup)

add_test(NAME setup COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}//test/setup.py)
set_tests_properties(setup PROPERTIES FIXTURE_SETUP my-fixture)

add_test(NAME feature-a COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/feature-a.py)
add_test(NAME feature-b COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/feature-b.py)
set_tests_properties(feature-a feature-b PROPERTIES FIXTURES_REQUIRED my-fixture)

add_test(NAME cleanup COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/cleanup.py)
set_tests_properties(cleanup PROPERTIES FIXTURE_CLEANUP my-fixture)