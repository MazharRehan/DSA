/*Task1:
Convert the following infix expression into a postfix expression using your
own stack template.
a ++bb--((cc++dd**ee//((ff--gg))))**((hh++ii))
Now, evaluate the postfix expression by providing a value for each variable.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Custom stack template
template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

public:
    Stack(int size) {
        capacity = size;
        data = new T[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(T value) {
        if (topIndex == capacity - 1)
            throw out_of_range("Stack is full");
        data[++topIndex] = value;
    }

    T pop() {
        if (topIndex == -1)
            throw out_of_range("Stack is empty");
        return data[topIndex--];
    }

    T top() {
        if (topIndex == -1)
            throw out_of_range("Stack is empty");
        return data[topIndex];
    }

    bool empty() {
        return (topIndex == -1);
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
    Stack<char> stack(infix.length());

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
int evaluatePostfix(string postfix, int* values) {
    Stack<int> stack(postfix.length());

    for (char ch : postfix) {
        if (isalnum(ch)) {
            int index = ch - 'a';
            stack.push(values[index]);
        }
        else if (isOperator(ch)) {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result = 0;

            switch (ch) 
            {
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
                    cout << "Math Error: cannot divide an expression by Zero" << endl;
                    exit(0);
                }
                break;
            }

            stack.push(result);
        }
    }

    return stack.pop();
}

int main() {
    string infixExpression = "a + b - (c + d * e / (f - g)) * (h + i)";

    cout << "Infix expression: a + b - (c + d * e / (f - g)) * (h + i)" << endl;

    // Convert infix expression to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Prompt for variable values
    int values[26] = { 0 };
    for (char ch = 'a'; ch <= 'i'; ch++) {
        cout << "Enter value for " << ch << ": ";
        cin >> values[ch - 'a'];
    }

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression, values);
    cout << "Result: " << result << endl;

    return 0;
}
