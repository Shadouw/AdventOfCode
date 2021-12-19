cmake_minimum_required(VERSION 3.5)
project(AdventOfCode VERSION 0.1.0)

# Install Catch2
# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#installing-catch2-from-git-repository

find_package(Catch2 REQUIRED)


include(CTest)
enable_testing()



# Template
add_executable(template template.cpp)
target_link_libraries ( template PRIVATE Catch2::Catch2 )
add_test ( template ${CMAKE_BINARY_DIR}/template )

# 2021 

add_executable(2021.19 2021/19.cpp)
target_link_libraries(2021.19 PRIVATE Catch2::Catch2)
add_test ( 2021.19 ${CMAKE_BINARY_DIR}/2021.19 )

add_executable(2021.18 2021/18.cpp)
target_link_libraries(2021.18 PRIVATE Catch2::Catch2)
add_test ( 2021.18 ${CMAKE_BINARY_DIR}/2021.18 )

add_executable(2021.17 2021/17.cpp)
target_link_libraries(2021.17 PRIVATE Catch2::Catch2)
add_test ( 2021.17 ${CMAKE_BINARY_DIR}/2021.17 )

add_executable(2021.16 2021/16.cpp)
target_link_libraries(2021.16 PRIVATE Catch2::Catch2)
add_test ( 2021.16 ${CMAKE_BINARY_DIR}/2021.16 )

add_executable(2021.15 2021/15.cpp)
target_link_libraries(2021.15 PRIVATE Catch2::Catch2)
add_test ( 2021.15 ${CMAKE_BINARY_DIR}/2021.15 )

add_executable(2021.14 2021/14.cpp)
target_link_libraries(2021.14 PRIVATE Catch2::Catch2)
add_test ( 2021.14 ${CMAKE_BINARY_DIR}/2021.14 )


add_executable(2021.13 2021/13.cpp)
target_link_libraries ( 2021.13 PRIVATE Catch2::Catch2 )
add_test ( 2021.13 ${CMAKE_BINARY_DIR}/2021.13 )

add_executable(2021.12 2021/12.cpp)
target_link_libraries ( 2021.12 PRIVATE Catch2::Catch2 )
add_test ( 2021.12 ${CMAKE_BINARY_DIR}/2021.12 )

add_executable(2021.11 2021/11.cpp)
target_link_libraries ( 2021.11 PRIVATE Catch2::Catch2 )
add_test ( 2021.11 ${CMAKE_BINARY_DIR}/2021.11 )

add_executable(2021.10 2021/10.cpp)
target_link_libraries ( 2021.10 PRIVATE Catch2::Catch2 )
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
target_link_libraries ( 2015.25 PRIVATE Catch2::Catch2 )
add_test ( 2015.25 ${CMAKE_BINARY_DIR}/2015.25 )

add_executable(2015.24 2015/24.cpp)
target_link_libraries(2015.24 PRIVATE Catch2::Catch2)
add_test ( 2015.24 ${CMAKE_BINARY_DIR}/2015.24 )

add_executable(2015.23 2015/23.cpp)
target_link_libraries ( 2015.23 PRIVATE Catch2::Catch2 )
add_test ( 2015.23 ${CMAKE_BINARY_DIR}/2015.23 )

add_executable(2015.22 2015/22.cpp)
target_link_libraries ( 2015.22 PRIVATE Catch2::Catch2 )
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
target_link_libraries ( 2015.01 PRIVATE Catch2::Catch2 )
add_test ( 2015.01 ${CMAKE_BINARY_DIR}/2015.01 )




#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
