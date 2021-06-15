add_executable(test_nice_numbers13
    test_digit.cpp)
target_link_libraries(test_nice_numbers13 GTest::gtest_main)
add_test(NAME test_nice_numbers13 COMMAND test_nice_numbers13)
