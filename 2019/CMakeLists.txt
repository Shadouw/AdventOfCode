# 2019 
file(GLOB files "2019/*.cpp")
foreach(filename ${files})
    get_filename_component(fn "${filename}" NAME_WE)
    message(STATUS "Add target: 2019.${fn}")

    add_executable(2019.${fn} 2019/${fn}.cpp)
    target_link_libraries ( 2019.${fn} PRIVATE crypto Catch2::Catch2WithMain )
    add_test ( 2019.${fn} ${CMAKE_BINARY_DIR}/2019.${fn} )    
endforeach()