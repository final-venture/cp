class Solution {
private:
    vector<int> seg;
public:
    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = INT_MIN;
            return;
        }
        int m = l + (r - l) / 2;
        build(idx * 2 + 1, l, m);
        build(idx * 2 + 2, m + 1, r);
        seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    int query(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (qr < l || r < ql)
        {
            return INT_MIN;
        }
        int m = l + (r - l) / 2;
        int left = query(idx * 2 + 1, l, m, ql, qr);
        int right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return max(left, right);
    }

    int update(int idx, int l, int r, int t, int v)
    {
        if (l == r && r == t)
        {
            seg[idx] = v;
            return seg[idx];
        }
        if (l > t || r < t)
        {
            return seg[idx];
        }
        int m = l + (r - l) / 2;
        int left = update(idx * 2 + 1, l, m, t, v);
        int right = update(idx * 2 + 2, m + 1, r, t, v);
        return seg[idx] = max(left, right);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        seg.resize(4 * n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = nums[i] - i;
        }
        vector<int> sorted(a.begin(), a.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> n2fi;
        for (int i = 0; i < n; ++i)
        {
            n2fi[sorted[i]] = i;
        }
        unordered_map<int, int> cnt;
        build(0, 0, n - 1);
        for (int i = 0; i < n; ++i)
        {
            int add = 0;
            if (n2fi[nums[i]] >= 0)
            {
                add = query(0, 0, n - 1, 0, n2fi[nums[i]] + cnt[nums[i]] - 1); // add oob process
            }
            update(0, 0, n - 1, n2fi[nums[i]] + cnt[nums[i]], max(a[i], add + a[i]));
            ++cnt[nums[i]];
        }
        int ret = query(0, 0, n - 1, 0, n - 1);
        return ret;
    }
};
