cmake_minimum_required(VERSION 3.11)
project(libjzoffer)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/core/)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(core)
add_subdirectory(exercise/ex6)
add_subdirectory(exercise/ex18)
