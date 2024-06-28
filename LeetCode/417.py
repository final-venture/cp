class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        res = []
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        rows, cols = len(heights), len(heights[0])
        q = deque()
        seenp = set()
        seena = set()

        for c in range(cols):
            seenp.add((0, c))
            seena.add((rows-1, c))
        for r in range(rows):
            seenp.add((r, 0))
            seena.add((r, cols-1))
        
        q += seenp
        while q:
            cr, cc = q.popleft()

            for dr, dc in directions:
                nr, nc = cr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols and heights[nr][nc] >= heights[cr][cc] and (nr, nc) not in seenp:
                    seenp.add((nr, nc))
                    q.append((nr, nc))

        q += seena
        while q:
            cr, cc = q.popleft()
            if (cr, cc) in seenp:
                res.append([cr, cc])
            for dr, dc in directions:
                nr, nc = cr + dr, cc + dc
                if 0 <= nr < rows and 0 <= nc < cols and heights[nr][nc] >= heights[cr][cc] and (nr, nc) not in seena:
                    
                    seena.add((nr, nc))
                    q.append((nr, nc))

        return res
        