#define c(x) static_cast<ll>(x)
#define ll long long
class Solution {
private:
    vector<ll> seg;
public:
    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = -2e14;
            return;
        }
        int m = l + (r - l) / 2;
        build(idx * 2 + 1, l, m);
        build(idx * 2 + 2, m + 1, r);
        seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    ll query(int idx, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (qr < l || r < ql)
        {
            return -2e14;
        }
        int m = l + (r - l) / 2;
        ll left = query(idx * 2 + 1, l, m, ql, qr);
        ll right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return max(left, right);
    }

    ll update(int idx, int l, int r, int t, ll v)
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
        ll left = update(idx * 2 + 1, l, m, t, v);
        ll right = update(idx * 2 + 2, m + 1, r, t, v);
        return seg[idx] = max(left, right);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        seg.resize(4 * n);
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            a[i] = nums[i] - i;
        }
        vector<ll> sorted(a.begin(), a.end());
        sort(sorted.begin(), sorted.end());
        map<ll, int> n2fi;
        for (int i = n - 1; i >= 0; --i)
        {
            n2fi[sorted[i]] = i;
        }
        map<ll, int> cnt;
        build(0, 0, n - 1);
        for (int i = 0; i < n; ++i)
        {
            ll add = 0;
            // cout << a[i] << ' ' << n2fi[a[i]] << '\n';
            if (n2fi[a[i]] + cnt[a[i]] - 1 >= 0)
            {
                add = query(0, 0, n - 1, 0, n2fi[a[i]] + cnt[a[i]] - 1); // add oob process
                // cout << add << '\n';
            }
            update(0, 0, n - 1, n2fi[a[i]] + cnt[a[i]], max(c(nums[i]), c(add + nums[i])));
            ++cnt[a[i]];
        }
        // for (int x : seg) cout << x << ' ';
        ll ret = query(0, 0, n - 1, 0, n - 1);
        return ret;
    }
};
