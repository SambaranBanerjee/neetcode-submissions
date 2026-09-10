class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total_prod_with_zero = 1
        total_prod_without_zero = 1
        zero_count = 0
        for num in nums:
            if num == 0:
                total_prod_with_zero *= num
                zero_count += 1 
                continue
            total_prod_without_zero *= num
            total_prod_with_zero *= num
        
        result = []
        for num in nums:
            if num == 0 and zero_count < 2:
                result.append(total_prod_without_zero)
                continue
            elif zero_count > 1:
                result.append(0)
                continue
            result.append(total_prod_with_zero // num)

        return result