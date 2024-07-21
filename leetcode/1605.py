class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        res = []
        rows, cols = len(rowSum), len(colSum)
        for r in range(rows):
            cand = []
            for c in range(cols):
                to_append = min(rowSum[r], colSum[c])
                cand.append(to_append)
                rowSum[r] -= to_append
                colSum[c] -= to_append
            res.append(cand)

        return res
