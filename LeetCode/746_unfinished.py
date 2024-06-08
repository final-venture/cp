class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        memo = {}
        length = len(cost)

        cost.append(0)

        def dfs(i):
            if i < 2:
                return cost[i]
            if i in memo:
                return memo[i]
            else:
                res = min(cost[i] + dfs(i-1), cost[i] + dfs(i-2))
                memo[i] = res
                return res

        return dfs(length)
