//Question 1: Implementation of Queue using an array:

#include<iostream>
#include<cassert>
using namespace std;

template <class Type>
class queueType
{
public:
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void enQueue(const Type& queueElement);
	void deQueue();
//	Type* getList() const {
//        return list;
//    }
	queueType(int queueSize = 100);
	~queueType();
private:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of elements in the queue
	int queueFront; //variable to point to the first element of the queue
	int queueRear; //variable to point to the last element of the queue
	Type* list; //pointer to the array that holds the queue elements
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (count == 0);
}
template <class Type>
bool queueType<Type>::isFullQueue() const
{
	return (count == maxQueueSize);
}

template <class Type>
void queueType<Type>::enQueue(const Type& newElement)
{
	if (!isFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize; 
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
}

template <class Type>
void queueType<Type>::deQueue()
{
	if (!isEmptyQueue())
	{
		count--;
		queueFront = (queueFront + 1) % maxQueueSize; 
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
}

template <class Type>
queueType<Type>::queueType(int queueSize)
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize; //set maxQueueSize to queueSize
	queueFront = 0; //initialize queueFront
	queueRear = maxQueueSize - 1; //initialize queueRear
	count = 0;
	list = new Type[maxQueueSize]; //create the array to hold the queue elements
} //end constructor


template <class Type>
queueType<Type>::~queueType()
{
	delete[] list;
}


int main() {
    queueType<int> myQueue(5);

    // Testing isEmptyQueue
    cout << "Is the queue empty? " << (myQueue.isEmptyQueue() ? "Yes" : "No") << endl;

    // Testing isFullQueue
    cout << "Is the queue full? " << (myQueue.isFullQueue() ? "Yes" : "No") << endl;

    // Enqueue elements
    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.enQueue(4);
    myQueue.enQueue(5);

    // Testing isFullQueue after enqueueing elements
    cout << "Is the queue full? " << (myQueue.isFullQueue() ? "Yes" : "No") << endl;

    // Testing isEmptyQueue after enqueueing elements
    cout << "Is the queue empty? " << (myQueue.isEmptyQueue() ? "Yes" : "No") << endl;

    // Dequeue elements
    myQueue.deQueue();
    myQueue.deQueue();

    // Enqueue additional elements
    myQueue.enQueue(6);
    myQueue.enQueue(7);

    return 0;
}

/*
Now, let's analyze the time complexity of each operation:

a) isEmptyQueue: This function simply checks if the count variable is equal to 0,
 indicating an empty queue. It performs a constant-time operation, so the time complexity is O(1).

b) isFullQueue: This function checks if the count variable is equal to maxQueueSize,
 indicating a full queue. It also performs a constant-time operation, so the time 
 complexity is O(1).

c) enQueue: This function adds an element to the queue. It involves updating the queueRear 
pointer, incrementing the count variable, and assigning the new element to the appropriate index 
in the list array. Since all these operations take constant time, the time complexity is O(1).

d) deQueue: This function removes an element from the queue. It involves updating the queueFront 
pointer and decrementing the count variable. Similar to the enQueue operation, these operations take 
constant time, so the time complexity is O(1).
*/
