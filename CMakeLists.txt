cmake_minimum_required(VERSION 3.12)
project(sort_benchmark VERSION 0.0.1 LANGUAGES CXX)

add_executable(
    my_sort src/main.cpp
    lib/sort_bench_lib.h
    lib/sort_func.cpp
)

target_link_libraries(my_sort PRIVATE Lib::lib) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/config.h
)

add_subdirectory(lib)
add_subdirectory(src)