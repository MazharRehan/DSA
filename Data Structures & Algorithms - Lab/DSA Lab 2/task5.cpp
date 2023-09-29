// task 5:

#include<iostream>
#include<string>
using namespace std;

template <typename T>
class Calculator
{
	T x, y;
	int action;
public:
	Calculator()
	{
		cout << "Input the two numbers: ";
		cin >> x >> y;

		cout << "\n\n<''>\n\tPress 1 for Addition"
			<< "\n\tPress 2 for Subtraction"
			<< "\n\tPress 3 for Multiplication"
			<< "\n\tPress 4 for Division" << endl;
		cin >> action;

		cout << endl;
	}
	void calculate()
	{
		if (action == 1)
			cout << "Addition of " << x << " & " << y << " is " << x + y << "." << endl;
		else if (action == 2)
			cout << "Subtraction of " << x << " & " << y << " is " << x - y << "."<< endl;
		else if (action == 3)
			cout << "Multiplication of " << x << " & " << y << " is " << x * y << "."<< endl;
		else if (action == 4)
			cout << "Division of " << x << " & " << y << " is " << (float)x / (float)y << "." << endl;
		else
			cout << "Error! Wrong input" << endl;
	}

};

int main()
{
	cout << "For Integer Numbers" << endl;
	Calculator<int> cal1;
	cal1.calculate();

	cout << "\nFor Float Numbers" << endl;
	Calculator<float> cal2;
	cal2.calculate();

	return 0;
}
