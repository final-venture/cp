class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        seen = set()

        def helper(i, cand, s):
            if s == target:
                res.append(cand)
                return
            if s > target or i >= len(candidates):
                return
        
            c = candidates[i]
            if c in seen:
                helper(i+1, cand, s)
            else:
                helper(i+1, cand+[c], s+c)
                seen.add(c)
                helper(i+1, cand, s)
                seen.remove(c)
        
        helper(0, [], 0)
        return res
