/* Task 6:
Write a class template for a MinMax class that holds two values of the same type and returns
the minimum and maximum values. */

#include <iostream>
using namespace std;

template <class T>
class MinMax
{
	T a, b;
public:
	MinMax()
	{
		cin >> a;
		cin >> b;
	}
	T compare()
	{
		return (a > b) ? a : b;
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
	MinMax<int>intObj;
	cout << "Input float values" << endl;
	MinMax<float>floatObj;
	cout << "Input character values" << endl;
	MinMax<char>charObj;

	cout << endl;
	cout << "Maximum of " << intObj.get_a() << " & " << intObj.get_b() << " is " << intObj.compare() << endl;
	cout << "Maximum of " << floatObj.get_a() << " & " << floatObj.get_b() << " is " << floatObj.compare() << endl;
	cout << "Maximum of " << charObj.get_a() << " & " << charObj.get_b() << " is " << charObj.compare() << endl;

	system("pause");
	return 0;
}