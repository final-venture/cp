class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def helper(r, c, node, chars="", visited=set()):
            if board[r][c] in node.children:
                char = board[r][c]
                nxt = node.children[char]
                
                if (r, c) not in visited:
                    if r > 0 and helper(r - 1, c, nxt, chars+char, visited):
                        return
                    if r < self.rows - 1 and helper(r + 1, c, nxt, chars+char, visited):
                        return
                    if c > 0 and helper(r, c - 1, nxt, chars+char, visited):
                        return
                    if c < self.cols - 1 and helper(r, c + 1, nxt, chars+char, visited):
                        return

                    if nxt.isWord:
                        self.res.add(chars+char)
                        return True
                
                visited.add((r, c))
            return

        self.root = TrieNode()
        self.res = set()
        self.rows = len(board)
        self.cols = len(board[0])

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
