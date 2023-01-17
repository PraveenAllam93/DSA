#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%') return true;
    return false;
}

string prefixToInfix(string prefix_exp) {
    stack<string> infix_exp;

    for (int i = prefix_exp.length() - 1; i >= 0; i--) {
        if (isOperator(prefix_exp[i])) {
            string op1 = infix_exp.top();
            infix_exp.pop();
            string op2 = infix_exp.top();
            infix_exp.pop();

            string operation = "(" + op1 + prefix_exp[i] + op2 + ")";

            infix_exp.push(operation);
        }

        else {
            infix_exp.push(string(1,prefix_exp[i]));
        }
    }

    return infix_exp.top();
}

int main() {
    string s;
    cout << "Enter the prefix exp : ";
    cin >> s;
    cout << "The infix exp is : " + prefixToInfix(s) + "\n";
    return 0;
}