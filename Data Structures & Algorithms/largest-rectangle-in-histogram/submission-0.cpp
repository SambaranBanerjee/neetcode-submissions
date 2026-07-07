class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int maxArea = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int height = heights[stk.top()];
                stk.pop();
                if (stk.empty()) {
                    maxArea = max(maxArea, height * i);
                }
                else {
                    maxArea = max(maxArea, height * (i - stk.top() - 1));
                }
            }
            stk.push(i);
        }
        return maxArea;
    }
};
