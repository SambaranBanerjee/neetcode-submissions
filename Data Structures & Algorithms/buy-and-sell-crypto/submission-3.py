class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        min_profit = prices[0]
        for price in prices:
            min_profit = min(price, min_profit)
            max_profit = max(max_profit, price - min_profit)
        return max_profit