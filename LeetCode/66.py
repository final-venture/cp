class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits.insert(0, 0)
        def increment(i):
            if digits[i] == 9:
                digits[i] = 0
                increment(i-1)
            else:
                digits[i] += 1

        increment(len(digits) - 1)

        if digits[0] == 0:
            digits.pop(0)
        return digits
