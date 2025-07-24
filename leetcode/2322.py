class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        # [1, 3, 4, 4, 3, 0, 0, 2, 2, 1]
        # [1, 3, 4, 4, 3, 0, 0, 2, 5, 5, 2, 1]
        n = len(nums)
        adj = [[] for i in range(n)]
        tour_in = [-1] * n
        tour_out = [-1] * n
        subtree_xor = [-1] * n
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        timer = [0]
        def dfs(node, par):
            tour_in[node] = timer[0]
            timer[0] += 1
            ret = nums[node]
            for nei in adj[node]:
                if nei == par:
                    continue
                ret ^= dfs(nei, node)
            tour_out[node] = timer[0]
            subtree_xor[node] = ret
            return ret

        dfs(0, -1)

        ret = 10**9
        all_xor = subtree_xor[0]
        for i in range(1, n):
            for j in range(i + 1, n):
                if tour_in[i] >= tour_out[j] or tour_in[j] >= tour_out[i]:
                    x1 = all_xor ^ subtree_xor[i] ^ subtree_xor[j]
                    x2 = subtree_xor[i]
                    x3 = subtree_xor[j]
                    xors = [x1, x2, x3]
                    xors.sort()
                    ret = min(ret, xors[-1] - xors[0])
                else:
                    top, bot = (i, j) if tour_in[i] < tour_in[j] else (j, i)
                    x1 = all_xor ^ subtree_xor[top]
                    x2 = subtree_xor[top] ^ subtree_xor[bot]
                    x3 = subtree_xor[bot]
                    xors = [x1, x2, x3]
                    xors.sort()
                    ret = min(ret, xors[-1] - xors[0])

        

        # print(tour_in)
        # print(tour_out)
        # print(subtree_xor)


        return ret