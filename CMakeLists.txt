# CMakeLists files in this project can

cmake_minimum_required (VERSION 2.8.11)
# by begood: here define the project name. Then ${MAIN_SOURCE_DIR} is the current 
project (MAIN)

# refer to the root source directory of the project as ${MAIN_SOURCE_DIR} and
# to the root binary directory of the project as ${MAIN_BINARY_DIR}.


#==========  General ===============================================
include_directories (${MAIN_SOURCE_DIR}/src) 

#probably this debug enable flag doesn't work
add_definitions(-DDEBUG)


#==========  Common  for both Product and Test ======================
#1) For samples directory 
aux_source_directory(${MAIN_SOURCE_DIR}/src/samples samples)
add_library (sample ${samples})
target_include_directories (sample PUBLIC ${MAIN_SOURCE_DIR}/src/samples)

add_library (hello ${MAIN_SOURCE_DIR}/src/hello.cc)
target_include_directories (hello PUBLIC ${MAIN_SOURCE_DIR}/src)


#==========  Product  ==================================================
#Try to build Product code
add_executable (MainProduct ${MAIN_SOURCE_DIR}/src/mainProduct.cc)
target_link_libraries (MainProduct LINK_PUBLIC sample)
target_link_libraries (MainProduct LINK_PUBLIC hello)


# ========== Test: all of below tests use Google Test Framework===============
#Found below two commands are not neeed. So comment them.
#find_package(Threads)
#target_link_libraries (MainTest ${CMAKE_THREAD_LIBS_INIT})

#include_directories (${MAIN_SOURCE_DIR}/contrib/gtest) 
add_library (GTEST ${MAIN_SOURCE_DIR}/contrib/gtest/gtest-all.cc)
target_include_directories (GTEST PUBLIC ${MAIN_SOURCE_DIR}/contrib/gtest)

include_directories (${MAIN_SOURCE_DIR}/test/src) 
# ========== Test: SampleTest=================================================
#1) sample1_unittest
add_executable (sample1_unittest ${MAIN_SOURCE_DIR}/test/src/gtest_main.cc ${MAIN_SOURCE_DIR}/test/src/samples/sample1_unittest.cc)
target_link_libraries (sample1_unittest LINK_PUBLIC GTEST)
target_link_libraries (sample1_unittest LINK_PUBLIC sample)

#2) all sample unit tests
aux_source_directory(${MAIN_SOURCE_DIR}/test/src/samples sample_test_files)
add_executable (samples_unittest ${MAIN_SOURCE_DIR}/test/src/gtest_main.cc ${sample_test_files})
target_link_libraries (samples_unittest LINK_PUBLIC GTEST)
target_link_libraries (samples_unittest LINK_PUBLIC sample)

#3) hello unit test
add_executable (hello_unittest ${MAIN_SOURCE_DIR}/test/src/gtest_main.cc ${MAIN_SOURCE_DIR}/test/src/hello_test.cc)
target_link_libraries (hello_unittest LINK_PUBLIC GTEST)
target_link_libraries (hello_unittest LINK_PUBLIC hello)

#==========  Test: MainTest For all test ================================
add_executable (AllTest ${MAIN_SOURCE_DIR}/test/src/gtest_main.cc ${sample_test_files} ${MAIN_SOURCE_DIR}/test/src/hello_test.cc)
target_link_libraries (AllTest LINK_PUBLIC GTEST)
target_link_libraries (AllTest LINK_PUBLIC sample)
target_link_libraries (AllTest LINK_PUBLIC hello)



