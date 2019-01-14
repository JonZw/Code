# Set minimum required CMake version
cmake_minimum_required(VERSION 3.5)
# Start project and set its name to ipk-demo
project(6.2 LANGUAGES CXX)
# Force compiler to run in C++14 mode
set(CMAKE_CXX_STANDARD 14)
#ennable testing
enable_testing()
# Create executable programs
add_executable(readv  readvector.cc)
add_executable(normalv normal.cc)
add_executable(uniformv uniform.cc)
add_executable(testmean meantest.cc)
add_executable(testmedian mediantest.cc)
#add libary
add_library(Lib io.cc statistics.cc)
#link libary
target_link_libraries(readv PUBLIC Lib)
target_link_libraries(normalv PUBLIC Lib)
target_link_libraries(uniformv PUBLIC Lib)
target_link_libraries(testmean PUBLIC Lib)
target_link_libraries(testmedian PUBLIC Lib)
#add test
add_test(NAME testmean COMMAND testmean)
add_test(NAME testmedian COMMAND testmedian)
