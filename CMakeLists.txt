cmake_minimum_required(VERSION 3.12)
project(fixed_point)

set(CMAKE_CXX_STANDARD 98)

add_executable(fixed_point main.cpp Price.cpp Price.h)