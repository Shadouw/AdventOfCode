# 2020 

add_executable(2020.02 2020/02.cpp)
target_link_libraries(2020.02 PRIVATE Catch2::Catch2WithMain)
add_test ( 2020.02 ${CMAKE_BINARY_DIR}/2020.02 )



add_executable(2020.01 2020/01.cpp)
target_link_libraries(2020.01 PRIVATE Catch2::Catch2WithMain)
add_test ( 2020.01 ${CMAKE_BINARY_DIR}/2020.01 )

