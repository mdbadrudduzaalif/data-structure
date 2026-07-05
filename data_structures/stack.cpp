#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

/**
 * @brief A template class representing a stack data structure.
 *
 * @tparam T The type of elements in the stack.
 * @tparam msize The maximum size of the stack (default is 7).
 */
template <typename T, size_t msize = 7>
class Stack {
private:
    std::vector<T> stackArr;
    int top; //if value is -1, that means the stack is empty

public:
    /**
     * @brief Constructs an empty Stack.
     */
    Stack() {
        stackArr.resize(msize);
        top = -1;
    }

    /**
     * @brief Pushes an element onto the top of the stack.
     *
     * @param item The element to push.
     * @throws std::overflow_error if the stack is full.
     */
    void push(T item) {
        //validation for full stack
        if (top == static_cast<int>(msize) - 1) {
            throw std::overflow_error("Stack is full");
        }
        stackArr[++top] = item;
        std::cout << "pushed element " << item << std::endl;
    }

    /**
     * @brief Removes and returns the element at the top of the stack.
     *
     * @return The element at the top of the stack.
     * @throws std::underflow_error if the stack is empty.
     */
    T pop() {
        //validation for empty stack
        if (top == -1) {
            throw std::underflow_error("Stack is empty");
        }
        return stackArr[top--];
    }

    /**
     * @brief Returns the element at the top of the stack without removing it.
     *
     * @return The element at the top of the stack.
     * @throws std::underflow_error if the stack is empty.
     */
    T peek() const {
        //validation for empty stack
        if (top == -1) {
            throw std::underflow_error("Stack is empty");
        }
        return stackArr[top];
    }

    /**
     * @brief Checks if the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty() const {
        return top == -1;
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
        s.peek();
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
        assert(false);
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
