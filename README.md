# MyCPlusPlus
This project aims at creating basic c++ class and modules. More modules will be integrated into it step by step. 
It uses cmake to generate Makefile.
It uses google test to do basic unit test. 
Its directory structure obeys the basic project naming convention. Hopefully, bigger application can be built based on it.

After git clone or download, below commands could be used to build the projects:
echnhog@CN00046054 ~/MyCPlusPlus
$ cmake .
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++.exe
-- Check for working CXX compiler: /usr/bin/c++.exe -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/echnhog/MyCPlusPlus

echnhog@CN00046054 ~/MyCPlusPlus
$ make
Scanning dependencies of target GTEST
[  3%] Building CXX object CMakeFiles/GTEST.dir/contrib/gtest/gtest-all.cc.o
[  6%] Linking CXX static library libGTEST.a
[  6%] Built target GTEST
Scanning dependencies of target hello
[  9%] Building CXX object CMakeFiles/hello.dir/src/hello.cc.o
[ 12%] Linking CXX static library libhello.a
[ 12%] Built target hello
Scanning dependencies of target sample
[ 15%] Building CXX object CMakeFiles/sample.dir/src/samples/sample1.cc.o
[ 18%] Building CXX object CMakeFiles/sample.dir/src/samples/sample2.cc.o
[ 21%] Building CXX object CMakeFiles/sample.dir/src/samples/sample4.cc.o
[ 24%] Linking CXX static library libsample.a
[ 24%] Built target sample
Scanning dependencies of target AllTest
[ 27%] Building CXX object CMakeFiles/AllTest.dir/test/src/gtest_main.cc.o
[ 30%] Building CXX object
CMakeFiles/AllTest.dir/test/src/samples/sample1_unittest.cc.o
[ 33%] Building CXX object
CMakeFiles/AllTest.dir/test/src/samples/sample2_unittest.cc.o
[ 36%] Building CXX object
CMakeFiles/AllTest.dir/test/src/samples/sample3_unittest.cc.o
[ 39%] Building CXX object
CMakeFiles/AllTest.dir/test/src/samples/sample4_unittest.cc.o
[ 42%] Building CXX object
CMakeFiles/AllTest.dir/test/src/samples/sample6_unittest.cc.o
[ 45%] Building CXX object
CMakeFiles/AllTest.dir/test/src/samples/sample7_unittest.cc.o
[ 48%] Building CXX object CMakeFiles/AllTest.dir/test/src/hello_test.cc.o
[ 51%] Linking CXX executable AllTest.exe
[ 51%] Built target AllTest
Scanning dependencies of target samples_unittest
[ 54%] Building CXX object
CMakeFiles/samples_unittest.dir/test/src/gtest_main.cc.o
[ 57%] Building CXX object
CMakeFiles/samples_unittest.dir/test/src/samples/sample1_unittest.cc.o
[ 60%] Building CXX object
CMakeFiles/samples_unittest.dir/test/src/samples/sample2_unittest.cc.o
[ 63%] Building CXX object
CMakeFiles/samples_unittest.dir/test/src/samples/sample3_unittest.cc.o
[ 66%] Building CXX object
CMakeFiles/samples_unittest.dir/test/src/samples/sample4_unittest.cc.o
[ 69%] Building CXX object
CMakeFiles/samples_unittest.dir/test/src/samples/sample6_unittest.cc.o
[ 72%] Building CXX object
CMakeFiles/samples_unittest.dir/test/src/samples/sample7_unittest.cc.o
[ 75%] Linking CXX executable samples_unittest.exe
[ 75%] Built target samples_unittest
Scanning dependencies of target sample1_unittest
[ 78%] Building CXX object
CMakeFiles/sample1_unittest.dir/test/src/gtest_main.cc.o
[ 81%] Building CXX object
CMakeFiles/sample1_unittest.dir/test/src/samples/sample1_unittest.cc.o
[ 84%] Linking CXX executable sample1_unittest.exe
[ 84%] Built target sample1_unittest
Scanning dependencies of target MainProduct
[ 87%] Building CXX object CMakeFiles/MainProduct.dir/src/mainProduct.cc.o
[ 90%] Linking CXX executable MainProduct.exe
[ 90%] Built target MainProduct
Scanning dependencies of target hello_unittest
[ 93%] Building CXX object
CMakeFiles/hello_unittest.dir/test/src/gtest_main.cc.o
[ 96%] Building CXX object
CMakeFiles/hello_unittest.dir/test/src/hello_test.cc.o
[100%] Linking CXX executable hello_unittest.exe
[100%] Built target hello_unittest

A lot of thanks to:
1) Google test author and user group. Especially:
http://stackoverflow.com/questions/3951808/using-googletest-in-eclipse-how/5800759#5800759.
2) cmake author and user group.

