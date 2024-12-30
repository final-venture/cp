class Solution {
private:
    vector<pair<int, int>> seg;
public:
    pair<int, int> merge(pair<int, int>& p1, pair<int, int>& p2)
    {
        if (p1.first == p2.first)
        {
            if (p1.first == 0) return {0, 1};
            return {p1.first, p1.second + p2.second};
        }
        return max(p1, p2);
    }

    pair<int, int> query(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (qr < l || r < ql)
        {
            return { -1, 0};
        }
        int m = l + (r - l) / 2;
        pair<int, int> left = query(idx * 2 + 1, l, m, ql, qr);
        pair<int, int> right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return merge(left, right);
    }

    pair<int, int> update(int idx, int l, int r, int t, pair<int, int> v)
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
        pair<int, int> left = update(idx * 2 + 1, l, m, t, v);
        pair<int, int> right = update(idx * 2 + 2, m + 1, r, t, v);
        return seg[idx] = merge(left, right);
    }
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        seg.resize(4 * n, {0, 1});
        vector<int> sorted(a.begin(), a.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> n2fi;
        for (int i = n - 1; i >= 0; --i)
        {
            n2fi[sorted[i]] = i;
        }
        unordered_map<int, int> cnt;

        for (int i = 0; i < n; ++i)
        {
            pair<int, int> cand = {1, 1};
            if (n2fi[a[i]] > 0)
            {
                cand = query(0, 0, n - 1, 0, n2fi[a[i]] - 1);
                ++cand.first;
            }
            update(0, 0, n - 1, n2fi[a[i]] + cnt[a[i]], cand);
            ++cnt[a[i]];
        }
        pair<int, int> ret = query(0, 0, n - 1, 0, n - 1);
        return ret.second;
    }
};
