# 2019 

add_executable(2019.01 2019/01.cpp)
target_link_libraries ( 2019.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2019.01 ${CMAKE_BINARY_DIR}/2019.01 )

