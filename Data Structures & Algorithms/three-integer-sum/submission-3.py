class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l = i + 1
            r = len(nums) - 1
            while l < r:
                current_sum = nums[i] + nums[l] + nums[r]
                if current_sum == 0:
                    result.append([nums[i], nums[l], nums[r]])
                    while (l > 0) and (l < len(nums) - 1) and nums[l] == nums[l + 1]:
                        l += 1
                    while (r > 0) and (r < len(nums) - 1) and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif current_sum > 0:
                    r -= 1
                else:
                    l += 1

        return result
                    