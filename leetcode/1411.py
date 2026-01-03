class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        
        @cache
        def dfs(idx, up1, up2, up3):
            if idx >= n:
                return 1
            ret = 0
            for i in range(3):
                if up1 == i:
                    continue
                for j in range(3):
                    if up2 == j or j == i:
                        continue
                    for k in range(3):
                        if up3 == k or k == j:
                            continue
                        ret += dfs(idx + 1, i, j, k)
                        ret %= MOD
            return ret

        return dfs(0, -1, -1, -1)
