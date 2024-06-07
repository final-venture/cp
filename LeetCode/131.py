class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        def dfs(i, cand):
            if i == len(s):
                res.append(cand)
                return

            for j in range(i, len(s)):
                if self.isPalindrome(s, i, j):
                    dfs(j+1, cand+[s[i:j+1]])
            
            return

        dfs(0, [])
        return res

    def isPalindrome(self, s, i, j):
        while i < j:
            if s[i] == s[j]:
                i += 1
                j -= 1
            else:
                return False
            
        return True
