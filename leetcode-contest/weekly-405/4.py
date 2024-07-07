class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False
        self.cost = inf

class Solution:
    def minimumCost(self, target: str, words: List[str], costs: List[int]) -> int:
        root = TrieNode()
        for word, cost in zip(words, costs):
            curr = root
            for c in word:
                if c not in curr.children:
                    curr.children[c] = TrieNode()
                curr = curr.children[c]
            curr.end = True
            curr.cost = min(cost, curr.cost)
        
        @cache
        def dp(i):
            if i == len(target):
                return 0

            curr = root
            res = inf
            for j in range(i, len(target)):
                c = target[j]
                if c not in curr.children:
                    break
                curr = curr.children[c]
                if curr.end:
                    res = min(res, curr.cost + dp(j + 1))
            return res

        result = dp(0)
        return result if result != inf else -1 
