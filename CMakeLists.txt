cmake_minimum_required(VERSION 3.5)
project(AdventOfCode VERSION 0.1.0)

# Install Catch2
# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#installing-catch2-from-git-repository

find_package(Catch2 REQUIRED)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

include_directories ( include )

# Template
add_executable(template template.cpp)
target_link_libraries ( template PRIVATE Catch2::Catch2WithMain )
add_test ( template ${CMAKE_BINARY_DIR}/template )

# Include Sub folders per year
include(2024/CMakeLists.txt)
include(2023/CMakeLists.txt)
include(2022/CMakeLists.txt)
include(2021/CMakeLists.txt)
include(2020/CMakeLists.txt)
include(2019/CMakeLists.txt)
include(2018/CMakeLists.txt)
include(2017/CMakeLists.txt)
include(2016/CMakeLists.txt)
include(2015/CMakeLists.txt)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
