class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        MOD = 10**9 + 7

        y2x = defaultdict(list)
        for x, y in points:
            y2x[y].append(x)

        cnt_sted = defaultdict(int)
        for k, v in y2x.items():
            sz = len(v)
            cnt_sted[k] = (sz * (sz - 1)) // 2

        ret = 0
        cnts = list(cnt_sted.values())
        sfx_sum = [0] * (len(cnts) + 1)
        for i in range(len(cnts) - 1, -1, -1):
            sfx_sum[i] = sfx_sum[i + 1] + cnts[i]
#print(sfx_sum)
#print(cnts)
        for i in range(len(cnts) - 1):
            ret += cnts[i] * sfx_sum[i + 1]
            ret %= MOD

        return ret
