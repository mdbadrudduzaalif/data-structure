#include <iostream>
#include <utility>
#include <cassert>

/**
 * @brief Calculates the sum and difference of two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return A std::pair containing the sum and difference.
 */
[[nodiscard]] std::pair<int, int> getSumAndDifference(const int a, const int b) {
    int sum = a + b;
    int diff = b - a;
    return {sum, diff};
}

int main() {
    int a = 20;
    int b = 40;

    std::pair<int, int> result = getSumAndDifference(a, b);

    std::cout << result.first << std::endl;
    std::cout << result.second << std::endl;

    assert(result.first == 60);
    assert(result.second == 20);

    std::cout << "All start tests passed." << std::endl;

    return 0;
}
