class SegmentTree:
    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.arr = nums
        self.seg = [0] * (4 * self.n)
        self.build(0, 0, self.n - 1)

    def build(self, idx, l, r):
        if l == r:
            self.seg[idx] = self.arr[l]
            return
        m = l + (r - l) // 2
        self.build(idx * 2 + 1, l, m)
        self.build(idx * 2 + 2, m + 1, r)
        self.seg[idx] = self.seg[idx * 2 + 1] + self.seg[idx * 2 + 2]

    def update(self, idx, l, r, t, v):
        if l == r and r == t:
            self.seg[idx] = v
            return
        if r < t or t < l:
            return
        m = l + (r - l) // 2
        self.updater(idx * 2 + 1, l, m, t, v)
        self.updater(idx * 2 + 2, m + 1, r, t, v)
        self.seg[idx] = self.seg[idx * 2 + 1] + self.seg[idx * 2 + 2]

    def query(self, idx, l, r, ql, qr):
        if ql <= l and r <= qr:
            return self.seg[idx]
        if r < ql or l > qr:
            return 0
        m = l + (r - l) // 2
        left = self.query(idx * 2 + 1, l, m, ql, qr)
        right = self.query(idx * 2 + 2, m + 1, r, ql, qr)
        return left + right
