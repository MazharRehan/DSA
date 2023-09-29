//Task3: C++ program to swap data of int, float and character using function template

#include <iostream>
using namespace std;

template <typename T>
void Swap(T&a, T&b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


int main()
{
	int i1 = 10, i2 = 50;
	float f1 = 2.2, f2 = 5.5;
	char c1 = 'a', c2 = 'z';

	cout << "Values before Swapping: " << endl;
	cout << "i1 = " << i1
		<< "\ni2 = " << i2
		<< "\nf1 = " << f1
		<< "\nf2 = " << f2
		<< "\nc1 = " << c1
		<< "\nc2 = " << c2 << endl;

	Swap(i1, i2);
	Swap(f1, f2);
	Swap(c1, c2);

	cout << "Values After Swapping: " << endl;
	cout << "i1 = " << i1
		<< "\ni2 = " << i2
		<< "\nf1 = " << f1
		<< "\nf2 = " << f2
		<< "\nc1 = " << c1
		<< "\nc2 = " << c2 << endl;

	system("pause");
	return 0;
}
