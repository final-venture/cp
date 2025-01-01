# Modified version of "KADANE'S ALGORITHM"
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        lmax = lmin = res = nums[0]

        for i in range(1, len(nums)):
            tmp = lmax
            lmax = max(nums[i], nums[i] * lmax, nums[i] * lmin)
            lmin = min(nums[i], nums[i] * tmp, nums[i] * lmin)
            res = max(res, lmax)

        return res
