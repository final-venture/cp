class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)
        MIN = -(10 ** 10)

        dp = [[[-1] * 3 for i in range(2 * k + 1)] for j in range(n)]
        def dfs(idx, rem, bal):
            if rem < 0:
                return MIN
            if idx >= n:
                return (MIN if rem & 1 else 0)
            if dp[idx][rem][bal + 1] != -1:
                return dp[idx][rem][bal + 1]
            ret = dfs(idx + 1, rem, bal)
            if bal >= 0 and rem > 0:
                ret = max(ret, dfs(idx + 1, rem - 1, bal - 1) - prices[idx])
            if bal <= 0 and rem > 0:
                ret = max(ret, dfs(idx + 1, rem - 1, bal + 1) + prices[idx])
            dp[idx][rem][bal + 1] = ret
            return ret

        return dfs(0, 2 * k, 0)
        