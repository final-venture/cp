class Solution {
private:
    vector<int> seg;
public:
    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = -1;
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
            return -1;
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

    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        seg.resize(4 * n);
        vector<pair<int, int>> sorted1(n), sorted2(n);
        vector<int> summ(n);

        // Prepare sorted1 and sorted2 with original indices
        for (int i = 0; i < n; ++i)
        {
            sorted1[i] = {nums1[i], i};
            sorted2[i] = {nums2[i], i};
            summ[i] = nums1[i] + nums2[i];
        }
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());

        build(0, 0, n - 1);

        int nn = queries.size();
        vector<pair<pair<int, int>, int>> sortedq(nn);
        for (int i = 0; i < nn; ++i)
        {
            sortedq[i] = {{queries[i][0], queries[i][1]}, i};
        }
        sort(sortedq.begin(), sortedq.end(), greater<>());

        int curr = n - 1;
        vector<int> ret(nn);
        for (int i = 0; i < nn; ++i)
        {
            auto& [q, qi] = sortedq[i];
            int x = q.first, y = q.second;

            // Update segment tree for elements >= x in nums1
            while (curr >= 0 && sorted1[curr].first >= x)
            {
                int idxx = sorted1[curr].second; // Original index
                int pos = lower_bound(sorted2.begin(), sorted2.end(), make_pair(nums2[idxx], idxx)) - sorted2.begin(); // Get sorted2 corresponding idx. This is because the segtree is built based on sorted2 indexes.
                update(0, 0, n - 1, pos, summ[idxx]);
                --curr;
            }

            // Query for range [idx2, n - 1] where nums2 >= y
            int idx2 = lower_bound(sorted2.begin(), sorted2.end(), make_pair(y, -1)) - sorted2.begin();
            ret[qi] = (idx2 < n) ? query(0, 0, n - 1, idx2, n - 1) : -1;
        }

        return ret;
    }

};
