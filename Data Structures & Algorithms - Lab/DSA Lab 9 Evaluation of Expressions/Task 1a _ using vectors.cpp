#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

// Custom stack template
template <typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(T value) {
        data.push_back(value);
    }

    T pop() {
        if (data.empty())
            throw out_of_range("Stack is empty");
        T value = data.back();
        data.pop_back();
        return value;
    }

    T top() {
        if (data.empty())
            throw out_of_range("Stack is empty");
        return data.back();
    }

    bool empty() {
        return data.empty();
    }
};

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

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    string postfix;
    Stack<char> stack;

    for (char ch : infix) {
        if (ch == ' ')
            continue;

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.pop();
            }
            if (!stack.empty() && stack.top() == '(')
                stack.pop(); // Pop the opening parenthesis
        }
        else if (isOperator(ch)) {
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        postfix += stack.pop();
    }

    return postfix;
}

// Function to evaluate the postfix expression
int evaluatePostfix(string postfix, vector<int>& values) {
    Stack<int> stack;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            int index = ch - 'a';
            stack.push(values[index]);
        }
        else if (isOperator(ch)) {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result = 0;

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
                result = operand1 / operand2;
                break;
            }

            stack.push(result);
        }
    }

    return stack.pop();
}

int main() {
    string infixExpression = "a + b - (c + d * e / (f - g)) * (h + i)";

    // Convert infix expression to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Prompt for variable values
    vector<int> values(26, 0);
    for (char ch = 'a'; ch <= 'i'; ch++) {
        cout << "Enter value for " << ch << ": ";
        cin >> values[ch - 'a'];
    }

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression, values);
    cout << "Result: " << result << endl;

    return 0;
}
