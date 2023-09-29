/* Task 2: 
Convert the following infix expression into a prefix expression
a - b + c * (d / e - (f + g))
Now, evaluate the prefix expression by providing a value for each variable.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(string infix) {
    string prefix;
    stack<char> stack;

    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    for (char& ch : infix) {
        if (ch == ' ')
            continue;

        if (isalnum(ch)) {
            prefix += ch;
        }
        else if (ch == ')') {
            stack.push(ch);
        }
        else if (ch == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == ')')
                stack.pop(); // Pop the closing parenthesis
        }
        else if (isOperator(ch)) {
            while (!stack.empty() && precedence(stack.top()) > precedence(ch)) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    // Reverse the prefix expression to get the final result
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

// Function to evaluate the prefix expression
int evaluatePrefix(string prefix, int* values) {
    stack<int> stack;

    // Reverse the prefix expression
    reverse(prefix.begin(), prefix.end());

    for (char ch : prefix) {
        if (isalnum(ch)) {
            int index = ch - 'a';
            stack.push(values[index]);
        }
        else if (isOperator(ch)) {
            int operand1 = stack.top();
            stack.pop();
            int operand2 = stack.top();
            stack.pop();
            int result;

            switch (ch) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 != 0)
                    result = operand1 / operand2;
                else
                {
                    cout << "Math Error: Cannot divide an expression by Zero" << endl;
                    exit(0);
                }
                break;
            }

            stack.push(result);
        }
    }

    return stack.top();
}

int main() {
    string infixExpression = "a - b + c * (d / e - (f + g))";


    cout << "Infix expression: a - b + c * (d / e - (f + g))" << endl;

    // Convert infix expression to prefix
    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << endl;

    // Prompt for variable values
    int values[26] = { 0 };
    for (char ch = 'a'; ch <= 'g'; ch++) {
        cout << "Enter value for " << ch << ": ";
        cin >> values[ch - 'a'];
    }

    // Evaluate the prefix expression
    int result = evaluatePrefix(prefixExpression, values);
    cout << "Result: " << result << endl;

    return 0;
}