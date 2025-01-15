class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = 0
        right = 1
        maxprofit = 0

        while left < right < len(prices):
            if prices[left] >= prices[right]:
                left = right
                right += 1
            else:
                maxprofit = max(maxprofit, prices[right] - prices[left])
                right += 1

        return maxprofit
