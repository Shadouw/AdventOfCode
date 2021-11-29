cmake_minimum_required(VERSION 3.0.0)
project(AdventOfCode VERSION 0.1.0)

#include(CTest)
#enable_testing()

add_executable(2015.01 2015/01.cpp)
add_executable(2015.02 2015/02.cpp)
add_executable(2015.03 2015/03.cpp)


add_executable(2015.04 2015/04.cpp)
target_link_libraries(2015.04 crypto)

add_executable(2015.05 2015/05.cpp)
add_executable(2015.06 2015/06.cpp)
add_executable(2015.07 2015/07.cpp)
add_executable(2015.08 2015/08.cpp)
add_executable(2015.09 2015/09.cpp)
add_executable(2015.10 2015/10.cpp)
add_executable(2015.11 2015/11.cpp)
add_executable(2015.12 2015/12.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
