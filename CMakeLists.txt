# Learning discrete mathematics
# Dmitriy Vetutnev, 2018


cmake_minimum_required(VERSION 3.0)
project(learn_discrete_math CXX)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)


option(USE_CONAN "Use Conan package manager" ON)

if(USE_CONAN)

    include(${CMAKE_SOURCE_DIR}/conan.cmake)

    conan_cmake_run(
        REQUIRES
            googletest/1.9.0-b2@odant/stable
        BASIC_SETUP
        CMAKE_TARGETS
        NO_OUTPUT_DIRS
        UPDATE
        BUILD outdated
    )

endif()


find_package(GTest REQUIRED)


enable_testing()


add_executable(fake fake.cpp)
target_link_libraries(fake GTest::Main)
add_test(
    NAME fake
    COMMAND fake
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

