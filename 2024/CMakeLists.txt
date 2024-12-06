# 2024 
file(GLOB files "2024/*.cpp")
foreach(filename ${files})
    get_filename_component(fn "${filename}" NAME_WE)
    message(STATUS "Add target: 2024.${fn}")

    add_executable(2024.${fn} 2024/${fn}.cpp)
    target_link_libraries ( 2024.${fn} PRIVATE crypto Catch2::Catch2WithMain )
    add_test ( 2024.${fn} ${CMAKE_BINARY_DIR}/2024.${fn} )    
endforeach()
