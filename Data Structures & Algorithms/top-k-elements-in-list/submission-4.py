class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        result = []
        sorted_list = sorted(count.items(), key= lambda x: x[1] , reverse=True)
        for i in range(0,k):
            result.append(sorted_list[i][0])
        return result