class SegmentTree:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.arr = nums[:]
        self.seg = [Counter() for _ in range(4 * self.n)]
        self.build(0, 0, self.n - 1)

    def build(self, idx, l, r):
        if l == r:
            self.seg[idx][self.arr[l]] += 1
            return
        m = l + (r - l) // 2
        self.build(idx * 2 + 1, l, m)
        self.build(idx * 2 + 2, m + 1, r)
        self.seg[idx] = self.seg[idx * 2 + 1] + self.seg[idx * 2 + 2]

    def update(self, idx, l, r, t, v):
        if l == r and r == t:
            self.seg[idx][self.arr[l]] -= 1
            self.seg[idx][v] += 1
            self.arr[l] = v
            return
        if r < t or t < l:
            return
        m = l + (r - l) // 2
        self.update(idx * 2 + 1, l, m, t, v)
        self.update(idx * 2 + 2, m + 1, r, t, v)
        self.seg[idx] = self.seg[idx * 2 + 1] + self.seg[idx * 2 + 2]

    def query(self, idx, l, r, ql, qr, v):
        if ql <= l and r <= qr:
            return self.seg[idx][v]
        if r < ql or l > qr:
            return 0
        m = l + (r - l) // 2
        left = self.query(idx * 2 + 1, l, m, ql, qr, v)
        right = self.query(idx * 2 + 2, m + 1, r, ql, qr, v)
        return left + right

class Solution:
    def popcountDepth(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        pcd = [-1] * 31 # cache popcnt 1 to 30
        
        def getPCD(x):
            curr_pcd = 0
            while x > 1:
                if x <= 30 and pcd[x] != -1:
                    return curr_pcd + pcd[x]
                x = x.bit_count()
                curr_pcd += 1
            return curr_pcd

        for i in range(31):
            pcd[i] = getPCD(i)

        nums_pcd = [0] * n
        for i in range(n):
            nums_pcd[i] = getPCD(nums[i])

        seg = SegmentTree(nums_pcd)
        ret = []
        for q in queries:
            if q[0] == 1:
                _, ql, qr, v = q
                ans = seg.query(0, 0, n - 1, ql, qr, v)
                ret.append(ans)
            else:
                _, t, v = q
                new_popcnt = getPCD(v)
                seg.update(0, 0, n - 1, t, new_popcnt)

        return ret
