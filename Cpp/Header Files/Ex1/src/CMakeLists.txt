cmake_minimum_required(VERSION 3.15)

project(Ex VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_library(cbancaria STATIC lib/conta/Bancaria.cpp lib/conta/Bancaria.hpp)
add_library(cpoupanca STATIC lib/conta/Poupanca.cpp lib/conta/Poupanca.hpp)
add_library(ccorrente STATIC lib/conta/Corrente.cpp lib/conta/Corrente.hpp)
add_library(banco STATIC lib/banco.hpp)
add_executable(main.out main.cpp)

target_link_libraries(cpoupanca PRIVATE cbancaria)
target_link_libraries(ccorrente PRIVATE cbancaria)
target_link_libraries(banco PUBLIC ccorrente cpoupanca)

target_link_libraries(main.out PRIVATE banco)
