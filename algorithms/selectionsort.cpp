#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
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
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[] = {50, 10, 21, 7, 9, 78, 36, 123};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Original array: ";
    printArray(array, n);

    selectionSort(array, n);

    cout << "Sorted array: ";
    printArray(array, n);

    return 0;
}
