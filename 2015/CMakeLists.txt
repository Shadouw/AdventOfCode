# 2015

add_executable(2015.25 2015/25.cpp)
target_link_libraries ( 2015.25 PRIVATE Catch2::Catch2WithMain )
add_test ( 2015.25 ${CMAKE_BINARY_DIR}/2015.25 )

add_executable(2015.24 2015/24.cpp)
target_link_libraries(2015.24 PRIVATE Catch2::Catch2WithMain)
add_test ( 2015.24 ${CMAKE_BINARY_DIR}/2015.24 )

add_executable(2015.23 2015/23.cpp)
target_link_libraries ( 2015.23 PRIVATE Catch2::Catch2WithMain )
add_test ( 2015.23 ${CMAKE_BINARY_DIR}/2015.23 )

add_executable(2015.22 2015/22.cpp)
target_link_libraries ( 2015.22 PRIVATE Catch2::Catch2WithMain )
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

# sudo apt install libssl-dev
add_executable(2015.04 2015/04.cpp)
target_link_libraries(2015.04 crypto)

add_executable(2015.03 2015/03.cpp)
add_executable(2015.02 2015/02.cpp)

add_executable(2015.01 2015/01.cpp)
target_link_libraries ( 2015.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2015.01 ${CMAKE_BINARY_DIR}/2015.01 )