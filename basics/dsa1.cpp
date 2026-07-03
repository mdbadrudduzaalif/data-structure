#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

/**
 * @brief Counts the number of odd and even numbers in a given vector.
 *
 * @param arr The vector of integers.
 * @return A std::pair where the first element is the number of odd integers
 *         and the second element is the number of even integers.
 */
std::pair<int, int> countOddEven(const std::vector<int>& arr) {
    int oddCount = 0;
    int evenCount = 0;

    for (int num : arr) {
        // If number is perfectly divisible by 2, it is even.
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
