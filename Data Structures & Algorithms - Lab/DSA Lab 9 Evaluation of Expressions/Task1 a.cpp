#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
/*
The <unordered_map> library in C++ provides an implementation of an associative 
container that stores key-value pairs with unique keys. It is part of the Standard 
Template Library (STL) and is based on a hash table data structure.

The unordered_map container is similar to the map container but with some differences.
It provides faster access to elements based on their keys but does not maintain a 
specific order of the elements. The elements are stored in an unordered manner based 
on their hash values.

Here are some key features and functionalities provided by the unordered_map:

Key-value pairs: It stores elements as key-value pairs, where each key is unique within 
the container.
Fast access: The unordered_map provides constant-time average complexity for access, 
insertion, and deletion of elements.
Hashing: It uses a hash function to determine the position of elements within the container,
enabling efficient lookup.
No specific order: Unlike map, unordered_map does not maintain a specific order of elements.
The elements are unordered based on their hash values.
Lookup and retrieval: Elements can be accessed and retrieved by their keys using the subscript 
operator ([]), at(), or iterators.
Iteration: It supports iteration over the elements using iterators.
Dynamic size: The size of the unordered_map can dynamically grow or shrink as elements are 
inserted or erased.
The unordered_map is particularly useful in scenarios where fast access to elements based on 
their keys is required, and the order of elements is not important. It is commonly used for 
implementing lookup tables, caches, and solving problems that involve mapping and indexing 
data efficiently
*/
using namespace std;

// Custom stack template
template <typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(T value) 
    {
        data.push_back(value);
    }

    T pop() 
    {
        if (data.empty())
            throw out_of_range("Stack is empty");
        T value = data.back();
        data.pop_back();
        return value;
    }

    T top()
    {
        if (data.empty())
            throw out_of_range("Stack is empty");
        return data.back();
    }

    bool empty() 
    {
        return data.empty();
    }
};

// Function to check if a character is an operator
bool isOperator(char ch) 
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) 
{
    string postfix;
    Stack<char> stack;

    for (char ch : infix) 
    {
        if (ch == ' ')
            continue;

        if (isalnum(ch))
            postfix += ch;
        
        else if (ch == '(')
            stack.push(ch);
        
        else if (ch == ')') 
        {
            while (!stack.empty() && stack.top() != '(') 
                postfix += stack.pop();
            
            if (!stack.empty() && stack.top() == '(')
                stack.pop(); // Pop the opening parenthesis
        }
        else if (isOperator(ch)) 
        {
            while (!stack.empty() && precedence(stack.top()) >= precedence(ch)) 
                postfix += stack.pop();
            
            stack.push(ch);
        }
    }

    while (!stack.empty())
        postfix += stack.pop();
    

    return postfix;
}

// Function to evaluate the postfix expression
int evaluatePostfix(string postfix, unordered_map<char, int>& variables) 
{
    Stack<int> stack;

    for (char ch : postfix) 
    {
        if (isalnum(ch))
            stack.push(variables[ch]);
        
        else if (isOperator(ch))
        {
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
                result = operand1 / operand2;
                break;
            }

            stack.push(result);
        }
    }

    return stack.pop();
}

int main() 
{
    string infixExpression = "a + b - (c + d * e / (f - g)) * (h + i)";

    cout << "Infix expression: a + b - (c + d * e / (f - g)) * (h + i)" << endl;

    // Convert infix expression to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Evaluate the postfix expression
    unordered_map<char, int> variables = 
    {
        {'a', 2},
        {'b', 3},
        {'c', 4},
        {'d', 5},
        {'e', 6},
        {'f', 7},
        {'g', 8},
        {'h', 9},
        {'i', 10}
    };

    int result = evaluatePostfix(postfixExpression, variables);
    cout << "Result: " << result << endl;

    return 0;
}
