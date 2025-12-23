class Solution:
    def lastInteger(self, n: int) -> int:
        mask = 12297829382473034410
        return ((n - 1) & mask) + 1
