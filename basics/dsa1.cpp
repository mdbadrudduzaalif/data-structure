#include <iostream>
#include <vector>

void countOddEven(const std::vector<int>& arr) {
    int oddCount = 0;
    int evenCount = 0;

    for (int num : arr) {
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    std::cout << "odd : " << oddCount << std::endl;
    std::cout << "even : " << evenCount << std::endl;
}

int main() {
    std::vector<int> arr = {5, 89, 69, 25, 45, 14, 23, 54, 87, 59, 6, 4, 2, 8, 7, 4, 3, 6, 1, 4};
    countOddEven(arr);

    return 0;
}
