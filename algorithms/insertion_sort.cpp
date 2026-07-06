#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "utils.h"

/**
 * @brief Sorts a C-style array using the Insertion Sort algorithm.
 *
 * @tparam T The type of elements in the array.
 * @param arr The array to sort.
 * @param n The number of elements in the array.
 */
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Sorts a standard vector using the Insertion Sort algorithm.
 *
 * @tparam T The type of elements in the vector.
 * @param arr The vector to sort.
 */
template <typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    std::cout << "Sorted array: ";
    printArray(arr, n);

    for (int i = 0; i < n - 1; ++i) {
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
