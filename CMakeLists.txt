cmake_minimum_required(VERSION 3.4)
project(databazefunc)
set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/code)

include(CPack.cmake)
