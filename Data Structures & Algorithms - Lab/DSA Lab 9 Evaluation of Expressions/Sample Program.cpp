// convert infix to postfix

/*
char a = '1';
int b = a - '0'; // '0' is 48 in ASCII // '1' is 49 in ASCII // 49 - 48 = 1
cout << b << endl;
Output:
1
//Below is the piece of code showing the conversion from string to int using stoi() :
string s = "3425";
int x = stoi(s);
cout << "The value of x is: " << x;
Output:
The value of x is: 3425
*/
#include <iostream>
#include <stack>
#include <string>
#include <sstream> 
using namespace std;

// takes an operator as input and returns its precedence value.
int precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}
// takes two integers and an operator and returns the result 
// of the arithmetic operation performed on them.
int applyOp(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
	return 0;
}
//takes an infix expression as input and returns its result.
int evaluate(string expression)
{
	stack<int> values;
	stack<char> ops;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ') // If the character is a space, it is skipped
			continue;
		if (isdigit(expression[i])) // isdigit(....)  build in function
		{
			int val = 0;
			while (i < expression.length() && isdigit(expression[i]))
			{
				val = (val * 10) + (expression[i] - '0'); // '0' is used to convert character to integer beasue '0' is 48 in ASCII
				i++;
			}
			i--;
			values.push(val);
		}
		else if (expression[i] == '(')
			ops.push(expression[i]);

		else if (expression[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();
				int val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(applyOp(val1, val2, op));
			}
			if (!ops.empty())
				ops.pop();
		}
		else
		{
			while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i]))
			{
				int val2 = values.top();
				values.pop();
				int val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(applyOp(val1, val2, op));
			}
			ops.push(expression[i]);
		}
	}
	while (!ops.empty())
	{
		int val2 = values.top();
		values.pop();
		int val1 = values.top();
		values.pop();
		char op = ops.top();
		ops.pop();
		values.push(applyOp(val1, val2, op));
	}
	return values.top();
}

int main()
{
	string expression;
	cout << "Enter an infix expression: ";
	getline(cin, expression);

	int result = evaluate(expression);

	cout << "Result: " << result << endl;

	return 0;
}
