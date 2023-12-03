# 2023 

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

