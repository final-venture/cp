class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.res = []
        board = [["." for _ in range(n)] for _ in range(n)]
        bl_c = set()
        bl_dp = set()
        bl_dn = set()

        def dfs(r):
            if r == n:
                self.res.append([''.join(board[i]) for i in range(n)])
                return
            for c in range(n):
                dp = r + c
                dn = r - c
                if c in bl_c or dp in bl_dp or dn in bl_dn:
                    continue
                board[r][c] = "Q"
                bl_c.add(c)
                bl_dp.add(dp)
                bl_dn.add(dn)
                dfs(r + 1)
                board[r][c] = "."
                bl_c.remove(c)
                bl_dp.remove(dp)
                bl_dn.remove(dn)

        dfs(0)

        return self.res
