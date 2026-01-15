class Solution:
    def countBalanced(self, low: int, high: int) -> int:
        @cache
        def dfs(idx, tight, diff_sum):
            if idx >= len(limit):
                if not diff_sum:
                    return 1
                else:
                    return 0
            if abs(diff_sum) > 72:
                return 0
            ret = 0
            ub = int(limit[idx]) if tight else 9
            for i in range(ub + 1):
                new_tight = tight and i == ub
                new_diff_sum = diff_sum + i if idx & 1 else diff_sum - i
                ret += dfs(idx + 1, new_tight, new_diff_sum)
            return ret

        global limit
        limit = str(high)
        hi = dfs(0, 1, 0)
        dfs.cache_clear()

        limit = str(low - 1)
        lo = dfs(0, 1, 0)
        dfs.cache_clear()

        return hi - lo
