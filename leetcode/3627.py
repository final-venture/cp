class Solution:
    def maximumMedianSum(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        # we want to take the smallest one, then two largest ones.
        # the second largest one is the median
        triplets = n // 3
        ret = 0
        for i in range(n - 2, triplets - 1, -2):
            ret += nums[i]
        return ret
        