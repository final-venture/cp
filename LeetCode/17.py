class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        if not digits:
            return []

        res = []
        m = {
        "2": ["a", "b", "c"], 
        "3": ["d", "e", "f"], 
        "4": ["g", "h", "i"], 
        "5": ["j", "k", "l"], 
        "6": ["m", "n", "o"], 
        "7": ["p", "q", "r", "s"], 
        "8": ["t", "u", "v"], 
        "9": ["w", "x", "y", "z"]
        }

        def dfs(i, cand):
            if i >= len(digits):
                res.append(cand)
                return

            for x in m[digits[i]]:
                dfs(i+1, cand+x)

            return

        dfs(0, "")
        return res
