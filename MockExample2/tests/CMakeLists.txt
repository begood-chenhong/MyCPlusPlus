cmake_minimum_required(VERSION 3.10)
project (googlemock_example)

include_directories(../ ../../googletest-src/googletest/include ../../googletest-src/googlemock/include)
add_executable(painter_test painter_test.cpp)
target_link_libraries(painter_test gmock gtest)
