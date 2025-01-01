class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        left = 1
        right = max(piles)
        res = inf

        while left <= right:
            k = (left + right) // 2
            h_taken = 0
            for bananas in piles:
                h_taken += math.ceil(bananas/k)
            if h_taken <= h:
                right = k - 1
                res = min(res, k)
            else:
                left = k + 1
                
        return res
