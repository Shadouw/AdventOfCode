cmake_minimum_required(VERSION 3.0.0)
project(AdventOfCode VERSION 0.1.0)

include(CTest)
enable_testing()



# Template
add_executable(template template.cpp)
target_include_directories ( template PRIVATE lib )
add_test ( template ${CMAKE_BINARY_DIR}/template )

# 2021 

add_executable(2021.11 2021/11.cpp)
target_include_directories ( 2021.11 PRIVATE lib )
add_test ( 2021.11 ${CMAKE_BINARY_DIR}/2021.11 )

add_executable(2021.10 2021/10.cpp)
target_include_directories ( 2021.10 PRIVATE lib )
add_test ( 2021.10 ${CMAKE_BINARY_DIR}/2021.10 )

add_executable(2021.09 2021/09.cpp)
add_executable(2021.08 2021/08.cpp)
add_executable(2021.07 2021/07.cpp)
add_executable(2021.06 2021/06.cpp)
add_executable(2021.05 2021/05.cpp)
add_executable(2021.04 2021/04.cpp)
add_executable(2021.03 2021/03.cpp)
add_executable(2021.02 2021/02.cpp)
add_executable(2021.01 2021/01.cpp)

# 2015

add_executable(2015.25 2015/25.cpp)
add_executable(2015.24 2015/24.cpp)
add_executable(2015.23 2015/23.cpp)
target_include_directories ( 2015.23 PRIVATE lib )
add_test ( 2015.23 ${CMAKE_BINARY_DIR}/2015.23 )

add_executable(2015.22 2015/22.cpp)
target_include_directories ( 2015.22 PRIVATE lib )
add_test ( 2015.22 ${CMAKE_BINARY_DIR}/2015.22 )

add_executable(2015.21 2015/21.cpp)
add_executable(2015.20 2015/20.cpp)
add_executable(2015.19 2015/19.cpp)
add_executable(2015.18 2015/18.cpp)
add_executable(2015.17 2015/17.cpp)
add_executable(2015.16 2015/16.cpp)
add_executable(2015.15 2015/15.cpp)
add_executable(2015.14 2015/14.cpp)
add_executable(2015.13 2015/13.cpp)
add_executable(2015.12 2015/12.cpp)
add_executable(2015.11 2015/11.cpp)
add_executable(2015.10 2015/10.cpp)
add_executable(2015.09 2015/09.cpp)
add_executable(2015.08 2015/08.cpp)
add_executable(2015.07 2015/07.cpp)
add_executable(2015.06 2015/06.cpp)
add_executable(2015.05 2015/05.cpp)

add_executable(2015.04 2015/04.cpp)
target_link_libraries(2015.04 crypto)

add_executable(2015.03 2015/03.cpp)
add_executable(2015.02 2015/02.cpp)

add_executable(2015.01 2015/01.cpp)
target_include_directories ( 2015.01 PRIVATE lib )
add_test ( 2015.01 ${CMAKE_BINARY_DIR}/2015.01 )




#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
