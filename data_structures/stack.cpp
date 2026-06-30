#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

template <typename T, size_t msize = 7>
class Stack {
private:
    std::vector<T> stackArr;
    int top; //if value is -1, that means the stack is empty

public:
    Stack() {
        stackArr.resize(msize);
        top = -1;
    }

    void push(T item) {
        //validation for full stack
        if (top == static_cast<int>(msize) - 1) {
            std::cerr << "*** overflow ***" << std::endl;
            return;
        }
        stackArr[++top] = item;
        std::cout << "pushed element " << item << std::endl;
    }

    T pop() {
        //validation for empty stack
        if (top == -1) {
            std::cerr << "*** underflow ***" << std::endl;
            throw std::underflow_error("Stack is empty");
        }
        return stackArr[top--];
    }

    T peek() const {
        //validation for empty stack
        if (top == -1) {
            std::cerr << "*** underflow ***" << std::endl;
            throw std::underflow_error("Stack is empty");
        }
        return stackArr[top];
    }

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
    s.push(8); // Overflow expected here

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
