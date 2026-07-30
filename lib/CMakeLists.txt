cmake_minimum_required(VERSION 3.12)

add_library(lib STATIC sort_func.cpp sort_bench_lib.h)

add_library(Lib::lib ALIAS lib)

target_include_directories(lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>       
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/generated>     
    $<INSTALL_INTERFACE:include>                         
)

include(GNUInstallDirs)

install(TARGETS lib EXPORT libTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES sort_bench_lib.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT libTargets
        FILE libConfig.cmake
        NAMESPACE Lib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Lib
)
