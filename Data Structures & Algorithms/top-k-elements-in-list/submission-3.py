class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        for num in nums:
            counts[num] = counts.get(num, 0) + 1
        
        sorted_items = sorted(counts.items(), key=lambda item: item[1] , reverse=True)
        top_k_freq = []

        for i in range(k):
            top_k_freq.append(sorted_items[i][0])
        return top_k_freq