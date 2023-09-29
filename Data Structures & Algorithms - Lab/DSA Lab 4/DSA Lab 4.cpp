#include<iostream>
using namespace std;

template<class Type>
class List
{
protected:
	Type* arr;
	int maxSize;
	int currentSize;
public:
	List();
	~List();
	List(int);
	List(const List&);
	virtual void addElement(Type);  //Should add the element on the List
	virtual void addElementAtFirstIndex(Type); //Should add the element at the first position of the List
	virtual void addElementAtLastIndex(Type);	//Should add the element at the last position of the List
	virtual Type removeElement();	//Should remove the element from the current position of the List
	virtual Type removeElementFromEnd();	//Should remove the element from the last position of the List
	virtual void removeElementFromStart();	//Should remove the element from the first position of the List

};

template<class Type>
List<Type>::List() {
	maxSize = 10;
	currentSize = 7;

	arr = new Type[maxsize];

	cout << "Enter array Elements: ";
	for (int i = 0; i < currentSize; i++)
		cin >> arr[i];

}

template<class Type>
List<Type>::List(int maxSize)
{
	this->maxSize = maxSize;
	arr = new Type[maxSize];
	currentSize = 0;
}

template<class Type>
List<Type>::List(const List& obj)
{
	arr = obj.arr;
	maxSize = obj.maxSize;
	currentSize = obj.currentSize;
}

template<class Type>
List<Type>::~List() {
	delete[] arr;
	arr = NULL;
}

template<class Type>
void List<Type>::addElement(Type element)
{
	if (currentSize == maxSize) {
		cout << "List is full!" << endl;
		return;
	}
	arr[currentSize++] = element;
}

template<class Type>
void List<Type>::addElementAtFirstIndex(Type element) 
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
void List<Type>::addElementAtLastIndex(Type insertItem)
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
Type List<Type>::removeElementFromEnd()
{
	currentSize--;

	return arr;
}

template <class Type>
void List<Type>::removeElementFromStart()
{
	for (int i = 0; i < currentSize - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	currentSize--;
}

template <class Type>
Type List<Type>::removeElement()
{
	currentSize--;

	return arr;
} //end removeAt


int main()
{
	int choice = 0;
	List<int>obj;

	do
	{

		cout << "Choose the following function do you want to perform\n"
			<< "	1 - Add the element on the List"
			<< "\n	2 - Add the element at the first position of the List"
			<< "\n	3 - Add the element at the last position of the List"
			<< "\n	4 - Remove the element from the current position of the List"
			<< "\n	5 - Remove the element from the last position of the List"
			<< "\n	6 - Remove the element from the first position of the List"
			<< "\n 7  - Exit" << endl;

		cin >> choice;


		if (choice == 1)
			obj.addElement(5);
		elseif(choice == 2)
			addElementAtFirstIndex(10);
		elseif(choice == 3)
			addElementAtLastIndex(15);
		elseif(choice == 4)
			removeElement();
		elseif(choice == 5)
			removeElementFromEnd();
		elseif(choice == 6)
			removeElementFromStart();
		elseif(choice == 7);
		else
			cout << "Please choose the correct option" << endl;

	} while (choice != 7);


	return 0;
}