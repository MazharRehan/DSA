// Linked Implementation of Queues


#include <iostream>
using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template <class Type>
class linkedQueueType
{
public:
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void enQueue(const Type& queueElement);
	void deQueue();
	linkedQueueType();
	~linkedQueueType();
private:
	nodeType<Type>* queueFront; //pointer to the front of the queue
	nodeType<Type>* queueRear; //pointer to the rear of the queue
};

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return(queueFront == NULL);
} //end
template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
} //end isFullQueue
template <class Type>
void linkedQueueType<Type>::enQueue(const Type& newElement)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>; //create the node
	newNode->info = newElement; //store the info
	newNode->link = NULL; //initialize the link field to NULL
	if (queueFront == NULL) //if initially the queue is empty
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else //add newNode at the end
	{
		queueRear->link = newNode;
		queueRear = newNode;
	}
}//end addQueue

template <class Type>
void linkedQueueType<Type>::deQueue()
{
	nodeType<Type>* temp;
	if (!isEmptyQueue())
	{
		temp = queueFront; //make temp point to the first node
		queueFront = queueFront->link; //advance queueFront
		delete temp; //delete the first node
		if (queueFront == NULL) //if after deletion the queue is empty
			queueRear = NULL; //set queueRear to NULL
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue
template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
	queueFront = NULL; //set front to null
	queueRear = NULL; //set rear to null
} //end default constructor


template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
	nodeType<Type>* temp;
	while (queueFront != nullptr) 
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
	}
	queueRear = nullptr;
}


int main() {
    linkedQueueType<int> myQueue;

    // Testing isEmptyQueue
    cout << "Is the queue empty? " << (myQueue.isEmptyQueue() ? "Yes" : "No") << endl;

    // Enqueue elements
    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.enQueue(4);
    myQueue.enQueue(5);

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
Time complexity analysis:
isEmptyQueue:
    This function has a constant time complexity of O(1) since it only involves 
	checking the values of front and rear.
isFullQueue:
    This function also has a constant time complexity of O(1). In the linked list implementation, there is no fixed size
    limitation, so the queue is never considered full. Therefore, the function can return false directly without any additional
    computations.
enQueue: 
    This function has a constant time complexity of O(1) since it simply adds a new node at the rear end of the linked list.
deQueue: 
    This function also has a constant time complexity of O(1) since it only involves updating the front pointer to the next 
    node and deleting the previous front node.

*/
