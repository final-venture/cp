"""
    BRUTE FORCE: O(n * n!)
    Optimise n! => dp[curr, bit] could be max palindrome length 
        for a path visiting all bit
        max(dp[x, bit] for x in range(n) and all b bits)
    TC: O(n^2 * 2^n) ~ 10^6
"""
class Solution:
    def maxLen(self, n: int, edges: List[List[int]], label: str) -> int:
        adj = [set() for i in range(n)]
        full_mask = (1 << n) - 1
        for u, v in edges:
            adj[u].add(v)
            adj[v].add(u)
        char2nodes = defaultdict(list)
        for i in range(n):
            char2nodes[label[i]].append(i)

        @cache
        def dfs(node1, node2, curr_mask):
            if node1 > node2:
                return dfs(node2, node1, curr_mask)
            if curr_mask == full_mask:
                return 0

            ret = 1
            curr_mask |= (1 << node1)
            curr_mask |= (1 << node2)

            for nodes in char2nodes.values():
                for i in range(len(nodes)):
                    nei1 = nodes[i]
                    if curr_mask & (1 << nei1):
                        continue
                    for j in range(i + 1, len(nodes)):
                        nei2 = nodes[j]
                        if curr_mask & (1 << nei2):
                            continue
                        if (nei1 in adj[node1] and nei2 in adj[node2]) or (nei1 in adj[node2] and nei2 in adj[node1]):
                            ret = max(ret, 2 + dfs(nei1, nei2, curr_mask))
            return ret

        maxx = 1
        for i in range(n):
            for j in range(n):
                if i == j:
                    maxx = max(maxx, dfs(i, j, 0))
                elif label[i] == label[j] and j in adj[i]:
                    maxx = max(maxx, 1 + dfs(i, j, 0))

        return maxx

        # def checkPalindrome(self, s):
        #     l, r = 0, len(s) - 1
        #     while l < r:
        #         if s[l] != s[r]:
        #             return 0
        #         l += 1
        #         r -= 1
        #     return len(s)

        # adj = [[] for _ in range(n)]
        # for u, v in edges:
        #     if v not in adj[u]:
        #         adj[u].append(v)
        #     if u not in adj[v]:
        #         adj[v].append(u)
        
        # full_mask = (1 << n) - 1

        # memo = [[-1] * (full_mask + 2) for i in range(15)]
        # def dfs(node, curr_mask, string):
        #     if (1 << node) & curr_mask:
        #         return 0
        #     if memo[node][curr_mask] != -1:
        #         return memo[node][curr_mask]
        #     curr_mask |= (1 << node)
        #     string += label[node]
        #     ret = self.checkPalindrome(string)
        #     for nei in adj[node]:
        #         ret = max(ret, dfs(nei, curr_mask, string))
        #     memo[node][curr_mask] = ret
        #     return ret

        # maxx = 0
        # for i in range(n):
        #     maxx = max(dfs(i, 0, ""), maxx)
        # return maxx
