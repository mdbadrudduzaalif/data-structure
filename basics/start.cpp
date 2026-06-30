#include <iostream>

void printSumAndDifference(int a, int b) {
    int sum = a + b;
    int diff = b - a;

    std::cout << sum << std::endl;
    std::cout << diff << std::endl; // Added newline for cleaner output
}

int main() {
    int a = 20;
    int b = 40;

    printSumAndDifference(a, b);

    return 0;
}
