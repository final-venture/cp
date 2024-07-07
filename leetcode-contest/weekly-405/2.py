class Solution:
    def validStrings(self, n: int) -> List[str]:
        self.res = []
        def dfs(n, cand):
            if not n:
                self.res.append(cand)
                return
            if cand and cand[-1] == "0":
                dfs(n-1, cand+"1")
            else:
                dfs(n-1, cand+"1")
                dfs(n-1, cand+"0")
            return

        dfs(n, "")
        return self.res
