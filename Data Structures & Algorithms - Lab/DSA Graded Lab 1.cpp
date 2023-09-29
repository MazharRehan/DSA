// array based list

#include<iostream>
using namespace std;

template <class Type>
class List
{
	Type * arr;
	int maxSize;
	int currentSize;
public:
	List()
	{
		maxSize = 10;
		currentSize = 7;
		arr = new Type[10];
		// initialize array
		for (int i = 0; i < currentSize; i++)
			arr[i] = 100 - i*5;
	}
	~List()
	{
		delete[]arr;
		arr = NULL;
	}
	void addElement()  // add element at 1st index
	{
		Type element;
		cout << "Enter the element do you want to add:";
		cin >> element;

		for (int i = currentSize; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = element;

		currentSize++;
	}
	void removeElement()  // remove element from last index
	{
		currentSize--;
		cout << arr[currentSize] << " has been removed." << endl;

	}
	Type searchMaxElement()
	{
		Type max = arr[0];

		for (int i = 1; i < currentSize; i++)
		{
			if (max < arr[i])
				max = arr[i];
		}
		return max;
	}

	Type searchMinElement()
	{
		Type min = arr[0];

		for (int i = 1; i < currentSize; i++)
		{
			if (min > arr[i])
				min = arr[i];
		}
		return min;
	}

	void regrow(Type element)
	{
		Type *newArr = new Type[maxSize + 1];

		for (int i = 0; i < currentSize; i++)
			newArr[i] = arr[i];

		newArr[currentSize] = element;

		delete[]arr;
		arr = newArr;

		currentSize++;
	}
	void display()
	{
		for (int i = 0; i < currentSize; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};


int main()
{
	List<int>obj;

	int input = 0;

	do
	{
		cout << "Input the function do you want to perform.\n"
			<< "1-addElement\n"
			<< "2-removeElement\n"
			<< "3-searchMaxElement\n"
			<< "4-searchMinElement\n"
			<< "5-display\n"
			<< "6-Regrow Array\n"
			<< "7-Exit\n" << endl;
		cin >> input;

		if (input == 1)
			obj.addElement();
		else if (input == 2)
			obj.removeElement();
		else if (input == 3)
			cout << "Maximum number is " << obj.searchMaxElement() << endl;
		else if (input == 4)
			cout << "Minimum number is " << obj.searchMinElement() << endl;
		else if (input == 5)
			obj.display();
		else if (input == 6)
			obj.regrow(100);


	} while (input != 7);

	return 0;
}
