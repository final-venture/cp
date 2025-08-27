class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        directions = [(-1, -1), (-1, 1), (1, 1), (1, -1), (-1, -1)]
        def valid(r, c, next_num):
            if r >= n or r < 0 or c >= m or c < 0:
                return False
            if grid[r][c] == next_num:
                return True
            return False

        @cache
        def dfs(r, c, dir_idx, turned):
            # print(r, c)
            ret = 1
            dr, dc = directions[dir_idx]
            nr, nc = r + dr, c + dc
            next_num = -1
            if grid[r][c] == 1:
                next_num = 2
            else:
                next_num = grid[r][c] ^ 2
            if valid(nr, nc, next_num):
                ret = max(ret, 1 + dfs(nr, nc, dir_idx, turned))
                if not turned:
                    ret = max(ret, 1 + dfs(nr, nc, dir_idx + 1, 1))
            return ret

        # return dfs(0, 2, 2, 0)

        maxx = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    for idx in range(0, 4):
                        maxx = max(dfs(i, j, idx, 0), maxx)
        
        return maxx
