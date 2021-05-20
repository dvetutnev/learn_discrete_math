add_executable(test_find_sum_generator test_generator.cpp test_find_sum.cpp)
target_link_libraries(test_find_sum_generator GTest::gtest_main pprint::pprint)
