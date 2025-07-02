class Solution:
    def possibleStringCount(self, word: str) -> int:
        ret = 1
        cand = 1
        for i in range(1, len(word)):
            if word[i] == word[i - 1]:
                cand += 1
            else:
                ret += max(cand - 1, 0)
                cand = 1
        ret += max(cand - 1, 0)
        return ret
