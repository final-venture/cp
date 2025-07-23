class Solution:
    def popcountDepth(self, n: int, k: int) -> int:
        if k == 0:
            return 1
        pcd = [0] * 65
        for i in range(2, 65):
            popcnt = i.bit_count()
            pcd[i] = 1 + pcd[popcnt]

        s = []
        ok = False
        for i in range(64, -1, -1):
            if (n >> i) & 1:
                ok = True
            if ok:
                s.append((n >> i) & 1)

        # print(s)

        @cache
        def dfs(idx, rem_bits, tight):
            if rem_bits < 0:
                return 0
            if idx >= len(s) and rem_bits == 0:
                return 1
            if idx >= len(s):
                return 0
            
            ret = 0
            limit = s[idx] if tight else 1
            for i in range(limit + 1):
                newTight = tight and (i == s[idx])
                ret += dfs(idx + 1, rem_bits - i, newTight)
            return ret
            
        ret = 0
        for avail_bits in range(1, 65):
            if pcd[avail_bits] == k - 1:
                ret += dfs(0, avail_bits, 1)
                if avail_bits == 1:
                    ret -= 1
        
        return ret
