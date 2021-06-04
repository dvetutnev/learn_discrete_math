add_executable(test_id
    symbol.cpp
    test_symbol.cpp
    digit.cpp
    test_digit.cpp
    item.cpp
    test_item.cpp)

target_link_libraries(test_id GTest::gtest_main)
add_test(NAME test_id COMMAND test_id)
