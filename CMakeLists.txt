
cmake_minimum_required(VERSION 3.14)
project(sort_benchmark VERSION 0.0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/config.h
)

# ---- Подключение GoogleTest через FetchContent ----
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP ON
)

# Форсируем сборку gtest в виде статических библиотек
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# --------------------------------------------------



add_subdirectory(lib)
add_subdirectory(src)

# Включаем поддержку тестов в CMake и добавляем папку с тестами
enable_testing()
add_subdirectory(tests)

