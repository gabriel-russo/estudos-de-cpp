cmake_minimum_required(VERSION 3.15)

project(Ex)

set(CMAKE_CXX_STANDARD 11)

add_executable(main.out
        src/main.cpp
        src/ContaCorrente.cpp src/ContaCorrente.h
        src/ContaPoupanca.cpp src/ContaPoupanca.h
        src/ContaBancaria.cpp src/ContaBancaria.h
        )
