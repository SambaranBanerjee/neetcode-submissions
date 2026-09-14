class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        leftMax = height[0]
        rightMax = height[right]
        maxArea = 0

        while left <= right:
            if height[left] <= height[right]:
                leftMax = max(leftMax, height[left])
                maxArea += leftMax - height[left]
                left += 1
            else:
                rightMax = max(rightMax, height[right])
                maxArea += rightMax - height[right]
                right -= 1

        return maxArea
