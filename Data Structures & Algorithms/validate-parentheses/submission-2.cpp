class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else if (s[i] == ')') {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top() == '(') {
                    stk.pop();
                }
                else {
                    return false;
                }
            }else if (s[i] == '}') {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top() == '{') {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == ']') {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top() == '[') {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (stk.empty())
            return true;
        return false;
    }
};
