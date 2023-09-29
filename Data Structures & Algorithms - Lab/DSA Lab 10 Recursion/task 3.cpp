/*
Task 3
The least common multiple (LCM) of two numbers is the smallest number that is a multiple of both. Write
and test a recursive method LCM with the following specification.
PARAMETERS: positive integers j and k
RETURN VALUE: the least common multiple (LCM) of j and k
EXAMPLES:
LCM (3, 5) is 15
LCM (6, 8) is 24
*/

#include<iostream>
using namespace std;

int LCM(int n1, int n2)
{
	static int multiple = 0;
	multiple += n2; // we are creating multiples of one number and checking if it is a multiple of the other number

	if (multiple%n1 == 0 && multiple%n2 == 0)
		return multiple;
	else
		return LCM(n1, n2);
}

int main()
{
	int n1, n2;
	cout << "Enter numbers:\nn1_";
	cin >> n1;
	cout << "n2_";
	cin >> n2;
	cout << "LCM of " << n1 << " & " << n2 << " is " << LCM(n1, n2) << endl;

	return 0;
}
