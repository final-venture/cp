"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        intervals = [(i.start, i.end) for i in intervals]
        intervals.sort()
        for i in range(1, len(intervals)):
            curr = intervals[i]
            prev = intervals[i - 1]
            if prev[1] > curr[0]:
                return False

        return True
