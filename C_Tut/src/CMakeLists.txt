# Specify the minimum version for CMake
 
cmake_minimum_required(VERSION 3.11)

# set (CMAKE_CXX_STANDARD 11)

# Project's name

project(Tut C)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "${PROJECT_SOURCE_DIR}/*.c")
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "${PROJECT_SOURCE_DIR}/*.h")
set (${PROJECT_NAME}_INCLUDE_DIRS "")
foreach (_headerFile ${PROJECT_NAME}_HEADERS)
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND ${PROJECT_NAME}_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES ${PROJECT_NAME}_INCLUDE_DIRS)

add_executable (${PROJECT_NAME}Exe ${${PROJECT_NAME}_SOURCES})
target_include_directories(${PROJECT_NAME}Exe PRIVATE ${${PROJECT_NAME}_INCLUDE_DIRS})
