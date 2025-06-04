class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            b = 1 & (n >> i)
            res = res | (b << (31 - i))

        return res
