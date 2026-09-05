class Solution:
    def jump(self, nums: List[int]) -> int:
        count = 0
        can_reach = 0
        max_dist = 0

        for i in range(len(nums) - 1):
            can_reach = max(can_reach, i + nums[i])
            if i == max_dist:
                count += 1
                max_dist = can_reach

        return count