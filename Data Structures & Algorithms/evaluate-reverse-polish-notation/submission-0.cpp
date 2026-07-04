class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                int result = num1 + num2;
                stk.push(result);
            }
            else if (tokens[i] == "-") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                int result = num2 - num1;
                stk.push(result);
            }
            else if (tokens[i] == "*") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                int result = num2 * num1;
                stk.push(result);
            }
            else if (tokens[i] == "/") {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                int result = num2 / num1;
                stk.push(result);
            }
            else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
