#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%') return true;
    return false;
}

string prefixToPostfix(string prefix_exp) {

    stack<string> postfix_exp;

    for (int i = prefix_exp.length() - 1; i >= 0; i--) {

        if (isOperator(prefix_exp[i])) {

            string op1 = postfix_exp.top();
            postfix_exp.pop();
            string op2 = postfix_exp.top();
            postfix_exp.pop();

            string operation =  op1 + op2 + prefix_exp[i];

            postfix_exp.push(operation);
        }
        else postfix_exp.push(string(1, prefix_exp[i]));
    }

    return postfix_exp.top();
}

int main() {
    string prefix_exp;
    cout << "Enter the prefix exp : ";
    cin >> prefix_exp;
    cout << "The postfix exp is : " << prefixToPostfix(prefix_exp) << "\n";
    return 0;
}