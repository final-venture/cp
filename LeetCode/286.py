class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        inf = 2147483647
        rows = len(grid)
        cols = len(grid[0])
        
        q = deque()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append([r, c, 0])

        while q:
            cr, cc, count = q.popleft()
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dr, dc in directions:
                nr, nc = cr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] not in [0, -1]: #bug?
                    if grid[nr][nc] <= grid[cr][cc]: #change 2 ==
                        continue
                    grid[nr][nc] = count + 1
                    q.append([nr, nc, count+1])

# Model from HTH sajj
class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        inf = 2147483647
        rows = len(grid)
        cols = len(grid[0])
        
        q = deque()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append((r, c))

        while q:
            cr, cc = q.popleft()
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for dr, dc in directions:
                nr, nc = cr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == inf:
                    grid[nr][nc] = grid[cr][cc] + 1
                    q.append((nr, nc))
        
