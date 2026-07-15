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
[[nodiscard]] std::pair<size_t, size_t> countOddEven(const std::vector<int>& arr) {
    size_t evenCount = static_cast<size_t>(std::count_if(arr.begin(), arr.end(), [](int num) { return num % 2 == 0; }));
    size_t oddCount = arr.size() - evenCount;
    return {oddCount, evenCount};
}

int main() {
    std::vector<int> arr = {5, 89, 69, 25, 45, 14, 23, 54, 87, 59, 6, 4, 2, 8, 7, 4, 3, 6, 1, 4};
    std::pair<size_t, size_t> counts = countOddEven(arr);

    std::cout << "odd : " << counts.first << std::endl;
    std::cout << "even : " << counts.second << std::endl;

    assert(counts.first == 11);
    assert(counts.second == 9);

    std::cout << "All dsa1 tests passed." << std::endl;

    return 0;
}
