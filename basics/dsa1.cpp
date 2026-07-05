#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

/**
 * @brief Counts the number of odd and even numbers in a given vector.
 *
 * @param arr The vector of integers to process.
 * @return std::pair<int, int> A pair containing the count of odd numbers (first) and even numbers (second).
 */
std::pair<int, int> countOddEven(const std::vector<int>& arr) {
    int oddCount = 0;
    int evenCount = 0;

    for (int num : arr) {
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    return {oddCount, evenCount};
}

int main() {
    std::vector<int> arr = {5, 89, 69, 25, 45, 14, 23, 54, 87, 59, 6, 4, 2, 8, 7, 4, 3, 6, 1, 4};
    std::pair<int, int> counts = countOddEven(arr);

    std::cout << "odd : " << counts.first << std::endl;
    std::cout << "even : " << counts.second << std::endl;

    assert(counts.first == 11);
    assert(counts.second == 9);

    std::cout << "All dsa1 tests passed." << std::endl;

    return 0;
}
