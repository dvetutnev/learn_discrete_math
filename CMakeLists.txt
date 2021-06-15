# Learning discrete mathematics
# Dmitriy Vetutnev, 2019, 2021


cmake_minimum_required(VERSION 3.12.4)
project(learn_discrete_math CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(conan.cmake)

conan_cmake_autodetect(settings)
conan_cmake_install(
    PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR}/conanfile.txt
    BUILD missing
    REMOTE conan-center
    SETTINGS ${settings}
)


find_package(benchmark REQUIRED)
find_package(GTest REQUIRED)
find_package(pprint REQUIRED)


enable_testing()


include(towns_generator/towns_generator.cmake)
add_library(shortest_way_obj OBJECT shortest_way/shortest_way.cpp)


add_executable(shortest_way shortest_way/main.cpp $<TARGET_OBJECTS:shortest_way_obj>)
add_test(NAME shortest_way COMMAND shortest_way)

add_executable(shortest_way_benchmark shortest_way/benchmark.cpp $<TARGET_OBJECTS:shortest_way_obj>)
target_link_libraries(shortest_way_benchmark benchmark::benchmark)
add_test(NAME shortest_way_benchmark COMMAND shortest_way_benchmark)


add_subdirectory(find_sum)
add_subdirectory(boats)
add_subdirectory(uniteller)
add_subdirectory(reverse_words)
add_subdirectory(nice_numbers13)
