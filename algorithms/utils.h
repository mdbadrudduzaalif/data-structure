#ifndef UTILS_H
#define UTILS_H

#include <iostream>

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif // UTILS_H
