cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Note the C standard
project(PythonEmbed LANGUAGES C)

# Optional to use C99 standard for C but something that might be wanted
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSION OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find Python Interpreter
find_package(PythonInterp REQUIRED)

# Find Python Header and Library (module is FindPythonLibs.cmake)
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)

add_executable(embed-python main.c)

# Include directory
target_include_directories(embed-python PRIVATE ${PYTHON_INCLUDE_DIRS})

# Link the Python Library (Note for Windows dll needs to be linked too)
target_link_libraries(embed-python PRIVATE ${PYTHON_LIBRARIES})