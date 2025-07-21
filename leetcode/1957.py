class Solution:
    def makeFancyString(self, s: str) -> str:
        n = len(s)
        banned = [False] * n

        lst = '.'
        consec_cnt = -1
        for i in range(n):
            if s[i] == lst:
                consec_cnt += 1
                if consec_cnt >= 3:
                    banned[i] = True
            else:
                consec_cnt = 1
                lst = s[i]

        ret = "".join([s[i] for i in range(n) if not banned[i]])
        return ret
