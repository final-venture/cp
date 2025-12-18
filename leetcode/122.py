class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        MIN = -(10 ** 10)

        @cache
        def dfs(idx, bal):
            if idx >= n:
                return (MIN if bal & 1 else 0)
            ret = dfs(idx + 1, bal)
            if bal <= 0:
                ret = max(ret, dfs(idx + 1, bal + 1) - prices[idx])
            if bal > 0:
                ret = max(ret, dfs(idx + 1, bal - 1) + prices[idx])
            return ret

        return dfs(0, 0)
        