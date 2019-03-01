# Learning discrete mathematics
# Dmitriy Vetutnev, 2019

cmake_minimum_required(VERSION 3.0)
project(learn_discrete_math CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/towns_generator)

set(workDir ${CMAKE_BINARY_DIR}/towns_generator)
set(cmd ${CMAKE_COMMAND})
set(args
    "-G" ${CMAKE_GENERATOR}
    "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
    "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
    "-DCMAKEVERBOSE_MAKE_FILE=ON"
    ${CMAKE_SOURCE_DIR}/towns_generator
)
string(REPLACE ";" " " _args "${args}")
message(STATUS "Working directory: ${workDir}")
message(STATUS "Execute: ${cmd} ${_args}")
execute_process(
    COMMAND ${cmd} ${args}
    WORKING_DIRECTORY ${workDir}
    RESULT_VARIABLE exitCode
    ERROR_VARIABLE errorOutput
    OUTPUT_VARIABLE output
)
message(${output})
if(NOT "${exitCode}" STREQUAL "0")
    message(SEND_ERROR ${errorOutput})
    message(FATAL_ERROR "Failed! Exit code: ${exitCode}")
endif()

set(args
    "--build"
    ${CMAKE_BINARY_DIR}/towns_generator
)
string(REPLACE ";" " " _args "${args}")
message(STATUS "Execute: ${cmd} ${_args}")
execute_process(
    COMMAND ${cmd} ${args}
    RESULT_VARIABLE exitCode
    ERROR_VARIABLE errorOutput
    OUTPUT_VARIABLE output
)
message(${output})
if(NOT "${exitCode}" STREQUAL "0")
    message(SEND_ERROR ${errorOutput})
    message(FATAL_ERROR "Failed! Exit code: ${exitCode}")
endif()

set(cmd ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/towns_generator)
set(args
    "10"
    ${CMAKE_BINARY_DIR}/towns.h
)
string(REPLACE ";" " " _args "${args}")
message(STATUS "Execute: ${cmd} ${_args}")
execute_process(
    COMMAND ${cmd} ${args}
    RESULT_VARIABLE exitCode
    ERROR_VARIABLE errorOutput
)
if(NOT "${exitCode}" STREQUAL "0")
    message(SEND_ERROR ${errorOutput})
    message(FATAL_ERROR "Failed! Exit code: ${exitCode}")
endif()


add_executable(fake fake.cpp)
