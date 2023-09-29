//*************************************************************
// Author: D.S. Malik
//Array based Implementation of Queues
// 
// This class specifies the basic operations on a queue.
//*************************************************************
// Abstract Class

#include<iostream>
#include<cassert>
using namespace std;

template <class Type>
class queueADT
{
public:
	virtual bool isEmptyQueue() const = 0;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	// otherwise returns false.
	virtual bool isFullQueue() const = 0;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	// otherwise returns false.
	virtual void initializeQueue() = 0;
	//Function to initialize the queue to an empty state.
	//Postcondition: The queue is empty.
	virtual Type front() const = 0;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the first element of the queue
	// is returned.
	virtual Type back() const = 0;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the last element of the queue
	// is returned.
	virtual void addQueue(const Type& queueElement) = 0;
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement is
	// added to the queue.
	virtual void deleteQueue() = 0;
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first element
	// is removed from the queue.
};
// Implementation of Queues as Arrays
// This class specifies the basic operation on a queue as an
// array.
//*************************************************************
template <class Type>
class queueType : public queueADT<Type>
{
public:
	const queueType<Type>& operator=(const queueType<Type>&);
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
	//Postcondition: The queue is empty.
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
	// terminates; otherwise, the last element of the queue
	// is returned.
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
	int queueCount() const;

	queueType(int queueSize = 100);
	//Constructor
	queueType(const queueType<Type>& otherQueue);
	//Copy constructor
	~queueType();
	//Destructor
private:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of
	//elements in the queue
	int queueFront; //variable to point to the first
	//element of the queue
	int queueRear; //variable to point to the last
	//element of the queue
	Type* list; //pointer to the array that holds
	//the queue elements
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (count == 0);
} //end isEmptyQueue
template <class Type>
bool queueType<Type>::isFullQueue() const
{
	return (count == maxQueueSize);
} //end isFullQueue

template <class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
} //end initializeQueue

template <class Type>
Type queueType<Type>::front() const
{
	assert(!isEmptyQueue());
	return list[queueFront];
} //end front

template <class Type>
Type queueType<Type>::back() const
{
	assert(!isEmptyQueue());
	return list[queueRear];
} //end back

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
	if (!isFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize; //use the
		//mod operator to advance queueRear
		//because the array is circular
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
} //end addQueue

template <class Type>
void queueType<Type>::deleteQueue()
{
	if (!isEmptyQueue())
	{
		count--;
		queueFront = (queueFront + 1) % maxQueueSize; //use the
		//mod operator to advance queueFront
		//because the array is circular
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
} //end deleteQueue

template <class Type>
int queueType<Type>::queueCount() const 
{
	return queueFront == -1 ? 0 : (queueRear - queueFront + 1);
}


template <class Type>
queueType<Type>::queueType(int queueSize)
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize; //set maxQueueSize to
	//queueSize
	queueFront = 0; //initialize queueFront
	queueRear = maxQueueSize - 1; //initialize queueRear
	count = 0;
	list = new Type[maxQueueSize]; //create the array to
	//hold the queue elements
} //end constructor
template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
    maxQueueSize = otherQueue.maxQueueSize;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;
    count = otherQueue.count;
    list = new Type[maxQueueSize];

    // Copy the elements of otherQueue's list array to this list array
    for (int i = queueFront; i != queueRear; i = (i + 1) % maxQueueSize)
    {
        list[i] = otherQueue.list[i];
    }
    // Copy the last element of otherQueue's list array
    list[queueRear] = otherQueue.list[queueRear];
}

template <class Type>
queueType<Type>::~queueType()
{
	delete[] list;
}

int main()
{
	queueType<string> queue(10);
	// Initialize the queue

	int option = 0;
	do {
		cout << "\n\nWelcome to the Fast Food Restaurant\n\n";
		cout << "Please choose an option from the following menu:\n";
		cout << "1. Add customer to the queue\n";
		cout << "2. Serve next customer\n";
		cout << "3. Display number of customers waiting\n";
		cout << "4. Quit\n\n";
		cout << "Enter your choice (1-4): ";
		cin >> option;

		string name;

		switch(option)
		{
		case 1:
			// Add customer to the queue
			cout << "Enter customer name: ";
			cin >> name;
			queue.addQueue(name);
			cout << "Added " << name << " to the queue.\n";
			break;

		case 2:
			// Serve next customer
			if (!queue.isEmptyQueue()) {
				string nextCustomer = queue.front();
				queue.deleteQueue();
				cout << "Serving " << nextCustomer << ".\n";
			}
			else {
				cout << "Queue is empty.\n";
			}
			break;

		case 3:
			// Display number of customers waiting
			cout << "There are " << queue.queueCount() << " customers waiting.\n";
			break;

		case 4:
			// Quit
			cout << "Exiting program.\n";
			break;

		default:
			cout << "Invalid option. Please try again.\n";
			break;
		}
	} while (option != 4);

	return 0;
}
/*
Output:

Welcome to the Fast Food Restaurant

Please choose an option from the following menu:
1. Add customer to the queue
2. Serve next customer
3. Display number of customers waiting
4. Quit

Enter your choice (1-4): 1
Enter customer name: ali
Added ali to the queue.


Welcome to the Fast Food Restaurant

Please choose an option from the following menu:
1. Add customer to the queue
2. Serve next customer
3. Display number of customers waiting
4. Quit

Enter your choice (1-4): 2
Serving ali.


Welcome to the Fast Food Restaurant

Please choose an option from the following menu:
1. Add customer to the queue
2. Serve next customer
3. Display number of customers waiting
4. Quit

Enter your choice (1-4): 3
There are 0 customers waiting.


Welcome to the Fast Food Restaurant

Please choose an option from the following menu:
1. Add customer to the queue
2. Serve next customer
3. Display number of customers waiting
4. Quit

Enter your choice (1-4): 1
Enter customer name: Ahmand
Added Ahmand to the queue.


Welcome to the Fast Food Restaurant

Please choose an option from the following menu:
1. Add customer to the queue
2. Serve next customer
3. Display number of customers waiting
4. Quit

Enter your choice (1-4): 3
There are 1 customers waiting.


Welcome to the Fast Food Restaurant

Please choose an option from the following menu:
1. Add customer to the queue
2. Serve next customer
3. Display number of customers waiting
4. Quit

Enter your choice (1-4): 4
Exiting program.

*/