# 2018 

add_executable(2018.01 2018/01.cpp)
target_link_libraries ( 2018.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2018.01 ${CMAKE_BINARY_DIR}/2018.01 )

