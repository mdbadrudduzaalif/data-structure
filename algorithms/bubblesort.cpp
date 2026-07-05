#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "utils.h"

/**
 * @brief Sorts a C-style array using the Bubble Sort algorithm.
 *
 * @tparam T The type of elements in the array.
 * @param arr The array to sort.
 * @param n The number of elements in the array.
 */
template <typename T>
void bubbleSort(T arr[], int n) {
    for (int last_index = n - 1; last_index > 0; last_index--) {
        bool swapped = false;
        for (int index = 0; index < last_index; index++) {
            if (arr[index] > arr[index + 1]) {
                std::swap(arr[index], arr[index + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

/**
 * @brief Sorts a standard vector using the Bubble Sort algorithm.
 *
 * @tparam T The type of elements in the vector.
 * @param arr The vector to sort.
 */
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    if (arr.empty()) return;
    int n = arr.size();
    for (int last_index = n - 1; last_index > 0; last_index--) {
        bool swapped = false;
        for (int index = 0; index < last_index; index++) {
            if (arr[index] > arr[index + 1]) {
                std::swap(arr[index], arr[index + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int arr[] = {5, 6, 8, 4, 1, 2, 3, 9, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    // Basic unit test
    for (int i = 0; i < n - 1; ++i) {
        assert(arr[i] <= arr[i + 1]);
    }

    std::vector<int> vec = {5, 6, 8, 4, 1, 2, 3, 9, 7, 10};
    std::cout << "Original vector: ";
    printArray(vec);

    bubbleSort(vec);

    std::cout << "Sorted vector: ";
    printArray(vec);

    // Basic unit test
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        assert(vec[i] <= vec[i + 1]);
    }

    std::cout << "All bubbleSort tests passed." << std::endl;

    return 0;
}
