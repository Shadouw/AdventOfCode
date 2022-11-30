# 2022 

add_executable(2022.01 2022/01.cpp)
target_link_libraries ( 2022.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.01 ${CMAKE_BINARY_DIR}/2022.01 )

