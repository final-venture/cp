class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        gaps = []
        gaps.append(startTime[0])
        for i in range(1, n):
            gap = startTime[i] - endTime[i - 1]
            gaps.append(gap)
        gaps.append(eventTime - endTime[-1])

        curr = maxx = l = r = 0
        while r < len(gaps):
            curr += gaps[r]
            maxx = max(maxx, curr)
            if r - l >= k:
                curr -= gaps[l]
                l += 1
            r += 1

        return maxx
            