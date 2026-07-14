#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

/**
 * @brief A generic Stack data structure with a fixed maximum size.
 *
 * @tparam T The type of elements to store in the stack.
 * @tparam msize The maximum number of elements the stack can hold. Defaults to 7.
 */
template <typename T, size_t msize = 7>
class Stack {
private:
    std::vector<T> stackArr;

public:
    /**
     * @brief Constructs a new Stack object.
     */
    Stack() {
        stackArr.reserve(msize);
    }

    /**
     * @brief Pushes an element onto the top of the stack.
     *
     * @param item The element to add.
     * @throw std::overflow_error if the stack is full.
     */
    void push(const T& item) {
        if (stackArr.size() == msize) {
            throw std::overflow_error("Stack is full");
        }
        stackArr.push_back(item);
        std::cout << "pushed element " << item << std::endl;
    }

    /**
     * @brief Removes and returns the element at the top of the stack.
     *
     * @return The element at the top.
     * @throw std::underflow_error if the stack is empty.
     */
    [[nodiscard]] T pop() {
        if (stackArr.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        T item = stackArr.back();
        stackArr.pop_back();
        return item;
    }

    /**
     * @brief Returns the element at the top of the stack without removing it.
     *
     * @return The element at the top.
     * @throw std::underflow_error if the stack is empty.
     */
    [[nodiscard]] T peek() const {
        if (stackArr.empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return stackArr.back();
    }

    /**
     * @brief Checks if the stack is empty.
     *
     * @return true if the stack is empty, false otherwise.
     */
    [[nodiscard]] bool isEmpty() const {
        return stackArr.empty();
    }
};

int main() {
    Stack<int> s;
    assert(s.isEmpty());

    try {
        (void)s.pop();
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
