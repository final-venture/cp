class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        append_count = 0
        pop_remaining = 0
        res = 0
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        rows, cols = len(grid), len(grid[0])
        q = deque()
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    q.append((i, j))
                    pop_remaining += 1

        while q:
            cr, cc = q.popleft()
            if pop_remaining == 0:
                pop_remaining = append_count
                append_count = 0
                res += 1
            pop_remaining -= 1
            for dr, dc in directions:
                nr, nc = cr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    q.append((nr, nc))
                    append_count += 1
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    return -1
        
        return res
