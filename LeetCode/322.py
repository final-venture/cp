# Memoisation
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        memo = {}  # Memoization dictionary

        def dp(remaining):
            if remaining == 0:
                return 0  # Base case: amount reached
            if remaining < 0:
                return float('inf')  # Invalid case: amount exceeded
            if remaining in memo:
                return memo[remaining]  # Use memoized result

            min_coins = float('inf')
            for coin in coins:
                min_coins = min(min_coins, 1 + dp(remaining - coin))

            memo[remaining] = min_coins  # Store result for memoization
            return min_coins

        result = dp(amount)
        return result if result != float('inf') else -1  # Check if solution exists

# Bottom-Up
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount+1)
        dp[0] = 0

        for i in range(1, amount+1):
            for c in coins:
                if i-c >= 0:
                    dp[i] = min(dp[i], 1 + dp[i-c])
        
        res = dp[amount]
        return res if res != amount+1 else -1
