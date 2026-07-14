class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        top_k_freq = counts.most_common(k)

        freq_elements = [element for element,count in top_k_freq]
        return freq_elements