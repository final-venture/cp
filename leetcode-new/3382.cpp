#define ll long long
class Solution {
private:
    vector<ll> seg;
public:
    ll query(ll idx, ll l, ll r, ll ql, ll qr)
    {
        if (ql <= l && r <= qr)
            return seg[idx];
        if (r < ql || qr < l || ql > qr)
            return -1;
        ll m = l + (r - l) / 2;
        ll left = query(idx * 2 + 1, l, m, ql, qr);
        ll right = query(idx * 2 + 2, m + 1, r, ql, qr);
        return max(left, right);
    }
    ll update(ll idx, ll l, ll r, ll t, ll v)
    {
        if (l == r && r == t)
            return seg[idx] = v;
        if (r < t || l > t)
            return seg[idx];
        ll m = l + (r - l) / 2;
        ll left = update(idx * 2 + 1, l, m, t, v);
        ll right = update(idx * 2 + 2, m + 1, r, t, v);
        return seg[idx] = max(left, right);
    }
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        ll n = xCoord.size();
        map<ll, vector<ll>> y2xv;
        for (ll i = 0; i < n; ++i)
        {
            y2xv[yCoord[i]].push_back(xCoord[i]);
        }
        for (auto& [y, xv] : y2xv)
        {
            sort(xv.begin(), xv.end());
        }
        set<ll> xtmp(xCoord.begin(), xCoord.end());
        unordered_map<ll, ll> x2n;
        ll cnt = 0;
        for (ll x : xtmp)
        {
            x2n[x] = cnt;
            ++cnt;
        }
        // for (auto& [x, n] : x2n)
        // {
        //     cout << x << ' ' << n << '\n';
        // }
        ll nxcnt = xtmp.size();
        seg.resize(nxcnt * 4, -1);
        ll ret = -1;
        for (auto& [y1, xv] : y2xv)
        {
            ll nn = xv.size();
            for (ll i = 1; i < nn; ++i)
            {
                ll x1 = xv[i - 1], x2 = xv[i];
                // cout << x1 << ' ' << x2 << '\n';
                ll candy1 = query(0, 0, nxcnt - 1, x2n[x1], x2n[x1]);
                ll candy2 = query(0, 0, nxcnt - 1, x2n[x2], x2n[x2]);
                // cout << candy1 << ' ' << candy2 << '\n';
                if (candy1 != -1 && candy1 == candy2)
                {
                    ll y2 = candy1;
                    if (x2 - x1 > 1)
                    {
                        // cout << x1 + 1 << ' ' << x2 - 1 << '\n';
                        ll candconfy = query(0, 0, nxcnt - 1, x2n[x1] + 1, x2n[x2] - 1);
                        // cout << candconfy << '\n';
                        if (candconfy < y2)
                        {
                            ll cand = (y1 - y2) * (x2 - x1);
                            // cout << cand << '\n';
                            ret = max(ret, cand);
                        }
                    }
                    else
                    {
                        ll cand = (y1 - y2) * (x2 - x1);
                        ret = max(ret, cand);
                    }
                }
            }
            for (auto& x : xv)
            {
                update(0, 0, nxcnt - 1, x2n[x], y1);
            }
        }
        return ret;
    }
};
