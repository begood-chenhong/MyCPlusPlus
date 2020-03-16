cmake_minimum_required(VERSION 3.10)
project (googletest_example)

include_directories(../ ../../googletest-src/googletest/include)
add_executable(queue_test queue_test.cpp)
target_link_libraries(queue_test gtest)
