"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""
# Combine 252 & 1190: Runtime: O(n^2 logn), Memory: O(n)
class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals = [(i.start, i.end) for i in intervals]
        overflow = []
        res = 0
        
        while intervals:
            intervals.sort()
            prev = intervals[0]
            for i in range(1, len(intervals)):
                curr = intervals[i]
                if curr[0] >= prev[1]:
                    prev = curr
                elif curr[1] < prev[1]:
                    overflow.append(prev)
                    prev = curr
                else:
                    overflow.append(curr)
                    
            intervals = overflow
            overflow = []
            res += 1

        return res
