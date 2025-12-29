class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        letters = "ABCDEF"
        b2v = defaultdict(list)
        for a in allowed:
            b2v[a[:-1]].append(a[-1])

        def getPerms(layer, prev, perms, curr_perm):
            if (layer <= 0):
                perms.append(curr_perm)
                return
                
            idx = len(curr_perm)
            b = prev[idx] + prev[idx+1]
            for v in b2v[b]:
                getPerms(layer - 1, prev, perms, curr_perm + v)

        @cache
        def dfs(layer, prev):
            if layer <= 0:
                return True
            perms = []
            getPerms(layer, prev, perms, "")

            for perm in perms:
                if dfs(layer - 1, perm):
                    return True

            return False

        return dfs(len(bottom) - 1, bottom)
