file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/towns_generator)
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

set(workDir ${CMAKE_BINARY_DIR}/towns_generator)
set(cmd ${CMAKE_COMMAND})
set(args
    "-G" ${CMAKE_GENERATOR}
    "-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
    "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    "-DCMAKEVERBOSE_MAKE_FILE=${CMAKEVERBOSE_MAKE_FILE}"
)
if(NOT isMultiConfig)
    set(args
        ${args}
        "-DCMAKE_BUILD_TYPE=Release"
    )
endif()
set(args
    ${args}
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
if(isMultiConfig)
    set(args
        ${args}
        "--config"
        "Release"
    )
endif()
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

if(EXISTS ${CMAKE_BINARY_DIR}/towns.h)
    message(STATUS "Created ${CMAKE_BINARY_DIR}/towns.h")
else()
    message(FATAL_ERROR "Can not create ${CMAKE_BINARY_DIR}/towns.h")
endif()
