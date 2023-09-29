//************************************************************
// Author: D.S. Malik
// no driver code

#include<iostream>
#include<string>
#include<cassert>
using namespace std;

class customerType
{
public:
	customerType(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);
	customerType(const customerType& other); // copy constructor
	~customerType(); //Destructor
	void setCustomerInfo(int cN = 0, int inTime = 0, int wTime = 0, int tTime = 0);
	int getWaitingTime() const;
	void setWaitingTime(int time);
	void incrementWaitingTime();
	int getArrivalTime() const;
	int getTransactionTime() const;
	int getCustomerNumber() const;

private:
	int customerNumber;
	int arrivalTime;
	int waitingTime;
	int transactionTime;
};
customerType::customerType(int cN, int arrvTime,
	int wTime, int tTime)
{
	setCustomerInfo(cN, arrvTime, wTime, tTime);
}
customerType::customerType(const customerType& other)
{
	customerNumber = other.customerNumber;
	arrivalTime = other.arrivalTime;
	waitingTime = other.waitingTime;
	transactionTime = other.transactionTime;
}
void customerType::setCustomerInfo(int cN, int arrvTime, int wTime, int tTime)
{
	customerNumber = cN;
	arrivalTime = arrvTime;
	waitingTime = wTime;
	transactionTime = tTime;
}
int customerType::getWaitingTime() const
{
	return waitingTime;
}
void customerType::setWaitingTime(int time)
{
	waitingTime = time;
}
void customerType::incrementWaitingTime()
{
	waitingTime++;
}
int customerType::getArrivalTime() const
{
	return arrivalTime;
}
int customerType::getTransactionTime() const
{
	return transactionTime;
}
int customerType::getCustomerNumber() const
{
	return customerNumber;
}
customerType::~customerType()
{
	// Destructor code goes here, if needed
}


// class serverType
// This class specifies the members to implement a server.
//************************************************************


class serverType
{
public:
	serverType();
	//Default constructor
	//Sets the values of the instance variables to their default
	//values.
	//Postcondition: currentCustomer is initialized by its
	// default constructor; status = "free"; and the
	// transaction time is initialized to 0.
	bool isFree() const;
	//Function to determine if the server is free.
	//Postcondition: Returns true if the server is free,
	// otherwise returns false.
	void setBusy();
	//Function to set the status of the server to busy.
	//Postcondition: status = "busy";
	void setFree();
	//Function to set the status of the server to "free."
	//Postcondition: status = "free";
	void setTransactionTime(int t);
	//Function to set the transaction time according to the
	//parameter t.
	//Postcondition: transactionTime = t;
	void setTransactionTime();
	//Function to set the transaction time according to
	//the transaction time of the current customer.
	//Postcondition:
	// transactionTime = currentCustomer.transactionTime;
	int getRemainingTransactionTime() const;
	//Function to return the remaining transaction time.
	//Postcondition: The value of transactionTime is returned.
	void decreaseTransactionTime();
	//Function to decrease the transactionTime by 1 unit.
	//Postcondition: transactionTime--;
	void setCurrentCustomer(customerType cCustomer);
	//Function to set the info of the current customer
	//according to the parameter cCustomer.
	//Postcondition: currentCustomer = cCustomer;
	int getCurrentCustomerNumber() const;
	//Function to return the customer number of the current
	//customer.
	//Postcondition: The value of customerNumber of the
	// current customer is returned.
	int getCurrentCustomerArrivalTime() const;
	//Function to return the arrival time of the current
	//customer.
	//Postcondition: The value of arrivalTime of the current
	// customer is returned.
	int getCurrentCustomerWaitingTime() const;
	//Function to return the current waiting time of the
	//current customer.
	//Postcondition: The value of transactionTime is returned.
	int getCurrentCustomerTransactionTime() const;
	//Function to return the transaction time of the
	//current customer.
	//Postcondition: The value of transactionTime of the
	// current customer is returned.
private:
	customerType currentCustomer;
	string status;
	int transactionTime;
};
serverType::serverType()
{
	status = "free";
	transactionTime = 0;
}
bool serverType::isFree() const
{
	return (status == "free");
}
void serverType::setBusy()
{
	status = "busy";
}
void serverType::setFree()
{
	status = "free";
}
void serverType::setTransactionTime(int t)
{
	transactionTime = t;
}
void serverType::setTransactionTime()
{
	int time;
	time = currentCustomer.getTransactionTime();
	transactionTime = time;
}
void serverType::decreaseTransactionTime()
{
	transactionTime--;
}
void serverType::setCurrentCustomer(customerType cCustomer)
{
	currentCustomer = cCustomer;
}
int serverType::getCurrentCustomerNumber() const
{
	return currentCustomer.getCustomerNumber();
}
int serverType::getCurrentCustomerArrivalTime() const
{
	return currentCustomer.getArrivalTime();
}
int serverType::getCurrentCustomerWaitingTime() const
{
	return currentCustomer.getWaitingTime();
}
int serverType::getCurrentCustomerTransactionTime() const
{
	return currentCustomer.getTransactionTime();
}
int serverType::getRemainingTransactionTime() const
{
	return transactionTime;
}

//Server List
// class serverListType
// This class specifies the members to implement a list of
// servers.
//************************************************************
class serverListType
{
public:
	serverListType(int num = 1);
	//Constructor to initialize a list of servers
	//Postcondition: numOfServers = num
	// A list of servers, specified by num, is created and
	// each server is initialized to "free".
	~serverListType();
	//Destructor
	//Postcondition: The list of servers is destroyed.
	int getFreeServerID() const;
	//Function to search the list of servers.
	//Postcondition: If a free server is found, returns its ID;
	// otherwise, returns -1.
	int getNumberOfBusyServers() const;
	//Function to return the number of busy servers.
	//Postcondition: The number of busy servers is returned.
	void setServerBusy(int serverID, customerType cCustomer, int tTime);
	//Function to set a server busy.
	//Postcondition: The server specified by serverID is set to
// "busy", to serve the customer specified by cCustomer,
// and the transaction time is set according to the
// parameter tTime.
	void setServerBusy(int serverID, customerType cCustomer);
	//Function to set a server busy.
	//Postcondition: The server specified by serverID is set to
	// "busy", to serve the customer specified by cCustomer.
	void updateServers(ostream& outFile);
	//Function to update the status of a server.
	//Postcondition: The transaction time of each busy server
	// is decremented by one unit. If the transaction time of
	// a busy server is reduced to zero, the server is set to
	// "free". Moreover, if the actual parameter corresponding
	// to outFile is cout, a message indicating which customer
	// has been served is printed on the screen, together with the
	// customer's departing time. Otherwise, the output is sent
	// to a file specified by the user.
private:
	int numOfServers;
	serverType* servers;
};
serverListType::serverListType(int num)
{
	numOfServers = num;
	servers = new serverType[num];
}
serverListType::~serverListType()
{
	delete[] servers;
}
int serverListType::getFreeServerID() const
{
	int serverID = -1;
	for (int i = 0; i < numOfServers; i++)
		if (servers[i].isFree())
		{
			serverID = i;
			break;
		}
	return serverID;
}
int serverListType::getNumberOfBusyServers() const
{
	int busyServers = 0;
	for (int i = 0; i < numOfServers; i++)
		if (!servers[i].isFree())
			busyServers++;
	return busyServers;
}
void serverListType::setServerBusy(int serverID, customerType cCustomer, int tTime)
{
	servers[serverID].setBusy();
	servers[serverID].setTransactionTime(tTime);
	servers[serverID].setCurrentCustomer(cCustomer);
}
void serverListType::setServerBusy(int serverID, customerType cCustomer)
{
	int time = cCustomer.getTransactionTime();
	servers[serverID].setBusy();
	servers[serverID].setTransactionTime(time);
	servers[serverID].setCurrentCustomer(cCustomer);
}
void serverListType::updateServers(ostream& outF)
{
	for (int i = 0; i < numOfServers; i++)
		if (!servers[i].isFree())
		{
			servers[i].decreaseTransactionTime();
			if (servers[i].getRemainingTransactionTime() == 0)
			{
				outF << "From server number " << (i + 1)
					<< " customer number "
					<< servers[i].getCurrentCustomerNumber()
					<< "\n departed at clock unit "
					<< servers[i].getCurrentCustomerArrivalTime()
					+ servers[i].getCurrentCustomerWaitingTime()
					+ servers[i].getCurrentCustomerTransactionTime()
					<< endl;
				servers[i].setFree();
			}
		}
}

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
template <class Type>
class queueType : public queueADT<Type>
{
public:
	const queueType<Type>& operator=(const queueType<Type>&);
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue(const Type& queueElement);
	void deleteQueue();
	queueType(int queueSize = 100);
	queueType(const queueType<Type>& otherQueue);
	~queueType();
private:
	int maxQueueSize; 
	int count; 
	int queueFront;
	int queueRear; 
	Type* list;
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

// Waiting Customers Queue

// class waitingCustomerQueueType
// This class extends the class queueType to implement a list
// of waiting customers.
//************************************************************
class waitingCustomerQueueType : public queueType<customerType>
{
public:
	waitingCustomerQueueType(int size = 100);
	//Constructor
	//Postcondition: The queue is initialized according to the
	// parameter size. The value of size is passed to the
	// constructor of queueType.
	void updateWaitingQueue();
	//Function to increment the waiting time of each
	//customer in the queue by one time unit.
};
/*
Notice that the class waitingCustomerQueueType is derived from the class
queueType, which implements the queue in an array. You can also derive it from the
class linkedQueueType, which implements the queue in a linked list. We leave
the details as an exercise for you.
*/
waitingCustomerQueueType::waitingCustomerQueueType(int size) :queueType<customerType>(size)
{

}

void waitingCustomerQueueType::updateWaitingQueue()
{
	customerType cust;
	cust.setWaitingTime(-1);
	int wTime = 0;
	addQueue(cust);
	while (wTime != -1)
	{
		cust = front();
		deleteQueue();
		wTime = cust.getWaitingTime();
		if (wTime == -1)
			break;
		cust.incrementWaitingTime();
		addQueue(cust);
	}
}

void setSimulationParameters(int& sTime, int& numOfServers, int& transTime, int& tBetweenCArrival)
{
	cout << "Enter the simulation time: ";
	cin >> sTime;
	cout << endl;
	cout << "Enter the number of servers: ";
	cin >> numOfServers;
	cout << endl;
	cout << "Enter the transaction time: ";
	cin >> transTime;
	cout << endl;
	cout << "Enter the time between customers arrival: ";
	cin >> tBetweenCArrival;
	cout << endl;
}
int main()
{
	return 0;
}

/*
Sample Run:
Customer number 1 arrived at time unit 4
Customer number 2 arrived at time unit 8
From server number 1 customer number 1
departed at clock unit 9
Customer number 3 arrived at time unit 9
Customer number 4 arrived at time unit 12
From server number 1 customer number 2
departed at clock unit 14
From server number 1 customer number 3
departed at clock unit 19
Customer number 5 arrived at time unit 21
From server number 1 customer number 4
departed at clock unit 24
From server number 1 customer number 5
departed at clock unit 29
Customer number 6 arrived at time unit 37
Customer number 7 arrived at time unit 38
Customer number 8 arrived at time unit 41
From server number 1 customer number 6
departed at clock unit 42
Customer number 9 arrived at time unit 43
Customer number 10 arrived at time unit 44
From server number 1 customer number 7
departed at clock unit 47
Customer number 11 arrived at time unit 49
Customer number 12 arrived at time unit 51
From server number 1 customer number 8
departed at clock unit 52
Customer number 13 arrived at time unit 52
Customer number 14 arrived at time unit 53
Customer number 15 arrived at time unit 54
From server number 1 customer number 9
departed at clock unit 57
Customer number 16 arrived at time unit 59
From server number 1 customer number 10
departed at clock unit 62
Customer number 17 arrived at time unit 66
From server number 1 customer number 11
departed at clock unit 67
Customer number 18 arrived at time unit 71
From server number 1 customer number 12
departed at clock unit 72
From server number 1 customer number 13
departed at clock unit 77
Customer number 19 arrived at time unit 78
From server number 1 customer number 14
departed at clock unit 82
From server number 1 customer number 15
departed at clock unit 87
Customer number 20 arrived at time unit 90
From server number 1 customer number 16
departed at clock unit 92
Customer number 21 arrived at time unit 92
From server number 1 customer number 17
departed at clock unit 97
The simulation ran for 100 time units
Number of servers : 1
Average transaction time : 5
Average arrival time difference between customers : 4
Total waiting time : 269
Number of customers that completed a transaction : 17
Number of customers left in the servers : 1
The number of customers left in queue : 3
Average waiting time : 12.81
* *************END SIMULATION * ************
*/