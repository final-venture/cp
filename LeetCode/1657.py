class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        a = defaultdict(int)
        b = defaultdict(int)
        if len(word1) != len(word2):
            return False

        for i in range(len(word1)):
            a[word1[i]] += 1
        
        for i in range(len(word2)):
            b[word2[i]] += 1

        if a.keys() != b.keys():
            return False

        if Counter(b.values()) != Counter(a.values()):
            return False

        return True
        
# Better Solution:
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        return set(word1) == set(word2) and Counter(Counter(word1).values()) == Counter(Counter(word2).values())
