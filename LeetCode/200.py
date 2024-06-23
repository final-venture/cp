class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.res = 0
        rows = len(grid)
        cols = len(grid[0])

        def dfs(r, c):
            if 0 <= r < rows and 0 <= c < cols:
                if grid[r][c] == "0":
                    return

                grid[r][c] = "0"
                dfs(r, c+1)
                dfs(r, c-1)
                dfs(r+1, c)
                dfs(r-1, c)

            return

        for x in range(rows):
            for y in range(cols):
                if grid[x][y] == "1":
                    dfs(x, y)
                    self.res += 1
            
        return self.res
