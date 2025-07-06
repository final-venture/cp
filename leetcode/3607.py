class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(c + 1)]
        seen = [0] * (c + 1)
        for u, v in connections:
            adj[u].append(v)
            adj[v].append(u)

        def dfs(node):
            if seen[node]:
                return
            seen[node] = 1
            cand.add(node)
            s2cc[node] = curr_cc
            for nei in adj[node]:
                dfs(nei)

        s2cc = [0] * (c + 1)
        curr_cc = 0
        cc = []
        for i in range(1, c + 1):
            cand = SortedList()
            dfs(i)
            cc.append(cand)
            curr_cc += 1

        ret = []
        for op, node in queries:
            if op == 1:
                if not len(cc[s2cc[node]]):
                    ret.append(-1)
                elif node in cc[s2cc[node]]:
                    ret.append(node)
                else:
                    ret.append(cc[s2cc[node]][0])
            else:
                if node in cc[s2cc[node]]:
                    cc[s2cc[node]].remove(node)
        
        return ret
