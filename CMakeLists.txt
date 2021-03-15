# Configurazione minimale per CMake
cmake_minimum_required(VERSION 3.19)
project(C02046)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(c02046 src/main.cpp src/namespace.cpp src/raii.cpp src/esempio_struct.cpp src/structenum.cpp src/functions.cpp src/strings.cpp src/heap.cpp src/arrays.cpp src/references.cpp src/variables.cpp)
