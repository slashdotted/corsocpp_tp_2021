# Configurazione minimale per CMake
cmake_minimum_required(VERSION 3.19)
project(C02046)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(c02046 src/mylist.cpp src/main.cpp src/lecturer.cpp src/casts.cpp src/lecturerresearcher.cpp src/employee.cpp src/researcher.cpp src/overloading.cpp src/virtualdestructor.cpp src/finaldeletedefault.cpp src/hiding.cpp src/overriding.cpp src/derivationtypes.cpp src/polymorphic.cpp src/binding.cpp src/exceptions.cpp src/smartpointers_unique.cpp src/smartpointers_shared.cpp src/standardlibrary.cpp src/namespace.cpp src/raii.cpp src/esempio_struct.cpp src/structenum.cpp src/functions.cpp src/strings.cpp src/heap.cpp src/arrays.cpp src/references.cpp src/variables.cpp)
