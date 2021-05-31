add_executable(test_boats test_boats.cpp)
target_link_libraries(test_boats GTest::gtest_main)
add_test(NAME test_boats COMMAND test_boats)
