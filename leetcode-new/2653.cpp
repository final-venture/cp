// Binary Search on Segment Tree O(n log max(nums))
class Solution {
private:
    vector<int> seg;
public:
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

    int query(int idx, int l, int r, int x)
    {
        if (l == r)
        {
            if (seg[idx] >= x) return l;
            return 155;
        }
        int m = l + (r - l) / 2;
        int left = idx * 2 + 1;
        if (seg[left] >= x) return query(left, l, m, x);
        int right = idx * 2 + 2;
        return query(right, m + 1, r, x - seg[left]);
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
        return seg[idx] = left + right;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        seg.resize(404);
        build(0, 0, 100);
        for (int i = 0; i < k - 1; ++i)
        {
            update(0, 0, 100, nums[i] + 50, 1);
        }
        vector<int> ret;
        for (int i = k - 1; i < n; ++i)
        {
            update(0, 0, 100, nums[i] + 50, 1);
            int cand = query(0, 0, 100, x);
            cand -= 50;
            ret.push_back(min(cand, 0));
            update(0, 0, 100, nums[i - k + 1] + 50, -1);
        }
        return ret;
    }
};

// Brute force O(n * max(nums))
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int dp[105];
        memset(dp, 0, sizeof(dp));
        vector<int> ret;
        int l = 0, r = 0;
        while (r - l < k - 1)
        {
            ++dp[nums[r] + 50];
            ++r;
        }
        while (r < n)
        {
            // cout << "exe" << '\n';
            ++dp[nums[r] + 50];
            ++r;
            int cnt = 0;
            for (int i = 0; i < 50; ++i)
            {
                cnt += dp[i];
                if (cnt >= x)
                {
                    ret.push_back(i - 50);
                    break;
                }
            }
            if (cnt < x) ret.push_back(0);
            --dp[nums[l] + 50];
            ++l;
        }
        return ret;
    }
};
