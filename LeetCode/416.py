# Brute Force / Naive
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        self.res = False
        self.t = sum(nums)

        if self.t % 2 != 0:
            return False

        def dfs(i, cand):
            if cand == self.t//2:
                self.res = True
                return
            if i >= len(nums):
                return
            dfs(i+1, cand+nums[i])
            dfs(i+1, cand)
        
        dfs(0, 0)
        return self.res
