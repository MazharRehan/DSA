/* Task5: 
	Write a class template for a Comparator class that compares two values of the same type and
returns true if they are equal and false otherwise. */

#include <iostream>
using namespace std;

template <class T>
class Comparator
{
	T a, b;
public:
	Comparator()
	{
		cin >> a;
		cin >> b;
	}
	bool compare()
	{
		return (a == b )? true : false;
	}
	T get_a()
	{
		return a;
	}
	T get_b()
	{
		return b;
	}

};

int main()
{
	cout << "Input integer values" << endl;
	Comparator<int>intObj;
	cout << "Input float values" << endl;
	Comparator<float>floatObj;
	cout << "Input character values" << endl;
	Comparator<char>charObj;

	cout << "Output:" << endl;
	cout << intObj.get_a() << " & " << intObj.get_b() << " are " << (intObj.compare() == 1 ? "Equal" : " not Equal") << endl;
	cout << floatObj.get_a() << " & " << floatObj.get_b() << " are " << (floatObj.compare() == 1 ? "Equal" : " not Equal") << endl;
	cout << charObj.get_a() << " & " << charObj.get_b() << " are " << (charObj.compare() == 1 ? "Equal" : " not Equal") << endl;

	system("pause");
	return 0;
}