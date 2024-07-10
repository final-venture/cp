class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = r = len(s) - 1
        req = {}
        for x in t:
            if x not in req:
                req[x] = 0
            req[x] += 1

        count_req = len(req)

        res = ""

        while l >= 0:
            char = s[l]
            if char in req:
                req[char] -= 1
                if not req[char]:
                    count_req -= 1
            
            while not count_req:
                if not res or len(s[l:r+1]) < len(res):
                    res = s[l:r+1]
                if s[r] in req:
                    req[s[r]] += 1
                    if req[s[r]] > 0:
                        count_req += 1
                r -= 1
                
            l -= 1
        
        return res
