# 2023 

add_executable(2023.10 2023/10.cpp)
target_link_libraries ( 2023.10 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.10 ${CMAKE_BINARY_DIR}/2023.10 )

add_executable(2023.09 2023/09.cpp)
target_link_libraries ( 2023.09 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.09 ${CMAKE_BINARY_DIR}/2023.09 )

add_executable(2023.08 2023/08.cpp)
target_link_libraries ( 2023.08 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.08 ${CMAKE_BINARY_DIR}/2023.08 )

add_executable(2023.07 2023/07.cpp)
target_link_libraries ( 2023.07 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.07 ${CMAKE_BINARY_DIR}/2023.07 )

add_executable(2023.06 2023/06.cpp)
target_link_libraries ( 2023.06 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.06 ${CMAKE_BINARY_DIR}/2023.06 )

add_executable(2023.05 2023/05.cpp)
target_link_libraries ( 2023.05 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.05 ${CMAKE_BINARY_DIR}/2023.05 )

add_executable(2023.04 2023/04.cpp)
target_link_libraries ( 2023.04 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.04 ${CMAKE_BINARY_DIR}/2023.04 )

add_executable(2023.03 2023/03.cpp)
target_link_libraries ( 2023.03 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.03 ${CMAKE_BINARY_DIR}/2023.03 )

add_executable(2023.02 2023/02.cpp)
target_link_libraries ( 2023.02 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.02 ${CMAKE_BINARY_DIR}/2023.02 )

add_executable(2023.01 2023/01.cpp)
target_link_libraries ( 2023.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2023.01 ${CMAKE_BINARY_DIR}/2023.01 )

