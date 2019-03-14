# Learning discrete mathematics
# Gerator towns list
# Dmitriy Vetutnev, 2019

cmake_minimum_required(VERSION 3.0)
project(towns_generator CXX)

if(MSVC)
    add_compile_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_executable(towns_generator
    towns_generator.cpp
    ../fantasyname/c++/namegen.cc
)
target_include_directories(towns_generator PRIVATE ../fantasyname/c++)
target_compile_definitions(towns_generator PRIVATE -DHAVE_CXX14)
