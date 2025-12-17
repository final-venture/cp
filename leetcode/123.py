class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        MIN = -(10 ** 10)

        @cache
        def dfs(idx, rem, bal):
            if rem < 0:
                return MIN
            if idx >= n:
                return (MIN if rem & 1 else 0)
            ret = dfs(idx + 1, rem, bal)
            if bal <= 0 and rem > 0:
                ret = max(ret, dfs(idx + 1, rem - 1, bal + 1) - prices[idx])
            if bal > 0 and rem > 0:
                ret = max(ret, dfs(idx + 1, rem - 1, bal - 1) + prices[idx])
            return ret

        return dfs(0, 4, 0)
        