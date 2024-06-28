class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        self.rows, self.cols = len(board), len(board[0])
        self.seen = set()

        def dfs(cr, cc):
            if board[cr][cc] == "X" or (cr, cc) in self.seen:
                return
            self.seen.add((cr, cc))
            for dr, dc in self.directions:
                nr, nc = cr + dr, cc + dc
                if 0 <= nr < self.rows and 0 <= nc < self.cols:
                    dfs(nr, nc)

        for r in range(self.rows):
            dfs(r, 0)
            dfs(r, self.cols-1)
        for c in range(self.cols):
            dfs(0, c)
            dfs(self.rows-1, c)

        for r in range(self.rows):
            for c in range(self.cols):
                if (r, c) not in self.seen:
                    board[r][c] = "X"
