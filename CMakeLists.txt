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

# Testing
enable_testing()
add_test(NAME dsa1_test COMMAND dsa1)
add_test(NAME start_test COMMAND start)
add_test(NAME bubblesort_test COMMAND bubblesort)
add_test(NAME insertion_sort_test COMMAND insertion_sort)
add_test(NAME selectionsort_test COMMAND selectionsort)
add_test(NAME queue_test COMMAND queue)
add_test(NAME stack_test COMMAND stack)
