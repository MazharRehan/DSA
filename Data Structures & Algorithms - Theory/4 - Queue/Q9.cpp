// Implementation of queue(enqueue, dequeue).
#include <iostream>
using namespace std;

class Queue {
public:
	int front, rear, size;
	unsigned cap;
	int* arr;
};

Queue* createQueue(unsigned cap)
{
	Queue* queue = new Queue();
	queue->cap = cap;
	queue->front = queue->size = 0;

	queue->rear = cap - 1;
	queue->arr = new int[(queue->cap * sizeof(int))];
	return queue;
}

int isFull(Queue* queue)
{
	return (queue->size == queue->cap);
}

int isempty(Queue* queue) { return (queue->size == 0); }
// Function to add an item to the queue. It changes rear and size.
void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->cap;
	queue->arr[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}
// Function to remove an item from queue. It changes front and size
int dequeue(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	int item = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->cap;
	queue->size = queue->size - 1;
	return item;
}
// front(): This operation returns the element at the front end without removing it.
int front(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	return queue->arr[queue->front];
}
//4. rear(): This operation returns the element at the rear end without removing it.
int rear(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	return queue->arr[queue->rear];
}

// Driver code
int main()
{
	Queue* queue = createQueue(1000);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	cout << dequeue(queue);
	cout << " dequeued from queue\n";
	cout << "Front item is " << front(queue) << endl;
	cout << "Rear item is " << rear(queue);
	return 0;
}
/*
10 enqueued to queue
20 enqueued to queue
30 enqueued to queue
40 enqueued to queue
10 dequeued from queue
Front item is 20
Rear item is 40
*/
