class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        maxAmount = 0
        while left <= right:
            currAmount = 0
            if heights[left] < heights[right]:
                currAmount = heights[left] * (right - left)
                left += 1
            else:
                currAmount = heights[right] * (right - left) 
                right -= 1
            maxAmount = max(maxAmount, currAmount)

        return maxAmount