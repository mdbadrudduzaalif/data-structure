#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "utils.h"

/**
 * @brief Sorts a C-style array using the Selection Sort algorithm.
 *
 * @tparam T The type of elements in the array.
 * @param arr The C-style array to sort.
 * @param size The number of elements in the array.
 */
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

/**
 * @brief Sorts a std::vector using the Selection Sort algorithm.
 *
 * @tparam T The type of elements in the vector.
 * @param arr The std::vector to sort.
 */
template <typename T>
void selectionSort(std::vector<T>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        std::swap(arr[i], arr[min_idx]);
    }
}


int main() {
    int array[] = {50, 10, 21, 7, 9, 78, 36, 123};
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Original array: ";
    printArray(array, size);

    selectionSort(array, size);

    std::cout << "Sorted array: ";
    printArray(array, size);

    for (int i = 0; i < size - 1; ++i) {
        assert(array[i] <= array[i + 1]);
    }

    std::vector<int> vec = {50, 10, 21, 7, 9, 78, 36, 123};
    std::cout << "Original vector: ";
    printArray(vec);

    selectionSort(vec);

    std::cout << "Sorted vector: ";
    printArray(vec);

    for (size_t i = 0; i < vec.size() - 1; ++i) {
        assert(vec[i] <= vec[i + 1]);
    }

    std::cout << "All selectionSort tests passed." << std::endl;

    return 0;
}
