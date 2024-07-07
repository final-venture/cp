class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        dp_row = [[[0, 0] for _ in range(cols)] for _ in range(rows)]
        dp_full = [[[0, 0] for _ in range(cols)] for _ in range(rows)]
        
        for r in range(rows):
            if grid[r][0] == "X":
                dp_row[r][0][0] += 1
            if grid[r][0] == "Y":
                dp_row[r][0][1] += 1
            for c in range(1, cols):
                dp_row[r][c][0], dp_row[r][c][1] = dp_row[r][c-1][0], dp_row[r][c-1][1]
                if grid[r][c] == "X":
                    dp_row[r][c][0] += 1
                if grid[r][c] == "Y":
                    dp_row[r][c][1] += 1
            
        for c in range(cols):
            dp_full[0][c] = dp_row[0][c].copy()
        for r in range(1, rows):
            dp_full[r][0] = [dp_full[r-1][0][0] + dp_row[r][0][0], dp_full[r-1][0][1] + dp_row[r][0][1]]

        for r in range(1, rows):
            for c in range(1, cols):
                dp_full[r][c][0], dp_full[r][c][1] = (dp_full[r-1][c][0] + dp_row[r][c][0]), dp_full[r-1][c][1] + dp_row[r][c][1]

        res = 0
        for r in range(rows):
            for c in range(cols):
                if dp_full[r][c][0] > 0 and dp_full[r][c][0] == dp_full[r][c][1]:
                    res += 1
        
        return res
