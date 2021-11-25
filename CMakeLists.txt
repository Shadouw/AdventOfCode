cmake_minimum_required(VERSION 3.0.0)
project(AdventOfCode VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(2015.01 2015/01.cpp)
#add_executable(2015.01B 2015/01B.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
