cmake_minimum_required(VERSION 3.17.2)


set(CMAKE_SYSTEM_NAME DOS)
set(CMAKE_SYSTEM_PROCESSOR I86)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED True)



set(CMAKE_BUILD_TYPE MinSizeRel)


project(dosadapt VERSION 0.1)
add_library(dosadapt screen.cpp)
include_directories(../inc)

string(APPEND CMAKE_CXX_FLAGS " -0 -xd")
