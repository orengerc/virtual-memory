cmake_minimum_required(VERSION 3.20)
project(virtual_memory)

set(CMAKE_CXX_STANDARD 11)

add_executable(virtual_memory SimpleTest.cpp PhysicalMemory.cpp VirtualMemory.cpp VirtualMemory.cpp BitwiseOps.h)
