cmake_minimum_required(VERSION 3.19)

project(main)
#project(training1)

set(CMAKE_CXX_STANDARD 11   )
set(CMAKE_BUILD_TYPE Debug)


include_directories(${PROJECT_SOURCE_DIR}/include/)

#add_library(${PROJECT_NAME}
#        include/LeetCode.h)

add_executable(main src/main.cpp)


