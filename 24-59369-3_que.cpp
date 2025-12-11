#include <iostream>
#define msize 7
using namespace std;

int queueArr[msize];
int front = -1; // if value is -1, the queue is empty
int rear  = -1; // if value is -1, the queue is empty

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

void display() {
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

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();

    return 0;
}

