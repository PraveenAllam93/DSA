/* infix to postfix */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int precedence(char c) {
    int prec = (c == '^') ? 3 
        : (c == '/') || c == '*' ?  2
        : (c == '+') || c == '-' ?  1
        :  -1;
    return prec;    
}

void infixToPostfix(string s) {
    stack<char> stk;
    string result;

    for ( int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9)) {
            result += c;
        }

        else if ( c == '(' ) {
            stk.push(c);
        }

        else if ( c == ')' ) {
            while (stk.top() != '(' ) {
                result += stk.top();
                stk.pop();
            }
            stk.pop();
        }

        else {
            while (!stk.empty()
                   && precedence(s[i]) <= precedence(stk.top())) {
                result += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
 
    cout << "The Postfix is : " + result << endl;
}

int main() {
    string s;
    cout << "Enter the infix operation : ";
    cin >> s;
    infixToPostfix(s);
    return 0;
}