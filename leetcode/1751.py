# O(k * n) dp
# dp[i][j] is max value we can have after we attend up to the i'th event on the j'th selection
# dp[i][j] = max(val[i] + dp[i - 1][j + 1], val[i] + dp[i - 2][j + 1]...)
# ret is max(dp[n][j]) for 0 <= j <= k

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        n = len(events)
        @cache
        def dfs(idx, remaining):
            if idx >= n or not remaining:
                return 0
            nxt = bisect_right(events, [events[idx][1], inf, inf])
            return max(dfs(nxt, remaining - 1) + events[idx][2], dfs(idx + 1, remaining))
        return dfs(0, k)

# Cached Binary Search Solution O(n(k + log n))
class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        n = len(events)
        next_event = [n] * n
        for i in range(n):
            ed = events[i][1]
            next_event[i] = bisect_right(events, [ed, inf, inf])

        @cache
        def dfs(idx, remaining):
            if idx >= n or not remaining:
                return 0
            return max(dfs(next_event[idx], remaining - 1) + events[idx][2], dfs(idx + 1, remaining))
        return dfs(0, k)

