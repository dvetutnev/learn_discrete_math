# Learning discrete mathematics
# Dmitriy Vetutnev, 2019

cmake_minimum_required(VERSION 3.9)
project(learn_discrete_math CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

option(BENCHMARK_ENABLE_TESTING "" OFF)
option(BENCHMARK_ENABLE_INSTALL "" OFF)
add_subdirectory(benchmark)

enable_testing()

include(towns_generator/towns_generator.cmake)
add_library(shortest_way_obj OBJECT shortest_way/shortest_way.cpp)

add_executable(shortest_way shortest_way/main.cpp $<TARGET_OBJECTS:shortest_way_obj>)
add_test(
    NAME shortest_way
    COMMAND shortest_way
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_executable(shortest_way_benchmark shortest_way/benchmark.cpp $<TARGET_OBJECTS:shortest_way_obj>)
target_link_libraries(shortest_way_benchmark benchmark)
add_test(
    NAME shortest_way_benchmark
    COMMAND shortest_way_benchmark
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
