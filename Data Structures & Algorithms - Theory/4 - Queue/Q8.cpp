//Linked List Representation of Queue :
//Enqueue: Adds an item from the back of the queue.
//Dequeue: Removes an item from the front of the queue. 

#include <iostream>
#include <cstdlib>

using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode* front, * rear;
    Queue() { front = rear = NULL; }
};

void enqueue(Queue* q, int value) {
    QNode* node = new QNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}

int dequeue(Queue* q) {
    if (q->front == NULL)
        return INT_MIN;
    QNode* node = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    int value = node->data;
    delete node;
    return value;
}

int front(Queue* q) {
    if (q->front == NULL)
        return INT_MIN;
    return q->front->data;
}

int rear(Queue* q) {
    if (q->rear == NULL)
        return INT_MIN;
    return q->rear->data;
}

int main() {
    Queue* q = new Queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    cout << dequeue(q) << " dequeued from queue\n";
    cout << "Front item is " << front(q) << endl;
    cout << "Rear item is " << rear(q) << endl;

    return 0;
}
/*
10 dequeued from queue
Front item is 20
Rear item is 40
*/
