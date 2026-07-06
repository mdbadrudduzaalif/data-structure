#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

/**
 * @brief Utility functions for the algorithms module.
 */

/**
 * @brief Prints the elements of a C-style array.
 *
 * @tparam T The type of elements in the array.
 * @param arr The C-style array to print.
 * @param size The number of elements in the array.
 */
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Prints the elements of a std::vector.
 *
 * @tparam T The type of elements in the vector.
 * @param arr The std::vector to print.
 */
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

#endif // UTILS_H
