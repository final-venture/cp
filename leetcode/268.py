class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0
        for n in range(len(nums) + 1):
            res = res ^ n

        for x in nums:
            res = res ^ x

        return res
