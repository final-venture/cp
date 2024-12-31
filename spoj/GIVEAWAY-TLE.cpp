// We need to use segtree of ordered_set rather than vector: https://codeforces.com/blog/entry/11080
// so that update can work in O(log^2 n)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define EPS 1e-9

void init()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
}

vector<vector<int>> seg;
vector<int> a;

inline vector<int> merge(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> ret;
    int n1 = v1.size(), n2 = v2.size();
    int i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (v1[i1] <= v2[i2])
        {
            ret.push_back(v1[i1]);
            ++i1;
        }
        else
        {
            ret.push_back(v2[i2]);
            ++i2;
        }
    }

    while (i1 < n1)
    {
        ret.push_back(v1[i1]);
        ++i1;
    }

    while (i2 < n2)
    {
        ret.push_back(v2[i2]);
        ++i2;
    }
    return ret;
}

inline void build(int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = {a[l]};
        return;
    }
    int m = l + (r - l) / 2;
    build(idx * 2 + 1, l, m);
    build(idx * 2 + 2, m + 1, r);
    seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
}

inline int query(int idx, int l, int r, int ql, int qr, int k)
{
    if (ql <= l && r <= qr)
    {
        int nn = seg[idx].size();
        int cnt = lower_bound(all(seg[idx]), k) - seg[idx].begin();
        return nn - cnt;
    }
    if (r < ql || l > qr)
    {
        return 0;
    }
    int m = (l + r) >> 1;
    int left = query(idx * 2 + 1, l, m, ql, qr, k);
    int right = query(idx * 2 + 2, m + 1, r, ql, qr, k);
    return left + right;
}

inline vector<int> update(int idx, int l, int r, int t, int v)
{
    if (l == r && r == t)
    {
        seg[idx] = {v};
        return seg[idx];
    }
    if (l > t || r < t)
    {
        return seg[idx];
    }
    int m = (l + r) >> 1;
    // vector<int> left = update(idx * 2 + 1, l, m, t, v);
    // vector<int> right = update(idx * 2 + 2, m + 1, r, t, v);
    return seg[idx] = merge(update(idx * 2 + 1, l, m, t, v), update(idx * 2 + 2, m + 1, r, t, v));
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    seg.resize(4 * n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;

    while (q--)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        --a; --b;
        if (cmd == 0)
        {
            int c;
            cin >> c;
            cout << query(0, 0, n - 1, a, b, c) << '\n';
        }
        else
        {
            update(0, 0, n - 1, a, b);
        }
    }
}

signed main()
{
    init();
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
