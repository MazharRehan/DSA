//In this example, we write a C++ program that reads a data file consisting of each
//student’s GPA followed by the student’s name.The program then prints the highest
//GPA and the names of all the students who received that GPA.The program scans the
//input file only once.Moreover, we assume that there are a maximum of 100 students
//in the class.

//*************************************************************
// Author: D.S. Malik
//
// This program reads a data file consisting of students' GPAs
// followed by their names. The program then prints the highest
// GPA and the names of the students with the highest GPA.
//*************************************************************
// array based implementation of stack

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;

// This class specifies the basic operations on a stack.
// Abstract Class
template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};

// This class specifies the basic operation on a stack as an array.
//Concrete Class -> Implementation class of the above abstract class
template <class Type>
class stackType : public stackADT<Type>
{
private:
	int maxStackSize; 
	int stackTop;
	Type* list; 

	void copyStack(const stackType<Type>& otherStack);

public:
	const stackType<Type>& operator=(const stackType<Type>&);

	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type& newItem);
	Type top() const;
	void pop();

	stackType();
	stackType(int stackSize = 100);
	stackType(const stackType<Type>& otherStack);
	~stackType();
};

template <class Type>
void stackType<Type>::initializeStack()
{
	stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
	return(stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	if (!isFullStack())
	{
		list[stackTop] = newItem; //add newItem at the top
		stackTop++; 
	}
	else
		cout << "Cannot add to a full stack." << endl;
}

template <class Type>
Type stackType<Type>::top() const
{
	assert(stackTop != 0); 
	return list[stackTop - 1]; 
}

template <class Type>
void stackType<Type>::pop()
{
	if (!isEmptyStack())
		stackTop--; 
	else
		cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;

	list = new Type[maxStackSize];

	
	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j]; //Warning: Buffer overrun while writing to 'list'

}

template <class Type>
stackType<Type>::stackType()
{
	cout << "Creating an array of size 100." << endl;
	maxStackSize = 100;

	stackTop = 0; 
	list = new Type[maxStackSize]; 
}

template <class Type>
stackType<Type>::stackType(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize; 
	stackTop = 0; 
	list = new Type[maxStackSize]; 
}

template <class Type>
stackType<Type>::~stackType() 
{
	delete[] list;
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
	list = NULL;
	copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack)
{
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);
	return *this;
}

void testCopyConstructor(stackType<int> otherStack);

int main()
{
	//Step 1
	double GPA;
	double highestGPA;
	string name;
	stackType<string> stack(100);
	ifstream infile;
	infile.open("HighestGPAData.txt"); //Step 2
	if (!infile) //Step 3
	{
		cout << "The input file does not exist. Program terminates!" << endl;
		return 1;
	}
	cout << fixed << showpoint; //Step 4
	cout << setprecision(2); //Step 4
	infile >> GPA >> name; //Step 5
	highestGPA = GPA; //Step 6
	while (infile) //Step 7
	{
		if (GPA > highestGPA) //Step 7.1
		{
			stack.initializeStack(); //Step 7.1.1
				if (!stack.isFullStack()) //Step 7.1.2
					stack.push(name);
			highestGPA = GPA; //Step 7.1.3
		}
		else if (GPA == highestGPA) //Step 7.2
			if (!stack.isFullStack())
				stack.push(name);
			else
			{
				cout << "Stack overflows. "
					<< "Program terminates!" << endl;
				return 1; //exit program
			}
		infile >> GPA >> name; //Step 7.3
	}
	cout << "Highest GPA = " << highestGPA << endl;//Step 8
	cout << "The students holding the "
		<< "highest GPA are:" << endl;
	while (!stack.isEmptyStack()) //Step 9
	{
		cout << stack.top() << endl;
		stack.pop();
	}
	cout << endl;
	return 0;
}
void testCopyConstructor(stackType<int> otherStack)
{
	if (!otherStack.isEmptyStack())
		cout << "otherStack is not empty." << endl
		<< "The top element of otherStack: "
		<< otherStack.top() << endl;
}

/*
Sample Run:
Input File (HighestGPAData.txt)
3.4 Randy
3.2 Kathy
2.5 Colt
3.4 Tom
3.8 Ron
3.8 Mickey
3.6 Peter
3.5 Donald
3.8 Cindy
3.7 Dome
3.9 Andy
3.8 Fox
3.9 Minnie
2.7 Gilda
3.9 Vinay
3.4 Danny

Output:
Highest GPA = 3.90
The students holding the highest GPA are:
Vinay
Minnie
Andy

Note that the names of the students with the highest GPA are output in the reverse
order, relative to the order they appear in the input because the top element of the
stack is the last element added to the stack.
*/
