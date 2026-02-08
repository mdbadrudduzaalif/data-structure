#include<iostream>
using namespace std;
int main(){
int arr[10]={5,6,8,4,1,2,3,9,7,10};
int index;
int last_index;

// Bubble sort algorithm
for(last_index = 9; last_index > 0; last_index--) {
    for(index = 0; index < last_index; index++) {
        // Swap if current element is greater than next element
        if(arr[index] > arr[index + 1]) {
            int temp = arr[index];
            arr[index] = arr[index + 1];
            arr[index + 1] = temp;
        }
    }
}

// Print sorted array
cout << "Sorted array: ";
for(index = 0; index < 10; index++) {
    cout << arr[index] << " ";
}
cout << endl;

return 0;
}
