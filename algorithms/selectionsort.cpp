#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "utils.h"

/**
 * @brief Sorts a C-style array using the Selection Sort algorithm.
 *
 * @tparam T The type of elements in the array.
 * @param arr The array to sort.
 * @param n The number of elements in the array.
 */
template <typename T>
void selectionSort(T arr[], int n) {
    if (n <= 1 || arr == nullptr) return;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(arr[i], arr[min]);
        }
    }
}

/**
 * @brief Sorts a standard vector using the Selection Sort algorithm.
 *
 * @tparam T The type of elements in the vector.
 * @param arr The vector to sort.
 */
template <typename T>
void selectionSort(std::vector<T>& arr) {
    if (arr.size() <= 1) return;
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(arr[i], arr[min]);
        }
    }
}


int main() {
    int array[] = {50, 10, 21, 7, 9, 78, 36, 123};
    int n = sizeof(array) / sizeof(array[0]);

    std::cout << "Original array: ";
    printArray(array, n);

    selectionSort(array, n);

    std::cout << "Sorted array: ";
    printArray(array, n);

    for (int i = 0; i < n - 1; ++i) {
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

    std::vector<int> empty_vec;
    selectionSort(empty_vec);
    assert(empty_vec.empty());

    std::cout << "All selectionSort tests passed." << std::endl;

    return 0;
}
