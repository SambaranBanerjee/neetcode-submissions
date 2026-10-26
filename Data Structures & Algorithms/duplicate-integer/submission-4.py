class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        elements = set()
        for element in nums:
            if element in elements:
                return True
            elements.add(element)
        return False
        
