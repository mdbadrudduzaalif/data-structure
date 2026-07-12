#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>

/**
 * @brief Counts the number of odd and even numbers in a vector.
 *
 * @param arr The vector of integers.
 * @return A std::pair where the first element is the count of odd numbers
 *         and the second element is the count of even numbers.
 */
std::pair<int, int> countOddEven(const std::vector<int>& arr) {
    int evenCount = std::count_if(arr.begin(), arr.end(), [](int num) { return num % 2 == 0; });
    int oddCount = arr.size() - evenCount;
    return {oddCount, evenCount};
}

int main() {
    std::vector<int> arr = {5, 89, 69, 25, 45, 14, 23, 54, 87, 59, 6, 4, 2, 8, 7, 4, 3, 6, 1, 4};
    std::pair<int, int> counts = countOddEven(arr);

    std::cout << "odd : " << counts.first << std::endl;
    std::cout << "even : " << counts.second << std::endl;

    assert(counts.first == 11);
    assert(counts.second == 9);

    std::vector<int> empty_arr = {};
    std::pair<int, int> empty_counts = countOddEven(empty_arr);
    assert(empty_counts.first == 0);
    assert(empty_counts.second == 0);

    std::cout << "All dsa1 tests passed." << std::endl;

    return 0;
}
