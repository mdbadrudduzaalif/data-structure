#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "utils.h"

/**
 * @brief Sorts a C-style array using the Insertion Sort algorithm.
 *
 * @tparam T The type of elements in the array.
 * @param arr The C-style array to sort.
 * @param size The number of elements in the array.
 */
template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Sorts a std::vector using the Insertion Sort algorithm.
 *
 * @tparam T The type of elements in the vector.
 * @param arr The std::vector to sort.
 */
template <typename T>
void insertionSort(std::vector<T>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    printArray(arr, size);
    
    insertionSort(arr, size);
    
    std::cout << "Sorted array: ";
    printArray(arr, size);

    for (int i = 0; i < size - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }

    std::vector<int> vec = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original vector: ";
    printArray(vec);

    insertionSort(vec);

    std::cout << "Sorted vector: ";
    printArray(vec);

    for (size_t i = 0; i < vec.size() - 1; ++i) {
        assert(vec[i] <= vec[i + 1]);
    }

    std::cout << "All insertionSort tests passed." << std::endl;
    
    return 0;
}
