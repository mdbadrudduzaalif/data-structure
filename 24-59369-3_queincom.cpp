#include <iostream>
using namespace std;

#define MX_Size 7

int queue[MX_Size];
int front = -1;   // queue is empty
int rear  = -1;   // queue is empty

void enqueue(int item) {
    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = item;
    cout << "Enqueued Element: " << item << endl;
}

int dequeue() {
    return queue[front++];
}

void display() {
    cout << "Display Items: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
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
