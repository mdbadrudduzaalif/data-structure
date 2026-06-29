#include <iostream>
#include "utils.h"

template <typename T>
void selectionSort(T arr[], int n) {
    // Outer loop for checking the current position
    for (int i = 0; i < n; i++) {
        // Pick the current position for the min value.
        int min = i;

        // Inner loop for finding the index position of min value
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }

        // Swap
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    return 0;
}
