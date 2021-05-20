add_executable(test_find_sum test_generator.cpp test_find_sum.cpp)
target_link_libraries(test_find_sum GTest::gtest_main pprint::pprint)
add_test(NAME test_find_sum COMMAND test_find_sum)

add_executable(benchmark_find_sum benchmark_find_sum.cpp)
target_link_libraries(benchmark_find_sum benchmark::benchmark)
add_test(NAME benchmark_find_sum COMMAND benchmark_find_sum)
