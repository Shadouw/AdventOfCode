# 2022 

add_executable(2022.07 2022/07.cpp)
target_link_libraries ( 2022.07 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.07 ${CMAKE_BINARY_DIR}/2022.07 )

add_executable(2022.06 2022/06.cpp)
target_link_libraries ( 2022.06 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.06 ${CMAKE_BINARY_DIR}/2022.06 )

add_executable(2022.05 2022/05.cpp)
target_link_libraries ( 2022.05 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.05 ${CMAKE_BINARY_DIR}/2022.05 )

add_executable(2022.04 2022/04.cpp)
target_link_libraries ( 2022.04 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.04 ${CMAKE_BINARY_DIR}/2022.04 )

add_executable(2022.03 2022/03.cpp)
target_link_libraries ( 2022.03 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.03 ${CMAKE_BINARY_DIR}/2022.03 )

add_executable(2022.02 2022/02.cpp)
target_link_libraries ( 2022.02 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.02 ${CMAKE_BINARY_DIR}/2022.02 )

add_executable(2022.01 2022/01.cpp)
target_link_libraries ( 2022.01 PRIVATE Catch2::Catch2WithMain )
add_test ( 2022.01 ${CMAKE_BINARY_DIR}/2022.01 )

