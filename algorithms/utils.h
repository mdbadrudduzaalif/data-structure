#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

template <typename T>
void printArray(const T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

#endif // UTILS_H
