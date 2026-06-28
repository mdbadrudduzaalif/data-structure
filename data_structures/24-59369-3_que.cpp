#include <iostream>
#define msize 7
using namespace std;

class Queue {
private:
    int queueArr[msize];
    int front; // if value is -1, the queue is empty
    int rear;  // if value is -1, the queue is empty

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int item) {
        // check overflow
        if (rear == msize - 1) {
            cout << "*** overflow (queue is full) ***" << endl;
            return;
        }

        if (front == -1) {      // first element
            front = 0;
        }

        rear++;
        queueArr[rear] = item;
        cout << "Enqueued element: " << item << endl;
    }

    int dequeue() {
        // check underflow
        if (front == -1 || front > rear) {
            cout << "*** underflow (queue is empty) ***" << endl;
            return -1;
        }

        int item = queueArr[front];
        front++;

        // if queue becomes empty again, reset indices
        if (front > rear) {
            front = -1;
            rear  = -1;
        }

        cout << "Dequeued element: " << item << endl;
        return item;
    }

    void display() const {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Display elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queueArr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    return 0;
}
