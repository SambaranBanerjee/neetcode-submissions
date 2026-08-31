class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        result = []
        n = len(intervals)

        result.append(intervals[0])

        for [start, end] in intervals:
            prev = result[-1]
            if start <= prev[1]:
                prev[1] = max(prev[1], end)
            elif start > prev[1]:
                result.append([start, end])

        return result