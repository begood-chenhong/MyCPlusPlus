# MyCPlusPlus
This learning project aims at creating a basic c++ development environment by integrating cmake, googletest and googlemock together.
More classes and modules can be built based on it step by step.   
It uses cmake to generate Makefile.  
It uses googletest to do basic unit test.  
It uses googlemock to simulate c++ mock class.   
Its directory structure obeys the basic project naming convention. Hopefully, bigger application can be built based on it.  

Usage:  
After git clone or download, below commands could be used to build the projects and generate executable files:    
$ cmake .  
$ make  
  
A lot of thanks to:  
1) Google test authors and user group.   
I Also refer to the usage description at:   
http://stackoverflow.com/questions/3951808/using-googletest-in-eclipse-how/5800759#5800759.  
2) cmake authors and user group.  
3) I followed these steps to create this project, so great thanks to the corresponding authors.  
   a) Create a simple cmake project:  
      https://cmake.org/cmake/help/latest/guide/tutorial/index.html#id1  
   b) Integrate googletest and googlemock to existing project created in step a) :  
      https://github.com/google/googletest/blob/master/googletest/README.md   
      https://crascit.com/2015/07/25/cmake-gtest/  
   c) Refer to below materials to create googletest and googlemock examples:  
      https://github.com/google/googletest/blob/master/googlemock/docs/for_dummies.md  
      https://github.com/google/googletest/tree/master/googlemock/docs  
      https://github.com/davidstutz/googlemock-example  
  
  
Note:
1) On CYGWIN64 platform, in order to make googlemock work, suggest to use "cmake . -Dgtest_disable_pthreads=ON".
Otherwise, below error can happen:
"[ FATAL ] /cygdrive/c/code/temp/TrialSecondApproach_OnlyDefault/googletest-src/googletest/include/gtest/internal/gtest-port.h:1636:: pthread_mutex_lock(&mutex_)failed with error 22
Aborted (core dumped)"
2) If want to generate google test sample executable files, suggest to use "cmake . -Dgtest_build_samples=ON".
3) If want want to build for debug (including source information, i.e. -g), use "cmake . -DCMAKE_BUILD_TYPE=Debug"  


