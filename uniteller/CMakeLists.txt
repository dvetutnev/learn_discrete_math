add_executable(test_id
    symbol.cpp
    test_symbol.cpp
    digit.cpp
    test_digit.cpp
    group.cpp
    test_group.cpp
    id.cpp
    test_id.cpp)

target_link_libraries(test_id GTest::gtest_main)
add_test(NAME test_id COMMAND test_id)
