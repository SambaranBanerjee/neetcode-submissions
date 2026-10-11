class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen_index = {}
        left = 0
        max_len = 0
        
        for right, char in enumerate(s):
            if char in last_seen_index and last_seen_index[char] >= left:
                left = last_seen_index[char] + 1
            
            last_seen_index[char] = right
            
            max_len = max(max_len, right - left + 1)

        return max_len