class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        res = []

        def backtrack(usedL, usedR, cand):
            if usedL == usedR == n:
                res.append(cand)
                return
            if usedL < n:
                backtrack(usedL+1, usedR, cand+"(")
            if usedR < usedL:
                backtrack(usedL, usedR+1, cand+")")

        backtrack(0,0,"")
        return res
