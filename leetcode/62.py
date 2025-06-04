class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for j in range(n)] for i in range(m)]
        dp[0][0] = 1
        rows, cols = m, n

        for r in range(rows):
            for c in range(cols):
                if 0 <= r - 1 < rows:
                    dp[r][c] += dp[r - 1][c]
                if 0 <= c - 1 < cols:
                    dp[r][c] += dp[r][c - 1] 
                
        return dp[-1][-1]
