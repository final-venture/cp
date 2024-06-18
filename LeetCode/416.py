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

# DP
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        t = sum(nums)
        if t % 2:
            return False

        dp = set()

        for i in range(len(nums)):
            for n in dp.copy():
                dp.add(nums[i]+n)
            dp.add(nums[i])

        return True if t // 2 in dp else False
