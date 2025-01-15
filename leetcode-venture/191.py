# Own (bad memory)
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        curr = 1
        while n:
            if n & curr == curr:
                n -= curr
                count += 1
            curr *= 2

        return count

# Model
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            n &= (n-1)
            count += 1
        return count
