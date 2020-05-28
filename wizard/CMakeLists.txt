cmake_minimum_required(VERSION 3.17.2)


set(CMAKE_SYSTEM_NAME DOS)
set(CMAKE_SYSTEM_PROCESSOR I86)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(CMAKE_BUILD_TYPE MinSizeRel)


project(adoiswiz VERSION 0.1)

add_executable(adoiswiz main.cpp)

set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")
find_library(ADAPT_LIBRARY NAMES dosadapt HINTS ../build/dosadapt)
target_link_libraries(adoiswiz ${ADAPT_LIBRARY})
include_directories(../inc)
