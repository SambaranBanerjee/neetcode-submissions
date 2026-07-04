class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) 
            return 0;
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[0];
        int rightMax = height[right];
        while(left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                maxArea += leftMax - height[left];
                left++;
            }
            else {
                rightMax = max(rightMax, height[right]);
                maxArea += rightMax - height[right];
                right--;
            }
        }
        return maxArea;
    }
};
