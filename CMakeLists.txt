cmake_minimum_required(VERSION 3.10)

project(6502)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(emulator 
main.cpp 
cpu.cpp 
cpuMemory.cpp 
)

