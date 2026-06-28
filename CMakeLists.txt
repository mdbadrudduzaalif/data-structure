cmake_minimum_required(VERSION 3.10)
project(DSABasics)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Basics
add_executable(dsa1 basics/dsa1.cpp)
add_executable(start basics/start.cpp)

# Algorithms
add_executable(bubblesort algorithms/bubblesort.cpp)
add_executable(insertion_sort algorithms/insertion_sort.cpp)
add_executable(selectionsort algorithms/selectionsort.cpp)

# Data Structures
add_executable(queue data_structures/24-59369-3_que.cpp)
add_executable(stack data_structures/24-59369-3_stack.cpp)
