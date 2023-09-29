//Task4: C++ program to find largest among two numbers using function template

#include <iostream>
using namespace std;

template <typename T>
T largest(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}


int main()
{
	int i1 = 10, i2 = 50;
	float f1 = 2.2, f2 = 5.5;
	char c1 = 'a', c2 = 'z';

	cout << "Lagest of " << i1 << " & " << i2 << " is " << largest(i1, i2) << endl;
	cout << "Lagest of " << f1 << " & " << f2 << " is " << largest(f1, f2) << endl;
	cout << "Lagest of " << c1 << " & " << c2 << " is " << largest(c1, c2) << endl;
																		
	system("pause");
	return 0;
}