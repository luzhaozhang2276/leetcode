cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(leetcode main.cpp)