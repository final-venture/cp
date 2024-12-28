// O(n) dp
class Solution
{
public:
    int lengthOfLIS(vector<int> &vec)
    {
        int n = vec.size();
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (vec[j] > vec[i])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// O(nlogn) binary search + greedy
class Solution
{
public:
    int lengthOfLIS(vector<int> &vec)
    {
        int n = vec.size();
        vector<int> cands;
        for (int x : vec)
        {
            if (cands.empty() || x > cands[cands.size() - 1])
            {
                cands.push_back(x);
            }
            else
            {
                auto it = lower_bound(cands.begin(), cands.end(), x);
                *it = x;
            }
        }
        return cands.size();
    }
};

// O(nlogn) segment tree (prefix queries)
class Solution {
public:
    vector<int> seg;
    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = 0;
            return;
        }
        int m = l + (r - l) / 2;
        build(idx * 2 + 1, l, m);
        build(idx * 2 + 2, m + 1, r);
        seg[idx] = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    }

    int query(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (qr < l || r < ql)
        {
            return 0;
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
            seg[idx] += v;
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

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n - 1);

        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> cnt;
        unordered_map<int, int> n2fi;

        for (int i = 0; i < n; ++i)
        {
            if (n2fi.find(sorted[i]) != n2fi.end()) continue;
            n2fi[sorted[i]] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            int cand = query(0, 0, n - 1, 0, n2fi[nums[i]] - 1);
            update(0, 0, n - 1, n2fi[nums[i]] + cnt[nums[i]], cand + 1);
            ++cnt[nums[i]];
        }
        return query(0, 0, n - 1, 0, n - 1);
    }
};

