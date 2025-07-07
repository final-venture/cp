class Solution:
    def minTime(self, n: int, edges: List[List[int]], k: int) -> int:
        def check(t):
            adj = [[] for _ in range(n)]
            for u, v, time in edges:
                if time > t:
                    adj[u].append(v)
                    adj[v].append(u)
            seen = [0] * n
            cc_cnt = 0

            def dfs(node):
                if seen[node]:
                    return
                seen[node] = 1
                for nei in adj[node]:
                    dfs(nei)

            for i in range(n):
                if seen[i]:
                    continue
                dfs(i)
                cc_cnt += 1
            
            return cc_cnt >= k
        
        lo, hi = 0, int(2e9)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if check(mid):
                hi = mid
            else:
                lo = mid + 1
        
        return lo
