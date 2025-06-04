#define ll long long
class Solution {
private:
    vector<pair<ll, ll>> seg;
    vector<pair<ll, ll>> bounds;
public:
    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = bounds[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(idx * 2 + 1, l, mid);
        build(idx * 2 + 2, mid + 1, r);
        seg[idx].first = max(seg[idx * 2 + 1].first, seg[idx * 2 + 2].first);
        seg[idx].second = min(seg[idx * 2 + 1].second, seg[idx * 2 + 2].second);
    }
    pair<ll, ll> query(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (ql > r || qr < l)
        {
            return { -100, 1e10};
        }
        int mid = l + (r - l) / 2;
        pair<int, int> left = query(idx * 2 + 1, l, mid, ql, qr);
        pair<int, int> right = query(idx * 2 + 2, mid + 1, r, ql, qr);
        return {max(left.first, right.first), min(left.second, right.second)};
    }
    long long continuousSubarrays(vector<int>& nums) {
        ll ret = 0;
        int n = nums.size();
        seg.resize(4 * n);
        bounds.resize(n);
        for (int i = 0; i < n; ++i)
        {
            bounds[i] = {nums[i] - 2, nums[i] + 2};
        }
        build(0, 0, n - 1);
        int l = 0, r = 0;
        while (r < n)
        {
            auto [lb, ub] = query(0, 0, n - 1, l, r);
            if (lb <= nums[r] && nums[r] <= ub)
            {
                ret += (r - l + 1);
                ++r;
            }
            else
            {
                ++l;
            }
        }
        return ret;
    }
};
