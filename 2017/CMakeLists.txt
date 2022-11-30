# 2017 

add_executable(2017.01 2017/01.cpp)
target_link_libraries ( 2017.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2017.01 ${CMAKE_BINARY_DIR}/2017.01 )

