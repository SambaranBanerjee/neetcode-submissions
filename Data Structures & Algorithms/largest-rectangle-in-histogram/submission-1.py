class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        n = len(heights)
        max_area = 0
        stk = []
        for i in range(n):
            while stk and heights[stk[-1]] > heights[i]:
                height = heights[stk[-1]]
                stk.pop()
                if not stk:
                    max_area = max(max_area, height * i)
                else:
                    max_area = max(max_area, height * (i - stk[-1] - 1))
            stk.append(i)
        return max_area