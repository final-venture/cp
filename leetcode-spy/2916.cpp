// store sum and square in a node
// we can use math to figure out sum of squares
// range addition update and range sum query.
#define ll long long
#define MOD 1000000007
class Solution {
private:
    vector<pair<ll, ll>> seg;
    vector<ll> lazy;
    vector<ll> nums;
public:
    void propagate(int idx, int l, int r)
    {
        if (lazy[idx])
        {
            // (a + v)^2 + (b + v)^2 + (c + v)^2... = (a^2 + b^2 + c^2) + v(a + b + c) + v^2 * gap
            // = sqrsum^2 + v  * sum^2 + v^2 * gap
            ll sqr = seg[idx].first + lazy[idx] * seg[idx].second * 2 + lazy[idx] * lazy[idx] * (r - l + 1);
            ll summ = seg[idx].second + lazy[idx] * (r - l + 1);
            seg[idx].first = sqr;
            seg[idx].second = summ;
            if (l != r)
            {
                lazy[idx * 2 + 1] += lazy[idx];
                lazy[idx * 2 + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    pair<ll, ll> merge(pair<ll, ll>& p1, pair<ll, ll>& p2)
    {
        return {p1.first + p2.first, p1.second + p2.second};
    }

    // void build(int idx, int l, int r)
    // {
    //     if (l == r)
    //     {
    //         seg[idx] = {0, 0};
    //         return;
    //     }
    //     int m = l + (r - l) / 2;
    //     build(idx * 2 + 1, l, m);
    //     build(idx * 2 + 2, m + 1, r);
    //     seg[idx].second = seg[idx * 2 + 1] + seg[idx * 2 + 2];
    //     seg[idx].first = seg[idx * 2 + 1].first * seg[idx * 2 + 2];
    // }

    pair<ll, ll> query(int idx, int l, int r, int ql, int qr)
    {
        propagate(idx, l, r);
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        if (qr < l || r < ql)
        {
            return {0, 0};
        }
        int m = l + (r - l) / 2;
        pair<ll, ll> left = query(idx * 2 + 1, l, m, ql, qr);
        pair<ll, ll> right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return merge(left, right);
    }

    pair<ll, ll> update(int idx, int l, int r, int ql, int qr, int v)
    {
        if (ql <= l && r <= qr)
        {
            lazy[idx] += v;
            propagate(idx, l, r);
            return seg[idx];
        }
        propagate(idx, l, r);
        if (qr < l || r < ql)
        {
            return seg[idx];
        }
        int m = l + (r - l) / 2;
        pair<ll, ll> left = update(idx * 2 + 1, l, m, ql, qr, v);
        pair<ll, ll> right = update(idx * 2 + 2, m + 1, r, ql, qr, v);
        return seg[idx] = merge(left, right);
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n, {0, 0});
        lazy.resize(4 * n, 0);
        int maxx = *max_element(nums.begin(), nums.end());
        vector<int> last_seen(maxx + 1, -1);
        // build(0, 0, n - 1);

        ll ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int st = (last_seen[nums[i]] != -1) ? last_seen[nums[i]] + 1 : 0;
            int ed = i;
            update(0, 0, n - 1, st, ed, 1);
            last_seen[nums[i]] = i;
            ret += query(0, 0, n - 1, 0, n - 1).first;
            ret %= MOD;
        }
        return ret;
    }
};
