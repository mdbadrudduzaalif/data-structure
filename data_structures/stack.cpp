#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

/**
 * @brief A generic Stack data structure with a maximum size.
 *
 * @tparam T The type of elements to store.
 * @tparam msize The maximum size of the stack.
 */
template <typename T, size_t msize = 7>
class Stack {
    static_assert(msize > 0, "Stack size must be greater than 0");

private:
    std::vector<T> stackArr;

public:
    /**
     * @brief Constructor for the Stack class.
     */
    Stack() {
        stackArr.reserve(msize);
    }

    /**
     * @brief Adds an element to the top of the stack.
     *
     * @param item The element to push.
     * @throws std::overflow_error if the stack is full.
     */
    void push(const T& item) {
        if (stackArr.size() == msize) {
            throw std::overflow_error("Stack is full");
        }
        stackArr.push_back(item);
        std::cout << "pushed element " << item << std::endl;
    }

    /**
     * @brief Adds an element to the top of the stack using move semantics.
     *
     * @param item The element to push.
     * @throws std::overflow_error if the stack is full.
     */
    void push(T&& item) {
        if (stackArr.size() == msize) {
            throw std::overflow_error("Stack is full");
        }
        stackArr.push_back(std::move(item));
        std::cout << "pushed element " << stackArr.back() << std::endl;
    }

    /**
     * @brief Removes and returns the element at the top of the stack.
     *
     * @return The popped element.
     * @throws std::underflow_error if the stack is empty.
     */
    T pop() {
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
     * @return The top element.
     * @throws std::underflow_error if the stack is empty.
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

    /**
     * @brief Returns the number of elements in the stack.
     *
     * @return The size of the stack.
     */
    [[nodiscard]] size_t getSize() const {
        return stackArr.size();
    }

    /**
     * @brief Clears all elements from the stack.
     */
    void clear() {
        stackArr.clear();
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
    assert(s.getSize() == 6);

    // Test clear and getSize
    s.clear();
    assert(s.isEmpty());
    assert(s.getSize() == 0);

    // Test move semantics
    std::string str1 = "hello";
    Stack<std::string, 5> ss;
    ss.push(std::move(str1));
    assert(ss.getSize() == 1);
    assert(str1.empty()); // Moved from

    std::cout << "All Stack tests passed." << std::endl;

    return 0;
}
