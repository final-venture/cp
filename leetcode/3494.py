class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n, m = len(skill), len(mana)
        dp = [0] * (n + 1)

        for i in range(m):
            for j in range(1, n + 1):
                dp[j] = max(dp[j], dp[j - 1]) + mana[i] * skill[j - 1]
            for j in range(n - 1, 0, -1):
                dp[j] = dp[j + 1] - mana[i] * skill[j]

        return dp[n]
