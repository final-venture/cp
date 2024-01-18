class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root

        for i in range(len(word)):
            if not curr.children.get(word[i]):
                curr.children.update({word[i]: TrieNode()})
            curr = curr.children[word[i]]

        curr.isWord = True

    def search(self, word: str) -> bool:
        curr = self.root

        for i in range(len(word)):
            if not curr.children.get(word[i]):
                return False
            curr = curr.children[word[i]]

        if curr.isWord:
            return True

        return False

    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for i in range(len(prefix)):
            if not curr.children.get(prefix[i]):
                return False
            curr = curr.children[prefix[i]]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)