cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-std=c++11 -DX__DEBUG__")

project(GA_TSP)

file(GLOB_RECURSE TSP_SOURCES)
file(GLOB_RECURSE TSP_HEADERS)

set (TSP_INCLUDE_DIRS "")
foreach (_headerFile ${TSP_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND TSP_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES TSP_INCLUDE_DIRS)

include_directories(${TSP_INCLUDE_DIRS})
add_executable (main main.cpp ${TSP_SOURCES})

target_link_libraries (main)
