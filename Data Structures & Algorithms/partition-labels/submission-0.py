class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last_seen = {}
        for i in range(len(s)):
            last_seen[s[i]] = i
        result = []
        start = 0
        boundary = 0 
        for end in range(len(s)):
            boundary = max(boundary, last_seen[s[end]])
            if end == boundary:
                result.append(end - start + 1)
                start = end + 1

        return result
