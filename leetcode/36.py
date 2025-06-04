class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            occurrences = [0] * 9
            for number in row:
                if number == ".":
                    continue
                occurrences[int(number)-1] += 1
            for p in range(2, 10):
                if p in occurrences:
                    return False
        
        for col in range(9):
            occurrences = [0] * 9
            for row in range(9):
                number = board[row][col]
                if number == ".":
                    continue
                occurrences[int(number)-1] += 1
            for p in range(2, 10):
                if p in occurrences:
                    return False

        for i in range(0, 7, 3):
            for j in range(0, 7, 3):
                occurrences = [0] * 9
                for k in range(3):
                    for l in range(3):
                        number = board[k+i][j+l]
                        if number == ".":
                            continue
                        occurrences[int(number)-1] += 1
                for p in range(2, 10):
                    if p in occurrences:
                        return False
        
        return True
