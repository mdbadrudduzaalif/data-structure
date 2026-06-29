#include <iostream>
#include "utils.h"

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int last_index = n - 1; last_index > 0; last_index--) {
        for (int index = 0; index < last_index; index++) {
            if (arr[index] > arr[index + 1]) {
                T temp = arr[index];
                arr[index] = arr[index + 1];
                arr[index + 1] = temp;
            }
        }
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

    return 0;
}
