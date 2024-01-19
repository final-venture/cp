class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        used = set()
        def helper(cand):
            if len(cand) == len(nums):
                res.append(cand)
                return
            for i in nums:
                if i in used:
                    continue
                used.add(i)
                helper(cand+[i])
                used.remove(i)
        
        helper([])
        return res
