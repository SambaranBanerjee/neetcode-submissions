class MinStack {
public:
    stack<int> stk;
    stack<int> minElements;
    MinStack() {

    }
    
    void push(int val) {
        if (minElements.empty() || minElements.top() >= val) {
            minElements.push(val);
        }
        stk.push(val);
    }
    
    void pop() {
        int removedValue = stk.top();
        stk.pop();
        if (removedValue == minElements.top()){
            minElements.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minElements.top();
    }
};
