#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

/**
 * @brief A generic circular queue data structure.
 *
 * @tparam T The type of elements to store.
 * @tparam msize The maximum size of the queue (default 7).
 */
template <typename T, size_t msize = 7>
class Queue {
private:
    std::vector<T> queueArr;
    int front; // -1 if empty
    int rear;  // -1 if empty

public:
    Queue() : front(-1), rear(-1) {
        queueArr.resize(msize);
    }

    /**
     * @brief Adds an item to the rear of the queue.
     * @param item The item to add.
     * @throws std::overflow_error if the queue is full.
     */
    void enqueue(T item) {
        // Simple check for circular queue full state
        if ((rear + 1) % static_cast<int>(msize) == front) {
            std::cerr << "*** overflow (queue is full) ***" << std::endl;
            throw std::overflow_error("Queue is full");
        }

        if (front == -1) { // first element
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % static_cast<int>(msize);
        }

        queueArr[rear] = item;
        std::cout << "Enqueued element: " << item << std::endl;
    }

    /**
     * @brief Removes and returns the item at the front of the queue.
     * @return The dequeued item.
     * @throws std::underflow_error if the queue is empty.
     */
    T dequeue() {
        if (isEmpty()) {
            std::cerr << "*** underflow (queue is empty) ***" << std::endl;
            throw std::underflow_error("Queue is empty");
        }

        T item = queueArr[front];

        if (front == rear) { // queue becomes empty
            front = -1;
            rear  = -1;
        } else {
            front = (front + 1) % static_cast<int>(msize);
        }

        std::cout << "Dequeued element: " << item << std::endl;
        return item;
    }

    /**
     * @brief Checks if the queue is empty.
     * @return True if empty, false otherwise.
     */
    bool isEmpty() const {
        return front == -1;
    }

    /**
     * @brief Returns the item at the front without removing it.
     * @return The item at the front.
     * @throws std::underflow_error if the queue is empty.
     */
    T peek() const {
        if (isEmpty()) {
            std::cerr << "*** underflow (queue is empty) ***" << std::endl;
            throw std::underflow_error("Queue is empty");
        }
        return queueArr[front];
    }

    /**
     * @brief Displays the elements of the queue.
     */
    void display() const {
        if (isEmpty()) {
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

    // Fill the queue
    q.enqueue(70);
    q.enqueue(80);

    // Test overflow
    try {
        q.enqueue(90);
        assert(false); // Should not reach here
    } catch (const std::overflow_error& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

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
