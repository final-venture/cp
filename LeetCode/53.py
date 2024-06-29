class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        gmax = -inf
        lmax = 0

        for n in nums:
            lmax += n
            gmax = max(gmax, lmax)
            if lmax < 0:
                lmax = 0
        
        return gmax
