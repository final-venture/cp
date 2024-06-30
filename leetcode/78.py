class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        def backtrack(i, cand=[]):
            if i == len(nums):
                self.res.append(cand)
                return
            backtrack(i+1, cand+[nums[i]])
            backtrack(i+1, cand)
        
        backtrack(0)
        return self.res
