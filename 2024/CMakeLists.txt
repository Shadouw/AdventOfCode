# 2024 

add_executable(2024.02 2024/02.cpp)
target_link_libraries ( 2024.02 PRIVATE Catch2::Catch2WithMain )
add_test ( 2024.02 ${CMAKE_BINARY_DIR}/2024.02 )

add_executable(2024.01 2024/01.cpp)
target_link_libraries ( 2024.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2024.01 ${CMAKE_BINARY_DIR}/2024.01 )

