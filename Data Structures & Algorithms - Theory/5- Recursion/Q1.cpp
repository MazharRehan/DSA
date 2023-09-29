// Recursion

#include<iostream>
using namespace std;

void display(int n) // display numbers from n...1 and 1...n
{
	if (n < 1) // base case/condition
		return;

	cout << n << endl; // print in forward Order
	display(n - 1);
	cout << n << endl; // print in reverse  order
}

int main()
{
	int n = 0;
	cout << "......"; cin >> n;
	display(n);

	return 0;
}
