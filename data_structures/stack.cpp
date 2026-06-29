#include <iostream>

template <typename T, size_t msize = 7>
class Stack {
private:
    T stackArr[msize];
    int top; //if value is -1, that means the stack is empty

public:
    Stack() {
        top = -1;
    }

    void push(T item) {
        //validation for full stack
        if (top == msize - 1) {
            std::cout << "***overflow***" << std::endl;
            return;
        }
        stackArr[++top] = item;
        std::cout << "pushed element " << item << std::endl;
    }

    T pop() {
        //validation for empty stack
        if (top == -1) {
            std::cout << "***underflow***" << std::endl;
            return T();
        }
        return stackArr[top--];
    }

    T peek() const {
        //validation for empty stack
        if (top == -1) {
            std::cout << "***underflow***" << std::endl;
            return T();
        }
        return stackArr[top];
    }
};

int main() {
    Stack<int> s;
    s.pop();
    s.peek();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    std::cout << "top element : " << s.peek() << std::endl;
    std::cout << "poped element : " << s.pop() << std::endl;
    std::cout << "top element : " << s.peek() << std::endl;

    return 0;
}
