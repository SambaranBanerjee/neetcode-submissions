class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        for i, num in enumerate(nums):
            if num == target:
                return i
        return -1