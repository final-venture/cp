class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        res = [intervals[0]]

        for x in intervals:
            if res[-1][1] >= x[0]:
                res[-1] = [res[-1][0], max(x[1], res[-1][1])]
            else:
                res.append([x[0], x[1]])
        
        return res
