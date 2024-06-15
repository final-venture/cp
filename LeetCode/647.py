# 1
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0

        self.count = 1

        def dfs(i):
            if i + 1 < len(s) and int(s[i+1]) != 0:
                if int(s[i]) == 1:
                    self.count += 1
                if int(s[i]) == 2 and 0 < int(s[i+1]) < 7:
                    self.count += 1
                dfs(i+1)
            
        dfs(0)
        return self.count

# 2
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0

        i = len(s) - 1
        res = 1

        while i > 0:
            if s[i] != "0":
                if int(s[i-1]) == 1:
                    res += 1
                if int(s[i-1]) == 2 and int(s[i]) < 7:
                    res += 1
                i -= 1
            elif int(s[i-1]) == 0:
                return 0
            else:
                i -= 2

        return res

# 3
class Solution:
    def numDecodings(self, s: str) -> int:
        self.count = 0

        def dfs(i):
            if i >= len(s):
                self.count += 1
                return
            if s[i] == "0":
                return
            if i + 1 < len(s):
                if int(s[i]) == 1:
                    dfs(i+2)
                if int(s[i]) == 2 and int(s[i+1]) < 7:
                    dfs(i+2)
            dfs(i+1)

        dfs(0)
        return self.count

# 4
class Solution:
    def numDecodings(self, s: str) -> int:
        memo = {}

        def dfs(i):
            if i in memo:
                return memo[i]
            else:
                if i >= len(s):
                    return 1
                elif s[i] == "0":
                    return 0
                res = dfs(i+1)
                if i + 1 < len(s):
                    if int(s[i]) == 1 or (int(s[i]) == 2 and int(s[i+1]) < 7):
                        res += dfs(i+2)
                        
                memo[i] = res
                return res

        return dfs(0)
