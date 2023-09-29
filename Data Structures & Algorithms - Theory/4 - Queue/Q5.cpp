/*
Customer
Every customer has a customer number, arrival time, waiting time, transaction time, and
departure time. If we know the arrival time, waiting time, and transaction time, we can
determine the departure time by adding these three times. Let us call the class to implement the
customer object customerType. It follows that the class customerType has four member
variables: the customerNumber, arrivalTime, waitingTime, and transactionTime, each of type int.The basic operations that must be performed on an object of type
customerType are as follows : Set the customer’s number, arrival time, and waiting time;
increment the waiting time by one clock unit; return the waiting time; return the arrival time;
return the transaction time; and return the customer number.The following class,
customerType, implements the customer as an ADT :
*/

//************************************************************
// Author: D.S. Malik
//
// class customerType
// This class specifies the members to implement a customer.
//************************************************************
#include<iostream>
using namespace std;

class customerType
{
public:
	customerType(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);
	//Constructor to initialize the instance variables
	//according to the parameters
	//If no value is specified in the object declaration,
	//the default values are assigned.
	//Postcondition: customerNumber = cN; arrivalTime = arrvTime;
	// waitingTime = wTime; transactionTime = tTime
	customerType(const customerType& other); // copy constructor
	~customerType(); //Destructor
	void setCustomerInfo(int cN = 0, int inTime = 0, int wTime = 0, int tTime = 0);
	//Function to initialize the instance variables.
	//Instance variables are set according to the parameters.
	//Postcondition: customerNumber = cN; arrivalTime = arrvTime;
	// waitingTime = wTime; transactionTime = tTime;
	int getWaitingTime() const;
	//Function to return the waiting time of a customer.
	//Postcondition: The value of waitingTime is returned.
	void setWaitingTime(int time);
	//Function to set the waiting time of a customer.
	//Postcondition: waitingTime = time;
	void incrementWaitingTime();
	//Function to increment the waiting time by one time unit.
	//Postcondition: waitingTime++;
	int getArrivalTime() const;
	//Function to return the arrival time of a customer.
	//Postcondition: The value of arrivalTime is returned.
	int getTransactionTime() const;
	//Function to return the transaction time of a customer.
	//Postcondition: The value of transactionTime is returned.
	int getCustomerNumber() const;
	//Function to return the customer number.
	//Postcondition: The value of customerNumber is returned.
	
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

void customerType::setCustomerInfo(int cN, int arrvTime,
	int wTime, int tTime)
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
	// The destructor doesn't need to do anything specific in this case,
	// since the customerType class doesn't dynamically allocate any memory.
}

int main()
{
	// create a customer object with default values
	customerType myCustomer;
	// set the customer's info
	myCustomer.setCustomerInfo(1, 5, 2, 3);

	// output the customer's info
	cout << "Customer Number: " << myCustomer.getCustomerNumber() << endl;
	cout << "Arrival Time: " << myCustomer.getArrivalTime() << endl;
	cout << "Waiting Time: " << myCustomer.getWaitingTime() << endl;
	cout << "Transaction Time: " << myCustomer.getTransactionTime() << endl;

	// increment the customer's waiting time
	myCustomer.incrementWaitingTime();

	// output the updated waiting time
	cout << "Updated Waiting Time: " << myCustomer.getWaitingTime() << endl;

	return 0;
}
/*
Customer Number: 1
Arrival Time: 5
Waiting Time: 2
Transaction Time: 3
Updated Waiting Time: 3
*/