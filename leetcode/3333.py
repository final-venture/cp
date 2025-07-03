import sys
sys.setrecursionlimit(10**8)

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        MOD = 10**9 + 7
        n = len(word)
        curr = 0
        lst = word[0]
        runs = []
        for i in range(n):
            if word[i] != lst:
                runs.append(curr)
                curr = 0
                lst = word[i]
            curr += 1
        runs.append(curr)

        @cache
        def dfs(idx, rem):
            if rem < len(runs) - idx:
                return 0
            if idx >= len(runs):
                return 1

            total = (dfs(idx, rem - 1) +
                   dfs(idx + 1, rem - 1) -
                   dfs(idx + 1, rem - 1 - runs[idx]))

            return total % MOD

        all_ways = 1
        for x in runs:
            all_ways *= x
            if (all_ways > MOD):
                all_ways %= MOD

        ret = (all_ways - dfs(0, k - 1)) % MOD
        dfs.cache_clear()

        return ret
