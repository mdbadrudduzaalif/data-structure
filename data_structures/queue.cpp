#include <iostream>

template <typename T, size_t msize = 7>
class Queue {
private:
    T queueArr[msize];
    int front; // if value is -1, the queue is empty
    int rear;  // if value is -1, the queue is empty

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(T item) {
        // check overflow for circular queue
        if ((front == 0 && rear == msize - 1) || (rear == (front - 1 + msize) % msize)) {
            std::cout << "*** overflow (queue is full) ***" << std::endl;
            return;
        }

        if (front == -1) {      // first element
            front = 0;
            rear = 0;
        } else if (rear == msize - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        queueArr[rear] = item;
        std::cout << "Enqueued element: " << item << std::endl;
    }

    T dequeue() {
        // check underflow
        if (front == -1) {
            std::cout << "*** underflow (queue is empty) ***" << std::endl;
            return T();
        }

        T item = queueArr[front];

        // if queue becomes empty again, reset indices
        if (front == rear) {
            front = -1;
            rear  = -1;
        } else if (front == msize - 1) {
            front = 0;
        } else {
            front++;
        }

        std::cout << "Dequeued element: " << item << std::endl;
        return item;
    }

    void display() const {
        if (front == -1) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        std::cout << "Display elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                std::cout << queueArr[i] << " ";
            }
        } else {
            for (int i = front; i < msize; i++) {
                std::cout << queueArr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                std::cout << queueArr[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> q;

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
