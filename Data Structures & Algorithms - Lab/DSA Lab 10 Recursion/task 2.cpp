/*
Task 2
Write a program that computes the sum of first N natural numbers. For example, if a user enters 5 as
input, the program should display 15 as output (since 5+4+3+2+1 = 15). Your function should be
recursive.
*/

#include<iostream>
using namespace std;

int sum(int n)
{
	if (n == 0)
		return 0;

	return n + sum(n - 1);
}

int main()
{
	int n = 0;
	cout << "Input n: ";
	cin>>n;
	
	cout <<"Sum of 5th natural numbers = " << sum(n) << endl;

	system("pause");
	return 0;
}
