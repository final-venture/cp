class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        root = ListNode(word[0])
        curr = root

        if rows == 1 and cols == 1 and board[0][0] == word:
            return True

        self.res = False
        self.seen = set()

        for i in range(1, len(word)):
            curr.next = ListNode(word[i])
            curr = curr.next

        def helper(r, c, curr):
            if self.res == True:
                return
            
            if not curr:
                self.res = True
                return

            if (r, c) in self.seen:
                return

            if board[r][c] == curr.val:
                if r > 0:
                    self.seen.add((r, c))
                    helper(r-1, c, curr.next)
                    self.seen.remove((r, c))
                if r < rows - 1:
                    self.seen.add((r, c))
                    helper(r+1, c, curr.next)
                    self.seen.remove((r, c))
                if c > 0:
                    self.seen.add((r, c))
                    helper(r, c-1, curr.next)
                    self.seen.remove((r, c))
                if c < cols - 1:
                    self.seen.add((r, c))
                    helper(r, c+1, curr.next)
                    self.seen.remove((r, c))

            return

        for r in range(rows):
            for c in range(cols):
                helper(r, c, root)

        return self.res
