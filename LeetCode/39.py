class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.res = []
        def backtrack(cand, sum):
            if sum == target:
                self.res.append(cand)
                return
            if sum > target:
                return
            for i in candidates:
                if cand[-1] <= i:
                    backtrack(cand+[i], sum+i)
        
        for i in candidates:
            backtrack([i], i)
        return self.res
