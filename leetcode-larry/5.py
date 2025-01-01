class Solution:
    def longestPalindrome(self, s: str) -> str:
        ll, lr = 0, 0
        for i in range(len(s)):
            l = r = i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            if r - l - 2 > lr - ll:
                ll, lr = l+1, r-1
            
            l, r = i, i+1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            if r - l - 2 > lr - ll:
                ll, lr = l+1, r-1
        
        return s[ll:lr+1]
