#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

template <typename T, size_t msize = 7>
class Stack {
private:
    std::vector<T> stackArr;

public:
    Stack() {
        stackArr.reserve(msize);
    }

    void push(const T& item) {
        if (stackArr.size() == msize) {
            throw std::overflow_error("Stack is full");
        }
        stackArr.push_back(item);
        std::cout << "pushed element " << item << std::endl;
    }

    T pop() {
        if (stackArr.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        T item = stackArr.back();
        stackArr.pop_back();
        return item;
    }

    [[nodiscard]] T peek() const {
        if (stackArr.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return stackArr.back();
    }

    [[nodiscard]] bool isEmpty() const {
        return stackArr.empty();
    }
};

int main() {
    Stack<int> s;
    assert(s.isEmpty());

    try {
        s.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    try {
        (void)s.peek();
    } catch (const std::underflow_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    try {
        s.push(8); // Overflow expected here
    } catch (const std::overflow_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    assert(!s.isEmpty());
    assert(s.peek() == 7);
    std::cout << "top element : " << s.peek() << std::endl;

    int popped = s.pop();
    assert(popped == 7);
    std::cout << "poped element : " << popped << std::endl;

    assert(s.peek() == 6);
    std::cout << "top element : " << s.peek() << std::endl;

    std::cout << "All Stack tests passed." << std::endl;

    return 0;
}
