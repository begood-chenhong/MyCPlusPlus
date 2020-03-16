cmake_minimum_required(VERSION 3.10)
project (googlemock_example)

include_directories(../ ../../googletest-src/googletest/include ../../googletest-src/googlemock/include)
add_executable(order_test order_test.cpp)
target_link_libraries(order_test Order gmock gtest)
