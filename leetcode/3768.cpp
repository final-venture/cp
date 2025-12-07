class Solution
{
private:
    vector<int> seg;
    int n;
    void update(int idx, int l, int r, int t, int v)
    {
        if (l == r && r == t)
        {
            seg[idx] += v;
            return;
        }
        if (r < t || l > t)
        {
            return;
        }
        int m = l + (r - l) / 2;
        update(idx * 2 + 1, l, m, t, v);
        update(idx * 2 + 2, m + 1, r, t, v);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }
    int query(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (r < ql || l > qr)
        {
            return 0;
        }
        int m = l + (r - l) / 2;
        int left = query(idx * 2 + 1, l, m, ql, qr);
        int right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return left + right;
    }

public:
    long long minInversionCount(vector<int> &nums, int k)
    {
        n = nums.size();
        vector<int> numsCopy(nums.begin(), nums.end());
        sort(numsCopy.begin(), numsCopy.end());
        numsCopy.erase(unique(numsCopy.begin(), numsCopy.end()), numsCopy.end());
        int nn = numsCopy.size();
        unordered_map<int, int> compress;
        int timer = 0;
        for (int i = 0; i < nn; ++i)
        {
            compress[numsCopy[i]] = timer++;
        }
        seg.resize(4 * n, 0);

        long long ret = LLONG_MAX;
        long long cand = 0;

        for (int i = 0; i < k; ++i)
        {
            int compressed = compress[nums[i]];
            update(0, 0, n - 1, compressed, 1);
            if (compressed + 1 <= n - 1)
            {
                cand += query(0, 0, n - 1, compressed + 1, n - 1);
            }
        }
        ret = min(ret, cand);

        for (int i = k; i < n; ++i)
        {
            int toRemove = compress[nums[i - k]];
            int toInsert = compress[nums[i]];
            if (toRemove - 1 >= 0)
            {
                cand -= query(0, 0, n - 1, 0, toRemove - 1);
            }
            update(0, 0, n - 1, toRemove, -1);
            if (toInsert + 1 <= n - 1)
            {
                cand += query(0, 0, n - 1, toInsert + 1, n - 1);
            }
            update(0, 0, n - 1, toInsert, 1);
            ret = min(ret, cand);
        }

        return ret;
    }
};
