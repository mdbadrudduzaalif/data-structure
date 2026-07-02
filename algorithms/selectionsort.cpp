#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "utils.h"

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}

template <typename T>
void selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
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

    std::cout << "All selectionSort tests passed." << std::endl;

    return 0;
}
