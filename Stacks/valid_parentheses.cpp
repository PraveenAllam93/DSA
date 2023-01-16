#include <stack>

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        char check;
        stack<char> validation_check;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' or s[i] == '[') {
                validation_check.push(s[i]);
            }
            else {
                if (validation_check.empty()) return false;
                check = validation_check.top();
                if((s[i] == ')' && check != '(') || (s[i] == '}' && check != '{') || (s[i] == ']' && check != '[')) return false;
                validation_check.pop();
            }
        }
        return validation_check.empty();
        
    }
};
