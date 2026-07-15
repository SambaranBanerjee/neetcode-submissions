class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        result = 0

        while (l <= r):
            mid = l + (r - l) // 2
            
            totalHours = sum(math.ceil(pile/mid) for pile in piles)

            if totalHours <= h:
                result = mid
                r = mid - 1
            else:
                l = mid + 1

        return result


        