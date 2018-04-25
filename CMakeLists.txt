cmake_minimum_required(VERSION 3.0)
project(utility)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(utility impl.cpp)

target_include_directories(utility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
