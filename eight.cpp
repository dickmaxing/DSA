#include <iostream>
#include <stack>
#include <string>
#include <cmath> 
#include <stdexcept>

using namespace std;

// Function to get the priority of an operator
int priority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '^') {
        return 3;
    }
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string exp) {
    stack<char> c;
    string fin;

    int len = exp.length();
    for (int i = 0; i < len; i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9' || ch == '.') {
            // If the character is a digit, add it to the output string
            fin += ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            // If the character is an operator
            while (!c.empty() && priority(ch) <= priority(c.top())) {
                fin += c.top(); // Pop from the stack to output string
                c.pop();
            }
            c.push(ch); // Push the current operator onto the stack
        } else if (ch == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            c.push(ch);
        } else if (ch == ')') {
            // If the character is a closing parenthesis, pop from the stack until the opening parenthesis is found
            while (c.top() != '(') {
                fin += c.top(); // Pop from the stack to output string
                c.pop();
            }
            c.pop(); // Remove the opening parenthesis from the stack
        }
    }

    // Pop all remaining operators in the stack
    while (!c.empty()) {
        fin += c.top(); // Pop from the stack to output string
        c.pop();
    }

    return fin;
}

// Function to evaluate a postfix expression
float evaluatePostfix(string exp) {
    stack<float> c;

    int len = exp.length();
    for (int i = 0; i < len; i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9' || ch == '.') {
            // If the character is a digit, push it onto the stack
            float num = 0;
            int j = i;
            while (j < len && (exp[j] >= '0' && exp[j] <= '9' || exp[j] == '.')) {
                num = num * 10 + (exp[j] - '0');
                j++;
            }
            if (j < len && exp[j] == '.') {
                j++;
                float decimal = 0;
                int k = 0;
                while (j < len && exp[j] >= '0' && exp[j] <= '9') {
                    decimal += (exp[j] - '0') / pow(10, k + 1);
                    j++;
                    k++;
                }
                num += decimal;
            }
            c.push(num);
            i = j - 1;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            // If the character is an operator, pop two numbers from the stack, perform the operation, and push the result back onto the stack
            float num2 = c.top();
            c.pop();
            float num1 = c.top();
            c.pop();
            if (ch == '+') {
                c.push(num1 + num2);
            } else if (ch == '-') {
                c.push(num1 - num2);
            } else if (ch == '*') {
                c.push(num1 * num2);
            } else if (ch == '/') {
                if (num2 != 0) {
                    c.push(num1 / num2);
                } else {
                    throw runtime_error("Division by zero");
                }
            } else if (ch == '^') {
                c.push(pow(num1, num2));
            }
        }
    }

    // The final result is the only number left in the stack
    return c.top();
}

int main() {
    string inExp;
    cout << "Enter an expression: ";
    getline(cin,inExp);
    string postfixExp = infixToPostfix(inExp);
    cout << "Postfix expression: " << postfixExp << endl;
    cout << "Evaluating postfix expression: " << postfixExp << endl;
    float result = evaluatePostfix(postfixExp);
    cout << "Result: " << result << endl;
    return 0;
}