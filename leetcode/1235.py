class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        events = []
        for st, ed, wt in zip(startTime, endTime, profit):
            events.append((st, ed, wt))
        events.sort()
        n = len(events)

        @cache
        def dfs(i):
            if i >= n:
                return 0
            nxt = bisect_left(events, (events[i][1], -inf, -inf))
            return max(dfs(nxt) + events[i][2], dfs(i + 1))

        return dfs(0)
