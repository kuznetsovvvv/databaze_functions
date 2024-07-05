cmake_minimum_required(VERSION 3.10) 

project(databazefunc)

set(CMAKE_CXX_STANDARD 17)

add_executable(
databazefunc
databaze_functions_and_files1.cpp
Functions.h
Functions.cpp
)

target_include_directories(databazefunc PRIVATE
   code 
)


