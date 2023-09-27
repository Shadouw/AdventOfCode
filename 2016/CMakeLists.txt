# 2016

add_executable(2016.14 2016/14.cpp)
target_link_libraries ( 2016.14 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.14 ${CMAKE_BINARY_DIR}/2016.14 )

add_executable(2016.13 2016/13.cpp)
target_link_libraries ( 2016.13 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.13 ${CMAKE_BINARY_DIR}/2016.13 )

add_executable(2016.12 2016/12.cpp)
target_link_libraries ( 2016.12 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.12 ${CMAKE_BINARY_DIR}/2016.12 )

add_executable(2016.11 2016/11.cpp)
target_link_libraries ( 2016.11 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.11 ${CMAKE_BINARY_DIR}/2016.11 )

add_executable(2016.10 2016/10.cpp)
target_link_libraries ( 2016.10 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.10 ${CMAKE_BINARY_DIR}/2016.10 )

add_executable(2016.09 2016/09.cpp)
target_link_libraries ( 2016.09 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.09 ${CMAKE_BINARY_DIR}/2016.09 )

add_executable(2016.08 2016/08.cpp)
target_link_libraries ( 2016.08 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.08 ${CMAKE_BINARY_DIR}/2016.08 )

add_executable(2016.07 2016/07.cpp)
target_link_libraries ( 2016.07 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.07 ${CMAKE_BINARY_DIR}/2016.07 )

add_executable(2016.06 2016/06.cpp)
target_link_libraries ( 2016.06 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.06 ${CMAKE_BINARY_DIR}/2016.06 )

add_executable(2016.05 2016/05.cpp)
target_link_libraries ( 2016.05 PRIVATE Catch2::Catch2WithMain crypto )
add_test ( 2016.05 ${CMAKE_BINARY_DIR}/2016.05 )

add_executable(2016.04 2016/04.cpp)
target_link_libraries ( 2016.04 PRIVATE Catch2::Catch2WithMain )
add_test ( 2016.04 ${CMAKE_BINARY_DIR}/2016.04 )

add_executable(2016.03 2016/03.cpp)
target_link_libraries ( 2016.03 PRIVATE Catch2::Catch2WithMain )
add_test ( 2016.03 ${CMAKE_BINARY_DIR}/2016.03 )

add_executable(2016.02 2016/02.cpp)
target_link_libraries ( 2016.02 PRIVATE Catch2::Catch2WithMain )
add_test ( 2016.02 ${CMAKE_BINARY_DIR}/2016.02 )

add_executable(2016.01 2016/01.cpp)
target_link_libraries ( 2016.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2016.01 ${CMAKE_BINARY_DIR}/2016.01 )
