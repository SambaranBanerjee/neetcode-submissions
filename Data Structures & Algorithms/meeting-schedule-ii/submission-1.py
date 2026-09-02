"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        if not intervals:
            return 0

        start = sorted([i.start for i in intervals])
        end = sorted([i.end for i in intervals])

        max_rooms = 0
        current_rooms = 0
        s = 0
        e = 0
        n = len(intervals)

        while s < n:
            if start[s] < end[e]:
                current_rooms += 1
                s += 1
            else:
                current_rooms -= 1
                e += 1

            max_rooms = max(max_rooms, current_rooms)

        return max_rooms