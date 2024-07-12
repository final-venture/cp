class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        res = 0
        intervals.sort()
        prev = intervals[0]

        for i in range(1, len(intervals)):
            curr = intervals[i]
            if curr[0] == prev[0]:
                res += 1
                continue
            if curr[0] >= prev[1]:
                prev = curr
            elif curr[1] >= prev[1]:
                res += 1
            else:
                prev = curr
                res += 1
            
        return res
