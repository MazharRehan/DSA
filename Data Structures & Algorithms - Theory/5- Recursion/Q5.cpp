// Print the nth Fibonacci number ( 0, 1, 1, 2, 3, 5, 8, 13, ....  )
// sum of previous two numbers 0+1=1, 1+1=2, 1+2=3, 2+3=5, 3+5=8, 5+8=13

#include<iostream>
using namespace std;

int fib(int n)
{
	if (n == 0 || n == 1)
		return n;

	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n;
	cin >> n;
	cout << n << "th fibonacci number is " << fib(n);

	return 0;
}