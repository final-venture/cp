class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def helper(r, c, node, chars=""):
            if (r, c) in self.seen:
                return

            if board[r][c] in node.children:
                char = board[r][c]
                nxt = node.children[char]
                self.seen.add((r, c))

                if r > 0:
                    helper(r - 1, c, nxt, chars+char)
                if r < self.rows - 1:
                    helper(r + 1, c, nxt, chars+char)
                if c > 0:
                    helper(r, c - 1, nxt, chars+char)
                if c < self.cols - 1:
                    helper(r, c + 1, nxt, chars+char)

                if nxt.isWord:
                    self.res.add(chars+char)
                self.seen.remove((r, c))

            return

        self.root = TrieNode()
        self.res = set()
        self.rows = len(board)
        self.cols = len(board[0])
        self.seen = set()

        for word in words:
            self.curr = self.root
            for char in word:
                if char not in self.curr.children:
                    self.curr.children[char] = TrieNode()
                self.curr = self.curr.children[char]
            self.curr.isWord = True
        
        for r in range(self.rows):
            for c in range(self.cols):
                helper(r, c, self.root)

        return list(self.res)
