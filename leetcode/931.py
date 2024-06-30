class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        dim = len(matrix)
        self.res = inf
        self.cache = {}
        def helper(r, c):
            if r == dim:
                return 0
            if c < 0 or c == dim:
                return inf
            if (r, c) in self.cache:
                return self.cache[(r, c)]
            
            res = matrix[r][c] + min(helper(r+1, c), helper(r+1, c+1), helper(r+1, c-1))
            self.cache[(r, c)] = res
            return res

        for c in range(dim):
            self.res = min(self.res, helper(0, c))

        return self.res

# Use bottom-up approach for better memory
