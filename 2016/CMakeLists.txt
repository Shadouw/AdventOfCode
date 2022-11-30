# 2016

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
