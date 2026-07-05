#include <iostream>
#include <utility>
#include <cassert>

/**
 * @brief Calculates the sum and the difference of two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return std::pair<int, int> A pair containing the sum (first) and the difference (second, where difference is b - a).
 */
std::pair<int, int> getSumAndDifference(int a, int b) {
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
