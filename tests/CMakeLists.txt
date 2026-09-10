cmake_minimum_required(VERSION 3.12)

add_executable(unit_tests test_main.cpp)

target_link_libraries(unit_tests PRIVATE
    Lib::lib
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)