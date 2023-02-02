cmake_minimum_required(VERSION 3.15)

project(Ex VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(include/banco)

add_executable(main.out main.cpp)

target_link_libraries(main.out PRIVATE banco)
