#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

template <typename T, size_t msize = 7>
class Queue {
private:
    std::vector<T> queueArr;
    int front; // if value is -1, the queue is empty
    int rear;  // if value is -1, the queue is empty

public:
    Queue() {
        queueArr.resize(msize);
        front = -1;
        rear = -1;
    }

    void enqueue(T item) {
        // check overflow for circular queue
        if ((front == 0 && rear == static_cast<int>(msize) - 1) || (rear == (front - 1 + static_cast<int>(msize)) % static_cast<int>(msize))) {
            std::cerr << "*** overflow (queue is full) ***" << std::endl;
            return;
        }

        if (front == -1) {      // first element
            front = 0;
            rear = 0;
        } else if (rear == static_cast<int>(msize) - 1 && front != 0) {
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
            std::cerr << "*** underflow (queue is empty) ***" << std::endl;
            throw std::underflow_error("Queue is empty");
        }

        T item = queueArr[front];

        // if queue becomes empty again, reset indices
        if (front == rear) {
            front = -1;
            rear  = -1;
        } else if (front == static_cast<int>(msize) - 1) {
            front = 0;
        } else {
            front++;
        }

        std::cout << "Dequeued element: " << item << std::endl;
        return item;
    }

    bool isEmpty() const {
        return front == -1;
    }

    T peek() const {
        if (front == -1) {
            std::cerr << "*** underflow (queue is empty) ***" << std::endl;
            throw std::underflow_error("Queue is empty");
        }
        return queueArr[front];
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
            for (int i = front; i < static_cast<int>(msize); i++) {
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

    assert(q.isEmpty());

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    assert(!q.isEmpty());
    assert(q.peek() == 10);

    int dequeued = q.dequeue();
    assert(dequeued == 10);
    assert(q.peek() == 20);

    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();

    assert(q.dequeue() == 20);
    assert(q.dequeue() == 30);
    assert(q.dequeue() == 40);
    assert(q.dequeue() == 50);
    assert(q.dequeue() == 60);

    assert(q.isEmpty());

    std::cout << "All Queue tests passed." << std::endl;

    return 0;
}
