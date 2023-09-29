/* Task 3:
Check if an expression is balanced or not.
Example
{[{}{}]}[()], {{}{}}, []{}() are balanced expressions.
{()}[), {(}) are not balanced
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std; 

bool isBalanced(string expression) {
    stack<char> stack; // stack to store opening brackets

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch); // push opening brackets
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty())
                return false;

            char top = stack.top();
            stack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    string expression1 = "{[{}{}]}[()]";
    string expression2 = "{{}{}]";
    string expression3 = "[]{}()";

    if (isBalanced(expression1))
        cout << expression1 << " is balanced" << endl;
    else
        cout << expression1 << " is not balanced" << endl;

    if (isBalanced(expression2))
        cout << expression2 << " is balanced" << endl;
    else
        cout << expression2 << " is not balanced" << endl;

    if (isBalanced(expression3))
        cout << expression3 << " is balanced" << endl;
    else
        cout << expression3 << " is not balanced" << endl;

    return 0;
}
