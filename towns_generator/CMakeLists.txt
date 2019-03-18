# Learning discrete mathematics
# Gerator towns list
# Dmitriy Vetutnev, 2019

cmake_minimum_required(VERSION 3.9)
project(towns_generator CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

add_executable(towns_generator
    towns_generator.cpp
    ../fantasyname/c++/namegen.cc
)
target_include_directories(towns_generator PRIVATE ../fantasyname/c++)
target_compile_definitions(towns_generator PRIVATE -DHAVE_CXX14)
