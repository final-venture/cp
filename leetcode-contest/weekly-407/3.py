class Solution:
    def maxOperations(self, s: str) -> int:
        res = 0
        onec = 0

        for i in range(len(s) - 1):
            if s[i] == "1":
                onec += 1
                if s[i + 1] == "0":
                    res += onec
        
        return res
