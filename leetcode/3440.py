class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        gaps = []
        n = len(startTime)
        gaps.append(startTime[0])
        for i in range(1, n):
            gaps.append(startTime[i] - endTime[i - 1])
        gaps.append(eventTime - endTime[-1])

        pfxmax = gaps.copy()
        sfxmax = gaps.copy()
        for i in range(1, n + 1):
            pfxmax[i] = max(gaps[i], pfxmax[i - 1])
        for i in range(n + 1 - 2, -1, -1):
            sfxmax[i] = max(gaps[i], sfxmax[i + 1])
            
        nlg = [0] * (n + 1) # next largest gap for i excl i and i + 1
        for i in range(n + 1):
            if i - 1 >= 0:
                nlg[i] = max(nlg[i], pfxmax[i - 1]) 
            if i + 2 < n + 1:
                nlg[i] = max(nlg[i], sfxmax[i + 2])

        ret = max(gaps)
        for i in range(1, n + 1):
            if nlg[i - 1] >= endTime[i - 1] - startTime[i - 1]:
                ret = max(gaps[i] + gaps[i - 1] + (endTime[i - 1] - startTime[i - 1]), ret)
            else:
                ret = max(gaps[i] + gaps[i - 1], ret)

        return ret
