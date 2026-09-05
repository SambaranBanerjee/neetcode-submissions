class Solution:
    def canJump(self, nums: List[int]) -> bool:
        finish = len(nums) - 1
        can_reach = 0
        for i in range(len(nums)):
            if can_reach < i:
                return False
            
            can_reach = max(can_reach, i + nums[i])
            
            if can_reach >= finish:
                return True

        return True
            
