cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(postfix)

include_directories(include gtest)

add_subdirectory(src)
add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(test)
