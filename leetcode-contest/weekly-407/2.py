class Solution:
    def doesAliceWin(self, s: str) -> bool:
        vowels = set(["a", "e", "i", "o", "u"])
        vc = 0
        for c in s:
            if c in vowels:
                vc += 1
        
        if vc:
            return True
        else:
            return False
