#include <iostream>
#define msize 7
using namespace std;

class Stack {
private:
    int stackArr[msize];
    int top; //if value is -1, that means the stack is empty

public:
    Stack() {
        top = -1;
    }

    void push(int item) {
        //validation for full stack
        if (top == msize - 1) {
            cout << "***overflow***" << endl;
            return;
        }
        stackArr[++top] = item;
        cout << "pushed element " << item << endl;
    }

    int pop() {
        //validation for empty stack
        if (top == -1) {
            cout << "***underflow***" << endl;
            return -1;
        }
        return stackArr[top--];
    }

    int peek() const {
        //validation for empty stack
        if (top == -1) {
            cout << "***underflow***" << endl;
            return -1;
        }
        return stackArr[top];
    }
};

int main() {
    Stack s;
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
    cout << "top element : " << s.peek() << endl;
    cout << "poped element : " << s.pop() << endl;
    cout << "top element : " << s.peek() << endl;

    return 0;
}
