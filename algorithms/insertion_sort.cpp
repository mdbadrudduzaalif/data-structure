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
void insertionSort(T arr[], size_t n) {
    if (n <= 1 || arr == nullptr) return;
    for (size_t i = 1; i < n; i++) {
        T key = std::move(arr[i]);
        std::ptrdiff_t j = static_cast<std::ptrdiff_t>(i) - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = std::move(arr[j]);
            j--;
        }
        arr[j + 1] = std::move(key);
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
    if (arr.size() <= 1) return;
    insertionSort(arr.data(), arr.size());
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    std::cout << "Sorted array: ";
    printArray(arr, n);

    for (size_t i = 0; i < n - 1; ++i) {
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

    // Edge cases testing
    std::vector<int> empty_vec;
    insertionSort(empty_vec);
    assert(empty_vec.empty());

    std::vector<int> single_element_vec = {42};
    insertionSort(single_element_vec);
    assert(single_element_vec.size() == 1 && single_element_vec[0] == 42);

    std::vector<int> negative_vec = {-5, 3, -2, 8, -10, 0};
    insertionSort(negative_vec);
    for (size_t i = 0; i < negative_vec.size() - 1; ++i) {
        assert(negative_vec[i] <= negative_vec[i + 1]);
    }

    std::cout << "All insertionSort tests passed." << std::endl;
    
    return 0;
}
