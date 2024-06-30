class Solution:
    def minSteps(self, s: str, t: str) -> int:
        res = 0
        sc = {}
        tc = {}

        for i in range(len(s)):
            sc[s[i]] = sc.get(s[i], 0) + 1

        for i in range(len(t)):
            tc[t[i]] = tc.get(t[i], 0) + 1

        for i in sc:
            tmp = sc[i] - tc.get(i, 0)
            if tmp > 0:
                res += tmp
        
        return res
