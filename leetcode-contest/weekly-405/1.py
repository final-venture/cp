class Solution:
    def getEncryptedString(self, s: str, k: int) -> str:
        res = ""
        for i in range(len(s)):
            idx = (i + k) % len(s)
            res = res + s[idx] 
        
        return res
            