# 2020 

add_executable(2020.05 2020/05.cpp)
target_link_libraries(2020.05 PRIVATE Catch2::Catch2WithMain)
add_test ( 2020.05 ${CMAKE_BINARY_DIR}/2020.05 )

add_executable(2020.04 2020/04.cpp)
target_link_libraries(2020.04 PRIVATE Catch2::Catch2WithMain)
add_test ( 2020.04 ${CMAKE_BINARY_DIR}/2020.04 )

add_executable(2020.03 2020/03.cpp)
target_link_libraries(2020.03 PRIVATE Catch2::Catch2WithMain)
add_test ( 2020.03 ${CMAKE_BINARY_DIR}/2020.03 )

add_executable(2020.02 2020/02.cpp)
target_link_libraries(2020.02 PRIVATE Catch2::Catch2WithMain)
add_test ( 2020.02 ${CMAKE_BINARY_DIR}/2020.02 )

add_executable(2020.01 2020/01.cpp)
target_link_libraries(2020.01 PRIVATE Catch2::Catch2WithMain)
add_test ( 2020.01 ${CMAKE_BINARY_DIR}/2020.01 )

