// Task 2:
// Array based list

#include<iostream>
using namespace std;

template<class Type>
class MyList
{
protected:
	Type* arr;
	int maxSize;
	int currentSize;
public:
	MyList();
	~MyList();
	MyList(int);
	MyList(const MyList&);
	virtual void addElement(Type);  //Should add the element on the List
	virtual void addElementAtFirstIndex(Type); //Should add the element at the first position of the List
	virtual void addElementAtLastIndex(Type);	//Should add the element at the last position of the List
	virtual Type removeElement();	//Should remove the element from the current position of the List
	virtual Type removeElementFromEnd();	//Should remove the element from the last position of the List
	virtual void removeElementFromStart();	//Should remove the element from the first position of the List
	virtual void display();

	bool empty(); // Returns whether the MyList is empty or not
	bool  full(); // Returns whether the MyList is full or not
	int  size(); // Returns the current size of the MyList
	bool insertAt(int, Type); // Adds a value at the index passed to the function, returns true if the index is present and value is added else returns false.
	Type  last(); // Returns the last element of the MyList
	bool search(Type); // Returns true if the searched value is present in the list else returns false


};

template<class Type>
MyList<Type>::MyList() {
	maxSize = 10;
	currentSize = 7;

	arr = new Type[maxSize];

	cout << "Enter array Elements(Limit 7): ";
	for (int i = 0; i < currentSize; i++)
		cin >> arr[i];

}

template<class Type>
MyList<Type>::MyList(int maxSize)
{
	this->maxSize = maxSize;
	arr = new Type[maxSize];
	currentSize = 0;
}

template<class Type>
MyList<Type>::MyList(const MyList& obj)
{
	arr = obj.arr;
	maxSize = obj.maxSize;
	currentSize = obj.currentSize;
}

template<class Type>
MyList<Type>::~MyList() {
	delete[] arr;
	arr = NULL;
}

template<class Type>
void MyList<Type>::addElement(Type element)
{
	if (currentSize == maxSize) {
		cout << "List is full!" << endl;
		return;
	}
	arr[currentSize++] = element;
}

template<class Type>
void MyList<Type>::addElementAtFirstIndex(Type element)
{
	if (currentSize == maxSize) {
		cout << "List is full!" << endl;
		return;
	}
	for (int i = currentSize; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
	arr[0] = element;
	++currentSize;
}


template <class Type>
void MyList<Type>::addElementAtLastIndex(Type insertItem)
{
	if (currentSize >= maxSize) //the list is full
		cerr << "Cannot insert in a full list" << endl;
	else
	{
		arr[currentSize] = insertItem; //insert the item at the end
		currentSize++; //increment the length
	}
} //end insertEnd

template <class Type>
Type MyList<Type>::removeElementFromEnd()
{
	currentSize--;

	return arr[currentSize];
}

template <class Type>
void MyList<Type>::removeElementFromStart()
{
	for (int i = 0; i < currentSize - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	currentSize--;
}

template <class Type>
Type MyList<Type>::removeElement()
{
	currentSize--;

	return arr[currentSize]; // return removed element
} //end removeAt

template <class Type>
void MyList<Type>::display()
{
	cout << "List elements are: ";
	for (int i = 0; i < currentSize; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <class Type>
bool MyList<Type>::empty()
{
	return (currentSize == 0);
}
template <class Type>
bool MyList<Type>::full()
{
	return (currentSize == maxSize);
}

template <class Type>
int MyList<Type>::size()
{
	return currentSize;
}

template <class Type>
bool MyList<Type>::insertAt(int index, Type value)
{
	if (index < 0 || index >= maxSize)
	{
		cerr << "The position of the item to be inserted is out of range" << endl;
		return 0;
	}
	else if (currentSize >= maxSize) //list is full
	{
		cerr << "Cannot insert in a full list" << endl;
		return 0;
	}

	for (int i = currentSize; i > index; i--)
		arr[i] = arr[i - 1]; //move the elements down

	arr[index] = value; //insert the item at the specified position
	currentSize++; //increment the length


	return 1;
}

template <class Type>
Type MyList<Type>::last()
{
	return arr[currentSize - 1];
}

template <class Type>
bool MyList<Type>::search(Type value)
{
	for (int i = 0; i < currentSize; i++)
		if (arr[i] == value)
			return true;

	return false;
}


int main()
{
	int choice = 0;
	MyList<int>obj;
	int value = 0, index = 0;

	do
	{
		cout << "Choose the following function do you want to perform\n"
			<< "	1 - Add the element on the List"
			<< "\n	2 - Add the element at the first position of the List"
			<< "\n	3 - Add the element at the last position of the List"
			<< "\n	4 - Remove the element from the current position of the List"
			<< "\n	5 - Remove the element from the last position of the List"
			<< "\n	6 - Remove the element from the first position of the List"
			<< "\n	7 - Display the list elements"
			<< "\n	8 - Check List is empty or not"
			<< "\n	9 - Check List is full or not"
			<< "\n	10 - View current size of the List "
			<< "\n	11 - Adds a value to the List"
			<< "\n	12 - Display last element of the List"
			<< "\n	13 - Search a value in the List"
			<< "\n	14  - Exit"
			<< "\n___";

		cin >> choice;


		if (choice == 1)
		{
			cout << "Input the value so you want to add: ";
			cin >> value;
			obj.addElement(value);
		}
		else if (choice == 2)
		{
			cout << "Input the value so you want to add: ";
			cin >> value;
			obj.addElementAtFirstIndex(value);
		}
		else if (choice == 3)
		{
			cout << "Input the value so you want to add: ";
			cin >> value;
			obj.addElementAtLastIndex(value);
		}
		else if (choice == 4)
			cout << obj.removeElement() << " is removed." << endl;
		else if (choice == 5)
			cout << obj.removeElementFromEnd() << " is removed." << endl;
		else if (choice == 6)
			obj.removeElementFromStart();
		else if (choice == 7)
			obj.display();
		else if (choice == 8)
			cout << "List is " << ((obj.empty() == 1) ? "Empty." : "Not Empty.") << endl;
		else if (choice == 9)
			cout << "List is " << ((obj.full() == 1) ? "full." : "not full.") << endl;
		else if (choice == 10)
			cout << "Size of list is " << obj.size() << endl;
		else if (choice == 11)
		{
			cout << "Input the value so you want to add: ";
			cin >> value;
			cout << "Input the index where do you want to add a value: ";
			cin >> index;
			cout << "Value is" << ((obj.insertAt(index, value) == 1) ? "inserted." : "not inserted.") << endl;
		}
		else if (choice == 12)
			cout << obj.last() << " is the last element in the List." << endl;
		else if (choice == 13)
		{
			cout << "Input the value so you want to search: ";
			cin >> value;
			cout << value<<" is " << ((obj.search(value)==1)?"present":"not present")<<" in the list." << endl;
		}
		else if (choice == 14);
		else
			cout << "Please choose the correct option" << endl;

	} while (choice != 14);


	return 0;
}
