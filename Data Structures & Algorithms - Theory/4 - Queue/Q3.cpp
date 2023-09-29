// Linked Implementation of Queues
//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations on a queue as a
// linked list.
//*************************************************************
//Definition of the node

#include <iostream>
#include<cassert>
using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template <class Type>
class queueADT
{
public:
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;
	virtual Type front() const = 0;
	virtual Type back() const = 0;
	virtual void addQueue(const Type& queueElement) = 0;
	virtual void deleteQueue() = 0;
};
template <class Type>
class linkedQueueType : public queueADT<Type>
{
public:
	const linkedQueueType<Type>& operator=(const linkedQueueType<Type>&);
	//Overload the assignment operator.
	bool isEmptyQueue() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	// otherwise returns false.
	bool isFullQueue() const;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	// otherwise returns false.
	void initializeQueue();
	//Function to initialize the queue to an empty state.
	//Postcondition: queueFront = NULL; queueRear = NULL
	Type front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the first element of the
	// queue is returned.
	Type back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
// terminates; otherwise, the last element of the
// queue is returned.
	void addQueue(const Type& queueElement);
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement is
	// added to the queue.
	void deleteQueue();
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first element
	// is removed from the queue.
	linkedQueueType();
	//Default constructor
	linkedQueueType(const linkedQueueType<Type>& otherQueue);
	//Copy constructor
	~linkedQueueType();
	//Destructor
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
void linkedQueueType<Type>::initializeQueue()
{
	nodeType<Type>* temp;
	while (queueFront != NULL) //while there are elements left in the queue
	{
		temp = queueFront; //set temp to point to the current node
		queueFront = queueFront->link; //advance first to the next node
		delete temp; //deallocate memory occupied by temp
	}
	queueRear = NULL; //set rear to NULL
} //end initializeQueue
template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
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
Type linkedQueueType<Type>::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
} //end front
template <class Type>
Type linkedQueueType<Type>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
} //end back
template <class Type>
void linkedQueueType<Type>::deleteQueue()
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

// Copy constructor
template<typename Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) 
{
	if (otherQueue.front == nullptr) 
	{
		// If the other queue is empty, set front and rear to nullptr
		queueFront = nullptr;
		queueRear = nullptr;
	}
	else 
	{
		// Copy the elements from the other queue
		nodeType<Type>* current = otherQueue.queueFront;
		while (current != nullptr) 
		{
			addQueue(current->info);
			current = current->link;
		}
	}
}

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

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=(const linkedQueueType<Type>& otherQueue)
{
	if (this != &otherQueue) // Avoid self-assignment
	{
		// First, deallocate any memory that may have already been allocated for this queue
		nodeType<Type>* current = queueFront;
		while (current != nullptr)
		{
			queueFront = queueFront->link;
			delete current;
			current = queueFront;
		}
		queueRear = nullptr;

		// Now, copy over the elements from the other queue
		nodeType<Type>* otherCurrent = otherQueue.queueFront;
		while (otherCurrent != nullptr)
		{
			enqueue(otherCurrent->info);
			otherCurrent = otherCurrent->link;
		}
	}

	return *this; // Return a reference to the current object
}


//***************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class linkedQueueType
// in a program.
//***************************************************************

int main()
{
	linkedQueueType<int> queue;
	int x, y;
	queue.initializeQueue();
	x = 4;
	y = 5;
	queue.addQueue(x);
	queue.addQueue(y);
	x = queue.front();
	queue.deleteQueue();
	queue.addQueue(x + 5);
	queue.addQueue(16);
	queue.addQueue(x);
	queue.addQueue(y - 3);
	cout << "Queue Elements: ";
	while (!queue.isEmptyQueue())
	{
		cout << queue.front() << " ";
		queue.deleteQueue();
	}
	cout << endl;

	return 0;
}
/*
Sample Run :
Queue Elements : 5 9 16 4 2
*/
