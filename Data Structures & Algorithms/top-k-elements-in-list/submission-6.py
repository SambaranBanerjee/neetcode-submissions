class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        min_heap = []

        for item, freq in count.items():
            #min-heap in python sorts by first element of tuple
            heapq.heappush(min_heap, (freq, item)) 
            
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        
        return [item for freq, item in min_heap]