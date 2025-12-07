class Solution:
    def minChanges(self, n: int, k: int) -> int:
        res = 0
        i = 0
        while n or k:
            if n & 1 and not k & 1:
                res += 1
            elif k & 1 and not n & 1:
                return -1
            n = n >> 1
            k = k >> 1

        return res
