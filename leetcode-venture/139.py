class TrieNode():
    def __init__(self):
        self.children = {}
        self.isWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        curr = self.root

        for i in range(len(word)):
            if not curr.children.get(word[i]):
                curr.children.update({word[i]: TrieNode()})
            curr = curr.children[word[i]]
        
        curr.isWord = True

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie = Trie()
        
        for word in wordDict:
            trie.insert(word)

        dp = [False] * (len(s) + 1)
        dp[0] = True
        i = 0

        for i in range(len(s)):
            if not dp[i]:
                continue
            curr = trie.root
            for j in range(i, len(s)):
                if s[j] not in curr.children:
                    break
                curr = curr.children[s[j]]
                if curr.isWord:
                    dp[j+1] = True 

        return dp[len(s)]
