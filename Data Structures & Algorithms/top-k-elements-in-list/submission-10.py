class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1
        min_heap = []

        for item,freq in count.items():
            heapq.heappush(min_heap, (freq, item))

            if len(min_heap) > k:
                heapq.heappop(min_heap)

        return [item for freq, item in min_heap]