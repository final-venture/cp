class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        self.curr = 0
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        dr, dc = directions[self.curr]

        def turn():
            self.curr += 1
            if self.curr == 4:
                self.curr = 0
            
        res = []
        rows, cols = len(matrix), len(matrix[0])
        r, c = 0, 0

        while (0 <= r < rows and 0 <= c < cols) and matrix[r][c] != ".":
            res.append(matrix[r][c])
            matrix[r][c] = "."

            if (0 <= r+dr < rows) and (0 <= c+dc < cols):
                if matrix[r+dr][c+dc] == ".":
                    turn()
            else:
                turn()

            dr, dc = directions[self.curr]
            r, c = r + dr, c + dc

        return res
