add_executable(test_nice_numbers13
    test_digit.cpp
    test_number.cpp
    test_calc.cpp)
target_link_libraries(test_nice_numbers13 GTest::gtest_main)
add_test(NAME test_nice_numbers13 COMMAND test_nice_numbers13)

add_executable(benchmark_nice_numbers13 benchmark_calc.cpp)
target_link_libraries(benchmark_nice_numbers13 benchmark::benchmark)
add_test(NAME benchmark_nice_numbers13 COMMAND benchmark_nice_numbers13)
