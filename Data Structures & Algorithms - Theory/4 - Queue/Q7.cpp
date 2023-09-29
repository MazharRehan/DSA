// Array representation of Queue

#include <iostream>
using namespace std;

// A structure to represent a queue
class Queue 
{
public:
    int front, rear, size;
    unsigned cap;
    int* arr;
};

// Function to create a queue of given capacity
// It initializes size of queue as 0
Queue* createQueue(unsigned cap)
{
    Queue* queue = new Queue();
    queue->cap = cap;
    queue->front = queue->size = 0;

    queue->rear = cap - 1;
    queue->arr = new int[(queue->cap * sizeof(int))];
    return queue;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item)
{
    if (queue->size == queue->cap) {
        cout << "Queue is full" << endl;
        return;
    }
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->arr[queue->rear] = item;
    queue->size++;
}

// Function to remove an item from queue.
int dequeue(Queue* queue)
{
    if (queue->size == 0) {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size--;
    return item;
}

// Function to get the front element of the queue
int front(Queue* queue)
{
    if (queue->size == 0) {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    return queue->arr[queue->front];
}

// Function to get the rear element of the queue
int rear(Queue* queue)
{
    if (queue->size == 0) {
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    return queue->arr[queue->rear];
}

int main() {
    unsigned capacity = 5;
    Queue* queue = createQueue(capacity);

    // Enqueue some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Dequeue an element
    int item = dequeue(queue);
    cout << "Dequeued item: " << item << std::endl;

    // Front and Rear elements
    cout << "Front element: " << front(queue) << std::endl;
    cout << "Rear element: " << rear(queue) << std::endl;

    return 0;
}

/*
Dequeued item: 10
Front element: 20
Rear element: 40

*/
