add_executable(test_nice_numbers13
    test_digit.cpp
    test_number.cpp
    test_calc.cpp
    test_composition_length.cpp
    test_parallel_calculation.cpp
    test_separate_range.cpp)
target_link_libraries(test_nice_numbers13 GTest::gmock_main)
add_test(NAME test_nice_numbers13 COMMAND test_nice_numbers13)

add_executable(benchmark_nice_numbers13 benchmark_composition_length.cpp)
target_link_libraries(benchmark_nice_numbers13 benchmark::benchmark)
add_test(NAME benchmark_nice_numbers13 COMMAND benchmark_nice_numbers13)
