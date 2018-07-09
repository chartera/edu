# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.11)

set (CMAKE_CXX_STANDARD 11)

# Project's name

project(edu)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${PROJECT_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

add_executable(main ${PROJECT_SOURCE_DIR}/main.cpp ${PROJECT_SOURCE_DIR}/interpreter.cpp ${PROJECT_SOURCE_DIR}/token.cpp ${PROJECT_SOURCE_DIR}/variable.cpp)
