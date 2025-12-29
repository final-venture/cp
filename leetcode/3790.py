class Solution:
    def minAllOneMultiple(self, k: int) -> int:
        digits, curr = 0, 0
        # *10 + 1

        while (digits < 100005):
            digits += 1
            curr = (curr * 10 + 1) % k
            if (curr % k == 0):
                return digits

        return -1
