cmake_minimum_required(VERSION 3.17.2)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(CMAKE_BUILD_TYPE MinSizeRel)


project(adoisc VERSION 0.1)

IF(MSVC)
    add_compile_options(/EHsc)
ENDIF(MSVC)

add_executable(adoisc src/main.cpp)
include_directories(inc)
