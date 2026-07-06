#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

template <typename T, size_t msize = 7>
class Queue {
private:
    std::vector<T> queueArr;
    size_t frontIndex;
    size_t count;

public:
    Queue() : frontIndex(0), count(0) {
        queueArr.resize(msize);
    }

    void enqueue(const T& item) {
        if (count == msize) {
            throw std::overflow_error("Queue is full");
        }

        size_t rearIndex = (frontIndex + count) % msize;
        queueArr[rearIndex] = item;
        count++;
        std::cout << "Enqueued element: " << item << std::endl;
    }

    T dequeue() {
        if (count == 0) {
            throw std::underflow_error("Queue is empty");
        }

        T item = queueArr[frontIndex];
        frontIndex = (frontIndex + 1) % msize;
        count--;
        std::cout << "Dequeued element: " << item << std::endl;
        return item;
    }

    bool isEmpty() const {
        return count == 0;
    }

    T peek() const {
        if (count == 0) {
            throw std::underflow_error("Queue is empty");
        }
        return queueArr[frontIndex];
    }

    void display() const {
        if (count == 0) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        std::cout << "Display elements: ";
        for (size_t i = 0; i < count; i++) {
            std::cout << queueArr[(frontIndex + i) % msize] << " ";
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
    q.enqueue(70);
    q.enqueue(80);

    try {
        q.enqueue(90); // Overflow expected here
    } catch (const std::overflow_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    q.display();

    assert(q.dequeue() == 20);
    assert(q.dequeue() == 30);
    assert(q.dequeue() == 40);
    assert(q.dequeue() == 50);
    assert(q.dequeue() == 60);
    assert(q.dequeue() == 70);
    assert(q.dequeue() == 80);

    assert(q.isEmpty());

    std::cout << "All Queue tests passed." << std::endl;

    return 0;
}
