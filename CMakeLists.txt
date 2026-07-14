cmake_minimum_required(VERSION 3.10)
project(DSABasics)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic)

# Basics
add_executable(dsa1 basics/dsa1.cpp)
add_executable(start basics/start.cpp)

# Algorithms
add_executable(bubblesort algorithms/bubblesort.cpp)
add_executable(insertion_sort algorithms/insertion_sort.cpp)
add_executable(selectionsort algorithms/selectionsort.cpp)

# Data Structures
add_executable(queue data_structures/queue.cpp)
add_executable(stack data_structures/stack.cpp)

enable_testing()
add_test(NAME dsa1 COMMAND dsa1)
add_test(NAME start COMMAND start)
add_test(NAME bubblesort COMMAND bubblesort)
add_test(NAME insertion_sort COMMAND insertion_sort)
add_test(NAME selectionsort COMMAND selectionsort)
add_test(NAME queue COMMAND queue)
add_test(NAME stack COMMAND stack)
